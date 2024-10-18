/*
    PRÁCTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

#include "Programa.h"

/*
    Constructor de la clase Programa
*/
Programa::Programa(int s)
    : instrucciones(new Instruccion*[s]), size(s) 
{}

/*
    Destructor de la clase Programa
*/
Programa::~Programa()
{
    delete[] instrucciones;
}

/*
    Empieza con una pila vacía y con el contador de programa a 0 
    (en la primera instrucción). El programa finalizará en cuanto 
    el contador de programa se quede fuera del rango válido del vector 
    (lo cual, habitualmente, ocurrirá por sobrepasar la última 
    instrucción del programa).
*/
void Programa::ejecucion()
{
    stack<int> pila;
    int contador = 0;

    cout << "Ejecucion:" << endl;

    while (contador >= 0 && contador < size) {
        instrucciones[contador]->operacion(pila, contador);
    }
}

/*
    Muestra por la salida estándar (pantalla) todas las instrucciones 
    del programa junto a su número de línea (el que tiene el contador 
    del programa cuando la ejecuta).
*/
void Programa::listado() const
{
    cout << "Programa:" << endl;
    
    for (int i = 0; i < size; i++) {
        cout << i << " " << instrucciones[i]->nombre() << endl;
    }
}

/*
    Calcula la suma de dos números introducidos por teclado y muestra 
    el resultado por pantalla.
*/
SumaNums::SumaNums()
    : Programa(4)
{
    instrucciones[0] = new Read();
    instrucciones[1] = new Read();
    instrucciones[2] = new Add();
    instrucciones[3] = new Write();
}

/*
    Pide al usuario un número, que asumiremos que es positivo y entero y
    muestra por pantalla una cuenta atrás desde ese número, de uno en uno 
    hasta llegar a cero.
*/
CuentaAtras::CuentaAtras()
    : Programa(7)
{
    instrucciones[0] = new Read();
    instrucciones[1] = new Dup();
    instrucciones[2] = new Write();
    instrucciones[3] = new Push(-1);
    instrucciones[4] = new Add();
    instrucciones[5] = new Dup();
    instrucciones[6] = new Jumpif(1);
}

/*
    Pide al usuario un número y calcula su factorial.
*/
Factorial::Factorial()
    : Programa(14)
{
    instrucciones[0] = new Push(1);
    instrucciones[1] = new Read();
    instrucciones[2] = new Swap();
    instrucciones[3] = new Over();
    instrucciones[4] = new Mul();
    instrucciones[5] = new Swap();
    instrucciones[6] = new Push(-1);
    instrucciones[7] = new Add();
    instrucciones[8] = new Dup();
    instrucciones[9] = new Push(-2);
    instrucciones[10] = new Add();
    instrucciones[11] = new Jumpif(2);
    instrucciones[12] = new Swap();
    instrucciones[13] = new Write();
}