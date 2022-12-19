#include <iostream>
#include <ctime>
#include <string>

using namespace std;


class Zavod {
protected:
    string name;
public:
    Zavod(string name = "Atlant") {
        cout << "����������� ������ �����" << endl;
        this->name = name;
        //cout << this->name << endl;
    }
    virtual string zavod_info() = 0;

    virtual ~Zavod() {
        cout << "����� ��������" << endl;
    }
};

class Factory : virtual public Zavod {
protected:
    int num_workers;
    int num_conveyors;
public:

    Factory(string name = "��� 0", int workeram = 10000, int num_conveyors = 4) : Zavod(name) {
        cout << "����������� ������ ��� " << endl;
        this->num_workers = workeram;
        this->num_conveyors = num_conveyors;
    }

    string zavod_info() override {
        return "��� ��� - " + name ;
    }

    virtual int get_workers_per_conv() {
        srand(time(NULL));
        int amount = rand() % 1000;
        return amount;
    }

    virtual  ~Factory() {
        cout << "��� ��������" << endl;
    }

};

class Conveyor : virtual public Factory {
protected:
    int amount_workers;
public:

    Conveyor(string name = "�������� 0", int amount_people = 10000) : Factory(name, amount_people, 5) {
        cout << "����������� ������ ��������" << endl;
        this->amount_workers = amount_people;
 
    }


    string zavod_info() override {
        return  "��������: " + name;
    }

    int get_workers_per_conv() override {
        return this->amount_workers / 5;
    }

    virtual ~Conveyor() {
        cout << "�� ��������� �������� " ;
        cout << get_workers_per_conv() << " �������" << endl;;
    }
};

class WorkPlace : virtual public Conveyor {

public:
    WorkPlace(string name = "������� ����� 0", int amount_workers = 1000) : Conveyor(name, (amount_workers * 10))
    {
        this->name = name;
    }


    string zavod_info() override {
        return  "������� �����: " + name + " ����� �������: " + to_string(amount_workers);
    }


    virtual ~WorkPlace()
    {
        cout << "������ �������� �� ������� ����� " << endl;
    }
};

int main()
{
    system("chcp 1251");
    Zavod* tseh1 = new Factory("��� 1", 5000, 5);
    Zavod* conv1 = new Conveyor("�������� 1", 1000);
    Zavod* work1 = new WorkPlace("������� ����� 1", 1000);
    Zavod* zavodik[] = { tseh1,conv1,work1 };
    for (int i = 0; i < 3; i++)
    {
        cout << endl << zavodik[i]->zavod_info() << endl;
       
    }

    for (int i = 0; i < 3; i++) {
        delete zavodik[i];
    }
    //delete zavodik;
}