/********************************************
* Titre: Travail pratique #4 - Main.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Piece.h"
#include "Roi.h"
#include "Tour.h"
#include "Pion.h"
#include "Echiquier.h"

#include <string.h>
#include <iostream>

using namespace std;

int main()
{
	//1-  Creez les huit pions blancs avec les coordonnées (i,1) i : 0-->7 et les id A2-->H2
	Pion* pion0 = new Pion("A2", "blanc", 0, 1);
	Pion* pion1 = new Pion("B2", "blanc", 1, 1);
	Pion* pion2 = new Pion("C2", "blanc", 2, 1);
	Pion* pion3 = new Pion("D2", "blanc", 3, 1);
	Pion* pion4 = new Pion("E2", "blanc", 4, 1);
	Pion* pion5 = new Pion("F2", "blanc", 5, 1);
	Pion* pion6 = new Pion("G2", "blanc", 6, 1);
	Pion* pion7 = new Pion("H2", "blanc", 7, 1);
	//2-Creez les huit pions noirs avec les coordonnées (i,6) i : 0-->7 et les id A7-->H7
	Pion* pion00 = new Pion("A7", "noir", 0, 7);
	Pion* pion01 = new Pion("B7", "noir", 1, 7);
	Pion* pion02 = new Pion("C7", "noir", 2, 7);
	Pion* pion03 = new Pion("D7", "noir", 3, 7);
	Pion* pion04 = new Pion("E7", "noir", 4, 7);
	Pion* pion05 = new Pion("F7", "noir", 5, 7);
	Pion* pion06 = new Pion("G7", "noir", 6, 7);
	Pion* pion07 = new Pion("H7", "noir", 7, 7);
	//3-  Creez les deux tours blanches d'id "A1" et "H1" dans les positions respectives (0,0) et (7,0)
	Tour* tour1 = new Tour("A1", "blanc", 0, 0);
	Tour* tour2 = new Tour("H1", "blanc", 7, 0);
	//4-  Creez les deux tours noires  d'id "A8" et "H8" dans les positions respectives (0,7) et (7,7)
	Tour* tour01 = new Tour("A8", "noir", 0, 0);
	Tour* tour02 = new Tour("H8", "noir", 7, 0);
	//5-  Creez les Fous blanc et noirs
	Fou* fou1 = new Fou("C1", "blanc", 2, 0);
	Fou* fou2 = new Fou("F1", "blanc", 5, 0);
	Fou* fou01 = new Fou("C8", "noir", 2, 7);
	Fou* fou02 = new Fou("F8", "noir", 5, 7);
	//6-  Creez les deux reines E1 et E8	
	Reine* reine1 = new Reine("E1", "blanc", 4, 0);
	Reine* reine01 = new Reine("E8", "noir", 4, 7);
	//7-  Creez les deux rois D1 et D8
	Roi* roi1 = new Roi("D1", "blanc", 5, 0);
	Roi* roi01 = new Roi("D8", "noir" ,3 ,7);
	// 8- Creez un echiquier 
	Echiquier echiquier;
	cout << "----------AJOUT DES PIECES----------" << endl;
	//9- Ajoutez toutes les pièces précidament définies à l'echiquier	
	echiquier += pion0;
	echiquier += pion1;
	echiquier += pion2;
	echiquier += pion3;
	echiquier += pion4;
	echiquier += pion5;
	echiquier += pion6;
	echiquier += pion7;
	echiquier += pion00;
	echiquier += pion01;
	echiquier += pion02;
	echiquier += pion03;
	echiquier += pion04;
	echiquier += pion05;
	echiquier += pion06;
	echiquier += pion07;
	echiquier += tour1;
	echiquier += tour2;
	echiquier += tour01;
	echiquier += tour02;
	echiquier += fou1;
	echiquier += fou2;
	echiquier += fou01;
	echiquier += fou02;
	echiquier += reine1;
	echiquier += reine01;
	echiquier += roi1;
	echiquier += roi01;
	cout << "----------TEST DES DEPLACEMENTS------------" << endl;
	//10-  Deplacer la piece d'id A2 à la position (0,2)  --Deplacement de Pion
	echiquier.deplacerPiece("A2", 0, 2);
	//11-  Deplacer le piece d'id H7 à la position (7,4)  --Deplacement du Pion
	echiquier.deplacerPiece("H7", 7, 4);
	echiquier.deplacerPiece("D2", 4, 1);
	echiquier.deplacerPiece("A1", 0, 4);
	//12-  Deplacer la piece d'id A2 à la position (0,4)  --Deplacement du Pion
	echiquier.deplacerPiece("A2", 0, 4);
	//13-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	echiquier.deplacerPiece("H8", 7, 6);
	//14-  Deplacer la piece d'id H8 à la position (7,6)  --Deplacement de la Tour
	echiquier.deplacerPiece("H8", 7, 6);
	//15-  Enlever la piece d'id A2 
	echiquier -= "A2";
	
	cout << "----------TEST DES PROMOTIONS------------" << endl;
	
	//16- Promouvoir la piece d'id F6. 
	echiquier.promouvoir("F6");
	//17- Promouvoir la piece d'id B2.	
	echiquier.promouvoir("B2");
	
	//18- Affichage de l'Echiquier
	cout << echiquier;
	//Si vous avez besoin de lancer avec un arret a la fin, faites ctrl+F5;


	delete pion0;
    delete pion1;
    delete pion2;
    delete pion3;
    delete pion4;
	delete pion5;
	delete pion6 ;
	delete pion7 ;
	
	delete pion00 ;
	delete pion01 ;
	delete pion02 ;
	delete pion03 ;
	delete pion04 ;
	delete pion05 ;
	delete pion06 ;
	delete pion07 ;
	
	delete tour1 ;
	delete tour2 ;

	delete tour01 ;
	delete tour02 ;

	delete fou1 ;
	delete fou2 ;
	delete fou01 ;
	delete fou02 ;
		
	delete reine1 ;
	delete reine01;
	
	delete roi1 ;
	delete roi01 ;
	return 0;
}

























