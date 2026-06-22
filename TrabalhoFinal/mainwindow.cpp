#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "LeitorArquivo.h"
#include "EscalonadorRoundRobin.h"
#include "EscalonadorSJFPreemptivo.h"
#include "EscalonadorPrioridade.h"
#include "login.h"

#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <sstream>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent, const QString &usuario)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , usuarioLogado(usuario)
{
    ui->setupUi(this);
    ui->labelQuantum->setVisible(true);
    ui->spinQuantum->setVisible(true);

    QString imagem = (usuarioLogado == "admin") ? ":/s2SO.png" : ":/AndreDaMoto.jpg";
    ui->textOutput->setStyleSheet(
        "background-image: url(" + imagem + ");"
                                            "background-repeat: no-repeat;"
                                            "background-position: center;"
                                            "background-color: #1E1E1E;"
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendOutput(const QString &text)
{
    QString linha = text.toHtmlEscaped();

    if (linha.contains("CONCLUIDO"))
        linha = "<span style='color:#4CAF50;'>" + linha + "</span>";
    else if (linha.contains("Page Fault"))
        linha = "<span style='color:#FF5252;'>" + linha + "</span>";
    else if (linha.contains("RELATORIO") || linha.contains("==="))
        linha = "<span style='color:#FFD700;'>" + linha + "</span>";
    else if (linha.contains("Tempo Medio") || linha.contains("Page Faults"))
        linha = "<span style='color:#64B5F6;'>" + linha + "</span>";
    else
        linha = "<span style='color:#E0E0E0;'>" + linha + "</span>";

    ui->textOutput->append("<pre style='margin:0;'>" + linha + "</pre>");
}

void MainWindow::on_btnBrowse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        "Selecionar arquivo CSV",
        "",
        "CSV Files (*.csv);;All Files (*)"
        );
    if (!fileName.isEmpty()) {
        ui->lineEditCSV->setText(fileName);
    }
}

void MainWindow::on_btnLimpar_clicked()
{
    ui->textOutput->clear();
    QString imagem = (usuarioLogado == "admin") ? ":/s2SO.png" : ":/AndreDaMoto.jpg";
    ui->textOutput->setStyleSheet(
        "background-image: url(" + imagem + ");"
                                            "background-repeat: no-repeat;"
                                            "background-position: center;"
                                            "background-color: #1E1E1E;"
        );
}

void MainWindow::on_comboEscalonador_currentIndexChanged(int index)
{
    // Mostra campo Quantum só para Round-Robin (índice 0)
    bool isRR = (index == 0);
    ui->labelQuantum->setVisible(isRR);
    ui->spinQuantum->setVisible(isRR);
}

void MainWindow::on_btnExecutar_clicked()
{
    // Pega os valores da interface
    QString csvPath = ui->lineEditCSV->text();
    if (csvPath.isEmpty()) {
        QMessageBox::warning(this, "Aviso", "Selecione um arquivo CSV primeiro!");
        return;
    }

    int ram        = ui->spinRAM->value();
    int tamFrame   = ui->spinFrame->value();
    int politica   = ui->comboPolitica->currentIndex() + 1; // 1=FIFO, 2=LRU, 3=Ótimo
    int escalonador = ui->comboEscalonador->currentIndex(); // 0=RR, 1=SJF, 2=Prio
    int quantum    = ui->spinQuantum->value();

    // Redireciona cout para capturar a saída dos escalonadores
    coutBuffer.str("");
    coutBuffer.clear();
    oldCoutBuf = std::cout.rdbuf(coutBuffer.rdbuf());

    // Carrega processos
    LeitorArquivo leitor(csvPath.toStdString());
    std::vector<Processo> processos = leitor.lerProcessosCSV();

    if (processos.empty()) {
        std::cout.rdbuf(oldCoutBuf);
        QMessageBox::warning(this, "Erro", "Nenhum processo carregado. Verifique o CSV.");
        return;
    }

    // Executa o escalonador escolhido
    if (escalonador == 0) {
        EscalonadorRoundRobin rr(processos, quantum, ram, politica, tamFrame);
        rr.executarSimulacao();
    } else if (escalonador == 1) {
        EscalonadorSJFPreemptivo sjf(processos, ram, politica, tamFrame);
        sjf.executarSimulacao();
    } else {
        EscalonadorPrioridade prio(processos, ram, politica, tamFrame);
        prio.executarSimulacao();
    }

    // Restaura cout e exibe saída
    std::cout.rdbuf(oldCoutBuf);
    ui->textOutput->clear();
    QString output = QString::fromStdString(coutBuffer.str());
    ui->textOutput->setStyleSheet("background-color: #1E1E1E;");
    for (const QString &linha : output.split("\n"))
        appendOutput(linha);
}

void MainWindow::on_btnSair_clicked()
{
    this->close();

}