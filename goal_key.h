#ifndef GOAL_KEY_H
#define GOAL_KEY_H
#include <godot_cpp/classes/sprite2d.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class GoalKey : public Sprite2D {
    GDCLASS(GoalKey, Sprite2D)

private:
    float detection_radius = 30.0f;

public:
    static void _bind_methods();

    void _process(double delta) override;

    void set_detection_radius(float radius);
    float get_detection_radius() const;

    void hide_key();

signals:
    void key_collected();
};

#endif