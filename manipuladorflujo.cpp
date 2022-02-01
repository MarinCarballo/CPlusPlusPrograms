

#include <iostream>
#include <iomanip>
#define PI 3.1415927

using namespace std;

int main(void)
{
    double num = -PI;
    cout <<  "Vamos a mostrar el numero" << num << " usando distintas notaciones" <<endl << endl;
    cout << setfill('.') ;
    //Mostramos el numero en la forma por defecto con 3 cifras significativas
    cout << "Notacion por defecto (3 cifras significativas): " << endl;
    cout << setprecision(3);
    cout << left;
    cout << setw(15) <<num<< endl;

    cout << "Notacion por defecto (3 cifras significativas): " << endl;
    cout << setprecision(3);
    cout << right;
    cout << setw(15) <<num<< endl;

    cout << "Notacion por defecto (3 cifras significativas): " << endl;
    cout << setprecision(3);
    cout << internal;
    cout << setw(15) <<num<< endl;
    //Mostramos el número en la forma fixed con 4 cifras significativas
    cout << "Notacion fixed (4 cifras significativas): "<< endl;
    cout << fixed;
    cout << setprecision(4);
    cout << left;
    cout << setw(15) <<num<< endl;

     //Mostramos el numero en la forma cientufica con 6 cifras significativas
    cout << "Notacion cientifica (6 cifras significativas): "<< endl;
    cout << scientific;
    cout << setprecision(5);
    cout << left;
    cout << setw(15) <<num<< endl;

    return 0;
}


