/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QLabel *labelCSV;
    QHBoxLayout *csvLayout;
    QLineEdit *lineEditCSV;
    QPushButton *btnBrowse;
    QLabel *labelRAM;
    QSpinBox *spinRAM;
    QLabel *labelFrame;
    QSpinBox *spinFrame;
    QLabel *labelEscalonador;
    QComboBox *comboEscalonador;
    QLabel *labelQuantum;
    QSpinBox *spinQuantum;
    QLabel *labelPolitica;
    QComboBox *comboPolitica;
    QSpacerItem *verticalSpacer;
    QPushButton *btnExecutar;
    QPushButton *btnLimpar;
    QPushButton *btnSair;
    QGroupBox *groupBoxSaida;
    QVBoxLayout *verticalLayout2;
    QTextEdit *textOutput;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 650);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMaximumSize(QSize(280, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        labelCSV = new QLabel(groupBox);
        labelCSV->setObjectName("labelCSV");

        verticalLayout->addWidget(labelCSV);

        csvLayout = new QHBoxLayout();
        csvLayout->setObjectName("csvLayout");
        lineEditCSV = new QLineEdit(groupBox);
        lineEditCSV->setObjectName("lineEditCSV");

        csvLayout->addWidget(lineEditCSV);

        btnBrowse = new QPushButton(groupBox);
        btnBrowse->setObjectName("btnBrowse");

        csvLayout->addWidget(btnBrowse);


        verticalLayout->addLayout(csvLayout);

        labelRAM = new QLabel(groupBox);
        labelRAM->setObjectName("labelRAM");

        verticalLayout->addWidget(labelRAM);

        spinRAM = new QSpinBox(groupBox);
        spinRAM->setObjectName("spinRAM");
        spinRAM->setMinimum(64);
        spinRAM->setMaximum(65536);
        spinRAM->setValue(200);

        verticalLayout->addWidget(spinRAM);

        labelFrame = new QLabel(groupBox);
        labelFrame->setObjectName("labelFrame");

        verticalLayout->addWidget(labelFrame);

        spinFrame = new QSpinBox(groupBox);
        spinFrame->setObjectName("spinFrame");
        spinFrame->setMinimum(1);
        spinFrame->setMaximum(1024);
        spinFrame->setValue(50);

        verticalLayout->addWidget(spinFrame);

        labelEscalonador = new QLabel(groupBox);
        labelEscalonador->setObjectName("labelEscalonador");

        verticalLayout->addWidget(labelEscalonador);

        comboEscalonador = new QComboBox(groupBox);
        comboEscalonador->addItem(QString());
        comboEscalonador->addItem(QString());
        comboEscalonador->addItem(QString());
        comboEscalonador->setObjectName("comboEscalonador");

        verticalLayout->addWidget(comboEscalonador);

        labelQuantum = new QLabel(groupBox);
        labelQuantum->setObjectName("labelQuantum");

        verticalLayout->addWidget(labelQuantum);

        spinQuantum = new QSpinBox(groupBox);
        spinQuantum->setObjectName("spinQuantum");
        spinQuantum->setMinimum(1);
        spinQuantum->setMaximum(100);
        spinQuantum->setValue(2);

        verticalLayout->addWidget(spinQuantum);

        labelPolitica = new QLabel(groupBox);
        labelPolitica->setObjectName("labelPolitica");

        verticalLayout->addWidget(labelPolitica);

        comboPolitica = new QComboBox(groupBox);
        comboPolitica->addItem(QString());
        comboPolitica->addItem(QString());
        comboPolitica->addItem(QString());
        comboPolitica->setObjectName("comboPolitica");

        verticalLayout->addWidget(comboPolitica);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnExecutar = new QPushButton(groupBox);
        btnExecutar->setObjectName("btnExecutar");
        btnExecutar->setMinimumSize(QSize(0, 40));

        verticalLayout->addWidget(btnExecutar);

        btnLimpar = new QPushButton(groupBox);
        btnLimpar->setObjectName("btnLimpar");

        verticalLayout->addWidget(btnLimpar);

        btnSair = new QPushButton(groupBox);
        btnSair->setObjectName("btnSair");

        verticalLayout->addWidget(btnSair);


        horizontalLayout->addWidget(groupBox);

        groupBoxSaida = new QGroupBox(centralwidget);
        groupBoxSaida->setObjectName("groupBoxSaida");
        verticalLayout2 = new QVBoxLayout(groupBoxSaida);
        verticalLayout2->setObjectName("verticalLayout2");
        textOutput = new QTextEdit(groupBoxSaida);
        textOutput->setObjectName("textOutput");
        textOutput->setReadOnly(true);
        QFont font;
        font.setFamilies({QString::fromUtf8("Courier New")});
        font.setPointSize(11);
        textOutput->setFont(font);

        verticalLayout2->addWidget(textOutput);


        horizontalLayout->addWidget(groupBoxSaida);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Simulador de SO", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Configura\303\247\303\265es", nullptr));
        labelCSV->setText(QCoreApplication::translate("MainWindow", "Arquivo CSV:", nullptr));
        lineEditCSV->setPlaceholderText(QCoreApplication::translate("MainWindow", "processos.csv", nullptr));
        btnBrowse->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        labelRAM->setText(QCoreApplication::translate("MainWindow", "RAM Total (MB):", nullptr));
        labelFrame->setText(QCoreApplication::translate("MainWindow", "Tamanho do Frame (MB):", nullptr));
        labelEscalonador->setText(QCoreApplication::translate("MainWindow", "Escalonador:", nullptr));
        comboEscalonador->setItemText(0, QCoreApplication::translate("MainWindow", "Round-Robin", nullptr));
        comboEscalonador->setItemText(1, QCoreApplication::translate("MainWindow", "SJF Preemptivo", nullptr));
        comboEscalonador->setItemText(2, QCoreApplication::translate("MainWindow", "Prioridade Preemptiva", nullptr));

        labelQuantum->setText(QCoreApplication::translate("MainWindow", "Quantum (Round-Robin):", nullptr));
        labelPolitica->setText(QCoreApplication::translate("MainWindow", "Pol\303\255tica de Substitui\303\247\303\243o:", nullptr));
        comboPolitica->setItemText(0, QCoreApplication::translate("MainWindow", "FIFO", nullptr));
        comboPolitica->setItemText(1, QCoreApplication::translate("MainWindow", "LRU", nullptr));
        comboPolitica->setItemText(2, QCoreApplication::translate("MainWindow", "\303\223timo", nullptr));

        btnExecutar->setText(QCoreApplication::translate("MainWindow", "\342\226\266 Executar Simula\303\247\303\243o", nullptr));
        btnLimpar->setText(QCoreApplication::translate("MainWindow", "Limpar", nullptr));
        btnSair->setText(QCoreApplication::translate("MainWindow", "Deslogar", nullptr));
        groupBoxSaida->setTitle(QCoreApplication::translate("MainWindow", "Sa\303\255da da Simula\303\247\303\243o", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
