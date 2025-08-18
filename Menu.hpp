//
// Created by haskell on 18/08/25.
//

#ifndef MENU_HPP
#define MENU_HPP
#include "main.hpp"


class menu {
public:
    std::vector<Aluno> cadastrarTurma();
    void relatorioAprovados();
    void relatorioReprovados();
    void sair();
};



#endif //MENU_HPP
