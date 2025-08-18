//
// Created by haskell on 18/08/25.
//

#ifndef MAIN_HPP
#define MAIN_HPP
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

#endif //MAIN_HPP
