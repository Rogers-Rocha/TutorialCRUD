#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

int ind = 0;
char alunos_cadastrados[max][40];
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
    int matricula;
    tipoData Data;
    tipoDisc Disc;
}Cadastro[max];

int menu(void), verificaLista(void), volt(), Cadastrar(int fim, int Cad);
void inicia(void);
void listar(void), exibirAprovados(void);
void buscarAluno(void);

int main(void){
    
    int opcao, Cad = 0;
    inicia();

    do{
        opcao = menu();
        switch(opcao){
            case 1:
                ind = Cadastrar(ind, Cad);
                break;
            case 2:
                listar();
                break;
            case 3:
                exibirAprovados();
                break;
            case 4:
                buscarAluno();
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

int Cadastrar(int ind, int Cad){
    
    system("cls");
    int exit = 2;
    while(exit == 2){
        if(ind < max){
            printf("\nNumero de alunos cadastrados: %d/%d\n", ind, max);

            // printf("\nDigite a matricula do aluno: ");
            // fflush(stdout);
            // scanf("%d", &Cadastro[Cad].matricula);
            // getchar();

            printf("\nDigite o nome do aluno: ");
            fflush(stdout);
            fgets(Cadastro[ind].aluno, 50, stdin);
            Cadastro[ind].aluno[strcspn(Cadastro[ind].aluno, "\n")] = '\0';

            strcpy(alunos_cadastrados[Cad], Cadastro[ind].aluno);
            Cad++;

            printf("\nDigite a data de nascimento (dd mm aaaa): ");
            fflush(stdout);
            scanf("%d %d %d", &Cadastro[ind].Data.dia, &Cadastro[ind].Data.mes, &Cadastro[ind].Data.ano);
            getchar();

            // printf("\nDiciplina: ");
            // fflush(stdout);
            // fgets(Cadastro[Cad].Disc.discplina, 50, stdin);
            // Cadastro[Cad].Disc.discplina[strcspn(Cadastro[Cad].Disc.discplina, "\n")] = '\0';

            // printf("\nProfessor: ");
            // fflush(stdout);
            // fgets(Cadastro[Cad].Disc.professor, 50, stdin);
            // Cadastro[Cad].Disc.professor[strcspn(Cadastro[Cad].Disc.discplina, "\n")] = '\0';

            printf("\nDigite as 3 notas do aluno: ");
            fflush(stdout);
            scanf("%f %f %f", &Cadastro[ind].Disc.notas[0], &Cadastro[ind].Disc.notas[1], &Cadastro[ind].Disc.notas[2]);
            Cadastro[ind].Disc.media = (Cadastro[ind].Disc.notas[0] + Cadastro[ind].Disc.notas[1] + Cadastro[ind].Disc.notas[2])/3;
            ind++;
        }else{
            printf("\nNao ha espaco para mais cadastros.\n");
        }
        system("cls");
        printf("-------------------------------------------------------");
        printf("\nExibicao dos dados armazenados apenas nesse cadastro");
        for(int i = 0; i < Cad; i++){

            printf("\nId: %d\nAluno: %s\nNascimento: %d/%d/%d\nNotas: %3.2f| %3.2f| %3.2f|\nMedia: %.2f", i + 1, Cadastro[i].aluno, Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano, Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
            printf("\n");
        }
        printf("\n");
        exit = volt();
    }
    return ind;
};

void listar(void){
    system("cls");
    int i, exit = 2;
    while (exit == 2)
    {
        if(ind == 0){
            printf("\nNao existe aluno cadastrado");
            return;
        }else{
            printf("-------------------------------------------------------");
            printf("\nExibicao de todos os dados armazenados");
            for(i = 0; i < ind; i++){
                printf("\nId: %d\nAluno: %s\nNascimento: %d/%d/%d\nNotas: %3.2f| %3.2f| %3.2f|\nMedia: %.2f\n", i + 1, Cadastro[i].aluno, Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano, Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
            }
            printf("\nTotal de alunos cadastrados: %d\n", ind);
        }
        exit = volt();
    }
}

void exibirAprovados(void){
    system("cls");
    float cont = 0, aprov; 
    printf("-------------------------------------------------------");
    printf("\nExibicao dos alunos aprovados:\n");
    for(int i = 0; i < ind; i ++){
        if(Cadastro[i].Disc.media >= 7){
            cont++;
            printf("\nAluno %d: %s aprovado com media %.2f", i + 1, Cadastro[i].aluno, Cadastro[i].Disc.media);
        }
    }
    if (ind > 0) {
        aprov = (cont/ind)*100;
        printf("\n\n%.f%% da sala foi aprovada.\n", aprov);
    } else {
        printf("\n\nNao ha alunos cadastrados para calcular a porcentagem.\n");
    }
}

void buscarAluno(void){
    system("cls");
    int i = 0, pos, exit = 2;
    char aluno2[40];

    while (exit == 2) {
        if (ind == 0) {
            printf("\nNenhum aluno cadastrado.\n");
            return;
        }
        printf("\nDigite o nome do aluno que deseja encontrar: ");
        fgets(aluno2, 40, stdin);
        aluno2[strcspn(aluno2, "\n")] = '\0'; 

        int encontrado = 0; 
        for (i = 0; i < ind; i++) {
            if (strcmp(Cadastro[i].aluno, aluno2) == 0) {
                encontrado = 1;
                

                printf("\nO aluno '%s' possui id %d no cadastro.", aluno2, i + 1);
                printf("\nNotas: %.2f | %.2f | %.2f      Media: %.2f\n", Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
                
            }
        }

        if (encontrado == 0) {
            printf("\nO aluno '%s' nao foi encontrado.\n", aluno2);
        }

        exit = volt(); 
    }
}



int volt()
{
    int volt;
    printf("\nDeseja voltar ao menu? 1(sim), 2(nao): ");
    scanf("%d", &volt);
    getchar();

    switch (volt)
    {
    case 1:
        printf("\n");
    case 2:
        break;
    }

    return volt;
}

// gcc -o a p1.c
// .\a
// 