/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;
import java.util.Scanner;

public class Read extends Instruccion
{
    /*
        Pide un valor al usuario por la entrada estándar (indicando al usuario 
        de alguna forma que espera una entrada de datos) y lo apila en la pila.
    */
    @Override
    protected void operacion(Stack<Integer> pila, PC contador)
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("? ");
        int num = sc.nextInt();
        pila.push(num);
    
        contador.actualizar();
    }

    /*
        Devuelve una cadena de texto que representa la propia instrucción
    */
    @Override
    protected String nombre()
    {
        return "read";
    }
}