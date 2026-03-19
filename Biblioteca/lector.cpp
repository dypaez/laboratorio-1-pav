#include "lector.h"
#include "dtfecha.h"
using namespace std;

Lector::Lector(string ci, string nombre, int dia, int mes, int anio){
    this->ci = ci;
    this->nombre = nombre;
    this->fechaRegistro = DtFecha(dia,mes,anio);
}

string Lector::getCi() {
    return ci;
}

string Lector::getNombre() {
    return nombre;
}

DtFecha Lector::getFechaRegistro() {
    return fechaRegistro;
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
