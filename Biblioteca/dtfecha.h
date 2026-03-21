#ifndef DTFECHA_H
#define DTFECHA_H

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        //Constructores
        DtFecha();
        DtFecha(int dia, int mes, int anio);
        //Operaciones
        int getDia();
        int getMes();
        int getAnio();
        //Destructor
        ~DtFecha();
};

#endif
