#include "red.h"
#include "enrutador.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "auxiliar.h"
using namespace std;
Red::Red()
{

}

void Red::agregarEnrutador()
{
    //Agrega un enrutador totalmente nuevo
    string nombre;
    Enrutador nuevo;

    cout << "Ingresa el nombre del nuevo enrutador: \n==>" << endl;
    cin >> nombre;
    //Verifico que nueva enrutador no exista
    if(VerificarExistencia(nombre)){
        cout << "EL ENRUTADOR " << nombre << " YA EXISTE!!!\n";
        return;
    }


    nuevo.agregarNodo(nombre,0);
    Enrutadores_red.insert(make_pair(nombre,nuevo));
    cout << "\nSe ha creado el nuevo enrutador '" << nombre << "' con exito.\n";

    //preguntar si quiere agregar al enrutador
    agregarNodo_a_Enrutador(nombre);

}

void Red::agregarEnrutador(string name)
{
    Enrutador new_router;
    //new_router.agregarNodo(name,0);
    Enrutadores_red.insert(make_pair(name,new_router));
}

void Red::agregarNodo_a_Enrutador()
{
    string name_origin;
    string name_destin;
    int peso = 0;
    string opc="Y";


    while(opc=="Y"){
        cout << "Ingresa nombre del nodo origen\n==>";
        cin >> name_origin;
        cout << "Ingresa nombre del nodo para conectar con el enrutador " << name_origin << "\n==>";
        cin>> name_destin;
        if((VerificarExistencia(name_origin))&&(VerificarExistencia(name_destin))&&(name_origin!=name_destin)){
            //verificar que exista en la lista de los enrutadores
            //Verifcar que no sea el mismo
            cout << "Ingrese el peso respectivo de "<< name_destin << "\n==>";
            cin >> peso;
            Enrutadores_red[name_origin].agregarNodo(name_destin,peso);
            Enrutadores_red[name_destin].agregarNodo(name_origin,peso);

            cout << "Quieres asignar mas conexiones al enrutador? \n";
            cout << "Si (Escribe Y)\nNo (Escribe N)\n=>";
            cin>>opc;
        }else{
            opc = "Y";
            cout << "Los nombres son iguales o el nodo no existe";
        }


    }
    //posible verificación de peso
    //Enrutadores_red[name_origin].agregarNodo(name_destin,peso);
}

void Red::agregarNodo_a_Enrutador(string name_origin)
{
    //Metodo sobrecargado. Se accede unicamente cuando esta creando un nuevo enrutador
    string name_destin;
    int peso = 0;
    string opc="Y";


    while(opc=="Y"){
        cout << "\nIngresa nombre del nodo para conectar con el enrutador " << name_origin << "\n==>";
        cin>> name_destin;
        if(VerificarExistencia(name_destin)){
            if(name_origin!=name_destin){
                //verificar que exista en la lista de los enrutadores
                //Verifcar que no sea el mismo
                cout << "Ingrese el peso respectivo de "<< name_destin << "\n==>";
                cin >> peso;
                //Conectar en ambos enrutadores
                Enrutadores_red[name_origin].agregarNodo(name_destin,peso);
                Enrutadores_red[name_destin].agregarNodo(name_origin,peso);

                cout << "Quieres asignar mas conexiones al enrutador? \n";
                cout << "Si (Escribe Y)\nNo (Escribe N)\n=>";
                cin>>opc;
            }else {
                cout << "Los nombres son iguales!!!!\n";
                cout << "Deseas intentarlo de nuevo?\n";
                cout << "Si (Escribe Y)\nNo, salir al menu (Escribe N)\n=>";
                cin>>opc;
            }
        }else{
            cout << "El enrutador a conectar no existe!!!!";
            cout << "Deseas intentarlo de nuevo?\n";
            cout << "Si (Escribe Y)\nNo, salir al menu (Escribe N)\n=>";
            cin>>opc;
        }


    }
}

void Red::agregarNodo_a_Enrutador(string name_origin, string name_destin,int peso)
{
    Enrutadores_red[name_origin].agregarNodo(name_destin,peso);
    Enrutadores_red[name_destin].agregarNodo(name_origin,peso);
}

bool Red::VerificarExistencia(string nombre_ingresado)
{
    if (Enrutadores_red.find(nombre_ingresado) == Enrutadores_red.end()) {
        return false;
    }
    return true;
}

