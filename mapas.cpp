//Problema que trata de resolver el problema del viajante
//Se prueban varios algoritmos
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include <cmath>

#define MAX 100
#define MAX_TIME 3600

using namespace std;

//La clase tMapa se utiliza para almacenar en memoria
//el nombre de las ciudades y las distancias entre las mismas
class tMapa
{
public:
    int num_ciudades;
    string nombre_ciudad[MAX];
    int distancia[MAX][MAX];
    void LeerMapa(void);
};
//Método LeerMapa: Extrae los datos del fichero y los copia
//sobre la matriz de distancias del objeto
void tMapa::LeerMapa(void){
    ifstream fichero;
    int i,j;

    fichero.open("distancias.txt");

    //Leer número de ciudades
    fichero >>num_ciudades;

    //Leer nombre de las ciudades
    for (i=0;i<num_ciudades;i++){
        fichero>>nombre_ciudad[i];
    }
    //Leer la matriz de distancias
    for(i=0;i<num_ciudades;i++){
        for(j=0;j<num_ciudades;j++)
            fichero>>distancia[i][j];
    }
    fichero.close();

    return;
}
//La clase tRuta almacena un posible recorrido, es decir,
//el orden en el que se pueden recorrer las ciudades.
//Al final se añade la ciudad de origen como un elemento más.
//También guarda la distancia que supone dicho recorrido
class tRuta
{
    public:
        int num_ciudades;
        int recorrido[MAX+1];
        int distancia;

        void CalculaDistancia(tMapa mapa);
        void MuestraRuta(tMapa mapa);
};

//Método CalculaDistancia():calcula la distancia tontal de un recorrido
void tRuta::CalculaDistancia(tMapa mapa)
{
    int i;
    distancia=0;

    //Sumar la distancia entre cada dos ciudades del recorrido
    for(i=0;i<num_ciudades;i++)
        distancia=distancia + mapa.distancia[recorrido[i-1]][recorrido[i]];
    return;
}
//Método MuestraResultado(): muestra en pantalla la distancia de un recorrido y
//el orden en que hay que recorrer las ciudades, mostrando sus nombres.
void tRuta::MuestraRuta(tMapa mapa)
{
    int i;

    cout <<"Distancia: "<<distancia<<"Kms"<<endl;
    cout <<"Recorrido propuesto: "<<endl;

    //Ciudades intermedias, cada 5 hago un salto de línea
    for(i=0; i<=num_ciudades;i++){
        cout<<mapa.nombre_ciudad[recorrido[i]]<<" > ";
        if(i%5==0) cout << endl;
    }
    cout <<endl;
    return;
}

tRuta Algoritmo1(tMapa mapa);
tRuta Algoritmo2(tMapa mapa);
tRuta Algoritmo3(tMapa mapa);
tRuta Algoritmo4 (tMapa mapa, int tiempo_maximo);
tRuta Algoritmo5 (tMapa mapa, int tiempo_maximo);
tRuta Algoritmo6 (tMapa mapa, int tiempo_maximo);
tRuta IntercambiaCiudades (tRuta ruta, tMapa mapa);
char EscogeAlgoritmo ();
int PedirTiempoMaximo();

//Algoritmo1: calcula ruta por defecto. Se coge como
//recorrido el orden en que aparecen en el fichero original
tRuta Algoritmo1(tMapa mapa)
{
    tRuta ruta;
    int i;

    ruta.num_ciudades = mapa.num_ciudades;
    for(i=0; i<ruta.num_ciudades;i++)
        ruta.recorrido[i]=i;

    //Se añade la ciudad de partida al final del recorrido
    ruta.recorrido[ruta.num_ciudades] = 0;

    ruta.CalculaDistancia(mapa);

    return ruta;
}

