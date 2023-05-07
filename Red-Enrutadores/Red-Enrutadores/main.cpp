#include <iostream>
#include "enrutador.h"
#include "red.h"
#include <map>
#include <string>
using namespace std;

int main()
{
    Red nueva;
    short int st=0;
    nueva.agregarEnrutador("A");
    nueva.agregarEnrutador("B");
    nueva.agregarEnrutador("C");
    nueva.agregarEnrutador("D");
    nueva.agregarEnrutador("E");
    nueva.agregarEnrutador("F");
    nueva.agregarEnrutador("G");

    nueva.agregarNodo_a_Enrutador("A","B",3);
    nueva.agregarNodo_a_Enrutador("A","C",6);
    nueva.agregarNodo_a_Enrutador("B","C",2);
    nueva.agregarNodo_a_Enrutador("B","D",1);
    nueva.agregarNodo_a_Enrutador("C","D",4);
    nueva.agregarNodo_a_Enrutador("C","E",2);
    nueva.agregarNodo_a_Enrutador("D","E",6);
    nueva.agregarNodo_a_Enrutador("E","G",2);
    nueva.agregarNodo_a_Enrutador("E","F",2);
    nueva.agregarNodo_a_Enrutador("F","G",3);

    while(st !=-1){
        cout << "Ingresa opcion: \n";
        cout << "1.Crear nuevo enrutador.\n2.Crear nueva conexion a Enrutador\n3.Eliminar enrutador.\n";
        cout << "4.Eliminar nodo de enrutador\n5.Cambiar peso de un enlace\n6.Calcular peso camino mas cercano\n7.Mostrar camino mas cercano con nodos";
        cout << "\n8.Mostrar Nodos de la red";
        cout << "-1 para salir.\n==>";
        cin >> st;
        switch (st) {
        case 1:
            nueva.agregarEnrutador();
            nueva.mostrarEnrutadores();

            break;
        case 2:
            nueva.agregarNodo_a_Enrutador();//puedo dejar "X" dentro de la funcion
            nueva.mostrarEnrutadores();
            break;
        case 3:
            nueva.eliminar_Router();

            nueva.mostrarEnrutadores();
            break;
        case 4:
            nueva.eliminar_nodoEn();
            nueva.mostrarEnrutadores();
            break;
        case 5:
            nueva.cambiarPeso();
            break;
        case 6:
            nueva.calcularCaminos3(1);
            break;
        case 7:
            nueva.calcularCaminos3(0);
            break;
        case 8:
            nueva.mostrarEnrutadores();
            break;
        case -1:

            break;
        default:
            break;
        }
    }






    cout << "Hello World!" << endl;
    return 0;
}
