#include "behaviortree_ros2/bt_action_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/executors.hpp"
#include "behaviortree_ros2/plugins.hpp"
#include "fibonacci.hpp"

using namespace BT;
using namespace std;

class FibonacciSequence : public SyncActionNode {
    public:
    FibonacciSequence(
        const string & name,
        const NodeConfig & config
    ) : SyncActionNode(name, config) {}

    NodeStatus tick() override {
        string msg;
        if (getInput("message", msg)) {
            cout << "FibonacciSequence: " << msg << endl;
            return NodeStatus::SUCCESS;
        } else {
            cout << "FibonacciSequence FAILED" << endl;
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
 <root BTCPP_format="4">
     <BehaviorTree>
        <Sequence>
            <PrintValue message="start"/>
            <SleepAction name="sleepA" msec="2000"/>
            <PrintValue message="sleep completed"/>
            <Fallback>
                <Timeout msec="1500">
                   <SleepAction name="sleepB" action_name="sleep_service" msec="2000"/>
                </Timeout>
                <PrintValue message="sleep aborted"/>
            </Fallback>
        </Sequence>
     </BehaviorTree>
 </root>
)";

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);

    BehaviorTreeFactory factory;
    
    auto node = std::make_shared<rclcpp::Node>("fibonacci_action_client");
    
    RosNodeParams params; 
    params.nh = node;
    params.default_port_value = "fibonacci";
    
    factory.registerNodeType<FibonacciAction>("Fibonacci", params);
    
    auto tree = factory.createTreeFromText(xml_text);
    
    tree.tickWhileRunning();
    
    return 0;
}