//Algoritmo2(Greedy): se establece un recorrido consistente en
//escoger en primer lugar la ciudad más cercana a la ciudad de origen,
//después la más cercana a la escogida, y así sucesivamente
//Este algoritmo es en el fondo un problema de encontrar N mínimos,
//teniendo en cuenta que las ciudades que se hayan tenido en cuenta
//ya no hay que volver a considerarls
tRuta Algoritmo2(tMapa mapa)
{
    tRuta ruta;
    int distanciamin;
    int i,j;
    int ciudad_mascercana, contador;
    bool ciudad_escogida[MAX];

    ruta.num_ciudades = mapa.num_ciudades;

    //Usamos un array que indique si una ciudad ya se ha incluido o no
    for(i=0;i<=ruta.num_ciudades;i++)
        ciudad_escogida[i]=false;

    //La primera ciudad es la de partida la última es la misma
    ruta.recorrido[0]=ruta.recorrido[ruta.num_ciudades]=0;
    ciudad_escogida[0]=ciudad_escogida[ruta.num_ciudades]=true;

    //i indica el número de ciudad a la que hay que buscar la más cercanaa
    i=0;
    //contador indica el número de mínimos que hay que buscar, uno por cada
    //ciudad a recorrer, menos la última intermedia, que
    //retorna siempore a la de partida
    contador=0;
    while(contador<(ruta.num_ciudades-1))
    {
        //Para cada ciudad del recorrido busca la ciudad más cercana
        distanciamin=100000;
        for(j=0;j<ruta.num_ciudades;j++)
        {
            //Las ciudades que ya se han incluido en el recorrido no se cuentan
            //para evitar las repeticiones
            if(ciudad_escogida[j]==false)
                if(mapa.distancia[i][j]<distanciamin)
            {
                distanciamin=mapa.distancia[i][j];
                ciudad_mascercana=j;
            }
        }
        //Escogemos la ciudad más cercana como siguiente
        //en el recorrido y la descartamos para las próximas búsquedas
        //de mínimos
        i=ciudad_mascercana;
        ciudad_escogida[ciudad_mascercana]=true;
        contador++;
        ruta.recorrido[contador]=ciudad_mascercana;
    }
    ruta.CalculaDistancia(mapa);

    return ruta;
}

//Algoritmo3:se genera una ruta al azar
tRuta Algoritmo3(tMapa mapa)
{
    tRuta ruta;
    bool ciudad_escogida[MAX];
    int i, azar;

    ruta.num_ciudades=mapa.num_ciudades;
    //La ciudad de origen y la llega es fija
    ruta.recorrido[0]= ruta.recorrido[ruta.num_ciudades]=0;
    //Para controlar las ciudades ya escogidas previamente
        for (i = 1; i < ruta.num_ciudades; i++) {
        ciudad_escogida[i] = false;
    }
    //Las ciudades intermedias se escogen al azar
    for (i = 1; i < ruta.num_ciudades; i++) {
        azar = rand()%(ruta.num_ciudades-1)+1;
        while (ciudad_escogida[azar] == true) {
            if (azar == (ruta.num_ciudades-1)) {
                azar = 1;
            }else {
                azar ++;
            }
        }
        ruta.recorrido[i] = azar;
        ciudad_escogida[azar] = true;
    }
    ruta.CalculaDistancia(mapa);
    return ruta;
}

tRuta Algoritmo4 (tMapa mapa, int tiempo_maximo){
    tRuta RutaAleatoria, RutaMejor;
    clock_t tini, tfin;
    int numsecs;

    tini = clock();
    RutaMejor = Algoritmo3(mapa);
    do {
        RutaAleatoria = Algoritmo3(mapa);

        if (RutaAleatoria.distancia < RutaMejor.distancia) {
            RutaMejor = RutaAleatoria;
        }
        tfin = clock();
        numsecs = (int)(tfin-tini)/CLOCKS_PER_SEC;
    } while (numsecs <= tiempo_maximo);
    return RutaMejor;
}

