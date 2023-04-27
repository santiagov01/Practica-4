#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <map>
#include <iostream>
#include <string>
using namespace std;

class Enrutador
{
private:
    //Conexiones directas. La red entra acá para establecer
    //las conexiones de los nodos
    map<string,int> nodo; //{A : 0, B :5, C: 10}

    //Camino más cercano
    //map<string,int> conections;

public:
    Enrutador();
    void agregarNodo(string,int);
    void eliminarNodo();
    void mostrarNodos();

    map<string, int> getNodo() const;

    void setNodo(const map<string, int> &newNodo);

    ~Enrutador();
};

#endif // ENRUTADOR_H
