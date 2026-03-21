#ifndef LECTOR_H
#define LECTOR_H

#include <iostream>
#include <string>
using namespace std;
#include "dtfecha.h"
#include "prestamo.h"

class Lector {
    private:
        string ci;
        string nombre;
        DtFecha fechaRegistro;
        Prestamo* prestamos[10];
    public:
        Lector();
        Lector(string ci, string nombre, int dia, int mes, int anio);
        string getCi();
        string getNombre();
        DtFecha getFechaRegistro();
        bool prestamoLleno();
        bool agregarPrestamo(Prestamo* p);
        void setCi(string);
        void setNombre(string);
        void setFechaRegistro(DtFecha);
        

     ~Lector();
};

#endif