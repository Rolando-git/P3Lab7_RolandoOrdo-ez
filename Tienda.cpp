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

void Tienda::crearCategoria(){
    for(int i = 0; i < 4; i++){
        if(i == 0){
            Categoria* c = new Categoria("shoes");
            categorias.push_back(c);
            delete c;
        }
        if(i == 1){
            Categoria* c = new Categoria("hoodies");
            categorias.push_back(c);
            delete c;
        }
        if(i == 2){
            Categoria* c = new Categoria("t-shirts");
            categorias.push_back(c);
            delete c;
        }
        if(i == 3){
            Categoria* c = new Categoria("jackets");
            categorias.push_back(c);
            delete c;
        }
    }
    string cat;
    cout << "Ingrese nueva categoria" << endl;
    cin >> cat;
    Categoria* c = new Categoria(cat);
    categorias.push_back(c);
    delete c;
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
            c = categorias[0];
        break;
        case 2:
            c = categorias[1];
        break;
        case 3:
            c = categorias[2];
        break;
        case 4:
            c = categorias[3];
        break;
        default: c = categorias[4];
    }
    Articulo* a = new Articulo(nombre,talla,precio,cantidad,descuento,c);
    articulos.push_back(a);
    delete a;
    delete c;
}

void Tienda::editarArticulo(){
    int p = 0;
    cout << "ingrese posicion del articulo a editar" << endl;
    cin >> p;
    int op = 0;
    cout << "1.Nombre" << endl;
    cout << "2.Talla" << endl;
    cout << "3.Precio" << endl;
    cout << "4.Cantidad" << endl;
    cout << "5.Descuento" << endl;
    cout << "6.Categoria" << endl;
    cin >> op;
    switch(op){
        case 1:
        {
            string nombre;
            cout << "ingrese nuevo nombre" << endl;
            cin >> nombre;
            articulos[p]->setNombre(nombre);
        }
        break;
        case 2:
        {
            string talla;
            cout << "ingrese nueva talla" << endl;
            cin >> talla;
            articulos[p]->setTallas(talla);
        }
        break;
        case 3:
        {
            int precio = 0;
            cout << "ingrese nuevo precio" << endl;
            cin >> precio;
            articulos[p]->setPrecio(precio);
        }
        break;
        case 4:
        {
            int cantidad = 0;
            cout << "ingrese cantidad" << endl;
            cin >> cantidad;
            articulos[p]->setCantidad(cantidad);
        }
        break;
        case 5:
        {
            int descuento = 0;
            cout << "ingrese nuevo descuento" << endl;
            cin >> descuento;
            articulos[p]->setDescuento(descuento);
        }
        break;
        case 6:
        {
            string cat;
            cout << "ingrese nueva categoria" << endl;
            cin >> cat;
            Categoria* c = new Categoria(cat);
            articulos[p]->setCategoria(c);
            delete c;
        }
        break;
        default: cout << "Error, opcion no valida" << endl;
    }
}

void Tienda::imprimirArticulos(){
    //unidades por categoria
    cout << "UNIDADES POR CATEGORIA" << endl;
    for(int i = 0; i < categorias.size(); i++){
        string cat = categorias[i]->getNombre();
        cout << cat << ":" << endl;
        int cant = 0;
        for(int j = 0; j < articulos.size(); j++){
            Categoria* C = articulos[j]->getCategoria();
            string cat_art = C->getNombre();
            if(cat_art == cat){
                cant = cant + articulos[j]->getCantidad();
                string n = articulos[j]->getNombre();
                cout << n << " " << cant << endl;
            }
            delete C;
        }
    }
    //precio total por categoria
    cout << "PRECIO TOTAL POR CATEGORIA" << endl;
    for(int i = 0; i < categorias.size(); i++){
        string cat = categorias[i]->getNombre();
        cout << cat << ":" << endl;
        int cant = 0;
        for(int j = 0; j < articulos.size(); j++){
            Categoria* C = articulos[j]->getCategoria();
            string cat_art = C->getNombre();
            if(cat_art == cat){
                cant = cant + articulos[j]->getPrecio();
                cout << cant << endl;
            }
            delete C;
        }
    }
    //precio total de los articulos de la tienda sin descuento
    cout << "PRECIO TOTAL DE LOS ARTICULOS SIN DESCUENTO" << endl;
    int cant = 0;
    for(int i = 0; i < articulos.size(); i++){
        cant = cant + articulos[i]->getPrecio();
    }
    cout << cant << endl;
    cant = 0;
    //total de unidades en la Tienda
    cout << "TOTAL DE UNIDADES EN LA TIENDA" << endl;
    for(int i = 0; i < articulos.size(); i++){
        cant = cant + articulos[i]->getCantidad();
    }
    cout << cant << endl;
    cant = 0;
}

