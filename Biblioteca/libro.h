#ifndef LIBRO_H
#define LIBRO_H
#include "material.h"
class Libro : public Material{
    private:
        std::string autor;
        int cantPaginas;
    public :
        Libro(std::string codigo, std::string titulo, std::string autor, int anioPublicacion, int cantPaginas);
        std::string getAutor();
        int getCantPaginas();
        void setAutor(std::string);
        void setCantPaginas(int);
        ~Libro();
};
#endif