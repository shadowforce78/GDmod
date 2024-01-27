#include <Geode/geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <windows.h>

#define addr 0x20A23C
#define onaddr "\xE9\x79\x06\x00\x00"
#define offaddr "\x6A\x14\x8B\xCB\xFF"

using namespace geode::prelude;

class $modify(Test, PauseLayer)
{
    bool buttonPressed = false;
    void onMySillyyBtn(CCObject * target)
    {
        // FLAlertLayer::create(
        //     "Geode",
        //     "Hello World from my Custom Mod!",
        //     "OK")
        //     ->show();

        // If button is pressed set buttonPressed to true

        if (buttonPressed == false)
        {
            // If button is pressed set buttonPressed to true
            bool buttonPressed = false;
            // Write to memory
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)addr, onaddr, 5, 0);
        }
        else
        {
            // If button is pressed set buttonPressed to true
            bool buttonPressed = false;
            // Write to memory
            WriteProcessMemory(GetCurrentProcess(), (LPVOID)addr, offaddr, 5, 0);
        }
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

        // If button is pressed show label
        if (buttonPressed == true)
        {

            auto label = CCLabelBMFont::create("Noclip Enabled", "bigFont.fnt");
            label->setPosition(71, 272);
            label->setScale(0.5);
            label->setTag(1);
            label->setVisible(buttonPressed);
            this->addChild(label);
        }
        else
        {
            this->removeChildByTag(1);
        }
    }
};

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
