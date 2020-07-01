#include <string>
#include <iostream>
#include <grpcpp/grpcpp.h>

#include "apis/cpp/protocol/v1/fee.grpc.pb.h"
#include "apps/utils/strings.hpp"
#include "apps/3rd/json.hpp"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


using protocol::fee::v1::FeeAdminApi;
using protocol::fee::v1::FeeAdminReq;
using protocol::fee::v1::FeeAdminResp;

using utils::CmdMap;

class FeeAdminClient 
{
public:
    FeeAdminClient(shared_ptr<Channel> channel)
        : stub_(FeeAdminApi::NewStub(channel)) {}

    void Exec(string cmd)
    {
        FeeAdminReq req;
        req.set_cmd(cmd);

        FeeAdminResp resp;
        ClientContext ctx;
        Status status = stub_->AdminOp(&ctx, req, &resp);

        if (status.ok())
        {
            // cout << "[header]code:" << resp.mutable_header()->code() << ", msg:" + resp.mutable_header()->message() << endl;
            cout << "[body]" << endl << resp.result() << endl;
        }
        else
        {
            cout << "resp abnormal" << endl;
            cout << "code:" << status.error_code() << ": " << status.error_message() << endl;
            cout << status.error_details() << endl;
        }
    }
    private:
    unique_ptr<FeeAdminApi::Stub> stub_;
};

CmdMap cmdMap = {
    {
        "config", {
            {"setjson_config", "eg:config set {\"kick_mode\":1}"},
            {"show", "show config info(db user/passwd obscured)"},
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

// int main(int argc, char** argv) {
//   string address = "localhost";
//   string port = "50051";
//   string server_address = address + ":" + port;
//   cout << "Client querying server address: " << server_address << endl;


//   // Instantiate the client. It requires a channel, out of which the actual RPCs
//   // are created. This channel models a connection to an endpoint (in this case,
//   // localhost at port 50051). We indicate that the channel isn't authenticated
//   // (use of InsecureChannelCredentials()).
//   Client greeter(grpc::CreateChannel(
//       server_address, grpc::InsecureChannelCredentials()));
//   string user("world");

//   string reply = greeter.SayHello(user);
//   cout << "Greeter received: " << reply << endl;

//   reply = greeter.SayHelloAgain(user);
//   cout << "Greeter received: " << reply << endl;

//   return 0;
// }

vector<string> quits = {"exit", "quit", "bye"};
vector<string> helps = {"help", "info", "man"};
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
    FeeAdminClient client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
    while (1)
    {
        cout << adminPrompt;
        std::getline(std::cin, line);
        auto elts = utils::splitByWhitespace(line);
        if (elts.empty()) continue;
        string cmd = elts[0];
        utils::toLower(cmd);

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

        // valid command. send request
        // string s1, s2;
        // if (elts.size() == 2){s1 = elts[1];}
        // else if (elts.size() > 2){s1 = elts[1], s2 = elts[2];}

        client.Exec(cmd);
    }

    cout << _exitPrompt;
    return 0;
}