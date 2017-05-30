/*Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados – 1/2017
Alunos: João Ricardo Ferreira Costa , Rafael Martins Diniz
Turma: B
Descricao: Trabalho Obrigatorio 02 -- Simulação de uma agenda telefônica. */

#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

struct agenda {
       int cod; //ESSA VARIAVEL É UM CODIGO QUE ACESSA A POSIÇÃO DO CONTATO NA LISTA. A PARTIR DELA, PODE-SE ACESSAR/MODIFICAR/CONSULTAR QUALQUER DADO DE UM CONTATO ATRAVÉS DO CÓDIGO DE ACESSO.
       char nome[30];
       char email[50];
       int tel;
       int vazio; //VAZIO = 0 e DISPONIVEL = 1.
} registros[100];

int aux=0;


void menu();
void cadastrar(int cod, int pos);
void consultar();
void editar();
void mostrar_lista();
int verifica_pos();
void ordenaNomes();
void instrucoes();
void zerar();
int verifica_cod(int cod);
void excluir();

int main() {

    zerar();
    printf("\n");
    instrucoes();

    int op=0, retorno, temp , posicao;

    while(op!=7){
        menu();
        printf("\n  > DIGITE A OPCAO DESEJADA:  ");
        scanf("%d", &op);

        if(op > 7 || op <= 0){
            printf("\n\n OPCAO INVALIDA!\n DIGITE A OPCAO DESEJADA:   \n\n");
            scanf("%d", &op);
        }

        system("cls");
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

            case 3: {          //FUNCAO PARA EDITAR UM USUARIO JA CADASTRADO
                editar();
            break;
            }

            case 4: {
                printf("\n >> EXCLUIR CONTATO\n");
                excluir();
            break;
            }

            case 5: {
                printf("\n\n >> LISTA DE CONTATOS\n\n");
                mostrar_lista();
            break;
            }

            case 6: {
                printf("\n\n >> LISTA DE CONTATOS ORDENADA\n\n");
                ordenaNomes();
            break;
            }

            case 7: {
                printf("\n\nSAINDO....\n\n");
            break;
            }
        }
    }

    getch();
}

void menu(){
    printf("\n\n <><><><><><>  -----   AGENDA TELEFONICA  ----- <><><><><><> \n\n");

    printf("                    [1] - CADASTRAR NOVO CONTATO\n\n");
    printf("                    [2] - CONSULTAR CONTATO\n\n");
    printf("                    [3] - EDITAR CONTATO\n\n");
    printf("                    [4] - EXCLUIR CONTATO\n\n");
    printf("                    [5] - MOSTRAR LISTA DE CONTATOS\n\n");
    printf("                    [6] - ORDENAR LISTA DE CONTATOS\n\n");
    printf("                    [7] - SAIR \n\n ");
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

void editar(){
    int i=0, cod;

    printf(" \n>> EDITAR CONTATO\n");

    printf("\n Informe o codigo do contato:");
    scanf("%d", &cod);
    getchar();

    while(i<=100) {
        if(registros[i].cod==cod){
            if(registros[i].vazio==1){
                printf("\nDigite o novo nome:\n\n");
                scanf("%[^\n]s", registros[i].nome);
                getchar();
                printf("Digite o novo telefone:\n\n");
                scanf("%d",&registros[i].tel);
                getchar();
                printf("Digite o novo e-mail:\n\n");
                scanf("%[^\n]s", registros[i].email);
                getchar();
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

    for(cont=0;cont<aux;cont++){
        if(registros[cont].vazio==1){
            printf("\nNome: %s\n", registros[cont].nome);
            printf("Codigo: %d\n", registros[cont].cod);
        }
    }
}

void ordenaNomes(){
    int i,j,cont;
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

       for(cont=0;cont<aux;cont++){
            if(registros[cont].vazio==1){
                printf("\nNome:%s\n", registros[cont].nome);
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

void instrucoes(){
    printf(" \n\n>> INSTRUCOES DE USO:\n\n");
    printf(" - Todo contato deve possuir um codigo.\n");
    printf(" - Sua agenda deve ter, no maximo, 100 contatos.\n");
    printf(" - Seus contatos devem possuir um nome, um telefone e um e-mail.\n");
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
