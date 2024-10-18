/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

public class Jumpif extends Instruccion
{
    protected int linea;

    public Jumpif(int l)
    {
        linea = l;
    }

    /*
        Desapila la cima de la pila, y si su valor es mayor o igual que cero 
        salta la ejecución del programa a la línea linea (atributo de la clase).
    */
    @Override
    protected void operacion(Stack<Integer> pila, PC contador)
    {
        int cima = pila.pop();
        if (cima >= 0){
            contador.actualizar(linea);
        } else {
            contador.actualizar();
        }
    }

    /*
        Devuelve una cadena de texto que representa la propia instrucción
    */
    @Override
    protected String nombre()
    {
        return "jumpif";
    }
}