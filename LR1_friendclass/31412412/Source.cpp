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
		
		cout << "������� ������ �� ���������: ����, ������, ������ ���������� �������� " << name << endl;
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
	ivanov.name = "������ ���� ��������";
	ivanov.FillStudent();
	petrov.name = "������ ���� ��������";
	petrov.FillStudent();
	sidorov.name = "������� ����� ���������";
	sidorov.FillStudent();
	ivanov.rate = nesterenkov.GetStudentRate(ivanov);
	petrov.rate = nesterenkov.GetStudentRate(petrov);
	sidorov.rate = nesterenkov.GetStudentRate(sidorov);

	
	cout << "����� ��������: " << ivanov.id << " ��� ��������: " << ivanov.name << " ������ ��������: " << ivanov.rate << endl;
	cout << "����� ��������: " << petrov.id << " ��� ��������: " << petrov.name << " ������ ��������: " << petrov.rate << endl;
	cout << "����� ��������: " << sidorov.id << " ��� ��������: " << sidorov.name << " ������ ��������: " << sidorov.rate << endl;
	
	
}