tRuta Algoritmo5 (tMapa mapa, int tiempo_maximo){
    tRuta RutaNueva, RutaMejor;
    clock_t tini, tfin;
    int num_secs;

    tini = clock();
    RutaMejor = Algoritmo3(mapa);
    do {
        RutaNueva = IntercambiaCiudades(RutaMejor, mapa);
        if (RutaNueva.distancia < RutaMejor.distancia) {
            RutaMejor = RutaNueva;
        }
        tfin = clock();
        num_secs = (int)(tfin - tini)/CLOCKS_PER_SEC;
    } while (num_secs <= tiempo_maximo);

    return RutaMejor;
}

tRuta IntercambiaCiudades (tRuta RutaOriginal, tMapa mapa){
    int p1, p2;
    tRuta ruta;

    ruta = RutaOriginal;
    p1 = rand()%(ruta.num_ciudades-1) + 1;
    p2 = rand()%(ruta.num_ciudades-1) + 1;

    ruta.recorrido[p1] = RutaOriginal.recorrido[p2];
    ruta.recorrido[p2] = RutaOriginal.recorrido[p1];

    ruta.CalculaDistancia(mapa);

    return ruta;
}

tRuta Algoritmo6 (tMapa mapa, int tiempo_maximo){

    tRuta RutaNueva, RutaMejor;
    clock_t tini, tfin;
    int num_secs, i;
    double azar, probabilidad, T;

    tini = clock();
    RutaMejor = Algoritmo3(mapa);

    T = pow(tiempo_maximo, 2);
    do{
        for (i = 0; i<100; i++) {
            RutaNueva = IntercambiaCiudades(RutaMejor, mapa);
            if (RutaNueva.distancia <= RutaMejor.distancia) {
                RutaMejor = RutaNueva;
            }else{
                probabilidad = exp((double)(RutaMejor.distancia-RutaNueva.distancia)/(T*RutaMejor.distancia));
                azar = (double)rand()/RAND_MAX;
                if (probabilidad > azar) {
                    RutaMejor = RutaNueva;
                }
            }
        }
        T = 0.995*T;
        tfin = clock();
        num_secs = (int)(tfin - tini)/CLOCKS_PER_SEC;
    } while (num_secs <= tiempo_maximo);

    return RutaMejor;

}

char EscogeAlgoritmo (){
    char eleccion;
    cout << "PROBLEMA DEL VIAJANTE DEL COMERCIO " << endl << endl;
    cout << "1. Ruta por defecto" << endl;
    cout << "2. Algoritmo GREEDY" << endl;
    cout << "3. Ruta aleatoria" << endl;
    cout << "4. Busqueda completamente aleatoria" << endl;
    cout << "5. Busqueda aleatoria dirigida" << endl;
    cout << "6. Busqueda aleatoria dirigida con similated annealing" << endl;

    do {
        cout << "Escoja algoritmo: ";
        cin >> eleccion;
    } while ((eleccion < '1') || (eleccion > '6'));
    cout << endl;

    return eleccion;
}

int PedirTiempoMaximo (){
    int t;
    do {
        cout << "Introduzca numero de segundos maximos para la busqueda: ";
        cin >> t;
    } while ((t <= 0) || (t >= MAX_TIME));

    return t;
}

