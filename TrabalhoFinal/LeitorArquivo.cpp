#include "LeitorArquivo.h"
#include <fstream>
#include <iostream>
#include <sstream> 

LeitorArquivo::LeitorArquivo(const std::string& caminho) : caminhoArquivo(caminho) {}

std::vector<Processo> LeitorArquivo::lerProcessosCSV() {
    std::vector<Processo> listaProcessos;
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "[Erro] Nao foi possivel abrir o arquivo: " << caminhoArquivo << std::endl;
        return listaProcessos;
    }

    std::string linha;
    if (!std::getline(arquivo, linha)) {
        return listaProcessos; 
    }

    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string campo;
        Processo p;

        if (std::getline(ss, campo, ',')) p.tempoChegada = std::stoi(campo);
        if (std::getline(ss, campo, ',')) p.tempoExecucao = std::stoi(campo);
        if (std::getline(ss, campo, ',')) p.prioridade = std::stoi(campo);
        if (std::getline(ss, campo, ',')) p.memoriaNecessaria = std::stoi(campo);

        listaProcessos.push_back(p);
    }

    arquivo.close();
    return listaProcessos; 
}