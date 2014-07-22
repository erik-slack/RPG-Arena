#pragma once
#include <sstream>
#include "ArenaInterface.h"
#include "Fighter.h"
#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"
using namespace std;

class Arena : public ArenaInterface
{
public:
//constructors
	Arena();
	~Arena();

//mutators
	virtual bool addFighter(string input_info);
	virtual bool removeFighter(string name);

//analyzers
	bool name_checker(string in_name);
	bool value_checker(int test_num1, int test_num2, int test_num3, int test_num4);

	virtual FighterInterface* getFighter(string in_name);
	virtual int getSize();

private:
//data
	vector<FighterInterface*> all_fighters; // 
};