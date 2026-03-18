#include "dtmaterial.h"


DtMaterial::DtMaterial(string codigo, string titulo, int anioPublicacion, float multaBase){
    this->codigo = codigo;
    this->titulo = titulo;
    this->anioPublicacion = anioPublicacion;
    this->multaBase = multaBase;
}

string DtMaterial::getCodigo(){
    return this->codigo;
}
string DtMaterial::getTitulo(){
    return this->titulo;
}
int DtMaterial::getAnioPublicacion(){
    return this->anioPublicacion;
}
float DtMaterial::getMultaBase(){
    return this->multaBase;
}
void DtMaterial::imprimirDatos(){
    cout << "Codigo: " << this->codigo << endl
         << "Titulo: " << this->titulo << endl
         << "Año de publicación: " << this->anioPublicacion << endl;
}
DtMaterial::~DtMaterial(){
    //Vacío porque no se crea punteros
}