void Red::mostrarEnrutadores()
{
    //iterador de multimapa (1)
    //iterador de mapa, luego accedo a los nodos en enrutadores.h
    string name_router;
    cout << "Ingresa el nombre del enrutador al que quieres acceder: \n==>" << endl;
    cin >> name_router;
    map<string,int> copia;
    //Enrutador copia_nodos;
    //copia_nodos = Enrutadores_red[name_router];
    if(VerificarExistencia(name_router)){
        cout << "LOS NODOS DEL ENRUTADOR " << name_router << " SON: " << endl;
        Enrutadores_red[name_router].mostrarNodos();
    }else{
        cout << "El nodo ingresado NO existe!!!\n";
    }


    //cout << "LOS NODOS DEL ENRUTADOR " << name_router << " SON: " << endl;
    //copia_nodos.mostrarNodos();


        //ALGO ESTÁ SUCENDIENDO ACA
    /*map<string,map<string,int>> copia_enrutador;
    copia_enrutador[name_router]=Enrutadores_red[name_router].getNodo();


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
    cout << endl;*/


}

void Red::mostrarEnrutadores(string name_router)
{

    //Enrutador copia_nodos;
    //copia_nodos = Enrutadores_red[name_router];

    if(VerificarExistencia(name_router)){
        cout << "LOS NODOS DEL ENRUTADOR " << name_router << " SON: " << endl;
        Enrutadores_red[name_router].mostrarNodos();
    }else{
        cout << "El nodo ingresado NO existe!!!\n";
    }
}

void Red::eliminar_nodoEn()
{
    string name_router;
    string name_destin;
    //string name_destin;
    cout << "Ingresa el nombre del enrutador de origen al cual quieres eliminarle un nodo" << endl;
    cin >> name_router;
    cout << "Ingrese el nodo a borrar" << endl;
    cin >> name_destin;
    if((!VerificarExistencia(name_router))&&(!VerificarExistencia(name_destin))){
        cout << "\nAlguno de los enrutadores ingresados no existe\n";
        return;
    }

    if(Enrutadores_red[name_router].verificarExistenciaNodo(name_destin)){
        Enrutadores_red[name_router].eliminarNodo(name_destin);
        Enrutadores_red[name_destin].eliminarNodo(name_router);
        cout << "Se ha borrado con exito\n";
    }else cout << "El nodo ingresado no existe.\n";
    /*
    //Eliminar conexion en los demás routers

    //Enrutadores_red.erase(name_router);
    map<string, Enrutador>::iterator itr;
    //recorre cada clave de toda la red
    for(itr = Enrutadores_red.begin(); itr != Enrutadores_red.end(); ++itr) {
        if(!((itr->first)==name_router))//si se va
        Enrutadores_red[itr->first].eliminarNodo(name_router);//accede a un enrutador específico
    }*/

}

void Red::eliminar_Router()
{
    string name_router;
    cout << "Ingresa el nombre del enrutador que quieres eliminar" << endl;
    cin >> name_router;
    if(VerificarExistencia(name_router)){
        Enrutadores_red.erase(name_router);
        map<string, Enrutador>::iterator itr;
        //recorre cada clave de toda la red
        for(itr = Enrutadores_red.begin(); itr != Enrutadores_red.end(); ++itr) {
            Enrutadores_red[itr->first].eliminarNodo(name_router);//accede a un enrutador específico
        }

    }else{
        cout << "\nEl enrutador ingresado no existe\n";
    }
}

void Red::cambiarPeso()
{
    string origen,destino;
    int peso;
    cout << "Ingresa nodo origen"<< endl;
    cin>> origen;
    cout << "Ingresa nodo destino" << endl;
    cin >> destino;

    if(Enrutadores_red[origen].verificarExistenciaNodo(destino)){
        cout << "Ingresa el nuevo peso" << endl;
        cin >> peso;
        Enrutadores_red[origen].cambiarPesoNodo(destino,peso);
        Enrutadores_red[destino].cambiarPesoNodo(origen,peso);
        cout << "Sea ha cambiado con éxito";
    }
}



