#include "lector.h"
using namespace std;
Lector::Lector(string ci, string nombre, DtFecha* fechaRegistro){
    this->fechaRegistro = fechaRegistro;
    this->ci = ci;
    this->nombre = nombre;
    this->cantidadPrestados=0;
    for(int i = 0; i<MAX_PRESTAMOS; i++){
        this->prestamos[i] = nullptr;
    }
}

string Lector::getCi() {
    return ci;
}

string Lector::getNombre() {
    return nombre;
}

DtFecha* Lector::getFechaRegistro() {
    return this->fechaRegistro;
}
int Lector::getCantidadPrestados(){
    return this->cantidadPrestados;
}
Prestamo* Lector::getPrestamo(int i){
    if(i>=0 && i<MAX_PRESTAMOS){
        return prestamos[i];
    }else{
        return nullptr;
    }
}
bool Lector::prestamoLleno(){
    for (int i=0; i<10; i++){
        if(this->prestamos[i]==nullptr){
            return false;
        }
    }
    return true;
}
bool Lector::agregarPrestamo(Prestamo* p) {
    for(int i=0; i<MAX_PRESTAMOS; i++){
        if(prestamos[i] == nullptr){
            prestamos[i] = p;
            cantidadPrestados++;
            return true; //Éxito
        }
    }
    return false; //Error
}
Material* Lector::buscarMaterialPrestado(string codigoMaterial){
    Prestamo* p = nullptr;
    for(int i=0; i<getCantidadPrestados(); i++){
        p = prestamos[i];
        if(p && p->getMaterial()->getCodigo()==codigoMaterial){
            return p->getMaterial();
        }
    }
    return nullptr;
}
void Lector::setCi(string ci) {
    this->ci = ci;
}

void Lector::setNombre(string nombre) {
    this->nombre = nombre;
}

void Lector::setFechaRegistro(DtFecha* fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}



Lector::~Lector() {
    delete fechaRegistro;
    for(int i=0;i<MAX_PRESTAMOS;i++){
        delete prestamos[i];
    }
}
