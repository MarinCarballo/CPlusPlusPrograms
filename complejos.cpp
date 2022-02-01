//CLASE PARA TRABAJAR CON NÚMEROS COMPLEJOS.
//Antonio B. Marín Carballo, 1º C Física.

#include <iostream>
#include <cmath>

using namespace std;

class cComplejo{
private:
    double re,im;
public:
        cComplejo();
        void leeTeclado();
        void MostrarPorPantalla();
        void AsignaValor(double r, double i);
        void AsignaValorPolar (double m, double a);
        double ParteReal ();
        double ParteImaginaria ();
        double Modulo();
        double Argumento();
        cComplejo conjugado();
        cComplejo operator + (cComplejo op);
        cComplejo operator - (cComplejo op);
        cComplejo operator * (cComplejo op);
        cComplejo operator / (cComplejo op);
        bool operator == (cComplejo op);
        bool operator != (cComplejo op);

};
//Método constructor asigna como valor inicial a cualquier objeto de la clase compleja el valor de 1+0i
  cComplejo::cComplejo(){
  re=1;
  im=0;
  }
  //Lee un número complejo desde el teclado
  void cComplejo::leeTeclado(){
    cout<<"Parte real: ";
    cin>>re;
    cout<<"Parte imaginaria: ";
    cin>>im;
  }
  void cComplejo::MostrarPorPantalla(){
    if(im>0)
    cout<<re<<" + "<<im<<"i"<<endl;
    else cout<<re<<" "<<im<<"i"<<endl;
  }
  //Asigna un valor a re y a im desde el main, así no se accede directamente al privado.
  void cComplejo::AsignaValor(double r, double i){
        re=r;
        im=i;
  }
//Muestra el valor de la parte real de nuestro número complejo.Devuelve un real.
double cComplejo :: ParteReal (){
    return re;
}
//Muestra el valor de la parte imaginaria de nuestro número complejo.Devuelve un real.
double cComplejo :: ParteImaginaria (){
    return im;
}
//Calcula el módulo del número complejo y lo devuelve. Devuelve un real.
double cComplejo:: Modulo(){
    return sqrt(re*re+im*im);
}
//Calcula el argumento del número complejo y lo devuelve. Devuelve un real.
double cComplejo:: Argumento(){
    return atan(im/re);
}
//AsignaPolar: pone un número complejo en su forma polar
//m=Módulo a=Argumento. Devuelve un real.
void cComplejo:: AsignaValorPolar(double m, double a){
    re = m*cos(a);
    im = m*sin(a);
}
//Conjugado: calcula el conjugado. Z=a+bi || Z(CONJUGADO)=a-bi. Devuelve un cComplejo,
cComplejo cComplejo::conjugado(){
    cComplejo aux;
    aux.re=re;
    aux.im=-im;
return aux;
}
//Operador +, devuelve complejo(suma de complejos -> complejo)
cComplejo cComplejo::operator + (cComplejo op){
    cComplejo aux;
    aux.re= re + op.re;
    aux.im= im + op.im;
return aux;
}
//Operador -, devuelve complejo(resta de complejos -> complejo)
cComplejo cComplejo::operator - (cComplejo op){
    cComplejo aux;
    aux.re= re - op.re;
    aux.im= im - op.im;
return aux;
}
//Operador *, devuelve complejo(multiplicación de complejos -> complejo)
cComplejo cComplejo::operator * (cComplejo op){
    cComplejo aux;
    aux.re= re*op.re + im*op.im;
    aux.im= re*op.im + im*op.re;
return aux;
}
//Operador /, devuelve complejo(division de complejos -> complejo)
cComplejo cComplejo::operator / (cComplejo op){
    cComplejo aux;
    aux.re = (re * op.re + im*op.im)/(op.re*op.re + op.im*op.im);
    aux.im = (im * op.re - re*op.im)/(op.re*op.re + op.im*op.im);
return aux;
}
//Operador !=, devuelve un booleano ya que comprueba si son desiguales
//Si son desiguales -> true, si no->false
bool cComplejo::operator!= (cComplejo op){
    if((re!=op.re)&&(im!=op.im))
       return true;
    else return false;
}
//Operador ==, devuelve un booleano ya que comprueba si son iguales
//Si son iguales -> true, si no->false
bool cComplejo::operator== (cComplejo op){
    if((re!=op.re)&&(im!=op.im))
       return false;
    else return true;
}
