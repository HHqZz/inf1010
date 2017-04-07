/*********************************************************
* Titre: Travail pratique #6 - Calculatrice.cpp
* Date:  19 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#ifndef ERREUR_H
#define ERREUR_H

using namespace std;
class InvalidValueException : public logic_error
{
public:
    InvalidValueException(string what_arg = "");

};

#endif // ERREUR_H
InvalidValueException::InvalidValueException(string
what_arg) : logic_error(what_arg)
{
}
