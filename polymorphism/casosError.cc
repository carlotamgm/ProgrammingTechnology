/*
	PRÁCTICA 4
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

#include "casosError.h"

const char* size_negativo::what() const noexcept
{
    return "Se ha introducido un tamaño negativo";
}

const char* ya_existe::what() const noexcept
{
    return "Ya existe un nodo con el mismo nombre";
}

const char* no_dir::what() const noexcept
{
    return "El directorio buscado no existe";
}

const char* no_existe::what() const noexcept
{
    return "El nodo buscado no existe";
}

const char* es_buc::what() const noexcept
{
    return "Se ha podido entrar en un bucle";
}

const char* buc_infinito::what() const noexcept
{
    return "Se ha detectado un bucle infinito";
}