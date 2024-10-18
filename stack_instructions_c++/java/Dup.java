/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

public class Dup extends Instruccion
{
    /*
        Duplica la cima de la pila (desapila su valor y lo reapila dos veces).
    */
    @Override
    protected void operacion(Stack<Integer> pila, PC contador)
    {
        int cima = pila.pop();
        pila.push(cima);
        pila.push(cima);

        contador.actualizar();
    }

    /*
        Devuelve una cadena de texto que representa la propia instrucción
    */
    @Override
    protected String nombre()
    {
        return "dup";
    }
}