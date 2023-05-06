#include "enrutador.h"
#include <map>
#include <iostream>
#include <string>
using namespace std;


Enrutador::~Enrutador()
{

}

Enrutador::Enrutador()
{


}

void Enrutador::agregarNodo(string name_nodo, int peso)
{
    nodo.insert(make_pair(name_nodo,peso));
    /*
    //establece las conexiones iniciales para un nodo
    //recordar incluir condicion para el mismo nodo
    // e.g si se crea el nodo d, su peso para si mismo es 0
    cout << "Ingrese nombre del nodo: ";
    cin >> name_nodo;
    //Verificar nodo exista!!!
    cout << "Ingrese peso: ";
    cin >> peso;*/

}

bool Enrutador::verificarExistenciaNodo(string name_router)
{
    if (nodo.find(name_router) == nodo.end()) {
        return false;
    }
    return true;
}

void Enrutador::eliminarNodo()
{
    string name_destin;
    cout << "Ingrese el nodo a borrar" << endl;
    cin >> name_destin;
    if(verificarExistenciaNodo(name_destin)){
        nodo.erase(name_destin);
        cout << "Se ha borrado con exito\n";
    }else cout << "El nodo ingresado no existe.\n";

}

void Enrutador::eliminarNodo(string name)
{
    nodo.erase(name);
}

void Enrutador::mostrarNodos()
{

    cout << "\tNodo\tPeso\n";
    for(it=nodo.begin(); it!=nodo.end(); ++it){      
      cout << "\t" << it->first << " \t " << it->second << endl;
    }
}

void Enrutador::cambiarPesoNodo(string destino, int w)
{
    nodo[destino] = w;
}


map<string, int> Enrutador::getNodo() const
{
    return nodo;
}

void Enrutador::setNodo(const map<string, int> &newNodo)
{
    nodo = newNodo;
}
