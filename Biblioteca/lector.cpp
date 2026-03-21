using namespace std;
#include "lector.h"
using namespace std;
Lector::Lector(){
    this->fechaRegistro = DtFecha(0,0,0);
    this->ci = "";
    this->nombre = "";
    for(int i = 0; i<10; i++){
        this->prestamos[i] = nullptr;
    }
}
Lector::Lector(string ci, string nombre, int dia, int mes, int anio){
    this->fechaRegistro = DtFecha(dia, mes, anio);
    this->ci = ci;
    this->nombre = nombre;
    for(int i = 0; i<MAX_PRESTAMOS; i++){
        this->prestamos[i] = nullptr;
    }
}

string Lector::getCi() {
    return this->ci;
}

string Lector::getNombre() {
    return this->nombre;
}

DtFecha Lector::getFechaRegistro() {
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
    if(!prestamoLleno()){
        for(int i=0; i<MAX_PRESTAMOS; i++){
            if(prestamos[i] == nullptr){
                prestamos[i] = p;
                return true; //Éxito
            }
        }
    }else{
        return false; //ERROR
    }
}
void Lector::setCi(string ci) {
    this->ci = ci;
}

void Lector::setNombre(string nombre) {
    this->nombre = nombre;
}

void Lector::setFechaRegistro(DtFecha fechaRegistro) {
    this->fechaRegistro = fechaRegistro;
}



Lector::~Lector() {
}
