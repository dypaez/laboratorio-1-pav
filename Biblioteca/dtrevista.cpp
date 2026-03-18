#include "dtrevista.h"

DtRevista::DtRevista(string c, string t, int numEd, int ap, float mb, bool esMensual) : DtMaterial(c, t, ap, mb) {
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