#include "revista.h"
using namespace std;
Revista::Revista(string c, string t, int numEd, int ap, bool esMensual) : Material(c, t, ap, 2.0) {
    this->numeroEdicion = numEd;
    this->esMensual = esMensual;
}
int Revista::getNumeroEdicion(){
    return this->numeroEdicion;
}
void Revista::setNumeroEdicion(int numeroEdicion){
    this->numeroEdicion = numeroEdicion;
}
bool Revista::getMensual(){
    return this->esMensual;
}
void Revista::setMensual(bool esMensual){
    this->esMensual = esMensual;
}

Revista::~Revista(){
    //Vacio porque no tiene punteros
}