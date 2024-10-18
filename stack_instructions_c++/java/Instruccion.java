/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

/*
    Clase base que representa una instrucción que puede ejecutarse.
*/
public abstract class Instruccion
{
    protected abstract void operacion(Stack<Integer> pila, PC contador);
    protected abstract String nombre();
}
