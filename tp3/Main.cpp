/********************************************
* Titre: Travail pratique #3 - Main.cpp
* Date: 17 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/
#include "Piece.h"
#include "Tour.h"
#include "Roi.h"
#include "Pion.h"
#include "Echiquier.h"
#include <iostream>

using namespace std;

int main()
{
	//1-  Creez un objet de type Roi à l'aide du constructeur par défaut.
/*
	Tour tour("1", "noir", 0, 5);
	Tour tour1("2", "blanc", 0, 6);
	Tour tour2("3", "blanc", 0, 7);
	tour2.deplacer(1, 7);
	cout << tour2.obtenirPositionX() << "," << tour2.obtenirPositionY() << endl;
	Tour tour3("4", "noir", 0, 8);
	Tour tour4("5", "blanc", 7, 7);
	Echiquier e1;
	e1.ajouterTour(tour);
	e1.ajouterTour(tour1);
	e1.ajouterTour(tour2);
	e1.ajouterTour(tour3);
	e1.enleverTour("2");
	//e1.enleverTour("4");
	e1.deplacerPiece("3", 7, 7);
	e1.ajouterTour(tour4);
	//cout << tour2.obtenirPositionX() << "," << tour2.obtenirPositionY() << endl; */
    
    Roi roi1;
    
    
	//2- Donnez l'id D1 au roi défini dans l'étape 1
	
    roi1.modifierId("D1");
    
	//3-  Définissez la position (3,0) pour le roi défini dans l'étape 1
	
    roi1.modifierPositionX(3);
    roi1.modifierPositionY(0);
    
	//4-  Creez un objet de type Roi Noir à la position (3,7) ayant comme id D8.
    
    Roi roi2("D8", "noir", 3, 7);

	//5-  Creez les huit pions blancs avec les coordonnées (i,1) i : 0-->7 et les id A2-->H2
	
    Pion pion1("A2", "blanc", 0, 1, true);
    Pion pion2("B2", "blanc", 1, 1, true);
    Pion pion3("C2", "blanc", 2, 1, true);
    Pion pion4("D2", "blanc", 3, 1, true);
    Pion pion5("E2", "blanc", 4, 1, true);
    Pion pion6("F2", "blanc", 5, 1, true);
    Pion pion7("G2", "blanc", 6, 1, true);
    Pion pion8("H2", "blanc", 7, 1, true);
    
	//6-  Creez les huit pions noirs avec les coordonnées (i,6) i : 0-->7 et les id A7-->H7
    
    Pion pion9("A7", "noir", 0, 6, true);
    Pion pion10("B7", "noir", 1, 6, true);
    Pion pion11("C7", "noir", 2, 6, true);
    Pion pion12("D7", "noir", 3, 6, true);
    Pion pion13("E7", "noir", 4, 6, true);
    Pion pion14("F7", "noir", 5, 6, true);
    Pion pion15("G7", "noir", 6, 6, true);
    Pion pion16("H7", "noir", 7, 6, true);

	//7-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)
	
    Tour tour1("A1", "blanc", 0, 0);
    Tour tour2("H1", "blanc", 7, 0);
    
	//8-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)
    
    Tour tour3("A8", "noir", 0, 7);
    Tour tour4("H8", "noir", 7, 7);
    
	//9-  Creez un Echiquier
	
    Echiquier echiquier;
    
	//10- Ajoutez toutes les pièces précidament définies à l'echiquier
	
    echiquier.ajouterRoi(roi1, 0);
    echiquier.ajouterRoi(roi2, 1);
    echiquier.ajouterPion(pion1);
    echiquier.ajouterPion(pion2);
    echiquier.ajouterPion(pion3);
    echiquier.ajouterPion(pion4);
    echiquier.ajouterPion(pion5);
    echiquier.ajouterPion(pion6);
    echiquier.ajouterPion(pion7);
    echiquier.ajouterPion(pion8);
    echiquier.ajouterPion(pion9);
    echiquier.ajouterPion(pion10);
    echiquier.ajouterPion(pion11);
    echiquier.ajouterPion(pion12);
    echiquier.ajouterPion(pion13);
    echiquier.ajouterPion(pion14);
    echiquier.ajouterPion(pion15);
    echiquier.ajouterPion(pion16);
    echiquier.ajouterTour(tour1);
    echiquier.ajouterTour(tour2);
	echiquier.ajouterTour(tour3);
	echiquier.ajouterTour(tour4);

	//11-  Deplacer la piece d'id A2 à la position (0,2)  --Deplacement de Pion
	
    echiquier.deplacerPiece("A2", 0, 2);

	//12-  Deplacer le piece d'id H7 à la position (7,4)  --Deplacement du Pion
	
    echiquier.deplacerPiece("H7", 7, 4);
    
	//13-  Deplacer la piece d'id A2 à la position (0,4)  --Deplacement du Pion
	
    echiquier.deplacerPiece("A2", 0, 4);
    
	//14-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	
    echiquier.deplacerPiece("H8", 7, 6);

	//15-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	
    echiquier.deplacerPiece("H8", 7, 6);
    
	//16-  Enlever la piece d'id A2
	
    echiquier.enleverPion("A2");
	
	return 0;
}

