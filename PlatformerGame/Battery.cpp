#include "Battery.hpp"

Battery::Battery(const Vec2<double>& pos) : Object(pos) {
    this->sprite_info.sprite_index = SpriteIndex::battery;
}

void Battery::step() {
    if (check_box_collision<Player>(Vec2<double>{0, 0}))
        room->del_instance(this);
}