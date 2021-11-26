#include "Articulo.hpp"

Articulo::Articulo(string nombre, string tallas, int precio, int cantidad, int descuento, Categoria* categoria){
    this->nombre = nombre;
    this->tallas = tallas;
    this->precio = precio;
    this->cantidad = cantidad;
    this->descuento = descuento;
    this->categoria = categoria;
}

void Articulo::setNombre(string nombre){
    this->nombre = nombre;
}

string Articulo::getNombre(){
    return this->nombre;
}

void Articulo::setTallas(string tallas){
    this->tallas = tallas;
}

string Articulo::getTallas(){
    return this->tallas;
}

void Articulo::setPrecio(int precio){
    this->precio = precio;
}

int Articulo::getPrecio(){
    return this->precio;
}

void Articulo::setCantidad(int cantidad){
    this->cantidad = cantidad;
}

int Articulo::getCantidad(){
    return this->cantidad;
}

void Articulo::setDescuento(int descuento){
    this->descuento = descuento;
}

int Articulo::getDescuento(){
    return this->descuento;
}

void Articulo::setCategoria(Categoria* categoria){
    this->categoria = categoria;
}

Categoria* Articulo::getCategoria(){
    return this->categoria;
}