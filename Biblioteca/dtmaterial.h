<<<<<<< Updated upstream
#ifndef DTMATERIAL_H
#define DTMATERIAL_H
#include <string>
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
		//Destructor
		~DtMaterial();
};

=======
#ifndef DTMATERIAL_H
#define DTMATERIAL_H
#include <string>
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
		virtual void mostrarDatos();
		//Destructor
		~DtMaterial();
};

>>>>>>> Stashed changes
#endif