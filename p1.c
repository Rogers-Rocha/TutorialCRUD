#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

typedef struct Data tipoData;
typedef struct Disc tipoDisc;
struct Data{
    int dia;
    int mes;
    int ano;
};

struct Disc{
    char discplina[50];
    char professor[50];
    float notas[3];
    float media;
};

struct Aluno{
    char aluno[50];
    char endereco[70];
    int matricula;
    tipoData Data;
    tipoDisc Disc;
}Cadastro[max];

int menu(void), verificaLista(void);
void inicia(void), Cadastrar(void);

int main(void){
    
    system("pause");
    return 0;
} 

int menu(void){
    char opc[10];
    int opcao;
    fflush(stdin);

    printf("\n(1) - Cadastrar Aluno\n");
    printf("\n(2) - Listar Alunos\n");
    printf("\n(3) - Listar Alunos Aprovados\n");
    printf("\n(4) - Buscar Aluno por nome\n");
    printf("\n(5) - Buscar Aluno por disciplina\n");
    printf("\n(6) - Alterar Aluno\n");
    printf("\n(7) - Excluir Aluno\n");
    printf("\n(8) - Sair\n");

    do{
        printf("\n> ");
        fflush(stdout);
        fgets(opc, 10, stdin);

        opcao = atoi(opc);

    }while(opcao < 1 || opcao > 8);

    return opcao;
};

void inicia(void){
    register int i;
    for(i = 0; i < max; i++){ 
        Cadastro[i].aluno[0] = '\0';
    }
};

void Cadastrar(void){

}

int verificaLista(void){
    register int t;
    for(t = 0; t < max; t++){
        if(Cadastro[t].aluno[0] == '\0'){
            return t;
        }
    }
    return t;
};