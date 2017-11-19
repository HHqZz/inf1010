#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE
#include <string>


#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"

using namespace std;

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	bool AssocierImage(GroupeImage* groupe, Image* image) {
		int tempSize = listImage_.size(); // stocke taille actuelle de la liste dimage
		ajouter(image); // met a jour limage dans la base de donnee

		if (groupe->ajouterImage(image) &&  // check si le groupe a bien ajoute
			tempSize != listImage_.size()) // check si la liste dimage a bien ete mise a jour
				return true;
		else return false;
		
	}
	
	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
		bool retirer = groupe->retirerImage(nomImage);
		if (retirer) {
			supprimer(groupe->obtenirImage(nomImage));
		}
		return retirer;
		
	}
	
	/*	
		Operateur << : cette méthode affiche le contenu de la base de données. Le format
		est laissé à votre discrétion, mais on voudrait minimalement voir le nombre de
		groupes et d’images dans la base de données ainsi que leur noms.
	*/
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {
		
		// Creation des iterateurs
		auto itGroupe = dataBase.listGroupeImage_.begin();
		auto itGroupeEnd = dataBase.listGroupeImage_.end();
		auto itImage = dataBase.listImage_.begin();
		auto itImageEnd = dataBase.listImage_.end();
		//------------
		int nbImageListGrpImage = (*itGroupe)->obtenirNombreImages();
		int compteur = 0;
		

		// Affichage
		os << "-------------------------------------------------------------------------" << endl;
		os << " Affichage de la base de donnees Specifique : " << endl;
		os << "-------------------------------------------------------------------------" << endl << endl;
	
		for (itGroupe;itGroupe != itGroupeEnd; itGroupe++) {
			os << "Groupe image ";
			os << compteur;
			os << " contient :"; 
			os << nbImageListGrpImage << " images qui sont les suivantes : " << endl;
			//(*itGroupe)->afficherNomsImages();
			compteur++;

		}
		return  os;
	}

};
#endif
