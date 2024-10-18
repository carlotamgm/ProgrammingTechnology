/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

public class Main
{
    public static void main(String[] args)
    {
        SumaNums prog1 = new SumaNums();
        prog1.listado();
        prog1.ejecucion();

        System.out.println();
        
        CuentaAtras prog2 = new CuentaAtras();
        prog2.listado();
        prog2.ejecucion();

        System.out.println();
        
        Factorial prog3 = new Factorial();
        prog3.listado();
        prog3.ejecucion();
    }
}