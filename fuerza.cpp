/*Programa para calcular la fuerza de un cuerpo puntual a partir de la masa y la aceleraci�n
Entradas: masa y aceleraci�n.
Saldida: Fuerza.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main(void)
{
    /*Declaraci�n de las variables usadas */
    int masa, aceleracion, fuerza;

    /*Entrada de la longitud de los lados */
    cout << "Introduzca la masa del cuerpo: ";
    cin >> masa;

    cout << "Introduzca la aceleracion del cuerpo: ";
    cin >> aceleracion;

    /*C�lculo de la fuerza*/
    fuerza=masa*aceleracion;

    /*Declaraci�n del resultado*/
    cout <<"El valor de la fuerza es: " << fuerza << endl;

    system ("pause");
    return 0;
}
