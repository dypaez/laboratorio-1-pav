#include "libro.h"
using namespace std;
Libro::Libro(string c, string t, string a, int ap, int cantP) : Material(c, t, ap, 5.0) {
    this->autor = a;
    this->cantPaginas = cantP;
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
Libro::~Libro(){
    //Vacio porque no hay punteros.
}