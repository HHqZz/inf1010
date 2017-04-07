/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#ifndef BOUTON_H
#define BOUTON_H

#include<QToolButton>

class Bouton : public QToolButton
{
    Q_OBJECT
public:
    Bouton(const QString &text, QWidget *parent = 0);
    QSize sizeHint() const;
};

#endif // BOUTON_H
