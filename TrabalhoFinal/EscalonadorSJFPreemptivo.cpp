#include "EscalonadorSJFPreemptivo.h"
#include "GerenciadorMemoria.h"
#include <iostream>
#include <climits>
#include <iomanip>

struct ProcessoSJF {
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

EscalonadorSJFPreemptivo::EscalonadorSJFPreemptivo(const std::vector<Processo>& procs, int ram, int politica, int tamFrame)
    : ram(ram), politicaMem(politica), tamFrame(tamFrame) {
    processosIniciais = procs;
}

void EscalonadorSJFPreemptivo::executarSimulacao() {

    GerenciadorMemoria gerenciadorMemoria(ram, politicaMem, tamFrame);

    std::vector<ProcessoSJF> lista;
    int idContador = 1;
    for (const auto& p : processosIniciais) {
        lista.push_back({idContador++, p.tempoChegada, p.tempoExecucao, p.tempoExecucao, p.prioridade, p.memoriaNecessaria, -1, 0, false});
    }

    std::vector<std::string> previsaoFutura;
    int tempoAtual = 0;
    int processosConcluidos = 0;
    int totalProcessos = lista.size();
    int ultimoIdExecutado = -1;

    std::cout << "\n==============================================" << std::endl;
    std::cout << "     INICIANDO SIMULACAO COMPLETA (SJF + MEM) " << std::endl;
    std::cout << "==============================================" << std::endl;

    while (processosConcluidos < totalProcessos) {
        int indiceMelhorProcesso = -1;
        int menorTempoRestante = INT_MAX;

        for (int i = 0; i < totalProcessos; i++) {
            if (lista[i].tempoChegada <= tempoAtual && lista[i].tempoRestante > 0) {
                if (lista[i].tempoRestante < menorTempoRestante) {
                    menorTempoRestante = lista[i].tempoRestante;
                    indiceMelhorProcesso = i;
                }
            }
        }

        if (indiceMelhorProcesso == -1) {
            std::cout << "[Tempo " << tempoAtual << "] CPU Ociosa.\n";
            tempoAtual++;
            continue;
        }

        ProcessoSJF& pAtual = lista[indiceMelhorProcesso];

        if (ultimoIdExecutado != -1 && ultimoIdExecutado != pAtual.id) {
            std::cout << "[Tempo " << tempoAtual << "] Troca de contexto: CPU mudou para P" << pAtual.id << "\n";
        }
        ultimoIdExecutado = pAtual.id;

        if (!pAtual.iniciado) {
            pAtual.tempoPrimeiraExecucao = tempoAtual;
            pAtual.iniciado = true;
        }

        // Calcula com base no tamanho do frame escolhido pelo usuário
        int paginasDoProcesso = pAtual.memoriaNecessaria / tamFrame;
        if (paginasDoProcesso <= 0) paginasDoProcesso = 1;

        int paginaAcessada = (pAtual.tempoExecucaoOriginal - pAtual.tempoRestante) % paginasDoProcesso;
        gerenciadorMemoria.acessarPagina(pAtual.id, paginaAcessada, previsaoFutura, tempoAtual);

        std::cout << "[Tempo " << tempoAtual << "] CPU executando P" << pAtual.id 
                  << " | Restante: " << pAtual.tempoRestante << " u.t.\n";
        
        pAtual.tempoRestante--;
        tempoAtual++;

        if (pAtual.tempoRestante == 0) {
            std::cout << "[Tempo " << tempoAtual << "] >>> Processo P" << pAtual.id << " CONCLUIDO! <<<\n";
            pAtual.tempoConclusao = tempoAtual;
            processosConcluidos++;
            ultimoIdExecutado = -1;
        }
    }

    // (O restante do relatório permanece igual...)
    double totalEspera = 0;
    double totalResposta = 0;
    std::cout << "\n=======================================================\n";
    std::cout << "          RELATORIO DE PERFORMANCE DO SIMULADOR        \n";
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