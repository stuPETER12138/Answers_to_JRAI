#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int32.hpp"
#include "std_msgs/msg/bool.hpp"

using std::placeholders::_1;
using namespace std::chrono_literals;
using std_msgs::msg::Int32;
using std_msgs::msg::Bool;

class Node02 : public rclcpp::Node {
    public:
    Node02() : Node("node_02"), count_(1) {
        publisher_ = this->create_publisher<Int32>("fibonacci_223", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&Node02::timer_callback, this));
        subscription_ = this->create_subscription<Bool>("if_even_122", 10, 
        std::bind(&Node02::even_callback, this, _1));
    }
    private:
    rclcpp::Publisher<Int32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<Bool>::SharedPtr subscription_;
    size_t count_;
    void timer_callback() {
        auto num = Int32();
        int n = 0;
        n = count_++;
        if (fibonacci(n + 1) > 12345) {
            count_ = 1;
        }
        num.data = fibonacci(n);
        // RCLCPP_INFO(this->get_logger(), "Fibonacci sequence: %d", num.data);
        publisher_ -> publish(num);
    }
    int fibonacci(int n) {
        if (n > 2) {
            return fibonacci(n - 1) + fibonacci(n - 2);
        } else {
            return 1;
        }
    }
    void even_callback(const Bool & msg) {
        RCLCPP_INFO(this->get_logger(), "%s", msg.data ? "True" : "Flase");
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Node02>());
    rclcpp::shutdown();
    return 0;
}
