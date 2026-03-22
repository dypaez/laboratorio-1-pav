#include "prestamo.h"
Prestamo::Prestamo(int dia, int mes, int anio, int dias, Material* mat){
	this->fechaPrestamo = DtFecha(dia, mes, anio);
}
DtFecha Prestamo::getFecha(){
	return this->fechaPrestamo;
}
int Prestamo::getDiasPermitidos(){
	return this->diasPermitidos;
}
Prestamo::~Prestamo(){
}
