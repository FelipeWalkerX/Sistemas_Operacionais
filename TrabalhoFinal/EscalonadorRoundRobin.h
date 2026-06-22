#ifndef ESCALONADOR_ROUND_ROBIN_H
#define ESCALONADOR_ROUND_ROBIN_H

#include <vector>
#include <queue>
#include "LeitorArquivo.h"

class EscalonadorRoundRobin {
private:
    std::vector<Processo> processosIniciais;
    int quantum;
    int ram;
    int politicaMem;
    int tamFrame;

public:
    EscalonadorRoundRobin(const std::vector<Processo>& procs, int q, int ram, int politica, int tamFrame);
    void executarSimulacao();
};

#endif