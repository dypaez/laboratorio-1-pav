#ifndef DTREVISTA_H
#define DTREVISTA_H
#include "dtmaterial.h"

class DtRevista : public DtMaterial{
    private:
        int numeroEdicion;
        bool esMensual;
    public:
        DtRevista(string codigo, string titulo, int numeroEdicion, int anioPublicacion, float multaBase, bool esMensual);
        int getNumeroEdicion();
        bool getMensual();
        ~DtRevista();
};

#endif