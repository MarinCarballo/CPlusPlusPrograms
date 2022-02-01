/*Programa para calcular el volumen de un cilindro a partir de su radio y su altura.
Entradas: El radio y la altura del cilindro
Saldida: El volumen del cilindro
El volumen de un cilindro es V=PI*R*R*Altura.
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
/*Definimos el valor de PI*/
#define PI 3.141592
using namespace std;
int main(void)
{
    /*Declaración de las variables usadas */
    double R, altura, volumen;
    /*Entrada de la longitud de los lados */
    cout << "Introduzca el radio del cilindro: ";
    cin >> R;

    cout << "Introduzca la altura del cilindro: ";
    cin >> altura;

    /*Cálculo del volumen*/
    volumen=PI*R*R*altura;

    /*Declaración del resultado*/
    cout <<"El valor del volumen es: " << volumen << endl;

    system ("pause");
    return 0;
}
