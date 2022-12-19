#pragma once
using namespace std;

class CharacterClass
{
	friend int tctoi(char x, char y);
	friend class Character;
	friend class WeaponClass;
	friend class CharacterInstance;
	friend class ElementalWeapon;
	friend void main();
private:

	
	bool* armor_use;
	bool* weapon_use;
	int hitdice;
	char base_char;
	int skillamount;
	bool* savethrows;
	int* skilluse;
	int numsktotal;
	int num_lvl1_spell_slots[9];
	ifstream classfile;
	bool has_magic;
	vector <string> class_traits;
public:
	string classname;
	CharacterClass(int classnumber = 1)
	{
		string filename = classfiles_global[classnumber - 1], stringtmp;
		char stringptr = '0';
		try
		{
			classfile.open(CLASS_FOLDER + filename);
			if (!classfile.is_open())
			{
				throw FileOpenException();
			}
		}
		catch (FileOpenException& filexc)
		{
			filename = classfiles_global[filexc.filenumber - 1];
		}
		getline(classfile, classname);
		getline(classfile, stringtmp);
		int i = 0, j = 0;
		armor_use = new bool[3];
		while (stringptr != '\0')
		{
			stringptr = stringtmp[i];
			if (stringptr != ' ' && stringptr != '\0')
			{
				armor_use[j] = (bool)stringptr - 48;
				j++;
			}
			i++;
		}
		getline(classfile, stringtmp);
		weapon_use = new bool[5];
		i = 0; 
		j = 0;
		stringptr = '0';
		while (stringptr != '\0')
		{
			stringptr = stringtmp[i];
			if (stringptr != ' ' && stringptr != '\0')
			{
				weapon_use[j] = (bool)stringptr - 48;
				j++;
			}
			i++;
		}	
		getline(classfile, stringtmp);
		hitdice = stoi(stringtmp);
		getline(classfile, stringtmp);
		base_char = stringtmp[0];
		getline(classfile, stringtmp);
		skillamount = stoi(stringtmp);
		i = 0;
		j = 0;
		stringptr = '0';
		getline(classfile, stringtmp);
		savethrows = new bool[6];
		while (stringptr != '\0')
		{
			stringptr = stringtmp[i];
			if (stringptr != ' ' && stringptr != '\n')
			{
				savethrows[j] = (int)stringptr - 48;
				j++;
			}
			i++;
		}
		i = 0;
		j = 0;
		stringptr = '0';
		getline(classfile, stringtmp);
		GetTraitLine(stringtmp);
		getline(classfile, stringtmp);
		has_magic = stoi(stringtmp);
		if(has_magic)
		{
			getline(classfile, stringtmp);
			stringptr = '0';
			j = 0;
			for (i = 0; i < stringtmp.size(); i++)
			{
				stringptr = stringtmp[i];
				if (stringptr != ' ')
				{
					num_lvl1_spell_slots[j] = (int)stringptr - 48;
					j++;
				}
			}
		}
		else
			getline(classfile, stringtmp);
		while (!classfile.eof())
		{
			getline(classfile, stringtmp);
			class_traits.push_back(stringtmp);
			
		}
	}

	void GetTraitLine(string traitstr)
	{
		
		char sym1, sym2, check = 48;
		int ctr = 0, i = 0;
		while (check != '\0')
		{
			check = traitstr[++i];
			if (check == ' ')
				ctr++;
			//i++;
		}
		ctr++; // –азмерность массива - число пробелов +1
		numsktotal = ctr;
		int j = 0;
		skilluse = new int[ctr];
		for (i = 0; i <= (int)traitstr.size(); i++)
		{
			check = traitstr[i];
			if (check != ' ')
			{
				if (traitstr[i + 1] == ' ')
				{
					sym1 = traitstr[i];
					skilluse[j] = (int)sym1 - 48;
					j++;
				}
				else
				{
					if (traitstr[i + 1] != ' ')
					{
						sym1 = traitstr[i];
						sym2 = traitstr[i + 1];
						skilluse[j] = tctoi(sym1, sym2);
						j++;
						i++;
					}
				}
			}

			i++;
		}
	}

	~CharacterClass()
	{
		classfile.close();
	}

};