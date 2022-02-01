#include <iostream>
#include <cstdlib>
#include <ctime>
#define TAM 100

void mostrarMatriz(int M[][TAM], int nfil, int ncol);
void sumaMatrices(int M1[][TAM], int nfil, int ncol, int M2[][TAM], int M3[][TAM]);
void RestaMatrices(int M1[][TAM], int nfil, int ncol, int M2[][TAM], int M3[][TAM]);
void rellenarMatriz(int M[][TAM], int nfil, int ncol);
void rellenarMatrizAleatorio(int M[][TAM], int & nfil, int & ncol);
void multiplicarMatrices(int A[][TAM], int nfil, int ncol, int B[][TAM], int nfil2, int ncol2, int C[][TAM], int & nfil3, int &ncol3);

using namespace std;

int main(){
    int M1[TAM][TAM], M2[TAM][TAM], M3[TAM][TAM];
    int nfil, ncol, nfil1, ncol1, nfil2, ncol2, nfil3, ncol3;

    //Inicialización de la semilla pra números aleatorios
    srand(time(NULL));

    cout << "Introduzca el número de filas de la matriz 1: ";
    cin >> nfil1;
    cout << "Introduzca el número de columnas de la matriz 1: ";
    cin >> ncol1;

    cout << "Introduzca el número de filas de la matriz 2: ";
    cin >> nfil2;
    cout << "Introduzca el número de columnas de la matriz 2: ";
    cin >> ncol2;

    rellenarMatrizAleatorio(M1, nfil1, ncol1);
    cout << "La primera matriz es: "<<endl;
    mostrarMatriz(M1, nfil1, ncol1);
    rellenarMatrizAleatorio(M2, nfil2, ncol2);
    cout << "La segunda matriz es: "<<endl;
    mostrarMatriz(M2, nfil2, ncol2);

    cout <<"Su suma es: "<<endl;
    sumaMatrices(M1, nfil1, ncol1, M2, M3);
    mostrarMatriz(M3,nfil1,ncol1);
    cout <<"Su resta es: "<<endl;
    RestaMatrices(M1, nfil1, ncol1, M2, M3);
    mostrarMatriz(M3,nfil1,ncol1);
    if(ncol1==nfil2){
    cout <<"Su multiplicacion es: "<<endl;
    multiplicarMatrices(M1, nfil1,ncol1,M2,nfil2,ncol2,M3,nfil3,nfil3);
    mostrarMatriz(M3,nfil1,ncol1);
    }
    else {
    cout << "No se pueden multiplicar matrices con numero de columnas de M1 y numero de filas de M2 DIFERENTES "<<endl;
    }
    return 0;
}
//Función que rellena los valores de una matriz aleatoriamente.
void rellenarMatrizAleatorio(int M[][TAM], int & nfil, int & ncol){
    int i,n,j;

    for (i=0;i<nfil;i++){
        for (j=0;j<ncol; j++){
            M[i][j] = rand();
        }
    }
    return;
}


//Función que devuelve la suma de dos matrices
//Parámetros:  -M1: Matriz 1 de dimensiones nfil x ncol
//             -M2: Matriz 2 de dimensiones nfil x ncol
//             -M3: Matriz 3 de dimensiones nfil x ncol
//              ncol y nfil: numero de filas y de las columnas
//Devuelve: M3

void sumaMatrices(int M1[][TAM], int nfil, int ncol, int M2[][TAM], int M3[][TAM]){
    int i,n,j;
    for (i=0;i<nfil;i++){
        for (j=0;j<ncol; j++){
           M3[i][j] = M1[i][j] + M2[i][j];
        }
}
        return;
}
//Función que devuelve la resta de dos matrices
//Parámetros:  -M1: Matriz 1 de dimensiones nfil x ncol
//             -M2: Matriz 2 de dimensiones nfil x ncol
//             -M3: Matriz 3 de dimensiones nfil x ncol
//              ncol y nfil: numero de filas y de las columnas
//Devuelve: M3
void RestaMatrices(int M1[][TAM], int nfil, int ncol, int M2[][TAM], int M3[][TAM]){
    int i,n,j;
    for (i=0;i<nfil;i++){
        for (j=0;j<ncol; j++){
           M3[i][j] = M1[i][j] - M2[i][j];
        }
}
        return;
}
//Función que muestra una matriz
//Parámetros:  n,j
//Devuelve: M
void mostrarMatriz (int M[][TAM], int nfil, int ncol){

    for (int i = 0; i < nfil; i++){
        for (int j = 0; j < ncol; j++){
            cout << M[i][j] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
//Función que devuelve la  de multiplicacion dos matrices
//Parámetros:  -M1: Matriz 1 de dimensiones nfil1 x ncol1
//             -M2: Matriz 2 de dimensiones nfil2 x ncol2
//             -M3: Matriz 3 de dimensiones nfil3 x ncol3
//Devuelve: M3
void multiplicarMatrices(int A[][TAM], int nfil1, int ncol1, int B[][TAM], int nfil2, int ncol2, int C[][TAM], int & nfil3, int &ncol3){
    int i,j,k,suma;
    if (nfil1==ncol2){
    for (i=0;i<nfil1;i++){
        for(j=0;j<ncol2;j++){
            suma=0;
            for(k=0;k<ncol1;k++){
                suma += A[i][k]*B[k][j];
            C[i][j]=suma;}
                            }
                        }
    return;
    }
}
//Función que devuelve la suma de dos matrices
//Parámetros: ncol y nfil: numero de filas y de las columnas
//Devuelve: M
void rellenarMatriz(int M[][TAM], int nfil, int ncol){
    int i,j;
    for(i=0;i<nfil;i++){
        for(j=0;j<ncol;i++){
            cout<<"Fila "<<i+1<<"Columna: "<<j+1;
            cin >> M [i][j];
            }
        }
return;
        }
