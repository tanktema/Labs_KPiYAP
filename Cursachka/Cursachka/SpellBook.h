#pragma once

using namespace std;

class SpellClass
{
	friend class Character;
	friend class CharacterInstance;

protected:
	string spell_school;
	int spell_level;
	string spell_name;
	string spell_definition;
	string spell_upper_levels_bonus;
public:
	SpellClass()
	{
		cout << "Введите название заклинания:" << endl;
		rewind(stdin);
		getline(cin, spell_name);
		cout << "Выберите школу заклинания: " << endl;
		for (int i = 0; i < 8; i++)
		{
			cout << i + 1 << ". " << spellschools[i] << endl;
		}
		int input_ptr;
		try
		{
			cin >> input_ptr;
			if (input_ptr < 1 || input_ptr > 8)
			{
				throw GeneratorException();
			}
		}
		catch (GeneratorException& inputgen)
		{
			input_ptr = inputgen.ReturnExceptionValue();
		}
		spell_school = spellschools[input_ptr - 1];
		cout << "Выберите круг заклинания: " << endl;
		try
		{
			cin >> spell_level;
			if (spell_level < 1 || spell_level > 8)
			{
				throw GeneratorException();
			}
		}
		catch (GeneratorException& inputgen)
		{
			spell_level = inputgen.ReturnExceptionValue();
		}
		rewind(stdin);
		cout << "Введите описание заклинания: " << endl;
		rewind(stdin);
		getline(cin, spell_definition);
		cout << "На заклинание оказывает эффект использование ячейки более высокого круга? y/n" << endl;
		char input_ptr_char;
		try
		{
			input_ptr_char = _getch();
			if (input_ptr_char != 'n' && input_ptr_char != 'y')
			{
				throw CharInputException(input_ptr_char);
			}
		}
		catch (CharInputException& input_exc)
		{
			input_ptr_char = input_exc.input_char;
		}
		if (input_ptr_char == 'y')
		{
			cout << "Введите эффекты спользования ячейки более высокого круга:" << endl;
			rewind(stdin);
			getline(cin, spell_upper_levels_bonus);
		}
	}
};