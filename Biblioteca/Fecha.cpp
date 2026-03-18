#include "Fecha.h";
#include <iostream>;
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
