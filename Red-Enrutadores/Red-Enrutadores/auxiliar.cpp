#include <iostream>
#include "auxiliar.h"
#include <string>
#include <vector>
#include <algorithm>
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

void LeerRed()
{

}
