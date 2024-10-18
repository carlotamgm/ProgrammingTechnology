/*
    PRÁCTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

#include "Instruccion.h"

class Programa
{
protected:
    Instruccion** instrucciones;
    int size;

public:
    Programa(int s);
    ~Programa();
    void ejecucion();
    void listado() const;
};

class SumaNums : public Programa
{
public:
    SumaNums();
};

class CuentaAtras : public Programa
{
public:
    CuentaAtras();
};

class Factorial : public Programa
{
public:
    Factorial();
};