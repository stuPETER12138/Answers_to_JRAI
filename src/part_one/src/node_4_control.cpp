#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "interfaces/action/boiling.hpp"

class BoilControl : public rclcpp::Node {
    public:
    BoilControl() : Node("boil_control") {
    }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto boil_action_service = std::make_shared<BoilControl>();
  rclcpp::spin(boil_action_service);
  rclcpp::shutdown();
  return 0;
}
