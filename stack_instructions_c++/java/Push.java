/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

public class Push extends Instruccion
{
    protected int cte;

    public Push(int c)
    {
        cte = c;
    }
    
    /*
        Apila la constante cte (atributo de la clase) en la pila.
    */
    @Override
    protected void operacion(Stack<Integer> pila, PC contador)
    {
        pila.push(cte);

        contador.actualizar();
    }
    
    /*
        Devuelve una cadena de texto que representa la propia instrucción
    */
    @Override
    protected String nombre()
    {
        return "push";
    }
}
