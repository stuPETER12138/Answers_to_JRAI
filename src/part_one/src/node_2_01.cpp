#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"

using std::placeholders::_1;
using std_msgs::msg::String;
using std_msgs::msg::Bool;

class Node01 : public rclcpp::Node {
    public:
    Node01() : Node("node_01") {
        subscription_ = this->create_subscription<String>("fibonacci_321", 10, 
        std::bind(&Node01::fibo_callback, this, _1));
        publisher_ = this->create_publisher<Bool>("if_even_122", 10);
    }
    private:
    rclcpp::Subscription<String>::SharedPtr subscription_;
    rclcpp::Publisher<Bool>::SharedPtr publisher_;
    void fibo_callback(const String & msg) const {
        // RCLCPP_INFO(this->get_logger(), "Fibonacci sequence: %s", msg.data.c_str());
        auto if_even = Bool();
        int num = std::stoi(msg.data);
        if_even.data = (num % 2 == 0);
        RCLCPP_INFO(this->get_logger(), "If %d is even: %s", num, if_even.data ? "True" : "Flase");
        publisher_ -> publish(if_even);
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Node01>());
    rclcpp::shutdown();
    return 0;
}
