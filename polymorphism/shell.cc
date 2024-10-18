/*
	PRÁCTICA 4
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include "shell.h"
#include <sstream>
#include <algorithm>

Shell::Shell()
{
	arbol.insert({"/", make_shared<Directorio>("/")});		// se crea el primer directorio del arbol
	auto root = arbol.find("/");
	ruta_activa.push_back(make_pair(root->first, root->second));		// se añade a la ruta activa
}

/*
	Devuelve la ruta completa de forma textual, con todos los nombres 
	de los directorios desde la raíz hasta el directorio actual concatenados 
	y separados por el separador '/'
*/
string Shell::pwd()
{
	string ruta;
	int cont = 0;

	for (const auto& i : ruta_activa)
	{
		if (cont > 1)
		{
			ruta += "/";
		}
		ruta += i.first;

		cont++;
	}

	return ruta;
}

/*
	Devuelve un listado con el nombre de todos los nodos contenidos en la ruta actual, 
	uno por línea
*/
string Shell::ls()
{
	return ruta_activa.back().second->listado("ls");
}

/*
	Devuelve un listado con el nombre y el tamaño de todos los nodos contenidos en la 
	ruta actual, uno por línea.
*/
string Shell::du()
{
	return ruta_activa.back().second->listado("du");
}

/*
	Edita el fichero de nombre 'name' (en el directorio actual). Para simular la edición, 
	simplemente se cambia el tamaño del fichero al valor especificado como parámetro. 
	Si el fichero no existe, se debe crear con el nombre y tamaño especificados.
*/
void Shell::vi(string name, int size)
{
	if (size < 0)		// un fichero no puede tener un tamaño negativo
	{
		throw size_negativo();
	}

	auto dir = arbol.find(ruta_activa.back().first);		// directorio actual
	auto elem = dir->second->buscar(name);		// fichero a añadir o editar

	if (elem != nullptr) {		// existe

		if (elem->tipo() != "Fichero")		// dos nodos distintos no pueden tener el mismo nombre
		{
			throw ya_existe();
		}

		shared_ptr<Fichero> fich = static_pointer_cast<Fichero>(elem);
		fich->actualizarSize(size);

	} else {		// no existe

		shared_ptr<Fichero> nuevo = make_shared<Fichero>(name, size);
		dir->second->anadir(nuevo, "Fichero");

	}
}

/*
	Crea un directorio de nombre 'name' en el directorio activo.
*/
void Shell::mkdir(string name)
{
	auto dir = arbol.find(ruta_activa.back().first);		// directorio actual
	auto elem = dir->second->buscar(name);			// directorio a crear

	if (elem != nullptr)	// existe
	{
		throw ya_existe();
	}

	shared_ptr<Directorio> nuevo = make_shared<Directorio>(name);
	dir->second->anadir(nuevo, "Directorio");			// se añade como subdirectorio
	arbol.insert({name, nuevo});		// se anota en el arbol como directorio existente
}

/*
	Hace que la ruta activa pase a referenciar a otro directorio.
	La nueva ruta activa definida en 'path' debe referenciar un directorio o 
	un enlace a un directorio.
*/
void Shell::cd(string path)
{
	if (path != ".")		// no seguimos en el directorio actual
	{
		if (path == "/") {		// se vuelve al directorio raíz
			
			ruta_activa.clear();
			auto root = arbol.find("/");
			ruta_activa.push_back(make_pair(root->first, root->second));

		} else if (path == ".." && ruta_activa.back().first != "/") {		// se vuelve al directorio anterior (padre)

			ruta_activa.pop_back();

		} else {

			string elem = path;

			if (path[0] == '/')		// ruta absoluta (desde raíz)
			{
				path.erase(0, 1);
				cd("/");		// volvemos al raíz
			}

			// nueva ruta
			stringstream f(path);
			while (getline(f, elem, '/'))
			{
				path.erase(0, elem.length());		// eliminamos el directorio que vamos a añadir a ruta_activa

				if (elem == ".." || elem == ".") {

					cd(elem);

				} else {
					
					auto nodo = ruta_activa.back().second->buscar(elem);		// nodo al que cambiar
					if (nodo == nullptr)
					{
						throw no_existe();
					}

					if (nodo->tipo() == "Directorio") {		// añadimos en ruta_activa
						
						shared_ptr<Directorio> aux = static_pointer_cast<Directorio>(nodo);
						ruta_activa.push_back(make_pair(elem, aux));

					} else if (nodo->tipo() == "Enlace") {		// vamos al nodo que apunta el enlace

						int cont = 0;
						shared_ptr<Enlace> link = static_pointer_cast<Enlace>(nodo);

						while (link->referencia()->tipo() == "Enlace" && cont < 16)		// cadena de enlaces
						{
							cont++;
							link = static_pointer_cast<Enlace>(link->referencia());
						}
						
						if (cont == 16) {		// hemos podido entrar en bucle

							throw es_buc();

						} else if (link->referencia()->tipo() != "Directorio") {	// es un fichero
						
							throw no_dir();

						} 
						
						cd(link->referencia()->nombre());

					} else {		// es un fichero

						throw no_dir();

					}
				}
			}
		}
	}
}

