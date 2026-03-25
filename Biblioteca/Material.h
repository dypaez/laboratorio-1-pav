#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>
#include <iostream>
#include "dtmaterial.h"
class Material{
	private:
		std::string codigo;
		std::string titulo;
		int anioPublicacion;
	public:
		Material(std::string codigo, std::string titulo, int anioPublicacion);
		std::string getCodigo();
		std::string getTitulo();
		int getAnioPublicacion();
		void setCodigo(std::string);
        void setTitulo(std::string);
        void setAnioPublicacion(int);
		virtual float calcularMulta(int diasAtraso) = 0;
		~Material();
};

#endif