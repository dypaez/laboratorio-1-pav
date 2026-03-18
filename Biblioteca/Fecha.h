#ifndef FECHA_H
#define FECHA_H

class DtFecha{
    private:
    int dia;
    int mes;
    int anio;
    public:
    void setDia(int);
    int getDia();
    void setMes(int);
    int getMes();
    void setAnio(int);
    int getAnio();
    
    //Constructores
    DtFecha(int dia, int mes, int anio);
    
    //Destructor
    ~DtFecha();
};



#endif