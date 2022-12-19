#pragma once

using namespace std;

class CharacterRace
{
	friend class Character;
	friend class CharacterInstance;
	
public:
	string racename;
	int* racemods;
	int speed;
	bool has_darkvision;
	string* traits;
	int num_traits;
	ifstream racefile;
	CharacterRace(int racenum = 1)
	{
		string filename = baseracefiles[racenum - 1], stringtmp;
		char stringptr = 48;
		try
		{
			racefile.open(RACE_FOLDER + filename);
			if (!racefile.is_open())
			{
				throw FileOpenException();
			}
		}
		catch (FileOpenException& filexc)
		{
			filename = baseracefiles[filexc.filenumber - 1];
		}
		rewind(stdin);
		getline(racefile, racename);
		racemods = new int[6];
		int i = 0, j = 0;
		getline(racefile, stringtmp);
		while (stringptr != '\0')
		{
			stringptr = stringtmp[i];
			if (stringptr != ' ' && stringptr != '\n')
			{
				racemods[j] = (int)stringptr - 48;
				j++;
			}
			i++;

		}
		getline(racefile, stringtmp);
		speed = stoi(stringtmp);
		getline(racefile, stringtmp);
		has_darkvision = stoi(stringtmp);
		string traitstring[99];
		num_traits = 0;
		i = 0;
		while (!racefile.eof())
		{
			getline(racefile, stringtmp);
			traitstring[i] = stringtmp;
			i++;
			num_traits++;
		}
		traits = new string[num_traits];
		for (int k = 0; k < num_traits; k++)
		{
			traits[k] = traitstring[k];
		}
		
	}

	~CharacterRace()
	{
		racefile.close();
	}
};