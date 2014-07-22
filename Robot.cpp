#include "Robot.h"
#include <cmath>
using namespace std;


// CONSTRUCTORS
Robot::Robot(string name2, int hit_points2, int strength2, int speed2, int magic2):Fighter(name2, hit_points2, strength2, speed2, magic2)
{
	//type = "R";
	max_energy = magic * 2;
	current_energy = max_energy;
	bonus_damage = 0;
}

Robot::~Robot(){}

// MUTATORS
void Robot::reset()
{
	Fighter::reset();

	current_energy = max_energy; // Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
	bonus_damage = 0; // Also resets a Robot's bonus damage to 0.
}

bool Robot::useAbility() // Robot: Shockwave Punch
{
	bonus_damage = 0;

	if (current_energy >= ROBOT_ABILITY_COST) // Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
	{
		// Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)). 
		// The bonus damage formula should be computed using double arithmetic, and only the final result should be cast into an integer.
		/*	Examples:
		*	strength=20, current_energy=20, maximum_energy=20	=>	bonus_damage=20
		*	strength=20, current_energy=15, maximum_energy=20	=>	bonus_damage=6
		*	strength=20, current_energy=10, maximum_energy=20	=>	bonus_damage=1
		*	strength=20, current_energy=5,  maximum_energy=20	=>	bonus_damage=0 */
		bonus_damage = (strength * (pow((current_energy / max_energy), 4))); 

		//Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
		current_energy = current_energy - ROBOT_ABILITY_COST;

		return true; // Return true if the ability was used; false otherwise.
	}
	else
	{
		return false;
	}
}


// ANALYZERS
int Robot::getDamage()
{
	// Robot: This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
	int damage = strength + bonus_damage;

	bonus_damage = 0;
	return damage;
}