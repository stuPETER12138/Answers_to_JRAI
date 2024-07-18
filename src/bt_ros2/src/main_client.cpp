#include "behaviortree_ros2/bt_action_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors.hpp"
#include "behaviortree_ros2/plugins.hpp"
#include "fibonacci.hpp"

using namespace BT;
using namespace std;

class Speaking : public SyncActionNode {
    public:
    Speaking(
        const string & name,
        const NodeConfig & config
    ) : SyncActionNode(name, config) {}

    NodeStatus tick() override {
        string msg;
        if (getInput("message", msg)) {
            cout << "Speaking: " << msg << endl;
            return NodeStatus::SUCCESS;
        } else {
            cout << "Speaking FAILED" << endl;
            return NodeStatus::FAILURE;
        }
    }

    static PortsList providedPorts() {
        return {
            InputPort<string>("message")
        };
    }
};

static const char * xml_text = R"(
 <root BTCPP_format="3">
     <BehaviorTree>
        <Sequence>
            <FiboSeq message = "Sequence start with (0) 1 1."/>
            <Fibonacci name = "FiboAction" order = "10"/>
            <FiboSeq message = "Fibonacci sequence ended."/>
        </Sequence>
     </BehaviorTree>
 </root>
)";

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);

    BehaviorTreeFactory factory;
    
    auto node = std::make_shared<rclcpp::Node>("fibonacci_action_client");

    factory.registerNodeType<Speaking>("FiboSeq");
    
    RosNodeParams params; 
    params.nh = node;
    params.default_port_value = "fibonacci";
    
    factory.registerNodeType<FibonacciAction>("Fibonacci", params);
    
    auto tree = factory.createTreeFromText(xml_text);
    
    tree.tickWhileRunning();
    
    return 0;
}
