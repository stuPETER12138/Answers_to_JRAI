#include "rclcpp/rclcpp.hpp"
#include "interfaces/msg/now.hpp"
#include "time.h"

using namespace std::chrono_literals;
using interfaces::msg::Now;

class Publisher : public rclcpp::Node {
    public:
    Publisher() : Node("now_publisher") {
        publisher_ = this->create_publisher<Now>("now_time", 10);
        timer_ = this->create_wall_timer(1000ms, std::bind(&Publisher::timer_callback, this));
    }
    private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<Now>::SharedPtr publisher_;
    void timer_callback() {
        time_t t = time(0);
        char tmp[64];
        strftime(tmp, sizeof(tmp), "%Y 年 %m 月 %d 日 %H 时 %M 分 %S 秒", localtime(&t));
        auto time = Now();
        time.now = tmp;
        RCLCPP_INFO(this->get_logger(), "%s", time.now.c_str());
        publisher_->publish(time);
    }
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Publisher>());
    rclcpp::shutdown();
    return 0;
}
