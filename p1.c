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
    
    int opcao;
    inicia();

    do{
        opcao = menu();
        switch(opcao){
            case 1:
                Cadastrar();
                break;
            case 8:
                printf("\nSaindo do programa...\n");
                break;
            default:
                printf("\nOpcao nao implementada.\n");
                break;
        }
    }while(opcao != 8);

    system("pause");
    return 0;
} 

int menu(void){
    char opc[10];
    int opcao;
    fflush(stdin);

    printf("--------------Menu----------------");
    printf("\n(1) - Cadastrar Aluno\n");
    printf("\n(2) - Listar Alunos\n");
    printf("\n(3) - Listar Alunos Aprovados\n");
    printf("\n(4) - Buscar Aluno por nome\n");
    printf("\n(5) - Buscar Aluno por disciplina\n");
    printf("\n(6) - Alterar Aluno\n");
    printf("\n(7) - Excluir Aluno\n");
    printf("\n(8) - Sair\n");
    printf("-----------------------------------");

    do{
        printf("\nDigite a sua opcao: ");
        fflush(stdout);
        fgets(opc, 10, stdin);

        opcao = atoi(opc);

    }while(opcao < 1 || opcao > 8);

    return opcao;
}

void inicia(void){
    register int i;
    for(i = 0; i < max; i++){ 
        Cadastro[i].aluno[0] = '\0';
    }
};

void Cadastrar(void){
    
    system("cls");
    int Cad;
    
    Cad = verificaLista();

    if(Cad >= max){
        printf("\nNao ha espaco para mais cadastros.\n");
        return;
    }

    printf("\nO numero de alunos cadastrados: %d/%d", Cad, max);

    printf("\nDigite a matricula do aluno: ");
    fflush(stdout);
    scanf("%d", &Cadastro[Cad].matricula);
    getchar();

    printf("\nDigite o nome do aluno: ");
    fflush(stdout);
    fgets(Cadastro[Cad].aluno, 50, stdin);
    Cadastro[Cad].aluno[strcspn(Cadastro[Cad].aluno, "\n")] = '\0';

    printf("\nDigite o endereco do aluno: ");
    fflush(stdout);
    fgets(Cadastro[Cad].endereco, 70, stdin);
    Cadastro[Cad].endereco[strcspn(Cadastro[Cad].endereco, "\n")] = '\0';

    printf("\nDigite a data de nascimento: (dd mm aaaa) ");
    fflush(stdout);
    scanf("%d %d %d", &Cadastro[Cad].Data.dia, &Cadastro[Cad].Data.mes, &Cadastro[Cad].Data.ano);
    getchar();

    printf("\nDiciplina: ");
    fflush(stdout);
    fgets(Cadastro[Cad].Disc.discplina, 50, stdin);
    Cadastro[Cad].Disc.discplina[strcspn(Cadastro[Cad].Disc.discplina, "\n")] = '\0';

    printf("\nProfessor: ");
    fflush(stdout);
    fgets(Cadastro[Cad].Disc.professor, 50, stdin);
    Cadastro[Cad].Disc.professor[strcspn(Cadastro[Cad].Disc.discplina, "\n")] = '\0';

    printf("\nDigite as 3 notas do aluno: ");
    fflush(stdout);
    scanf("%f %f %f", &Cadastro[Cad].Disc.notas[0], &Cadastro[Cad].Disc.notas[1], &Cadastro[Cad].Disc.notas[2]);
    printf("\n");

};

int verificaLista(void){
    register int t;
    for(t = 0; t < max; t++){
        if(Cadastro[t].aluno[0] == '\0'){
            return t;
        }
    }
    return max;
};