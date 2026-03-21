#ifndef LIBRO_H
#define LIBRO_H
#include "material.h"
#include "dtlibro.h"
class Libro : public Material{
    private:
        std::string autor;
        int cantPaginas;
    public :
        Libro(DtLibro dtl);
        std::string getAutor();
        int getCantPaginas();
        void setAutor(std::string);
        void setCantPaginas(int);
        ~Libro();
};
#endif