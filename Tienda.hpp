#pragma once
#include <iostream>
#include "Articulo.hpp"
#include "Categoria.hpp"
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Tienda{
    vector<Articulo*> articulos;
    vector<Categoria*> categorias;

    public:
        Tienda();
        ~Tienda();
        void crearArticulo();
        void editarArticulo();
        void imprimirArticulos();
        void eliminarArticulo();
};