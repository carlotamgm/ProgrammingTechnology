/*
	PRÁCTICA 3
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
    Coms: fichero que contiene clases auxiliares para implementar 
          las pedidas en el enunciado de la práctica:
            - Item
            - CargaEspecial
            - Transporte
*/

#include <string>
#include <list>
#include <sstream>

using namespace std;

/***************************************** ÍTEM ***************************************************/

/*
    Clase base que sirve para definir las clases Carga y Camion.
*/
class Item
{
protected:
    string nom;
    double vol;
    double pes;

    Item(const string& nombre, double volumen, double peso)
        : nom(nombre), vol(volumen), pes(peso)
    {}

public:
    /*
        Devuelve el nombre del ítem ("Camion" y "Contenedor" si se trata 
        de un camión o de un contenedor, respectivamente).
    */
    virtual string nombre() const
    {
        return nom;
    }

    /*
        Devuelve el volumen del ítem correspondiente.
    */
    virtual double volumen() const
    {
        return vol;
    }

    /*
        Devuelve el peso del ítem correspondiente.
    */
    virtual double peso() const
    {
        return pes;
    }

    /*
        Devuelve un string con la información del contenido de un ítem
        correspondiente: nombre, volumen en metros cúbicos y peso en kg.
    */
    virtual string mostrar() const
    {
        stringstream ss;

        ss << nombre() << " [" << volumen() << " m3] [" << peso() << " kg]" << endl;

        return ss.str();
    }

    /*
        Devuelve el tipo del ítem correspondiente.
    */
    virtual string tipo() const
    {
        return " de Carga Estandar";
    }
};

/****************************************** TRANSPORTE ***********************************************/

/*
    Clase base que sirve para definir las clases Contenedor y Camion.
*/
template<class T>
class Transporte
{
protected:
    double cap;
    list<T*> items;

    Transporte(double capacidad)
        : cap(capacidad)
    {}

public:
    /*
        Guarda el elemento que se le pasa como argumento (sea un producto 
        o un contenedor) si cabe según su capacidad. Si el elemento es guardado, 
        el método devolverá true, mientras que si no hay capacidad libre suficiente,
        el elemento no se guardará y el método devolverá false.
        Además, da un error de compilación si el elemento a guardar no es del tipo 
        adecuado al contenedor correspondiente (o al camión).
    */
    bool guardar(T* elemento)
    {
        bool cabe = true;
        double volum = 0.0;

        // calculamos el volumen actual
        for (auto i : this->items) {
            volum += i->volumen();
        }

        // comprobamos si cabría el nuevo elemento
        if (volum + elemento->volumen() > cap) {
            cabe = false;
        } else {    // cabe
            items.push_back(elemento);
        }
        
        return cabe;
    }
};