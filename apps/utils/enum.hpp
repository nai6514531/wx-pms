#ifndef UTILS_ENUM_HHPP
#define UTILS_ENUM_HHPP

using namespace std;

namespace utils {
    string SUCCESS_MSG = "操作成功";
    string DB_CONNECT_ERROR_MSG = "数据库连接错误";
    string NO_RECORD_MSG= "未查询到记录";
    string CREATE_ERROR_MSG= "数据创建失败";
    enum RespCode
    {
        OK = 0,
        DB_CONNECT_ERROR,
        NO_RECORD,
        CREATE_ERROR,
    };
    // 表示扣费服务的状态
    enum DeductionStatus
    {
        NORMAL = 0,
        EXPIRED,
    };
}
#endif