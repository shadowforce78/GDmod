#include <Geode/geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <windows.h>
#include <imgui-cocos.hpp>

using namespace geode::prelude;

// $on_mod(Loaded) {
// When the mod is loaded, this code will be executed.
// }
bool menuImg = false;

class $modify(Test, PauseLayer){

    void onMySillyyBtn(CCObject * target){
        ImGuiCocos::get().setup([]
                                {
                                    menuImg = true;
                                    // this runs after imgui has been setup,
                                    // its a callback as imgui will be re initialized when toggling fullscreen,
                                    // so use this to setup any themes and or fonts!
                                })
            .draw([]
                    {
                        ImGui::Begin("Saumon's Mod");

                        ImGui::Button("Awesome button");

                        ImGui::End(); });
}
void customSetup()
{
    PauseLayer::customSetup();
    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_stopEditorBtn_001.png");
    auto button = CCMenuItemSpriteExtra::create(
        buttonSprite, nullptr, this,
        menu_selector(Test::onMySillyyBtn));

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition(462, 212);
    menu->setScale(0.75);
    this->addChild(menu);
}
}
;

class $modify(MyAwesomeModification, MenuLayer){

    void onMyButton(CCObject * target){

        FLAlertLayer::create(
            "Geode",
            "Hello World from my Custom Mod!",
            "OK")
            ->show();
}

bool init()
{
    if (!MenuLayer::init())
        return false;

    auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_stopEditorBtn_001.png");
    auto button = CCMenuItemSpriteExtra::create(
        buttonSprite, nullptr, this,
        menu_selector(MyAwesomeModification::onMyButton));

    auto menu = CCMenu::create();
    menu->addChild(button);
    menu->setPosition(-53, 227.750);
    menu->setScale(0.75);
    this->addChild(menu);

    return true;
}
}
;
