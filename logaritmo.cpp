/*Programa que calcula el logaritmo de un número en cualquier base
(por ejemplo, el logaritmo de 10 en base 3). El programa pedirá al usuario que
introduzca el número y la base del logaritmo, y el programa mostrará el resultado*/
//Para generar los logaritmos para otras bases, se usa la siguiente relación matemática: logaritmo base b de a == logaritmo natural (a) / logaritmo natural (b).
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(void)
{
    //Declaración de variables
    double logaritmo, numero, base;
    //Petición de variables
    cout << "Este programa sirve para calcular el logaritmo de un número en cualquier base" <<endl;
    cout << "Introduzca el numero: ";
    cin >> numero;
    cout <<"Introduzca la base del logaritmo: ";
    cin >> base;
    //Calculo
    logaritmo=(log (numero))/(log (base));
    //Resultado
    cout << setfill('_') ;
    cout << setprecision(5) <<"El logaritmo de " <<numero<< " en base "<<base<< " es " << logaritmo << endl;
    cout << setprecision(5) << setw (5) << left <<"log" <<base<< "("<<numero<<")=" << logaritmo<<endl;

    return 0;
}
