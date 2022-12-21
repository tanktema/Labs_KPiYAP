#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

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
            cin >> MnozhValue[i];
            for (int j = 0; j < i; j++)
            {
                if (MnozhValue[i] == MnozhValue[j])
                {
                    cout << "Такое значение уже присутствует в множестве, добаьте другое!" << endl;
                    i--;
                }
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
    

    ~Set()
    {
        cout << "Работа прекращена" << endl;
    }
};

int main()
{
    system("chcp 1251");
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
        cin >> inputptr;
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