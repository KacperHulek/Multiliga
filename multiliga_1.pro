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
    src/aktualizujwyniki.cpp \
    src/databasemanager.cpp \
    src/dodajgracza.cpp \
    src/dodajogloszenie.cpp \
    src/edycjadanych.cpp \
    src/edytujgraczawlidze.cpp \
    src/edytujlige.cpp \
    src/edytujwpis.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/menuopiekuna.cpp \
    src/ogloszenia.cpp \
    src/ranking.cpp \
    src/rejestracja.cpp \
    src/spotkania.cpp \
    src/wpiszwynikmeczu.cpp \
    src/zarzadzajligami.cpp \
    src/zmianahasla.cpp \
    src/zmianaloginu.cpp \
    src/zmiendatekolejki.cpp

HEADERS += \
    include/aktualizujwyniki.h \
    include/databasemanager.h \
    include/dodajgracza.h \
    include/dodajogloszenie.h \
    include/edycjadanych.h \
    include/edytujgraczawlidze.h \
    include/edytujlige.h \
    include/edytujwpis.h \
    include/mainwindow.h \
    include/menuopiekuna.h \
    include/ogloszenia.h \
    include/ranking.h \
    include/rejestracja.h \
    include/spotkania.h \
    include/wpiszwynikmeczu.h \
    include/zarzadzajligami.h \
    include/zmianahasla.h \
    include/zmianaloginu.h \
    include/zmiendatekolejki.h

FORMS += \
    ui/aktualizujwyniki.ui \
    ui/dodajgracza.ui \
    ui/dodajogloszenie.ui \
    ui/edycjadanych.ui \
    ui/edytujgraczawlidze.ui \
    ui/edytujlige.ui \
    ui/edytujwpis.ui \
    ui/mainwindow.ui \
    ui/menuopiekuna.ui \
    ui/ogloszenia.ui \
    ui/ranking.ui \
    ui/rejestracja.ui \
    ui/spotkania.ui \
    ui/wpiszwynikmeczu.ui \
    ui/zarzadzajligami.ui \
    ui/zmianahasla.ui \
    ui/zmianaloginu.ui \
    ui/zmiendatekolejki.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
