#include "behaviortree_cpp/bt_factory.h"
#include "put_in_the_fridge.h"

using namespace PUT_IN_THE_FRIDGE;
using namespace BT;

int main() {
    BehaviorTreeFactory factory;
    factory.registerNodeType<PutElephant>("PutElephant");
    factory.registerSimpleCondition("CheckFrige", [&](TreeNode&) {
        return CheckFridge();
    });
    FridgeDoor fridge_door;
    factory.registerSimpleAction("OpenFridge", [&](TreeNode&) {
        return fridge_door.open();
    });
    factory.registerSimpleAction("CloseFridge", [&](TreeNode&) {
        return fridge_door.close();
    });
    auto tree = factory.createTreeFromFile("src/bt_cpp/src/main_tree.xml");
    tree.tickWhileRunning();
    return 0;
}
