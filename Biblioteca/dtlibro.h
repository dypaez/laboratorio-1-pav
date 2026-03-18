#ifndef DTLIBRO_H
#define DTLIBRO_H
#include "dtmaterial.h"

class DtLibro : public DtMaterial{
    private:
        string autor;
        int cantPaginas;
    public :
        DtLibro(string codigo, string titulo, string autor, int anioPublicacion, float multaBase, int cantPaginas);
        string getAutor();
        int getCantPaginas();
        void imprimirDatosLibro();
        ~DtLibro();
};

#endif