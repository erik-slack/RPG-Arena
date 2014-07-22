#include "Fighter.h"
using namespace std;


// CONSTRUCTORS
Fighter::Fighter(string name2, int hit_points2, int strength2, int speed2, int magic2)
{
	name = name2;
	hit_points = hit_points2;
	strength = strength2;
	speed = speed2;
	magic = magic2;
	currentHP = hit_points;
}

Fighter::~Fighter(void) {}

// MUTATORS
void Fighter::takeDamage(int damage)
{
	// Reduces the fighter's current hit points by an amount equal to the given damage minus one fourth of the fighter's speed.
	/*Examples:
	*	damage=10, speed=7	=> damage_taken=9
	*	damage=10, speed=9	=> damage_taken=8
	*	damage=10, speed=50	=> damage_taken=1
	*/
	int total_damage = (damage - (speed / 4));

	if (total_damage < 1) // This method must reduce the fighter's current hit points by at least one.
	{
		currentHP = currentHP - 1;
	}
	else
	{
		currentHP = currentHP - total_damage; // It is acceptable for this method to give the fighter negative current hit points.
	}
}

void Fighter::reset()
{
	currentHP = hit_points; // Restores a fighter's current hit points to its maximum hit points.
}

void Fighter::regenerate()
{
	// Increases the fighter's current hit points by an amount equal to one sixth of the fighter's strength.
	int increaseHP = (strength / 6);

	if(increaseHP < 1) // This method must increase the fighter's current hit points by at least one.
	{
		increaseHP = 1;
	}

	currentHP = currentHP + increaseHP;

	if(currentHP > hit_points) // Do not allow the current hit points to exceed the maximum hit points.
	{
		currentHP = hit_points;
	}
}

bool Fighter::useAbility()
{
	/*
		Attempts to perform a special ability based on the type of fighter.  
		The fighter will attempt to use this special ability just prior to attacking every turn.
		Return true if the ability was used; false otherwise.
	*/
	return false;
}

// ANALYZERS
string Fighter::getName()
{
	return name; // Returns the name of this fighter.
}

int Fighter::getMaximumHP()
{
	return hit_points; // Returns the maximum hit points of this fighter.
}

int Fighter::getCurrentHP()
{
	return currentHP; // Returns the current hit points of this fighter.
}

int Fighter::getStrength()
{
	return strength; // Returns the strength stat of this fighter.
}

int Fighter::getSpeed()
{
	return speed; // Returns the speed stat of this fighter.
}

int Fighter::getMagic()
{
	return magic; // Returns the magic stat of this fighter.
}