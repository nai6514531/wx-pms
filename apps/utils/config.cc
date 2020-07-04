#include "config.hpp"

namespace utils
{
    void to_json(json &j, const SvrConfig &sc)
    {
        j = json{
            {"endpoint", sc.endpoint},
        };
    }

    void from_json(const json &j, SvrConfig &sc)
    {
        j.at("endpoint").get_to(sc.endpoint);
    }

    void to_json(json &j, const DBConfig &db)
    {
        j = json{
            {"server", db.server},
            {"port", db.port},
            {"username", db.username},
            {"password", db.password},
            {"dbname", db.dbname},
        };
    }

    void from_json(const json &j, DBConfig &db)
    {
        j.at("server").get_to(db.server);
        j.at("port").get_to(db.port);
        j.at("username").get_to(db.username);
        j.at("password").get_to(db.password);
        j.at("dbname").get_to(db.dbname);
    }

    void to_json(json &j, const AllConfig &ac)
    {
        j = json{
            {"server", ac.svr},
            {"db", ac.db},
        };
    }

    void from_json(const json &j, AllConfig &ac)
    {
        j.at("server").get_to(ac.svr);
        j.at("db").get_to(ac.db);
    }
} 