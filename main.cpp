/*LIbrerias*/
#include <iostream>
#include <string>
#include "Elemento.h"
#include "Pila.h"
#include <vector>
using namespace std;
int main()
{
    vector <Pila *> Stacks;
    string operacion = "";
    cout << "Ingrese la operacion a realizar: " << endl;
    cin >> operacion;
    Pila *stack;
    string simbolo;
    cout << "Agregando a la Pila" << endl;
    vector<string> Letras;
    for (int i = 0; i < operacion.size(); i++)
    {
        string simbolo = "";
        simbolo = operacion.substr(i, 1) + "";
        Letras.push_back(simbolo);
    }

    for (int i = 0; i < Letras.size(); i++)
    {
        Elemento *Apuntadorbase = new Elemento(Letras[i]);
        //   cout<<Apuntadorbase->getSimbolo()<<endl;
        if (i == 0)
        {
            Elemento *Apuntadorbase = new Elemento(Letras[i]);
            stack = new Pila(Apuntadorbase);
        }
        else
        {
            Elemento *Apuntadorbase = new Elemento(Letras[i]);
            stack->Apilar(Apuntadorbase);
        }
    }

    while (!stack->estaVacia())
    { 
        double total;
       Elemento* Valortrabajar= stack->desapilar();
       cout<<"Nuevo Ultimo:  "<<Valortrabajar->getSimbolo()<<endl;
       

    }
    
}