#pragma once
using namespace std;

class Character : private CharacterClass, private CharacterRace
{
	friend void main();
	friend vector <int> GetCharacterStats(int rolltype, vector <int> racebonuses);
	friend class WeaponClass;
	friend class ElementalWeapon;
	friend class CharacterInstance;
public:
	string character_name;
	string character_alignment;
	int character_level;
	int character_skillbonus;
	vector <int> character_stats;
	vector <int> character_statmods;
	vector <int> character_savemods;
	vector <bool> character_has_skill;
	vector <int> character_skill_value;
	int character_perception;
	int character_maxhp;
	int character_armorclass;
	vector <string> character_traits;
	vector <int> dex_skills_array;
	vector <int> str_skills_array;
	vector <int> int_skills_array;
	vector <int> wis_skills_array;
	vector <int> char_skills_array;

	Character(int classnumber, int racenumber) : CharacterClass(classnumber), CharacterRace(racenumber)
	{
		int input_value;
		dex_skills_array = { 0, 8, 15 };
		str_skills_array = { 2 };
		int_skills_array = { 1, 7, 9, 12, 14 };
		wis_skills_array = { 3, 4, 10, 13, 17 };
		char_skills_array = { 5, 6, 11, 16 };
		character_level = 1;
		character_skillbonus = 2;
		cout << "Вы - " << racename << " " << classname << " " << endl;
		cout << "Введите имя персонажа " << endl;
		rewind(stdin);
		getline(cin, character_name);
		cout << "Выберите мировоззрение: " << endl;
		for (int i = 0; i < 9; i++)
		{
			cout << i << " - " << alignments[i] << endl;
		}
		try
		{
			cin >> input_value;
			if (input_value < 1 && input_value >= 10)
			{
				throw GeneratorException();
			}
		}
		catch (GeneratorException& genexcnumber_in)
		{
			input_value = genexcnumber_in.ReturnExceptionValue();
		}
		character_alignment = alignments[input_value];
		cout << "Выберите метод распределения характеристик: 1 - Распределение очков, 2 - Случайная генерация, 3 - Выбор стандартных" << endl;
		try
		{
			cin >> input_value;
			if (input_value < 1 || input_value > 3)
			{
				throw GeneratorException();
			}
		}
		catch (GeneratorException& genexcnumber_in)
		{
			input_value = genexcnumber_in.ReturnExceptionValue();
		}
		vector <int> race_stat_bonus = ArrayToVector(racemods, 6);
		character_stats = GetCharacterStats(input_value, race_stat_bonus);
		character_statmods = GetStatModifiers(character_stats);
		character_savemods = character_statmods;
		for (int i = 0; i < (int)character_statmods.size(); )
		{
			if (savethrows[i] == 1)
			{
				character_savemods[i] = character_statmods[i] + character_skillbonus;
			}
			i++;
		}
		character_maxhp = hitdice + character_statmods[2];
		cout << sizeof(skilluse) << endl;
		vector <int> skills_vector = ArrayToVector(skilluse, numsktotal);

		character_has_skill = GetSkillUse(skills_vector, skillamount);
		character_skill_value = GetSkills(character_statmods, character_has_skill, character_skillbonus);
		character_traits = ArrayToVector(traits, num_traits);
	}


