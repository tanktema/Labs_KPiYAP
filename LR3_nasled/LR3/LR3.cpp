#include <iostream>
#include <ctime>

using namespace std;


class zavod {
    friend void main();
    friend class factory1;
    friend class factory2;
public:
    string zavodhead;
private:
    int total_num_of_workers;
    string production;
    int amount_of_prod;

    zavod(string zavodname = "Atlant", string targetprod = "Холодильники")
    {
        srand(time(NULL));
        zavodhead = zavodname;
        production = targetprod;
        total_num_of_workers = rand() % 1000;
        amount_of_prod = rand() % 2000;
        cout << "Работников завода " << zavodhead << ": " << total_num_of_workers << endl;
        cout << "Им необходимо произвести " << amount_of_prod << " ед. продукции " << production << endl;
    }
    ~zavod()
    {
        cout << "Работа началась!" << endl;
    }
};

class factory1 : private zavod {
    friend class conveyor1;
    friend void main();
private:
    int num_of_fact1_workers;
    int production_by_fact1;
    factory1(float percent = 0.5, string factoryname = "Atlant", string productionname = "Холодильники") : zavod(factoryname, productionname)
    {
        num_of_fact1_workers = total_num_of_workers * percent;
        production_by_fact1 = amount_of_prod * percent;
        cout << "В первом цеху работает " << num_of_fact1_workers << " людей и им нужно произвести " << production_by_fact1 << " ед. продукции " << production << endl;
        
    }
    ~factory1()
    {
        cout << "Первый цех начал работу!" << endl;
    }
};

class conveyor1 : private factory1 {
    int num_prod_lines;
    int people_per_prodline;
    friend void main();
    conveyor1(int num_convs = 4, float to_fact_1 = 0.5, string factoryname = "Atlant", string productionname = "Холодильники") : factory1(to_fact_1, factoryname, productionname)
    {
        num_prod_lines = num_convs;
        people_per_prodline = num_of_fact1_workers / num_prod_lines;
        cout << "На этом участке производства работает " << num_prod_lines << " конвейеров, на каждом из которых работает " << people_per_prodline << " людей" << endl;
    }

    ~conveyor1()
    {
        for (int i = 1; i <= num_prod_lines; i++)
        {
            cout << "Конвейер номер " << i << " начал работу!" << endl;
        }
    }
};


class onecamfridge {
    friend void main();
    friend class twocamfridge;
    friend class fourcamfridge;

    
private:
    int power_camera;
    string fridgemark;

    onecamfridge(int campower = 100, string fridgename = "Fridge2")
    {
        fridgemark = fridgename;
        power_camera = campower;
        cout << "В холодильнике марки " << fridgemark << " 1 камера мощностью " << power_camera << endl;
    }

    ~onecamfridge()
    {

        cout << "Однокамерный холодильник поступил в продажу" << endl;
    }
};

class twocamfridge : private onecamfridge {
    friend class fourcamfridge;
    friend void main();
private:
    int power_camera_2;
    twocamfridge(int campower = 100, string fridgemark1 = "Fridge", string fridge2 = "Fridge2") : onecamfridge(campower, fridge2)
    {
        fridgemark = fridgemark1;
        power_camera_2 = campower;
        power_camera = campower;
        cout << "В холодильнике марки " << fridgemark << " 2 камеры мощностью " << power_camera << " " << power_camera_2 << " каждая" << endl;
    }

    ~twocamfridge()
    {
        cout << "Двухкамерный холодильник поступил в продажу" << endl;
    }
};

class fourcamfridge : private twocamfridge {
    friend void main();
private:
    int power_camera_3;
    int power_camera_4;
    fourcamfridge(int campower = 100, string fridge4cam = "Fridge0", string fridge2cam = "Fridge", string fridge1cam = "Fridge2") : twocamfridge(campower, fridge2cam, fridge1cam)
    {
        fridgemark = fridge4cam;
        power_camera = campower;
        power_camera_2 = campower;
        power_camera_3 = campower;
        power_camera_4 = campower;
        cout << "В холодильнике марки " << fridgemark << " 4 камеры мощностью " << power_camera << " " << power_camera_2 << " " << power_camera_3 << " " << power_camera_4 << " каждая" << endl;
    }

    ~fourcamfridge()
    {
        cout << "Четырехкамерный холодильник поступил в продажу" << endl;
    }
};


class largefactory {
    friend void main();
public:
    string flargename;
    int workerslf;
    largefactory(string name = "Большой завод", int workeram = 4000)
    {
        flargename = name;
        workerslf = workeram;
        cout << flargename << endl;
    }
};



class smallfactory1 : virtual public largefactory {
    friend void main();
    friend class bigfactory;
private:
    string smfname1;
    int smfworkers1;
    smallfactory1(int workers = 1000, string fname1 = "Цех 1")
    {
        smfworkers1 = workerslf * 0.5;
        smfname1 = fname1;
        cout << smfworkers1 << endl;
        cout << smfname1 << endl;
    }
};

class smallfactory2 : virtual public largefactory {
    friend void main();
    friend class bigfactory;
private:
    string smfname2;
    int smfworkers2;
    smallfactory2(int workers = 1000, string fname1 = "Цех 2")
    {
        smfworkers2 = workerslf * 0.5;
        smfname2 = fname1;
        cout << smfworkers2 << endl;
        cout << smfname2 << endl;
    }
};



class bigfactory : private smallfactory1, private smallfactory2 {
    friend void main();
private:
    string bigfname;
    int bigfwokers;

    bigfactory(string factoryname = "Фабрика")
    {
        bigfname = factoryname;
        bigfwokers = smfworkers1 + smfworkers2;
    }

    ~bigfactory()
    {
        cout << bigfname << endl;
        cout << bigfwokers << endl;
        cout << smfworkers1 << endl;
        cout << smfworkers2 << endl;
        cout << smfname2 << endl;
        cout << smfname1 << endl;
        cout << flargename << endl;
    }
};


void main()
{
    system("chcp 1251");
    zavod atlant("Atlant", "Холодильники");
    conveyor1(3, 0.3, atlant.zavodhead, atlant.production);
    fourcamfridge(150, "Атлант-4");

    bigfactory factory("Заводик");

}
