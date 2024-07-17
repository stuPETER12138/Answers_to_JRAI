#ifndef PUT_IN_THE_FRIDGE_H
#define PUT_IN_THE_FRIDGE_H

#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/behavior_tree.h"

namespace PUT_IN_THE_FRIDGE {

    using BT::NodeStatus;

    NodeStatus CheckFridge();

    class FridgeDoor {
        public:
        FridgeDoor() : _opened(true) {}
        NodeStatus open();
        NodeStatus close();
        private:
        bool _opened;
    };

    class PutElephant : public BT::SyncActionNode {
        public:
        PutElephant(const std::string & name) : BT::SyncActionNode(name, {}) {}
        NodeStatus tick() override;
    };

    inline void RegisterNodes(BT::BehaviorTreeFactory& factory) {
        static FridgeDoor fridge_door;
        factory.registerSimpleCondition(
            "CheckFridge",
            std::bind(CheckFridge));
        factory.registerSimpleAction(
            "OpenFridge",
            std::bind(&FridgeDoor::open, & fridge_door));
        factory.registerSimpleAction(
            "CloseFridge",
            std::bind(&FridgeDoor::close, & fridge_door));
        factory.registerNodeType<PutElephant>("PutElephant");
    }
}

#endif  // PUT_IN_THE_FRIDGE_H
