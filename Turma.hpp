#ifndef TURMA_HPP
#define TURMA_HPP
// bloco cheio
#ifdef _WIN32
    #define CHAR_BLOCK_FULL (char)219
#else
    #define CHAR_BLOCK_FULL "\u2588"
#endif

// bloco médio
#ifdef _WIN32
    #define CHAR_BLOCK_MEDIUM (char)177
#else
    #define CHAR_BLOCK_MEDIUM "\u2592"
#endif

#include <vector>

#include "Aluno.hpp"


class Turma {
private:
    int qtdTotalAlunos;
    int qtdTotalProvas;
    float mediaAprovacao;
    std::string turmaName;
    std::vector<Aluno> alunos;

    // metodos
    static bool compararMedia(const Aluno &a, const Aluno &b);

    static void desenharGrafico(const int &qtdAlunos, const int &alunosAprovados, const int &alunosAprovadosF);

public:
    Turma();

    // getters
    int getQtdAlunos() const;

    int getQtdProvas() const;

    float getMediaAprovacao() const;

    std::string getTurmaName() const;

    std::vector<Aluno> getAlunos() const;

    // setters
    void createTurma();

    void setQtdAlunos(int qtdAlunos);

    void setQtdProvas(int qtdProvas);

    void setMediaAprovacao(float mediaAprovacao);

    void setTurmaName(std::string turmaName);

    void addAlunos(int qtdTotalAlunos);

    // metodos
    static void listTurmas(std::vector<Turma> &turmas);

    static void imprimeRelatorio(Turma &turma);
};

#endif // TURMA_HPP
