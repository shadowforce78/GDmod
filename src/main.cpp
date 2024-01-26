#include <Geode/geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

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

        // Toggle the button
        if (buttonPressed == false)
        {
            buttonPressed = true;
            auto label = CCLabelBMFont::create("Noclip Enabled", "bigFont.fnt");
            label->setPosition(71, 272);
            label->setScale(0.5);
            label->setTag(1);
            label->setVisible(buttonPressed);
            this->addChild(label);
            //  "opcodes": [
            //         {"addr": "0x20A23C", "on": "E9 79 06 00 00", "off": "6A 14 8B CB FF"}
            //     ],

            

        }
        else
        {
            buttonPressed = false;
            this->removeChildByTag(1);

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
