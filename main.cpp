#include <stdio.h>

// Escreva um algoritmo que solicite ao usuário três notas de N alunos em uma turma
// e ao final, apresente ao usuário:

// Versão 1: A quantidade de alunos na turma e a média aritmética das notas de cada aluno
// Versão 2: Solicitar ao usuário a medida de aprovação e quantidade provas e gerar relatório com
// 			nome e as notas do aluno
// Versão 3: Introduzir o campo sexo (M-masculino ou F-feminino) e gerar
//			estatística de aprovação/reprovação por sexto
// Versão 4: Apresentar os relatorios ordenadas por media aritmetica das notas

#define APROVADO 6

struct sexo {
    char genero;
};

struct aluno {
    char nome[30];
    float nota[3];
    struct sexo sexo;
    bool aprovado;
};

int qtdAluno = 0;

int main() {
    // declação de variaveis
    aluno turma[100];
    char resposta;

    // coleta dos dados
    do {
        qtdAluno += 1;
        printf("Informe o nome do aluno %i. Aluno:", qtdAluno);
        scanf("%s", &turma[qtdAluno].nome);

        for (int nota = 1; nota <= 3; nota++) {
            printf("Informe as notas do aluno %i: ", qtdAluno);
            scanf("%f", &turma[qtdAluno].nota[nota]);
            // Estamos usando a primeira posição do vetor para acumular
            // a soma das notas.
            turma[qtdAluno].nota[0] += turma[qtdAluno].nota[nota];
        }

        // if ternário
        turma[qtdAluno].aprovado = turma[qtdAluno].nota[0] / 3 >= APROVADO;

        printf("Informe o sexo do aluno %i: ", qtdAluno);
        scanf("%s", &turma[qtdAluno].sexo.genero);


        printf("Deseja informar o proximo aluno: (S/N)");
        scanf("%s", &resposta);
    } while (resposta == 's' or resposta == 'S');
    // processamento dos dados

    // apresentação dos dados
}
