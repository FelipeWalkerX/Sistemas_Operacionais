#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include "LeitorArquivo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, const QString &usuario = "");
    ~MainWindow();

private slots:
    void on_btnBrowse_clicked();
    void on_btnExecutar_clicked();
    void on_btnLimpar_clicked();
    void on_comboEscalonador_currentIndexChanged(int index);
    void on_btnSair_clicked();

private:
    Ui::MainWindow *ui;
    void appendOutput(const QString &text);
    std::streambuf *oldCoutBuf;
    std::stringstream coutBuffer;
    QString usuarioLogado;
};

#endif