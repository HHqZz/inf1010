/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#include<QtGui>

#include"Bouton.h"

Bouton::Bouton(const QString &text, QWidget *parent): QToolButton(parent)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    setText(text);
}

QSize Bouton::sizeHint() const
{
    QSize size = QToolButton::sizeHint();
    size.rheight() += 20;
    size.rwidth() = qMax(size.width(), size.height());
    return size;
}
