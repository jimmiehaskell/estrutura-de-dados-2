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
            std::cout << "\t#\t [3] - Buscar turma por ID" << std::endl;
            std::cout << "\t#\t [4] - Deletar turmas." << std::endl;
            std::cout << "\t#\t [5] - Sair do programa." << std::endl;
            std::cout << std::endl;
            std::cout << "-> ";
            std::cin >> opcaoMenu;
            switch (opcaoMenu) {
                case 1: {
                    Turma turma;
                    turma.createTurma();
                    turma_db.push_back(turma);
                    std::cout << "Sem espaço na memoria." << std::endl;
                    break;
                }
                case 2: {
                    limparTela();
                    Turma().listTurmas(turma_db);
                    break;
                }
                case 3: {
                    int contTurma = 0;
                    limparTela();
                    Turma().listTurmas(turma_db);
                    std::vector<Aluno> alunos = turma_db[contTurma].getAlunos();

                    std::cout << "Informe o ID da turma: ";
                    std::cin >> contTurma;
                    std::cout << "Turma: " << turma_db[contTurma].getTurmaName() << std::endl;
                    Turma().imprimeRelatorio(turma_db[contTurma]);
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
