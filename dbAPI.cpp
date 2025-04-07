#include <cstdlib>
#include <cstdint>
#include "httplib.h"
#include <iostream>
#include <vector>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <future>
#include <thread>
using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

mongocxx::client connectToMongo() {
    mongocxx::instance instance{};
    const auto uri = mongocxx::uri{std::getenv("YOUSOFS_MONGODB_CLUSTER_CONNECT_STRING")};
    mongocxx::options::client client_options;
    const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
    client_options.server_api_opts(api);
    mongocxx::client conn{uri,client_options};
    return conn;
}

int main() {
 
 std::packaged_task<mongocxx::client ()> pkg{connectToMongo};
 std::future<mongocxx::client> fut = pkg.get_future();
 std::thread t{std::move(pkg)};
 mongocxx::client conn = fut.get();

 
 httplib::Server svr;

 svr.Post("/login",[](const httplib::Request &req, httplib::Response &res){
    std::cout << "Recieved this data: " << req.body << "\n";
    res.set_content("{\"access\":\"granted\"}", "application/json");
});
 svr.listen("localhost",8080);

 t.join();

 return -1;
}