/*
	Crea en el directorio actual un enlace simbólico de nombre 'name' que apunta 
	al elemento identificado mediante la ruta especificada en 'path', que puede 
	ser de cualquier tipo. El nombre 'name' es un nombre simple de nodo (se creará 
	en el directorio activo), por lo que no puede contener una ruta completa.
	La ruta definida en 'path' sí, de tal modo que se puede crear un enlace a un 
	elemento en otro directorio del árbol, que debe existir previamente.
*/
void Shell::ln(string path, string name)
{
	string dir_actual = pwd();
	auto dir = arbol.find(ruta_activa.back().first);
	shared_ptr<Nodo> link;
	string nodo;


	if (path == "." || (path == "/") || (path == "..") ) {		// enlace al directorio actual/raíz/anterior que crearía un bucle infinito
		throw buc_infinito();
	
	} else {
		bool encontrado=false;
		string dir = "";

		int i = dir_actual.find_last_of("/");

		while( dir!="/" && i>0 ) {

			i = dir_actual.find_last_of("/");
			if (i !=dir_actual.npos)
			{
				dir=dir_actual;
				if (dir==path) { //el path al que se quiere hacer link está por encima y crearía un bucle infinito
					encontrado=true;
					throw buc_infinito();
				}
				dir = dir_actual.substr(0, i);		// quitamos el último nodo
			}


		} 


		if(!encontrado ) { //el path al que se quiere hacer link está por debajo

			int i = path.find_last_of("/");
			if (i != path.npos)
			{
				string dir = path.substr(0, i);		// quitamos el último nodo
				path = path.substr(i+1);		// último nodo
				cd(dir);
			}

			auto elem = ruta_activa.back().second->buscar(path);
			if (elem == nullptr)	// no se ha encontrado el nodo
			{
				cd(dir_actual);
				throw no_existe();
			}

			cd(dir_actual);
			link = make_shared<Enlace>(elem, name);
		}

	}

	dir->second->anadir(link, "Enlace");

}

/*
	Devuelve el tamaño del nodo que referencia el path.
*/
int Shell::stat(string path)
{
	string dir_actual = pwd();
	if (path == ".") {		// directorio actual

		return ruta_activa.back().second->tamano();

	} else if (path == "..") {		// directorio anterior

		ruta_activa.pop_back();
		return stat(".");

	} else {

		int i = path.find_last_of("/");
		if (i != path.npos)
		{
			string dir = path.substr(0, i);		// quitamos el último nodo
			path = path.substr(i+1);		// último nodo
			cd(dir);
		}

		auto elem = ruta_activa.back().second->buscar(path);
		if (elem == nullptr)	// no se ha encontrado el nodo
		{
			throw no_existe();
		}

		if (elem->tipo() == "Enlace") {

			int cont = 0;
			shared_ptr<Enlace> link = static_pointer_cast<Enlace>(elem);

			while (link->referencia()->tipo() == "Enlace" && cont < 16)		// cadena de enlaces
			{
				cont++;
				link = static_pointer_cast<Enlace>(link->referencia());
			}
			
			if (cont == 16)		// hemos podido entrar en bucle
			{
				throw es_buc();
			}

			stat(link->referencia()->nombre());

		} else {

			cd(dir_actual);
			return elem->tamano();

		}

	}
}

/*
	Elimina un nodo. Si es un fichero, es simplemente eliminado. Si es un enlace, elimina 
	el enlace pero no el nodo referenciado. Si es un directorio, elimina el directorio y 
	todo su contenido. Si existen enlaces al elemento borrado, ese elemento sigue siendo 
	accesible a traves del enlace (todavía existe), pero no a través de su ubicación original 
	(que ha sido eliminada).
*/
void Shell::rm(string path)
{
	string dir_actual = pwd();
	int i = path.find_last_of("/");
	if (i != path.npos)
	{
		string dir = path.substr(0, i);		// quitamos el último nodo
		path = path.substr(i+1);		// último nodo
		cd(dir);
	}

	auto elem = ruta_activa.back().second->buscar(path);
	if (elem == nullptr)	// no se ha encontrado el nodo
	{
		cd(dir_actual);
		throw no_existe();
	}

	if (elem->tipo() == "Fichero" || elem->tipo() == "Enlace") {

		ruta_activa.back().second->eliminar(elem);

	} else {		// es un directorio
		
		cd(elem->nombre());
		ruta_activa.back().second->eliminar();		// eliminamos su contenido
		ruta_activa.pop_back();
		ruta_activa.back().second->eliminar(elem);		// eliminamos la referencia de la ruta activa
		arbol.erase(elem->nombre());		// eliminamos la referencia del arbol

	}

	cd(dir_actual);
}