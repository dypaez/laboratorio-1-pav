#include "lector.h"
#include <iostream>
#include <stdexcept>
using namespace std;
/*
ARREGLOS
*/
    Lector* lectores[MAX_LECTORES];
    Material* materiales[MAX_MATERIALES];
    
/*
    ARREGLOS
*/

int main(){
    //INICIALIZACION DE ARREGLOS
    for(int i=0; i<MAX_MATERIALES; i++){
        materiales[i] = nullptr;
    }
    for(int i=0; i<MAX_LECTORES; i++){
        lectores[i] = nullptr;
    }
    int opcion=-1;
    while(opcion!=0){
        mostrarMenu();
        cin >> "Opcion: " >> opcion;
        switch(opcion){
            case 0:
            break;
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            default:
            break;
        }
    }
    return 0;
}
void registrarLector(string ci, string nombre, DtFecha* fechaRegistro){
    if(ci != "" && nombre != "" && fechaRegistro){
        for(int i=0;i<MAX_LECTORES;i++){
            if(lectores[i]==nullptr){
                lectores[i] = new Lector(ci, nombre, fechaRegistro);
                cout << "Lector ingresado con éxito." << endl;
                return;
            }
        }
        cout << "ERROR: No hay espacio en la lista de lectores." << endl;
    }
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha * fechaPrestamo, int diasPermitidos){
    for(int i=0; i<MAX_LECTORES; i++){
        if(lectores[i]!=nullptr){
            if(lectores[i]->getCi() == ci){
                if(!lectores[i]->prestamoLleno()){
                    for(int j; j<MAX_MATERIALES; j++){
                        if(materiales[j]->getCodigo() == codigoMaterial){
                            Material* material = materiales[j];
                            Prestamo* prestamo = new Prestamo(fechaPrestamo, material, diasPermitidos);
                            lectores[i]->agregarPrestamo(prestamo);
                            cout << "Prestamo registrado con éxito." << endl;
                            return;
                        }
                    }
                    cout << "El material especificado no existe." << endl;
                    return;
                }
            }
            cout << "La cédula especificada no está registrada." << endl;
            return;
        }
    }
}
DtMaterial** obtenerMaterialesPrestados(string ci, int&cantMateriales){
    try{

    }catch(invalid_argument){

    }
}
float consultarMultaMaterial(string ci, string codigoMaterial){

}
DtMaterial** verPrestamosAntesDeFecha(string ci, DtFecha* fecha, int& cantPrestamos){

}
void agregarMaterial(DtMaterial * dtMaterial){
    
};


void mostrarMenu(){
    cout << "Bienvenido!\nElija la opción:" << endl <<
            "1) Registrar lector" << endl <<
            "2) Agregar préstamo" << endl <<
            "3) Obtener materiales prestados" << endl <<
            "4) Consultar multa de material" << endl <<
            "5) Ver préstamos antes de fecha" << endl <<
            "6) Agregar material" << endl <<
            "0) Salir" << endl;
}