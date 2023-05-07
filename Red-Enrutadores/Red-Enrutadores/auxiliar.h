#ifndef AUXILIAR_H
#define AUXILIAR_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <red.h>
using namespace std;
bool verificarVector(vector<string> vector, string compare);
void eliminarElementoVector(vector<string> &vec, string elemento);
void LeerRed(string name_file, Red *red_archivo);
int saltos(string name_file);
void menu(Red *nuevared);
#endif // AUXILIAR_H
