#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class student;
class decanus;




class student
{
	friend void main();
	friend class decanus;
	
private:
	int id;
	string name;
	float rate;
	int oapmark, ailomark, mathmark;
public:
	void FillStudent() {
		setlocale(LC_ALL, "ru");
		
		cout << "Введите оценки по предметам: ОАиП, АиЛОЦУ, Высшая математика студента " << name << endl;
		cin >> oapmark >> ailomark >> mathmark;
	}
};

class decanus
{
public:

	static float GetStudentRate(student& stud)
	{
		float rating;
		rating = (float)stud.oapmark;
		rating += (float)stud.ailomark;
		rating += (float)stud.mathmark;
		rating /= 3;
		return rating;
	}

};


void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	student ivanov, petrov, sidorov;
	decanus nesterenkov;
	ivanov.id = 1;
	petrov.id = 2;
	sidorov.id = 3;
	ivanov.name = "Иванов Иван Иванович";
	ivanov.FillStudent();
	petrov.name = "Петров Петр Петрович";
	petrov.FillStudent();
	sidorov.name = "Сидоров Сидор Сидорович";
	sidorov.FillStudent();
	ivanov.rate = nesterenkov.GetStudentRate(ivanov);
	petrov.rate = nesterenkov.GetStudentRate(petrov);
	sidorov.rate = nesterenkov.GetStudentRate(sidorov);

	
	cout << "Номер студента: " << ivanov.id << " ФИО студента: " << ivanov.name << " Рейтин студента: " << ivanov.rate << endl;
	cout << "Номер студента: " << petrov.id << " ФИО студента: " << petrov.name << " Рейтин студента: " << petrov.rate << endl;
	cout << "Номер студента: " << sidorov.id << " ФИО студента: " << sidorov.name << " Рейтин студента: " << sidorov.rate << endl;
	
	
}