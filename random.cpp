//Rrograma que genera tres n�meros enteros aleatorios y los muestra en pantalla.
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(void)
{
    int n1, n2, n3;
    //Semilla
    srand(time(NULL));
    //Generaci�n de los n�meros
    n1=rand();
    n2=rand();
    n3=rand();

    //Declaraci�n de resultados
    cout <<"El primer numero aleatorio es "<<n1<<endl;
    cout <<"El segundo numero aleatorio es "<<n2<<endl;
    cout <<"El tercer numero aleatorio es "<<n3<<endl;

return 0;

}
