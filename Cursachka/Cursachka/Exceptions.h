#pragma once
#include <iostream>



; using namespace std;

class GeneratorException
{
	
public:
	int exc_value;
	GeneratorException()
	{
		cout << "Некорректный ввод! Повторить ввод? y/n" << endl;
		try
		{
			char input_info = _getch();
			if (input_info != 'y')
			{
				throw(input_info);
			}
			cout << "Введите новое значение: " << endl;
			cin >> exc_value;
		}
		catch (char input_char)
		{
			cout << "Установлено значение по умолчанию!" << endl;
			exc_value = 1;
		}
	}

	int ReturnExceptionValue()
	{
		return exc_value;
	}
};

class FileException
{
	
public:
	string ofstream_filename;
	char overwrite_confirm;
	FileException(string file_name_before)
	{
		ofstream_filename = file_name_before;
		cout << "Персонаж с таким именем уже существует! Перезаписать его? y/n" << endl;
		overwrite_confirm = _getch();
		FilenameReturn();
	}

	string FilenameReturn()
	{
		string name_to_ret;
		switch (overwrite_confirm)
		{
		case 'y':
			name_to_ret = ofstream_filename;
			break;
		case 'n':
			name_to_ret = ofstream_filename+  "_new";
			break;
		}
		return name_to_ret;
	}
};

class CharInputException
{

public:
	char input_char;
	CharInputException(char input_char_send)
	{
		cout << "Некорректный ввод, повторите!" << endl;
		rewind(stdin);
		try
		{
			input_char = _getch();
			if (input_char != 'y')
			{
				throw input_char;
			}
		}
		catch (char inp_char)
		{
			input_char = 'n';
		}
	}
};

class FileOpenException
{
public:
	int filenumber;
	char input_char;
	FileOpenException()
	{
		cout << "Не удалось открыть файл! Повторить ввод? y/n" << endl;
		try
		{
			input_char = _getch();
			if (input_char != 'y')
			{
				throw input_char;
			}

		}
		catch (char inp_char)
		{
			cout << "Выполнение программы прекращено: не удалось открыть файл класса/расы!" << endl;
			exit(0);
		}
	}

	int RetryFileEnter()
	{
		cout << "Введите новое значение " << endl;
		cin >> filenumber;
		return filenumber;
	}
};