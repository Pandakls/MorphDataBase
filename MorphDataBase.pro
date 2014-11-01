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
    model/entities/character.cpp \
    model/items/item.cpp \
    model/masteries/mastery.cpp \
    model/ability/spell.cpp \
    model/items/jewel.cpp \
    model/items/armor.cpp \
    model/items/garment.cpp \
    model/items/potion.cpp \
    model/items/weapon.cpp \
    model/entities/stats.cpp \
    model/masteries/masterybonus.cpp \
    controler/worldcontroler.cpp \
    controler/world.cpp \
    model/entities/entity.cpp \
    model/entities/monster.cpp \
    model/entities/clique.cpp \
    model/ability/gift.cpp

HEADERS  += mainwindow.h \
    GadToolKit.h \
    dice/dice.h \
    model/entities/character.h \
    model/items/item.h \
    model/masteries/mastery.h \
    model/ability/spell.h \
    model/items/jewel.h \
    model/items/armor.h \
    model/items/garment.h \
    model/items/potion.h \
    model/items/weapon.h \
    model/items/buff.h \
    model/entities/stats.h \
    model/masteries/masterybonus.h \
    controler/worldcontroler.h \
    controler/world.h \
    GadGeom.h \
    model/entities/entity.h \
    model/entities/monster.h \
    model/entities/clique.h \
    model/ability/gift.h

FORMS    += mainwindow.ui
