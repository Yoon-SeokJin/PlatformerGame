#include "FlickingBlock.hpp"

FlickingBlockOn::FlickingBlockOn(const Vec2<double>& pos) : Block(pos) {
    sprite_info.sprite_index = SpriteIndex::flicking_block;
    sprite_info.image_index = 0;
}

void FlickingBlockOn::step() {
}

void FlickingBlockOn::toggle() {
    room->add_instance(new FlickingBlockOff(pos));
    room->del_instance(this);
}

FlickingBlockOff::FlickingBlockOff(const Vec2<double>& pos) : Object(pos) {
    sprite_info.sprite_index = SpriteIndex::flicking_block;
    sprite_info.image_index = 1;
}

void FlickingBlockOff::step() {
}

void FlickingBlockOff::toggle() {
    room->add_instance(new FlickingBlockOn(pos));
    room->del_instance(this);
}