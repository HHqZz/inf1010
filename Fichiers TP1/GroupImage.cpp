#include "GroupImage.h"
#include "Const.h"
#include "Image.h"

GroupImage::GroupImage() : type_("unknown"),nombreImages_(0),capaciteImages_(0),images_(nullptr)
{
}
GroupImage::~GroupImage()
{
	delete images_;
}

GroupImage::GroupImage(const string &type, unsigned int capaciteImages) : type_(type),nombreImages_(0),capaciteImages_(capaciteImages),images_(nullptr)
{
}

void GroupImage::modifierType(const string &type)
{
	type_ = type;
}
string GroupImage::obtenirType() const
{
	return type_;
}
Image GroupImage::obtenirImage(unsigned int indiceImage) const
{
	return *image[indiceImage];
}
unsigned int GroupImage::obtenirNombreImages() const
{
	return nombreImages_;
}
void GroupImage::ajouterImage(const Image &image)
{

}
void GroupImage::afficherImages() const
{

}
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage)
{
}
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage)
{

}