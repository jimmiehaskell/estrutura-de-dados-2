#ifndef TURMA_HPP
#define TURMA_HPP
#include <vector>

#include "Aluno.hpp"


class Turma {
private:
    int qtdTotalAlunos;
    int qtdTotalProvas;
    float mediaAprovacao;
    std::string turmaName;
    std::vector<Aluno> alunos;

public:
    Turma();

    int getQtdAlunos();
    int getQtdProvas();
    float getMediaAprovacao();
    std::string getTurmaName();
    std::vector<Aluno> getAlunos();

    void setQtdAlunos(int qtdAlunos);
    void setQtdProvas(int qtdProvas);
    void setMediaAprovacao(float mediaAprovacao);
    void setTurmaName(std::string turmaName);
    void addAlunos(int qtdTotalAlunos);
};


#endif // TURMA_HPP
