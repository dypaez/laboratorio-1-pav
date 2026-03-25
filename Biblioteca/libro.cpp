#include "libro.h"
#include "constantes.h"
using namespace std;
Libro::Libro(DtLibro dtl) : Material(dtl.getCodigo(), dtl.getTitulo(), dtl.getAnioPublicacion()) {
    this->autor = dtl.getAutor();
    this->cantPaginas = dtl.getCantPaginas();
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
float calcularMulta(int diasAtraso){
    return (diasAtraso * MULTA_BASE_LIBRO);
}
Libro::~Libro(){
    //Vacio porque no hay punteros.
}