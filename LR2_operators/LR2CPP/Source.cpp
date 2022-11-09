#include <iostream>
#include <string>

using namespace std;

class integer
{
private:
	int value;
public:
	integer(int num)
	{
		if (num >= 0)
			value = num;
		else
			value = num * -1;
	}

	integer& operator ++()
	{
		this->value += 10;
		return *this;
	}

	integer& operator ++(int)
	{
		this->value += 10;
		return *this;
	}

	integer& operator --()
	{
		this->value -= 10;
		if (this->value < 0)
			this->value = 0;
		return *this;
	}

	integer& operator --(int)
	{
		this->value -= 10;
		if (this->value < 0)
			this->value = 0;
		return *this;
	}

	integer operator() (int o)
	{
		if (o >= 0)
			this->value = o;
		else
			this->value = o * -1;
		return *this;
	}

	integer operator = (integer x)
	{
		this->value = x.value;
		return *this;
	}

	friend ostream& operator <<(ostream& offs, const integer& a)
	{
		return offs << a.value;
	}

	friend bool operator ==(const integer& a, const integer& b)
	{
		return a.value == b.value;
	}

	friend const integer operator +(const integer& a, const integer& b)
	{
		return integer(a.value + b.value);
	}

	friend const integer operator -(const integer& a, const integer& b)
	{
		return integer(a.value - b.value);
	}

	int get()
	{
		return this->value;
	}


	
};


void main()
{
	system("chcp 1251");
	system("CLS");
	integer a(10), b(-20);
	int k;
	cout << a << endl;
	a = a + b;
	cout << a << endl;
	a(60);
	a++;
	cout << a++ << endl;
	++a;
	cout << a << endl;
	a--;
	cout << a-- << endl;
	--a;
	cout << a << endl;
	if (a == b)
	{
		cout << "Значения равны!" << endl;
	}
	else
		cout << "Значения не равны!" << endl;

	a = b;
	if (a == b)
	{
		cout << "Значения равны!" << endl;
	}
	else
		cout << "Значения не равны!" << endl;

	k = a.get();
	cout << k << endl;
}