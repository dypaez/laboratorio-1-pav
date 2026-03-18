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
void DtRevista::imprimirDatosRevista(){
    DtMaterial::imprimirDatos();
    cout << "Número de edición: " << this->numeroEdicion << endl
         << "Es mensual: " << (this->esMensual ? "Sí" : "No") << endl;
}
DtRevista::~DtRevista(){
    //Vacio porque no tiene punteros
}