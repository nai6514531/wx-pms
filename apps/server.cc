#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "apis/cpp/protocol/v1/deduction.grpc.pb.h"
#include "apps/3rd/sql/mysqlplus.h"

using namespace std;
using namespace daotk::mysql;

using std::string;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using protocol::payment::deduction::v1::DeductionAdminApi;
using protocol::payment::deduction::v1::DeductionAdminReq;
using protocol::payment::deduction::v1::DeductionAdminResp;
using protocol::payment::deduction::v1::DeductionStruct;


// Logic and data behind the server's behavior.
class FeeAdminServer final : public DeductionAdminApi::Service {
  Status GetDeductionList(ServerContext* context, const DeductionAdminReq* req, DeductionAdminResp* res) override {
    connection my{ "127.0.0.1", "root", "nai6514531", "payment" };
    if (!my) {
      cout << "Connection failed" << endl;
    }

    DeductionStruct data;
    int status;
    string desc;
    string title;
    auto deduction_list = my.query("select * from deduction");

    while (!deduction_list.eof()) {
      deduction_list.fetch(status, desc, title);
      cout << "title: " << title << ", status: " << status << ", desc: " << desc;
			cout << endl;
      data.set_title(title);
      data.set_desc(desc);
      data.set_status(status);
      res->mutable_data()->Add(std::move(data));
      deduction_list.next();
    }
    return Status::OK;
  }

  Status AdminOp(ServerContext* context, const DeductionAdminReq* req, DeductionAdminResp* res) override {
    string result("success hanlder");
    string header = req->header();
    std::cout << header << std::endl;
    return Status::OK;
  }
};

void RunServer() {
  string address = "0.0.0.0";
  string port = "50051";
  string server_address = address + ":" + port;
  FeeAdminServer service;

  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}

int main(int argc, char** argv) {
  RunServer();

  return 0;
}
