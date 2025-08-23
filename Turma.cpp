#include "Turma.hpp"

#include <iostream>

// contrutor
Turma::Turma() {
    do {
        std::cout << "Informe o nome da turma: ";
        /* solucao para o loop, o 'cin' só pega até o primeiro espaco
         * usando o 'getline', ele captura do a linha digitada pelo usuario
         * o 'ws' serve para ignorar espacos em branco no buffer, google.
         */
        std::getline(std::cin >> std::ws, turmaName);
    } while (this->turmaName.empty());

    do {
        std::cout << "Informe a quantidade de alunos da turma: ";
        std::cin >> this->qtdTotalAlunos;
    } while (this->qtdTotalAlunos <= 1);

    do {
        std::cout << "Informe a quantidade de provas da turma: ";
        std::cin >> this->qtdTotalProvas;
    } while (this->qtdTotalProvas < 2);

    do {
        std::cout << "Informe a media para aprovacao da turma: ";
        std::cin >> this->mediaAprovacao;
    } while (this->mediaAprovacao < 5);

    this->alunos.reserve(this->qtdTotalAlunos);

    addAlunos(this->qtdTotalAlunos);
    std::cout << "Turma::Turma(); ok!!" << std::endl;
}

// getters
int Turma::getQtdAlunos() {
    return this->qtdTotalAlunos;
}

int Turma::getQtdProvas() {
    return this->qtdTotalProvas;
}

float Turma::getMediaAprovacao() {
    return this->mediaAprovacao;
}

std::string Turma::getTurmaName() {
    return this->turmaName;
}


std::vector<Aluno> Turma::getAlunos() {
    return this->alunos;
}

// setters
void Turma::setQtdAlunos(int qtdAlunos) {
    this->qtdTotalAlunos = qtdAlunos;
}

void Turma::setQtdProvas(int qtdProvas) {
    this->qtdTotalProvas = qtdProvas;
}

void Turma::setMediaAprovacao(float mediaAprovacao) {
    this->mediaAprovacao = mediaAprovacao;
}

void Turma::setTurmaName(std::string turmaName) {
    this->turmaName = turmaName;
}


void Turma::addAlunos(int qtdTotalAlunos) {
    if (qtdTotalAlunos > 0) {
        for (int i = 0; i < qtdTotalAlunos; i++) {
            std::string alunoNome = "";
            char alunoSexo;
            std::vector<float> alunoNotas(this->qtdTotalProvas);

            // inicio da coleta dos dados para cadastrar um novo aluno
            do {
                std::cout << "Informe o nome do aluno(a): ";
                std::cin >> alunoNome;
            } while (alunoNome == "");

            do {
                std::cout << "Informe o sexo do aluno(a), (F-feminino ou M-masculino): ";
                std::cin >> alunoSexo;
                alunoSexo = toupper(alunoSexo);
            } while (alunoSexo != 'F' && alunoSexo != 'M');

            for (int i = 0; i < this->qtdTotalProvas; i++) {
                std::cout << "Informe a " << i+1 << "ª nota do aluno(a) " << alunoNome << ": ";
                std::cin >> alunoNotas[i];
                std::cout << std::endl;
            }
            // fim

        // inicio da persistencia dos dados do aluno
        Aluno aluno;
        aluno.setAlunoNome(alunoNome);
        aluno.setAlunoSexo(alunoSexo);
        aluno.setAlunoNotas(alunoNotas, this->mediaAprovacao);
        // fim

        // inclui o aluno no vetor alunos
        this->alunos.push_back(aluno);
        std::cout << "addAlunos(); ok!!" << std::endl;
        }
    }
    // std::string alunoNome;
    // char alunoSexo;
    // std::vector<float> alunoNotas(this->qtdTotalProvas);
    //
    // // inicio da coleta dos dados para cadastrar um novo aluno
    // do {
    //     std::cout << "Informe o nome do aluno(a): ";
    //     std::cin >> alunoNome;
    // } while (alunoNome == "");
    //
    // do {
    //     std::cout << "Informe o sexo do aluno(a), (F-feminino ou M-masculino): ";
    //     std::cin >> alunoSexo;
    //     alunoSexo = toupper(alunoSexo);
    // } while (alunoSexo != 'F' && alunoSexo != 'M');
    //
    // for (int i = 0; i < this->qtdTotalProvas; i++) {
    //     std::cout << "Informe a " << i+1 << "ª nota do aluno(a) " << alunoNome << ": ";
    //     std::cin >> alunoNotas[i];
    //     std::cout << std::endl;
    // }
    // // fim
    //
    // // inicio da persistencia dos dados do aluno
    // Aluno aluno;
    // aluno.setAlunoNome(alunoNome);
    // aluno.setAlunoSexo(alunoSexo);
    // aluno.setAlunoNotas(alunoNotas, this->mediaAprovacao);
    // // fim
    //
    // // inclui o aluno no vetor alunos
    // this->alunos.push_back(aluno);
    // std::cout << "ok!!" << std::endl;
}

// // debug
// int main() {
//     Turma turma;
//     turma.addAluno();
//     std::cout << "ok main!" << std::endl;
//     return 0;
// }