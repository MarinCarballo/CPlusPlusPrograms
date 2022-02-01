 #include <iostream>
 #include <cmath>

using namespace std;

double e(int x, int n);
double potencia(double x, int n);

int main(void)
    {
        int x,num;
        double NumE;

        cout <<"Introduce el numero de terminos que se consideraran en la suma: ";
        cin >> num;
        cout <<"Introduce el valor de x: ";
        cin >> x;
        NumE=e(x,num);
        cout <<"El valor de e elevado a "<<x<<" para "<<num<<" terminos es: "<<NumE<<endl;

    return 0;
    }

//Funci�n para calcular el valor de e^x
//Par�metros: par�metros el valor de x y el n�mero n de t�rminos que se considerar�n en la suma de Taylor.
//Devuelve: valor de e^x.

double e(int x, int n)
    {
        int i,j;
        double suma,prod, terminos;
        suma=0;
        prod=1;
        for (i=1;i<=n;i++)
        {
            prod=prod*i;
            terminos=potencia(x,i)/prod;
            suma = suma + terminos;
        }
    return suma+1;//C++ no reconoce el factorial de 0, que es 1, por lo que a la suma final se le suma 1.
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
