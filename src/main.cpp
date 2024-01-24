#include <Geode/geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;
//  "opcodes": [
//         {"addr": "0x20A23C", "on": "E9 79 06 00 00", "off": "6A 14 8B CB FF"}
//     ],

class $modify(Test, PauseLayer){
    void onMySillyyBtn(CCObject * target){
        // FLAlertLayer::create(
        //     "Geode",
        //     "Hello World from my Custom Mod!",
        //     "OK")
        //     ->show();

        // Make a toggable text label
        auto label = CCLabelBMFont::create("Hello World!", "bigFont.fnt");
        label->setPosition(100, 100);
        label->setScale(0.5);
        label->setTag(1);
        this->addChild(label);

        

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
