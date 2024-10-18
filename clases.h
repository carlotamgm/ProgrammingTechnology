/*
	PRÁCTICA 3
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
    Coms: fichero que contiene las clases pedidas en el
          enunciado de la práctica:
            - Carga y CargaEspecial
            - Producto
            - SerVivo
            - Toxico
            - Contenedor
            - Camion
*/

#include "bases.h"

/***************************************** CARGAS **************************************************/

/*
    Clase que representa cualquier carga (producto o contenedor) que se puede 
    transportar dentro de un almacén (contenedor o camión). Pueden transportarse 
    en un contenedor para cargas estándar o directamente en un camión, y no pueden 
    introducirse en un contenedor para seres vivos o productos tóxicos.
*/
class Carga : public Item
{
public:
    Carga(const string& nombre, double volumen, double peso)
        : Item(nombre, volumen, peso)
    {}
};

/*
    Clase similar a la clase Carga pero que solo sirve para definir las
    cargas especiales: seres vivos y productos tóxicos. Sólo pueden ser 
    transportadas en un contenedor específico para dicha categoría (y 
    nunca directamente en un camión o en un contenedor general o de otro tipo).
*/
class CargaEspecial : public Item
{
protected:
	CargaEspecial(const string& nombre, double volumen, double peso)
		: Item(nombre, volumen, peso)
	{}
};

/*
    Clase que representa un producto definido mediante un nombre identificativo 
    (una cadena de texto), su volumen y su peso (valores predeterminados, definidos 
    al crearlo). 
*/
class Producto : public Carga
{
public:
	Producto(const string& nombre, double volumen, double peso)
		: Carga(nombre, volumen, peso)
	{}
};

/*
    Clase similar a la clase Producto pero que representa una carga especial,
    un ser vivo. Sólo pueden ser transportadas en un contenedor específico para 
    dicha categoría (y nunca directamente en un camión o en un contenedor general
    o de otro tipo).
*/
class SerVivo : public CargaEspecial
{
public:
	SerVivo(const string& nombre, double volumen, double peso)
		: CargaEspecial(nombre, volumen, peso)
	{}
	
    /*
        Devuelve el tipo del ítem correspondiente.
    */
	string tipo() const override
	{
		return " de Seres Vivos";
	}
};

/*
    Clase similar a la clase Producto pero que representa una carga especial,
    un producto tóxico. Sólo pueden ser transportadas en un contenedor específico 
    para dicha categoría (y nunca directamente en un camión o en un contenedor 
    general o de otro tipo).
*/
class Toxico : public CargaEspecial
{
public:
	Toxico(const string& nombre, double volumen, double peso)
		: CargaEspecial(nombre, volumen, peso)
	{}
	
    /*
        Devuelve el tipo del ítem correspondiente.
    */
	string tipo() const override
	{
		return " de Productos Toxicos";
	}
};

/*************************************** CONTENEDORES ***********************************************/

/*
    Clase que representa un contenedor estándar, con su correspondiente 
    capacidad (en metros cúbicos), que define también el volumen que ocupa.
    Dentro de un contenedor se puede introducir otro contenedor, siempre y 
    cuando no se supere su capacidad (tiene que ser, evidentemente más
    pequeño).
*/
template<class T>
class Contenedor : public Carga, public Transporte<T>
{	
public:
	Contenedor(double capacidad)
        : Carga("Contenedor", capacidad, 0.0), Transporte<T>(capacidad)
    {}

    /*
        Devuelve el peso de un contenedor, el cual es igual a la suma del 
        peso de todos los elementos contenidos (no tienen ningún límite de peso).
    */
    double peso() const override
    {
        double resul = 0.0;

        // sumamos el peso de todos los elementos que contiene
        for (auto i : this->items) {
            resul += i->peso();
        }

        return resul;
    }

    /*
        Devuelve un string con la información del contenido de un contenedor
        y de los ítems que contiene en su interior.
    */
    string mostrar() const override
    {
        stringstream ss;

        ss << nombre() << " [" << volumen() << " m3] [" << peso() << " kg]" << this->items.front()->tipo() << endl;

        for (auto i : this->items) {
            ss << "    ";
            if (i->tipo() != " de Carga Estandar") {
                ss << "  ";
            }
            ss << i->mostrar();
        }
        
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const Contenedor c)
    {
        os << c.mostrar();
        return os;
    }
};

/*************************************** CAMIÓN **********************************************/

/*
    Clase que representa un camión con su correspondiente capacidad. Dentro de 
    un camión se puede introducir un contenedor (siempre y cuando quepa en términos 
    de volumen). Un camión, sin embargo, no es un tipo de carga, y por tanto no 
    puede guardarse dentro de un contenedor ni dentro de otro camión.
*/
class Camion : public Item, public Transporte<Carga>
{
public:
    Camion(double capacidad)
        : Item("Camion", capacidad, 0.0), Transporte(capacidad)
    {}

    /*
        Devuelve el peso de un camion, el cual es igual a la suma del peso de todos 
        los elementos contenidos (no tienen ningún límite de peso).
    */
    double peso() const override
    {
        double resul = 0.0;

        // sumamos el peso de todos los elementos que contiene
        for (auto i : items) {
            resul += i->peso();
        }

        return resul;
    }

    /*
        Devuelve un string con la información del contenido de un camión
        y de los ítems que contiene en su interior.
    */
    string mostrar() const override
    {
        stringstream ss;

        ss << nombre() << " [" << volumen() << " m3] [" << peso() << " kg]" << endl;

        for (auto i : items) {
            ss << "  " << i->mostrar();
        }
        
        return ss.str();
    }

    friend ostream& operator<<(ostream& os, const Camion c)
    {
        os << c.mostrar();
        return os;
    }
};