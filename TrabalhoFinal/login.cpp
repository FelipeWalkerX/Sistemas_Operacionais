#include "login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) : QDialog(parent) {
    setWindowTitle("Login - Simulador de SO");
    setFixedSize(320, 240);

    QVBoxLayout *layout = new QVBoxLayout(this);

    QLabel *labelTitulo = new QLabel("🖥️ Simulador de SO", this);
    labelTitulo->setAlignment(Qt::AlignCenter);
    labelTitulo->setStyleSheet("font-size: 12px; font-weight: bold; margin-bottom: 10px;");

    QLabel *labelUsuario = new QLabel("Usuário:", this);
    inputUsuario = new QLineEdit(this);
    inputUsuario->setPlaceholderText("Digite o usuário");

    QLabel *labelSenha = new QLabel("Senha:", this);
    inputSenha = new QLineEdit(this);
    inputSenha->setPlaceholderText("Digite a senha");
    inputSenha->setEchoMode(QLineEdit::Password);

    labelErro = new QLabel("", this);
    labelErro->setStyleSheet("color: red;");
    labelErro->setAlignment(Qt::AlignCenter);

    btnEntrar = new QPushButton("Entrar", this);
    btnEntrar->setStyleSheet("background-color: #4CAF50; color: white; font-weight: bold; padding: 6px;");

    layout->addWidget(labelTitulo);
    layout->addWidget(labelUsuario);
    layout->addWidget(inputUsuario);
    layout->addWidget(labelSenha);
    layout->addWidget(inputSenha);
    layout->addWidget(labelErro);
    layout->addWidget(btnEntrar);

    connect(btnEntrar, &QPushButton::clicked, this, &Login::tentarLogin);
    connect(inputSenha, &QLineEdit::returnPressed, this, &Login::tentarLogin);
    connect(inputUsuario, &QLineEdit::returnPressed, this, &Login::tentarLogin);
}

void Login::tentarLogin() {
    QString usuario = inputUsuario->text();
    QString senha = inputSenha->text();

    bool usuarioValido = (usuario == "admin" && senha == "admin") ||
                         (usuario == "andre" && senha == "daMoto");

    if (usuarioValido) {
        accept();
    } else {
        labelErro->setText("Usuário ou senha incorretos!");
        inputSenha->clear();
        inputSenha->setFocus();
    }
}