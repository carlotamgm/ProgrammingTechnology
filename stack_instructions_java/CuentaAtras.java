/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

public class CuentaAtras extends Programa
{
    public CuentaAtras()
    {
        super(7);
        instrucciones[0] = new Read();
        instrucciones[1] = new Dup();
        instrucciones[2] = new Write();
        instrucciones[3] = new Push(-1);
        instrucciones[4] = new Add();
        instrucciones[5] = new Dup();
        instrucciones[6] = new Jumpif(1);
    }
}