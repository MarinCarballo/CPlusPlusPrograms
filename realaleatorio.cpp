#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main(void)
{
    double n,n1,n2;
    //Semilla
    srand(time(NULL));
    //Generaci�n de los n�meros
    n=rand();//Primer llamamiento excluido para aportar m�s aleatoriedad.
    n1=rand();
    n2=n1/RAND_MAX;
    //Declaraci�n de resultados
    cout <<"El numero aleatorio es "<<n2<<endl;
return 0;

}
