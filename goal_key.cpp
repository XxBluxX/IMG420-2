#include "goal_key.h"
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

void GoalKey::_bind_methods() {
    CLASSDB::bind_method(D_METHOD("set_detection_radius", "radius"), &GoalKey::set_detection_radius);
    CLASSDB::bind_method(D_METHOD("get_detection_radius"), &GoalKey::get_detection_radius);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "detection_radius"), "set_detection_radius", "get_detection_radius");

    ADD_SIGNAL(MethodInfo("key_collected"));
}

void GoalKey::set_detection_radius(float radius) {
    detection_radius = radius;
}

float GoalKey::get_detection_radius() const {
    return detection_radius;
}

void GaolKey::_process(double delta) {
    Node *player = get_node_or_null(/root/Node2D/Player);
    if (player) {
        Vector2 player_pos = ((Node2D *)player)->get_position();
        if (get_position().distance_to(player_pos) < detection_radius) {
            emit_signal("key_collected");
        }
    }
}

void GoalKey::hide_key() {
    set_visible(false);
}