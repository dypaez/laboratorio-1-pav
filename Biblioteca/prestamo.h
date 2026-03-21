#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "dtfecha.h"
#include "material.h"
class Prestamo{
	private:
		DtFecha fechaPrestamo;
		int diasPermitidos;
		Material* material;
	public:
		Prestamo(int dia, int mes, int anio, int dias, Material* mat);
		DtFecha getFecha();
		int getDiasPermitidos();
		~Prestamo();
};

#endif
