#include "lector.h"
#include "libro.h"
#include "revista.h"
#include "dtfecha.h"
#include <iostream>
#include <stdexcept>
#include <cctype>
#include <sstream>
#ifdef _WIN32
    #include <windows.h>
#endif
using namespace std;
/*
ARREGLOS
*/
Lector* lectores[MAX_LECTORES];
Material* materiales[MAX_MATERIALES];
/*
ARREGLOS
*/
bool existeLector(string ci){
    for(int i=0; i<MAX_LECTORES; i++){
        if(lectores[i]!=nullptr && lectores[i]->getCi()==ci){
            return true;
        }
    }
    return false;
}
Lector* encontrarLector(string ci){
    for(int i=0; i<MAX_LECTORES; i++){
        if(lectores[i]!=nullptr && lectores[i]->getCi()==ci){
            return lectores[i];
        }
    }
    return nullptr;
}
bool existeMaterial(string codigo){
    for(int i=0; i<MAX_MATERIALES; i++){
        if(materiales[i]!=nullptr && materiales[i]->getCodigo() == codigo){
            return true;
        }
    }
    return false;
}
Material* encontrarMaterial(string codigo){
    for(int i=0; i<MAX_MATERIALES; i++){
        if(materiales[i]!=nullptr && materiales[i]->getCodigo() == codigo){
            return materiales[i];
        }
    }
    return nullptr;
}
void mostrarMenu(){
    
    cout << "Bienvenido!\nElija la opcion:" << endl <<
    "1) Registrar lector" << endl <<
    "2) Agregar prestamo" << endl <<
    "3) Obtener materiales prestados" << endl <<
    "4) Consultar multa de material" << endl <<
    "5) Ver prestamos antes de fecha" << endl <<
    "6) Agregar material" << endl <<
    "0) Salir" << endl;
}
void registrarLector(string ci, string nombre, DtFecha* fechaRegistro){
    if(existeLector(ci)){ //Si ya existe Lector registrado con la CI pasada por parametro
        throw invalid_argument("Ya existe un usuario registrado con esa CI.");
    }
    for(int i=0;i<MAX_LECTORES;i++){ //Iterar por la coleccion de lectores.
        if(lectores[i]==nullptr){ //En el primer espacio vacio
            lectores[i] = new Lector(ci, nombre, fechaRegistro); //Crear una instancia de Lector.
            cout << "Lector ingresado con exito." << endl; //Avisar al usuario.
            return; //Cortar la funcion
        }
    }//Si no hay espacio...
    throw invalid_argument("No hay espacio en la coleccion de lectores."); //Lanzar error.
}
void agregarPrestamo(string ci, string codigoMaterial, DtFecha * fechaPrestamo, int diasPermitidos){
    Lector* l = encontrarLector(ci);
    Material* m = encontrarMaterial(codigoMaterial);
    if(l==nullptr){ //Si el lector no existe
        throw invalid_argument("El lector ingresado no existe."); //Lanzar error.
    }
    if(m==nullptr){ //Si el material no existe
        throw invalid_argument("El material especificado no existe."); //Lanzar error.
    }
    if(l->prestamoLleno()){ //Si el lector tiene la colección de préstamos llena
        throw invalid_argument("El lector ya tiene el maximo de prestamos."); //Lanzar error.
    }
    //Si ninguna condición que invalide el ingreso se cumple
    Prestamo* prestamo = new Prestamo(fechaPrestamo, m, diasPermitidos); //Se crea una instancia de la clase Prestamo.
    l->agregarPrestamo(prestamo); //Y posteriormente, se añade a la coleccion de prestamos del lector.
    cout << "Prestamo registrado con exito." << endl; //¡EXITO!
    return;
    

}

