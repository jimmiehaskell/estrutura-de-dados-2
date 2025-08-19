//
// Created by haskell on 18/08/25.
//

#include "CadastrarAlunos.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

bool CadastrarAlunos::compararPorMediaFinal(const Aluno &a, const Aluno &b) {
    return a.media > b.media;
}

void CadastrarAlunos::desenharGrafico(int totalAlunos, int totalAlunosAprovados, int totalAlunosAprovadosM) {
    float pTotalAlunosAprovados = static_cast<float>(totalAlunosAprovados)/totalAlunos*100;
    float pTotalAlunosAprovadosM = static_cast<float>(totalAlunosAprovadosM)/totalAlunosAprovados*100;

    // Gráfico total de aprovados da turma
    for (int i=0; i<pTotalAlunosAprovados; i++) {
        if (i==0) {
            // formar o resulta apenas com a parte inteira 10%, 20%
            std::cout << std::fixed << std::setprecision(0);
            std::cout << "Aproveitamento da turma " << pTotalAlunosAprovados << "%: ";
        }
        std::cout << "\033[32m" << CHAR_BLOCK_FULL << "\033[0m"; // Cor verde, representa os alunos aprovados
    }
    for (int i=1; i<100-pTotalAlunosAprovados; i++)
        std::cout << "\033[31m" << CHAR_BLOCK_MEDIUM << "\033[0m"; // Cor vermelha, representa os alunos reprovados
    std::cout << std::endl;

    // Gráfico total de alunos aprovados por genero F/M
    for (int i=0; i<pTotalAlunosAprovadosM; i++) {
        if (i==0) {
            // formar o resulta apenas com a parte inteira 10%, 20%
            std::cout << std::fixed << std::setprecision(0);
            std::cout << "Total alunos aprovados feminino " << 100-pTotalAlunosAprovadosM << "% e masculino " << pTotalAlunosAprovadosM << "%: ";
        }
        std::cout << "\033[94m" << CHAR_BLOCK_FULL << "\033[0m"; // Cor azul claro, representa os alunos aprovados
    }
    for (int i=1; i<100-pTotalAlunosAprovadosM; i++)
        std::cout << "\033[95m" << CHAR_BLOCK_FULL << "\033[0m"; // Cor magenta claro, representa as alunas aprovados
    std::cout << std::endl;
    std::cout << std::endl;
}


std::vector<Aluno> CadastrarAlunos::cadastrarTurma() {
    // recebe o total de alunos
    std::cout << "Informe o total de alunos na turma: ";
    std::cin >> qtdTotalAlunos;
    std::cout << std::endl;

    // recebe o total de provas da turma
    std::cout << "Informe o total de provas: ";
    std::cin >> qtdTotalProvas;
    std::cout << std::endl;

    // recebe a media para aprovacao dos alunos
    std::cout << "Informe a media para aprovacao: ";
    std::cin >> mediaAprovacao;
    std::cout << std::endl;

    // aloca vetor turma
    std::vector<Aluno> turma(qtdTotalAlunos);

    // coleta dados
    while (contAluno < qtdTotalAlunos) {
        std::cout << "Informe o nome do aluno " << contAluno + 1 << ": ";
        std::cin >> turma[contAluno].nome;
        std::cout << std::endl;

        turma[contAluno].nota.reserve(qtdTotalProvas);
        float somaNotas = 0;
        for (int i = 0; i < qtdTotalProvas; i++) {
            std::cout << "Informe a nota da " << i + 1 << "ª prova: ";
            std::cin >> turma[contAluno].nota[i];
            std::cout << std::endl;

            somaNotas += turma[contAluno].nota[i];
        }

        std::cout << "Informe o sexo do aluno, F ou M: ";
        std::cin >> turma[contAluno].sexo.genero;
        // Deixa o sexo do aluno em maiuscula.
        turma[contAluno].sexo.genero = std::toupper(turma[contAluno].sexo.genero);
        std::cout << std::endl;

        turma[contAluno].media = somaNotas / qtdTotalProvas;
        turma[contAluno].aprovado = turma[contAluno].media >= mediaAprovacao;
        if (turma[contAluno].aprovado)
            totalAlunoAprovado++;

        if (turma[contAluno].sexo.genero == 'M')
            totalAlunoM++;

        contAluno++;
    }

    return turma;
}

void CadastrarAlunos::relatorioAprovados(std::vector<std::vector<Aluno>> turmas) {
    int contAprovados=0;
    int contAprovadosM=0;

    // Varre o primeiro vetor, contando a quantidade de turmas no BD
    for (int i = 0; i < turmas.size(); i++) {
        // Verifica se a turma  no BD
        // está vazio, se for 'true' pula a interação do for.
        if (turmas[i].empty())
            break;

        // Faz a ordenação do vetor de acordo com a média
        // final de cada aluno, do maior para o menor
        std::sort(turmas[i].begin(), turmas[i].end(), compararPorMediaFinal);

        // Imprime o total de alunos no primeiro vetor
        std::cout << "Relação dos alunos(a), aprovados na turma: " << i + 1 << "." << std::endl;

        // Varre o segundo vetor, struct Aluno
        for (int j = 0; j < turmas[i].size(); j++) {
            if (turmas[i].at(j).aprovado) {
                std::cout << std::fixed << std::setprecision(2);
                std::cout << "- " << turmas[i].at(j).nome << ", média: " << turmas[i].at(j).media << std::endl;
                contAprovados++;
                if (turmas[i].at(j).sexo.genero == 'M')
                    contAprovadosM++;
            }
        }

        std::cout << "Gráfico de aproveitamento da turma: " << i + 1 << "." << std::endl;
        desenharGrafico(turmas[i].size(),contAprovados, contAprovadosM);
    }
}

void CadastrarAlunos::relatorioReprovados() {}
