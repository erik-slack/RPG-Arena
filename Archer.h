#pragma once
#include "Fighter.h"
using namespace std;


class Archer : public Fighter
{
public:
	// CONSTRUCTORS
	Archer(string name2, int hit_points2, int strength2, int speed2, int magic2);
	~Archer();

	// MUTATORS
	void reset();
	bool useAbility();	

	// ANALYZERS
	int getDamage();

private:
	// DATA
	int original_speed;
};
