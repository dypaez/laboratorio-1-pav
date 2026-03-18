#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha{
    private:
    int dia;
    int mes;
    int anio;
    public:
    int getDia();
    int getMes();
    int getAnio();
    void printFecha();
    //Constructores
    DtFecha(int dia, int mes, int anio);
    
    //Destructor
    ~DtFecha();
};



#endif
