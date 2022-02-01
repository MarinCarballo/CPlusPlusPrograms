/*Realice un programa que genere 10 números reales aleatorios comprendidos
entre -7.5 y 7.5 y los muestre en pantalla. Además, al final deberá mostrar el valor
máximo, el mínimo y el valor promedio de los números que se han generado. */

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(void)
{
    int i;
    double n1,promedio, maximo, minimo;
    promedio=0;
    maximo=0;
    minimo=0;
    //Semilla
    srand(time(NULL));
    //Generación de los números
    for(i=1; i<=10; i++) {
        n1=rand();
        n1=n1/RAND_MAX*15-7.5;
        if (n1>maximo){
            maximo=n1;
            }
        if (n1<minimo){
            minimo=n1;
            }
        promedio=promedio+n1;
        cout << "En la iteracion numero: " << i << " el numero aleatorio es: "<< n1<<endl;
    }
    //Declaración de resultados
    cout <<"El maximo es: "<<maximo<<", el minimo es: "<<minimo<<" y el valor promedio es: "<<promedio/10<<endl;
return 0;
}
