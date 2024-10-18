/*
	PRÁCTICA 1
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include "rational.h"
#include <iostream>

// Helper methods -----------------------


/*
	Devuelve el máximo común divisor entre a y b
*/
int Rational::mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

/*
	Devuelve la fracción irreducible
*/
void Rational::reduce() {
	int div = mcd(num, denom);
	num /= div;
	denom /= div;
}

// Constructor -----------------------
/*
	Incialización con el valor por defecto 0/1
*/
Rational::Rational() 
	: num{}, denom(1)
{}

/*
	Incialización a partir de dos enteros (num/den)
*/
Rational::Rational(int num, int den)
	: num(num), denom(den)
{}



// Add -----------------------
/*
    Suma dos Rational (el implícito y that) y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator+(const Rational& that) const {
	Rational res;
	res.denom = denom * that.denom;
	res.num = (res.denom / denom) * num 
			   + (res.denom / that.denom) * that.num;
	res.reduce();
	return res;
}

/*
    Suma el Rational implícito y un entero y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator+(int i) const {
	Rational res;
	res.num = denom * i + num;
	res.denom = denom;
	res.reduce();
	return res;
}

/*
    Suma un entero y un Rational y devuelve 
   	su fracción irreducible como Rational
*/
Rational operator+(int i, const Rational& r) {
	// el orden de los factores no altera al producto
	return r + i;
}

// Subtract -----------------------
/*
    Resta dos Rational (el implícito y that) y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator-(const Rational& that) const {
	Rational res;
	res.denom = denom * that.denom;
	res.num = (res.denom / denom) * num 
			   - (res.denom / that.denom) * that.num;
	res.reduce();
	return res;
}

/*
    Resta el Rational implícito con un entero y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator-(int i) const {
	Rational res;
	res.num = num - denom * i;
	res.denom = denom;
	res.reduce();
	return res;
}

/*
   	Resta un entero y un Rational y devuelve 
	su fracción irreducible como Rational
*/
Rational operator-(int i, const Rational& r) {
	Rational res;
	res.num = r.denom * i - r.num;
	res.denom = r.denom;
	res.reduce();
	return res;
}

// Multiply -------------------------
/*
   	Multiplica dos Rational (el implícito y that) y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator*(const Rational& that) const {
	Rational res;
	res.num = num * that.num;
	res.denom = denom * that.denom;
	res.reduce();
	return res;
}

/*
   	Multiplica el Rational implícito con un entero y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator*(int i) const {
	Rational res;
	res.num = num * i;
	res.denom = denom;
	res.reduce();
	return res;
}

/*
   	Multiplica un entero y un Rational y devuelve 
   	su fracción irreducible como Rational
*/
Rational operator*(int i, const Rational& r) {
	// el orden de los factores no altera al producto
	return r * i;
}

// Divide ------------------------------
/*
    Divide dos Rational (el implícito y that) y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator/(const Rational& that) const {
	Rational res;
	res.num = num * that.denom;
	res.denom = denom * that.num;
	res.reduce();
	return res;
}

/*
   	Divide el Rational implícito con un entero y 
   	devuelve su fracción irreducible como Rational
*/
Rational Rational::operator/(int i) const {
	Rational res;
	res.num = num;
	res.denom = denom * i;
	res.reduce();
	return res;
}

/*
	Divide un entero y un Rational y devuelve 
	su fracción irreducible como Rational
*/
Rational operator/(int i, const Rational& r) {
	Rational res;
	res.num = i * r.denom;
	res.denom = r.num;
	res.reduce();
	return res;
}

// Input/output ---------------------------------
/*
	Muestra por pantalla un racional a través de un stream
*/
std::ostream& operator<<(std::ostream& os, Rational& r) {
	// opción 1
	/*
		os << "= ";
		if (num == denom) {
			os << "1";
		} else if (denom == 1) {
			os << num;
		}
	*/
	// opción 2

 	os << "= " << r.num << "/" << r.denom;
	return os;
}

/*
	Lee un racional a través de un stream
*/
std::istream& operator>>(std::istream& is, Rational& r) {
	int n,d;
	char barra;
	is >> n >> barra >> d;
	if (barra == '/')
		r = Rational(n,d);
	else 
		std::cout << "Error: no es un número racional" << std::endl;
	return is;
}
