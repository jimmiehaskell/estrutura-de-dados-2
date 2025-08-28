#include "Turma.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>

// constructor
Turma::Turma() {  }
Turma::~Turma() {  }

// getters
int Turma::getQtdAlunos() const {
    return this->qtdTotalAlunos;
}

int Turma::getQtdProvas() const {
    return this->qtdTotalProvas;
}

float Turma::getMediaAprovacao() const {
    return this->mediaAprovacao;
}

std::string Turma::getTurmaName() const {
    return this->turmaName;
}

std::vector<Aluno> Turma::getAlunos() const {
    return this->alunos;
}
// fim getters

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
// fim setters

// metodos publicos
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
        }
    }
}

void Turma::createTurma() {
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
}

void Turma::imprimeRelatorio(Turma &turma) {
    int alunosAprovados=0;
    int alunosAprovadosF=0;

    std::vector<Aluno> alunos = turma.getAlunos();
    for (int i = 0; i < turma.getQtdAlunos(); i++) {
        if (alunos[i].getAlunoMedia() >= turma.getMediaAprovacao()) {
            alunosAprovados++;
            if (alunos[i].getAlunoSexo() == 'F') {
                alunosAprovadosF++;
            }
        }
    }

    /* Faz a ordenação do vetor de acordo com a média
     * final de cada aluno, do maior para o menor
     */
    std::sort(alunos.begin(), alunos.end(), compararMedia);

    // imprime o total de alunos aprovados
    std::cout << "Relação dos alunos(a) aprovados na turma: " << turma.getTurmaName() << std::endl;
    for (int i = 0; i < alunosAprovados; i++) {
        std::cout << "\tNome: " << alunos[i].getAlunoNome() << std::endl;
        std::cout << "\tSexo: " << alunos[i].getAlunoSexo() << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\tMédia final: " << alunos[i].getAlunoMedia() << std::endl;
        std::cout << std::endl;
    }

    // Gráfico de aproveitamento da turma e aprovação por sexo
    desenharGrafico(turma.getQtdAlunos(), alunosAprovados, alunosAprovadosF);
}

void Turma::listTurmas(std::vector<Turma> &turmas) {
    for (int i = 0; i < turmas.size(); i++) {
        std::cout << i+1 << "ª Turma, id: " << i << " : " << turmas[i].getTurmaName() << std::endl;
        std::cout << "\tTotal alunos: " << turmas[i].getQtdAlunos() << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Turma::removerTurma(std::vector<Turma> &turma, int idTurma) {
    Turma t = turma[idTurma];
    turma.erase(turma.begin()+idTurma);
    std::cout << "Turma " << t.getTurmaName() << " removida com sucesso";
}

bool Turma::compararMedia(const Aluno &a, const Aluno &b) {
    return a.getAlunoMedia() > b.getAlunoMedia();
}
// fim metodos publicos

// metodos privados
void Turma::desenharGrafico(const int &qtdAlunos, const int &alunosAprovados, const int &alunosAprovadosF) {
    // static_cast<float>() eh necessario para garantir que a divisao nao descarte as casas decimais
    float pTotalAlunosAprovados = std::roundf(static_cast<float>(alunosAprovados)/qtdAlunos*100);
    float pTotalAlunosAprovadosF = std::roundf(static_cast<float>(alunosAprovadosF)/alunosAprovados*100);

    // Gráfico de total de alunos aprovados
    for (int i =0; i < static_cast<int>(pTotalAlunosAprovados); i++) {
        if (i==0) {
            // formar o resulta apenas com a parte inteira 10%, 20%
            std::cout << std::fixed << std::setprecision(0);
            std::cout << "Aproveitamento da turma " << pTotalAlunosAprovados << "%: ";
        }
        // Cor verde, representa os alunos aprovados
        std::cout << "\033[32m" << CHAR_BLOCK_FULL << "\033[0m";
    }
    // complate o grafico com os alunos reprovados, valores em %
    for (int i = 1; i < 100-static_cast<int>(pTotalAlunosAprovados); i++) {
        // Cor vermelha, representa os alunos reprovados
        std::cout << "\033[31m" << CHAR_BLOCK_MEDIUM << "\033[0m";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Gráfico dos alunos aprovados por genero, F/M
    for (int i = 0; i < static_cast<int>(pTotalAlunosAprovadosF); i++) {
        if (i==0) {
            // formar o resulta apenas com a parte inteira 10%, 20%
            std::cout << std::fixed << std::setprecision(0);
            std::cout << "Total alunos aprovados, F " << pTotalAlunosAprovadosF << "% e M " << 100-pTotalAlunosAprovadosF << "%: ";
        }
        // Cor magenta claro, representa as alunas aprovados
        std::cout << "\033[95m" << CHAR_BLOCK_FULL << "\033[0m";
    }
    for (int i = 0; i < 100-static_cast<int>(pTotalAlunosAprovadosF); i++) {
        // Cor azul claro, representa os alunos aprovados
        std::cout << "\033[94m" << CHAR_BLOCK_FULL << "\033[0m";
    }
    std::cout << std::endl;
    std::cout << std::endl;
}
// fim metodos privados
