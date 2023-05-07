#include <iostream>
#include "auxiliar.h"
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
bool verificarVector(vector<string> vector, string compare)
{
    for(unsigned int i = 0; i < vector.size(); i++) {
       //cout << "value of vec [" << i << "] = " << vector[i] << endl;
       if(vector[i] == compare)return true;
    }
    return false;
}

void eliminarElementoVector(vector<string>& vec, string elemento)
{
    auto it = find(vec.begin(), vec.end(), elemento);
    // Verificar si se encontró el elemento
    if (it != vec.end()) {
        // Eliminar el elemento del vector
        vec.erase(it);
    }
}

void LeerRed(string name_file, Red *red_archivo)
{
    string linea;
    ifstream fin;
    string N1,N2,W;
    char delimitador = ';';
    int salto;
    salto = saltos(name_file);
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }
        getline(fin,linea);
        stringstream inputstringstream(linea);
        while(getline(inputstringstream,N1,delimitador)){
            red_archivo->agregarEnrutador(N1);
        }

        for(int i = 1; i<salto;i++){
            getline(fin,linea);
            stringstream inputstringstream(linea); //convierte linea a sstream
            getline(inputstringstream,N1,delimitador);
            getline(inputstringstream,N2,delimitador);
            getline(inputstringstream,W,delimitador);
            red_archivo->agregarNodo_a_Enrutador(N1,N2,stoi(W));

        }
        fin.close();


    }
    catch (char c){
        cout<<"Error # "<<c<<": ";

        if(c=='2'){
            cout<<"Error al abrir el archivo para lectura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }

}

int saltos(string name_file){
    ifstream fin;
    int saltos = 0;
    try{

        fin.open(name_file);        //abre el archivo para lectura
        if(!fin.is_open()){
            throw '2';
        }

        while(fin.good()){ //lee caracter a caracter hasta el fin del archivo
            char temp=fin.get();
            if(fin.good()){
                if(temp == '\n'){
                    saltos++;//contar saltos de linea (cantidad cursos)
                }
            }
        }
        fin.close();
        return saltos;
    }
    catch (char c){
        cout<<"Error # "<<c<<": ";
        if(c=='2'){
            cout<<"Error al abrir el archivo para escritura.\n";
        }
    }
    catch (...){
        cout<<"Error no definido\n";
    }
    return 1;


}
void menu(Red *nueva){
    short int st=0;
    while(st !=-1){
        cout << "Ingresa opcion: \n";
        cout << "1.Crear nuevo enrutador.\n2.Crear nueva conexion a Enrutador\n3.Eliminar enrutador.\n";
        cout << "4.Eliminar nodo de enrutador\n5.Cambiar peso de un enlace\n6.Calcular peso camino mas cercano\n7.Mostrar camino mas cercano con nodos";
        cout << "\n8.Mostrar Nodos de la red";
        cout << "\n-1 para salir.\n==>";
        cin >> st;
        switch (st) {
        case 1:
            nueva->agregarEnrutador();
            break;
        case 2:
            nueva->agregarNodo_a_Enrutador();//puedo dejar "X" dentro de la funcion
            break;
        case 3:
            nueva->eliminar_Router();
            break;
        case 4:
            nueva->eliminar_nodoEn();

            break;
        case 5:
            nueva->cambiarPeso();
            break;
        case 6:
            nueva->calcularCaminos3(1);
            break;
        case 7:
            nueva->calcularCaminos3(0);
            break;
        case 8:
            nueva->mostrarEnrutadores();
            break;
        case -1:

            break;
        default:
            break;
        }
    }
}
