#include "enemy_spider.h"
#include <godot_spp/classes/node2s.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

void EnemySpider::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_speed", "speed"), &EnemySpider::set_speed)
    CLASSDB::bind_method(D_METHOD("get_speed"), &EnemySpider::get_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");

    ADD_SIGNAL(MethodInfo("player_touched"));
}

void EnemySpider::set_speed(float p_speed) {
    speed = p_speed;
}

float EnemySpider::get_speed() const {
    return speed;
}

void EnemySpider::_process(double delta) {
    if (!active) return;

    Vector2 pos = get_position();
    pos.x += speed * delta;
    set_position(pos);

    if (pos.x < 0 || pos.x > 480) {
        speed = -speed;
    }

    Node *player = get_node_or_null("/root/node2D/Player");
    if (player) {
        Vector2 player_pos = ((Node2D *)player)->get_position();
        if (pos.distance_to(player_pos) < 20.0f) {
            emit_signal(player_touched);
        }
    }
}

void EnemySpider::freeze() {
    active = false;
}