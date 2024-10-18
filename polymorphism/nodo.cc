/*
	PRÁCTICA 4
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include "nodo.h"

Nodo::Nodo(const string& nom, int tam, const string& tipo)
    : name(nom), size(tam), type(tipo)
{}

/*
    Devuelve el nombre de un nodo
*/
string Nodo::nombre() const
{
    return name;
}

/*
    Devuelve el tamaño de un nodo
*/
int Nodo::tamano() const
{
    return size;
}

/*
    Devuelve el tipo de un nodo, es decir, si es un fichero, directorio o enlace
*/
string Nodo::tipo() const
{
    return type;
}

Directorio::Directorio(const string& nom)
    : Nodo(nom, 0, "Directorio")
{}

/*
    Añade item (ya sea fichero, directorio o enlace) al directorio
    y actualiza el tamaño de este último
*/
void Directorio::anadir(const shared_ptr<Nodo>& item, const string& tipo)
{
    elementos.insert({item->nombre(), item});
    if (tipo == "Directorio") {

        size++;

    } else {

        size += item->tamano();

    }
    item->tipo() = tipo;
}

/*
    Elimina item del directorio y actualiza el tamaño de este último
*/
void Directorio::eliminar(const shared_ptr<Nodo>& item)
{
    size -= item->tamano();
    elementos.erase(item->nombre());
}

/*
    Elimina todos los elementos (ficheros, directorios y enlaces) 
    del directorio
*/
void Directorio::eliminar()
{
    elementos.clear();
}

/*
    Devuelve un puntero al nodo llamado nombre si existe entre 
    los elementos del directorio. Sino devuelve nullptr
*/
shared_ptr<Nodo> Directorio::buscar(const string& nombre)
{
    for (auto i : elementos)
    {
        if (nombre == i.first)
        {
            return i.second;
        }
    }

    return nullptr;    // solo si no ha encontrado el elemento buscado
}

/*
    Devuelve una lista de los elementos del directorio y si el comando
    que la pide es "du", además devuelve el tamaño de cada elemento
*/
string Directorio::listado(const string& comando) const
{
    string resul;

    for (auto i : elementos)
    {
        resul += i.first;
        if (comando == "du")
        {
            resul += (", " + to_string(i.second->tamano()));
        }
        resul += "\n";
    }

    return resul;
}

Fichero::Fichero(const string& nom, int tam)
    : Nodo(nom, tam, "Fichero")
{}

/*
    Actualiza el tamaño de un fichero
*/
void Fichero::actualizarSize(int tam)
{
    size = tam;
}

Enlace::Enlace(const shared_ptr<Nodo>& nodo, const string& nom)
    : Nodo(nom, nodo->tamano(), "Enlace"), ref(nodo)
{}

/*
    Devuelve un puntero al nodo que hace referencia el enlace
*/
shared_ptr<Nodo> Enlace::referencia() const
{
    return ref;
}