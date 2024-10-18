/*
	PRÁCTICA 4
	Autoras: Carlota Moncasi (839841)
			 E. Lilai Naranjo (840091)
*/

class arbol_ficheros_error
{
public:
    virtual const char* what() const noexcept = 0;
};

class size_negativo : public arbol_ficheros_error
{
	const char* what() const noexcept override;
};

class ya_existe : public arbol_ficheros_error
{
	const char* what() const noexcept override;
};

class no_dir : public arbol_ficheros_error
{
	const char* what() const noexcept override;
};

class no_existe : public arbol_ficheros_error
{
	const char* what() const noexcept override;
};

class es_buc : public arbol_ficheros_error
{
	const char* what() const noexcept override;
};

class buc_infinito : public arbol_ficheros_error
{
	const char* what() const noexcept override;
};