int main(){
    tMapa mapa;
    tRuta ruta;
    tRuta ruta_mejor;

    int tiempo;
    char opcion;
    int media;
    media = 0;
    ruta_mejor.distancia = 10000000;

    srand(time(NULL));
    mapa.LeerMapa();

    opcion = EscogeAlgoritmo();

    if (opcion == '1') {
        cout << "*** RUTA POR DEFECTO ***" << endl;
        cout << "Recorrido en el orden en el que aparecen las ciudades en el fichero" << endl << endl;
//Aqui no se hace las n pruebas de s segundos porque el resultado será siempre igual
        ruta = Algoritmo1(mapa);
        ruta.MuestraRuta(mapa);
    }else if (opcion == '2'){
        cout << "*** ALGORITMO DE DIJKTRA ***" << endl;
        cout << "Recorrido escogiendo siempre la ciudad mas proxima a una dada" << endl << endl;
//Aqui no se hace las n pruebas de s segundos porque el resultado será siempre igual
        ruta = Algoritmo2(mapa);
        ruta.MuestraRuta(mapa);
    }else if (opcion == '3'){
        cout << "*** RUTA ALEATORIA ***" << endl;
        cout << "Se genera una solución al azar" << endl << endl;
        ruta = Algoritmo3(mapa);
        ruta.MuestraRuta(mapa);
    }else if (opcion == '4'){
        cout << "*** BUSQUEDA COMPLETAMENTE ALEATORIA ***" << endl;
        cout << "Mejor recorrido de entre varias soluciones al azar" << endl << endl;

        tRuta MejorRuta;
        int n=0;
        int distanciamedia=0;
            cout<<"Numero de pruebas: ";
            cin>>n;
            tiempo = PedirTiempoMaximo();
            MejorRuta=Algoritmo3(mapa);//Generamos una ruta aleatorio para MejorRuta para poder comparar,
                for(int i=0;i<n;i++){
                    ruta = Algoritmo4(mapa, tiempo);//Generamos una ruta de s segundos.
                    distanciamedia+=ruta.distancia;//Vamos sumando las distancias.

                    if(ruta.distancia<MejorRuta.distancia)//Si en una prueba se obtiene una ruta mejor que la anterior, se actualiza.
                        MejorRuta=ruta;
                }
        distanciamedia=distanciamedia/n;//Calculo de la distancia media.
        cout<<"La distancia media es: "<<distanciamedia<<endl;
        cout<<"La mejor ruta es: "<<endl;
        MejorRuta.MuestraRuta(mapa);
    }else if (opcion == '5'){
        cout << "*** BUSQUEDA ALEATORIA DIRIGIDA ***" << endl;
        cout << "Mejor recorrido de entre varias soluciones al azar mediante transformaciones de una solucion dada" << endl << endl;

        tRuta MejorRuta;
        int n=0;
        int distanciamedia=0;
            cout<<"Numero de pruebas: ";
            cin>>n;
            tiempo = PedirTiempoMaximo();
            MejorRuta=Algoritmo3(mapa);//Generamos una ruta aleatorio para MejorRuta para poder comparar,
                for(int i=0;i<n;i++){
                    ruta = Algoritmo5(mapa, tiempo);//Generamos una ruta de s segundos.
                    distanciamedia+=ruta.distancia;//Vamos sumando las distancias.

                    if(ruta.distancia<MejorRuta.distancia)//Si en una prueba se obtiene una ruta mejor que la anterior, se actualiza.
                        MejorRuta=ruta;
                }
        distanciamedia=distanciamedia/n;//Calculo de la distancia media.
        cout<<"La distancia media es: "<<distanciamedia<<endl;
        cout<<"La mejor ruta es: "<<endl;
        MejorRuta.MuestraRuta(mapa);
    }else{
        cout << "*** BUSQUEDA CON SIMULATED ANNEALING ***" << endl;
        cout << "Busqueda aleatoria dirigida con enfrimamiento simulado" << endl << endl;

        tRuta MejorRuta;
        int n=0;
        int distanciamedia=0;
            cout<<"Numero de pruebas: ";
            cin>>n;
            tiempo = PedirTiempoMaximo();
            MejorRuta=Algoritmo3(mapa);//Generamos una ruta aleatorio para MejorRuta para poder comparar,
                for(int i=0;i<n;i++){
                    ruta = Algoritmo6(mapa, tiempo);//Generamos una ruta de s segundos.
                    distanciamedia+=ruta.distancia;//Vamos sumando las distancias.

                    if(ruta.distancia<MejorRuta.distancia)//Si en una prueba se obtiene una ruta mejor que la anterior, se actualiza.
                        MejorRuta=ruta;
                }
        distanciamedia=distanciamedia/n;//Calculo de la distancia media.
        cout<<"La distancia media es: "<<distanciamedia<<endl;
        cout<<"La mejor ruta es: "<<endl;
        MejorRuta.MuestraRuta(mapa);
    }
system("pause");
return 0;
}
