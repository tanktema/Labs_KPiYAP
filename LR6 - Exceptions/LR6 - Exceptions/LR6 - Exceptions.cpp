#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class SetException
{
    
public:
    string except_warn = "Неверный ввод!";
    int newvalue;
    SetException()
    {
        cout << "Такое значение уже есть в множестве! Ввведите другое" << endl;
        ReturnException();
    }

    int ReturnException()
    {
        cin >> newvalue;
        return newvalue;
    }

    int ShowUnexpected()
    {
        unexpected();
        terminate();
    }


};

void _terminate()
{
    cout << "Ошибка! Выполнение программы прекращено" << endl;
}

void _unexpected()
{
    cout << "Неожиданное значение!" << endl;
}

template<class T, int length>
class Set
{
public:
    T MnozhValue[length];
    Set()
    {
        cout << "Множество инициализировано!" << endl;
    }
    T SetInput()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Введите следующее значение в множество" << endl;
            try
            {
                cin >> MnozhValue[i];
                for (int j = 0; j < i; j++)
                {
                    if (MnozhValue[i] == MnozhValue[j])
                    {
                        throw SetException();
                        
                    }
                }
            }
            catch (SetException& setxec)
            {
                MnozhValue[i] = setxec.ReturnException();
            }
           
        }
        T sortptr;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (MnozhValue[j] > MnozhValue[i])
                {
                    sortptr = MnozhValue[j];
                    MnozhValue[j] = MnozhValue[i];
                    MnozhValue[i] = sortptr;
                }

            }
        }

        return 1;
    }
    void LookSet()
    {

        for (int i = 0; i < length; i++)
        {
            cout << MnozhValue[i] << endl;
        }
    }

    void InvertSet()
    {
        T sortptr;
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (MnozhValue[j] < MnozhValue[i])
                {
                    sortptr = MnozhValue[j];
                    MnozhValue[j] = MnozhValue[i];
                    MnozhValue[i] = sortptr;
                }

            }
        }
    }

    T operator[](int index)
    {
        return MnozhValue[index];
    }
    T operator+(T val)
    {
        for (int i = 0; i < length; i++)
        {
            MnozhValue[i] = MnozhValue[i] + val;
        }
        return *MnozhValue;
    }
    T operator-(T val)
    {
        for (int i = 0; i < length; i++)
        {
            MnozhValue[i] = MnozhValue[i] - val;
        }
        return *MnozhValue;
    }

    ~Set()
    {
        cout << "Работа прекращена" << endl;
    }
};

int main()
{
    system("chcp 1251");
    set_terminate(_terminate);
    set_unexpected(_unexpected);
    int numbers[10];
    const int amount = 10;
    int inputptr, number_change;
    bool endloop = 0;
    Set<int, amount> IntSet;
    cout << "Заполнение множества" << endl;
    IntSet.SetInput();
    cout << "Действия с множеством:" << endl;
    while (endloop != 1)
    {
        cout << "Доступные действия с множеством: \n1 - Инвертировать множество\n2 - Просмотреть множество\n3 - Увеличить все элементы множества на число\n4 - Уменьшить все эелементы множества на число\n5-Выход" << endl;
        try
        {
            cin >> inputptr;
            if (inputptr < 1 || inputptr > 5)
            {
                throw SetException();
            }
        }
        catch (SetException& setexcept)
        {
            setexcept.ShowUnexpected();
        }
        switch (inputptr)
        {
        case 1:
            IntSet.InvertSet();
            break;

        case 2:
            for (int i = 0; i < 10; i++)
            {
                cout << IntSet.MnozhValue[i] << " ";
            }
            break;
        case 3:
            cout << "Введите число:" << endl;
            cin >> number_change;
            for (int i = 0; i < 10; i++)
            {
                IntSet.MnozhValue[i] = IntSet.MnozhValue[i] + number_change;
            }
            break;
        case 4:
            cout << "Введите число:" << endl;
            cin >> number_change;
            for (int i = 0; i < 10; i++)
            {
                IntSet.MnozhValue[i] = IntSet.MnozhValue[i] - number_change;
            }
            break;
        case 5:
            cout << "Завершение работы " << endl;
            endloop = 1;
            break;
        }

    }

}