void agregarMaterial(DtMaterial * dtm){
    if(existeMaterial(dtm->getCodigo())){
        throw invalid_argument("Ya existe un material con ese codigo.");
    }
    for(int i=0; i<MAX_MATERIALES; i++){ //Recorriendo la coleccion de materiales...
        if(!materiales[i]){ //Si el indice actual es igual es nulo
            DtLibro* dtL = dynamic_cast<DtLibro*>(dtm); //Se intenta hacer dynamic_cast del "DtMaterial" pasado por parametro. Si este cast devuelve null, significa que NO es DtLibro.
            DtRevista* dtR = dynamic_cast<DtRevista*>(dtm); //Lo mismo que arriba, solo que si devuelve null, significa que NO es DtRevista.
            if(dtL){ //Si dtL (DtLibro) no es nulo...
                materiales[i] = new Libro(dtL); //Significa que el material a agregar es un libro.
                cout << "\nLibro registrado con exito." << endl;
            }else if(dtR){ //Pero, si dtR no es nulo...
                materiales[i] = new Revista(dtR); //Significa que el material a agregar es una revista.
                cout << "\nRevista registrada con exito." << endl;
            }else{ //Y si se da el caso de que ambos dan null??
                delete dtm;
                throw invalid_argument("Tipo de dato desconocido."); //Lanzar error, aunque por diseño nunca va a pasar.
            }
            delete dtm; //Luego de crear el objeto de Libro o Revista con el datatype, hacemos delete del DT, ya que su funcion termino.
            return; //Finalmente, cortamos la funcion por aca.
        }
    }//En caso de que no haya espacios nulos...
    delete dtm;
    throw invalid_argument("La coleccion de materiales esta llena."); //Lanzar error.
}
DtMaterial** obtenerMaterialesPrestados(string ci, int&cantMateriales){
    Lector* l = encontrarLector(ci);
    if(l==nullptr){//Si el lector indicado no existe.
        throw invalid_argument("El lector ingresado no existe."); //Lanzar error.
    }
    cantMateriales=l->getCantidadPrestados(); //El parametro cantMateriales es igualado a la cantidad de materiales prestados del lector.
    if(cantMateriales==0){ //Si el lector no tiene prestamos
        return nullptr; //Se devuelve null.
    }//Pero si no...
    DtMaterial** matsPrestados = new DtMaterial*[cantMateriales]; //Se crea un array dinamico de punteros de tipo DtMaterial con "cantMateriales" lugares.
    Prestamo* p; //Se declara un puntero a prestamo.
    Material* m;
    for(int j=0;j<cantMateriales;j++){ //iterando por la lista de prestamos.
        p = l->getPrestamo(j); //el puntero a prestamo es apuntado al prestamo almacenado en el lugar "j" de la coleccion.
        m = p->getMaterial(); //el puntero a material es apuntado al material de dicho prestamo.
        matsPrestados[j] = m->getDtMaterial(); //posteriormente se agrega dicho prestamo al indice "j" del array dinamico.
    }
    return matsPrestados; //Luego de terminar la iteracion por la lista de prestamos, devolver el array dinamico terminado.
}
float consultarMultaMaterial(string ci, string codigoMaterial, int diasAtraso){
    Lector* l = encontrarLector(ci);
    if(!l){ //Si no existe el lector
        throw invalid_argument("El lector ingresado no existe.");//Lanzar error.
    }
    Material* m = l->buscarMaterialPrestado(codigoMaterial);
    if(!m){
        throw invalid_argument("El lector no posee ese material."); //Lanzar error, el lector no posee ese material.
    }
    return m->calcularMulta(diasAtraso); //Devolver el calculo de multa del Material actual.
}
DtMaterial** verPrestamosAntesDeFecha(string ci, DtFecha* fecha, int& cantPrestamos){
    Lector* l = encontrarLector(ci);
    if(!l){
        throw invalid_argument("El lector ingresado no existe."); //Lanzar error.
    }
    int prestamosTotales=l->getCantidadPrestados(); //Se crea una variable que almacena la cantidad TOTAL de prestamos del lector.
    Prestamo* p; //Se declara un puntero a prestamo.
    DtMaterial** m = new DtMaterial*[prestamosTotales]; //Se crea un array dinamico de tipo DtMaterial con tamaño "prestamosTotales".
    int k=0; //Se crea variable k para llevar cuenta de que prestamos respetan las condiciones de la operacion.
    for(int j=0; j<prestamosTotales; j++){ //Iterando en los prestamos del Lector
        p = l->getPrestamo(j); //Se apunta el puntero al prestamo "j" del lector.
        if(p->getFecha()->enDias() < fecha->enDias()){ //Si el prestamo coincide con las condiciones de la operacion,
            m[k++] = p->getMaterial()->getDtMaterial(); //Se almacena en el indice "k" del array dinamico.
        }  
    }
    if(k==0){ //Si ningun prestamo cumplio con las condiciones
        cantPrestamos=0; //cantPrestamos se iguala a 0. (Esto porque el parametro "cantPrestamos" al ser por referencia, se usa para cambiar una variable pasada por parametro a la funcion!!)
        delete[] m; //Se borra el array dinamico "m", ya que no se utiliza para nada en este escenario.
        return nullptr; //Se devuelve null para manejarlo a posteriori.
    }//Pero, si al menos un prestamo cumple con las condiciones...
    cantPrestamos=k; //cantPrestamos se iguala a k, porque "k" prestamos estan antes de fecha.
    return m; //Se devuelve el array dinamico.
}


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
    cout << "Opcion: ";
    cin >> opcion;
    switch(opcion){
        case 0:
            for(int i=0;i<MAX_MATERIALES; i++){
                delete materiales[i];
            }
            for(int i=0;i<MAX_LECTORES; i++){
                delete lectores[i];
            }
            cout << "Adios!" << endl;
        break;
        case 1:{
            string ci = "", nombre = "", fecha = "";
            string diaStr, mesStr, anioStr;
            DtFecha* fechaRegistro = nullptr;
            cout << "\nIngrese la cedula de el/la lector/a: \n > ";
            cin >> ci;
            cout << "\nIngrese el nombre de el/la lector/a: \n > ";
            cin >> nombre;
            cout << "\nIngrese la fecha de registro (Formato DD/MM/YYYY): \n > ";
            cin >> fecha;
            stringstream ss(fecha);
            getline(ss, diaStr, '/');
            getline(ss, mesStr, '/');
            getline(ss, anioStr, '/');
            int dia = stoi(diaStr);
            int mes = stoi(mesStr);
            int anio = stoi(anioStr);
            fechaRegistro = new DtFecha(dia, mes, anio);
            try{
                registrarLector(ci, nombre, fechaRegistro);
            }catch(const invalid_argument &e){
                cout << "ERROR: " << e.what() << endl;
            }
        break;}
        case 2:{
            string ci = "", codigo = "", fecha = "";
            string diaStr, mesStr, anioStr;
            int duracionPrestamo;
            DtFecha* fechaPrestamo;
            cout << "\nIngrese la cedula del lector prestatario: \n > ";
            cin >> ci;
            cout << "\nIngrese el codigo del material que se prestara: \n > ";
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
            cout << "\nIngrese la duracion en dias del prestamo: \n > ";
            cin >> duracionPrestamo;
            try{
                agregarPrestamo(ci, codigo, fechaPrestamo, duracionPrestamo);
            }catch(const invalid_argument &e){
                cout << "ERROR: " << e.what() << endl;
            }
        break;}
        case 3:{
            string ci = "";
            cout << "\nIngrese la cedula de el/la lector/a: \n > ";
            cin >> ci;
            try{
                int cantMateriales = 0;
                DtMaterial** m = obtenerMaterialesPrestados(ci,cantMateriales);
                if(m==nullptr){
                    throw invalid_argument ("No tiene materiales prestados.");
                }
                cout << "\nPrestamos de el/la lector/a de CI " << ci << ".\n";
                for(int i=0; i<cantMateriales; i++){
                    m[i]->mostrarDatos();
                    cout << endl;
                }
                for(int i=0; i<cantMateriales; i++){
                    delete m[i];
                }
                delete[] m;
            }catch(const invalid_argument &e){
                cout << "ERROR: " << e.what() << endl;
            }
        break;}
        case 4:{
            string ci = "", codigoMaterial = "";
            cout << "\nIngrese la cedula de el/la lector/a: \n > ";
            cin >> ci;
            cout << "\nIngrese el codigo del material: \n > ";
            cin >> codigoMaterial;
            int diasAtraso = 0;
            cout << "\nIngrese los dias de atraso del material: \n > ";
            cin >> diasAtraso;
            try{
                float m = consultarMultaMaterial(ci, codigoMaterial, diasAtraso);
                cout << "\nLa multa del material es: " << m << endl;
            }catch(const invalid_argument &e){
                cout << "ERROR: " << e.what() << endl;
            }
        break;}
        case 5:{
            string ci = "", fecha = "";
            string diaStr, mesStr, anioStr;
            int cantPrestamos;
            DtFecha* fechaDT;
            cout << "\nIngrese la cedula del lector prestatario: \n > ";
            cin >> ci;
            cout << "\nIngrese la fecha de registro (Formato DD/MM/YYYY): \n > ";
            cin >> fecha;
            stringstream ss(fecha);
            getline(ss, diaStr, '/');
            getline(ss, mesStr, '/');
            getline(ss, anioStr, '/');
            int dia = stoi(diaStr);
            int mes = stoi(mesStr);
            int anio = stoi(anioStr);
            fechaDT = new DtFecha(dia, mes, anio);
            try {
                DtMaterial** m = verPrestamosAntesDeFecha (ci, fechaDT, cantPrestamos);
                if (m==nullptr) {
                    throw invalid_argument ("No se encontraron prestamos anteriores a la fecha indicada.");
                }
                cout << "Prestamos de el/la lector/a de CI " << ci << ", antes de " << dia << "/" << mes << "/" << anio << endl;
                for (int i = 0; i < cantPrestamos; i++){
                    m[i]->mostrarDatos();
                    cout << endl;
                } 
                for (int i = 0; i < cantPrestamos; i++){
                    delete m[i];
                } 
                delete[] m;
                delete fechaDT;
            }catch (const invalid_argument &e) {
                cout << "ERROR: " << e.what() << endl;
            }
        break;}
        case 6:{
            DtMaterial* mat = nullptr;
            int opc_material = 0;
            while((opc_material < 1) || (opc_material>2)){
                cout << "¿Que tipo de Material desea ingresar?" << endl <<
                        "1) Libro" << endl <<
                        "2) Revista" << endl <<
                        "\t> ";
                cin >> opc_material;
                if(opc_material < 1 || opc_material > 2){
                    cout << "Opcion invalida. Vuelta a intentarlo." << endl;
                }
            }
            string codigo, titulo;
            int anio;
            cout << "Ingrese el codigo del material: \n > ";
            cin >> codigo;
            cout << "\nIngrese el titulo del material: \n > ";
            cin >> titulo;
            cout << "\nIngrese el año de publicacion del material: \n > ";
            cin >> anio;
            switch(opc_material){
                    case 1:
                    {
                        string autor;
                        int cantPag;
                        cout << "\n¿Quien es el autor del libro? \n > ";
                        cin >> autor;
                        cout << "\n¿Cuantas paginas tiene el libro? \n > ";
                        cin >> cantPag;
                        mat = new DtLibro(codigo, titulo, autor, anio, cantPag);
                        break;
                    }
                    case 2:
                    {
                        int numeroEdicion;
                        char SiNo='0';
                        bool esMensual;
                        cout << "\nIngrese el numero de edicion de la revista: \n > ";
                        cin >> numeroEdicion;
                        do{
                            cout << "\n¿Es mensual? (S/N)";
                            cin >> SiNo;
                            SiNo = toupper(SiNo);
                            if(SiNo != 'N' && SiNo != 'S'){
                                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                            }
                        }while(SiNo != 'N' && SiNo != 'S');
                        esMensual = (SiNo == 'S');
                        mat = new DtRevista(codigo, titulo, numeroEdicion, anio, esMensual);
                    }
                    break;
            }
            try{
                agregarMaterial(mat);
            }catch(const invalid_argument &e){
                cout << "ERROR: " << e.what() << endl;
            }
            break;}
        default:
        break;
    }
}
return 0;
}
