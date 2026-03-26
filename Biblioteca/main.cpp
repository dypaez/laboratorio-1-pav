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
                cout << "\nIngrese la cédula de el/la lector/a";
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
            break;}
            case 2:{
                string ci = "", codigo = "", fecha = "";
                string diaStr, mesStr, anioStr;
                int duracionPrestamo;
                DtFecha* fechaPrestamo;
                cout << "\nIngrese la cédula del lector prestatario: \n > ";
                cin >> ci;
                cout << "\nIngrese el código del material que se prestará: \n > ";
                cin >> codigo;
                cout << "\nIngrese la fecha de registro (Formato DD/MM/YYYY): \n > ";
                cin >> fecha;
                stringstream ss(fecha);
                getline(ss, diaStr, '/');
                getline(ss, mesStr, '/');
                getline(ss, anioStr, '/');
                int dia = stoi(diaStr);
                int mes = stoi(mesStr);
                int anio = stoi(anioStr);
                fechaPrestamo = new DtFecha(dia, mes, anio);
                cout << "\nIngrese la duración en días del préstamo: \n > ";
                cin >> duracionPrestamo;
                agregarPrestamo(ci, codigo, fechaPrestamo, duracionPrestamo);
            break;}
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
    if(existeLector(ci)){ //Si ya existe Lector registrado con la CI pasada por parametro
        throw invalid_argument("Ya existe un usuario registrado con esa CI.");
    }
    for(int i=0;i<MAX_LECTORES;i++){ //Iterar por la colección de lectores.
        if(lectores[i]==nullptr){ //En el primer espacio vacío
            lectores[i] = new Lector(ci, nombre, fechaRegistro); //Crear una instancia de Lector.
            cout << "Lector ingresado con éxito." << endl; //Avisar al usuario.
            return; //Cortar la función
        }
    }//Si no hay espacio...
    throw invalid_argument("No hay espacio en la colección de lectores."); //Lanzar error.
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha * fechaPrestamo, int diasPermitidos){
    for(int i=0; i<MAX_LECTORES; i++){ //Iterando en la colección de lectores
        if(lectores[i]!=nullptr && lectores[i]->getCi() == ci){ //Si el índice actual NO es nulo y la cédula es igual a la ingresada por parámetros
            if(lectores[i]->prestamoLleno()){ //Se revisa si tiene la lista de préstamos llena
                throw invalid_argument("El lector ya tiene el máximo de préstamos."); //En caso de tenerla, lanza error, cancelando el proceso
            } //Pero si no...
            Material* material; // Se declara un puntero a Material
            for(int j=0; j<MAX_MATERIALES; j++){ //Iterando en la colección de materiales
                if(materiales[j]!=nullptr && materiales[j]->getCodigo() == codigoMaterial){ //Si el material actual NO es nulo y su código es igual al pasado por parámetros
                    material = materiales[j]; //el puntero a material declarado anteriormente, ahora apunta al material pasado por parámetro
                    Prestamo* prestamo = new Prestamo(fechaPrestamo, material, diasPermitidos); //Se crea una instancia de la clase Préstamo.
                    lectores[i]->agregarPrestamo(prestamo); //Y posteriormente, se añade a la colección de préstamos del lector.
                    cout << "Prestamo registrado con éxito." << endl; //¡ÉXITO!
                    return;
                }
            }//Si no se hallan coincidencias con el código de material indicado...
            throw invalid_argument("El material especificado no existe."); //Lanzar error.
        }
    }//Si no se encuentran coincidencias con la cédula indicada por parámetro...
    throw invalid_argument("El lector ingresado no existe."); //Lanzar error.
}
DtMaterial** obtenerMaterialesPrestados(string ci, int&cantMateriales){
    for(int i=0;i<MAX_LECTORES;i++){ //Iterando en la colección de lectores
        if(lectores[i]!=nullptr && lectores[i]->getCi()==ci){ //Si el índice actual NO es nulo y la cédula es igual a la ingresada por parámetros
            cantMateriales=lectores[i]->getCantidadPrestados(); //El parámetro cantMateriales es igualado a la cantidad de materiales prestados del lector.
            if(cantMateriales==0){ //Si el lector no tiene préstamos
                return nullptr; //Se devuelve null.
            }//Pero si no...
            DtMaterial** matsPrestados = new DtMaterial*[cantMateriales]; //Se crea un array dinámico de punteros de tipo DtMaterial con "cantMateriales" lugares.
            Prestamo* p; //Se declara un puntero a préstamo.
            for(int j=0;j<cantMateriales;j++){ //iterando por la lista de préstamos.
                p = lectores[i]->getPrestamo(j); //el puntero a préstamo declarado es apuntado al prestamo almacenado en el lugar "j" de la colección.
                matsPrestados[j] = p->getMaterial()->getDtMaterial(); //posteriormente se agrega dicho préstamo al índice "j" del array dinámico.
            }
            return matsPrestados; //Luego de terminar la iteración por la lista de préstamos, devolver el array dinámico terminado.
        }
    }//Si no se encuentra un lector con la cédula especificada en parámetros...
    throw invalid_argument("El lector ingresado no existe."); //Lanzar error.
}
float consultarMultaMaterial(string ci, string codigoMaterial, int diasAtraso){
    for(int i=0; i<MAX_LECTORES; i++){ //Iterando en la colección de lectores
        if(lectores[i]!=nullptr && lectores[i]->getCi()==ci){ //Si el índice actual NO es nulo y la cédula es igual a la ingresada por parámetros
            int cantPrestados=lectores[i]->getCantidadPrestados(); //Se crea una variable que almacena la cantidad de préstamos que tiene este lector.
            Material* m; 
            Prestamo* p; //Se declaran punteros a Material y Préstamo.
            for(int j=0; j<cantPrestados; j++){ //Iterando en la lista de préstamos...
                p = lectores[i]->getPrestamo(j); //El puntero a préstamo declarado es apuntado al prestamo almacenado en el lugar "j" de la colección.
                m = p->getMaterial(); //El puntero a material es apuntado al material almacenado en el préstamo actualmente seleccionado
                if(m->getCodigo()==codigoMaterial){ //Si dicho material es el que se está buscando
                    return m->calcularMulta(diasAtraso); //Devolver el cálculo de multa del Material actual.
                }
            }//En caso de que no se encuentre el material
            throw invalid_argument("El lector no posee ese material."); //Lanzar error, el lector no posee ese material.
        }
    }//Si no se encuentra la cédula especificada
    throw invalid_argument("El lector ingresado no existe.");//Lanzar error.
}
DtMaterial** verPrestamosAntesDeFecha(string ci, DtFecha* fecha, int& cantPrestamos){
    for(int i=0; i<MAX_LECTORES; i++){ //Iterando en la colección de lectores
        if(lectores[i]!=nullptr && lectores[i]->getCi()==ci){ //Si el índice actual NO es nulo y la cédula es igual a la ingresada por parámetros
            int prestamosTotales=lectores[i]->getCantidadPrestados(); //Se crea una variable que almacena la cantidad TOTAL de préstamos del lector.
            Prestamo* p; //Se declara un puntero a préstamo.
            DtMaterial** m = new DtMaterial*[prestamosTotales]; //Se crea un array dinámico de tipo DtMaterial con tamaño "prestamosTotales".
            int k=0; //Se crea variable k para llevar cuenta de qué préstamos respetan las condiciones de la operación.
            for(int j=0; j<prestamosTotales; j++){ //Iterando en los préstamos del Lector
                p = lectores[i]->getPrestamo(j); //Se apunta el puntero al préstamo "j" del lector.
                if(p->getFecha()->enDias() < fecha->enDias()){ //Si el préstamo coincide con las condiciones de la operación,
                    m[k++] = p->getMaterial()->getDtMaterial(); //Se almacena en el índice "k" del array dinámico.
                }  
            }
            if(k==0){ //Si ningún préstamo cumplió con las condiciones
                cantPrestamos=0; //cantPrestamos se iguala a 0. (Esto porque el parámetro "cantPrestamos" al ser por referencia, se usa para cambiar una variable pasada por parámetro a la funcion!!)
                delete[] m; //Se borra el array dinámico "m", ya que no se utiliza para nada en este escenario.
                return nullptr; //Se devuelve null para manejarlo a posteriori.
            }//Pero, si al menos un préstamo cumple con las condiciones...
            cantPrestamos=k; //cantPrestamos se iguala a k, porque "k" préstamos están antes de fecha.
            return m; //Se devuelve el array dinámico.
        }
    }//Si la cédula no coincide con ningún lector registrado...
    throw invalid_argument("El lector ingresado no existe."); //Lanzar error.
}
void agregarMaterial(DtMaterial * dtMaterial){
    if(existeMaterial(dtMaterial->getCodigo())){ //Esto no creo que amerite comentarios.
        throw invalid_argument("Ya existe un material con ese código.");
    }
    for(int i=0; i<MAX_MATERIALES; i++){ //Recorriendo la colección de materiales...
        if(materiales[i]==nullptr){ //Si el índice actual es igual es nulo
            DtLibro* dtL = dynamic_cast<DtLibro*>(dtMaterial); //Se intenta hacer dynamic_cast del "DtMaterial" pasado por parámetro. Si este cast devuelve null, significa que NO es DtLibro.
            DtRevista* dtR = dynamic_cast<DtRevista*>(dtMaterial); //Lo mismo que arriba, solo que si devuelve null, significa que NO es DtRevista.
            if(dtL != nullptr){ //Si dtL (DtLibro) no es nulo...
                materiales[i] = new Libro(dtL); //Significa que el material a agregar es un libro.
            }else if(dtR!=nullptr){ //Pero, si dtR no es nulo...
                materiales[i] = new Revista(dtR); //Significa que el material a agregar es una revista.
            }else{ //Y si se da el caso de que ambos dan null??
                throw invalid_argument("Tipo de dato desconocido."); //Lanzar error, aunque por diseño nunca va a pasar.
            }
            delete dtMaterial; //Luego de crear el objeto de Libro o Revista con el datatype, hacemos delete del DT, ya que su función terminó.
            return; //Finalmente, cortamos la función por acá.
        }
    }//En caso de que no haya espacios nulos...
    throw invalid_argument("La colección de materiales está llena."); //Lanzar error.
}
bool existeLector(string ci){
    for(int i=0; i<MAX_LECTORES; i++){
        if(lectores[i]!=nullptr && lectores[i]->getCi()==ci){
            return true;
        }
    }
    return false;
}
bool existeMaterial(string codigo){
    for(int i=0; i<MAX_MATERIALES; i++){
        if(materiales[i]!=nullptr && materiales[i]->getCodigo() == codigo){
            return true;
        }
    }
    return false;
}

