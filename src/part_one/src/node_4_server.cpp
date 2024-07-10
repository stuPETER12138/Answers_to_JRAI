#include "interfaces/action/boiling.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using interfaces::action::Boiling;
using GoalHandleBoiling = rclcpp_action::ServerGoalHandle<Boiling>;

class BoilingActionServer : public rclcpp::Node {
    public:
    BoilingActionServer() : Node("Boiling_server") {
        auto handle_goal = [this](
            const rclcpp_action::GoalUUID &, std::shared_ptr<const Boiling::Goal>
            goal) {
                RCLCPP_INFO(this->get_logger(), "Received started temperature: %d", goal->start_temperature);
                return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
            }; 
        auto handle_cancel = [this](
            const std::shared_ptr<GoalHandleBoiling>) {
                RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
                return rclcpp_action::CancelResponse::ACCEPT;
            };
        auto handle_accepted = [this](
            const std::shared_ptr<GoalHandleBoiling> 
            goal_handle) {
                auto execute_in_thread = [this, goal_handle]() {return this->execute(goal_handle);};
                std::thread{execute_in_thread}.detach();
            };
    this->server_ = rclcpp_action::create_server<Boiling>(
        this,
        "boiling_water",
        handle_goal,
        handle_cancel,
        handle_accepted);
    }
    private:
    rclcpp_action::Server<Boiling>::SharedPtr server_;
    void execute(const std::shared_ptr<GoalHandleBoiling> goal_handle) {
        RCLCPP_INFO(this->get_logger(), "Executing goal");
        rclcpp::Rate loop_rate(10);
        const auto goal = goal_handle->get_goal();
        auto feedback = std::make_shared<Boiling::Feedback>();
        auto & per_second_temperature = feedback->per_second_temperature;
        auto result = std::make_shared<Boiling::Result>();
        for (int time = 0; rclcpp::ok() && goal->start_temperature <= 100; time++) {
            if (goal_handle->is_canceling()) {
                result->final_temperature = per_second_temperature;
                goal_handle->canceled(result);
                RCLCPP_INFO(this->get_logger(), "Goal canceled");
                return;
            }
            if (goal->start_temperature < 50) {
                feedback->per_second_temperature = goal->start_temperature + time * time;
            } else {
                feedback->per_second_temperature = goal->start_temperature + time;
            }
            if (feedback->per_second_temperature > 100) {break;}
            goal_handle->publish_feedback(feedback);
            RCLCPP_INFO(this->get_logger(), "Publish feedback");
            loop_rate.sleep();
        }
        if (rclcpp::ok()) {
            result->final_temperature = 100;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal succeeded");
        }
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc,argv);
    auto srv_node = std::make_shared<BoilingActionServer>();
    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(srv_node);
    executor.spin();
    rclcpp::shutdown();
    return 0;
}
