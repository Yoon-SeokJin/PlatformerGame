#include "PlayManager.hpp"

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

PlayManager& PlayManager::instance() {
    static PlayManager instance;
    return instance;
}

void PlayManager::play() {
    load_data();
    Console console;
    console.hide_cursor();
    console.set_font_size(8);
    console.set_screen_size(Vec2<int>{ 16, 9 } * 12);
    console.fix_screen_size();
    View view;
    while (true) {
        Room room(Vec2<int>{ 16, 9 } * 12);
        room.add_instance(new RoomConstructor({ 0, 0 }, current_room));
        room.step();
        room.step();
        room.step();
        restart_room = false;
        restart_room_effect = 0;
        while (true) {
            Controller::instance().step();
            if (int room_index = static_cast<int>(current_room);
                room_index >= static_cast<int>(RoomIndex::stage1) && room_index <= static_cast<int>(RoomIndex::stage20)) {
                if (Controller::instance().key_pressed('P'))
                    is_pause = !is_pause;
                else if (Controller::instance().key_pressed(VK_ESCAPE)) {
                    is_pause = false;
                    set_room(RoomIndex::stage_selection);
                }
            }
            if ((restart_room || restart_room_effect == restart_room_effect_max) && !is_pause)
                room.step();
            if (restart_room && restart_room_effect == restart_room_effect_max) break;
            if (restart_room_effect < restart_room_effect_max)
                ++restart_room_effect;
            //str.emplace_back("frame_stacked");
            if (!frame_skip_or_waiting()) {
                view.clear();
                view.draw(room);
                console.clear();
                console.set_alpha_board(view, { 0, 0 }, Vec2<int>{16, 9} *12);
                console.apply_alpha_board_restart_room_effect(1.0 * restart_room_effect / restart_room_effect_max, restart_room);
                if (is_pause) console.apply_alpha_board_pause_effect();
                console.set_char_board_from_alpha_board();
                //str.emplace_back("fps : " + to_string(fps));
                //str.emplace_back("fps_real : " + to_string(fps_real));
                //str.emplace_back("delayed_time : " + to_string(delayed_time.count()));
                //for (int i = 0; i < ssize(str); ++i)
                //    console.set_char_board(str[i], i);
                //str.clear();
                console.draw();
            }
        }
    }
}

void PlayManager::set_room(RoomIndex room) {
    if (restart_room) return;
    current_room = room;
    restart_room = true;
    restart_room_effect = 0;
}

RoomIndex PlayManager::get_room() {
    return current_room;
}

PlayManager::PlayManager() {
    previous_time = high_resolution_clock::now();
    previous_time_real = high_resolution_clock::now();
    delayed_time = 0s;
    for (int i = 0; i < 20; ++i)
        stage_star_count[i] = 0;
}

bool PlayManager::frame_skip_or_waiting() {
    auto current_time = high_resolution_clock::now();
    auto second_per_frame = 1000ms / fps_standard;
    delayed_time += duration<double, milli>(current_time - previous_time) - second_per_frame;

    fps = 1000 / duration<double, milli>(current_time - previous_time).count();
    fps_real = 1000 / duration<double, milli>(current_time - previous_time_real).count();

    previous_time = high_resolution_clock::now();
    if (delayed_time > second_per_frame * 2) return true;
    if (delayed_time < 0ms) this_thread::sleep_for(-delayed_time);
    previous_time_real = high_resolution_clock::now();
    return false;
}

void PlayManager::save_data() {
    std::ofstream write_file;
    write_file.open("Recall_Save_Data.txt");
    if (write_file.is_open())
        for (int i = 0; i < 20; ++i)
            write_file << stage_star_count[i] << ' ';
    write_file.close();
}

void PlayManager::load_data() {
    ifstream read_file;
    read_file.open("Recall_Save_Data.txt");
    if (read_file) {
        if (read_file.is_open()) {
            for (int i = 0; i < 20; ++i) {
                if (read_file.eof()) throw "The save file is corrupt.";
                read_file >> stage_star_count[i];
            }
            int tmp;
            if (read_file >> tmp) throw "The save file is corrupt.";
            for (int i = 0; i < 20; ++i)
                if (stage_star_count[i] < 0 || stage_star_count[i] > 3)
                    throw "The save file is corrupt.";
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    if (stage_star_count[i * 5 + j] == 0 && stage_star_count[i * 5 + j + 1] > 0)
                        throw "The save file is corrupt.";
            for (int i = 0; i < 3; ++i)
                if (stage_star_count[4] == 0 && stage_star_count[i * 5 + 5] > 0)
                    throw "The save file is corrupt.";
        }
        else
            throw "Can't open the save file.";
    }
    else {
        save_data();
    }
}