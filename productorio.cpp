//Leer dos enteros y calcular el productorio de todos los n�meros entre estos dos.
//Antonio B. Mar�n Carballo, 1�C del grado en f�sicas.

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    //Declaraci�n de variables
    float prod;
    int n1, n2, i;
    //Introducci�n de datos
    cout <<"Introduce dos numeros enteros y se calculara el productorio de todos los n�meros entre estos dos"<<endl;
    cout <<"Introduzca el primer n�mero: ";
    cin >> n1;
    cout <<"Introduzca el segundo n�mero: ";
    cin >> n2;
    //C�culos
    prod = 1;//A continuaci�n hay que establecer dos condiciones if, para ver que n�mero es mayor, el que sea menor ser� el inicializador.
        if (n2>n1)
            {
                for(i=n1; i<=n2; i++)
                    {
                        prod=prod*i;
                    }
            }
        if (n1>n2)
            {
                for(i=n2; i<=n1; i++)
                    {
                        prod=prod*i;
                    }
            }

    //Declaraci�n de resultados
    cout <<"El productorio entre " <<n1<< " y " <<n2<< " es "<<prod<<endl;
    return 0;
}

