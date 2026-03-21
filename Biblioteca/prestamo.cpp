#include "prestamo.h"
Prestamo(int dia, int mes, int anio, int dias, Material* mat){
	this->fechaPrestamo = DtFecha(dia, mes, anio);
}
DtFecha getFecha(){
	return this->fechaPrestamo;
}
int getDiasPermitidos(){
	return this->diasPermitidos;
}
~Prestamo(){
}
