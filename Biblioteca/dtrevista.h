#ifndef DTREVISTA_H
#define DTREVISTA_H
#include "dtmaterial.h"

class DtRevista : public DtMaterial{
    private:
        int numeroEdicion;
        bool esMensual;
    public:
        DtRevista(std::string codigo, std::string titulo, int numeroEdicion, int anioPublicacion, float multaBase, bool esMensual);
        int getNumeroEdicion();
        bool getMensual();
        void imprimirDatosRevista();
        ~DtRevista();
};

#endif