#pragma once
#include "Fighter.h"

using namespace std;

class Cleric : public Fighter
{
public:
	// CONSTRUCTORS
	Cleric(string name2, int hit_points2, int strength2, int speed2, int magic2);
	~Cleric();

	// MUTATORS
	void reset();
	bool useAbility();
	void regenerate();

	// ANALYZERS
	int getDamage();

private:
	// DATA
	int mana;
	int max_mana;
};

