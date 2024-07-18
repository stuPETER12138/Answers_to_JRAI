#include "behaviortree_ros2/bt_action_node.hpp"
#include "interfaces/action/fibonacci.hpp"

using namespace BT;

using interfaces::action::Fibonacci;

class FibonacciAction: public RosActionNode<Fibonacci> {
    public:
    FibonacciAction(
        const std::string& name,
        const NodeConfig& conf,
        const RosNodeParams& params
    ) : RosActionNode<Fibonacci>(name, conf, params) {}
    static BT::PortsList providedPorts() {
        return providedBasicPorts({
            InputPort<unsigned>("msec")
        });
    }
    bool setGoal(RosActionNode::Goal & goal) override;
    NodeStatus onResultReceived(const WrappedResult & wr) override;
    virtual NodeStatus onFailure(ActionNodeErrorCode error) override;
    NodeStatus onFeedback(const std::shared_ptr<const Feedback> feedback);
};
