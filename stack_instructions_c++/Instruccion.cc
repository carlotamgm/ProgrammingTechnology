/*
    PRÁCTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

#include "Instruccion.h"

/*
    Pide un valor al usuario por la entrada estándar (indicando al usuario 
    de alguna forma que espera una entrada de datos) y lo apila en la pila.
*/
void Read::operacion(stack<int>& pila, int& contador)
{
    int num;

    cout << "? " << flush;
    cin >> num;
    
    pila.push(num);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Read::nombre() const
{
    return "read";
}

/*
    Desapila dos valores de la pila y apila su suma
*/
void Add::operacion(stack<int>& pila, int& contador)
{
    const int num1 = pila.top();
    pila.pop();
    const int num2 = pila.top();
    pila.pop();
    
    pila.push(num1 + num2);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Add::nombre() const
{
    return "add";
}

/*
    Desapila un valor de la pila y lo muestra por la salida 
    estándar (pantalla) al usuario.
*/
void Write::operacion(stack<int>& pila, int& contador)
{
    const int num = pila.top();
    pila.pop();
    
    cout << num << endl;

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Write::nombre() const
{
    return "write";
}

/*
    Constructor de la clase hija Push
*/
Push::Push(const int c) 
    : cte(c)
{}

/*
    Apila la constante cte (atributo de la clase) en la pila.
*/
void Push::operacion(stack<int>& pila, int& contador)
{
    pila.push(cte);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Push::nombre() const
{
    return "push";
}

/*
    Duplica la cima de la pila (desapila su valor y lo reapila dos veces).
*/
void Dup::operacion(stack<int>& pila, int& contador)
{
    const int cima = pila.top();
    pila.pop();
    
    pila.push(cima);
    pila.push(cima);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Dup::nombre() const
{
    return "dup";
}

/*
    Constructor de la clase hija Jumpif
*/
Jumpif::Jumpif(const int l) 
    : linea(l)
{}

/*
    Desapila la cima de la pila, y si su valor es mayor o igual que cero 
    salta la ejecución del programa a la línea linea (atributo de la clase).
*/
void Jumpif::operacion(stack<int>& pila, int& contador)
{
    const int cima = pila.top();
    pila.pop();

    if (cima >= 0) {
        contador = linea;
    } else {
        contador++;
    }
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Jumpif::nombre() const
{
    return "jumpif";
}

/*
    Desapila dos valores de la pila y apila su producto.
*/
void Mul::operacion(stack<int>& pila, int& contador)
{
    const int num1 = pila.top();
    pila.pop();
    const int num2 = pila.top();
    pila.pop();
    
    pila.push(num1*num2);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Mul::nombre() const
{
    return "mul";
}

/*
    Desapila dos valores de la pila y apila su producto.
*/
void Swap::operacion(stack<int>& pila, int& contador)
{
    const int num1 = pila.top();
    pila.pop();
    const int num2 = pila.top();
    pila.pop();
    
    pila.push(num1);
    pila.push(num2);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Swap::nombre() const
{
    return "swap";
}

/*
    Copia (apila) el valor que está tras la cima de la pila 
    (desapila dos valores, apila el segundo desapi￾lado, después 
    el primero y por último el segundo otra vez).
*/
void Over::operacion(stack<int>& pila, int& contador)
{
    const int num1 = pila.top();
    pila.pop();
    const int num2 = pila.top();
    pila.pop();
    
    pila.push(num2);
    pila.push(num1);
    pila.push(num2);

    contador++;
}

/*
    Devuelve una cadena de texto que representa la propia instrucción
*/
string Over::nombre() const
{
    return "over";
}