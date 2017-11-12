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
		//Remarque : cette modification doit �tre
		//refl�t�e dans le contenu de la base de donn�es aussi. ??????????
		//ajouter(image); ??
	}
	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage) {
		groupe->retirerImage(nomImage);
		//Remarque : cette modification
		//doit �tre refl�t�e dans le contenu de la base de donn�es aussi
		//supprimer(image);
	}

	/*	
		Operateur << : cette m�thode affiche le contenu de la base de donn�es. Le format
		est laiss� � votre discr�tion, mais on voudrait minimalement voir le nombre de
		groupes et d�images dans la base de donn�es ainsi que leur noms.
	*/
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {
		
		os << "-------------------------------------------" << endl;
		os << " Affichage de la base de donnees : " << endl;
		os << "-------------------------------------------" << endl;
		dataBase.listGroupeImage_.

	}

};
#endif
