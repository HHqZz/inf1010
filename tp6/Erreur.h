/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#ifndef ERREUR_H
#define ERREUR_H

using namespace std;
class InvalidValueExceptionDivideZero : public logic_error
{
public:
    InvalidValueExceptionDivideZero();

};


InvalidValueExceptionDivideZero::InvalidValueExceptionDivideZero() : logic_error("Exception division par 0 impossible !")
{
}

class InvalidValueExceptionInverseZero : public logic_error
{
public:
    InvalidValueExceptionInverseZero();

};


InvalidValueExceptionInverseZero::InvalidValueExceptionInverseZero() : logic_error("Exception inverse de 0 impossible !")
{
}

class InvalidValueExceptionNegativeSqrt : public logic_error
{
public:
    InvalidValueExceptionNegativeSqrt();

};


InvalidValueExceptionNegativeSqrt::InvalidValueExceptionNegativeSqrt() : logic_error("Exception racine carree negative impossible !")
{
}
#endif // ERREUR_H
