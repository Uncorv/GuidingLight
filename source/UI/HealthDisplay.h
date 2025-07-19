#pragma once
#include <UnigineWidgets.h>

class HealthDisplay
{
public:
    HealthDisplay();
    ~HealthDisplay();

    void setHealth(int current);

    Unigine::WidgetLabelPtr getWidget() const;

private:
    void updateText();

    int current_health = 3;
    Unigine::VectorStack<Unigine::WidgetSpritePtr> health_sprites;

    Unigine::WidgetLabelPtr label;
    Unigine::WidgetSpritePtr sprite;
};
