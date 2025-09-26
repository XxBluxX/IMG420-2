#ifndef ENEMY_SPIDER_H
#define ENEMY_SPIDER_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/classes/class_db.hpp>

using namespace godot;

class EnemySpider : public Sprite2D {
    GDCLASS(EnemySpider, Sprite2D)

private:
    float speed = 100.0f;
    bool active = true;

public:
    static void _bind_methods();

    void _process(double delta) override;

    void set_speed(float p_speed);
    float get_speed() const;

    void freeze();

signals:
    void player_touched();
};

#endif