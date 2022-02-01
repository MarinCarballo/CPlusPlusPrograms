//Leer números desde teclado y contar cuantos positivos y negativos introduce el usuario (0 para acabar).
//Antonio B. Marín Carballo, 1ºC del grado en físicas.

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    //Declaración de variables
    double numero, positivo, negativo;
    cout <<"Ingrese un numero: ";
    cin >>numero;
    positivo=0;
    negativo=0;
    while (numero!=0)
    {
        if(numero<0)
        {
            negativo=negativo+1;
            cout <<"Ingrese otro numero: ";
            cin >>numero;
        }
        if(numero>0)
        {
            positivo=positivo+1;
            cout <<"Ingrese otro numero: ";
            cin >>numero;
        }
    }
cout <<"Hay "<<positivo<< " numeros positivos y "<<negativo<<" numeros negativos"<<endl;
return 0;
}
