#ifndef DTMATERIAL_H
#define DTMATERIAL_H
#include <iostream>
using namespace std;

class DtMaterial{
	private:
		std::string codigo;
		std::string titulo;
		int anioPublicacion;
		float multaBase;
	public:
		//Constructor
		DtMaterial(std::string codigo, std::string titulo, int anioPublicacion, float multaBase);
		//Operaciones
		std::string getCodigo();
		std::string getTitulo();
		int getAnioPublicacion();
		float getMultaBase();
		void imprimirDatos();
		//Destructor
		~DtMaterial();
};

#endif