#ifndef ESCALONADOR_PRIORIDADE_H
#define ESCALONADOR_PRIORIDADE_H

#include <vector>
#include "LeitorArquivo.h"

class EscalonadorPrioridade {
private:
    std::vector<Processo> processosIniciais;
    int ram;
    int politicaMem;
    int tamFrame;

public:
    EscalonadorPrioridade(const std::vector<Processo>& procs, int ram, int politica, int tamFrame);
    void executarSimulacao();
};

#endif