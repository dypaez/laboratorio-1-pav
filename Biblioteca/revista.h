#ifndef REVISTA_H
#define REVISTA_H
#include "material.h"
#include "dtrevista.h"
class Revista : public Material{
    private:
        int numeroEdicion;
        bool esMensual;
    public:
        Revista(DtRevista dtr);
        int getNumeroEdicion();
        bool getMensual();
        void setNumeroEdicion(int);
        void setMensual(bool);
        float calcularMulta(int diasAtraso) override;
        ~Revista();
};
#endif