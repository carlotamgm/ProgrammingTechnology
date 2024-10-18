/*
	PRÁCTICA 1
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#pragma once

#include <iostream>

// Solucion con atributos publicos.

struct Rational
{
   friend void init(Rational& r);
   friend void init(Rational& r,int num, int den);
   friend void write(const Rational& r, std::ostream& os);
   friend void read(Rational& r, std::istream& is);
   friend Rational operator+(const Rational& r1, const Rational& r2);
   friend Rational operator+(const Rational& r, int i);
   friend Rational operator+(int i, const Rational& r);
   friend Rational operator-(const Rational& r1, const Rational& r2);
   friend Rational operator-(const Rational& r, int i);
   friend Rational operator-(int i, const Rational& r);
   friend Rational operator*(const Rational& r1, const Rational& r2);
   friend Rational operator*(const Rational& r, int i);
   friend Rational operator*(int i, const Rational& r);
   friend Rational operator/(const Rational& r1, const Rational& r2);
   friend Rational operator/(const Rational& r, int i);
   friend Rational operator/(int i, const Rational& r);

   private:
      int num;
      int denom;
      
      // funciones auxiliares
      int mcd(int a, int b);
      friend void reduce(Rational& r);
};

/*
   Devuelve el máximo común divisor entre a y b
*/
int mcd(int a, int b);
/*
   Devuelve en r su fracción irreducible
*/
void reduce(Rational& r);

/*
   Incializa r con el valor por defecto 0/1
*/
void init(Rational& r);
/*
   Incializa r a partir de dos enteros (num/den)
*/
void init(Rational& r,int num, int den);

// Entrada - salida
/*
   Muestra por pantalla r a través de un stream
*/
void write(const Rational& r, std::ostream& os);
/*
   Lee a través de un stream y lo guarda en r
*/
void read(Rational& r, std::istream& is);

// Operaciones aritmeticas
/*
   Devuelve la suma de dos Rational (r1 y r2) como Rational
*/
Rational operator+(const Rational& r1, const Rational& r2);
/*
   Devuelve la suma de un Rational con un entero como Rational
*/
Rational operator+(const Rational& r, int i);
/*
   	Devuelve la suma de un entero con un Rational como Rational
*/
Rational operator+(int i, const Rational& r);

/*
   Devuelve la resta de dos Rational (r1 y r2) como Rational
*/
Rational operator-(const Rational& r1, const Rational& r2);
/*
   Devuelve la resta de un Rational con un entero como Rational
*/
Rational operator-(const Rational& r, int i);
/*
   Devuelve la resta de un entero con un Rational como Rational
*/
Rational operator-(int i, const Rational& r);

/*
   Devuelve la multiplicación de dos Rational (r1 y r2) como Rational
*/
Rational operator*(const Rational& r1, const Rational& r2);
/*
   Devuelve la multiplicación de un Rational con un entero como Rational
*/
Rational operator*(const Rational& r, int i);
/*
   Devuelve la multiplicación de un entero con un Rational como Rational
*/
Rational operator*(int i, const Rational& r);

/*
   Devuelve la división de dos Rational (r1 y r2) como Rational
*/
Rational operator/(const Rational& r1, const Rational& r2);
/*
   Devuelve la división de un Rational con un entero como Rational
*/
Rational operator/(const Rational& r, int i);
/*
   Devuelve la división de un entero con un Rational como Rational
*/
Rational operator/(int i, const Rational& r);