void Red::calcularCaminos()
{
    //en realidad no necesito nodo destino, ya que conozco todos
    //etiquetas contiene el peso acumulado desde el origen, y el predecesor que forma la ruta más cercana
    map<string, vector<string>> etiquetas; // {'A' : <'0',''>, 'B'  : <'3','B'>,....}
    map<string, int>::iterator itr_nodos;
    int nuevo_peso;
    map<string,int> temp;
    vector<string> visitados;
    vector<string> pendientes;
    string nodo_origen,nodo_actual;
    cout << "\nIngresa nodo origen\n==>";
    cin >> nodo_origen;
    nodo_actual = nodo_origen;
    pendientes.push_back(nodo_origen);
    etiquetas[nodo_actual] = {"0",""}; //INICIALIZO

    while(pendientes.size()>0){
        //cambio el nodo en el que me paro
        calc_nodo_menorw(etiquetas,visitados, nodo_actual); //busca el nodo vecino con el menor peso
        cout << nodo_actual;
        visitados.push_back(nodo_actual);
        temp = Enrutadores_red[nodo_actual].getNodo();//se para sobre el nodo del menor peso
        //voy a iterar en dicho nodo

        for(itr_nodos = temp.begin();itr_nodos !=temp.end();++itr_nodos){
            if(!verificarVector(pendientes,itr_nodos->first) && !verificarVector(visitados,itr_nodos->first)){
                pendientes.push_back(itr_nodos->first);
            }
            nuevo_peso = stoi(etiquetas[nodo_actual][0]) + itr_nodos->second;
            if(!verificarVector(visitados,itr_nodos->first)){
                if(etiquetas.find(itr_nodos->first)==etiquetas.end()){//si no está en etiquetas
                    etiquetas[itr_nodos->first] = {to_string(nuevo_peso),nodo_actual};
                }else{
                    if(stoi(etiquetas[itr_nodos->first][0]) > nuevo_peso){
                        etiquetas[itr_nodos->first] = {to_string(nuevo_peso), nodo_actual};
                    }

                }
            }
        }


        //borrar  nodo actual de pendientes
        eliminarElementoVector(pendientes,nodo_actual);
    }

    map<string, vector<string>>::iterator itr_etiquetas;
    for(itr_etiquetas = etiquetas.begin(); (itr_etiquetas != etiquetas.end()); ++itr_etiquetas){
      cout << itr_etiquetas->first << " => " << (itr_etiquetas->second)[0] << " => " <<(itr_etiquetas->second)[1] << '\n';
    }
}

void Red::calc_nodo_menorw(map<string, vector<string>> etiquetas, vector<string> visitados, string& nodo_actual)
{
    unsigned int menor = 100000; //inicializar con un numero muuy grande
    unsigned int peso_temp;
    string nodo_menor;
    map<string, vector<string>>::iterator itr_e;

    for(itr_e=etiquetas.begin();itr_e!= etiquetas.end();++itr_e){
        peso_temp = stoi((itr_e->second)[0]); //accedo al primer elemento del vector
        if(menor > peso_temp && (!verificarVector(visitados,itr_e->first))){
            menor = peso_temp;
            nodo_menor = itr_e->first;
        }
    }
    nodo_actual = nodo_menor;

}

void Red::calcularCaminos2()
{
    string origen, destino;    
    vector<string> visitar;

    map<string,int> nodos_visitados;  //
    vector<string> temp_vecinos;
    map<string,int> temp;
    map<string,int> distancias;

    map<string, int>::iterator itr_cer;
    map<string, Enrutador>::iterator itr;

    vector<string>::iterator v;

    string padre;
    //recorre cada clave de toda la red
    itr_cer = distancias.begin();
    for(itr = Enrutadores_red.begin(); itr != Enrutadores_red.end(); ++itr) {
        ++itr_cer;
        //falta verificar que tengan conexion con otro nodo
        distancias.insert(make_pair(itr->first,10000000));
        nodos_visitados.insert(make_pair(itr->first,1));
        visitar.push_back(itr->first);//accede a un enrutador específico
    }
    //verificar que se guarde bien :)
    cout << "Ingresa nodo de origen: \n";
    cin >> origen;
    cout << "Ingresa nodo de destino:\n";
    cin >> destino;
    if(VerificarExistencia(origen)&& VerificarExistencia(destino)){


        //extraer vecinos
        //verifico que estén en nodos por visitar
        //realizo la comparación distancias[vecino1]>distancias[vecino1] + peso(org,vecino1)

        distancias[origen] = 0;//el origen vale 0
        //visitar los nodos vecinos en donde estoy parado
        for(itr_cer=Enrutadores_red[origen].getNodo().begin();itr_cer!=Enrutadores_red[origen].getNodo().end();++itr_cer){

        }




        v = visitar.begin();
        while( v != visitar.end()) {
           cout << "value of v = " << *v << endl;
           v++;
        }
        //ingreso a Enrutadores_red[origen]=> Nodos adyacentes
        //Recorro esos nodos y los guardo de manera temporal
        //y hago las comparaciones para cada uno
        //actualizo cercanos
        temp = Enrutadores_red[origen].getNodo();//enlaces nodo inicial
        padre = origen;
        while(!(nodos_visitados.empty())){//mientras queden nodos por visitar
            for(itr_cer = temp.begin();itr_cer != temp.end();++itr_cer){//recorre nodo con sus pesos donde estoy parado
                if(!(itr_cer->first == padre)){//ignorar si es el mismo
                    if(distancias[itr_cer->first]>(distancias[padre] + (itr_cer->second))){
                        //si la distancia calculada es mayor que la distancia al nodo anterior más el peso del enlace
                        distancias[itr_cer->first]=(distancias[padre] + (itr_cer->second));
                    }
                }
            }
            //una vez que finalice el recorrido por sus vecinos...borrar de visitar
            nodos_visitados.erase(padre);

        }



    }else{
        cout << "No existen\n";
    }
}

