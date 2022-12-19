#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <vector>
#include <conio.h>
using namespace std;

class WeaponClass
{
	friend void main();
	friend class Character;
	friend class CharacterInstance;

private:
	int damage_dice;
	int num_dmgd;
	string damage_type;
	int attack_char;
	int weapon_type;
	int damage_modifier;
	int attack_modifier;
	bool is_magical;
	vector <string> weapon_traits;
	string weapon_name;

public:

	WeaponClass()
	{
		cout << "������� �������� ������: " << endl;
		rewind(stdin);
		getline(cin, weapon_name);
		cout << "������� ����� ����� ������ � ����� ������ �����: " << endl;
		cin >> damage_dice;
		cin >> num_dmgd;
		cout << "������� ��� �����: " << endl;
		rewind(stdin);
		getline(cin, damage_type);
		cout << "������� �������������� ����� ������:" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << i + 1 << ": " << statnames[i] << endl;
		}
		
		bool is_in = 0;
		while (!is_in)
		{
			try
			{
				cin >> attack_char;
				if (attack_char < 1 || attack_char > 6)
				{
					throw GeneratorException();
				}
				is_in = 1;
			}
			catch (GeneratorException & inputgen)
			{
				attack_char = inputgen.ReturnExceptionValue();
				is_in = 1;
			}
		}
		is_in = 0;
		cout << "������� ��� ������:" << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << i + 1 << ": " << weapon_types[i] << endl;
		}
		while (!is_in)
		{
			try
			{
				cin >> weapon_type;
				if (weapon_type < 1 || weapon_type > 6)
				{
					throw GeneratorException();
				}
				is_in = 1;
			}
			catch (GeneratorException& inputgen)
			{
				weapon_type = inputgen.ReturnExceptionValue();
				is_in = 1;
			}
		}
		cout << "������� ����������� ������: " << endl;
		char input_ptr = '0';

		while (input_ptr != 'n')
		{
			cout << "������ ����� �����������?(y/n)" << endl;
			input_ptr = _getch();
			if (input_ptr != 'n')
			{
				rewind(stdin);
				string stringtmp;
				cout << "������� �����������: " << endl;
				getline(cin, stringtmp);
				weapon_traits.push_back(stringtmp);
			}
		}
		cout << "���� ������ ��������� ����������?(1/0)" << endl;
		cin >> is_magical;
		cout << weapon_name << endl;
		cout << "���� ������:" << num_dmgd << "d" << damage_dice << " " << damage_type;
		if (is_magical) cout << " ���." << endl;
		cout << "����������� ������: " << endl;
	}

	~WeaponClass()
	{

	}
};

class ArmorClass
{
	friend class CharacterInstance;
protected:
	int armor_value;
	int armor_type;
	string armor_name;
	bool can_use;
public:
	ArmorClass(int dex_char_bonus = 0, vector <bool> can_use_ac = { 0,0,0 })
	{
		cout << "������� �������� �����: " << endl;
		rewind(stdin);
		getline(cin, armor_name);
		cout << "�������� ��� �����: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << i + 1 << ". " << armor_types[i] << endl;
		}
		try
		{
			cin >> armor_type;
			if (armor_type < 1 || armor_type > 3)
			{
				throw GeneratorException();
			}
		}
		catch (GeneratorException& armor_exception)
		{
			armor_type = armor_exception.ReturnExceptionValue();
		}
		cout << "������� �������� ������ ������� �����: " << endl;
		cin >> armor_value;
		if (armor_type != 3)
		{
			if (armor_type == 1)
			{
				armor_value += dex_char_bonus;
			}
			if (armor_type == 2)
			{
				if (dex_char_bonus >= 2)
					armor_value += 2;
				else
					armor_value += dex_char_bonus;
			}
		}
		can_use = can_use_ac[armor_type - 1];
	}
};
