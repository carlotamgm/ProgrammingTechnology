/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

public abstract class Programa
{
    public Instruccion[] instrucciones;
    protected int size;

    public Programa(int s)
    {
        instrucciones = new Instruccion[s];
        size = s;
    }
    
    /*
        Empieza con una pila vacía y con el contador de programa a 0 
        (en la primera instrucción). El programa finalizará en cuanto 
        el contador de programa se quede fuera del rango válido del vector 
        (lo cual, habitualmente, ocurrirá por sobrepasar la última 
        instrucción del programa).
    */
    public void ejecucion()
    {
        Stack<Integer> pila = new Stack<Integer>();
        PC contador = new PC();

        System.out.println("Ejecucion:");

        while (contador.valor() >= 0 && contador.valor() < size) {
            instrucciones[contador.valor()].operacion(pila, contador);
        }
    }

    /*
        Muestra por la salida estándar (pantalla) todas las instrucciones 
        del programa junto a su número de línea (el que tiene el contador 
        del programa cuando la ejecuta).
    */
    public void listado()
    {
        System.out.println("Programa:");
        
        for (int i = 0; i < size; i++) {
            System.out.println( i + " " + instrucciones[i].nombre());
        }
    }
}