#include "BattleArena.h"
using namespace std;


Arena::Arena(){}

Arena::~Arena(){}

bool Arena::name_checker(string in_name) // Used by add fighter
{
	bool is_copy = false;

	for (int i = 0; i < all_fighters.size() ; i++)
	{
		if (in_name == all_fighters[i]->getName()) 
		{ 
			is_copy = true; 
		}
	}

	return is_copy;
}

bool Arena::value_checker(int value1, int value2, int value3, int value4) // Used by add fighter
{
	bool is_valid = false;

	if (value1 > 0 && value2 > 0 && value3 > 0 && value4 > 0 )
	{
		is_valid = true;
	}
	else
	{
		is_valid = false;
	}

	return is_valid;
}

bool Arena::addFighter(string info)
{
	// Adds a new fighter to the collection of fighters in the arena.
	bool is_duplicate = false;
	bool has_failed = false;
	bool is_positive = false;
	stringstream input_ss;
	input_ss.str(info);
	
	string name, type, surplus_input;
	int hit_points, strength, speed, magic = 0;
	
	input_ss >> name >> type;
	
	//start of the value tests
	input_ss >> hit_points >> strength >> speed >> magic;
	
	if(input_ss.fail())
	{
		has_failed = true;
	}

	input_ss >> surplus_input;
	if(!input_ss.fail())
	{
		has_failed = true;
	}

	is_positive = value_checker(hit_points, strength, speed, magic); // Tests to see if values are positive

	is_duplicate = name_checker(name); //Do not allow duplicate names.

	// Return true if a new fighter was added; false otherwise.
	if (type == "A" && is_positive == true && has_failed == false && is_duplicate == false)
	{
		FighterInterface* f_name = new Archer(name, hit_points, strength, speed, magic);
		all_fighters.push_back(f_name);
		return true;
	}
	else if (type == "C" && is_positive == true && has_failed == false && is_duplicate == false)
	{
		FighterInterface* f_name = new Cleric(name, hit_points, strength, speed, magic);
		all_fighters.push_back(f_name);
		return true;
	}
	else if (type == "R" && is_positive == true && has_failed == false && is_duplicate == false)
	{
		FighterInterface* f_name = new Robot(name, hit_points, strength, speed, magic);
		all_fighters.push_back(f_name);
		return true;
	}
	else
	{
		return false; // Reject any string that does not adhere to the format outlined in the lab specs.
	}
}

bool Arena::removeFighter(string in_name)
{
	bool was_removed = false; // Does nothing if no fighter is found with the given name.

	for (int i = 0; i < all_fighters.size(); i++)
	{
		if (in_name == all_fighters[i]->getName() ) 
		{
			all_fighters.erase(all_fighters.begin() + i); // Removes the fighter whose name is equal to the given name.
			was_removed = true; // Return true if a fighter is removed; false otherwise.
		}
	}

	return was_removed;
}
		
FighterInterface* Arena::getFighter(string in_name)
{
	bool test = false;
	FighterInterface* memory_location = NULL; // Returns NULL if no fighter is found with the given name.

	for (int i = 0; i < all_fighters.size(); i++)
	{
		if (in_name == all_fighters[i]->getName() ) 
		{
			memory_location = all_fighters[i]; // Return a memory address if a fighter is found; NULL otherwise.
			test = true; 
		}
	}

	return memory_location;
}
		
int Arena::getSize()
{
	return all_fighters.size(); // Returns the number of fighters in the arena. Return a non-negative integer.
}