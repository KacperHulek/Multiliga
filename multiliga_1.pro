QT += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += "C:/Program Files (x86)/bcrypt/include"
LIBS += -L"C:/Program Files (x86)/bcrypt/lib" -lbcrypt


CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aktualizujwyniki.cpp \
    databasemanager.cpp \
    dodajgracza.cpp \
    dodajogloszenie.cpp \
    edycjadanych.cpp \
    edytujgraczawlidze.cpp \
    edytujlige.cpp \
    edytujwpis.cpp \
    main.cpp \
    mainwindow.cpp \
    menuopiekuna.cpp \
    ogloszenia.cpp \
    ranking.cpp \
    rejestracja.cpp \
    spotkania.cpp \
    wpiszwynikmeczu.cpp \
    zarzadzajligami.cpp \
    zmianahasla.cpp \
    zmianaloginu.cpp \
    zmiendatekolejki.cpp

HEADERS += \
    aktualizujwyniki.h \
    databasemanager.h \
    dodajgracza.h \
    dodajogloszenie.h \
    edycjadanych.h \
    edytujgraczawlidze.h \
    edytujlige.h \
    edytujwpis.h \
    mainwindow.h \
    menuopiekuna.h \
    ogloszenia.h \
    ranking.h \
    rejestracja.h \
    spotkania.h \
    wpiszwynikmeczu.h \
    zarzadzajligami.h \
    zmianahasla.h \
    zmianaloginu.h \
    zmiendatekolejki.h

FORMS += \
    aktualizujwyniki.ui \
    dodajgracza.ui \
    dodajogloszenie.ui \
    edycjadanych.ui \
    edytujgraczawlidze.ui \
    edytujlige.ui \
    edytujwpis.ui \
    mainwindow.ui \
    menuopiekuna.ui \
    ogloszenia.ui \
    ranking.ui \
    rejestracja.ui \
    spotkania.ui \
    wpiszwynikmeczu.ui \
    zarzadzajligami.ui \
    zmianahasla.ui \
    zmianaloginu.ui \
    zmiendatekolejki.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
