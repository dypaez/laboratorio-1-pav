#ifndef DTMATERIAL_H
#define DTMATERIAL_H
#include <iostream>
#include <string>
using namespace std;

class DtMaterial{
	private:
		string codigo;
		string titulo;
		int anioPublicacion;
		float multaBase;
	public:
		//Constructor
		DtMaterial(string codigo, string titulo, int anioPublicacion, float multaBase);
		//Operaciones
		string getCodigo();
		string getTitulo();
		int getAnioPublicacion();
		float getMultaBase();
		//Destructor
		~DtMaterial();
};

#endif