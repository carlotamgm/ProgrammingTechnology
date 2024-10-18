/*
	PRÁCTICA 1
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
	Coms: Programa que simula una sencilla calculadora de fracciones, 
		  empleando un tipo de datos Rational implementado mediante una clase.
*/

#include "rational.h"
#include <iostream>

using namespace std;

int main()
{
	Rational a,b,r;
	char op;
	// int num;	// para comprobar que funcionan las operaciones con enteros

	while (true)
	{
		cout << "? " << flush;

		cin >> a;		// primer racional
		if (cin.fail())
			break;

		cin >> op;		// operación

		cin >> b;		// segundo racional
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
		cout << r << endl;
		cout << "\n" << flush;
	}

	return 0;
}
