#include <iostream>
#include <auxiliar.h>
#include "enrutador.h"
#include "red.h"
#include <map>
#include <string>
using namespace std;

int main()
{
    Red nueva;
    Red archivo;
    short int st=0;
    unsigned short int tipo = 0;

    cout << "Elige el tipo de red que quieres manipular\n1.Totalmente nueva\n2.A partir de un archivo";
    cin >> tipo;
    if(tipo == 2){
        string name = "data.txt";
        LeerRed(name,&archivo);
        menu(&archivo);
    }else{
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
        menu(&nueva);
    }
    return 0;

}
