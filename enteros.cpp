/*Programa que coge dos números enteros y nos da su suma, su resta, su producto, su cociente entero y su resto entero.
Entradas: a y b
Saldida: Suma, resta, producto, cociente entero y resto entero.
*/

#include <iostream>
#include <cstdlib>

using namespace std;
int main(void)
{
    /*Declaración de las variables usadas */
    int a, b, suma, resta, producto, division, resto;
    /*Entrada de a y de b */
    cout << "Introduzca el valor de a: ";
    cin >> a;

    cout << "Introduzca el valor de b: ";
    cin >> b;
while (b==0)
    {
        cout <<"No se puede dividir por 0, introduzca otro valor en b";
        cin >> b;
    }
if(b=!0)
{
    /*Cálculos*/
    suma=a+b;
    resta=a-b;
    producto=a*b;
    division=("%d", a/b);
    resto=("%d", a%b);
    /*Declaración del resultado*/
    cout <<"La suma da " << suma << endl;
    cout <<"La resta da " << resta << endl;
    cout <<"El producto da " << producto << endl;
    cout <<"El cociente entero es " << division << endl;
    cout <<"El resto entero es " << resto << endl;
    system ("pause");
    return 0;
}
}
