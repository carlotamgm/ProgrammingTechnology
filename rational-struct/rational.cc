/*
	PRÁCTICA 1
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include "rational.h"

// Helper functions -----------------------
/*
   	Devuelve el máximo común divisor entre a y b
*/
int mcd(int a, int b) {
   return ( b == 0 ? a : mcd(b,a%b));
}

/*
   	Devuelve en r su fracción irreducible
*/
void reduce(Rational& r) {
	int div = mcd(r.num, r.denom);
	r.num /= div;
	r.denom /= div;
}

// Constructor -----------------------
/*
   	Incializa r con el valor por defecto 0/1
*/
void init(Rational& r) {
   r.num = 0;
   r.denom = 1;
}

/*
   	Incializa r a partir de dos enteros (num/den)
*/
void init(Rational& r, int num, int den) {
   r.num = num;
   r.denom = den;
}

// Input/output ---------------------------------
/*
   	Muestra por pantalla r a través de un stream
*/
void write(const Rational& r, std::ostream& os) {
	// opción 1
	/*
		os << "= ";
		if (r.num == r.denom) {
			os << "1";
		} else if (r.denom == 1) {
			os << r.num;
		}
	*/
	// opción 2
	os << "= " << r.num << "/" << r.denom;
}

/*
   	Lee a través de un stream y lo guarda en r
*/
void read(Rational& r, std::istream& is) {
	char barra;
	is >> r.num >> barra >> r.denom;
}

// Add -----------------------
/*
   	Devuelve la suma de dos Rational (r1 y r2) como Rational
*/
Rational operator+(const Rational& r1, const Rational& r2) {
	Rational res;
	res.denom = r1.denom * r2.denom;
	res.num = (res.denom / r1.denom) * r1.num 
			   + (res.denom / r2.denom) * r2.num;
	return res;
}

/*
   	Devuelve la suma de un Rational con un entero como Rational
*/
Rational operator+(const Rational& r, int i) {
	Rational res;
	res.num = r.denom * i + r.num;
	res.denom = r.denom;
	return res;
}

/*
   	Devuelve la suma de un entero con un Rational como Rational
*/
Rational operator+(int i, const Rational& r) {
	// el orden de los factores no altera al producto
	return r + i;
}

// Subtract -----------------------
/*
   Devuelve la resta de dos Rational (r1 y r2) como Rational
*/
Rational operator-(const Rational& r1, const Rational& r2) {
	Rational res;
	res.denom = r1.denom * r2.denom;
	res.num = (res.denom / r1.denom) * r1.num 
			   - (res.denom / r2.denom) * r2.num;
	return res;
}

/*
   Devuelve la resta de un Rational con un entero como Rational
*/
Rational operator-(const Rational& r, int i) {
	Rational res;
	res.num = r.num - r.denom * i;
	res.denom = r.denom;
	return res;
}

/*
   Devuelve la resta de un entero con un Rational como Rational
*/
Rational operator-(int i, const Rational& r) {
	Rational res;
	res.num = r.denom * i - r.num;
	res.denom = r.denom;
	return res;
}

// Multiply -------------------------
/*
   Devuelve la multiplicación de dos Rational (r1 y r2) como Rational
*/
Rational operator*(const Rational& r1, const Rational& r2) {
	Rational res;
	res.num = r1.num * r2.num;
	res.denom = r1.denom * r2.denom;
	return res;
}

/*
   Devuelve la multiplicación de un Rational con un entero como Rational
*/
Rational operator*(const Rational& r, int i) {
	Rational res;
	res.num = r.num * i;
	res.denom = r.denom;
	return res;
}

/*
   Devuelve la multiplicación de un entero con un Rational como Rational
*/
Rational operator*(int i, const Rational& r) {
	// el orden de los factores no altera al producto
	return r * i;
}

// Divide ------------------------------
/*
   Devuelve la división de dos Rational (r1 y r2) como Rational
*/
Rational operator/(const Rational& r1, const Rational& r2) {
	Rational res;
	res.num = r1.num * r2.denom;
	res.denom = r1.denom * r2.num;
	return res;
}

/*
   Devuelve la división de un Rational con un entero como Rational
*/
Rational operator/(const Rational& r, int i) {
	Rational res;
	res.num = r.num;
	res.denom = r.denom * i;
	return res;
}

/*
   Devuelve la división de un entero con un Rational como Rational
*/
Rational operator/(int i, const Rational& r) {
	Rational res;
	res.num = i * r.denom;
	res.denom = r.num;
	return res;
}
