#include "revista.h"
#include "constantes.h"
using namespace std;
Revista::Revista(DtRevista* dtr) : Material(dtr->getCodigo(), dtr->getTitulo(), dtr->getAnioPublicacion()) {
    this->numeroEdicion = dtr->getNumeroEdicion();
    this->esMensual = dtr->getMensual();
}
int Revista::getNumeroEdicion(){
    return numeroEdicion;
}
void Revista::setNumeroEdicion(int numeroEdicion){
    this->numeroEdicion = numeroEdicion;
}
bool Revista::getMensual(){
    return esMensual;
}
void Revista::setMensual(bool esMensual){
    this->esMensual = esMensual;
}
float Revista::calcularMulta(int diasAtraso){
    return (diasAtraso * MULTA_BASE_REVISTA);
}
DtMaterial* Revista::getDtMaterial(){
    return new DtRevista(
        this->getCodigo(),
        this->getTitulo(),
        this->getNumeroEdicion(),
        this->getAnioPublicacion(),
        this->getMensual()
    );
}
Revista::~Revista(){
    //Vacio porque no tiene punteros
}