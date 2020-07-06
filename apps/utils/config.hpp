#ifndef UTILS_CONFIG_HPP
#define UTILS_CONFIG_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "apps/3rd/json.hpp"

namespace utils
{
    using std::ifstream;
    using std::string;
    using nlohmann::json;

    struct SvrConfig
    {
        string endpoint;
        // string healthKey;
    };

    void to_json(json &j, const SvrConfig &sc);
    void from_json(const json &j, SvrConfig &sc);

    struct DBConfig
    {
        string server;
        int port;
        string username;
        string password;
        string dbname;
    };

    void to_json(json &j, const DBConfig &db);
    void from_json(const json &j, DBConfig &db);

    struct AllConfig
    {
        SvrConfig svr;
        DBConfig db;
    };

    void to_json(json &j, const AllConfig &ac);
    void from_json(const json &j, AllConfig &ac);

    class Config
    {
        public:
            static Config &Instance()
            {
                static Config c;
                return c;
            }

            Config(const Config &) = delete;
            Config &operator=(Config &) = delete;

            bool Init(string configFile)
            {
                if (configFile.empty())
                    return false;
                ifstream s(configFile);
                if (!s.good())
                    return false;

                try
                {
                    json j;
                    s >> j;
                    ac_ = j.get<AllConfig>();
                }
                catch (...)
                {
                    return false;
                }
                return true;
            }

            const DBConfig &GetDBConfig() { return ac_.db; }
            const SvrConfig &GetSvrConfig() { return ac_.svr; }

        private:
            Config() {}
        private:
            utils::AllConfig ac_;
    };
}


#endif