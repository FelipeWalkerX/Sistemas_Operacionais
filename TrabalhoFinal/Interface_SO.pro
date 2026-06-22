QT += widgets
CONFIG += c++17

SOURCES += \
    EscalonadorPrioridade.cpp \
    EscalonadorRoundRobin.cpp \
    EscalonadorSJFPreemptivo.cpp \
    GerenciadorMemoria.cpp \
    LeitorArquivo.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    EscalonadorPrioridade.h \
    EscalonadorRoundRobin.h \
    EscalonadorSJFPreemptivo.h \
    GerenciadorMemoria.h \
    LeitorArquivo.h \
    login.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos.qrc