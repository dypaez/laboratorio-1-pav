#include "dtrevista.h"
using namespace std;
DtRevista::DtRevista(string c, string t, int numEd, int ap, bool esMensual) : DtMaterial(c, t, ap, 2.0) {
    this->numeroEdicion = numEd;
    this->esMensual = esMensual;
}
int DtRevista::getNumeroEdicion(){
    return this->numeroEdicion;
}
bool DtRevista::getMensual(){
    return this->esMensual;
}

DtRevista::~DtRevista(){
    //Vacio porque no tiene punteros
}