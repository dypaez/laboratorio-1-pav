#include "libro.h"
#include "constantes.h"
using namespace std;
Libro::Libro(DtLibro* dtl) : Material(dtl->getCodigo(), dtl->getTitulo(), dtl->getAnioPublicacion()) {
    this->autor = dtl->getAutor();
    this->cantPaginas = dtl->getCantPaginas();
}
string Libro::getAutor(){
    return this->autor;
}
void Libro::setAutor(string autor){
    this->autor = autor; 
}
int Libro::getCantPaginas(){
    return this->cantPaginas;
}
void Libro::setCantPaginas(int cantPaginas){
    this->cantPaginas = cantPaginas;
}
float Libro::calcularMulta(int diasAtraso){
    return (diasAtraso * MULTA_BASE_LIBRO);
}
DtMaterial* Libro::getDtMaterial(){
    return new DtLibro(
        this->getCodigo(),
        this->getTitulo(),
        this->getAutor(),
        this->getAnioPublicacion(),
        this->getCantPaginas()
    );
}

Libro::~Libro(){
    //Vacio porque no hay punteros.
}