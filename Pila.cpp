#include "Pila.h"
using namespace std;
Pila::Pila(Elemento *Simbolo)
{
    Simbolo->setAnterior(NULL);
    this->Actual = Simbolo;
    cout << "Creando la base de la pila." << endl;
    cout << Simbolo->getSimbolo() << endl;
}
void Pila::Apilar(Elemento *Simbolo) //Push
{
    Simbolo->setAnterior(this->Actual);
    cout << "Agregando a la pila: " << Simbolo->getSimbolo() << endl;
    Actual = Simbolo;
}

Elemento *Pila::desapilar() //Pop
{
    Elemento *Retornar = Actual;
    this->Actual = Actual->getAnterior();
    return Retornar;
}

Elemento *Pila::tope() //Top
{
    return Actual;
}
bool Pila::estaVacia() //IsEmpty
{
    if (this->Actual == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Pila::~Pila() //Destructor
{
    cout << "Eliminando de la pila...." << endl;
}

void Pila::setvalor(double nuevovalor)
{
    this->valor = nuevovalor;
}

double Pila::getvalor()
{
    return this->valor;
}