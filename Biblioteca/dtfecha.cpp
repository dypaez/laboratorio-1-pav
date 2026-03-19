#include "dtfecha.h"
#include <iostream>
using namespace std;


DtFecha::DtFecha(int dia, int mes, int anio){
    if(dia <= 31){
        this->dia = dia;
    }
    if(mes <= 12){
        this->mes = mes;
    }
    if(anio <= 2026){
        this->anio = anio;
    }
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
