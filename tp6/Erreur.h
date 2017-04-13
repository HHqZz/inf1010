/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#ifndef ERREUR_H
#define ERREUR_H

using namespace std;


/**********************************************************************************************
 * Description      : Classe pour catcher l'exception de division par zero
 **********************************************************************************************/
class InvalidValueExceptionDivideZero : public logic_error
{
public:
  // Constructeur par defaut
    InvalidValueExceptionDivideZero();

};


InvalidValueExceptionDivideZero::InvalidValueExceptionDivideZero() : logic_error("Exception division par 0 impossible !")
{
}



/**********************************************************************************************
 * Description      : Classe pour catcher l'exception de l'inverse par zero
 **********************************************************************************************/
class InvalidValueExceptionInverseZero : public logic_error
{
public:
  // Constructeur par defaut
    InvalidValueExceptionInverseZero();

};


InvalidValueExceptionInverseZero::InvalidValueExceptionInverseZero() : logic_error("Exception inverse de 0 impossible !")
{
}



/**********************************************************************************************
 * Description      : Classe pour catcher l'exception de la racine carre d'un nombre negatif
 **********************************************************************************************/
class InvalidValueExceptionNegativeSqrt : public logic_error
{
public:
  // Constructeur par defaut
    InvalidValueExceptionNegativeSqrt();

};


InvalidValueExceptionNegativeSqrt::InvalidValueExceptionNegativeSqrt() : logic_error("Exception racine carree negative impossible !")
{
}



#endif // ERREUR_H
