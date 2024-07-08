#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/now.hpp"

using std::placeholders::_1;
using interfaces::msg::Now;

class Subscriber : public rclcpp::Node {
    public:
    Subscriber() : Node("now_subscriber") {
        subscription_ = this->create_subscription<Now>("now_time", 10, 
        std::bind(&Subscriber::topic_callback, this, _1));
    }
    private:
    rclcpp::Subscription<Now>::SharedPtr subscription_;
    void topic_callback(const Now & msg) const {
        RCLCPP_INFO(this->get_logger(), "%s", msg.now.c_str());
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Subscriber>());
    rclcpp::shutdown();
    return 0;
}
