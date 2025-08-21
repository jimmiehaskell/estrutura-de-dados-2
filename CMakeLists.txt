cmake_minimum_required(VERSION 3.31)
project(Estrutura_de_Dados_II)

set(CMAKE_CXX_STANDARD 20)

add_executable(Estrutura_de_Dados_II Main.cpp
        Menu.cpp
        CadastrarAlunos.cpp
        CadastrarAlunos.hpp
        Aluno.hpp
        Aluno.cpp)
