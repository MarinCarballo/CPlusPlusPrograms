/*Función que devuelve el valor de x^n, siendo n un número entero.
Parámetros_
    -x:valor real correspondiente a la base
    -n: valor entero correspondiente al exponente.
Devuelve:
    -Devuelve xn.*/
#include <iostream>

using namespace std;

double elevado(double x, int n){
//Declaracion de variables locales
    double prod;
    int i;

    //Instrucciones
    prod=1;
    for(i=1; i<=n ;i++){
        prod=prod*x;
    }
//Salida. Las funciones casi siempre son de cálculo, es decir, no hay ni entrada ni salida de datos.
    return prod;
}
int main(){
    double base, resultado;
    int exponente;

    //Lectura de datos
    cout <<"Programa que calcula x^n siendo n entero"<<endl;
    cout <<"Introduzca la base: ";
    cin >>base;
    cout <<"Introduzca el exponente: ";
    cin >>exponente;

    //Cálculos
    resultado=elevado(base, exponente);

    //Salida
    cout <<"El resultado es: "<<resultado<<endl;
return 0;
}
