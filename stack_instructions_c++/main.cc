/*
    PRÁCTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
    Coms: Programa que implementa una máquina virtual que emula un 
          nuevo microcontrolador de tipo pila y que permite experimentar 
          con el juego de instrucciones y hacer análisis de eficiencia 
          sobre el mismo. Un microcontrolador de pila consta como memoria 
          a corto plazo de una única pila, y todas las instrucciones del 
          juego de instrucciones están diseñadas para coger sus operandos 
          de la pila (desapilándolos, pop) y para devolver su resultado en 
          la propia pila (apilándolos, push). El microcontrolador trabaja 
          únicamente con enteros de 32 bits (tipo int) y por tanto todas 
          las operaciones trabajan con ese tipo de datos.
*/

#pragma once

#include "Programa.h"

int main()
{
    SumaNums prog1;
    prog1.listado();
    prog1.ejecucion();

    cout << endl;

    CuentaAtras prog2;
    prog2.listado();
    prog2.ejecucion();

    cout << endl;

    Factorial prog3;
    prog3.listado();
    prog3.ejecucion();
}