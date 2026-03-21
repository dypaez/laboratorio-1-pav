#ifndef REVISTA_H
#define REVISTA_H
#include "material.h"
class Revista : public Material{
    private:
        int numeroEdicion;
        bool esMensual;
    public:
        Revista(std::string codigo, std::string titulo, int numeroEdicion, int anioPublicacion, bool esMensual);
        int getNumeroEdicion();
        bool getMensual();
        void setNumeroEdicion(int);
        void setEsMensual(bool);
        ~Revista();
};
#endif