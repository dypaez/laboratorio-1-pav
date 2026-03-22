#ifndef LECTOR_H
#define LECTOR_H

#include <string>
#include "constantes.h"
#include "dtfecha.h"
#include "prestamo.h"

class Lector {
    private:
        std::string ci;
        std::string nombre;
        DtFecha fechaRegistro;
        Prestamo* prestamos[MAX_PRESTAMOS];
    public:
        Lector();
        Lector(std::string ci, std::string nombre, int dia, int mes, int anio);
        std::string getCi();
        std::string getNombre();
        DtFecha getFechaRegistro();
        bool prestamoLleno();
        bool agregarPrestamo(Prestamo* p);
        void setCi(std::string);
        void setNombre(std::string);
        void setFechaRegistro(DtFecha);
        

     ~Lector();
};

#endif