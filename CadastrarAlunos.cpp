//
// Created by haskell on 18/08/25.
//

#include "CadastrarAlunos.hpp"

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
        toupper(turma[contAluno].sexo.genero);
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
    // Varre o primeiro vetor, contando a quantidade de turmas no BD
    for (int i=0; i<turmas.size(); i++) {
        // Verifica se a turma  no BD
        // tem pelo menos 1 aluno cadastrado
        if (turmas[i].size() <= 0)
            break;

        // Imprime o total de alunos no primeiro vetor
        std::cout << "Total de alunos aprovados na turma " << i + 1 << "." << std::endl;

        // Varre o segundo vetor, struct Aluno
        for (int j=0; j<turmas[i].size(); j++) {
            std::cout << "Aluno " << turmas[i].at(j).nome << std::endl;
            std::cout << "\tMédia final: " << turmas[i].at(j).media << std::endl;
            if (turmas[i].at(j).aprovado)
                std::cout << "\tStatus: Aprovado!" << std::endl;
            else
                std::cout << "\tStatus: Reprovado!" << std::endl;
        }
    }
}

