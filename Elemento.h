#include <string>
#include <iostream>
#ifndef ELEMENTO_H
#define ELEMENTO_H
#include <string>
#include "Elemento.h"
using namespace std;
//Inicio clase
class Elemento
{

  //Atributos
private:
  string simbolo;
  Elemento *Anterior;

  //metodos publicos
public:
  //prototipos de metodos
  Elemento(string);
  void setSimbolo(string);
  string getSimbolo();
  void setAnterior(Elemento *);
  Elemento *getAnterior();
  //Destructor
  ~Elemento();

}; //Fin de la clase

#endif
