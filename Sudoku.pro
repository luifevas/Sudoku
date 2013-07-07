#-------------------------------------------------
#
# Project created by QtCreator 2013-06-19T21:53:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sudoku
TEMPLATE = app


SOURCES += main.cpp\
        sudoku.cpp \
    ventanaprincipal.cpp \
    eleccion.cpp \
    instrucciones.cpp \
    acercade.cpp \
    ranking.cpp \
    jugador.cpp

HEADERS  += sudoku.h \
    ventanaprincipal.h \
    eleccion.h \
    instrucciones.h \
    acercade.h \
    ranking.h \
    jugador.h

FORMS    += sudoku.ui \
    ventanaprincipal.ui \
    eleccion.ui \
    instrucciones.ui \
    acercade.ui \
    ranking.ui
