#include "rclcpp/rclcpp.hpp"
#include "interfaces/srv/money.hpp"

using interfaces::srv::Money;
using std::placeholders::_1;
using std::placeholders::_2;

class Server : public rclcpp::Node {
    public:
    Server() : Node("node03_server") {
        server_ = this->create_service<Money>("how_much", std::bind(&Server::compare, this, _1, _2));
    }
    private:
    rclcpp::Service<Money>::SharedPtr server_;
    void compare(const Money::Request::SharedPtr req, const Money::Response::SharedPtr res) {
        if (req->num <= 500) {
            res->answer = "可以购买";
        } else {
            res->answer = "不可以购买";
        }
        RCLCPP_INFO(this->get_logger(), "%s", res->answer.c_str());
    }
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto service = std::make_shared<Server>();
    rclcpp::spin(service);
    rclcpp::shutdown();
    return 0;
}
