#ifndef RED_H
#define RED_H
#include "enrutador.h"
#include <map>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Red
{
private:
    //{A : {A:0,B:4,C:10,D:4},B : {A:4,B:0,D:1}} prototipo para la red
    map<string,Enrutador> Enrutadores_red;//conexiones directas unicamente
    map<string,Enrutador>::iterator itr_red;
    vector<string> nombres_enrutadores;

public:
    Red();
    void agregarEnrutador();
    void agregarEnrutador(string);
    void agregarNodo_a_Enrutador();//accede al enrutador de la red y agrega conexion
    void agregarNodo_a_Enrutador(string nombre);
    void agregarNodo_a_Enrutador(string origen, string destino, int peso);
    bool VerificarExistencia(string);
    void mostrarEnrutadores();//se podría sobrecargar
    void mostrarEnrutadores(string name_router);
    void eliminar_nodoEn();//elimina solo un elemento
    void eliminar_Router();//elimina todo el router
    void cambiarPeso();


    void calcularCaminos();
    void calc_nodo_menorw(map<string,vector<string>>, vector<string>, string &);
    void calcularCaminos2();
    void calcularCaminos3(int op);
    void calc_nearest(map<string, vector<string>>, vector<string> visitados, string &actual);




    ~Red();
};

#endif // RED_H