	vector <int> RandomizeStats()
	{
		int* random_dice;
		int currentval, sortptr, sum;
		vector <int> fill_array;
		srand(time(NULL));
		random_dice = new int[4];
		while ((int)fill_array.size() != 6)
		{
			sum = 0;
			for (int i = 0; i < 4; i++)
			{
				random_dice[i] = rand() % 6 + 1;
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (random_dice[i] > random_dice[j])
					{
						sortptr = random_dice[i];
						random_dice[i] = random_dice[j];
						random_dice[j] = sortptr;
					}
				}
			}
			for (int i = 0; i < 3; i++)
			{
				sum += random_dice[i];
			}
			fill_array.push_back(sum);
		}
		return fill_array;

	}

	vector <int> StandartStats()
	{
		vector <int> fill_array;
		vector <int> base_array = { 15, 14, 13, 12, 10, 8 };
		int insertvalue;
		for (int i = 0; i < 6; i++)
		{
			cout << "Вам доступны следующие значения: " << endl;
			PrintVector(base_array);
			cout << "Выберите значение характеристики " << statnames[i] << endl;
			cin >> insertvalue;
			while (IsInVector(insertvalue, base_array) == false)
			{
				cout << "Это значение недоступно для выбора, выберите другое!" << endl;
				cin >> insertvalue;
			}
			fill_array.push_back(insertvalue);
			base_array.erase(std::remove(base_array.begin(), base_array.end(), insertvalue), base_array.end());
		}

		return fill_array;
	}

	vector <int> GetCharacterStats(int rolltype, vector <int> racebonuses)
	{
		vector <int> statarr;
		switch (rolltype)
		{
		case 1:
			statarr = DistributeStats();
			break;
		case 2:
			statarr = RandomizeStats();
			break;
		case 3:
			statarr = StandartStats();
			break;
		}
		for (int i = 0; i < statarr.size(); i++)
		{
			statarr[i] += racebonuses[i];
		}
		return statarr;
	}

	vector <int> DistributeStats()
	{
		int amount_pts = 27, statvalue, tempstat, tempval, diffptr;
		vector <int> fill_array;
		bool trueval = 1;
		for (int i = 0; i < 6; i++)
		{
			trueval = 1;
			cout << "Очков для расходования: " << amount_pts << endl;
			while (trueval == 1)
			{
				cout << "Введите значение характеристики " << statnames[i] << ":" << endl;
				cin >> statvalue;
				if (statvalue < 8 || statvalue > 15)
				{
					cout << "Неверное значение! Введите значение между 8 и 15" << endl;
				}
				else
				{
					tempstat = statvalue;
					tempval = statvalue;
					diffptr = tempstat - 13;
					if (diffptr < 0)
						diffptr = 0;
					tempval = statvalue - 8;
					tempval += diffptr;
					fill_array.push_back(statvalue);
					amount_pts -= tempval;
					trueval = 0;
					if (amount_pts < 0)
					{
						cout << "Недостаточно очков! " << endl;
						fill_array.pop_back();
						amount_pts += tempval;
						trueval = 1;
					}
				}
			}
		}
		return fill_array;
	}

	vector <int> GetStatModifiers(vector <int>& statsarr)
	{
		int currmod;
		vector <int> fill_array;
		for (int i = 0; i < (int)statsarr.size(); i++)
		{
			currmod = statsarr[i];
			currmod -= 10;
			if (currmod >= 0)
				currmod = currmod / 2;
			else
				currmod = (currmod - 1) / 2;
			fill_array.push_back(currmod);
		}

		return fill_array;
	}


	vector <bool> GetSkillUse(vector <int>& skillarray, int numskills)
	{
		vector <bool> fill_array;
		vector <int> skilluse_array;
		int i = 0, input_value;
		cout << "Вам доступно " << numskills << " навыков из следующих:" << endl;
		for (i = 0; i < skillarray.size(); i++)
		{
			cout << skills[skillarray[i]] << "(" << skillarray[i] << ")" << endl;
		}
		cout << "Выберите навыки: " << endl;
		i = 0;
		while (i < numskills)
		{
			cin >> input_value;
			if (!IsInVector(input_value, skillarray))
			{
				cout << "Вы не можете выбрать этот навык!" << endl;
			}
			else
			{
				skilluse_array.push_back(input_value);
				i++;

			}

		}
		for (int i = 0; i < MAX_SKILLS; i++)
		{
			if (IsInVector(i, skilluse_array))
			{
				fill_array.push_back(1);
			}
			else
			{
				fill_array.push_back(0);
			}
		}
		return fill_array;
	}

	vector <int> GetSkills(vector <int>& statmodarr, vector <bool>& skillusearr, int skillbonus)
	{
		vector <int> fill_array;
		for (int i = 0; i < (int)skillusearr.size(); i++)
		{
			if (IsInVector(i, dex_skills_array))
			{
				if (skillusearr[i])
				{
					fill_array.push_back(statmodarr[1] + skillbonus);
				}
				else
				{
					fill_array.push_back(statmodarr[1]);
				}
			}
			if (IsInVector(i, str_skills_array))
			{
				if (skillusearr[i])
				{
					fill_array.push_back(statmodarr[0] + skillbonus);
				}
				else
				{
					fill_array.push_back(statmodarr[0]);
				}
			}
			if (IsInVector(i, int_skills_array))
			{
				if (skillusearr[i])
				{
					fill_array.push_back(statmodarr[3] + skillbonus);
				}
				else
				{
					fill_array.push_back(statmodarr[3]);
				}
			}
			if (IsInVector(i, wis_skills_array))
			{
				if (skillusearr[i])
				{
					fill_array.push_back(statmodarr[4] + skillbonus);
				}
				else
				{
					fill_array.push_back(statmodarr[4]);
				}
			}
			if (IsInVector(i, char_skills_array))
			{
				if (skillusearr[i])
				{
					fill_array.push_back(statmodarr[5] + skillbonus);
				}
				else
				{
					fill_array.push_back(statmodarr[5]);
				}
			}
		}

		return fill_array;
	}


	~Character()
	{


	}
};

