#ifndef GERENCIADOR_MEMORIA_H
#define GERENCIADOR_MEMORIA_H

#include <vector>
#include <string>

class GerenciadorMemoria {
private:
    int totalFrames;
    int politica; // 1 = FIFO, 2 = LRU, 3 = Ótimo
    int pageFaults;
    
    std::vector<std::string> memoriaFisica;
    std::vector<std::string> ordemFIFO;       
    std::vector<std::string> historicoLRU;    

public:
    // Construtor atualizado para receber o tamanho customizado do frame
    GerenciadorMemoria(int memoriaRamMB, int politicaEscolhida, int tamanhoFrameMB);
    void acessarPagina(int processoId, int numeroPagina, const std::vector<std::string>& referenciasFuturas, int instrucaoAtual);
    int getTotalPageFaults() const;
};

#endif