struct struct_strcol
{
    int cont;
    int blocks;
    char **lista;
};
typedef struct struct_strcol StrCol;
/**
Inicia Colecao de Strings
*/
void inicia_col(StrCol *str);
/**
Insere String na colecao
*/
void insere_string(StrCol *str, char *s,int tam);
/**
Lista Colecao de String
*/
void listar_col(StrCol *str);
/**
 Zera a colecao de Strings
*/
void libera_col(StrCol *str);
/**
Remove String especifico da Colecao
*/
void remove_string(StrCol *str,int indice);

