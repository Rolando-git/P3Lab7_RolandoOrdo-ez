#include "Tienda.hpp"

Tienda::Tienda(){

}

Tienda::~Tienda(){
    for(int i = 0; i < articulos.size(); i++){
        delete articulos[i];
    }
    articulos.clear();

    for(int j = 0; j < categorias.size(); j++){
        delete categorias[j];
    }
    categorias.clear();
}

void Tienda::crearArticulo(){
    string nombre;
    cout << "nombre del articulo:" << endl;
    cin >> nombre;
    string talla;
    cout << "talla del articulo" << endl;
    cin >> talla;
    int precio;
    cout << "precio del articulo" << endl;
    cin >> precio;
    int cantidad;
    cout << "cantidad en inventario" << endl;
    cin >> cantidad;
    int descuento;
    cout << "porcentaje de descuento:" << endl;
    cin >> descuento;
    int op;
    Categoria* c;
    cout << "categoria del articulo" << endl;
    cout << "1.shoes" << endl;
    cout << "2.hoodies" << endl;
    cout << "3.t-shirts" << endl;
    cout << "4.jackets" << endl;
    cin >> op;
    switch(op){
        case 1:
            c = new Categoria("shoes");
        break;
        case 2:
            c = new Categoria("hoodies");
        break;
        case 3:
            c = new Categoria("t-shirts");
        break;
        case 4:
            c = new Categoria("jackets");
        break;
        default: c = new Categoria("N/A");
    }
    categorias.push_back(c);
    Articulo* a = new Articulo(nombre,talla,precio,cantidad,descuento,c);
    articulos.push_back(a);
    delete a;
    delete c;
}