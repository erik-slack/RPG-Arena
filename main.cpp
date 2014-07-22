//#include <iostream>
//#include <vector>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//#include <cmath>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include "FighterInterface.h"
//#include "ArenaInterface.h"
//#include "BattleArena.h"
//#include "Fighter.h"
//
//
//void main_menu(Arena arena1)	
//{
//	//double* account_pointer = NULL; // Will set later;
//	bool repeat_checker = true;
//	while (repeat_checker == true)
//	{
//		cout << "My Frickin' Awesome RPG Application" << endl;
//		cout << "1 - Add New Fighter \n2 - Save Fighter List \n3 - Load Fighter List \n4 - Quit" << endl;
//		cout << "What would you like to do? \t";
//		int menu_choice = 1;
//		string name_choice = "";
//		string type_choice = "";
//		string strength_choice = "";
//		string speed_choice = "";
//		string magic_choice = "";
//		string info = "";
//		cin >> menu_choice;
//		if (menu_choice == 1)  // Add New Fighter
//		{
//			cout << "You chose menu choice " << menu_choice << endl;
//
//			cout << "Please input the name of your fighter." << endl;
//			cin >> name_choice;
//			cout << "Please choose the type of your fighter." << endl;
//			cin >> name_choice;
//			cout << "Please input the strength of your fighter." << endl;
//			cin >> name_choice;
//			cout << "Please input the speed of your fighter." << endl;
//			cin >> name_choice;
//			cout << "Please input the magic of your fighter." << endl;
//			cin >> name_choice;
//			info = setInfo(name_choice, type_choice, strength_choice, speed_choice, magic_choice);
//			arena1.addFighter(info);
//		}
//		else if (menu_choice == 2) // Save Fighter List
//		{
//			cout << "You chose menu choice " << menu_choice << endl;
//			//save_file(all_restaurants);
//		}
//		else if (menu_choice == 3) // Load Fighter List
//		{
//			string print_choice = "";
//			cout << "You chose menu choice " << menu_choice << endl;
//			//load_file(all_restaurants, restaurants_pointers);
//		}
//		else if (menu_choice == 4) // Quit
//		{
//			cout << endl;
//			cout << "The application has been terminated.  Goodbye." << endl;
//			repeat_checker = false;
//		}
//		else // input validator
//		{
//			cout << endl;
//			cout << "That is not a valid response to the question. \n" << endl;
//		}
//	}
//	cout << endl;
//}
//
//int main()
//{
//	Arena arena1;
//
//	main_menu(arena1);
//	
//	system ("pause");
//	return 0;
//}