#include "main.hpp"

#include <iostream>
#include <string>
#include <vector>

/* Escreva um algoritmo que solicite ao usuário três notas de N alunos em uma turma e ao final, apresente ao usuário:

* Versao 1: A quantidade de alunos na turma e a media aritmetica das notas de cada aluno
* Versao 2: Solicitar ao usuario a medida de aprovacao e quantidade provas e gerar relatorio com nome e as notas do
aluno
* Versao 3: Introduzir o campo sexo (M-masculino ou F-feminino) e gerar estatistica de aprovacao/reprovacao por sexto
* Versao 4: Apresentar os relatorios ordenadas por media aritmetica das notas
* Versao 5: Apresentar um menu de opcoes
* - 1: Relatorio de aprovados;
* - 2: Relatorio de reprovados; e
* - 3: Sair do programa.
*
* Inserir um gráfico em barra e apresentar a % dos alunos aprovados, sugestao do professor.
*/

int main() {
    // declacao de variaveis local
    int qtdTotalAluno = 0;
    int qtdTotalProva = 0;
    int contAluno = 0;
    float mediaAprovacao = 0;
    int totalAlunoM = 0;
    int totalAlunoAprovado = 0;

    // recebe o total de alunos
    std::cout << "Informe o total de alunos na turma: ";
    std::cin >> qtdTotalAluno;
    std::cout << std::endl;

    // recebe o total de provas da turma
    std::cout << "Informe o total de provas: ";
    std::cin >> qtdTotalProva;
    std::cout << std::endl;

    // recebe a media para aprovacao dos alunos
    std::cout << "Informe a media para aprovacao: ";
    std::cin >> mediaAprovacao;
    std::cout << std::endl;

    // aloca vetor de alunos
    std::vector<Aluno> alunos(qtdTotalAluno);

    // coleta dados
    while (contAluno < qtdTotalAluno) {
        std::cout << "Informe o nome do aluno " << contAluno + 1 << ": ";
        std::cin >> alunos[contAluno].nome;
        std::cout << std::endl;

        alunos[contAluno].nota.reserve(qtdTotalProva);
        float somaNotas = 0;
        for (int i = 0; i < qtdTotalProva; i++) {
            std::cout << "Informe a nota da " << i + 1 << "ª prova: ";
            std::cin >> alunos[contAluno].nota[i];
            std::cout << std::endl;

            somaNotas += alunos[contAluno].nota[i];
        }

        std::cout << "Informe o sexo do aluno, F ou M: ";
        std::cin >> alunos[contAluno].sexo.genero;
        toupper(alunos[contAluno].sexo.genero);
        std::cout << std::endl;

        alunos[contAluno].media = somaNotas / qtdTotalProva;
        alunos[contAluno].aprovado = alunos[contAluno].media >= mediaAprovacao;
        if (alunos[contAluno].aprovado)
            totalAlunoAprovado++;

        if (alunos[contAluno].sexo.genero == 'M')
            totalAlunoM++;

        // std::cout << "Aluno:\t\t\t" << alunos[contAluno].nome << std::endl;
        // std::cout << "\tMédia:\t\t" << alunos[contAluno].media << std::endl;
        // std::cout << "\tStatus:\t\t" << alunos[contAluno].aprovado << std::endl;

        contAluno++;
    }

    // apresentação
    return 0;
}