void Tienda::buscarArticulos(){
    int op = 0;
    cout << "1.Categorias" << endl;
    cout << "2.Tallas" << endl;
    cout << "3.Precio menor a mayor" << endl;
    cout << "4.Precio mayor a menor" << endl;
    cout << "5.Ninguna" << endl;
    cin >> op;
    switch(op){
        case 1:
        {
            for(int i = 0; i < categorias.size(); i++){
                string cat = categorias[i]->getNombre();
                cout << cat << ":" << endl;
                for(int j = 0; j < articulos.size(); j++){
                    Categoria* C = articulos[j]->getCategoria();
                    string cat_art = C->getNombre();
                    if(cat_art == cat){
                        string n = articulos[j]->getNombre();
                        cout << n << endl;
                    }
                    delete C;
                }
            }
        }
        break;
        case 2:
        {
            char talla;
            cout << "Ingrese talla a buscar" << endl;
            cin >> talla;
            for(int i = 0; i < articulos.size(); i++){
                string t = articulos[i]->getTallas();
                if(t.find(talla)){
                    string n = articulos[i]->getNombre();
                    cout << n << endl;
                }
            }
        }
        break;
        case 3:
        {
            vector<Articulo*> temp = this->articulos;
            Articulo* a;
            for(int i = 0; i < temp.size(); i++){
                for(int j = i + 1; j < temp.size(); j++){
                    if(temp[i]->getPrecio() > temp[j]->getPrecio()){
                        a = temp[i];
                        temp[i] = temp[j];
                        temp[j] = a;
                    }
                }
            }
            delete a;
            for(int i = 0; temp.size(); i++){
                string n = temp[i]->getNombre();
                cout << n << endl;
            }
            temp.clear();
        }
        break;
        case 4:
        {
            vector<Articulo*> temp = this->articulos;
            Articulo* a;
            for(int i = 0; i < temp.size(); i++){
                for(int j = i + 1; j < temp.size(); j++){
                    if(temp[i]->getPrecio() > temp[j]->getPrecio()){
                        a = temp[i];
                        temp[i] = temp[j];
                        temp[j] = a;
                    }
                }
            }
            delete a;
            for(int i = temp.size()-1; i > 0; i--){
                string n = temp[i]->getNombre();
                cout << n << endl;
            }
            temp.clear();
        }
        break;
        case 5:
        {
            for(int i = 0; i < articulos.size(); i++){
                string nombre = articulos[i]->getNombre();
                string tallas = articulos[i]->getTallas();
                int precio = articulos[i]->getPrecio();
                int cantidad = articulos[i]->getCantidad();
                int descuento = articulos[i]->getDescuento();
                Categoria* c = articulos[i]->getCategoria();
                string categoria = c->getNombre();
                delete c;
                cout << nombre << " ";
                cout << tallas << " ";
                cout << precio << " ";
                cout << cantidad << " ";
                cout << descuento << " ";
                cout << categoria << " ";
                cout <<"\n";
            }
        }
        break;
        default: cout << "Error" << endl;
    }
}

void Tienda::eliminarArticulo(){
    int p = 0;
    cout << "ingrese posicion del articulo a eliminar" << endl;
    cin >> p;
    this->articulos.erase(articulos.begin() + p);
}