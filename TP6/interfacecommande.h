
/*************************************************************
* Titre: Travail pratique #6 - Interface Graphique
* Date:  02 Decembre 2017
* Auteur : Constantin Bouis 1783438 et Xavier Ralay 1786307
**************************************************************/

//
// InterfaceCommande
// Classe abstraite permettant d'identifier
// les commandes possedant des fonctions
// Executer et AnnulerCommande.
//

#ifndef INTERFACECOMMANDE_H
#define INTERFACECOMMANDE_H

class InterfaceCommande
{
public:
    InterfaceCommande() {};
    virtual ~InterfaceCommande() {};
    virtual void Executer() = 0;
    virtual void AnnulerCommande() = 0;
};

#endif // INTERFACECOMMANDE_H
