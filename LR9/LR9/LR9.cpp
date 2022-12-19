#include <iostream>

using namespace std;

namespace architecture_object
{
    class Coordinates
    {
    public:
        double x_coord;
        double y_coord;

        Coordinates(double x, double y) : x_coord(x), y_coord(y)
        {
            cout << x_coord << "Широты " << y_coord << "Долготы" << endl;
        }
    };

    class Author
    {
    public:
        string name;

        Author(string authname) : name(authname)
        {
            cout << "Автор: " << name << endl;
        }
    };

    class Material
    {
    public:
        string mat_name;
        string type;

        Material(string name, string typemat) : mat_name(name), type(typemat)
        {
            cout << "Материал: " << type << ' ' << mat_name << endl;
        }
    };

    class Desc
    {
    public:
        string description;

        Desc(string descript) : description(descript)
        {
            cout << description << endl;
        }
    };

    class Memorial : public Coordinates, public Author, public Material, public Desc
    {
        bool is_unesco;
        Memorial(bool unesco, double xc, double yc, string authorname, string material, string mattype, string descript) :
            Desc(descript), Material(material, mattype), Author(authorname), Coordinates(xc, yc), is_unesco(unesco)
        {

        }
    };
}

int main()
{
    
}

