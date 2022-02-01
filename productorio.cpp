//Leer dos enteros y calcular el productorio de todos los números entre estos dos.
//Antonio B. Marín Carballo, 1ºC del grado en físicas.

#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    //Declaración de variables
    float prod;
    int n1, n2, i;
    //Introducción de datos
    cout <<"Introduce dos numeros enteros y se calculara el productorio de todos los números entre estos dos"<<endl;
    cout <<"Introduzca el primer número: ";
    cin >> n1;
    cout <<"Introduzca el segundo número: ";
    cin >> n2;
    //Cáculos
    prod = 1;//A continuación hay que establecer dos condiciones if, para ver que número es mayor, el que sea menor será el inicializador.
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

    //Declaración de resultados
    cout <<"El productorio entre " <<n1<< " y " <<n2<< " es "<<prod<<endl;
    return 0;
}

