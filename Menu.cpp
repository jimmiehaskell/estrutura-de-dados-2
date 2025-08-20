//
// Created by haskell on 18/08/25.
//

#include <iostream>

#include "CadastrarAlunos.hpp"
class Menu {
public:
    static void menu() {
        bool loop = true;
        int opcaoMenu = 0;

        // Persistencia dos dados em tempo de execução
        // por padrão 3, HARDCODED
        int totalTurmasDB = 3;
        int contTurma = 0;
        std::vector<std::vector<Aluno>> turma_db(totalTurmasDB);

        while (loop) {
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << "|\t\t\t\t\t Menu \t\t\t\t\t|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << "|\t\t Selecione a opcao desejada. \t\t|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cout << "|\t\t [1] - Cadastrar uma turma; \t\t|" << std::endl;
            std::cout << "|\t\t [2] - Relatório de aprovados; \t\t|" << std::endl;
            std::cout << "|\t\t [3] - Relatório de repovados; e \t|" << std::endl;
            std::cout << "|\t\t [4] - Sair do programa. \t\t\t|" << std::endl;
            std::cout << "+-------------------------------------------+" << std::endl;
            std::cin >> opcaoMenu;
            switch (opcaoMenu) {
                case 1:
                    if (contTurma < totalTurmasDB) {
                        turma_db[contTurma] = CadastrarAlunos().cadastrarTurma();
                        contTurma++;
                        break;
                        std::system("clear");
                    } else {
                        std::cout << "DB cheio!" << std::endl;
                        std::system("clear");
                    }
                case 2:
                    CadastrarAlunos().relatorioAprovados(turma_db);
                    std::system("clear");
                    break;
                case 3:
                    std::cout << "TODO: fazer!" << std::endl;
                    std::system("clear");
                    break;
                case 4:
                    loop = false;
                    break;
                default:
                    if (opcaoMenu < 0 || opcaoMenu > 4)
                        std::cout << "Opcao invalida!" << std::endl;
            }
            opcaoMenu = 0;
        }
    }
};
