#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "apis/cpp/protocol/v1/deduction.grpc.pb.h"

#include "apps/3rd/sql/mysqlplus.h"
#include "apps/3rd/json.hpp"

#include "apps/utils/config.hpp"

using namespace std;
using daotk::mysql::connection;
using std::string;
using nlohmann::json;

using utils::AllConfig;
using utils::Config;
using utils::DBConfig;
using utils::SvrConfig;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using protocol::payment::deduction::v1::DeductionAdminApi;
using protocol::payment::deduction::v1::DeductionAdminReq;
using protocol::payment::deduction::v1::DeductionAdminResp;
using protocol::payment::deduction::v1::DeductionStruct;


// Logic and data behind the server's behavior.
class AdminServer final : public DeductionAdminApi::Service {
  Status GetDeductionList(ServerContext* context, const DeductionAdminReq* req, DeductionAdminResp* res) override {
    DBConfig dbConf = Config::Instance().GetDBConfig();
    // Dao::Instance().GetDeductionList(dts);
    connection conn{ dbConf.server, dbConf.username, dbConf.password, dbConf.dbname };
    if (!conn) {
      cout << "Connection failed" << endl;
      // 记录数据库链接失败
      return Status::OK;
    }
    
    DeductionStruct data;
    string desc;
    string title;
    int status;
    int id;
    int pay_method_id;
    int detail_id;
    auto deduction_list = conn.query("select * from deduction");

    while (!deduction_list.eof()) {
      deduction_list.fetch(id, title, desc, status, pay_method_id, detail_id);
			cout << endl;
      data.set_title(title);
      data.set_desc(desc);
      data.set_status(status);
      data.set_id(id);
      data.set_pay_method_id(pay_method_id);
      data.set_detail_id(detail_id);
      res->mutable_data()->Add(std::move(data));
      deduction_list.next();
    }
    return Status::OK;
  }

  Status AdminOp(ServerContext* context, const DeductionAdminReq* req, DeductionAdminResp* res) override {
    return Status::OK;
  }
};

void RunServer(SvrConfig sc) {
  // 获取配置文件中的endpoint
  string server_address(sc.endpoint);
  AdminServer service;
  ServerBuilder builder;

  // 初始化grpc服务
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}


int main(int argc, char** argv) {
  string defaultConfigFile = "confs/server.json";
  if (!Config::Instance().Init(defaultConfigFile))
  {
    return -1;
  }

  SvrConfig svrConf = Config::Instance().GetSvrConfig();

  // if (!Dao::Instance().Init(dbConf)) {
  // }

  // if (!Dao::Instance().Init(dbConf)) {
  //   return -1;
  // }

  RunServer(svrConf);

  return 0;
}
