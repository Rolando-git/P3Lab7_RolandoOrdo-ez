#pragma once
#include <string>
using std::string;

class Articulo{
    string nombre;
    string tallas;
    int precio;
    int cantidad;
    int descuento;
    string categoria;

    public:
        Articulo(string,string,int,int,int,string);
        void setNombre(string);
        string getNombre();
        void setTallas(string);
        string getTallas();
        void setPrecio(int);
        int getPrecio();
        void setCantidad(int);
        int getCantidad();
        void setDescuento(int);
        int getDescuento();
        void setCategoria(string);
        string getCategoria();
};