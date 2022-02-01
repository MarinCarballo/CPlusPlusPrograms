/*Programa que calcule las funciones trigonom�tricas del �ngulo doble,
usando tanto la aplicaci�n directa de cada funci�n (primera columna de la Tabla I),
como la expresi�n alternativa (segunda columna de la Tabla I)*/

#include <iostream>
#include <cmath>
#include <iomanip>

#define PI 3.141592
using namespace std;

int main(void)
{
    //Declaraci�n de variables
    double angulo, sen1, sen2, cos1, cos2, tan1, tan2;
    //Petici�n del �ngulo
    cout <<"Introduzca el angulo: ";
    cin >> angulo;

    angulo=angulo*(PI/180);
    //Calculos
    sen1=sin(2*angulo);
    sen2=2*sin(angulo)*cos(angulo);
    cos1=cos(2*angulo);
    cos2=(pow(cos(angulo),2))-(pow(sin(angulo),2));
    tan1=tan(2*angulo);
    tan2=(2*tan(angulo))/(1-pow(tan(angulo),2));

    /*. Ponemos una primera columna en "left" indicando los �ngulos dobles, para saber cuando es sen, cos o tan.
    Para la segunda columna utilizamos "internal", esta indica la forma directa. Por �ltimo podemos usar "right" para indicar la columna
    de la forma alternativa*/

    cout << setfill('.') <<scientific <<setprecision(5);
    //Primera fila
    cout << setw(20)<< left << "ANGULOS DOBLES" << setw(20)<< internal << "FORMA DIRECTA" << setw(20)<< right << "FORMA ALTERNATIVA"<<endl;
    //Segunda fila
    cout << setw(20)<< left << "SEN" << setw(20)<< internal << sen1 << setw(20)<< right << sen2<<endl;
    //Tercera fila
    cout << setw(20)<< left << "COS" << setw(20)<< internal << cos1 << setw(20)<< right << cos2<<endl;
    //Cuarta fila
    cout << setw(20)<< left << "TAN" << setw(20)<< internal << tan1 << setw(20)<< right << tan2<<endl;

    return 0;
}
