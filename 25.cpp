//Realice una funcion para caluclar la expresion matematica siendo n entero x real<1
/*
Parámetros_
    -x:valor real menor que uno
    -n: valor entero
Devuelve:
    -Devuelve xla serie.*/
#include <iostream>
#include <cmath>
using namespace std;

double serie(double x, int n){
//Declaracion de variables locales
    double suma, numerador;
    int i;
    //Instrucciones
    suma=0;
    for(i=0; i<=n ;i++){
        suma += numerador/(2*i+1);//+= es como decir suma=suma+ j
        numerador= x*x;
    }
//Salida. Las funciones casi siempre son de cálculo, es decir, no hay ni entrada ni salida de datos.
    return suma;
}
