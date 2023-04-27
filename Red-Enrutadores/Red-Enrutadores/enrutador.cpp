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

void Enrutador::eliminarNodo()
{
    string name_destin;
    cout << "Ingrese el nodo a borrar" << endl;
    cin >> name_destin;
    //verificar que exista en el diccionario
    nodo.erase(name_destin);
}

void Enrutador::mostrarNodos()
{
    map<string, int>::iterator it;
    for(it=nodo.begin(); it!=nodo.end(); ++it){
      cout << it->first << " => " << it->second << '\n';
    }
}


map<string, int> Enrutador::getNodo() const
{
    return nodo;
}

void Enrutador::setNodo(const map<string, int> &newNodo)
{
    nodo = newNodo;
}
