#pragma once

#define MAX_STATS 6
#define MAX_SKILLS 18
#define MAX_CLASSES 12
#define MAX_WEAPON_TYPES 3
#define MAX_ARMOR_TYPES 5
#define MAX_ALIGNMENTS 9
#define MAX_SPELLSCHOOLS 8
#define RACE_FOLDER "Races/"
#define CLASS_FOLDER "Classes/"
#define CHARACTER_FOLDER "Characters/"
#define MAX_CLASSES 12
#define MAX_RACES 19

using namespace std;

const string skills[MAX_SKILLS] = { "����������", "������", "��������", "����������", "���������", "�����������", "�����������", "�������", "�������� ���", "�����", "��������", "�����", "�������", "����������������", "�������", "����������", "���������", "���� �� ���������" };
const string armor_types[MAX_WEAPON_TYPES] = { "������", "�������", "�������" };
const string weapon_types[MAX_ARMOR_TYPES] = { "�������", "��������", "������������", "���������", "����������" };
const string statnames[MAX_STATS] = { "����", "��������", "������������", "���������", "��������", "�������" };
const string alignments[MAX_ALIGNMENTS] = { "�������-������", "����������-������", "��������-������", "����������-������", "�������-�����������", "��������-�����������", "�������-����", "����������-����", "��������-����" };
const string spellschools[MAX_SPELLSCHOOLS] = { "����� ����������", "����� ������", "����� �������", "����� �����������", "����� ����������", "����� ����������", "����� ��������������", "����� ����������" };
const string classnames_global[MAX_CLASSES] = { "����", "�������", "������", "��������", "����", "�����", "����", "����", "�����", "���������", "�������", "������" };
const string classfiles_global[MAX_CLASSES] = { "warrior_class.txt", "paladin_class.txt", "barbarian_class.txt", "ranger_class.txt", "rogue_class.txt", "monk_class.txt", "bard_class.txt", "cleric_class.txt", "druid_class.txt", "wizard_class.txt", "sorcerer_class.txt", "warlock_class.txt" };
const string baseraces[MAX_RACES] = { "�������", "������ ����", "������ ����", "������ ����", "��������� ����", "������ ����", "��������", "�����", "��������� �������", "��������� �������", "���", "�������", "������", "������ �����", "�������� �����", "��������� �����", "����", "����������������", "�������" };
const string baseracefiles[MAX_RACES] = { "human_race.txt", "wooden_elf.txt", "high_elf.txt", "dark_elf.txt", "solar_elf.txt", "lunar_elf.txt", "half_elf.txt", "azradian_human.txt", "remess_human.txt", "mekass_human.txt", "ork_race.txt", "half_ork.txt", "goblin_race.txt", "mountain_dwarf.txt", "hill_dwarf.txt", "remess_dwarf.txt", "gmome_race.txt", "dragonborn.txt", "tiefling.txt" };

template <class T>
void PrintVector(vector <T>& vectorname)
{
	for (int i = 0; i < (int)vectorname.size(); i++)
	{
		cout << vectorname[i] << endl;
	}
	cout << endl;
}

template <class T>
void PrintVectorFile(vector <T>& vectorname, ofstream& offile)
{
	for (int i = 0; i < (int)vectorname.size(); i++)
	{
		offile << vectorname[i] << endl;
	}
	offile << endl;
}

template <class T3>
bool IsInVector(T3 compare, vector <T3>& vectorname)
{
	bool is_vector = 0;
	for (int i = 0; i < (int)vectorname.size(); i++)
	{
		if (compare == vectorname[i])
			is_vector = 1;
	}
	return is_vector;
}

template <class T>
int FindVectorIndex(T search_value, vector <T> vector_to_search)
{
	int return_value;
	for (int i = 0; i < (int)vector_to_search.size(); i++)
	{
		if (search_value == vector_to_search[i])
			return_value = i;
	}
	return return_value;
}

template <class T2>
vector <T2> ArrayToVector(T2* arr, int arraysize)
{
	vector <T2> return_array;
	for (int i = 0; i < arraysize; i++)
		return_array.push_back(arr[i]);
	return return_array;

}

int tctoi(char x, char y)
{
	return ((int)x - 48) * 10 + ((int)y - 48);
}
//
//pair <string, string> translit_list[66] = {
//	{"�", "A"},
//	{"�", "B"},
//	{"�", "V"},
//	{"�", "G"},
//	{"�", "D"},
//	{"�", "E"},
//	{"�", "Io"},
//	{"�", "Zh"},
//	{"�", "Z"},
//	{"�", "I"},
//	{"�", "J"},
//	{"�", "K"},
//	{"�", "L"},
//	{"�", "M"},
//	{"�", "N"},
//	{"�", "O"},
//	{"�", "P"},
//	{"�", "R"},
//	{"�", "S"},
//	{"�", "T"},
//	{"�", "U"},
//	{"�", "F"},
//	{"�", "Kh"},
//	{"�", "Ts"},
//	{"�", "Ch"},
//	{"�", "Sh"},
//	{"�", "Sch"},
//	{"�", "'"},
//	{"�", "U"},
//	{"�", "Y"},
//	{"�", "E"},
//	{"�", "Yu"},
//	{"�", "Ya"},
//	{"�", "a"},
//	{"�", "b"},
//	{"�", "v"},
//	{"�", "g"},
//	{"�", "d"},
//	{"�", "e"},
//	{"�", "io"},
//	{"�", "zh"},
//	{"�", "z"},
//	{"�", "i"},
//	{"�", "j"},
//	{"�", "k"},
//	{"�", "l"},
//	{"�", "m"},
//	{"�", "n"},
//	{"�", "o"},
//	{"�", "p"},
//	{"�", "r"},
//	{"�", "s"},
//	{"�", "t"},
//	{"�", "u"},
//	{"�", "f"},
//	{"�", "kh"},
//	{"�", "ts"},
//	{"�", "ch"},
//	{"�", "sh"},
//	{"�", "sch"},
//	{"�", "'"},
//	{"�", "u"},
//	{"�", "y"},
//	{"�", "e"},
//	{"�", "yu"},
//	{"�", "ya"}
//};