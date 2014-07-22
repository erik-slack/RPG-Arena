#pragma once
#include "Fighter.h"

using namespace std;

class Robot : public Fighter
{
public:
	// CONSTRUCTORS
	Robot(string name2, int hit_points2, int strength2, int speed2, int magic2);
	~Robot();
	
	// MUTATORS
	void reset();
	bool useAbility();

	// ANALYZERS
	int getDamage();

private:
	// DATA
	int max_energy;
	double current_energy;
	int bonus_damage;
};