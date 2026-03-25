#include "lector.h"
#include "libro.h"
#include "revista.h"
#include "dtfecha.h"
#include <iostream>
#include <stdexcept>
#include <locale>
#include <cctype>
#include <sstream>
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
        setlocale(LC_ALL, "");
        mostrarMenu();
        cout << "Opción: ";
        cin >> opcion;
        switch(opcion){
            case 0:
            break;
            case 1:{
                string ci = "", nombre = "", fecha = "";
                string diaStr, mesStr, anioStr;
                DtFecha* fechaRegistro = nullptr;
                cout << "Ingrese la cédula de el/la lector/a";
                cin >> ci;
                cout << "\nIngrese el nombre de el/la lector/a";
                cin >> nombre;
                cout << "\nIngrese la fecha de registro (Formato DD/MM/YYYY):";
                cin >> fecha;
                stringstream ss(fecha);
                getline(ss, diaStr, '/');
                getline(ss, mesStr, '/');
                getline(ss, anioStr, '/');
                int dia = stoi(diaStr);
                int mes = stoi(mesStr);
                int anio = stoi(anioStr);
                fechaRegistro = new DtFecha(dia, mes, anio);
                registrarLector(ci, nombre, fechaRegistro);
                delete fechaRegistro;
            break;}
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:{
                DtMaterial* mat = nullptr;
                int opc_material = 0;
                while((opc_material < 1) || (opc_material>2)){
                    cout << "¿Qué tipo de Material desea ingresar?" << endl <<
                            "1) Libro" << endl <<
                            "2) Revista" << endl <<
                            "\t> ";
                    cin >> opc_material;
                    if(opc_material < 1 || opc_material > 2){
                        cout << "Opción inválida. Vuelta a intentarlo." << endl;
                    }
                }
                string codigo, titulo;
                int anio;
                cout << "Ingrese el código del material: ";
                cin >> codigo;
                cout << "\nIngrese el título del material:";
                cin >> titulo;
                cout << "\nIngrese el año de publicación del material:";
                cin >> anio;
                switch(opc_material){
                        case 1:
                        {
                            string autor;
                            int cantPag;
                            cout << "\n¿Quién es el autor del libro?: ";
                            cin >> autor;
                            cout << "\n¿Cuántas páginas tiene el libro?";
                            cin >> cantPag;
                            mat = new DtLibro(codigo, titulo, autor, anio, cantPag);
                            break;
                        }
                        case 2:
                        {
                            int numeroEdicion;
                            char SiNo='0';
                            bool esMensual;
                            cout << "\nIngrese el número de edición de la revista: ";
                            cin >> numeroEdicion;
                            do{
                                cout << "\n¿Es mensual? (S/N)";
                                cin >> SiNo;
                                SiNo = toupper(SiNo);
                                if(SiNo != 'N' && SiNo != 'S'){
                                    cout << "\nOpción inválida. Intente de nuevo." << endl;
                                }
                            }while(SiNo != 'N' && SiNo != 'S');
                            esMensual = (SiNo == 'S');
                            mat = new DtRevista(codigo, titulo, numeroEdicion, anio, esMensual);
                        }
                        break;
                }
                agregarMaterial(mat);
                delete mat;
                break;}
            default:
            break;
        }
    }
    return 0;
}

void mostrarMenu(){
    setlocale(LC_ALL, "");
    cout << "Bienvenido!\nElija la opción:" << endl <<
            "1) Registrar lector" << endl <<
            "2) Agregar préstamo" << endl <<
            "3) Obtener materiales prestados" << endl <<
            "4) Consultar multa de material" << endl <<
            "5) Ver préstamos antes de fecha" << endl <<
            "6) Agregar material" << endl <<
            "0) Salir" << endl;
}

void registrarLector(string ci, string nombre, DtFecha* fechaRegistro){
    if(!existeLector){
        for(int i=0;i<MAX_LECTORES;i++){
            if(lectores[i]==nullptr){
                lectores[i] = new Lector(ci, nombre, fechaRegistro);
                cout << "Lector ingresado con éxito." << endl;
                return;
            }
        }
        cout << "ERROR: No hay espacio en la lista de lectores." << endl;
    }else{
        throw invalid_argument("Ya existe un usuario registrado con esa CI.");
    }
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha * fechaPrestamo, int diasPermitidos){
    for(int i=0; i<MAX_LECTORES; i++){
        if(lectores[i]!=nullptr){
            if(lectores[i]->getCi() == ci){
                if(lectores[i]->prestamoLleno()){
                    cout << "El lector ya tiene el máximo de préstamos." << endl;
                    return;
                }
                for(int j=0; j<MAX_MATERIALES; j++){

                    if(materiales[j]!=nullptr && materiales[j]->getCodigo() == codigoMaterial){
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
    }
    cout << "La cédula especificada no está registrada." << endl;
    return;
}
DtMaterial** obtenerMaterialesPrestados(string ci, int&cantMateriales){
    //Implementación pendiente
}
float consultarMultaMaterial(string ci, string codigoMaterial){
    //Implementación pendiente
}
DtMaterial** verPrestamosAntesDeFecha(string ci, DtFecha* fecha, int& cantPrestamos){

}
void agregarMaterial(DtMaterial * dtMaterial){
    if(existeMaterial(dtMaterial->getCodigo())){
        throw invalid_argument("Ya existe un material con ese código.");
    }
    for(int i=0; i<MAX_MATERIALES; i++){
        if(materiales[i]==nullptr){
            DtLibro* dtL = dynamic_cast<DtLibro*>(dtMaterial);
            DtRevista* dtR = dynamic_cast<DtRevista*>(dtMaterial);
            if(dtL != nullptr){
                materiales[i] = new Libro(dtL);
            }
            if(dtR!=nullptr){
                materiales[i] = new Revista(dtR);
            }
        }
    }
}
bool existeLector(string ci){
    for(int i=0; i<MAX_LECTORES; i++){
        if(lectores[i]!=nullptr){
            if(lectores[i]->getCi()==ci){
                return true;
            }
        }
    }
    return false;
}
bool materialesLleno(){
    for(int i=0; i<MAX_MATERIALES; i++){
        if(materiales[i]==nullptr){
            return false;
        }
    }
    return true;
}
bool existeMaterial(string codigo){
    for(int i=0; i<MAX_MATERIALES; i++){
        if(materiales[i]!=nullptr){
            if(materiales[i]->getCodigo() == codigo){
                return true;
            }
        }
    }
    return false;
}

