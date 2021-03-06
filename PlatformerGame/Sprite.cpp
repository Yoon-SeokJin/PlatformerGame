#include "Sprite.hpp"

SpriteArchive& SpriteArchive::instance() {
    static SpriteArchive instance;
    return instance;
};

const Sprite& SpriteArchive::get_sprite(SpriteIndex SpriteIndex) {
    return sprite[(int)SpriteIndex];
}

SpriteArchive::SpriteArchive() {
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Player0.bmp)");
        importer.read_bmp24(R"(Player1.bmp)");
        importer.read_bmp24(R"(Player2.bmp)");
        importer.read_bmp24(R"(Player3.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::player].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::player].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::player].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::player].size = { w, h };
        sprite[(int)SpriteIndex::player].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(PlayerJump0.bmp)");
        importer.read_bmp24(R"(PlayerJump1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::player_jump].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::player_jump].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::player_jump].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::player_jump].size = { w, h };
        sprite[(int)SpriteIndex::player_jump].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(PlayerDie0.bmp)");
        importer.read_bmp24(R"(PlayerDie1.bmp)");
        importer.read_bmp24(R"(PlayerDie2.bmp)");
        importer.read_bmp24(R"(PlayerDie3.bmp)");
        importer.read_bmp24(R"(PlayerDie4.bmp)");
        importer.read_bmp24(R"(PlayerDie5.bmp)");
        importer.read_bmp24(R"(PlayerDie6.bmp)");
        importer.read_bmp24(R"(PlayerDie7.bmp)");
        importer.read_bmp24(R"(PlayerDie8.bmp)");
        importer.read_bmp24(R"(PlayerDie9.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::player_die].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::player_die].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::player_die].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::player_die].size = { w, h };
        sprite[(int)SpriteIndex::player_die].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Block0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::block].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::block].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::block].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::block].size = { w, h };
        sprite[(int)SpriteIndex::block].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(BulletBlock0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::bullet_block].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::bullet_block].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::bullet_block].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::bullet_block].size = { w, h };
        sprite[(int)SpriteIndex::bullet_block].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Bullet0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::bullet].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::bullet].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::bullet].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::bullet].size = { w, h };
        sprite[(int)SpriteIndex::bullet].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(LaserBlock0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::laser_block].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::laser_block].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::laser_block].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::laser_block].size = { w, h };
        sprite[(int)SpriteIndex::laser_block].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Battery0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::battery].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::battery].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::battery].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::battery].size = { w, h };
        sprite[(int)SpriteIndex::battery].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Key0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::key].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::key].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::key].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::key].size = { w, h };
        sprite[(int)SpriteIndex::key].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Goal0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::goal].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::goal].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::goal].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::goal].size = { w, h };
        sprite[(int)SpriteIndex::goal].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Title0.bmp)");
        importer.read_bmp24(R"(Title1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::title].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::title].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::title].center = { 0, 0 };
        sprite[(int)SpriteIndex::title].size = { w, h };
        sprite[(int)SpriteIndex::title].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(HowToPlayText0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::how_to_play_text].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::how_to_play_text].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::how_to_play_text].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::how_to_play_text].size = { w, h };
        sprite[(int)SpriteIndex::how_to_play_text].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(HowToPlayKey0.bmp)");
        importer.read_bmp24(R"(HowToPlayKey1.bmp)");
        importer.read_bmp24(R"(HowToPlayKey2.bmp)");
        importer.read_bmp24(R"(HowToPlayKey3.bmp)");
        importer.read_bmp24(R"(HowToPlayKey4.bmp)");
        importer.read_bmp24(R"(HowToPlayKey5.bmp)");
        importer.read_bmp24(R"(HowToPlayKey6.bmp)");
        importer.read_bmp24(R"(HowToPlayKey7.bmp)");
        importer.read_bmp24(R"(HowToPlayKey8.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::how_to_play_key].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::how_to_play_key].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::how_to_play_key].center = { w, h / 2 };
        sprite[(int)SpriteIndex::how_to_play_key].size = { w, h };
        sprite[(int)SpriteIndex::how_to_play_key].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(HowToPlayArrow0.bmp)");
        importer.read_bmp24(R"(HowToPlayArrow1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::how_to_play_arrow].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::how_to_play_arrow].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::how_to_play_arrow].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::how_to_play_arrow].size = { w, h };
        sprite[(int)SpriteIndex::how_to_play_arrow].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(HowToPlayCircle0.bmp)");
        importer.read_bmp24(R"(HowToPlayCircle1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::how_to_play_circle].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::how_to_play_circle].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::how_to_play_circle].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::how_to_play_circle].size = { w, h };
        sprite[(int)SpriteIndex::how_to_play_circle].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(HowToPlaySpaceBar0.bmp)");
        importer.read_bmp24(R"(HowToPlaySpaceBar1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::how_to_play_space_bar].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::how_to_play_space_bar].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::how_to_play_space_bar].center = { w, h / 2 };
        sprite[(int)SpriteIndex::how_to_play_space_bar].size = { w, h };
        sprite[(int)SpriteIndex::how_to_play_space_bar].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(HowToPlayInformation0.bmp)");
        importer.read_bmp24(R"(HowToPlayInformation1.bmp)");
        importer.read_bmp24(R"(HowToPlayInformation2.bmp)");
        importer.read_bmp24(R"(HowToPlayInformation3.bmp)");
        importer.read_bmp24(R"(HowToPlayInformation4.bmp)");
        importer.read_bmp24(R"(HowToPlayInformation5.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::how_to_play_information].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::how_to_play_information].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::how_to_play_information].center = { 0, h / 2 };
        sprite[(int)SpriteIndex::how_to_play_information].size = { w, h };
        sprite[(int)SpriteIndex::how_to_play_information].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(StageSelectionText0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::stage_selection_text].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::stage_selection_text].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::stage_selection_text].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::stage_selection_text].size = { w, h };
        sprite[(int)SpriteIndex::stage_selection_text].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(StageSelectionDifficulty0.bmp)");
        importer.read_bmp24(R"(StageSelectionDifficulty1.bmp)");
        importer.read_bmp24(R"(StageSelectionDifficulty2.bmp)");
        importer.read_bmp24(R"(StageSelectionDifficulty3.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::stage_selection_difficulty].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::stage_selection_difficulty].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::stage_selection_difficulty].center = { w, h / 2 };
        sprite[(int)SpriteIndex::stage_selection_difficulty].size = { w, h };
        sprite[(int)SpriteIndex::stage_selection_difficulty].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(StageSelectionLock0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::stage_selection_lock].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::stage_selection_lock].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::stage_selection_lock].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::stage_selection_lock].size = { w, h };
        sprite[(int)SpriteIndex::stage_selection_lock].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(BreakableBlock0.bmp)");
        importer.read_bmp24(R"(BreakableBlock1.bmp)");
        importer.read_bmp24(R"(BreakableBlock2.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::breakable_block].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::breakable_block].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::breakable_block].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::breakable_block].size = { w, h };
        sprite[(int)SpriteIndex::breakable_block].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Button0.bmp)");
        importer.read_bmp24(R"(Button1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::button].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::button].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::button].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::button].size = { w, h };
        sprite[(int)SpriteIndex::button].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(ButtonBlock0.bmp)");
        importer.read_bmp24(R"(ButtonBlock1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::button_block].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::button_block].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::button_block].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::button_block].size = { w, h };
        sprite[(int)SpriteIndex::button_block].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(FlickingBlock0.bmp)");
        importer.read_bmp24(R"(FlickingBlock1.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::flicking_block].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::flicking_block].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::flicking_block].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::flicking_block].size = { w, h };
        sprite[(int)SpriteIndex::flicking_block].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(GuiMenuButton0.bmp)");
        importer.read_bmp24(R"(GuiMenuButton1.bmp)");
        importer.read_bmp24(R"(GuiMenuButton2.bmp)");
        importer.read_bmp24(R"(GuiMenuButton3.bmp)");
        importer.read_bmp24(R"(GuiMenuButton4.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::gui_menu_button].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::gui_menu_button].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::gui_menu_button].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::gui_menu_button].size = { w, h };
        sprite[(int)SpriteIndex::gui_menu_button].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(GuiLevelButton0.bmp)");
        importer.read_bmp24(R"(GuiLevelButton1.bmp)");
        importer.read_bmp24(R"(GuiLevelButton2.bmp)");
        importer.read_bmp24(R"(GuiLevelButton3.bmp)");
        importer.read_bmp24(R"(GuiLevelButton4.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::gui_level_button].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::gui_level_button].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::gui_level_button].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::gui_level_button].size = { w, h };
        sprite[(int)SpriteIndex::gui_level_button].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(TextStart0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::text_start].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::text_start].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::text_start].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::text_start].size = { w, h };
        sprite[(int)SpriteIndex::text_start].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(TextHow0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::text_how].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::text_how].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::text_how].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::text_how].size = { w, h };
        sprite[(int)SpriteIndex::text_how].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(TextExit0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::text_exit].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::text_exit].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::text_exit].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::text_exit].size = { w, h };
        sprite[(int)SpriteIndex::text_exit].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(TextStageNumber0.bmp)");
        importer.read_bmp24(R"(TextStageNumber1.bmp)");
        importer.read_bmp24(R"(TextStageNumber2.bmp)");
        importer.read_bmp24(R"(TextStageNumber3.bmp)");
        importer.read_bmp24(R"(TextStageNumber4.bmp)");
        importer.read_bmp24(R"(TextStageNumber5.bmp)");
        importer.read_bmp24(R"(TextStageNumber6.bmp)");
        importer.read_bmp24(R"(TextStageNumber7.bmp)");
        importer.read_bmp24(R"(TextStageNumber8.bmp)");
        importer.read_bmp24(R"(TextStageNumber9.bmp)");
        importer.read_bmp24(R"(TextStageNumber10.bmp)");
        importer.read_bmp24(R"(TextStageNumber11.bmp)");
        importer.read_bmp24(R"(TextStageNumber12.bmp)");
        importer.read_bmp24(R"(TextStageNumber13.bmp)");
        importer.read_bmp24(R"(TextStageNumber14.bmp)");
        importer.read_bmp24(R"(TextStageNumber15.bmp)");
        importer.read_bmp24(R"(TextStageNumber16.bmp)");
        importer.read_bmp24(R"(TextStageNumber17.bmp)");
        importer.read_bmp24(R"(TextStageNumber18.bmp)");
        importer.read_bmp24(R"(TextStageNumber19.bmp)");
        importer.read_bmp24(R"(TextStageNumber20.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::text_stage_number].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::text_stage_number].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::text_stage_number].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::text_stage_number].size = { w, h };
        sprite[(int)SpriteIndex::text_stage_number].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Star0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::star].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::star].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::star].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::star].size = { w, h };
        sprite[(int)SpriteIndex::star].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Pause0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::pause].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::pause].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::pause].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::pause].size = { w, h };
        sprite[(int)SpriteIndex::pause].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(Information0.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::information].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::information].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::information].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::information].size = { w, h };
        sprite[(int)SpriteIndex::information].number = n;
    }
    {
        SpriteImporter importer;
        importer.read_bmp24(R"(InformationText0.bmp)");
        importer.read_bmp24(R"(InformationText1.bmp)");
        importer.read_bmp24(R"(InformationText2.bmp)");
        importer.read_bmp24(R"(InformationText3.bmp)");
        importer.read_bmp24(R"(InformationText4.bmp)");
        importer.read_bmp24(R"(InformationText5.bmp)");
        importer.read_bmp24(R"(InformationText6.bmp)");
        importer.read_bmp24(R"(InformationText7.bmp)");
        importer.read_bmp24(R"(InformationText8.bmp)");
        auto [spr, w, h, n] = importer.get();
        sprite[(int)SpriteIndex::information_text].alpha = new int[w * h * n];
        memcpy(sprite[(int)SpriteIndex::information_text].alpha, spr, sizeof(int) * w * h * n);
        sprite[(int)SpriteIndex::information_text].center = { w / 2, h / 2 };
        sprite[(int)SpriteIndex::information_text].size = { w, h };
        sprite[(int)SpriteIndex::information_text].number = n;
    }
    {
        int w = 0, h = 0, n = 0;
        sprite[(int)SpriteIndex::none].alpha = nullptr;
        sprite[(int)SpriteIndex::none].center = {0, 0};
        sprite[(int)SpriteIndex::none].size = {0, 0};
        sprite[(int)SpriteIndex::none].number = n;
    }
}