
#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"
#include <queue>
#include "BaseDeDonnesSpecifique.h"
#include "Foncteur.h"
#include <functional>

using namespace  std;

int main() {
	
	// Chemin vers les images
	string cheminLoad = "./Ensemble d'images/Originale/";
    // Nom des 6 images dans un tableau de string
	string image[9] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "Monkey.bmp","WiC.bmp","Sloth.bmp","Green.bmp"};

    // Creer un conteneur de type QUEUE et ajouter les images dans la queue
	cout << "**************************************************" << endl;
	cout << "Creation de la file de travail" << std::endl;
	cout << "**************************************************" << endl << endl;


	//Creez 3 GroupeImage
	

	// Creez un objet de type BaseDeDonnesSpecifique et ajoutez les 3 groupes a la base de donnes
	


	/*Faites repartir les elements de la queue de maniere uniforme et sequentielle dans les groupe
	 Vous devez avoir la composition suivante :
		groupe 1 a les images 0,3,6
		groupe 2 a les images 1,4,7
		groupe 3 a les images 2,5,8
	 ATTENTION : la repartition doit se faire dans une seule boucle ET vous devez utiliser les fonctions de l'objet de base de donnes
	 NB: La methode pop() de queue<> ne retourne pas l'element de la structure
	*/
	
	cout << "**************************************************" << endl;
	cout << "CHARGEMENT DES IMAGES\n\n";
	// TODO : Votre implementation ici

	
	cout << "**************************************************" << endl << endl;
	cout <<"AFFICHAGE DE LA BASE DE DONNESES\n";
	// TODO : Afficher la base de donnes au complet

	// Pour chaque groupe, generez un nombre aleatoire. Le nombre aleatoire doit toujours donner un index valide
	// ET appliquez les modifications suivantes aux images obtenues avec le nombre aleatoire
	//GROUPE 1 - Mettre en negatif
	


	//GROUPE 2 - Mettre en gris
	


	//GROUPE 3 - Mettre en noir et blanc
	



	/*
	 *TRAITEMENT DE GROUPE 1
	 *Calculer l'intensite moyenne des images du groupe 1 et l'afficher
	 */

	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA MOYENNE \n\n";
	// TODO : Votre implementation ici


	cout << "MOYENNES DES IMAGES DANS LA BASE DE DONNES: \n";


	// Trouver toutes les images avec une intensite moyenne plus petite que la valeur trouve et
	// afficher leur nom et leur moyenne
	// ATTENTION : Faire ceci avec une boucle for intelligente de type 
	//																for (Type variable : conteneur)


	cout << "**************************************************" << endl << endl;



	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA TAILLE \n\n";
	// TODO : Votre implementation ici

	/*
	 *TRAITEMENT DE GROUPE 2
	 * Calculer la taille moyenne des images dans le groupe 2 et afficher l'afficher
	 */
	


	// Afficher le nombre d'images dans la base de donnes
	cout << "Nombre d'images totales dans la base de donnes " << dataBase.obtenirListImages().size() << endl;

	// Trouver at afficher le nombre d'images qui ont une taille plus grande que la moyenne calculee
	// Utiliser les fonctions std::bind et std::placeholders pour effectuer le travail

	// Decommenter et Remplacer les variables X,Y, Z par les bons elements 
	/*
	 MonFoncteur foncteurTaille;
	 groupeImage2->supprimerElements(
		std::bind(
			X, //A COMPLETER générer un opérateur > pour les entiers
			//Le bind ci-dessous permet d'appeler la méthode obtenirTaile de la
			//Image* passée en argument du foncteur lors des appels de ce dernier dans supprimerElements
			std::bind(
				foncteurTaille,
				Y //A COMPLETER utiliser le premier placeholder (attention aux namespace) (reçoit une Image*)
				),
			Z //A COMPLETER comparer à taille Moyenne
			)
		);
	 */

	// Calculer le nombre d'images avec une taille superieure a la taille moyenne
	// ASTUCE: utilisez la STL et les fonctions de decompte conditionel

	// Afficher le nombre d'images dans la base de donnes avec une taille plus grande que la moyenne
	cout << "Nombre d'images dont la taille est plus grande que la moyenne " << "REMPLACEZ CA AVEC LA TAILLE" << endl;
	
	cout << "**************************************************" << endl << endl;


	/*
	 *TRAITEMENT DU GROUPE 3
	 *
	 *Mettre tout les images du groupe 3 en noir et blanc et sauvegarder
	 *ATTENTION : Vous devez utiliser la fonction generique "appliquerFoncteurUnaire"  demandee dans au TP5 et non une boucle sur les elements
	 */

	cout << "**************************************************" << endl;
	cout << "CONVERSION EN NOIR ET BLANC \n";
	// TODO : Votre implementation ici

	cout << "**************************************************" << endl << endl;


    // Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}
/*

1 / Car on peut insérer ou retirer un élément nimporte ou en temps constant
	Le vecteur est plus avantageux dans le cas ou l'on a besoin d'acceder frequemment a des elements  a des positions aleatoires

2 / L'implemenetation des classes generiques se fait dans le .h et non dans le .cpp car quand le compilateur voit une classe generique, 
    il doit avoir acces a la fois a la definition mais aussi a l'implementation pour produire une verswion specifique de la classe.

*/