/*
	PRÁCTICA 1
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
	Coms: Programa que simula una sencilla calculadora de fracciones, 
		  empleando un tipo de datos Rational implementado mediante un struct.
*/

#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational a,b,r;
	char op;
	// int num;	// para comprobar que funcionan las operaciones con enteros

	// inicializaciones
	init(a);
	init(b);
	init(r);

	while (true)
	{
		cout << "? " << flush;

		read(a,cin);	// primer racional
		if (cin.fail())
			break;

		cin >> op;		// operación

		read(b,cin);		// segundo racional
		if (cin.fail())
			break;
		
		// Calculo del resultado
		switch(op) {
			case '+':
				r = a + b;
				break;
			case '-':
				r = a - b;
				break;
			case '*':
				r = a * b;
				break;
			case '/':
				r = a / b;
				break;
			default:
				cout << "Operación no válida" << endl;
				break;
		}

		// Escritura del resultado
		reduce(r);
		write(r, cout);
		cout << "\n" << flush;
	}

	return 0;
}

