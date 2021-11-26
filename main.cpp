#include <iostream>
#include "Tienda.hpp"
using std::cin;
using std::cout;
using std::endl;

int menu();

int main(){
    Tienda* t = new Tienda();
    int opcion = menu();
    while(opcion != 5){
        switch(opcion){
            case 1:
            {
                t->crearArticulo();
            }
            break;
            case 2:
            {
                int op = 0;
                cout << "1.Agregar articulo" << endl;
                cout << "2.Modificar articulo" << endl;
                cout << "3.Eliminar articulo" << endl;
                cin >> op;
                switch(op){
                    case 1:
                        t->crearArticulo();
                    break;
                    case 2:
                        t->editarArticulo();
                    break;
                    case 3:
                        t->eliminarArticulo();
                    break;
                    default: cout << "Error, opcion no valida" << endl;
                }
            }
            break;
            case 3:
            {
                t->imprimirArticulos();
            }
            break;
            case 4:
            {
                t->buscarArticulos();
            }
            break;
            default: cout << "Error, opcion no valida" << endl;
        }
        opcion = menu();
    }
    delete t;
    return 0;
}

int menu(){
    int opcion = 0;
    cout << "1.Agregar Categorias" << endl;
    cout << "2.Mantenimiento de articulos" << endl;
    cout << "3.Estadisticas generales" << endl;
    cout << "4.Busqueda por categoria y talla" << endl;
    cout << "5.Salir" << endl;
    cin >> opcion;
    return opcion;
}