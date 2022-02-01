#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
return 0;
}

bool leeFicheroYMuestraPorPantalla(string nombre){
ifstream fich;
string cad;
fich.open(nombre.c_str());
    if(fich.is.open()){
        while(!fich.eof()){
            getline(fich, cad);
            cout<<cad<<end;
        }
    fich.close();
    return true;
    }
    else cout <<"Error al abrir el archivo"<<endl;
}

bool leeFicheroYMuestraPorPantalla(string origen, string destino){
ifstream FicheroOrigen;
ofstream FicheroDestino;
string cad;
FicheroOrigen.open(origen.c_str());
FicheroDestino.open(destino.c_str());
    if(FicheroOrigen.is.open()&&FicheroDestino.is.open()){
        while(!fich.eof()){
            getline(FicheroOrigen, cad);
            FicheroDestino>>cad>>end;
        }
    FicheroOrigen.close();
    FicheroDestino.close();
    return true;

    }
    else cout <<"Error al abrir el archivo"<<endl;
}

bool Comparar(string nombre1, string nombre 2, int &codigo){
    ifstream F1,F2;
    string cad1,cad2;
    bool soniguales;
    soniguales=true;
    F1.open(nombre1.c_str());
    F2.open(nombre1.c_str());
    if(!F1.is.open()){
        return false;
    }
    if(!F2.is.open()){
        return false;
    }
    else{
        while(!F1.eof()&&!F2.eof()&& soniguales()){
            getline(F1,cad1);
            getline(F2,cad2);
                if(cad1 != cad2)
                    soniguales=falso
                }
                if(F1.eof()!=F2.eof())
                    soniguales=falso
            F1.close();
            F2.close();
            return soniguales
    }
}


bool mediasPorColumnas(string nombre, int m[]){
    ifstream fich;
    int cont,num;
    num=0;
    fich.open(nombre.c_str());
    if(fich.is.open()){
        while(!fich.eof()){
            fich>>num;
            m[0]+=num;
            fich>>num;
            m[1]+=num;
            fich>>num;
            m[2]+=num;
            cont++;
        }
        m[0]/=cont;
        m[1]/=cont;
        m[2]/=cont;
    fich.close;
    return true;}
    else{
        cout<<"ERROR. El fichero no se pudo abrir"<<endl;
        return false;
    }
}
