#pragma once

#include <windows.h>
#include <sstream>
#include <deque>
#include "Controller.hpp"
#include "Room.hpp"
#include "PlayManager.hpp"
#include "BulletBlock.hpp"
#include "Bullet.hpp"
#include "Battery.hpp"
#include "Vec2.hpp"
#include "Particle.hpp"
#include "Follower.hpp"

class Block;

class HowToPlayPlayerClone : public Object {
public:
    HowToPlayPlayerClone(const Vec2<double>& pos);
    virtual ~HowToPlayPlayerClone();
    void step() override;
    bool left_key, right_key, up_key, space_bar_key;

private:
    Vec2<double> velocity = { 0, 0 };
    double speed = 0.9, force = 0.15, gravity = 0.05, jump = 1.5;

    int time_recall_sleep_max = 100;
    int time_recall_gauge_max = 200;
    int time_recall_sleep = time_recall_sleep_max;
    int time_recall_gauge = 0;
    std::deque<Vec2<double>> player_pos_list;
    std::deque<Vec2<double>> player_velocity_list;

    int image_delay = 10;
    int image_remaining_delay = 0;
    int move_direction = 0;
    double move_value = 0;
};