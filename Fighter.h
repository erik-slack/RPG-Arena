#pragma once
#include "FighterInterface.h"
using namespace std;


class Fighter : public FighterInterface
{
public:
	// CONSTRUCTORS
	Fighter(string name, /*string type,*/ int mhp, int strength, int speed, int magic);
	~Fighter(void);

	// MUTATORS
	void takeDamage(int damage);
	virtual void reset();
	virtual void regenerate();
	virtual bool useAbility();

	// ANALYZERS
	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();

protected:
	// DATA
	string name;
	int hit_points, strength, speed, magic, currentHP;
};