#include "dtfecha.h"
#include <iostream>
using namespace std;


DtFecha::DtFecha(int dia, int mes, int anio){
    this->anio = (anio > 0) ? anio : 2000;
    this->mes = (mes >= 1 && mes <= 12) ? mes : 1;
    int diasPorMes[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    this->dia = (dia >= 1 && dia <= diasPorMes[this->mes - 1]) ? dia : 1;
}
int DtFecha::getDia(){
    return this->dia;
}
int DtFecha::getMes(){
    return this->mes;
}
int DtFecha::getAnio(){
    return this->anio;
}
void DtFecha::printFecha(){
    cout << this->dia << "/" << this->mes << "/" << this->anio;
}
DtFecha::~DtFecha(){
    //No hay codigo porque no genera punteros.
}