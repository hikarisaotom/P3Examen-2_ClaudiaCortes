#include <string>
#include <iostream>
#include <string>
#include "Elemento.h"
#ifndef PILA_H
#define PILA_H
using namespace std;
//Inicio clase
class Pila
{
    //Atributos
  private:
    Elemento *Actual;
    Elemento *Viejo;
    double valor;
    string nombre;
    //metodos publicos
  public:
    //prototipos de metodos
    Pila(Elemento *);
    void Apilar(Elemento *); //Push
    Elemento *desapilar();   //Pop
    Elemento *tope();        //Top
    bool estaVacia();        //IsEmpty
    double getvalor();
    void setvalor(double);
    string getnombre();
    //Destructor
    ~Pila();

}; //Fin de la clase

#endif

/*CUANDO AGREGUE A LA PILA, DEBO HACER recibo.setAnterior(actual) y actual=recibido*/
