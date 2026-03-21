#ifndef DTLIBRO_H
#define DTLIBRO_H
#include "dtmaterial.h"
class DtLibro : public DtMaterial{
    private:
        std::string autor;
        int cantPaginas;
    public :
        DtLibro(std::string codigo, std::string titulo, std::string autor, int anioPublicacion, int cantPaginas);
        std::string getAutor();
        int getCantPaginas();
        ~DtLibro();
};
#endif