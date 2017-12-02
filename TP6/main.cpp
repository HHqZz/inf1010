
/*************************************************************
* Titre: Travail pratique #6 - Interface Graphique
* Date:  02 Decembre 2017
* Auteur : Constantin Bouis 1783438 et Xavier Ralay 1786307
**************************************************************/


#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
