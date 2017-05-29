/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Algoritmos e Programação de Computadores – 1/2017

Alunos: João Ricardo Ferreira Costa, Rafael Martins Diniz
Turma: B

Descricao: Trabalho Obrigatorio 02 -- Simulação de uma agenda telefônica. */

#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

struct agenda {
       int cod;
       char nome[30];
       char email[50];
       int tel;
       int vazio; //VAZIO = 0 e DISPONIVEL = 1.
} registros[100];

int aux=0;

void menu();
void cadastrar(int cod, int pos);
void consultar();
void mostrar_lista();
int verifica_pos();
void ordenaNomes();
void zerar();
int verifica_cod(int cod);
void excluir();

main() {

    zerar();

    int op=0, retorno, temp , posicao;

    while(op!=5){
        menu();
        printf("\n  > DIGITE A OPCAO DESEJADA:  ");
        scanf("%d",&op);
        fflush(stdin);
        switch(op) {
            case 1: {                  // FUNCAO PARA CADASTRAR UM NOVO USUARIO
                posicao=verifica_pos();
                if (posicao!=-1) {
                printf("\n >>  INSERIR NOVO CONTATO\n");
                printf("\nInforme um codigo para esse contato: \n");
                scanf("%d",&temp);fflush(stdin);
                retorno=verifica_cod(temp);
                    if (retorno==1)
                        cadastrar(temp,posicao);
                    else
                        printf("\nCodigo ja existente ou nao existe!\n");
                }
                else
                    printf("\nA agenda esta cheia\n");
            break;
            }

            case 2: {                  //FUNCAO PARA CONSULTAR UM USUARIO EXISTENTE
                consultar();
            break;
            }

            case 3: {          //FUNCAO PARA EXCLUIR UM USUARIO JA CADASTRADO
                excluir();
            break;
            }

            case 4: {
                printf("\n >> LISTA DE CONTATOS\n");
                mostrar_lista();
            break;
            }
            case 5: {
                printf("\n\nSAINDO...\n\n");
            }

        }
}

getch();
}

void menu(){
    printf("\n\n <><><><><><>  -----   AGENDA TELEFONICA  ----- <><><><><><> \n\n");

    printf("                    [1] - CADASTRAR NOVO CONTATO\n\n");
    printf("                    [2] - CONSULTAR CONTATO\n\n");
    printf("                    [3] - EXCLUIR CONTATO\n\n");
    printf("                    [4] - MOSTRAR LISTA DE CONTATOS\n\n");
    printf("                    [5] - SAIR \n\n ");
}

void cadastrar(int cod, int pos) {

    pos=verifica_pos();

    registros[pos].cod=cod;

    printf("\nNome:\n");
    scanf("%[^\n]s", registros[pos].nome);
    getchar();
    printf("\nTelefone\n");
    scanf("%d",&registros[pos].tel);
    getchar();
    registros[pos].vazio=1;
    printf("\nE-mail:\n");
    scanf("%[^\n]s", registros[pos].email);
    getchar();

    printf("\n >> CONTATO CADASTRADO COM SUCESSO!\n\n");
}

void consultar() {
    int i=0, cod;
    //A VARIAVEL "i" FUNCIONA COMO UM CONTADOR. ELA É MAIS UTILIZADA DENTRO DE UM LOOP "FOR", NO ENTANTO EU TIVE PROBLEMAS COM O FOR E USEI ELA EM UM LOOP "WHILE".
    printf("\n >>  CONSULTAR CONTATO\n");


    printf("\nInforme o codigo do contato:\n");
    scanf("%d",&cod);

    while(i<=100) {
        if (registros[i].cod==cod) {
            if (registros[i].vazio==1) {
                printf(" >> DADOS DO CONTATO:\n");
                printf("\nNome: %s\n",registros[i].nome);
                printf("\nTelefone: %d\n",registros[i].tel);
                printf("\nE-mail: %s\n", registros[i].email);
            break;
            }
        }
        i++;
    }
    if(registros[i].cod!=cod){
            printf("\nOPS, ESSE CODIGO NAO FOI ENCONTRADO!\n");
        }
}

void mostrar_lista(){
    int i=0, cont;

    while(i<=100){
        if(registros[i].vazio==1){
            aux++;
        }
        i++;
    }

    ordenaNomes();

    for(cont=0;cont<aux;cont++){
        if(registros[cont].vazio==1){
            printf("\nNome: %s\n", registros[cont].nome);
            printf("Codigo: %d\n", registros[cont].cod);
        }
    }
}

void ordenaNomes(){
    int i,j;
    char aux2[30];


       for(i=1; i<aux; i++){
            for(j=i; j > 0 ; j--){
                if(strcoll(registros[j].nome, registros[j-1].nome) < 0){
                    strcpy(aux2, registros[j].nome);
                    strcpy(registros[j].nome, registros[j-1].nome);
                    strcpy(registros[j-1].nome, aux2);
                }
            }
       }

}

int verifica_pos() {
    int i=0;

    while (i<=100) {
        if (registros[i].vazio==0){
            return(i);
        }
        i++;
    }
    return(-1);
}

void zerar() {
    int i;
    for (i=0;i<=100;i++)
        registros[i].vazio=0;
}

int verifica_cod(int cod) {
    int i=0;
    while (i<=100) {
        if (registros[i].cod==cod)
        return(0);
    i++;
}
    return(1);
}

void excluir() {
    int cod, i=0;

    printf("\n >> EXCLUIR CONTATO \n");

    printf("\nInforme o codigo do contato que deseja excluir:\n");
    scanf("%d",&cod);


    while (i<=100) {
        if (registros[i].cod==cod)
            if (registros[i].vazio==1) {
                registros[i].vazio=0;
                printf("\n >> USUARIO EXCLUIDO COM SUCESSO!\n");
            break;
            }
        i++;
        if (i>100)
            printf("\nCodigo nao encontrado\n");
    }
}
