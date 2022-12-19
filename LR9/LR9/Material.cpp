#include "Material.h"

Material::Material(std::string name, std::string typemat) : mat_name(name), type(typemat)
{
    std::cout << "Материал: " << type << ' ' << mat_name << endl;
}