#include "material.h"
using namespace std;

Material::Material(std::string codigo, std::string titulo, int anioPublicacion, float multaBase){
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
    this->multaBase = multaBase;
}
string Material::getCodigo(){
    return this->codigo;
}
string Material::getTitulo(){
    return this->titulo;
}
int Material::getAnioPublicacion(){
    return this->anioPublicacion;
}
float Material::calcularMulta(int diasAtraso){
    return (this->multaBase * diasAtraso);
}
void Material::setCodigo(string codigo) {
    this->codigo = codigo;
}

void Material::setTitulo(string titulo) {
    this->titulo = titulo;
}

void Material::setAnioPublicacion(int anioPublicacion) {
    this->anioPublicacion = anioPublicacion;
}

Material::~Material(){

}