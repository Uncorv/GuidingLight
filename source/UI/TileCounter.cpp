#include "TileCounter.h"
#include <UnigineWorld.h>

using namespace Unigine;
using namespace Math;

TileCounter::TileCounter() : visited(0), total(0), current_level(1)
{
	freeze_state = World::getNodeByName("freeze_state");
	auto gui = Gui::getCurrent();

	label = WidgetLabel::create("Level: 1\nShadows Remaining: 100\n");
	label->setFontSize(40);
	label->setFontColor(Vec4(1.0f, 1.0f, 1.0f, 1.0f)); 
	label->setPosition(0, 20);
	label->arrange();

	updateText(); 

	// death_background = WidgetSprite::create(gui);
	// death_background->setTexture("core/textures/common/black.texture");
	// death_background->setPosition(0, 0);
	// death_background->setWidth(gui->getWidth());
	// death_background->setHeight(gui->getHeight());
	// death_background->setColor(vec4(0, 0, 0, 0)); 
	// gui->addChild(death_background, Gui::ALIGN_OVERLAP | Gui::ALIGN_EXPAND);

	// death_label = WidgetLabel::create(gui, "THE WAY IS LOST");
	// death_label->setFontSize(40);
	// death_label->setFontColor(vec4(1, 0, 0, 0));
	// death_label->setTextAlign(Gui::ALIGN_CENTER);
	// death_label->arrange();
	// death_label->setPosition(
	// 	(gui->getWidth() - death_label->getWidth()) / 2,
	// 	gui->getHeight() / 2
	// );
	// gui->addChild(death_label, Gui::ALIGN_OVERLAP);
}

TileCounter::~TileCounter()
{
	label.clear();
	// death_label.clear();
	// death_background.clear();
}

void TileCounter::updateCounter(int visitedTiles)
{
	visited = visitedTiles;
	updateText();
}

void TileCounter::setLevel(int level, int totalTiles)
{
	current_level = level;
	total = totalTiles;
	visited = 0;
	updateText();
}

void TileCounter::showDeathMessage()
{
	death_active = true;
	death_timer = 0.0f;
	// death_label->setFontColor(vec4(1, 0, 0, 1.0f));
	// death_background->setColor(vec4(0, 0, 0, 1.0f));

	showTheWayIsLost();
}

void TileCounter::update(float IFPS)
{
	if (!death_active)
		return;

	death_timer += IFPS;

	if (death_timer <= death_hold_duration)
	{
		// death_label->setFontColor(vec4(1, 0, 0, 1.0f));
		// death_background->setColor(vec4(0, 0, 0, 1.0f));
	}
	else
	{
		float fade_time = death_timer - death_hold_duration;
		float alpha = 1.0f - Math::clamp(fade_time / death_fade_duration, 0.0f, 1.0f);

		// death_label->setFontColor(vec4(1, 0, 0, alpha));
		// death_background->setColor(vec4(0, 0, 0, alpha));

		if (fade_time >= death_fade_duration)
		{
			death_active = false;
			hideTheWayIsLost();
		}
	}
}

void TileCounter::updateText()
{
	Unigine::String text = Unigine::String::format("Level: %d\nShadows Remaining: %d\n", current_level, total - visited);
	label->setText(text);

	if (visited >= total)
		label->setFontColor(Vec4(1.0f, 0.84f, 0.0f, 1.0f)); 
	else
		label->setFontColor(Vec4(1.0f, 1.0f, 1.0f, 1.0f));  
}

Unigine::WidgetLabelPtr TileCounter::getWidget() const
{
	return label;
}

void TileCounter::showTheWayIsLost()
{
	freeze_state->setEnabled(false);
	NodePtr the_way_is_lost = Unigine::World::getNodeByName("billboard_the_way_is_lost");
	NodePtr sound_the_way_is_lost = Unigine::World::getNodeByName("sound_the_way_is_lost");
	// Vec3 the_way_is_lost_pos = player->getWorldPosition();
	NodePtr player = Unigine::World::getNodeByName("player");
	Vec3 player_pos = player->getPosition();
	the_way_is_lost->setPosition(Vec3(player_pos.x, player_pos.y, 5.5f));
	the_way_is_lost->setEnabled(true);
	// sound_the_way_is_lost->setPosition(Vec3(player_pos.x, player_pos.y - 1.0f, 5.5f));
	// sound_the_way_is_lost->setEnabled(true);
}

void TileCounter::hideTheWayIsLost()
{
	NodePtr the_way_is_lost = Unigine::World::getNodeByName("billboard_the_way_is_lost");
	the_way_is_lost->setEnabled(false);
	freeze_state->setEnabled(true);
}