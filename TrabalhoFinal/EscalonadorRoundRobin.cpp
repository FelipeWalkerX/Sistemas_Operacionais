#include "EscalonadorRoundRobin.h"
#include "GerenciadorMemoria.h"
#include <iostream>
#include <queue>
#include <iomanip>

struct ProcessoSimulacao {
    int id;
    int tempoChegada;
    int tempoExecucaoOriginal;
    int tempoRestante;
    int prioridade;
    int memoriaNecessaria;
    int tempoPrimeiraExecucao;
    int tempoConclusao;
    bool iniciado;
};

EscalonadorRoundRobin::EscalonadorRoundRobin(const std::vector<Processo>& procs, int q, int ram, int politica, int tamFrame)
    : quantum(q), ram(ram), politicaMem(politica), tamFrame(tamFrame) {
    processosIniciais = procs;
}

void EscalonadorRoundRobin::executarSimulacao() {

    // Repassa o tamFrame para o Gerenciador de Memória
    GerenciadorMemoria gerenciadorMemoria(ram, politicaMem, tamFrame);

    std::vector<ProcessoSimulacao> lista;
    int idContador = 1;
    for (const auto& p : processosIniciais) {
        lista.push_back({idContador++, p.tempoChegada, p.tempoExecucao, p.tempoExecucao, p.prioridade, p.memoriaNecessaria, -1, 0, false});
    }

    std::queue<ProcessoSimulacao> filaProntos;
    std::vector<std::string> previsaoFutura; 
    int tempoAtual = 0;
    int processosConcluidos = 0;
    int totalProcessos = lista.size();
    std::vector<bool> inseridoNaFila(totalProcessos, false);

    std::cout << "\n==============================================" << std::endl;
    std::cout << "     INICIANDO SIMULACAO COMPLETA (RR + MEM)  " << std::endl;
    std::cout << "==============================================" << std::endl;

    while (processosConcluidos < totalProcessos) {
        for (int i = 0; i < totalProcessos; i++) {
            if (lista[i].tempoChegada <= tempoAtual && !inseridoNaFila[i] && lista[i].tempoRestante > 0) {
                filaProntos.push(lista[i]);
                inseridoNaFila[i] = true;
            }
        }

        if (filaProntos.empty()) {
            tempoAtual++;
            continue;
        }

        ProcessoSimulacao atual = filaProntos.front();
        filaProntos.pop();

        int tempoExecucaoNesseTurno = (atual.tempoRestante > quantum) ? quantum : atual.tempoRestante;

        for (auto& p : lista) {
            if (p.id == atual.id && !p.iniciado) {
                p.tempoPrimeiraExecucao = tempoAtual;
                p.iniciado = true;
                atual.tempoPrimeiraExecucao = tempoAtual;
                atual.iniciado = true;
            }
        }

        std::cout << "[Tempo " << tempoAtual << "] CPU executando P" << atual.id 
                  << " por " << tempoExecucaoNesseTurno << " u.t. (Restante: " << atual.tempoRestante << ")\n";

        for (int t = 0; t < tempoExecucaoNesseTurno; t++) {
            // Calcula a quantidade de páginas virtuais dividindo pelo tamFrame do usuário
            int paginasDoProcesso = atual.memoriaNecessaria / tamFrame;
            if (paginasDoProcesso <= 0) paginasDoProcesso = 1;
            int paginaAcessada = (atual.tempoExecucaoOriginal - atual.tempoRestante) % paginasDoProcesso;
            
            gerenciadorMemoria.acessarPagina(atual.id, paginaAcessada, previsaoFutura, tempoAtual);

            tempoAtual++;
            atual.tempoRestante--;

            for (int i = 0; i < totalProcessos; i++) {
                if (lista[i].tempoChegada <= tempoAtual && !inseridoNaFila[i] && lista[i].tempoRestante > 0) {
                    filaProntos.push(lista[i]);
                    inseridoNaFila[i] = true;
                }
            }
        }

        if (atual.tempoRestante == 0) {
            std::cout << "[Tempo " << tempoAtual << "] >>> Processo P" << atual.id << " CONCLUIDO! <<<\n";
            processosConcluidos++;
            for (auto& p : lista) {
                if (p.id == atual.id) p.tempoConclusao = tempoAtual;
            }
        } else {
            for (auto& p : lista) {
                if (p.id == atual.id) p.tempoRestante = atual.tempoRestante;
            }
            filaProntos.push(atual);
        }
    }

    // (O restante do relatório permanece igual...)
    double totalEspera = 0;
    double totalResposta = 0;
    std::cout << "\n=======================================================\n";
    std::cout << "        RELATORIO DE PERFORMANCE (ROUND-ROBIN)         \n";
    std::cout << "=======================================================\n";
    std::cout << "Proc\tTurnaround\tT.Espera\tT.Resposta\n";
    std::cout << "-------------------------------------------------------\n";
    for (const auto& p : lista) {
        int turnaround = p.tempoConclusao - p.tempoChegada;
        int tempoEspera = turnaround - p.tempoExecucaoOriginal;
        int tempoResposta = p.tempoPrimeiraExecucao - p.tempoChegada;
        totalEspera += tempoEspera;
        totalResposta += tempoResposta;
        std::cout << "P" << p.id << "\t" << turnaround << " u.t.\t\t" << tempoEspera << " u.t.\t\t" << tempoResposta << " u.t.\n";
    }
    std::cout << "-------------------------------------------------------\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-> Tempo Medio de Resposta: " << (totalResposta / totalProcessos) << " u.t.\n";
    std::cout << "-> Tempo Medio de Espera:   " << (totalEspera / totalProcessos) << " u.t.\n";
    std::cout << "-> Total de Page Faults:    " << gerenciadorMemoria.getTotalPageFaults() << "\n";
    std::cout << "=======================================================\n\n";
}