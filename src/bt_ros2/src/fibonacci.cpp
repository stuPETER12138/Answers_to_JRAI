#include "fibonacci.hpp"
#include "behaviortree_ros2/plugins.hpp"

bool FibonacciAction::setGoal(RosActionNode::Goal & goal) {
    getInput("order", goal.order);
    return true;
}

NodeStatus FibonacciAction::onResultReceived(const RosActionNode::WrappedResult & wr) {
    std::stringstream ss;
    for (auto number : wr.result->sequence) {
      ss << number << " ";
    }
    RCLCPP_INFO(logger(), "%s", ss.str().c_str());
    return NodeStatus::SUCCESS;
}

NodeStatus FibonacciAction::onFailure(ActionNodeErrorCode error) {
    RCLCPP_ERROR(logger(), "Error: %d", error);
    return NodeStatus::FAILURE;
}

NodeStatus FibonacciAction::onFeedback(const std::shared_ptr<const Feedback> feedback) {
    std::stringstream ss;
    ss << "Next number in sequence received: ";
    for (auto number : feedback->partial_sequence) {
      ss << number << " ";
    }
    RCLCPP_INFO(logger(), "%s", ss.str().c_str());
    return NodeStatus::RUNNING;
}

CreateRosNodePlugin(FibonacciAction, "FibonacciAction");
