#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>
#include <map>
#include <iomanip>
#include "Globaldata.h"
#include "Exceptions.h"
#include "CharClasses.h"
#include "Races.h"
#include "Weapons.h"
#include "SpellBook.h"
#include "CharacterDefinition.h"
using namespace std;

void main()
{
	system("chcp 1251");
	system("CLS");
	
	int class_in_num, race_in_num;
	bool truein = 0;
	vector <WeaponClass> weapon_list;
	cout << "Выберите класс: " << endl;
	for (int i = 0; i < 12; i++)
	{
		cout << i + 1 << " - " << classnames_global[i] << endl;
	}
	while (truein == 0)
	{
		
		try
		{
			cin >> class_in_num;
			if (class_in_num < 1 || class_in_num >= 13)
			{
				throw GeneratorException();
			}
			truein = 1;
		}
		catch (GeneratorException& genexcnumber_in)
		{
			class_in_num = genexcnumber_in.ReturnExceptionValue();
			truein = 1;
		}

	}
	cout << "Выберите расу: " << endl;
	truein = 0;
	for (int i = 0; i < 19; i++)
	{
		cout << i + 1 << " - " << baseraces[i] << endl;
	}
	while (truein == 0)
	{
		
		try
		{
			cin >> race_in_num;
			if (race_in_num < 1 || race_in_num >= 19)
			{
				throw GeneratorException();
			}
			truein = 1;
		}
		catch (GeneratorException& genexcnumber_in)
		{
			race_in_num = genexcnumber_in.ReturnExceptionValue();
			truein = 1;
		}
	}
	char inp_ptr = '0';
	while (inp_ptr != 'n')
	{
		cout << "Записать новое оружие для персонажа? (y/n)" << endl;
		try
		{
			inp_ptr = _getch();
			if (inp_ptr != 'n' && inp_ptr != 'y')
			{
				throw CharInputException(inp_ptr);
			}
			if (inp_ptr == 'y')
			{
				WeaponClass new_weapon;
				weapon_list.push_back(new_weapon);
			}

		}
		catch (CharInputException& input_exc)
		{
			inp_ptr = input_exc.input_char;
		}
		
		
	}
	CharacterInstance newcharacter(weapon_list, class_in_num, race_in_num);
}