class CharacterInstance : private Character
{
protected:
	vector <WeaponClass> weapon_list;
	vector <string> character_inventory;
	vector <SpellClass> character_spellbook;
	bool can_use_armor;
	ofstream character_file;
public:
	CharacterInstance(vector <WeaponClass> weapons, int classnum, int racenum) : Character(classnum, racenum)
	{
		weapon_list = weapons;
		for (int i = 0; i < (int)weapon_list.size(); i++)
		{
			weapon_list[i].damage_modifier = character_statmods[weapon_list[i].attack_char - 1];
			weapon_list[i].attack_modifier = weapon_list[i].damage_modifier;
			if (weapon_use[weapon_list[i].attack_char])
			{
				weapon_list[i].attack_modifier += 2;
			}
		}
		char inp_ptr;
		cout << "Персонаж носит броню? (y/n)" << endl;
		try
		{
			inp_ptr = _getch();
			if (inp_ptr != 'n' && inp_ptr != 'y')
			{
				throw CharInputException(inp_ptr);
			}
		}
		catch (CharInputException& input_exc)
		{
			inp_ptr = input_exc.input_char;
		}
		
		if (inp_ptr == 'y')
		{
			ArmorClass character_armor(character_statmods[1], ArrayToVector(armor_use, 3));
			character_armorclass = character_armor.armor_value;
			can_use_armor = character_armor.can_use;
			character_inventory.push_back(character_armor.armor_name);
		}
		if (inp_ptr == 'n')
		{
			inp_ptr == '0';
			cout << "Персонаж обладает умением Защита без Доспехов? y/n" << endl;
			try
			{
				inp_ptr = _getch();
				if (inp_ptr != 'n' && inp_ptr != 'y')
				{
					throw CharInputException(inp_ptr);
				}
			}
			catch (CharInputException& input_exc)
			{
				inp_ptr = input_exc.input_char;
			}
			if (inp_ptr == 'n')
				character_armorclass = 10 + character_statmods[1];
			else
			{
				int char1, char2;
				cout << "Выберите две характеристики, которые учитываются при расчете класса доспехов:" << endl;
				for (int i = 0; i < 6; i++)
				{
					cout << i + 1 << ". " << statnames[i] << endl;
				}
				cin >> char1;
				bool is_in = 0;
				while (!is_in)
				{
					try
					{
						cin >> char1;
						if (char1 < 1 || char1 > 6)
						{
							throw GeneratorException();
						}
						is_in = 1;
					}
					catch (GeneratorException& inputgen)
					{
						char1 = inputgen.ReturnExceptionValue();
						is_in = 1;
					}
				}
				char1 -= 1;
				is_in = 0;
				cin >> char2;
				while (!is_in)
				{
					try
					{
						cin >> char2;
						if (char2 < 1 || char2 > 6)
						{
							throw GeneratorException();
						}
						is_in = 1;
					}
					catch (GeneratorException& inputgen)
					{
						char2 = inputgen.ReturnExceptionValue();
						is_in = 1;
					}
				}
				char2 -= 1;
				character_armorclass = 10 + character_statmods[char1] + character_statmods[char2];
			}
		}
		character_perception = 10 + character_savemods[4];
		if (has_magic)
		{
			cout << "Владение персонажа магией:" << endl;
			for (int i = 0; i < 9; i++)
			{
				cout << "Ячейки " << i + 1 << " круга: " << num_lvl1_spell_slots[i] << endl;
			}
			char inp_ptr = '0';
			while (inp_ptr != 'n')
			{
				cout << "Добавить новое заклинание? (y/n)" << endl;
				inp_ptr = _getch();
				if (inp_ptr != 'n' && inp_ptr != 'y')
					cout << "Неверный ввод!";
				if (inp_ptr == 'y')
				{
					SpellClass new_spell;
					character_spellbook.push_back(new_spell);
				}

			}
		}


		cout << "Вы хотите заполнить инвентарь персонажа? (y - да)" << endl;
		cin >> inp_ptr;
		if (inp_ptr == 'y')
		{
			cout << "Введите количество предметов в инвентаре: " << endl;
			int inv_size;
			try
			{
				cin >> inv_size;
				if (inv_size < 1)
				{
					throw GeneratorException();
				}
			}
			catch (GeneratorException& genexcnumber_in)
			{
				inv_size = genexcnumber_in.ReturnExceptionValue();
			}
			for (int i = 0; i < weapon_list.size(); i++)
			{
				character_inventory.push_back(weapon_list[i].weapon_name);
			}
			if (inv_size < character_inventory.size())
			{
				cout << "Инвентарь заполнен!" << endl;
			}
			else
			{
				string tmp_str;
				inv_size -= character_inventory.size();
				if (inv_size > 0)
				{
					cout << "Введите еще " << inv_size << " предметов:" << endl;
					while (inv_size > 0)
					{
						rewind(stdin);
						getline(cin, tmp_str);
						character_inventory.push_back(tmp_str);
						inv_size--;
					}
				}
			}
		}
	}

