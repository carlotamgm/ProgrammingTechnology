/*
    PRACTICA 2
    Autoras: Carlota Moncasi y E. Lilai Naranjo
    NIPs: 839841 y 840091
*/

public class PC
{
    private int cont;

    public PC()
    {
        cont = 0;
    }

    /*
        Aumenta en uno cont
    */
    public void actualizar()
    {
        cont++;
    }

    /*
        Aumenta en v cont
    */
    public void actualizar(int v)
    {
        cont = v;
    }

    /*
        Devuelve el valor de cont
    */
    public int valor()
    {
        return cont;
    }
}