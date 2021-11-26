#pragma once
#include <string>
using std::string;

class Categoria{
    string nombre;

    public:
        Categoria(string);
        void setNombre(string);
        string getNombre();
};