void Red::calcularCaminos3(int op)
{
    string recorrido;
    string nodo_inicio;
    string nodo_destino;
    string nodo_actual;
    map<string,int> distances;
    map<string,int>::iterator itr_d;
    vector<string> por_visitar;
    vector<string>::iterator itr_visit;
    map<string, vector<string>> etiqueta;
    map<int, string>::iterator itr_etq;
    map<string,int> temp;
    map<string, int>::iterator itr_temp;

    vector<string> pendientes;
    vector<string>::iterator itr_p;
    map<string, vector<string>>::iterator itr_e;

    int nuevo_peso_posible;
    cout << "\nIngresa nodo de origen: \n";
    cin >> nodo_inicio;
    cout << "\nIngresa nodo de destino:\n";
    cin >> nodo_destino;

    if(!(VerificarExistencia(nodo_inicio)&&VerificarExistencia(nodo_destino))){
        cout << "\nAlguno de los nodos ingresados no existe!\n";
        return;
    }
    nodo_actual = nodo_inicio;
    itr_d = distances.begin();
    for(itr_red = Enrutadores_red.begin(); itr_red != Enrutadores_red.end(); ++itr_red) {
        distances.insert(make_pair(itr_red->first,1000000));
        por_visitar.push_back(itr_red->first);
    }
    distances[nodo_actual] = 0;
    //distances[nodo_inicio] = 0;
    etiqueta[nodo_inicio] = {"0",""};
    temp = Enrutadores_red[nodo_inicio].getNodo();
    //"Inicializa" peso de los vecinos
    for(itr_temp = temp.begin();itr_temp != temp.end(); ++itr_temp){
        etiqueta[itr_temp->first] = {to_string(itr_temp->second),nodo_actual};
    }
    eliminarElementoVector(por_visitar,nodo_actual);
    while(por_visitar.size() >0){


        //calcular el más cercano.
        calc_nearest(etiqueta,por_visitar,nodo_actual);//calcula el más cercano
        cout << nodo_actual;
        temp = Enrutadores_red[nodo_actual].getNodo();
        for(itr_temp = temp.begin();itr_temp != temp.end(); ++itr_temp){
            //itera todos los nodos
            //peso hasta nodo actual + peso entre nodo actual y su vecino
            nuevo_peso_posible = stoi(etiqueta[nodo_actual][0]) + itr_temp->second;
            if(verificarVector(por_visitar,itr_temp->first)){
                if(!(etiqueta.find(itr_temp->first)==etiqueta.end())){
                    if(stoi(etiqueta[itr_temp->first][0])>nuevo_peso_posible)
                        //actualizo con el valor de peso acumulado y el nodo anterior más cercano (el actual)
                        etiqueta[itr_temp->first] = {to_string(nuevo_peso_posible),nodo_actual};
                }else{
                        etiqueta[itr_temp->first] = {to_string(nuevo_peso_posible), nodo_actual};
                    }

                }
            }
        eliminarElementoVector(por_visitar,nodo_actual);
    }
    if(op==1){
        cout << "Recorrer de " << nodo_inicio << " hasta " << nodo_destino << " cuesta: " << etiqueta[nodo_destino][0];
    }else{
        cout << "Nodos a recorrer:\n";
        recorrido = etiqueta[nodo_destino][1];
        cout << recorrido;
        while(recorrido != nodo_inicio){
            recorrido = etiqueta[recorrido][1];
            cout << "==>"<< recorrido;
        }
        cout << endl;
    }
    map<string, vector<string>>::iterator itr_etiquetas;
    for(itr_etiquetas = etiqueta.begin(); (itr_etiquetas != etiqueta.end()); ++itr_etiquetas){
      cout << itr_etiquetas->first << " => " << (itr_etiquetas->second)[0] << " => " <<(itr_etiquetas->second)[1] << '\n';

    }
}

void Red::calc_nearest(map<string, vector<string>> etiquetas,vector<string> por_visitar, string& actual)
{
    //busca en las etiquetas (distancias actuales) cual es la más cercana
    unsigned int menor = 1000000; //inicializar con un numero muuy grande
    unsigned int peso_temp;
    string nodo_menor;
    map<string, vector<string>>::iterator itr_e;

    for(itr_e=etiquetas.begin();itr_e!= etiquetas.end();++itr_e){
        peso_temp = stoi((itr_e->second)[0]); //accedo al primer elemento del vector
        if(peso_temp < menor && (verificarVector(por_visitar,itr_e->first))){
            menor = peso_temp;
            nodo_menor = itr_e->first;
        }
    }
    actual = nodo_menor;

}

Red::~Red()
{

}
