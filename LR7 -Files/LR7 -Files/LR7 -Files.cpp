#include <iostream>
#include <fstream>

using namespace std;

class Exception
{
public:
    Exception()
    {
        cout << "В файле отсутствуют искомые данные! " << endl;
    }
};

class Plant
{
private:
    int height;
    int age;
    int num_vars;

public:
    Plant(int heightptr, int ageptr, int variants) : height(heightptr), age(ageptr), num_vars(variants)
    {

    }

    Plant()
    {
        height = 1;
        age = 1;
        num_vars = 1;
    }

    friend ostream& operator<<(std::ostream& str, Plant& plt)
    {
        str << plt.height << ' ' << plt.age << ' ' << plt.num_vars << endl;
        return str;
    }

    friend istream& operator>>(std::istream& str, Plant& plt)
    {
        str >> plt.height >> plt.age >> plt.num_vars;
        return str;
    }

    void WriteBinary(std::ofstream& b, Plant plant)
    {
        b.write(reinterpret_cast<char*>(&plant), sizeof(Plant));
    }

    void ReadBinary(std::ifstream& b, Plant plant)
    {
        b.read(reinterpret_cast<char*>(&plant), sizeof(Plant));
    }

    static void DeleteObject(Plant& objectToDelete)
    {
        std::fstream file("original.bin", std::ios::in | std::ios::out | std::ios::binary);
        if (!file)
        {
            return;
        }

        std::ofstream tempFile("temp.bin", std::ios::out | std::ios::binary);
        if (!tempFile)
        {
            file.close();
            return;
        }

        Plant temp;
        while (file.read(reinterpret_cast<char*>(&temp), sizeof(Plant)))
        {
            if (temp.height != objectToDelete.height && temp.age != objectToDelete.age && temp.num_vars != objectToDelete.num_vars)
            {
                tempFile.write(reinterpret_cast<char*>(&temp), sizeof(Plant));
            }
        }

        file.close();
        tempFile.close();

        remove("Plants.bin");
        rename("temp.bin", "Plants.bin");
    }

    static void SearchHeight(int searchheight, int valuesearchptr)
    {
        try
        {
            bool searchptr = 0;
            ifstream filelook("Plants.bin", std::ios::out | std::ios::binary);
            Plant temp;
            while (!filelook.eof() && !searchptr)
            {
                temp.ReadBinary(filelook, temp);
                cout << temp.age << temp.height << temp.num_vars << endl;
                switch (valuesearchptr)
                {
                case 1:
                    if (temp.height == searchheight)
                    {
                        cout << "Найденный образец: " << temp.age << ' ' << temp.height << ' ' << temp.num_vars << endl;
                        searchptr = 1;
                        DeleteObject(temp);
                    }
                    break;
                case 2:
                    if (temp.age == searchheight)
                    {
                        cout << "Найденный образец: " << temp.age << ' ' << temp.height << ' ' << temp.num_vars << endl;
                        searchptr = 1;
                        DeleteObject(temp);
                    }
                    break;
                case 3:
                    if (temp.num_vars == searchheight)
                    {
                        cout << "Найденный образец: " << temp.age << ' ' << temp.height << ' ' << temp.num_vars << endl;
                        searchptr = 1;
                        DeleteObject(temp);
                    }
                    break;
                default:
                    break;
                }
            }

            if (searchptr == 0)
            {
                throw Exception();
            }
        }

        catch (Exception& exc)
        {
            cout << "Не удалось удалить значения, т.к значения отсутствуют" << endl;
        }
    }
};

int main()
{
    system("chcp 1251");
    Plant newplant;
    int switchptr, inpptr, valuesearchptr;
    bool endloop = 0;
    while (endloop == 0)
    {
        cout << "1 - Вывести значения из файла на экран\n2 - Записать значения в бинарный файл\n3 - Поиск и удаление по росту/возрасту/числу родственных растений\n4 - Завершить работу" << endl;
        cin >> switchptr;
        ofstream binf("Plants.bin", ios::binary);
        ifstream textf("Plants.txt");
        switch (switchptr)
        {
        case 1:

            for (int i = 0; i < 6; i++)
            {
                textf >> newplant;
                cout << newplant;
            }
            break;

        case 2:
            for (int i = 0; i < 6; i++)
            {
                textf >> newplant;
                cout << newplant;
                newplant.WriteBinary(binf, newplant);
            }
            break;
        case 3:
            cout << "Введите значение, что мы собираемся искать: \n 1. По росту \n 2. По возрасту \n 3. По числу" << endl;
            cin >> valuesearchptr;
            cout << "Введите значение поиска: " << endl;
            cin >> inpptr;
            Plant::SearchHeight(inpptr, valuesearchptr);
            break;

        case 4:
            cout << "Завершение работы " << endl;
            endloop = 1;
            break;
        }

    }

    return 0;
}
