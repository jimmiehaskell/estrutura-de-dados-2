//
// Created by haskell on 18/08/25.
//

#ifndef CADASTRARALUNOS_HPP
#define CADASTRARALUNOS_HPP
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

#include <string>
#include <vector>


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

class CadastrarAlunos {

private:
    // declacao de variaveis
    int contAluno=0;
    int totalAlunoM=0;
    int totalAlunoAprovado=0;
    int qtdTotalAlunos=0;
    int qtdTotalProvas=0;
    float mediaAprovacao=0;

    static bool compararPorMediaFinal(const Aluno &a, const Aluno &b);
    static void desenharGrafico(int totalAlunos, int totalAlunosAprovados, int totalAlunosAprovadosM);


public:
    std::vector<Aluno> cadastrarTurma();
    static void relatorioAprovados(std::vector<std::vector<Aluno>>);
    static void relatorioReprovados(std::vector<std::vector<Aluno>>);
    static void sair();
};

#endif // CADASTRARALUNOS_HPP
