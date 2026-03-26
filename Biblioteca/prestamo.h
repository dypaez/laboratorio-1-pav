#ifndef PRESTAMO_H
#define PRESTAMO_H

#include "dtfecha.h"
#include "material.h"
class Prestamo{
	private:
		DtFecha* fechaPrestamo;
		int diasPermitidos;
		Material* material;
	public:
		Prestamo(DtFecha* fechaPrestamo, Material* mat, int diasPermitidos);
		DtFecha* getFecha();
		int getDiasPermitidos();
		Material* getMaterial();
		~Prestamo();
};

#endif
