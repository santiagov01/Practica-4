#include "red.h"
#include "enrutador.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
Red::Red()
{

}

void Red::agregarEnrutador(string nombre)
{
    //Agrega un enrutador totalmente nuevo
    Enrutador nuevo;
    //cout << "Ingrese el nombre del nuevo enrutador: ";
    //cin>> nombre;
    //nombres_enrutadores
    //Verifico que nodo no esté repetido
    if(VerificarExistencia(nombre)){
        cout << "EL ENRUTADOR " << nombre << " YA EXISTE!!!\n";
        return;
    }
    cout << "Ahora vas a ingresar las conexiones y pesos: ";
    //Verifico que nodo a conectar exista
    nuevo.agregarNodo(nombre,0);
    Enrutadores.insert(make_pair(nombre,nuevo));
    cout << "Se ha creado el nuevo enrutador " << nombre << " con exito.\n";
    agregarNodo_a_Enrutador(nombre);

}

void Red::agregarNodo_a_Enrutador(string name_origin)
{

    string name_destin;
    int peso = 0;
    string opc="Y";


    while(opc=="Y"){
        cout << "Ingresa nombre del nodo para conectar con el enrutador " << name_origin << "\n==>";
        cin>> name_destin;

        //verificar que exista en la lista de los enrutadores
        //Verifcar que no sea el mismo
        cout << "Ingrese el peso respectivo de "<< name_destin << "\n==>";
        cin >> peso;
        Enrutadores[name_origin].agregarNodo(name_destin,peso);
        cout << "Quieres asignar conexiones al enrutador? \n";
        cout << "Si (Escribe Y)\nNo (Escribe N)\n=>";
        cin>>opc;
    }
    //posible verificación de peso
    //Enrutadores[name_origin].agregarNodo(name_destin,peso);

}

bool Red::VerificarExistencia(string nombre_ingresado)
{
    if (Enrutadores.find(nombre_ingresado) == Enrutadores.end()) {
        return false;
    }
    return true;
    vector<string>::iterator v = nombres_enrutadores.begin(); //Iterador que referencia al primer elemento
    while( v != nombres_enrutadores.end()) {
       cout << "value of v = " << *v << endl;
       if(*v == nombre_ingresado) return true;
       v++;

    }
    return false;
}

void Red::mostrarEnrutadores(string name_router)
{
    //iterador de multimapa (1)
    //iterador de mapa, luego accedo a los nodos en enrutadores.h
    map<string,int> copia;
    Enrutador copia_nodos;
    copia_nodos = Enrutadores[name_router];
    //cout << "LOS NODOS DEL ENRUTADOR " << name_router << " SON: " << endl;
    //copia_nodos.mostrarNodos();

    map<string,map<string,int>> copia_enrutador;
    copia_enrutador[name_router]=Enrutadores[name_router].getNodo();


    cout << "\nThe mapmap is : \n";
    cout << "\tKEY\tELEMENT\n";
    for(auto const &itr2 : copia_enrutador) {
        cout << "\tPara " << itr2.first << ":\n";
      // itr2.first is the first key
      for(auto const &itr3 : itr2.second) {
        // itr3.first is the second key
        // itr3.second is the data
        cout << '\t' << itr3.first << '\t' << itr3.second << '\n';
      }
    }
    cout << endl;


}

void Red::eliminar_nodoEn()
{
    string name_router;
    //string name_destin;
    cout << "Ingresa el nombre del enrutador de origen al cual quieres eliminarle un nodo" << endl;
    cin >> name_router;
    //cout << "Ahora ingresa el nombre del nodo que quieres borrar: \n";
    //cin >> name_destin;
    Enrutadores[name_router].eliminarNodo();//accede al enrutador individual y elimina nodo
    //Eliminar conexion con
}

Red::~Red()
{

}
