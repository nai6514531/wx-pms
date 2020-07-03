#include <string>
#include <iostream>
#include <grpcpp/grpcpp.h>

#include "apis/cpp/protocol/v1/deduction.grpc.pb.h"
#include "apps/utils/strings.hpp"
#include "apps/3rd/json.hpp"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


using protocol::payment::deduction::v1::DeductionAdminApi;
using protocol::payment::deduction::v1::DeductionAdminReq;
using protocol::payment::deduction::v1::DeductionAdminResp;

using utils::CmdMap;

class DeductionAdmin 
{
    public:
        DeductionAdmin(shared_ptr<Channel> channel)
            : stub_(DeductionAdminApi::NewStub(channel))
        
        {
            reqHandlers = {
                {"getlist", &DeductionAdmin::getList},
            };
            printOp.add_whitespace = true;
            printOp.always_print_primitive_fields = true;
            printOp.preserve_proto_field_names = true;
        }

        void Exec(string cmd, string data)
        {
            auto it = reqHandlers.find(cmd);
            if (it == reqHandlers.end())
            {
                cout << "invalid cmd:" << cmd << data << endl;
                return;
            }
            (this->*(it->second))(data);
        }
    private:
        void getList(string data)
        {
            DeductionAdminReq req;
            // JsonStringToMessage(data, &req, parseOp);
            DeductionAdminResp resp;
            ClientContext ctx;
            Status status = stub_->GetDeductionList(&ctx, req, &resp);
            string printJ;
            MessageToJsonString(resp, &printJ, printOp);
            cout << "\ngrpc code:" << status.error_code() << " , msg:" << status.error_message() << endl;
            cout << printJ << endl;
        }
    private:
        using func = void (DeductionAdmin::*)(string);
        google::protobuf::util::JsonPrintOptions printOp;
        google::protobuf::util::JsonParseOptions parseOp;

        unique_ptr<DeductionAdminApi::Stub> stub_;
        unordered_map<string, func> reqHandlers;
};

CmdMap cmdMap = {
    {
        "getlist", {
            {"(no args)", "eg:config set {\"kick_mode\":1}"},
        }
    },
    {
        "help", {
            {"(no args)", "`help` can also be `man`, `info`"},
            {"specific_cmd", "help info on specific command"},
        }
    },
    {
        "exit", {
            {"(no args)", "exit program. `exit` can also be `quit`, `bye`"},
        }
    },
};

vector<string> quits = {"exit"};
vector<string> helps = {"help"};
string adminPrompt = "admin> ";
string _exitPrompt = "Au revoir.\n";
string defaultAddr = "127.0.0.1:12345";
string _helpPrompt = "type `help` for admin commands info\n";
string errorPrompt = "Invalid command, letters(a-zA-Z) only. Try `help` for more.\n";


int main(int argc, char **argv)
{
    string line, cmd;
    string address = "localhost";
    string port = "50051";
    string server_address = address + ":" + port;
    DeductionAdmin client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
    while (1)
    {
        cout << adminPrompt;
        std::getline(std::cin, line);
        auto elts = utils::splitByWhitespace(line);
        if (elts.empty()) continue;
        string cmd = elts[0];
        utils::toLower(cmd);
        string params = elts[1];

        if (!utils::isWord(cmd)) 
        { 
            cout << errorPrompt;
            continue; 
        }
        if (utils::in(cmd, helps))
        {
            string specificCmd;
            if (elts.size() > 1 && utils::isWord(elts[1]))
            {
                specificCmd = elts[1];
                utils::toLower(specificCmd);
            }
            utils::help(cmdMap, specificCmd);
            continue;
        }

        if (utils::in(cmd, quits)) break;

        if (cmdMap.find(cmd) == cmdMap.end()) 
        { 
            utils::help(cmdMap); 
            continue; 
        }
        client.Exec(cmd, elts[1]);
    }

    cout << _exitPrompt;
    return 0;
}