#include "rclcpp/rclcpp.hpp"
#include "interfaces/srv/money.hpp"

using namespace std::chrono_literals;
using interfaces::srv::Money;

class CLient : public rclcpp::Node {
    public:
    CLient() : Node("node03_client") {
        client_ = this->create_client<Money>("how_much");
    }
    bool connect_server() {
        while (!client_->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "强制退出！");
                return false;
            }
            RCLCPP_INFO(this->get_logger(), "等待链接...");
        }
        return true;
    }
    rclcpp::Client<Money>::FutureAndRequestId send_request(int32_t num) {
        auto request = std::make_shared<Money::Request>();
        request->num = num;
        return client_->async_send_request(request);
    }
    private:
    rclcpp::Client<Money>::SharedPtr client_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    auto client = std::make_shared<CLient>();
    bool flag = client->connect_server();
    if (!flag) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "服务器连接失败！");
        return 0;
    }
    auto response = client->send_request(atoi(argv[1]));
    if (rclcpp::spin_until_future_complete(client, response) ==
    rclcpp::FutureReturnCode::SUCCESS) {
        RCLCPP_INFO(client->get_logger(), "%s", response.get()->answer.c_str());
    } else {
        RCLCPP_INFO(client->get_logger(), "请求异常");
    }
    rclcpp::shutdown();
    return 0;
}
