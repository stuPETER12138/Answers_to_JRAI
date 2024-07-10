#include "interfaces/action/boiling.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

using interfaces::action::Boiling;
using GoalHandleBoiling = rclcpp_action::ClientGoalHandle<Boiling>;

class BoilingActionClient : public rclcpp::Node {
    public:
    explicit BoilingActionClient() : Node("Boiling_client") {
        this->client_ptr_ = rclcpp_action::create_client<Boiling>(this,"boiling_water");
    }
    void SendGoal() {
        if (!this->client_ptr_->wait_for_action_server()) {
            RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
            rclcpp::shutdown();
        }
        auto goal = Boiling::Goal();
        goal.start_temperature = 25;
        RCLCPP_INFO(this->get_logger(), "Sending goal");
        auto send_goal_options = rclcpp_action::Client<Boiling>::SendGoalOptions();
        send_goal_options.goal_response_callback = [this](const GoalHandleBoiling::SharedPtr & goal_handle) {
            if (!goal_handle) {
                RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
            } else {
                RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
            }
        };
        send_goal_options.feedback_callback = [this](
            GoalHandleBoiling::SharedPtr,
            const std::shared_ptr<const Boiling::Feedback> feedback) {
                RCLCPP_INFO(this->get_logger(), "%d", feedback->per_second_temperature);
            };
            send_goal_options.result_callback = [this](const GoalHandleBoiling::WrappedResult & result) {
                switch (result.code) {
                    case rclcpp_action::ResultCode::SUCCEEDED:
                    break;
                    case rclcpp_action::ResultCode::ABORTED:
                    RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
                    return;
                    case rclcpp_action::ResultCode::CANCELED:
                    RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
                    return;
                    default:
                    RCLCPP_ERROR(this->get_logger(), "Unknown result code");
                    return;
                }
            RCLCPP_INFO(this->get_logger(), "%d", result.result->final_temperature);
            rclcpp::shutdown();
        };
        this->client_ptr_->async_send_goal(goal, send_goal_options);
    }
    private:
    rclcpp_action::Client<Boiling>::SharedPtr client_ptr_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc,argv); 

    auto cli_node = std::make_shared<BoilingActionClient>();

    cli_node->SendGoal();

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(cli_node);

    executor.spin();

    return 0;
}
