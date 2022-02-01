#include <iostream>

#define PI 3.1415926

double potencia(double x, int n);
double arcsen(double x, int nt);
double arccos(double x, int nt);
double grados(double x);

using namespace std;
int main(void)
{
    double num;
    double asenrad, acosrad;
    double asengra, acosgra;
    int nt;

    //Pedir el n�mero
    cout <<"Introduzca un numero real; ";
    cin >> num;
    cout <<"Introduzca el valor de nt:  ";
    cin >> nt;
    //Calculos en tr
    asenrad=arcsen(num, nt);
    acosrad=arccos(num, nt);

    asengra= grados(asenrad);
    acosgra= grados(acosrad);

    cout << "Arco seno: "<<asenrad<<endl;
    cout << "Arco seno: "<<asengra<<endl;
    cout << "Arco coseno: "<<acosrad<<endl;
    cout << "Arco coseno: "<<acosgra<<endl;

    return 0;
}
/*Funci�n potencia, calcula la potencia en�sima
Par�metros: x, n.
Devuelve: x elevado a n*/

double potencia(double x, int n)
    {
        int i;
        double prod;
        prod=1;
        for(i=1; i<=n; i++) prod=prod*x;
        return prod;
    }

/*Funci�n arcoseno: calcula el arcoseno de un n�mero
Par�metros: x
Devuelve: arcosen(x)*/
double arcsen(double x, int nt)
    {
        double num,den,suma;
        int n,j;

        suma=x;
        for(n=1;n<=nt;n++)
        {
            num=1;
            den=1;
            for(j=1;j<=n;j++)
                {
                    num=num*(2*j-1);
                    den=den*2*j;
                }
            num=num*potencia(x,2*n+1);
            den=den*(2*n+1);

            suma=suma+num/den;
        }
        return suma;
    }
/*Funci�n arcocoseno: calcula el arcocoseno de un n�mero
Par�metros: x
Devuelve: arccos(x)*/
double arccos(double x, int nt)
    {
        return PI/2-arcsen(x, nt);
    }

/*Funci�n grados: convierte radianes en grados
Par�metros: x
Devuelve: El respectivo valor de x en grados*/
double grados(double x)
    {
        return 180*x/PI;
    }
