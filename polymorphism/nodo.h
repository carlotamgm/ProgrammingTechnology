/*
	PRÁCTICA 4
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include <iostream>
#include <unordered_map>
#include <memory>

using namespace std;

class Nodo {
protected:
    string name;
    int size;
    string type;

    Nodo(const string& nom, int tam, const string& tipo);

public:
    string nombre() const;
    int tamano() const;
    string tipo() const;
};

class Directorio : public Nodo {
private:
    unordered_map<string, shared_ptr<Nodo>> elementos;

public:
    Directorio(const string& nom);

    void anadir(const shared_ptr<Nodo>& item, const string& tipo);
    void eliminar(const shared_ptr<Nodo>& item);
    void eliminar();
    shared_ptr<Nodo> buscar(const string& nombre);
    string listado(const string& comando) const;
};

class Fichero : public Nodo {
public:
    Fichero(const string& nom, int tam);

    void actualizarSize(int tam);
};

class Enlace : public Nodo {
private:
    shared_ptr<Nodo> ref;

public:
    Enlace(const shared_ptr<Nodo>& nodo, const string& nom);

    shared_ptr<Nodo> referencia() const;
};