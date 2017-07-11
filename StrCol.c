#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrCol.h"
#define quant 10

void inicia_col(StrCol *str)
{
    str->cont=0;
    str->blocks=quant;
    str->lista=(char**)malloc(str->blocks*sizeof(char*));
    if(str==NULL||str->lista==NULL)
    {
        printf("Nao ha espaco!!\n");
        system("pause");
        exit(1);
    }
}

void insere_string(StrCol *str, char *s,int tam)
{
    char *string;
    string = (char*)malloc(tam*sizeof(char));
    strcpy(string,s);
    str->lista[str->cont]=string;
    str->cont+=1;
    if(str->cont>=str->blocks)
    {
        str->blocks+=quant;
        str->lista=(char**)realloc(str->lista,str->blocks*sizeof(char*));
    }
}

void listar_col(StrCol *str)
{
    int i;
    for(i=0; i<str->cont; i++)
    {
        printf("%s,\n",str->lista[i]);
    }
}

void remove_string(StrCol *str,int indice)
{
    int i,j;
    free(str->lista[indice-1]);
    for(i=indice-1; i<str->cont-1; i++)
    {
        j=i+1;
        str->lista[i]=str->lista[j];
    }
    str->cont--;
}

void libera_col(StrCol *str)
{
    int i;
    for(i=str->cont; i>=0; i--)
    {
        str->lista[i]=NULL;
    }
    free(str);
}
