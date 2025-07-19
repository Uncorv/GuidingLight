#include <UnigineWidgets.h>
#include <UnigineGame.h>

class LevelNumberStartDisplay
{
public:
	LevelNumberStartDisplay();
	~LevelNumberStartDisplay();

	void showLevelBillbord(int level, bool need_freezing);
	void update(float IFPS);


private:
	void showLevelNumber();
	void hideLevelNumber();

	Unigine::NodePtr freeze_state;

	int remember_level;
	bool freezing;

	float elem_timer = 0.0f;
	bool elem_active = false;

	float elem_hold_duration = 1.0f;
	float elem_fade_duration = 0.5f;
};