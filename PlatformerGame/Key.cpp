#include "Key.hpp"

Key::Key(const Vec2<double>& pos) : Object(pos) {
    sprite_info.sprite_index = SpriteIndex::key;
}

void Key::step() {
    for (Object* e : room->get_pool()) {
        if (Player* p = dynamic_cast<Player*>(e)) {
            if (is_box_collide({ 0, 0 }, p)) {
                room->key_flag = 1;
                room->del_instance(this);
                Object* target = nullptr;
                if (p->followers.empty())
                    target = p;
                else
                    target = p->followers.back();
                Follower* follower = new Follower(pos, SpriteIndex::key, 0, target);
                room->add_instance(follower);
                p->followers.push_back(follower);
            }
        }
    }
}