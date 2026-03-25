#include "prestamo.h"
Prestamo::Prestamo(DtFecha* fechaPrestamo, Material* mat, int diasPermitidos){
	this->fechaPrestamo = fechaPrestamo;
	this->diasPermitidos = diasPermitidos;
	this->material = mat;
}
DtFecha* Prestamo::getFecha(){
	return this->fechaPrestamo;
}
int Prestamo::getDiasPermitidos(){
	return this->diasPermitidos;
}
Material* Prestamo::getMaterial(){
	return this->material;
}
Prestamo::~Prestamo(){
}
