#include "Aluno.hpp"


// constructor
Aluno::Aluno()=default;

Aluno::Aluno(std::string alunoNome, char alunoSexo, std::vector<float> alunoNotas, float mediaAprovacao) {
    setAlunoNome(alunoNome);
    setAlunoSexo(alunoSexo);
    setAlunoNotas(alunoNotas, mediaAprovacao);
}

// métodos privados
void Aluno::setAlunoMedia(std::vector<float> _notas, float _mediaAprovacao) {
    float somaNotas = 0;
    for (int i = 0; i < _notas.size(); i++) {
        somaNotas += _notas[i];
    }

    this->alunoMedia = somaNotas / _notas.size();
    setAlunoAprovado(this->alunoMedia > _mediaAprovacao);
}

void Aluno::setAlunoAprovado(bool a) {
    this->alunoAprovado = a;
}

/*
 * @param a, primeiro aluno a ser comparado
 * @param b, segundo aluno a ser comparado
 * @param o, (true ou false) representa a ordenação,
 * true = decrescente, false = crescente
*/
bool Aluno::compararMedias(const Aluno &a, const Aluno &b, bool o) {
    if (o) {
        return a.alunoMedia > b.alunoMedia;
    }
    return a.alunoMedia < b.alunoMedia;
}
// fim métodos privados

// métodos publicos
// getters
std::string Aluno::getAlunoNome() {
    return alunoNome;
}

std::vector<float> Aluno::getAlunoNotas() {
    return alunoNotas;
}

char Aluno::getAlunoSexo() {
    return alunoSexo;
}

float Aluno::getAlunoMedia() const {
    return alunoMedia;
}

std::string Aluno::getAlunoAprovado() {
    if (this->alunoAprovado) {
        return "Aprovado!";
    }
    return "Reprovado!";
}
// fim dos getters

// setters
void Aluno::setAlunoNome(std::string nome) {
    this->alunoNome = nome;
}

void Aluno::setAlunoNotas(std::vector<float> _notas, float _mediaAprovacao) {
    if (_notas.size() > 0) {
        this->alunoNotas = _notas;
        setAlunoMedia(_notas, _mediaAprovacao);
    }
}

void Aluno::setAlunoSexo(char sexo) {
    this->alunoSexo = sexo;
}
// fim dos setters
//fim dos métodos publicos

// int main() {
//     Aluno aluno1;
//     std::vector<float> aluno1Notas = {8, 9.75, 7.53, 9, 10};
//     aluno1.setAlunoNome("Jimmie");
//     aluno1.setAlunoNotas(aluno1Notas, 6);
//     aluno1.setAlunoSexo('M');
//
//     std::cout << "Aluno: " << aluno1.getAlunoNome() << std::endl;
//     std::cout << std::fixed << std::setprecision(2);
//     std::cout << "\tMédia: " << aluno1.getAlunoMedia() << std::endl;
//     std::cout << "\tStatus: " << aluno1.getAlunoAprovado() << std::endl;
//
//     return 0;
// }