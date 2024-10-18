/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

public class Write extends Instruccion
{
    /*
        Desapila un valor de la pila y lo muestra por la salida 
        estándar (pantalla) al usuario.
    */
    @Override
    protected void operacion(Stack<Integer> pila, PC contador)
    {
        int num = pila.pop();
        System.out.println(num);

        contador.actualizar();
    }

    /*
        Devuelve una cadena de texto que representa la propia instrucción
    */
    @Override
    protected String nombre()
    {
        return "write";
    }
}
