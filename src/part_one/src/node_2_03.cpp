#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;
using std_msgs::msg::Int32;
using std_msgs::msg::String;


class Node03 : public rclcpp::Node {
    public:
    Node03() : Node("node_03") {
        subscription_ = this->create_subscription<Int32>("fibonacci_223", 10, 
        std::bind(&Node03::fibo_callback, this, _1));   // (node_02)2 (to)2 (node_03)3
        publisher_ = this->create_publisher<String>("fibonacci_321", 10);
    }
    private:
    rclcpp::Subscription<Int32>::SharedPtr subscription_;
    rclcpp::Publisher<String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    void fibo_callback(const Int32 & msg) const {
        auto fibo = String();
        fibo.data = std::to_string(msg.data);
        RCLCPP_INFO(this->get_logger(), "Fibonacci sequence: %s", fibo.data.c_str());
        publisher_ -> publish(fibo);
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Node03>());
    rclcpp::shutdown();
    return 0;
}
