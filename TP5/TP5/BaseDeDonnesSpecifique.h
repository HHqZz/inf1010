#ifndef BASE_DE_DONNES_SPECIFIQUE
#define BASE_DE_DONNES_SPECIFIQUE

#include "BaseDeDonnesGenerique.h"
#include "GroupeImage.h"
#include "Image.h"

class BaseDeDonnesSpecifique: public BaseDeDonnesGenerique<Image,GroupeImage>
{
public:
	bool AssocierImage(GroupeImage* groupe, Image* image);
	bool EnleverImage(GroupeImage* groupe, const std::string& nomImage);
	friend std::ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase);

};
#endif
