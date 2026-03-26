#include "dtrevista.h"
#include "constantes.h"
#include <iostream>
using namespace std;
DtRevista::DtRevista(string c, string t, int numEd, int ap, bool esMensual) : DtMaterial(c, t, ap, MULTA_BASE_REVISTA) {
    this->numeroEdicion = numEd;
    this->esMensual = esMensual;
}
int DtRevista::getNumeroEdicion(){
    return this->numeroEdicion;
}
bool DtRevista::getMensual(){
    return this->esMensual;
}
void DtRevista::mostrarDatos(){
    DtMaterial::mostrarDatos();
    cout << "Numero de edición: " << this->numeroEdicion << endl <<
            "Es mensual: " << (this->esMensual ? "Sí" : "No") << endl;

}
DtRevista::~DtRevista(){
    //Vacio porque no tiene punteros
}