#include "codigo.h"
#include "analizador.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>

using namespace std;

codigo::codigo()
{
    //ctor
}

void codigo::Menu()
{
    this->Crear_Archivo();
    int opc=0;

        cout<<"Osman Guacamaya   201504354"<<endl;
        cout<<"Elija una opcion:"<<endl;
        cout<<"Ingrese un comando"<<endl;
        analizador a;
        a.analiza();

}


void codigo::Crear_Archivo()
{
    try
    {
        FILE *f1,*f2;
        f1= fopen("profesores.bin","wb");
        f2= fopen("alumnos.bin","wb");
        fclose(f1);
        fclose(f2);
    }
    catch(int i)
    {
        cout<<"Existe un error al crear el archivo"<< i<<endl;
        this->Pausa();
    }
}

void codigo::Poner_Ceros(FILE *f)
{
    char buffer[10];
    int leidos=0;
    while(leidos<10)
    {
        buffer[leidos]=0;
        leidos++;
    }
    try
    {
        fwrite (buffer, 1, leidos, f);
    }
    catch(int i)
    {
        cout<<"error en archivos al poner ceros"<<endl;
    }

}
/*

void codigo::Escribir_Archivo(void *dato,int opc)
{
    //Escribiendo en el archivo
    try
    {
        FILE *f;
        switch(opc)
        {
        case 1:
        {
            f = fopen("profesores.bin","ab");
            tprofe *p=(tprofe*)dato;
            fwrite(p,sizeof(tprofe),1,f);
            fclose(f);
            cout<<"Profesor Guardado"<<endl;
        }
        break;
        case 2:
        {
            f = fopen("alumnos.bin","ab");
            testu *e=(testu*)dato;
            fwrite(e,sizeof(testu),1,f);
            fclose(f);
            cout<<"Estudiante guardado"<<endl;
        }
        break;
        default:
            cout<<"no se escribira nada >:/"<<endl;
        break;
        }
        this->Pausa();
    }
    catch(int i)
    {
        cout<<"Esxiste un error en el archivo al intentar escribirlo"<<endl;
        this->Pausa();
    }
}
*/
void codigo::Pausa()
{
    cout << "Enter to continue..." <<endl;
    cin.ignore();
    cin.get();
    system("clear");
}


codigo::~codigo()
{
    //dtor
}
