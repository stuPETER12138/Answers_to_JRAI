#include "put_in_the_fridge.h"

BT_REGISTER_NODES(factory) {
    PUT_IN_THE_FRIDGE::RegisterNodes(factory);
}

namespace PUT_IN_THE_FRIDGE {

    using BT::NodeStatus;
    using namespace std;

    NodeStatus CheckFridge() {
        cout << "Fridge is empty." << endl;
        return NodeStatus::SUCCESS;
    }

    NodeStatus FridgeDoor::open() {
        _opened = true;
        cout << "Fridge door is opened." << endl;
        return NodeStatus::SUCCESS;
    }

    NodeStatus FridgeDoor::close() {
        _opened = false;
        cout << "Fridge door is closed." << endl;
        return NodeStatus::SUCCESS;
    }

    NodeStatus PutElephant::tick() {
        std::cout << "Elephant is " << this->name() << std::endl;
        return BT::NodeStatus::SUCCESS;
    }
}
