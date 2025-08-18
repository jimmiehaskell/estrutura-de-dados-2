//
// Created by haskell on 18/08/25.
//

#ifndef CADASTRARALUNOS_HPP
#define CADASTRARALUNOS_HPP
#include <iostream>
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

public:
    std::vector<Aluno> cadastrarTurma();
    void relatorioAprovados(std::vector<std::vector<Aluno>>);
    void relatorioReprovados();
    void sair();
};

#endif // CADASTRARALUNOS_HPP
