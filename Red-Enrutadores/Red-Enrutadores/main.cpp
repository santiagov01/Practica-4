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

    while(st !=-1){
        cout << "Ingresa opcion: \n";
        cout << "1.Crear nuevo enrutador.\n2.Crear nueva conexion a Enrutador\n3.Eliminar enrutador.\n";
        cout << "4.Eliminar nodo de enrutador\n5.Cambiar peso de un enlace\n6.Calcular peso camino mas cercano\n7.Mostrar camino mas cercano con nodos\n.";
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

            break;
        case 7:

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
