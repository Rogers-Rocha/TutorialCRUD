#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

int ind = 0;
typedef struct Data tipoData;
typedef struct Disc tipoDisc;
struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Disc
{
    char disciplina[50];
    char professor[50];
    float notas[3];
    float media;
};

struct Aluno
{
    char aluno[50];
    int matricula;
    tipoData Data;
    tipoDisc Disc;
} Cadastro[max];

int menu(), verificaLista(), volt(), Cadastrar(int ind, int cad);
void disciplinas();
void inicia();
void listar(), listar_tudo(), exibirAprovados();
void buscarAluno(), pordisciplina();
void alterar(), remover();

int main()
{

    int opcao;
    int cad = 0;
    inicia();

    do
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            ind = Cadastrar(ind, cad);
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
        case 5:
            pordisciplina();
            break;
        case 6:
            alterar();
            break;
        case 7:
            remover();
            break;
        case 8:
            printf("\nSaindo do programa...\n");
            break;
        default:
            printf("\nOpcao nao implementada.\n");
            break;
        }
    } while (opcao != 8);

    system("pause");
    return 0;
}

int menu()
{
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

    do
    {
        printf("\nDigite a sua opcao: ");
        fflush(stdout);
        fgets(opc, 10, stdin);

        opcao = atoi(opc);

    } while (opcao < 1 || opcao > 8);

    return opcao;
}

void inicia()
{
    register int i;
    for (i = 0; i < max; i++)
    {
        Cadastro[i].aluno[0] = '\0';
    }
};



