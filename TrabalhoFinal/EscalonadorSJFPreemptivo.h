#ifndef ESCALONADOR_SJF_PREEMPTIVO_H
#define ESCALONADOR_SJF_PREEMPTIVO_H

#include <vector>
#include "LeitorArquivo.h"

class EscalonadorSJFPreemptivo {
private:
    std::vector<Processo> processosIniciais;
    int ram;
    int politicaMem;
    int tamFrame;

public:
    EscalonadorSJFPreemptivo(const std::vector<Processo>& procs, int ram, int politica, int tamFrame);
    void executarSimulacao();
};

#endif