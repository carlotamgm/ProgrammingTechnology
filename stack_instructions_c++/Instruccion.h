/*
    PRÁCTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

#include <stack>
#include <iostream>

using namespace std;

/*
    Clase base que representa una instrucción que puede ejecutarse.
*/
class Instruccion
{
public:
    virtual void operacion(stack<int>& pila, int& contador) = 0;
    virtual string nombre() const = 0;
};

class Read : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Add : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Write : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Push : public Instruccion
{
public:
    Push(const int c);

protected:
    int cte;

    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Dup : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Jumpif : public Instruccion
{
public:
    Jumpif(const int l);

protected:
    int linea;

    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Mul : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Swap : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};

class Over : public Instruccion
{
protected:
    void operacion(stack<int>& pila, int& contador) override;
    string nombre() const override;
};