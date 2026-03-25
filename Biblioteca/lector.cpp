using namespace std;
#include "lector.h"
using namespace std;
Lector::Lector(string ci, string nombre, DtFecha* fechaRegistro){
    this->fechaRegistro = fechaRegistro;
    this->ci = ci;
    this->nombre = nombre;
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
            return true; //Éxito
        }
    }
    return false; //Error
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
}
