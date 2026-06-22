#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class Login : public QDialog {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    QString getUsuario() const { return inputUsuario->text(); }

private slots:
    void tentarLogin();

private:
    QLineEdit *inputUsuario;
    QLineEdit *inputSenha;
    QPushButton *btnEntrar;
    QLabel *labelErro;
};

#endif