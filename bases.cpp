//Programa que lee un valor entero desde el teclado y muestra su valor en pantalla usando la base decimal, la octal y la hexadecimal

#include <iostream>
#include <iomanip>

using namespace std;
int main(void)
{
    //Declaración de variables
    int numero;
    //Petición de variables
    cout << "Introduzca un valor entero: "<< endl;
    cin >> numero;
    //Base decimal
    cout << "Su valor en base decimal es: " << endl;
    cout << dec <<numero <<endl;
    cout << "Mostrando la base sería: " <<endl;
    cout << dec << showbase << numero <<endl;
    //Base octal
    cout << "Su valor en base octal es: " << endl;
    cout << oct << noshowbase <<numero <<endl;
    cout << "Su base es: " <<endl;
    cout << oct << showbase << numero <<endl;
    //Base hexadecimal
    cout << "Su valor en base hexadecimal es: " << endl;
    cout << hex <<noshowbase <<numero <<endl;
    cout << "Su base es: " <<endl;
    cout << hex << showbase << numero <<endl;
    return 0;
}
