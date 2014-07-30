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
    model/character/character.cpp \
    model/items/item.cpp \
    model/masteries/mastery.cpp \
    model/spells/spell.cpp \
    model/items/jewel.cpp \
    model/items/armor.cpp \
    model/items/garment.cpp \
    model/items/potion.cpp \
    model/items/weapon.cpp \
    model/character/stats.cpp \
    model/masteries/masterybonus.cpp \
    controler/worldcontroler.cpp \
    controler/world.cpp \
    model/entity.cpp

HEADERS  += mainwindow.h \
    GadToolKit.h \
    dice/dice.h \
    model/character/character.h \
    model/items/item.h \
    model/masteries/mastery.h \
    model/spells/spell.h \
    model/items/jewel.h \
    model/items/armor.h \
    model/items/garment.h \
    model/items/potion.h \
    model/items/weapon.h \
    model/items/buff.h \
    model/character/stats.h \
    model/masteries/masterybonus.h \
    controler/worldcontroler.h \
    controler/world.h \
    GadGeom.h \
    model/entity.h

FORMS    += mainwindow.ui
