#include <iostream>

#include "Turma.hpp"

class Menu {
private:
    static void limparTela() {
        #ifdef _WIN32
            std::system("cls");
        #else
            system("clear");
        #endif
    }
public:
    static void menu() {
        bool loop = true;
        int opcaoMenu = 0;

        /* Persistencia dos dados em tempo de execucao
         * é um teste para futuras implementacoes, ex. sqlite
         */
        std::vector<Turma> turma_db;

        while (loop) {
            std::cout << "\t#\t Menu" << std::endl;
            std::cout << "\t#\t Selecione a opcao desejada." << std::endl;
            std::cout << std::endl;
            std::cout << "\t#\t [1] - Cadastrar uma turma." << std::endl;
            std::cout << "\t#\t [2] - Listar turmas." << std::endl;
            std::cout << "\t#\t [3] - Editar turmas." << std::endl;
            std::cout << "\t#\t [4] - Deletar turmas." << std::endl;
            std::cout << "\t#\t [5] - Sair do programa." << std::endl;
            std::cout << std::endl;
            std::cout << "-> ";
            std::cin >> opcaoMenu;
            switch (opcaoMenu) {
                case 1: {
                    Turma turma;
                    turma_db.push_back(turma);
                    std::cout << "Sem espaço na memoria." << std::endl;
                    break;
                }
                case 2: {
                    for (int i = 0; i < turma_db.size(); i++) {
                        std::cout << i+1 << "ª Turma, id " << i << ", " << turma_db[i].getTurmaName() << std::endl;
                        std::cout << "\tQuantidade de alunos: " << turma_db[i].getQtdAlunos() << std::endl << std::endl;
                    }
                    break;
                }
                case 3: {
                    std::system("clear");
                    std::cout << "TODO: fazer!" << std::endl;
                    break;
                }
                case 4: {
                    std::system("clear");
                    std::cout << "TODO: fazer!" << std::endl;
                    break;
                }
                case 5: {
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
