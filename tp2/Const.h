/********************************************
* Titre: Travail pratique #2 - Const.h
* Date: Mardi 7	f�vrier	2017
* Auteur:Constantin Bouis 1783438, Hammami Ahmed 1796523
*******************************************/

// Fichier contenant toutes les constantes utiles
/// Ne pas oublier d'inclure ce fichier dans les autres .cpp
#pragma once
const int espace_nom = 20;
const int espace_horaires = 10;
const int espace_domaine = 20;
const int espace_niveau = 10;
const int espace_chambre = 10;

const int espacement_medecin = espace_nom + 2*espace_horaires + espace_domaine + 2*espace_niveau;

const int espacement_infirmier = espace_nom + 2*espace_chambre;

const int espacement_hopital = espacement_medecin;
#define ESPACE ' '
#define EGALE '='
#define AFFICHAGE_REPITITIF(valeur, nombreRepitition) std::setfill (valeur) << std::setw(nombreRepitition) << ""
#define AFFICHER_ESPACE(nombreRepitition) AFFICHAGE_REPITITIF(ESPACE, nombreRepitition)
#define AFFICHER_EGALE(nombreRepitition) AFFICHAGE_REPITITIF(EGALE, nombreRepitition)
#define AFFICHER_LINE(nombreRepitition) AFFICHAGE_REPITITIF('-', nombreRepitition)
