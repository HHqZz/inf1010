/*********************************************************
* Titre: Travail pratique #6 - main.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/


#include <QApplication>

#include "Calculatrice.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculatrice calc;
#if defined(Q_OS_SYMBIAN)
    calc.showMaximized();
#else
    calc.show();
#endif
    return app.exec();
}
