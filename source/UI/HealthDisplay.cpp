#include "HealthDisplay.h"
#include <UnigineMathLib.h>

using namespace Unigine;
using namespace Math;

HealthDisplay::HealthDisplay()
{
    auto gui = Gui::getCurrent();

    const int max_health = 3;

    int sprite_width = 100;
    int sprite_height = 100;
    int spacing = 10;

    int total_width = max_health * sprite_width + (max_health - 1) * spacing;
    int icons_start_x = gui->getWidth() - total_width - 20;
    int top_y = 20;

    for (int i = 0; i < max_health; i++)
    {
        auto sprite = WidgetSprite::create(gui);
        sprite->setTexture("data/player/kimchi.png");
        sprite->setWidth(sprite_width);
        sprite->setHeight(sprite_height);

        int icon_x = icons_start_x + i * (sprite_width + spacing);
        sprite->setPosition(icon_x, top_y);

        gui->addChild(sprite, Gui::ALIGN_OVERLAP);
        health_sprites.append(sprite);
    }
}

HealthDisplay::~HealthDisplay()
{
    label.clear();
}

void HealthDisplay::setHealth(int current)
{
    for (int i = 0; i < health_sprites.size(); i++)
    {
        if (i < current)
            health_sprites[i]->setColor(vec4(1, 1, 1, 1));
        else
            health_sprites[i]->setColor(vec4(1, 1, 1, 0.2f)); 
    }
    //updateText();
}

void HealthDisplay::updateText()
{
    Unigine::String text = Unigine::String::format("Health: %d", current_health);
    label->setText(text);

    if (current_health <= 1)
        label->setFontColor(vec4(1.0f, 0.0f, 0.0f, 1.0f));
    else
        label->setFontColor(vec4(1.0f, 1.0f, 1.0f, 1.0f));
}

Unigine::WidgetLabelPtr HealthDisplay::getWidget() const
{
    return label;
}
