#include "dtlibro.h"

DtLibro::DtLibro(string c, string t, string a, int ap, float mb, int cantP) : DtMaterial(c, t, ap, mb) {
    this->autor = a;
    this->cantPaginas = cantP;
}
string DtLibro::getAutor(){
    return this->autor;
}
int DtLibro::getCantPaginas(){
    return this->cantPaginas;
}
DtLibro::~DtLibro(){
    //Vacio porque no hay punteros.
}