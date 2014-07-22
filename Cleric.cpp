#include "Cleric.h"
using namespace std;


// CONSTRUCTORS
Cleric::Cleric(string name2, int hit_points2, int strength2, int speed2, int magic2):Fighter(name2, hit_points2, strength2, speed2, magic2)
{
	//type = "C";
	mana = magic * 5;
	max_mana = magic * 5;
}

Cleric::~Cleric(){}

// MUTATORS
void Cleric::reset()
{
	Fighter::reset();
	mana = max_mana; // Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
}

void Cleric::regenerate()
{
	Fighter::regenerate();

	int mana_increase = (magic / 5); // Also increases a Cleric's current mana by an amount equal to one fifth of the Cleric's magic.

	if (mana_increase < 1 )
	{
		mana_increase = 1; // This method must increase the Cleric's current mana by at least one.
	}

	mana = mana + mana_increase; 

	if (mana > max_mana) // Do not allow the current mana to exceed the maximum mana.
	{
		mana = max_mana;
	}
}

bool Cleric::useAbility() //Cleric: Healing Light
{	
	if (mana >= CLERIC_ABILITY_COST) // Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
	{
		int increaseHP = (magic / 3); // Increases the Cleric's current hit points by an amount equal to one third of its magic.
		mana = mana - CLERIC_ABILITY_COST; // Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
		
		if (increaseHP < 1 ) // This ability, when successful, must increase the Cleric's current hit points by at least one.  
		{
			increaseHP = 1;
		}

		currentHP = currentHP + increaseHP; // Will be used even if the Cleric's current HP is equal to their maximum HP.

		if (currentHP > hit_points) // Do not allow the current hit points to exceed the maximum hit points.
		{
			currentHP = hit_points;
		}
		
		return true; // Return true if the ability was used; false otherwise.
	}
	else
	{
		return false;
	}

}

// ANALYZERS
int Cleric::getDamage()
{
	int damage = magic; // Cleric: This value is equal to the Cleric's magic.
	return damage;
}
