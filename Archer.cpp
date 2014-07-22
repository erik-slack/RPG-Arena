#include "Archer.h"
using namespace std;

// CONSTRUCTORS
Archer::Archer(string name2, int hit_points2, int strength2, int speed2, int magic2):Fighter(name2, hit_points2, strength2, speed2, magic2)
{
	//type = "A";
	original_speed = speed;
}

Archer::~Archer(){}

// MUTATORS
void Archer::reset()
{
	Fighter::reset();
	speed = original_speed; // Also resets an Archer's current speed to its original value.
}

bool Archer::useAbility() // Archer: Quickstep
{
	speed++; // Increases the Archer's speed by one point each time the ability is used.
	return true; // Return true if the ability was used; false otherwise. This ability always works; there is no maximum bonus speed.
	// This bonus lasts until the reset() method is used.
}

// ANALYZERS
int Archer::getDamage()
{
	int damage = speed; // Archer: This value is equal to the Archer's speed.
	return damage;
}
