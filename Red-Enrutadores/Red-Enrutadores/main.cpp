#include <iostream>
#include "enrutador.h"
#include "red.h"
#include <map>
#include <string>
using namespace std;

int main()
{
    Red nueva;

    nueva.agregarEnrutador("X");
    nueva.mostrarEnrutadores("X");

    nueva.agregarNodo_a_Enrutador("X");//puedo dejar "X" dentro de la funcion
    nueva.mostrarEnrutadores("X");

    nueva.eliminar_nodoEn();
    nueva.mostrarEnrutadores("X");

    cout << "Hello World!" << endl;
    return 0;
}
