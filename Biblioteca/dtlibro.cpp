<<<<<<< Updated upstream
#include "dtlibro.h"
using namespace std;
DtLibro::DtLibro(string c, string t, string a, int ap, int cantP) : DtMaterial(c, t, ap, 5.0) {
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
=======
#include "dtlibro.h"
#include "constantes.h"
#include <iostream>
using namespace std;
DtLibro::DtLibro(string c, string t, string a, int ap, int cantP) : DtMaterial(c, t, ap, MULTA_BASE_LIBRO) {
    this->autor = a;
    this->cantPaginas = cantP;
}
string DtLibro::getAutor(){
    return this->autor;
}
int DtLibro::getCantPaginas(){
    return this->cantPaginas;
}
void DtLibro::mostrarDatos(){
    DtMaterial::mostrarDatos();
    cout << "Autor: " << this->autor << endl <<
            "Cantidad de páginas: " << this->cantPaginas << endl;
}
DtLibro::~DtLibro(){
    //Vacio porque no hay punteros.
>>>>>>> Stashed changes
}