#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	bool AssocierImage(GroupeImage* groupe, Image* image) {
		groupe->ajouterImage(image);
		//Remarque : cette modification doit être
		//reflétée dans le contenu de la base de données aussi. ??????????
		//ajouter(image); ??
	}
	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
		groupe->retirerImage(nomImage);
		//Remarque : cette modification
		//doit être reflétée dans le contenu de la base de données aussi
		//supprimer(image);
	}

	/*	
		Operateur << : cette méthode affiche le contenu de la base de données. Le format
		est laissé à votre discrétion, mais on voudrait minimalement voir le nombre de
		groupes et d’images dans la base de données ainsi que leur noms.
	*/
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {
		
		os << "-------------------------------------------" << endl;
		os << " Affichage de la base de donnees : " << endl;
		os << "-------------------------------------------" << endl;
		dataBase.listGroupeImage_.

	}

};
#endif
