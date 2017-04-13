/*********************************************************
* Titre: Travail pratique #5 - main.cpp
* Date:  04 Avril 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
**********************************************************/

#include <iostream>
#include <fstream>
#include <map>
#include "conteneurGenesListe.h"
#include "conteneurGenesMap.h"
#include "ConteneurGenes.h"

#include <cstddef>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{
	char c;
	ConteneurGenes* genes;

	// Le conteneur a deux implementations parmi lesquelles on choisit
	cout << "---  Voulez-vous utiliser la version liste (1) ou la version map (2) ? " << endl;
	do {
		cin.get(c);
	} while (c != '1' && c != '2');

	if (c == '1') {
		cout << "Utilisation de la version LISTE" << endl;
		genes = new ConteneurGenesListe();
	} else {
		cout << "Utilisation de la version MAP" << endl;
		genes = new ConteneurGenesMap();
	}

	//	ouverture du fichier de donnees
	ifstream fichier;
	fichier.open("genes.txt");
	if (fichier.fail()) {
		cout << "Fichier non trouve ! Mettez genes.txt avec le fichier projet  \n" << endl;
		return 1;
	}
	// Lecture des entrees de chaque gene
	string nom, description, espece, contenu, id;
	getline(fichier, id);
	while (!fichier.eof()) {
		getline(fichier,nom);
		getline(fichier,description);
		getline(fichier,espece);
		getline(fichier,contenu);
		genes->inserer(atoi(id.c_str()), nom, description, espece, contenu);
		getline(fichier,id);
	}
	fichier.close();



	cout << "----------------------------------------------------------" << endl;
	cout << "AFFICHAGE PAR ESPECE ET NOM\n" << endl;
	// !!!!  A FAIRE: afficher les g�nes par esp�ce et nom dans la sortie standard
	genes->afficherParEspeceEtNom(cout);

	cout << "----------------------------------------------------------" << endl;
	cout << "RECHERCHE DU GENE 25107" << endl;
	// !!!! A FAIRE: rechercher et afficher le g�ne ayant l'ID 25107
	// Le programme doit afficher "Le g�ne 25107 n'a pas �t� trouv�" si le g�ne n'est pas trouv�

	if (genes->trouver(25107) == nullptr)
		cout << "Le gene 25107 n'a pas ete trouve" << endl;
	else
		cout << genes->trouver(25107) << endl;


	cout << "----------------------------------------------------------" << endl;
	cout << "RETRAIT DU GENE 2290" << endl;
	// !!!! A FAIRE: retirer le g�ne 2290
	// Le programme doit afficher "Le g�ne a �t� retir�" si le retrait r�ussit,
	// ou bien "Le g�ne 2290 n'a pas �t� trouv�" si le retrait �choue
	if (genes->retirer(2290))
		cout << "Le gene 2290 a ete retire " << endl;
	else
		cout << "Le gene 2290 n'a pas ete trouve" << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "RETRAIT DE L'ESPECE HOMO SAPIENS" << endl;
	// !!!! A FAIRE: retirer tous les g�nes de l'esp�ce Homo sapiens
	// Le programme doit afficher le nombre de g�nes retir�s ("Nombre de genes retires = XX")
	cout << "nombre de genes retires = " << genes->retirerEspece("Homo sapiens") << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "RETRAIT DU GENE 552" << endl;
	// !!!! A FAIRE: retirer le g�ne 552
	// Le programme doit afficher "Le g�ne a �t� retir�" si le retrait r�ussit,
	// ou bien "Le g�ne 552 n'a pas �t� trouv�" si le retrait �choue
	if (genes->retirer(552))
		cout << "Le gene 552 a ete retire " << endl;
	else
		cout << "Le gene 552 n'a pas ete trouve " << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "MODIFICATION DU NOM DES GENES DE Mus musculus: Avpr1a-->XXXXX, Fmr1-->YYYYY et UwtA1-->ZZZZZ" << endl;
	// !!!! A FAIRE: modifier le nom des g�nes suivants pour l'esp�ce Mus musculus
	// G�ne Avpr1a --> nouveau nom = "XXXXX"
	// G�ne Fmr1 --> nouveau nom = "YYYYY"
	// G�ne UwtA1 --> nouveau nom = "ZZZZZ"
	// Le programme doit afficher le nombre de g�nes modifi�s ("Modification de XX nom(s) effectu�e")
	map<string, string> map;
	map.insert(make_pair("Avpr1a", "XXXXX"));
	map.insert(make_pair("Fmr1", "YYYYY"));
	map.insert(make_pair("UwtA1", "ZZZZZ"));
	cout << "nombre de gene modifies = " << genes->modifierNoms("Mus musculus", map) << endl;

	cout << "----------------------------------------------------------" << endl;
	cout << "AFFICHAGE PAR LONGEUR\n" << endl;
	// !!!! A FAIRE: afficher les g�nes par longueur
	genes->afficherParLongueur(cout);


	// !!!! A FAIRE: N'OUBLIEZ PAS DE R�PONDRE AUX QUESTIONS DANS UN FICHIER TEXTE !!!!


	delete genes;

	return 0;
}
