/*Programa que lea 5 valores reales desde el teclado y los
muestre de forma similar a como se muestra en la Figura 3 (en forma de
tabla, perfectamente alineados en una columna, fíjese bien que la coma
decimal debe aparecer en la misma vertical */

#include <iostream>
#include <iomanip>

using namespace std;
int main(void)
{
    //Declaración de variables
    double n1, n2, n3, n4, n5;
    //Pedir valores
    cout << "Introduzca el valor numero 1: ";
    cin >> n1;
    cout << "Introduzca el valor numero 2: ";
    cin >> n2;
    cout << "Introduzca el valor numero 3: ";
    cin >> n3;
    cout << "Introduzca el valor numero 4: ";
    cin >> n4;
    cout << "Introduzca el valor numero 5: ";
    cin >> n5;

    //Tabla
    cout << scientific;
    cout << setw(20)<< left << "Primer numero: " << setprecision(4) <<n1 <<endl;
    cout << setw(20)<< left << "Segundo numero: " << setprecision(4) <<n2 <<endl;
    cout << setw(20)<< left << "Tercer numero: " << setprecision(4) <<n3 <<endl;
    cout << setw(20)<< left << "Cuarto numero: " << setprecision(4) <<n4 <<endl;
    cout << setw(20)<< left << "Quinto numero: " << setprecision(4) <<n5 <<endl;

return 0;
}
