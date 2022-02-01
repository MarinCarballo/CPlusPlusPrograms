/*Realice un programa que genere 3 n�meros enteros aleatorios comprendidos
entre -100 y 100 y los muestre en pantalla, ordenados de mayor a menor.*/
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(void)
{
    double n1,n2,n3;
    //Semilla
    srand(time(NULL));
    //Generaci�n de los numeros
    n1=rand()%201-100;
    n2=rand()%201-100;
    n3=rand()%201-100;

    //Comparaciones:
    if (n1>=n2){
        if (n2>n3){
        cout <<"El mayor numero es: "<<n1<<" ,el mediano es: "<<n2<<" y el menor es: "<<n3<<endl;}
        if (n3>=n2){
                    if(n1>=n3){
                         cout <<"El mayor numero es: "<<n1<<" ,el mediano es: "<<n3<<" y el menor es: "<<n2<<endl;
                            }
                    else if(n1<=n3)
                        {cout <<"El mayor numero es: "<<n3<<" ,el mediano es: "<<n1<<" y el menor es: "<<n2<<endl;}
                }
        }
    if (n2>n1){
        if (n1>n3){
        cout <<"El mayor numero es: "<<n2<<" ,el mediano es: "<<n1<<" y el menor es: "<<n3<<endl;}
        if (n3>=n1){
                    if(n2>=n3){
                         cout <<"El mayor numero es: "<<n2<<" ,el mediano es: "<<n3<<" y el menor es: "<<n1<<endl;
                            }
                    else if(n2<=n3)
                        {cout <<"El mayor numero es: "<<n3<<" ,el mediano es: "<<n2<<" y el menor es: "<<n1<<endl;}
                }
        }
return 0;

}
