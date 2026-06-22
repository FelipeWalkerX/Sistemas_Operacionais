#ifndef LEITOR_ARQUIVO_H
#define LEITOR_ARQUIVO_H

#include <string>
#include <vector>

// Estrutura global que representa o modelo de dados de um Processo
struct Processo {
    int tempoChegada;
    int tempoExecucao; 
    int prioridade;
    int memoriaNecessaria; 
};

class LeitorArquivo {
private:
    std::string caminhoArquivo;

public:
    LeitorArquivo(const std::string& caminho);
    std::vector<Processo> lerProcessosCSV();
};

#endif