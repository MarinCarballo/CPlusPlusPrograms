#include <iostream>
#include <ctime>
#include <cmath>
bool es_primo (unsigned int n);

using namespace std;


int main(void){
    unsigned int n,i, r;
    unsigned long int suma;
    clock_t t1, t2;
    double numsecs;

    //Pedir el número
    cout<<"Introduzca un numero: ";
    cin >> n;

    //Realizar la suma acumulada
    suma=0;
    t1=clock();
    for(r=1; r<=100; r++){
        for(i=2;i<=n;i++)
            if(es_primo(i)) suma=suma+i;}
    t2=clock();

    //Mostrar el resultado
    cout << "Suma de los primos menores o igual que ";
    cout << n << ": " << suma <<endl;

    numsecs=(double)(t2-t1)/(CLOCKS_PER_SEC*100);
    cout << "Tiempo: "<<numsecs<<" segundos" <<endl;

    return 0;
}

bool es_primo (unsigned int n)
{
    unsigned int i,p;
    bool EsPrimo;

    if (n==2)EsPrimo=true;
    else if(n%2==0) EsPrimo=false;
    else
    {
        EsPrimo=true;
        p=(unsigned int)sqrt(n);
        i=3;
        while((i<=p)&& (EsPrimo==true))
        {
            if(n%i==0) EsPrimo=false;
            else i=i+2;
        }
    }
    return EsPrimo;
}