	string CharToString(char char_to_str)
	{
		string ctos;
		ctos[0] = char_to_str;
		return ctos;
	}

	~CharacterInstance()
	{
		system("CLS");
		//cout.setf(ios::showpos);
		cout << "Персонаж: " << character_name << endl;
		cout << character_alignment << " " << classname << " " << character_level << " Ур." << endl;
		cout << "Максимум хитов: " << character_maxhp << " Класс доспехов: " << character_armorclass;
		if (!can_use_armor) cout << "(-)";
		cout << " Инициатива: " << character_savemods[2] << " Скорость: " << speed << endl;
		cout << "Значения характеристик и навыков:" << endl;
		for (int i = 0; i < 6; i++)
		{
			cout << statnames[i] << ": " << character_stats[i] << "(" << character_statmods[i] << ")" << " Спасбросок: " << character_savemods[i] << endl;
		}
		for (int i = 0; i < character_skill_value.size(); i++)
		{
			cout << skills[i] << ": " << character_skill_value[i];
			if (character_has_skill[i]) cout << "(+)";
			cout << endl;
		}
		cout << "Оружие: " << endl;
		for (int i = 0; i < weapon_list.size(); i++)
		{
			cout << weapon_list[i].weapon_name << " " << weapon_list[i].attack_modifier << " " << weapon_list[i].num_dmgd << "d" << weapon_list[i].damage_dice << " + " << weapon_list[i].damage_modifier << " " << weapon_list[i].damage_type;
			if (weapon_list[i].is_magical) cout << " Маг." << endl;
			else cout << endl;
			cout << "Особенности оружия: " << endl;
			PrintVector(weapon_list[i].weapon_traits);
		}
		if (has_magic)
		{
			cout << "Магия:" << endl;
			for (int i = 0; i < 9; i++)
			{
				if (i == 0)
					cout << "Заговоры:" << endl;
				else
					cout << "Заклинания " << i << " круга: " << endl;
				for (int j = 0; j < character_spellbook.size(); j++)
				{
					if (character_spellbook[j].spell_level == i)
					{
						cout << character_spellbook[j].spell_name << endl;
						cout << character_spellbook[j].spell_school << endl;
						cout << character_spellbook[j].spell_definition << endl;
						cout << character_spellbook[j].spell_upper_levels_bonus << endl;
					}
				}
			}
		}
		cout << "Записать в файл? y/n" << endl;
		char infile;
		rewind(stdin);
		infile = _getch();
		string strtmp;
		string filename;
		if (infile == 'y')
		{
			filename = CHARACTER_FOLDER + character_name;
			try
			{
				ifstream filecheck;
				filecheck.open(filename + ".txt");
				if (filecheck.is_open())
				{
					throw FileException(filename);
				}
			}
			catch (FileException &errorfile)
			{
				filename = errorfile.FilenameReturn();
			}
			character_file.open(filename + ".txt");
			character_file 
				<< character_name << "\t" << classname << "  Уровень: " << character_level << "\n" << "Мировоззрение: " << character_alignment
				<< "\nМаксимум хитов: " << character_maxhp << "\nСкорость перемещения: " << speed << "\nКласс доспеха: " << character_armorclass
				<< "\nБонус инициативы: " << character_savemods[2] << "\nБонус мастерства: " << character_skillbonus << "\nЗначения характеристик и спасбросков: "
				<< "\n";
				for (int i = 0; i < 6; i++)
				{
					character_file << statnames[i] << ": " << character_stats[i] << "(" << character_statmods[i] << ")" << " Спасбросок: " << character_savemods[i] << endl;
				}
				for (int i = 0; i < character_skill_value.size(); i++)
				{
					character_file << skills[i] << ": " << character_skill_value[i];
					if (character_has_skill[i]) character_file << "(+)";
					character_file << endl;
				}
				character_file << "Оружие: " << endl;
				for (int i = 0; i < weapon_list.size(); i++)
				{
					character_file << weapon_list[i].weapon_name << " " << weapon_list[i].attack_modifier << " " << weapon_list[i].num_dmgd << "d" << weapon_list[i].damage_dice << " + " << weapon_list[i].damage_modifier << " " << weapon_list[i].damage_type;
					if (weapon_list[i].is_magical) character_file << " Маг." << endl;
					else character_file << endl;
					character_file << "Особенности оружия: " << endl;
					PrintVectorFile(weapon_list[i].weapon_traits, character_file);
				}
				if (has_magic)
				{
					character_file << "Магия:" << endl;
					for (int i = 0; i < 9; i++)
					{
						if (i == 0)
							character_file << "Заговоры:" << endl;
						else
							character_file << "Заклинания " << i << " круга: " << endl;
						for (int j = 0; j < character_spellbook.size(); j++)
						{
							if (character_spellbook[j].spell_level == i)
							{
								character_file << character_spellbook[j].spell_name << endl;
								character_file << character_spellbook[j].spell_school << endl;
								character_file << character_spellbook[j].spell_definition << endl;
								character_file << character_spellbook[j].spell_upper_levels_bonus << endl;
							}
						}
					}
				}
				PrintVectorFile(class_traits, character_file);
				vector <string> classtraitlist = ArrayToVector(traits, num_traits);
				if (has_darkvision)
				{
					classtraitlist.push_back("Тёмное зрение");
				}
				PrintVectorFile(classtraitlist, character_file);
				PrintVectorFile(character_inventory, character_file);
		}
	} 
};

