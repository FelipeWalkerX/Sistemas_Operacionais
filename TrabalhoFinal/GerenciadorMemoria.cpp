#include "GerenciadorMemoria.h"
#include <iostream>
#include <algorithm>

// O construtor agora calcula os frames dividindo a RAM pelo tamanho do frame digitado
GerenciadorMemoria::GerenciadorMemoria(int memoriaRamMB, int politicaEscolhida, int tamanhoFrameMB) {
    totalFrames = memoriaRamMB / tamanhoFrameMB;
    if (totalFrames <= 0) totalFrames = 1; 
    politica = politicaEscolhida;
    pageFaults = 0;
}

int GerenciadorMemoria::getTotalPageFaults() const {
    return pageFaults;
}

void GerenciadorMemoria::acessarPagina(int processoId, int numeroPagina, const std::vector<std::string>& referenciasFuturas, int instrucaoAtual) {
    std::string identificadorPagina = "P" + std::to_string(processoId) + "_Pag" + std::to_string(numeroPagina);

    auto it = std::find(memoriaFisica.begin(), memoriaFisica.end(), identificadorPagina);
    if (it != memoriaFisica.end()) {
        if (politica == 2) {
            auto itLRU = std::find(historicoLRU.begin(), historicoLRU.end(), identificadorPagina);
            if (itLRU != historicoLRU.end()) historicoLRU.erase(itLRU);
            historicoLRU.push_back(identificadorPagina);
        }
        return; 
    }

    pageFaults++;
    std::cout << "  [MEMORIA] Page Fault para " << identificadorPagina << "!\n";

    if (memoriaFisica.size() < (size_t)totalFrames) {
        memoriaFisica.push_back(identificadorPagina);
        ordemFIFO.push_back(identificadorPagina);
        historicoLRU.push_back(identificadorPagina);
        return;
    }

    std::string paginaParaRemover = "";

    if (politica == 1) {
        paginaParaRemover = ordemFIFO.front();
        ordemFIFO.erase(ordemFIFO.begin());
    }
    else if (politica == 2) {
        paginaParaRemover = historicoLRU.front(); 
        historicoLRU.erase(historicoLRU.begin());
    }
    else if (politica == 3) {
        int maiorIndiceFuturo = -1;
        paginaParaRemover = memoriaFisica[0];

        for (const std::string& pagNaRam : memoriaFisica) {
            int proximaVezQueSeraUsada = 999999; 

            for (size_t f = instrucaoAtual + 1; f < referenciasFuturas.size(); f++) {
                if (referenciasFuturas[f] == pagNaRam) {
                    proximaVezQueSeraUsada = f;
                    break;
                }
            }

            if (proximaVezQueSeraUsada > maiorIndiceFuturo) {
                maiorIndiceFuturo = proximaVezQueSeraUsada;
                paginaParaRemover = pagNaRam;
            }
        }
    }

    auto itSubstituir = std::find(memoriaFisica.begin(), memoriaFisica.end(), paginaParaRemover);
    if (itSubstituir != memoriaFisica.end()) {
        std::cout << "  [MEMORIA] Substituindo " << paginaParaRemover << " por " << identificadorPagina << ".\n";
        *itSubstituir = identificadorPagina;
    }

    if (politica == 1) ordemFIFO.push_back(identificadorPagina);
    if (politica == 2) historicoLRU.push_back(identificadorPagina);
}