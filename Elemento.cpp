
#include "Elemento.h"
using namespace std;

Elemento::Elemento(string Simbolo)
{
    this->simbolo = Simbolo;
    this->Anterior = NULL;
}

Elemento::~Elemento()
{
    cout << "Elemento Destruido" << endl;
}

void Elemento::setSimbolo(string NuevoSimbolo)
{
    this->simbolo = NuevoSimbolo;
}

string Elemento::getSimbolo()
{
    return simbolo;
}

void Elemento::setAnterior(Elemento *Anterior)
{
    this->Anterior = Anterior;
}

Elemento *Elemento::getAnterior()
{
    return this->Anterior;
}