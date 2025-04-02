#include "httplib.h"
#include<iostream>
int main() {
 httplib::Server svr;
 svr.Post("/login",[](const httplib::Request &req, httplib::Response &res){
    std::cout << "Recieved this data: " << req.body << "\n";
    res.set_content("{\"access\":\"granted\"}", "application/json");
});
 svr.listen("localhost",8080);
 return -1;
}
