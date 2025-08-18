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
    float media;
    bool aprovado;
};


int main() {
    // declacao de variaveis local
    int qtdTotalAluno=0;
    int qtdTotalProva=0;
    int contAluno=0;
    float mediaAprovacao=0;

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
        // TODO nomeAluno, 'for()' notaProva, sexo aluno
        contAluno++;
        std::cout << "Informe o nome do aluno " << contAluno << ": ";
        std::cin >> alunos[contAluno].nome;
        std::cout << std::endl;

        alunos[contAluno].nota.reserve(qtdTotalProva);
        float somaNotas = 0;
        for (int i=0; i<qtdTotalProva; i++) {
            std::cout << "Informe a nota da " << i << "ª prova: ";
            std::cin >> alunos[contAluno].nota[i];
            std::cout << std::endl;

            somaNotas += alunos[contAluno].nota[i];
        }

        std::cout << "Informe o sexo do aluno, F ou M: ";
        std::cin >> alunos[contAluno].sexo.genero;
        std::cout << std::endl;

        alunos[contAluno].media = somaNotas/qtdTotalProva;
        alunos[contAluno].aprovado = alunos[contAluno].media >= mediaAprovacao;

        std::cout << "Aluno: " << alunos[contAluno].nome << std::endl;
        std::cout << "\t Média: " << alunos[contAluno].media << std::endl;
        std::cout << "\t Status: " << alunos[contAluno].aprovado << std::endl;
    }

    // apresentação
    return 0;
}
