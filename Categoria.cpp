#include "Categoria.hpp"

Categoria::Categoria(string nombre){
    this->nombre = nombre;
}

void Categoria::setNombre(string nombre){
    this->nombre = nombre;
}

string Categoria::getNombre(){
    return this->nombre;
}