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
		float multaBase;
	public:
		Material(std::string codigo, std::string titulo, int anioPublicacion, float multaBase);
		std::string getCodigo();
		std::string getTitulo();
		int getAnioPublicacion();
		float calcularMulta(int diasAtraso);
		void setCodigo(std::string);
        void setTitulo(std::string);
        void setAnioPublicacion(int);
		
	
		~Material();
};

#endif