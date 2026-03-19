#ifndef LECTOR_H
#define LECTOR_H
#include <string>
#include "dtfecha.h"
class Lector {
    private:
        std::string ci;
        std::string nombre;
        DtFecha fechaRegistro;
    public:
        Lector(std::string ci, std::string nombre, int dia, int mes, int anio);
        std::string getCi();
        std::string getNombre();
        DtFecha getFechaRegistro();
        void setCi(std::string);
        void setNombre(std::string);
        void setFechaRegistro(DtFecha);
        ~Lector();
};

#endif