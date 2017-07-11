#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrCol.h"
/**
Protótipo de Agenda com uso de TAD;
Desenvolvedor:Felipe França Nogueira;
Matricula:1621313060;
Data:20/04/2017
*/

struct str_contato
{
    char nome[50];
    StrCol *email;
    StrCol *telefone;
};
/** Cria menu e recebe opção;*/
int menu()
{
    int opc;

    do
    {
        system("cls");
        printf("                        ****************************\n");
        printf("                        *        BEM VINDO         *\n");
        printf("                        *      A Melhor Agenda     *\n");
        printf("                        ****************************\n");
        printf("                        *    1-Adicionar Contato   *\n");
        printf("                        *    2-Listar Contatos     *\n");
        printf("                        *    3-Remover Contato     *\n");
        printf("                        *    4-Editar Contato      *\n");
        printf("                        *    5-Limpar Agenda       *\n");
        printf("                        *    6-Sair da Agenda      *\n");
        printf("                        ****************************\n");
        printf("                        Entre com a opcao desejada:");
        scanf("%i",&opc);
    }
    while(opc<0||opc>6);

    return opc;
}
/** Adicionar Contato*/
void add(struct str_contato **agenda,struct str_contato *contato,int cont)
{
    system("cls");
    contato->email=(StrCol*)malloc(sizeof(StrCol));
    contato->telefone=(StrCol*)malloc(sizeof(StrCol));

    char emailaux[200];
    int tamemail=0;
    char telaux[50];
    int tamtel=0;
    printf("*******************\n");
    printf("Contato %d\n",cont+1);
    printf("Nome:");
    scanf("%s",contato->nome);

    inicia_col(contato->email);
    printf("Email:");
    scanf("%s",emailaux);
    tamemail=strlen(emailaux);
    insere_string(contato->email,emailaux,tamemail);

    inicia_col(contato->telefone);
    printf("Telefone:");
    scanf("%s",telaux);
    tamtel=strlen(telaux);
    insere_string(contato->telefone,telaux,tamtel);

    agenda[cont]=contato;


}
/** Listar Contatos(ordem alfabetica)*/
void lista(struct str_contato **agenda,int cont)
{
    system("cls");

    int i;
    int j;
    struct str_contato *auxagenda;

    if(cont>0)
    {
        for(i=0; i<cont; i++)
        {
            for(j=i+1; j<cont; j++)
            {
                if(strcoll(agenda[i]->nome,agenda[j]->nome)>0)
                {
                    auxagenda=agenda[i];
                    agenda[i]=agenda[j];
                    agenda[j]=auxagenda;
                }
            }
        }
    }
    for(i=0; i<cont; i++)
    {
        printf("************************\n");
        printf("Contato %d\n",i+1);
        printf("Nome:%s\n",agenda[i]->nome);
        printf("Email:\n");
        listar_col(agenda[i]->email);
        printf("Telefone:\n");
        listar_col(agenda[i]->telefone);
        printf("************************\n");
    }
    if(cont==0)
    {
        printf("************************\n");
        printf("*      Agenda Vazia    *\n");
        printf("************************\n");
    }
    system("pause");
}
/** Remover Contato*/
int apaga(struct str_contato **agenda,struct str_contato *contato,int cont)
{
    system("cls");
    int i;
    int pos;

    if(cont>0)
    {
        for(i=0; i<cont; i++)
        {
            printf("************************\n");
            printf("Contato %d\n",i+1);
            printf("Nome:%s\n",agenda[i]->nome);
            printf("Email:\n");
            listar_col(agenda[i]->email);
            printf("Telefone:\n");
            listar_col(agenda[i]->telefone);
            printf("************************\n");
        }
        printf("Digite a posicao que deseja apagar:");
        scanf("%i",&pos);
        if(cont>=pos-1)
        {
            free(agenda[pos-1]);
            for(i=pos-1; i<cont; i++)
            {
                agenda[i]=agenda[i+1];
            }
            return 1;
        }
    }
    printf("!!Nao existe contatos na lista ainda!!\n");
    system("pause");
    return 0;

}
/** Editar Contato*/
void edita_contato(struct str_contato **agenda,struct str_contato *contato,int cont)
{
    system("cls");
    int pos_esc;
    int i;
    int selec;
    int pos;

    if(cont>0)
    {
        for(i=0; i<cont; i++)
        {
            printf("************************\n");
            printf("Contato %d\n",i+1);
            printf("Nome:%s\n",agenda[i]->nome);
            printf("Email:\n");
            listar_col(agenda[i]->email);
            printf("Telefone:\n");
            listar_col(agenda[i]->telefone);
            printf("************************\n");
        }
        printf("Digite a posicao que deseja editar:");
        scanf("%i",&pos);
        if(cont>=pos-1)
        {
            while(selec!=5)
            {
                contato=agenda[pos-1];
                system("cls");
                printf("************************\n");
                printf("Contato %d\n",pos);
                printf("Nome:%s\n",agenda[pos-1]->nome);
                printf("Email:\n");
                listar_col(agenda[pos-1]->email);
                printf("Telefone:\n");
                listar_col(agenda[pos-1]->telefone);
                printf("************************\n");
                printf("****************************\n");
                printf("*    1-Adicionar Email     *\n");
                printf("*    2-Excluir Email       *\n");
                printf("*    3-Adicionar Telefone  *\n");
                printf("*    4-Remover Telefone    *\n");
                printf("*    5-Sair da edicao      *\n");
                printf("****************************\n");
                printf("                        Entre com a opcao desejada:");

                char straux[200];
                int tamanhostr;
                scanf("%i",&selec);

                switch(selec)
                {

                case 1:
                    printf("****************************\n");
                    printf("*Email %d:",(pos));
                    scanf("%s",straux);
                    tamanhostr=strlen(straux);
                    insere_string(contato->email,straux,tamanhostr);
                    agenda[i]=contato;
                    break;

                case 2:
                    system("cls");
                    printf("************************\n");
                    printf("Contato %d\n",i+1);
                    printf("Nome:%s\n",contato->nome);
                    printf("Email:\n");
                    listar_col(contato->email);
                    printf("************************\n");
                    printf("Qual e o email que deseja apagar(posicao):");
                    scanf("%d",&pos_esc);
                    if(contato->email->cont>=pos_esc)
                    {
                        remove_string(contato->email,pos_esc);
                    }
                    else
                    {
                        printf("Posicao inexistente");
                    }
                    break;

                case 3:
                    printf("****************************\n");
                    printf("*Telefone %d:",(contato->telefone->cont+1));
                    scanf("%s",straux);
                    tamanhostr=strlen(straux);
                    insere_string(contato->telefone,straux,tamanhostr);
                    agenda[i]=contato;
                    break;

                case 4:
                    system("cls");
                    printf("************************\n");
                    printf("Contato %d\n",i+1);
                    printf("Nome:%s\n",contato->nome);
                    printf("Telefone:\n");
                    listar_col(contato->telefone);
                    printf("************************\n");
                    printf("Qual e o telefone que deseja apagar(posicao):");
                    scanf("%d",&pos_esc);
                    if(contato->telefone->cont>=pos_esc)
                    {
                        remove_string(contato->telefone,pos_esc);
                    }
                    else
                    {
                        printf("Posicao inexistente");
                    }

                    break;

                case 5:
                    break;
                }
            }
        }
    }
    else
    {
        printf("************************\n");
        printf("*      Agenda Vazia    *\n");
        printf("************************\n");
        system("pause");
    }
}
/** Limpa totalmente a agenda*/
void limpa_agenda(struct str_contato **agenda,int cont)
{
    int i;
    system("cls");
    if(cont>0)
    {
        for(i=cont-1; i>=0; i--)
        {
            libera_col(agenda[i]->email);
            libera_col(agenda[i]->telefone);
            free(agenda[i]);
        }
        printf("Todos os contatos deletados\n");
        system("pause");
    }
    else
    {
        printf("************************\n");
        printf("*      Agenda Vazia    *\n");
        printf("************************\n");
        system("pause");
    }

}
int main()
{
    /**Iniciando Structs*/
    struct  str_contato **agenda;
    struct str_contato *contato;
    /**Variaves*/
    int cont=0;
    int block=10;
    int opc;
    /**Alocando dinamicamente*/
    agenda = (struct str_contato**) malloc(block*sizeof(struct str_contato*));
    /**Iniciando a parte ao Usuario*/
    do
    {
        system("cls");
        opc=menu();
        contato = (struct str_contato*) malloc(sizeof(struct str_contato));
        switch(opc)
        {
        case 1:
            add(agenda,contato,cont);
            cont++;
            break;
        case 2:
            lista(agenda,cont);
            break;
        case 3:
            if(apaga(agenda,contato,cont)==1)
            {
                cont--;
            }
            break;
        case 4:
            edita_contato(agenda,contato,cont);
            break;
        case 5:
            limpa_agenda(agenda,cont);
            if (cont>0)
            {
                cont=0;
            }
            break;
        }
        if(cont==block)
        {
            block+=10;
            agenda = (struct str_contato**) realloc(agenda,block*sizeof(struct str_contato*));
        }
    }
    while(opc!=6);

    /**Limpa a tela\despede o usuario\encera programa*/
    system("cls");
    printf("               ********************************************\n");
    printf("               *        A MELHOR AGENDA DO MUNDO          *\n");
    printf("               *             Volte sempre!!!              *\n");
    printf("               ********************************************\n");
    return 0;
}
