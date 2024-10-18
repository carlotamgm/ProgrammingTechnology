/*
	PRÁCTICA 4
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include "nodo.h"
#include "casosError.h"
#include <list>

class Shell
{
private:
    unordered_map<string, shared_ptr<Directorio>> arbol;
    list<pair<string, shared_ptr<Directorio>>> ruta_activa;

public:
    Shell();

    string pwd();
    string ls();
    string du();
    void vi(string name, int size);
    void mkdir(string name);
    void cd(string path);
    void ln(string path, string name);
    int stat(string path);
    void rm(string path);
};
