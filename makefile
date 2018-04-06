#build
EXE: main.o Pila.o Elemento.o
	g++ main.o Pila.o Elemento.o -o EXE 

#main
main.o: main.cpp Pila.h Elemento.h
	g++ -c main.cpp      
#Pila
Pila.o: Pila.cpp Pila.h Elemento.h 
	g++ -c Pila.cpp
#Elemento
Elemento.o: Elemento.cpp Elemento.h
	g++ -c Elemento.cpp
