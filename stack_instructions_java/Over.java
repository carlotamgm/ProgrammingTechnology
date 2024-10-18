/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

import java.util.Stack;

public class Over extends Instruccion
{
    /*
        Copia (apila) el valor que está tras la cima de la pila 
        (desapila dos valores, apila el segundo desapi￾lado, después 
        el primero y por último el segundo otra vez).
    */
    @Override
    protected void operacion(Stack<Integer> pila, PC contador)
    {
        int num1 = pila.pop();
        int num2 = pila.pop();
        
        pila.push(num2);
        pila.push(num1);
        pila.push(num2);
        
        contador.actualizar();
    }
    
    /*
        Devuelve una cadena de texto que representa la propia instrucción
    */
    @Override
    protected String nombre()
    {
        return "over";
    }
}