#ifndef ANALIZADOR_H
#define ANALIZADOR_H
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

typedef struct
{
    int mbr_tamano;
    int mbr_fecha_creacion;
    int mbr_dsk_signature;
}tmbr;



class analizador
{
    public:
        analizador();
        void analiza();
        virtual ~analizador();

    protected:

    private:
    tmbr MBR;
    vector <string> listaTokens(string entrada);
    vector <string> segmentos(vector <string> tkns);
    void ejecutar(vector <string> tkns);
    bool iguales(string cad1,string cad2);
};

#endif // ANALIZADOR_H
