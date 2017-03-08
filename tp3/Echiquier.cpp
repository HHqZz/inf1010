/********************************************
* Titre: Travail pratique #3 - Echiquier.cpp
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Echiquier.h"


Echiquier::Echiquier(): capaciteTableauPion_(16), capaciteTableauTour_(4), compteurPion_(0), compteurTour_(0)
{
	tableauPions_ = new Pion [capaciteTableauPion_];
	tableauTours_ = new Tour [capaciteTableauTour_];
}

// Destructeur
Echiquier::~Echiquier()
{
	delete[] tableauPions_;
	delete[] tableauTours_;
	tableauPions_ = nullptr;
	tableauTours_ = nullptr;
}

// Methodes publiques

//Implementation de la methode pour ajouter un roi
void Echiquier::ajouterRoi(const Roi &unRoi, int position)
{
	rois_[position] = unRoi;
}

// Implementation de la methode pour ajouter une Tour
void Echiquier::ajouterTour(const Tour& uneTour)
{
	int nb_tours_noir = 0;												//verification du nbr de tours noirs et blanches dans l'echiquier
	int nb_tours_blanc = 0;
	for (int i = 0; i < compteurTour_; i++)														
		if (tableauTours_[i].obtenirCouleur() == "noir")
			nb_tours_noir++;
	nb_tours_blanc = compteurTour_ - nb_tours_noir;						//fin de la verification du nbr de tour selon la couleur

	if (compteurTour_ < capaciteTableauTour_)
	{
		if (uneTour.obtenirCouleur() == "noir" && nb_tours_noir < 2 )
			tableauTours_[compteurTour_++] = uneTour;
		else if (uneTour.obtenirCouleur() == "blanc" && nb_tours_blanc < 2)
			tableauTours_[compteurTour_++] = uneTour;
		else if (uneTour.obtenirCouleur() == "noir" && nb_tours_noir >= 2)
			cout << "il existe deja deux tours noirs dans l'echiquier" << endl;
		else if (uneTour.obtenirCouleur() == "blanc" && nb_tours_blanc >= 2)
			cout << "il existe deja deux tours blanches dans l'echiquier " << endl;
	}
	else
		cout << "vous avez atteint le nbr de tours maximal par echiquier" << endl;
}

// Implementation de la methode pour ajouter un pion
void Echiquier::ajouterPion(const Pion& unPion) 
{
	int nb_Pions_noir = 0;												//verification du nbr de pions noirs et blancs dans l'echiquier
	int nb_Pions_blanc = 0;
	for (int i = 0; i < compteurPion_; i++)
		if (tableauPions_[i].obtenirCouleur() == "noir")
			nb_Pions_noir++;
	nb_Pions_blanc = compteurPion_ - nb_Pions_noir;						//fin de la verification du nbr de pions selon la couleur

	if (compteurPion_ < capaciteTableauPion_)
	{
		if (unPion.obtenirCouleur() == "noir" && nb_Pions_noir < 8)
			tableauPions_[compteurPion_++] = unPion;
		else if (unPion.obtenirCouleur() == "blanc" && nb_Pions_blanc < 8)
			tableauPions_[compteurPion_++] = unPion;
		else if (unPion.obtenirCouleur() == "noir" && nb_Pions_noir >= 8)
			cout << "il existe deja huit pions noirs dans l'echiquier" << endl;
		else if (unPion.obtenirCouleur() == "blanc" && nb_Pions_blanc >= 8)
			cout << "il existe deja huit pions blanches dans l'echiquier " << endl;
	}
	else
		cout << "vous avez atteint le nbr de pions maximal par echiquier" << endl;
}

// Implementation de la methode pour enlever une Tour
void Echiquier::enleverTour(const string id)
{
	int i = trouverIdTour(compteurTour_, id, tableauTours_);
	if (i != -1)
	{
		compteurTour_--;
		for (int j = i; j < compteurTour_; j++)
			tableauTours_[j] = tableauTours_[j + 1];
	}
	Tour* TabIntermediaire = new Tour [capaciteTableauTour_];
	for (int i = 0; i < compteurTour_; i++)
		TabIntermediaire[i] = tableauTours_[i];
	tableauTours_ = TabIntermediaire;

	for (int i = 0; i < capaciteTableauTour_; i++)
		cout << tableauTours_[i].obtenirId() << endl;
}

// Implementation de la methode pour enlever un pion
void Echiquier::enleverPion(const string id) 
{
	int i = trouverIdPion(compteurPion_, id, tableauPions_);

	if (i != -1)
	{
		compteurPion_--;
		for (int j = i; j < compteurPion_; j++)
			tableauPions_[j] = tableauPions_[j + 1];
	}
	Pion* TabIntermediaire = new Pion [capaciteTableauPion_];
	for (int i = 0; i < compteurPion_; i++)
		TabIntermediaire[i] = tableauPions_[i];
	tableauPions_ = TabIntermediaire;

}

//Implementation de la methode pour deplacer une piece
void Echiquier::deplacerPiece(string id, int toX, int toY)
{
	for (int i = 0;  i < compteurPion_; i++)
	{
		if (id == tableauPions_[i].obtenirId())
			tableauPions_[i].deplacer(toX, toY);
	}
	for (int i = 0; i<compteurTour_; i++)
	{
		if (id == tableauTours_[i].obtenirId())
			tableauTours_[i].deplacer(toX, toY);
	}
	for (int i = 0; i<2; i++)
	{
		if (id == rois_[i].obtenirId())
			rois_[i].deplacer(toX, toY);
	}
}


// Implementation de la methode pour trouver l'ID d'une tour
int trouverIdTour(int compteur, const string &id, const Tour* tableau)
{
	int i = -1;
	
	do
	{
		i++;
	} while (i < compteur && tableau[i].obtenirId() != id);
	if (tableau[i].obtenirId() == id)
	{
		return i;
	}
	else
		return -1;
}


//Implementation de la methode pour trouver l'id d'un pion
int trouverIdPion(int compteur, const string &id, const Pion* tableau)
{
	int i = -1;
	do
	{
		i++;
	} while (i < compteur && tableau[i].obtenirId() != id);
	if (tableau[i].obtenirId() == id)
	{
		return i;
	}
	else
		return -1;
}

