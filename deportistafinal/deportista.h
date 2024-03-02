#ifndef DEPORTISTA_H_INCLUDED
#define DEPORTISTA_H_INCLUDED

#include <string.h>
#include <stdio.h>
using namespace std;
class Deportista{
private:
int numeroDeSocio;
char nombre[ 15 ];
int edad;
char deporte[ 15 ];
char genero[15];

public:
Deportista( int = 0, string = "", int = 0, string = "", string = "");
void establecerNumeroDeSocio( int );
int obtenerNumeroDeSocio() const;
void establecerNombre( string );
string obtenerNombre() const;
void establecerEdad( int );
int obtenerEdad() const;
void establecerDeporte( string );
string obtenerDeporte() const;
void establecerGenero(string);
string obtenerGenero() const;

};

#endif // DEPORTISTA_H_INCLUDED
