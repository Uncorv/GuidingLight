#include <UnigineWidgets.h>
#include <UnigineGame.h>

class TileCounter
{
public:
	TileCounter();
	~TileCounter();

	void updateCounter(int visitedTiles);
	void setLevel(int level, int totalTiles);
	void showDeathMessage();
	void update(float IFPS);

	Unigine::WidgetLabelPtr getWidget() const;

private:
	void updateText();
	void showTheWayIsLost();
	void hideTheWayIsLost();

	int visited;
	int total;
	int current_level;

	Unigine::NodePtr freeze_state;
	Unigine::WidgetLabelPtr label;
	// Unigine::WidgetLabelPtr death_label;
	// Unigine::WidgetSpritePtr death_background;
	float death_timer = 0.0f;
	bool death_active = false;


	float death_hold_duration = 2.0f;
	float death_fade_duration = 1.5f; 
};