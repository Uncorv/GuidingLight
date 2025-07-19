#include "LevelNumberStartDisplay.h"
#include <UnigineWorld.h>
#include <string>

using namespace Unigine;
using namespace Math;

LevelNumberStartDisplay::LevelNumberStartDisplay()
{
	freeze_state = World::getNodeByName("freeze_state");
}

LevelNumberStartDisplay::~LevelNumberStartDisplay()
{
	// nothing
}


void LevelNumberStartDisplay::showLevelBillbord(int level, bool need_freezing)
{
	elem_timer = 0.0f;
	elem_active = true;
	freezing = need_freezing;
	remember_level = level;
	showLevelNumber();
}

void LevelNumberStartDisplay::update(float IFPS)
{
	if (!elem_active)
		return;

	elem_timer += IFPS;

	if (elem_timer <= elem_hold_duration)
	{
		// death_label->setFontColor(vec4(1, 0, 0, 1.0f));
		// death_background->setColor(vec4(0, 0, 0, 1.0f));
	}
	else
	{
		float fade_time = elem_timer - elem_hold_duration;
		float alpha = 1.0f - Math::clamp(fade_time / elem_fade_duration, 0.0f, 1.0f);

		// death_label->setFontColor(vec4(1, 0, 0, alpha));
		// death_background->setColor(vec4(0, 0, 0, alpha));

		if (fade_time >= elem_fade_duration)
		{
			elem_active = false;
			hideLevelNumber();
		}
	}
}

void LevelNumberStartDisplay::showLevelNumber()
{
	if (freezing) {
		freeze_state->setEnabled(false);
	}

	std::string name = "billboard_level_" + std::to_string(remember_level);
	NodePtr billboard_level = Unigine::World::getNodeByName(name.c_str());
	// NodePtr sound_the_way_is_lost = Unigine::World::getNodeByName("sound_the_way_is_lost");
	NodePtr player = Unigine::World::getNodeByName("player");
	Vec3 player_pos = player->getPosition();
	billboard_level->setPosition(Vec3(player_pos.x, player_pos.y, 4.5f));
	billboard_level->setEnabled(true);
}

void LevelNumberStartDisplay::hideLevelNumber()
{
	std::string name = "billboard_level_" + std::to_string(remember_level);
	NodePtr billboard_level = Unigine::World::getNodeByName(name.c_str());
	billboard_level->setEnabled(false);

	if (freezing) {
		freeze_state->setEnabled(true);
	}
}