int Cadastrar(int ind, int cad)
{

    system("cls");
    int exit = 2;
    while (exit == 2)
    {
        if (ind < max)
        {
            printf("\nNumero de alunos cadastrados: %d/%d\n", ind, max);

            // printf("\nDigite a matricula do aluno: ");
            // fflush(stdout);
            // scanf("%d", &Cadastro[Cad].matricula);
            // getchar();

            printf("\nDigite o nome do aluno: ");
            fflush(stdout);
            fgets(Cadastro[ind].aluno, 50, stdin);
            Cadastro[ind].aluno[strcspn(Cadastro[ind].aluno, "\n")] = '\0';

            printf("\nDigite a data de nascimento (dd mm aaaa): ");
            fflush(stdout);
            scanf("%d %d %d", &Cadastro[ind].Data.dia, &Cadastro[ind].Data.mes, &Cadastro[ind].Data.ano);
            getchar();
            
            disciplinas();
            printf("\nDigite a sua disciplina: ");
            fflush(stdout);
            fgets(Cadastro[ind].Disc.disciplina, 50, stdin);
            Cadastro[ind].Disc.disciplina[strcspn(Cadastro[ind].Disc.disciplina, "\n")] = '\0';

            // // printf("\nProfessor: ");
            // // fflush(stdout);
            // // fgets(Cadastro[Cad].Disc.professor, 50, stdin);
            // // Cadastro[Cad].Disc.professor[strcspn(Cadastro[Cad].Disc.professor, "\n")] = '\0';

            for(int i = 0; i < 3; i++){
                float nota = -1;
                do{
                    printf("\nDigite a nota %d (entre 0 e 10): ", i + 1);
                    fflush(stdout);
                    char input[10];
                    fgets(input, 10, stdin);
                    nota = strtof(input, NULL);

                    if(nota < 0 || nota > 10){
                        printf("Nota invalida. Deve ser entre 0 e 10.\n");
                    }
                } while (nota < 0 || nota > 10);

                Cadastro[ind].Disc.notas[i] = nota;
            }

            Cadastro[ind].Disc.media = (Cadastro[ind].Disc.notas[0] + Cadastro[ind].Disc.notas[1] + Cadastro[ind].Disc.notas[2])/3;
            cad++;
            ind++;
        }
        else
        {
            printf("\nNao ha espaco para mais cadastros.\n");
        }
        system("cls");
        printf("-------------------------------------------------------");
        printf("\nExibicao dos dados armazenados no cadastro mais recente");
        for (int i = (ind - cad); i < ind; i++)
        {

            printf("\nIndice: %d\nAluno: %s\nNascimento: %d/%d/%d\nDisciplina: %s\nNotas: %3.2f| %3.2f| %3.2f|\nMedia: %.2f", i + 1, Cadastro[i].aluno, Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano, Cadastro[i].Disc.disciplina, Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
            printf("\n");
        }
        printf("\n");
        exit = volt();
    }
    return ind;
};

void disciplinas()
{
    printf("------------Disciplinas--------------");
    printf("\nPortugues\n");
    printf("\nMatematica\n");
    printf("\nProgramacao\n");
    printf("\nEconomia domestica\n");
    printf("-----------------------------------");
}

void listar()
{
    system("cls");
    int exit = 2;
    while(exit == 2){
        listar_tudo();
        exit = volt();
    }
    
}

void listar_tudo(){
    if (ind == 0)
    {
        printf("\nNao existe aluno cadastrado");
        return;
    }
    else
    {
        printf("-------------------------------------------------------");
        printf("\nExibicao de todos os dados armazenados");
        for (int i = 0; i < ind; i++)
        {
            printf("\nIndice: %d\nAluno: %s\nNascimento: %d/%d/%d\nDisciplina: %s\nNotas: %3.2f| %3.2f| %3.2f|\nMedia: %.2f", i + 1, Cadastro[i].aluno, Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano, Cadastro[i].Disc.disciplina, Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
            printf("\n");
        }
        printf("\nTotal de alunos cadastrados: %d\n", ind);
    }
}

void exibirAprovados()
{
    system("cls");
    float cont = 0, aprov;
    printf("-------------------------------------------------------");
    printf("\nExibicao dos alunos aprovados:\n");
    for (int i = 0; i < ind; i++)
    {
        if (Cadastro[i].Disc.media >= 7)
        {
            cont++;
            printf("\nAluno %d: %s aprovado com media %.2f", i + 1, Cadastro[i].aluno, Cadastro[i].Disc.media);
        }
    }
    if (ind > 0)
    {
        aprov = (cont / ind) * 100;
        printf("\n\n%.f%% da sala foi aprovada.\n", aprov);
    }
    else
    {
        printf("\n\nNao ha alunos cadastrados para calcular a porcentagem.\n");
    }
    
}

void buscarAluno()
{
    system("cls");
    int i = 0, exit = 2;
    char aluno2[40];

    while (exit == 2)
    {
        if (ind == 0)
        {
            printf("\nNenhum aluno cadastrado.\n");
            return;
        }
        printf("\nDigite o nome do aluno que deseja encontrar: ");
        fgets(aluno2, 40, stdin);
        aluno2[strcspn(aluno2, "\n")] = '\0';

        int encontrado = 0;
        for (i = 0; i < ind; i++)
        {
            if (strcmp(Cadastro[i].aluno, aluno2) == 0)
            {
                encontrado = 1;

                printf("\nO aluno '%s' possui id %d no cadastro.", aluno2, i + 1);
                printf("\nNotas: %.2f | %.2f | %.2f      Media: %.2f\n", Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
            }
        }

        if (encontrado == 0)
        {
            printf("\nO aluno '%s' nao foi encontrado.\n", aluno2);
        }
        exit = volt();
    }
}

void pordisciplina()
{
    system("cls");
    int i, exit = 2;
    char discip[40];

    while (exit == 2)
    {
        if (ind == 0)
        {
            printf("\nNenhuma disciplina cadastrada.\n");
            return;
        }
        disciplinas();
        printf("\nDigite a disciplina que deseja pesquisar: ");
        fgets(discip, 40, stdin);
        discip[strcspn(discip, "\n")] = '\0';

        int encontrado = 0;
        for (i = 0; i < ind; i++)
        {
            if (strcmp(Cadastro[i].Disc.disciplina, discip) == 0)
            {
                encontrado = 1;
                printf("\nDisciplina: %s", discip);
                printf("\nO aluno '%s' possui id %d no cadastro.", Cadastro[i].aluno, i + 1);
                printf("\nNotas: %.2f | %.2f | %.2f      Media: %.2f\n", Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2], Cadastro[i].Disc.media);
            }
        }

        if (encontrado == 0)
        {
            printf("\nNao foi encontrado aluno cadastrado na disciplina %s.\n", discip);
        }
        exit = volt();
    }
}

void alterar()
{
    system("cls");
    int exit = 2, encontrado = 0, alt;
    char aluno2[40];
    while (exit == 2)
    {
        listar_tudo();
        printf("\nDigite o nome do aluno que deseja alterar: ");
        fflush(stdout);
        fgets(aluno2, 50, stdin);
        aluno2[strcspn(aluno2, "\n")] = '\0';

        for (int i = 0; i < ind; i++)
        {
            if (strcmp(Cadastro[i].aluno, aluno2) == 0)
            {
                encontrado = 1;
                alt = i;
            }
        }

        if (encontrado)
        {
            int alte;
            printf("\nDeseja alterar o nome(1) ou as notas(2): ");
            scanf("%d", &alte);
            getchar();

            switch (alte)
            {
            case 1:
                printf("\nDigite o novo nome do aluno '%s': ",aluno2);
                fflush(stdout);
                fgets(Cadastro[alt].aluno, 50, stdin);
                Cadastro[alt].aluno[strcspn(Cadastro[alt].aluno, "\n")] = '\0';

                printf("\nO antigo nome '%s' foi alterado para '%s'\n", aluno2, Cadastro[alt].aluno);
                break;
            case 2:
                printf("\nDigite as novas notas do aluno %s: ", aluno2);
                scanf("%f %f %f", &Cadastro[alt].Disc.notas[0], &Cadastro[alt].Disc.notas[1], &Cadastro[alt].Disc.notas[2]);
                getchar();
                Cadastro[alt].Disc.media = (Cadastro[alt].Disc.notas[0] + Cadastro[alt].Disc.notas[1] + Cadastro[alt].Disc.notas[2]) / 3;
                printf("\nNovas notas: %3.2f| %3.2f| %3.2f\nMedia: %.2f\n", Cadastro[alt].Disc.notas[0], Cadastro[alt].Disc.notas[1], Cadastro[alt].Disc.notas[2], Cadastro[alt].Disc.media);
                break;
            default:
                printf("\nVoce apertou um numero diferente de 1 e 2...saindo do loop...");
                break;
            }
        }
        else
        {
            printf("\nAluno '%s' nao encontrado\n", aluno2);
        }
        printf("\n");
        exit = volt();
    }
}

void remover()
{
    system("cls");
    int lin = 0, encontrado = 0, exit = 2, pos = 0;
    char aluno2[40];
    while (exit == 2)
    {
        listar_tudo();
        printf("\nDigite o nome do aluno que deseja remover: ");
        fflush(stdout);
        fgets(aluno2, 40, stdin);
        aluno2[strcspn(aluno2, "\n")] = '\0';

        for (lin = 0; lin < ind; lin++)
        {
            if (strcmp(Cadastro[lin].aluno, aluno2) == 0)
            {
                encontrado = 1;
                pos = lin;
                break;
            }
        }

        if (encontrado)
        {
            for (int coluna = pos; coluna < ind - 1; coluna++)
                {
                    Cadastro[coluna] = Cadastro[coluna + 1];
            }
            ind--;
            system("cls");
            listar_tudo();
            printf("\nO aluno com o antigo id %d chamado '%s' foi removido.\n", pos + 1, aluno2);
        }
        else
        {
            printf("\nO aluno '%s' nao existe.\n", aluno2);
        }
        encontrado = 0;
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
        system("cls");
    case 2:
        system("cls");
        break;
    }

    return volt;
}

// gcc -o a p1.c
// .\a
//