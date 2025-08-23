//
// Created by haskell on 18/08/25.
//

#include <iostream>

#include "Turma.hpp"
class Menu {
public:
    static void menu() {
        bool loop = true;
        int opcaoMenu = 0;

        /* Persistencia dos dados em tempo de execucao
         * é um teste para futuras implementacoes, ex. sqlite
         */
        std::vector<Turma> turma_db;

        while (loop) {
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << "|\t\t\t\t\t Menu \t\t\t\t\t|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << "|\t\t Selecione a opcao desejada. \t\t|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << "|\t\t [1] - Cadastrar uma turma. \t\t|" << std::endl;
            std::cout << "|\t\t [2] - Listar turmas. \t\t\t\t|" << std::endl;
            std::cout << "|\t\t [3] - Editar turmas. \t\t\t\t|" << std::endl;
            std::cout << "|\t\t [4] - Deletar turmas. \t\t\t\t|" << std::endl;
            std::cout << "|\t\t [5] - Sair do programa. \t\t\t|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << std::endl;
            std::cout << "-> ";
            std::cin >> opcaoMenu;
            switch (opcaoMenu) {
                case 1: {
                    Turma turma;
                    turma_db.push_back(turma);
                    std::cout << "Sem espaço na memoria." << std::endl;
                }
                case 2: {
                    // CadastrarAlunos().relatorioAprovados(turma_db);
                    std::system("clear");
                    break;
                }
                case 3: {
                    std::cout << "TODO: fazer!" << std::endl;
                    std::system("clear");
                    break;
                }
                case 4: {
                    loop = false;
                    break;
                }
                default: {
                    if (opcaoMenu < 0 || opcaoMenu > 4)
                        std::cout << "Opcao invalida!" << std::endl;
                }
            }
            opcaoMenu = 0;
        }
    }
};
