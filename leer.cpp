#include <iostream>
#include <fstream>
#include <string>
#define MAX 22225

using namespace std;
void LeerCop(string palabras[]);
void CopiarAText(string palabras[],int n);
void Burbuja(string palabras[], int dimension);
void Seleccion(string palabras[], int dimension);

int main(void)
{
string diccionario[MAX];
LeerCop(diccionario);
Seleccion(diccionario, MAX);
CopiarAText(diccionario, MAX);
return 0;
}
void LeerCop(string palabras[])
{
ifstream fich;
int i;
i=0;
fich.open("C:\\CodeBlocks\\misprogramas\\letras\\palabras.txt");
    if(fich.is_open ()==true){
        cout<<"Fichero abierto: "<<endl;
        while(!fich.eof())
            {
                getline (fich,palabras[i]);
                i++;
            }
fich.close();
        }
    else cout<<"ERROR: Fichero no abierto";
return;
}

void CopiarAText(string palabras[], int n)
{
ofstream nuevofich;
int i;
i=0;
nuevofich.open("nfichero.txt");
for(i=0;i<n;i++){
    nuevofich << palabras[i]<<endl;
}
nuevofich.close();
return;
}


void Burbuja(string palabras[], int dimension)
{
    string temp;
    int i;
    int j;
    for (i=0; i<dimension; i++)
    {
        for (j=dimension-1; j>=i; j--)
        {
            if (palabras[j].length()>palabras[j-1].length()){
                temp = palabras[j];
                palabras[j] = palabras[j-1];
                palabras[j-1] = temp;
            }
        }
   }
   return;
}

void Seleccion(string palabras[], int dimension)
{
    string temp;
    int i, j, posmax;
    for (i=0; i<dimension-1; i++)
    {
        posmax=i;
        for (j=i+1; j<dimension; j++)
            if (palabras[j].length()>palabras[posmax].length()) posmax=j;

            temp = palabras[i];
            palabras[i] = palabras[posmax];
            palabras[posmax] = temp;
   }
   return;
}
