#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        //Constructores
        DtFecha(int dia, int mes, int anio);
        //Operaciones
        int getDia();
        int getMes();
        int getAnio();
        int enDias();
        //Destructor
        ~DtFecha();
};

#endif
