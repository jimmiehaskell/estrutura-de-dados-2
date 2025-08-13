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

// strucs
struct Sexo {
    char genero;
};

struct Aluno {
    std::string nome;
    std::vector<float> nota;
    Sexo sexo;
    bool aprovado;
    float media;
};


int main() {
    // declacao de variaveis local
    int qtdTotalAluno=0;
    int qtdTotalProva=0;
    int contAluno=0;
    float mediaAprovacao=0;

    // recebe o total de alunos
    std::cout << "Informe o total de alunos na turma: " << std::endl;
    std::cin >> qtdTotalAluno;

    // recebe o total de provas da turma
    std::cout << "Informe o total de provas: " << std::endl;
    std::cin >> qtdTotalProva;

    // recebe a media para aprovacao dos alunos
    std::cout << "Informe a media para aprovacao: " << std::endl;
    std::cin >> mediaAprovacao;

    // aloca vetor de alunos
    Aluno alunos[qtdTotalAluno];

    // coleta dos dados
    do {
        contAluno += 1;
        std::cout << "Informe o nome do aluno " << contAluno << " Aluno: " << std::endl;
        std::cin >> alunos[contAluno].nome;

        // garantindo que a posicao ZERO do vetor notas é 0
        alunos[contAluno].nota[0] = 0;
        for (int nota=1; nota<=qtdTotalProva; nota++) {
            float notaAluno;
            std::cout << "Informe as notas do aluno " << nota << ": " << std::endl;
            std::cin >> notaAluno;
            alunos[contAluno].nota[nota] = notaAluno;
            // Estamos usando a primeira posição do vetor para acumular
            // a soma das notas.
            alunos[contAluno].nota[0] += alunos[contAluno].nota[nota];
        }

        // if ternario?? tirar dúvida com o professor
        alunos[contAluno].aprovado = alunos[contAluno].nota[0] / qtdTotalAluno >= mediaAprovacao;

        std::cout << "Informe o sexo do aluno " << contAluno << ": " << std::endl;
        std::cin >> alunos[contAluno].sexo.genero;
    } while (contAluno <= qtdTotalAluno);
    // processamento dos dados

    // apresentação dos dados
}
