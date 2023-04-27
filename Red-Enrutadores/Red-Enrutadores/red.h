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
    map<string,Enrutador> Enrutadores;//conexiones directas unicamente
    vector<string> nombres_enrutadores;

public:
    Red();
    void agregarEnrutador(string);
    void agregarNodo_a_Enrutador(string);//accede al enrutador de la red y agrega conexion
    bool VerificarExistencia(string);
    void mostrarEnrutadores(string);//se podría sobrecargar
    void mostrarEnrutadores();
    void eliminar_nodoEn();
    void calcularCaminos();


    ~Red();
};

#endif // RED_H
