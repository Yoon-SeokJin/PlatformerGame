#include "StageSelection.hpp"

StageSelection::StageSelection(const Vec2<double>& pos) : Object(pos) {
    sprite_info.sprite_index = SpriteIndex::stage_selection;
    int star0 = 20, star3 = 20;
    for (int i = 19; i >= 0; --i) {
        if (PlayManager::instance().star_count[i] == 0)
            star0 = i;
        if (PlayManager::instance().star_count[i] < 3)
            star3 = i;
    }
    if (star3 == 20)
        focus = 0;
    else if (star0 == 20)
        focus = star3;
    else
        focus = star0;
}

void StageSelection::step() {
    if (!level_button_create) {
        level_button_create = true;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 5; ++j) {
                room->add_instance(stage[i * 5 + j] = new GuiButton(Vec2<int>{30, 20} *Vec2<int>{ j - 2, i - 1 }, SpriteIndex::gui_level_button));
                room->add_instance(new Sticker(stage[i * 5 + j]->get_pos(), SpriteIndex::text_stage_number, i * 5 + j + 1, stage[i * 5 + j]));
                for (int k = 0; k < PlayManager::instance().star_count[i * 5 + j]; ++k) {
                    room->add_instance(new Sticker(stage[i * 5 + j]->get_pos() + Vec2<int>{ -6 + 6 * k, 8 }, SpriteIndex::star, 0, stage[i * 5 + j]));
                }
            }
        }
        stage[focus]->focus();
    }
    else if (level_button_create && !selected) {
        int nxt_focus = focus;
        if (Controller::instance().key_pressed(VK_UP))
            nxt_focus -= 5;
        if (Controller::instance().key_pressed(VK_DOWN))
            nxt_focus += 5;
        if (Controller::instance().key_pressed(VK_LEFT))
            nxt_focus -= 1;
        if (Controller::instance().key_pressed(VK_RIGHT))
            nxt_focus += 1;
        if (nxt_focus != focus && nxt_focus >= 0 && nxt_focus < 20) {
            stage[focus]->unfocus();
            focus = nxt_focus;
            stage[focus]->focus();
        }
        if (Controller::instance().key_pressed(VK_RETURN)) {
            stage[focus]->trigger();
            selected = true;
        }
    }
    else if (selected) {
        if (stage[focus]->is_trigger_end) {
            RoomIndex stage_to_room_index[20] = {
                RoomIndex::stage1,RoomIndex::stage2,RoomIndex::stage3,RoomIndex::stage4,RoomIndex::stage5,
                RoomIndex::stage6,RoomIndex::stage7,RoomIndex::stage8,RoomIndex::stage9,RoomIndex::stage10,
                RoomIndex::stage11,RoomIndex::stage12,RoomIndex::stage13,RoomIndex::stage14,RoomIndex::stage15,
                RoomIndex::stage16,RoomIndex::stage17,RoomIndex::stage18,RoomIndex::stage19,RoomIndex::stage20,
            };
            PlayManager::instance().set_room(stage_to_room_index[focus]);
        }
    }
    if (Controller::instance().key_pressed(VK_ESCAPE) ||
        Controller::instance().key_pressed(VK_BACK) ||
        Controller::instance().key_pressed('X'))
        PlayManager::instance().set_room(RoomIndex::title);
}