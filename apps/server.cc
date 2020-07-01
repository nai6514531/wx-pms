#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "apis/cpp/protocol/v1/fee.grpc.pb.h"

using std::string;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using protocol::fee::v1::FeeAdminApi;
using protocol::fee::v1::FeeAdminReq;
using protocol::fee::v1::FeeAdminResp;

// Logic and data behind the server's behavior.
class FeeAdminServer final : public FeeAdminApi::Service {
  Status Logout(ServerContext* context, const FeeAdminReq* req, FeeAdminResp* res) override {
    string result("Logout ");
    res->set_result(result);
    return Status::OK;
  }

  Status AdminOp(ServerContext* context, const FeeAdminReq* req, FeeAdminResp* res) override {
    string result("success hanlder");
    string cmd = req->cmd();
    std::cout << cmd << std::endl;
    res->set_result(result);
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
