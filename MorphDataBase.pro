#-------------------------------------------------
#
# Project created by QtCreator 2014-07-22T17:40:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MorphDataBase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character/character.cpp \
    items/item.cpp \
    masteries/mastery.cpp \
    spells/spell.cpp \
    items/jewel.cpp \
    items/armor.cpp \
    items/garment.cpp \
    items/potion.cpp \
    items/weapon.cpp

HEADERS  += mainwindow.h \
    GadToolKit.h \
    dice/dice.h \
    character/character.h \
    items/item.h \
    masteries/mastery.h \
    spells/spell.h \
    items/jewel.h \
    items/armor.h \
    items/garment.h \
    items/potion.h \
    items/weapon.h

FORMS    += mainwindow.ui
