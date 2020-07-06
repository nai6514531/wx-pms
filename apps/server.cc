#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>

#include "apis/cpp/protocol/v1/deduction.grpc.pb.h"

#include "apps/3rd/sql/mysqlplus.h"
#include "apps/3rd/json.hpp"

#include "apps/utils/config.hpp"
#include "apps/utils/enum.hpp"

using namespace std;
using daotk::mysql::prepared_stmt;
using daotk::mysql::connection;
using std::string;
using nlohmann::json;

using utils::AllConfig;
using utils::Config;
using utils::DBConfig;
using utils::SvrConfig;
using utils::RespCode;
using utils::DeductionStatus;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using protocol::payment::deduction::v1::DeductionAdminApi;
using protocol::payment::deduction::v1::DeductionReq;
using protocol::payment::deduction::v1::DeductionResp;
using protocol::payment::deduction::v1::DeductionStruct;


// Logic and data behind the server's behavior.
class AdminServer final : public DeductionAdminApi::Service {
  // 获取付费列表
    Status GetDeductionList(ServerContext* context, const DeductionReq* req, DeductionResp* res) override {
        // TODO:增加数据库连接池，从连接池中获取connection
        // 应该定义结构体和数据库进行映射
        DBConfig dbConf = Config::Instance().GetDBConfig();
        DeductionStruct data;
        string desc;
        string title;
        int status;
        int id;
        int pay_method_id;
        connection conn{ dbConf.server, dbConf.username, dbConf.password, dbConf.dbname };
        if (!conn) {
            // 数据库连接失败
            res->set_success(false);
            res->set_message(utils::DB_CONNECT_ERROR_MSG);
            res->set_code(RespCode::DB_CONNECT_ERROR);
            // TODO:异常应该写到日志中
            cout << "Connection failed" << endl;
        }

        auto result = conn.query("select * from deduction where status = %d", DeductionStatus::NORMAL);
        while (!result.eof()) {
            result.fetch(id, title, desc, status, pay_method_id);
            data.set_title(title);
            data.set_desc(desc);
            data.set_status(status);
            data.set_id(id);
            data.set_pay_method_id(pay_method_id);
            res->mutable_data()->Add(std::move(data));
            result.next();
        }
        conn.close();
        res->set_success(true);
        res->set_message(utils::SUCCESS_MSG);
        res->set_code(RespCode::OK);
        return Status::OK;
    }

    // 获取失效的付费列表
    Status GetExpiredDeductionList(ServerContext* context, const DeductionReq* req, DeductionResp* res) override {
        // TODO:增加数据库连接池，从连接池中获取connection
        DBConfig dbConf = Config::Instance().GetDBConfig();
        DeductionStruct data;
        string desc;
        string title;
        int status;
        int id;
        int pay_method_id;
        connection conn{ dbConf.server, dbConf.username, dbConf.password, dbConf.dbname };
        if (!conn) {
            // 数据库连接失败
            res->set_success(false);
            res->set_message(utils::DB_CONNECT_ERROR_MSG);
            res->set_code(RespCode::DB_CONNECT_ERROR);
            // TODO:异常应该写到日志中
            cout << "Connection failed" << endl;
        }

        auto result = conn.query("select * from deduction where status = %d", DeductionStatus::EXPIRED);
        while (!result.eof()) {
            result.fetch(id, title, desc, status, pay_method_id);
            data.set_title(title);
            data.set_desc(desc);
            data.set_status(status);
            data.set_id(id);
            data.set_pay_method_id(pay_method_id);
            res->mutable_data()->Add(std::move(data));
            result.next();
        }
        conn.close();
        res->set_success(true);
        res->set_message(utils::SUCCESS_MSG);
        res->set_code(RespCode::OK);
        return Status::OK;
    }

    // 关闭付费功能
    Status CloseDeduction(ServerContext* context, const DeductionReq* req, DeductionResp* res) override {
        DBConfig dbConf = Config::Instance().GetDBConfig();
        int id = req->id();
        int expiredStatus = DeductionStatus::EXPIRED;
        connection conn{ dbConf.server, dbConf.username, dbConf.password, dbConf.dbname };
        if (!conn) {
            res->set_success(false);
            res->set_message(utils::DB_CONNECT_ERROR_MSG);
            res->set_code(RespCode::DB_CONNECT_ERROR);
            cout << "Connection failed" << endl;
        }
        auto result = conn.query("select * from deduction where id = %d limit 1", id);
        if (!result.is_empty()) {
            // 执行update操作
            prepared_stmt stmt(
                conn,
                "update deduction set status = ? where id = ? limit 1");
            stmt.bind_param(expiredStatus, id);
            stmt.execute();
            res->set_success(true);
            res->set_message(utils::SUCCESS_MSG);
            res->set_code(RespCode::OK);
        } else {
            res->set_success(false);
            res->set_message(utils::NO_RECORD_MSG);
            res->set_code(RespCode::NO_RECORD);
        }
        conn.close();
        return Status::OK;
    }

    // 开通付费功能
    Status OpenDeduction(ServerContext* context, const DeductionReq* req, DeductionResp* res) override {
        DBConfig dbConf = Config::Instance().GetDBConfig();
        int id = req->id();
        int normalStatus = DeductionStatus::NORMAL;
        connection conn{ dbConf.server, dbConf.username, dbConf.password, dbConf.dbname };
        if (!conn) {
            res->set_success(false);
            res->set_message(utils::DB_CONNECT_ERROR_MSG);
            res->set_code(RespCode::DB_CONNECT_ERROR);
            cout << "Connection failed" << endl;
        }
        auto result = conn.query("select * from deduction where id = %d limit 1", id);
        if (!result.is_empty()) {
            prepared_stmt stmt(
                conn,
                "update deduction set status = ? where id = ? limit 1");
            stmt.bind_param(normalStatus, id);
            stmt.execute();
            res->set_success(true);
            res->set_message(utils::SUCCESS_MSG);
            res->set_code(RespCode::OK);
            // 执行update操作
        } else {
            res->set_success(false);
            res->set_message(utils::NO_RECORD_MSG);
            res->set_code(RespCode::NO_RECORD);
        }
        conn.close();
        return Status::OK;
    }

    // 创建付费记录
    Status CreateDeduction(ServerContext* context, const DeductionReq* req, DeductionResp* res) override {
        DBConfig dbConf = Config::Instance().GetDBConfig();
        string title = req->title();
        string desc = req->desc();
        int normalStatus = DeductionStatus::NORMAL;
        connection conn{ dbConf.server, dbConf.username, dbConf.password, dbConf.dbname };
        if (!conn) 
        {
            res->set_success(false);
            res->set_message(utils::DB_CONNECT_ERROR_MSG);
            res->set_code(RespCode::DB_CONNECT_ERROR);
            cout << "Connection failed" << endl;
        }
        // 插入新数据
        prepared_stmt stmt(
            conn,
            "INSERT INTO `deduction` (`title`, `desc`, `status`) VALUES (?, ?, ?)");
        stmt.bind_param(title, desc, normalStatus);
        if (stmt.execute()) {
            res->set_success(true);
            res->set_message(utils::SUCCESS_MSG);
            res->set_code(RespCode::OK);
        } else {
            res->set_success(false);
            res->set_message(utils::CREATE_ERROR_MSG);
            res->set_code(RespCode::CREATE_ERROR);
        }
        conn.close();
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
    RunServer(svrConf);
    return 0;
}