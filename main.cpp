/*LIbrerias*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Elemento.h"
#include "Pila.h"
#include <vector>
using namespace std;
vector<Pila *> Variables;
void sumar(Pila *);
Pila *buscarletra(string);
int main()
{
    int respuesta = 0;

    while (respuesta != 1)
    {

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

        sumar(stack);
        Variables.push_back(stack);
        cout << "Desea Continuar? (1 para salir, 0 continuar)" << endl;
        cin >> respuesta;
    }
}

void sumar(Pila *stack)
{
    int cont = 0;
    double total;
    string simboloAnterior = "";
    int bandera;
    while (!stack->estaVacia())
    {

        Elemento *Valortrabajar = stack->desapilar();
        cout << "Nuevo Ultimo:  " << Valortrabajar->getSimbolo() << endl;
        string simbolo = Valortrabajar->getSimbolo();

        if (simbolo == "+")
        {
            bandera = 1;
            continue;
        }
        else if (simbolo == "-")
        {
            bandera = 2;
            continue;
        }
        else if (simbolo == "*")
        {
            bandera = 3;
            continue;
        }
        else if (simbolo == "/")
        {
            bandera = 4;
            continue;
        }
        else if (simbolo == "=" || simbolo == stack->getnombre() || simbolo == "(" || simbolo == ")")
        {
            bandera = 16;
            continue;
        }

        if (stoi(simbolo.c_str()) <= 9)
        {
            if (cont == 0)
            {
                total = stoi(simbolo.c_str());
                cont = 100;
                continue;
            }
        }

        switch (bandera)
        {
        case 1:
        { //+
            //  cout << simbolo << " = " << stoi(simbolo.c_str());
            total = total + stoi(simbolo.c_str());
            bandera = 16;
            break;
        }

        case 2:
        { //-
            //  cout << simbolo << " = " << stoi(simbolo.c_str());
            total = total - stoi(simbolo.c_str());
            bandera = 16;
            break;
        }

        case 3:
        { //*
            //  cout << simbolo << " = " << stoi(simbolo.c_str());
            total = total * stoi(simbolo.c_str());
            bandera = 16;
            break;
        }

        case 4:
        { // /
            //  cout << simbolo << " = " << stoi(simbolo.c_str());
            total = total / stoi(simbolo.c_str());
            bandera = 16;
            break;
        }

        } //fin del case.
    }     //FIn del while.
    stack->setvalor(total);
    cout << stack->getnombre() << " = " << stack->getvalor() << endl;
}

Pila *buscarletra(string simbolo)
{
    for (int i=0;i<Variables.size();i++)
    {
        if(simbolo==Variables[i]->getnombre()){
            return Variables[i];
        }
    }
}