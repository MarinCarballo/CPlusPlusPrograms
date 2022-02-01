#include <iostream>
#include <ctime>
bool es_primo (unsigned int n);

using namespace std;


int main(void){
    unsigned int n,i;
    unsigned long int suma;
    clock_t t1, t2;
    double numsecs;

    //Pedir el número
    cout<<"Introduzca un numero: ";
    cin >> n;

    //Realizar la suma acumulada
    t1=clock();
    suma=0;
    for(i=2;i<=n;i++)
        if(es_primo(i)) suma=suma+i;
    t2=clock();

    //Mostrar el resultado
    cout << "Suma de los primos menores o igual que ";
    cout << n << ": " << suma <<endl;

    numsecs=(double)(t2-t1)/CLOCKS_PER_SEC;
    cout << "Tiempo: "<<numsecs<<" segundos" <<endl;

    return 0;
}

//Función que comprueba si un numero entero es primo
//Devuelve un booleano, TRUE si es primo, FALSE si no lo es
//Divide el número por todos los enteros menores que él.
//Si el resto de algunas de las divisiones es cero, el número NO es primo.
bool es_primo (unsigned int n)
{
    unsigned int i;
    bool EsPrimo;

    EsPrimo=true;
    i=2;
    while ((i<n)&&(EsPrimo==true)){
        if (n%i==0) EsPrimo=false;
        else i++;
    }
    return EsPrimo;
}

