#include "analizador.h"


analizador::analizador()
{
    //ctor
}


void analizador::analiza()
{
    string entrada;
    vector <string> tokens;
    cout<<"Entro"<<endl;
    getline(cin,entrada);
    if(iguales(entrada.substr(0,1),"#"))
    {
        cout<<"Este es un comentario"<<endl;
    }
    else
    {
        cout<<"Este no es un comentario"<<endl;
        tokens = listaTokens(entrada);
        string comando = tokens[0];
        int cont=0;
        while(cont<tokens.size()-1)
        {
            tokens[cont]=tokens[cont+1];
            cont++;
        }
        ejecutar(tokens);
    }
}

void analizador::ejecutar(vector <string> tkns)
{
    if(iguales(tkns[0],"EXEC"))
    {
        cout<<"El path es: "<<tkns[1]<<endl;
    }
    else
    {
        cout<<tkns[0]<<endl;
    }
}

vector <string> analizador::segmentos(vector<string> tkns)
{

}

vector<string> analizador::listaTokens(string entrada)
{
    vector <string> tkns;
    int posI = 0;
    int posF = 0;
    string fragmento;
    bool flag =false;
    while(posF >=0)
    {
        if(entrada[posI]=='-')
            break;      //
        posF = entrada.find(' ',posI);
        fragmento = entrada.substr(posI,posF-posI);
        posI=posF+1;
        tkns.push_back(fragmento);
    }
    return tkns;
}


bool analizador::iguales(string cad1, string cad2)
{
    //convirtiendo en mayusculas la cadena 1
    string cad1M="";
    for(char&cad1:cad1)
    {
        cad1M+=toupper(cad1);
    }

    //comparando
    return cad1M==cad2 ? true:false;
}

analizador::~analizador()
{
    //dtor
}
