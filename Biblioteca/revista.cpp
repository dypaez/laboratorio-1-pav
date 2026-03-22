#include "revista.h"

using namespace std;
Revista::Revista(DtRevista dtr) : Material(dtr.getCodigo(), dtr.getTitulo(), dtr.getAnioPublicacion(), dtr.getMultaBase()) {
    this->numeroEdicion = dtr.getNumeroEdicion();
    this->esMensual = dtr.getMensual();
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