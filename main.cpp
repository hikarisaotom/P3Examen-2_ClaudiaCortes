/*LIbrerias*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Elemento.h"
#include "Pila.h"
#include <vector>
#include <fstream>
using namespace std;

vector<Pila *> Variables;
vector<string> DelArchivo;
void sumar(Pila *);
Pila *buscarletra(string);
bool boleanletra(string);
void leerarchivo();
Pila *generarstack(string);
int main()
{
    int respuesta = 0;
    leerarchivo();
    for (int i = 0; i < DelArchivo.size(); i++)
    {
        Pila *stack = generarstack(DelArchivo[i]);
        sumar(stack);
        Variables.push_back(stack);
    }
    while (respuesta != 1)
    {
        cout << "********************BIENVENIDO AL EXAMEN DE PROGRAMACION III***************************" << endl
             << " -> Tienes disponibles las variables A,B,C" << endl
             << " -> Claudia Patricia Cortes Pavon" << endl
             << " -> Lei del archivo, dame mi puntito :c" << endl;
        string operacion = "";
        cout << "Ingrese la operacion a realizar: " << endl;
        cin >> operacion;
        Pila *stack = generarstack(operacion);
        sumar(stack);
        // Variables.push_back(stack);
        cout << "Desea Continuar? (1 para salir, 0 continuar)" << endl;
        cin >> respuesta;

        /*  string operacion = "";
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
*/
    }
    for (int i = 0; i < Variables.size(); i++)
    {
        delete Variables[i];
    }
    Variables.clear();
    cout << "Saliendo del sistema......" << endl;
}

void sumar(Pila *stack)
{
    int cont = 0;
    double total;
    string simboloAnterior = "";
    int bandera;
    double valor;
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
        else if (simbolo != "=" && simbolo != stack->getnombre() && simbolo != "(" && simbolo != ")" && simbolo != "0" && simbolo != "1" && simbolo != "2" && simbolo != "3" && simbolo != "4" && simbolo != "5" && simbolo != "6" && simbolo != "7" && simbolo != "8" && simbolo != "9")
        {
            if (boleanletra(simbolo))
            {
                cout << "Encontro la letra;" << endl;
                valor += buscarletra(simbolo)->getvalor();
                cout << "" << valor << " simbolo " << buscarletra(simbolo)->getnombre() << endl;
                bandera = 16;
                continue;
            }
            else
            {

                bandera = 16;
                continue;
            }
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
    stack->setvalor(total + valor);
    cout << stack->getnombre() << " = " << stack->getvalor() << endl;
    Variables.push_back(stack);
}

Pila *buscarletra(string simbolo)
{
    for (int i = 0; i < Variables.size(); i++)
    {
        if (simbolo == Variables[i]->getnombre())
        {
            return Variables[i];
        }
    }
}

bool boleanletra(string simbolo)
{
    for (int i = 0; i < Variables.size(); i++)
    {
        if (simbolo == Variables[i]->getnombre())
        {
            return true;
        }
    }
    return false;
}

void leerarchivo()
{
    cout << "Leyendo del archivo....Dame mi extra :c Porfis" << endl;
    string file = "operaciones.txt";
    ifstream simbolos_archivo(file.c_str());

    //mientras hay lineas en el archivo
    if (simbolos_archivo.is_open())
    {
        while (!simbolos_archivo.eof())
        {
            //Leer una linea
            string line;
            getline(simbolos_archivo, line);
            if (line == ".")
            {
                break;
            }

            DelArchivo.push_back(line);
        }

        //cerrar al archivo}
        simbolos_archivo.close();
    }

    for (int i = 0; i < DelArchivo.size(); i++)
    {
        cout << i << " " << DelArchivo[i] << endl;
    }
}

Pila *generarstack(string operacion)
{
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

    return stack;
}