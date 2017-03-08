/********************************************
* Titre: Travail pratique #2 - Main.cpp
* Date: Mardi 7	février	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/
#include <string>
#include <iostream>
#include "Infirmier.h"
#include "Personnel.h"
#include "Const.h"
#include "Hopital.h"
#include "Medecin.h"
#include "Specialite.h"

using namespace std;

int main()
{
	// C'est a vous de voir si vous devez allouer dynamiquement ou non les elements

	//1-  Creez 11 objets du type Infirmier � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// A COMPLETER...
    Infirmier inf1("nomInfirmier1","prenomInfirmier1",3);
    Infirmier inf2("nomInfirmier2","prenomInfirmier2",1);
    Infirmier inf3("nomInfirmier3","prenomInfirmier3",5);
    Infirmier inf4("nomInfirmier4","prenomInfirmier4",2);
    Infirmier inf5("nomInfirmier5","prenomInfirmier5",6);
    Infirmier inf6("nomInfirmier6","prenomInfirmier6",3);
    Infirmier inf7("nomInfirmier7","prenomInfirmier7",8);
    Infirmier inf8("nomInfirmier8","prenomInfirmier8",5);
    Infirmier inf9("nomInfirmier9","prenomInfirmier9",1);
    Infirmier inf10("nomInfirmier10","prenomInfirmier10",9);
    Infirmier inf11("nomInfirmier11","prenomInfirmier11",10);
    
	//2-  Creez deux objets du type Personnel � l'aide du constructeur par d�faut
	// A COMPLETER...
    Personnel pers1;
    Personnel pers2;
    
	//3 - Creez deux objects de type Hopital qui vont prendre chacun en parametre le nom de l'hopital et le personnel assigné
	// Hopital Sacré-Coeur de Montréal
	// Hôpital Jean-Talon
	// A COMPLETER...
    Hopital hop1("Hopital Sacré-Coeur de Montréal", &pers1);
    Hopital hop2("Hôpital Jean-Talon", &pers2);
	//4-  Ajoutez les 6 objets du type Infimier � au personnel de l'Hôpital Sacré-Coeur de Montréal
	// A COMPLETER...
    pers1 += &inf1;
    pers1 += &inf2;
    pers1 += &inf3;
    pers1 += &inf4;
    pers1 += &inf5;
    pers1 += &inf6;
    
	//5-  Ajoutez les 5 objets qui restent du type Infimier � au personnel de l'Hôpital Jean-Talon
	// A COMPLETER...
    pers2 += &inf7;
    pers2 += &inf8;
    pers2 += &inf9;
    pers2 += &inf10;
    pers2 += &inf11;
    
	//6-  Creez 7 objets du type Specialite � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Specialites : Chirurgie, Demartologie, Gastrologie, Sport, Podologie, Pediatrie, Psychiatrie
	// A COMPLETER...
    Specialite spec1("Chirurgie",3);
    Specialite spec2("Demartologie",2);
    Specialite spec3("Gastrologie",1);
    Specialite spec4("Sport",4);
    Specialite spec5("Podologie",5);
    Specialite spec6("Pediatrie",6);
    Specialite spec7("Psychiatrie",7);
    
	//7- Creez 7 autres objets du type Medecin � l'aide du constructeur par param�tre avec des valeurs de votre choix
	// Dr. Franc : en Chirurgie
	// Dr. Sherlock : en Demartologie
	// Dr. Holmes : en Gastrologie
	// Dr. Jean : en Podologie
	// Dr. Jules : en Pediatrie
	// Dr. Kyle : en Sport
	// Dr. House : en Psychiatrie
	// A COMPLETER...
    Medecin med1("Franc", 8, &spec1);
    Medecin med2("Sherlock", 9, &spec2);
    Medecin med3("Holmes", 10, &spec3);
    Medecin med4("Jean", 11, &spec5);
    Medecin med5("Jules", 12, &spec6);
    Medecin med6("Kyle", 8, &spec4);
    Medecin med7("House", 5, &spec7);
    
	//8- Creer un autre medecin Sherlock en utilisant l'opérateur = et en utilisant le medecin existante Sherlock.
    Medecin med8 = med2;
	// Le horaire du deuxieme Sherlock devrai ensuite etre modifie pour une valeur differnte du premier Sherlock
	// A COMPLETER...
    med8.modifierHoraires(8);
    
	//9- Creer un autre medecin Holmes en utilisant le constructeur de copie et en utilisant le medecin existante Holmes.
	// Le horaire du deuxieme Holmes devrai ensuite etre modifie pour une valeur differnte du premier Holmes
	// A COMPLETER...
    Medecin med9(med3);
	
	//10- Ajoutez les medecins : parmis le personnel de l'hopital Sacré-Coeur : 
	// Dr. Franc, Dr. Sherlock, Dr. Holmes, Dr. Jean, Dr. Jules
	// A COMPLETER...
	// Dr. Sherlock(2), Dr. Holmes(2), Dr. Kyle, Dr. House
	// A COMPLETER...
    pers1 += &med1;
    pers1 += &med2;
    pers1 += &med3;
    pers1 += &med4;
    pers1 += (&med5);
    pers1 += (&med8);
    pers1 += (&med9);
    pers1 += (&med6);
    pers1 += (&med7);
    
    

	//11- Retirer le medecin Jean et deux infirmiers de l'hopital Sacré-Coeur et ajouter les
	// a l'hopital Jean-talon
    pers1.retirerMedecin("Jean");
    pers1 -= (&inf1);
    pers1 -= (&inf2);
    pers2 += (&med4);
    pers2 += (&inf1);
    pers2 += (&inf2);

    
	//12- Faites afficher l'hopital Sacré-Coeur puis Jean-Talon
	// A COMPLETER...
	
	cout << hop1;
	cout << hop2;
	return 0;
}


/*
1. Quelle	est	l’utilité	de	l’opérateur	=	et	du	constructeur	par	copie	?

l'utilité du constructeur par copy et de l'opérateur = est d'éviter la copie attribut par attribut lorsqu'on affecte un objet d'une classe vers un autre objet d'une meme classe par le constructeur de copie généré automatiquement par le compilateur.


2. Dans	quel	cas	est-il	absolument	nécessaire	de	les	implémenter	?

 
 Il est necessaire de les implémenter si on a un membre pointeur de façon a assurer la duplication correcte de la zone pointée(pour faire le Deep Copy).



3. Qu’est-ce	qui	différencie	l’opérateur	=	du	constructeur	par	copie	?
un constructeur par copie produit un nouvel objet de même valeur qu'un existant, et un opérateur d'affectation affecte l'objet existant sur lequel est appelé l'opérateur à la valeur d'un autre objet existant.


*/
