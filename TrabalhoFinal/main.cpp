#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    while (true) {
        Login login;
        if (login.exec() != QDialog::Accepted) {
            break;
        }

        MainWindow w(nullptr, login.getUsuario());
        w.show();
        a.exec();
    }

    return 0;
}