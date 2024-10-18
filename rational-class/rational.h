/*
	PRÁCTICA 1
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
	Coms: la función de int+Rational no se puede poner dentro de la clase porque 
		  se llamaría igual que la de Rational+int.
		  Solución: sacar una de esas funciones de la clase
		  			En otros casos se le podría cambiar el nombre a una función pero, por la forma en que te dan
					este fichero, no se puede.
		  A las funciones de fuera de la clase, se les pone friend para q puedan usar los atributos privados
*/

#pragma once

#include <iostream>


// Solución con atributos privados.


class Rational
{
	// Miembros
	int num;
	int denom;

	// Funciones auxiliares
	/*
		Devuelve el máximo común divisor entre a y b
	*/
	static int mcd(int a, int b);
	/*
		Devuelve la fracción irreducible
	*/
	void reduce();

public:
	// Constructores
	/*
		Incialización con el valor por defecto 0/1
	*/
	Rational();
	/*
		Incialización a partir de dos enteros (num/den)
	*/
	Rational(int num, int den);


	// Operadores aritmeticos
	/*
		Suma dos Rational (el implícito y that) y 
		devuelve su fracción irreducible como Rational
	*/
	Rational operator+(const Rational& that) const;
	/*
		Suma el Rational implícito y un entero y 
		devuelve su fracción irreducible como Rational
	*/
	Rational operator+(int i) const;
	/*
		Suma un entero y un Rational y devuelve 
		su fracción irreducible como Rational
	*/
	friend Rational operator+(int i, const Rational& r);
	/*
		Resta dos Rational (el implícito y that) y 
		devuelve su fracción irreducible como Rational
	*/

	Rational operator-(const Rational& that) const;
	/*
		Resta el Rational implícito con un entero y 
		devuelve su fracción irreducible como Rational
	*/
	Rational operator-(int i) const;
	/*
		Resta un entero y un Rational y devuelve 
		su fracción irreducible como Rational
	*/
	friend Rational operator-(int i, const Rational& r);
	/*
		Multiplica dos Rational (el implícito y that) y 
		devuelve su fracción irreducible como Rational
	*/

	Rational operator*(const Rational& that) const;
	/*
		Multiplica el Rational implícito con un entero y 
		devuelve su fracción irreducible como Rational
	*/
	Rational operator*(int i) const;
	/*
		Multiplica un entero y un Rational y devuelve 
		su fracción irreducible como Rational
	*/
	friend Rational operator*(int i, const Rational& r);
	/*
		Divide dos Rational (el implícito y that) y 
		devuelve su fracción irreducible como Rational
	*/

	Rational operator/(const Rational& that) const;
	/*
		Divide el Rational implícito con un entero y 
		devuelve su fracción irreducible como Rational
	*/
	Rational operator/(int i) const;
	/*
		Divide un entero y un Rational y devuelve 
		su fracción irreducible como Rational
	*/
	friend Rational operator/(int i, const Rational& r);

		// Entrada - salida
	/*
		Muestra por pantalla un racional a través de un stream
	*/
	friend std::ostream& operator<<(std::ostream& os, Rational& r) ;

	/*
		Lee un racional a través de un stream
	*/
	friend std::istream& operator>>(std::istream& is, Rational& r) ;
};

// Operadores aritmeticos
/*
	Suma un entero y un Rational y devuelve 
	su fracción irreducible como Rational
*/
Rational operator+(int i, const Rational& r);
/*
	Resta un entero y un Rational y devuelve 
	su fracción irreducible como Rational
*/
Rational operator-(int i, const Rational& r);
/*
	Multiplica un entero y un Rational y devuelve 
	su fracción irreducible como Rational
*/
Rational operator*(int i, const Rational& r);
/*
	Divide un entero y un Rational y devuelve 
	su fracción irreducible como Rational
*/
Rational operator/(int i, const Rational& r);

// Entrada - salida
/*
	Muestra por pantalla un racional a través de un stream
*/
std::ostream& operator<<(std::ostream& os, Rational& r) ;

/*
	Lee un racional a través de un stream
*/
std::istream& operator>>(std::istream& is, Rational& r) ;