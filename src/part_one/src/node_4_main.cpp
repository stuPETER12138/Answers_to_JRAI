#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "interfaces/action/boiling.hpp"
#include "../include/part_one/boil.h"

class BoilServer : public rclcpp::Node {
    public:
    BoilServer() : Node("boil_service") {
    }
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto boil_action_service = std::make_shared<BoilServer>();
  rclcpp::spin(boil_action_service);
  rclcpp::shutdown();
  return 0;
}
