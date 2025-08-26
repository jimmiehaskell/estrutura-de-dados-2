#ifndef ALUNO_HPP
#define ALUNO_HPP
#include <iomanip>
#include <string>
#include <vector>


class Aluno {
private:
    // variáveis
    std::string alunoNome;
    std::vector<float> alunoNotas;
    char alunoSexo;
    float alunoMedia;
    bool alunoAprovado;

    // métodos
    void setAlunoMedia(std::vector<float> _notas, float _mediaAprovacao);
    void setAlunoAprovado(bool a);
    bool compararMedias(const Aluno &a, const Aluno &b, bool o);

public:
    // construtor
    Aluno()=default;

    // métodos
    // getters
    std::string getAlunoNome();
    std::vector<float> getAlunoNotas();
    char getAlunoSexo();
    float getAlunoMedia() const;
    std::string getAlunoAprovado();

    // setters
    void setAlunoNome(std::string nome);
    void setAlunoNotas(std::vector<float> _notas, float _mediaAprovacao);
    void setAlunoSexo(char sexo);
};


#endif // ALUNO_HPP
