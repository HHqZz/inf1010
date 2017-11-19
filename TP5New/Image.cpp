//
// Created by Gabriel Bernard on 17-09-08.
//

#include "Image.h"
#include "PixelCouleur.h"
#include "PixelBN.h"
#include "PixelGris.h"
#include <iostream>

using namespace std;

// Constructeur par defaut
Image::Image() : pixels_(nullptr), typeImage_(TypeImage::Couleurs) {
    hauteur_ = 0;
    largeur_ = 0;
    taille_ = 0;
}

// Constructeur par parametre
Image::Image(const std::string& cheminDuFichier, const TypeImage& type)
        : cheminVersImageOriginale_(cheminDuFichier), typeImage_(type), pixels_(nullptr)
{
    // Retrouver le nom du fichier image a partir du chemin sur disque
    size_t indice = cheminVersImageOriginale_.find_last_of("/\\");
    nomDuFichier_ = cheminVersImageOriginale_.substr(indice+1);
    lireImage();
}


// Constructeur par copie
Image::Image(const Image& image) {
    typeImage_ = image.typeImage_;
    hauteur_ = image.obtenirNombrePixelHauteur();
    largeur_ = image.obtenirNombrePixelLargeur();
    taille_ = image.obtenirTaille();
    cheminVersImageOriginale_ = image.obtenirCheminDuFichier();
    nomDuFichier_ = image.obtenirNomImage();
    pixels_ = new Pixel*[taille_];
    Pixel** autreDonneeImage = image.pixels_;

    // Copie profonde (Deep copy)
    for(unsigned int i = 0; i < taille_; i++) {
		pixels_[i] = autreDonneeImage[i]->retournerUneCopieProfonde();
    }
}

// Destructeur
Image::~Image() {
	for (unsigned int i = 0; i < taille_; i++) {
		delete pixels_[i];
		pixels_[i] = nullptr;
	}
    delete[] pixels_;
    pixels_ = nullptr;
    taille_ = 0;
    hauteur_ = 0;
    largeur_ = 0;
    cheminVersImageOriginale_ = "";
    nomDuFichier_ = "";
}

Image& Image::operator=(const Image &image) {
    if(this != &image) {
        // Destruction des attributs precedants
        for (unsigned int i = 0; i < taille_; i++) {
            delete pixels_[i];
            pixels_[i] = nullptr;
        }
        delete[] pixels_;

        // Copie des attributs de image
        hauteur_ = image.obtenirNombrePixelHauteur();
        largeur_ = image.obtenirNombrePixelLargeur();
        taille_ = image.obtenirTaille();
        cheminVersImageOriginale_ = image.obtenirCheminDuFichier();
        nomDuFichier_ = image.obtenirNomImage();
        pixels_ = new Pixel*[taille_];
        Pixel** autreDonneeImage = image.pixels_;

        // Copie profonde (Deep copy)
        for(unsigned int i = 0; i < taille_; i++) {
            pixels_[i] = autreDonneeImage[i]->retournerUneCopieProfonde();
        }
    }
    return *this;
}

void Image::convertirCouleur() {
    if(typeImage_ == TypeImage::Couleurs) {
        cout << "L'image est deja en couleur, conversion inutile" << endl;
        return;
    }

    PixelCouleur* nouveauPixel;
    for(unsigned int i = 0; i < taille_; i ++) {
        Pixel* p = pixels_[i];
        nouveauPixel = new PixelCouleur(p->retournerR(), p->retournerG(), p->retournerB());
        delete pixels_[i];
        pixels_[i] = nouveauPixel;
    }
    typeImage_ = TypeImage::Couleurs;
}

void Image::convertirGris() {
    if(typeImage_ == TypeImage::Gris) {
        cout << "L'image est deja en Nuance de Gris, conversion inutile" << endl;
        return;
    }

    PixelGris* nouveauPixel;
    for(unsigned int i = 0; i < taille_; i ++) {
        nouveauPixel = new PixelGris(pixels_[i]->convertirPixelGris());
        delete pixels_[i];
        pixels_[i] = nouveauPixel;
    }
    typeImage_ = TypeImage::Gris;
}

void Image::convertirBN() {
    PixelBN* nouveauPixel;
    for(unsigned int i = 0; i < taille_; i ++) {
        nouveauPixel = new PixelBN(pixels_[i]->convertirPixelBN());
        delete pixels_[i];
        pixels_[i] = nouveauPixel;
    }
    typeImage_ = TypeImage::NB;
}

void Image::mettreEnNegatif() {
    for(unsigned int i = 0; i < taille_; i++) {
        pixels_[i]->mettreEnNegatif();
    }
}

bool Image::estMajoriteRouge() const
{
	int compteur = 0;
	for (int i = 0; i < taille_; i++) {
		if (pixels_[i]->estMajoriteRouge())
			compteur++;

	}
	if (compteur > (taille_ / 2))
		return true;
	else return false;
}

bool Image::estMajoriteVert() const
{
	int compteur = 0;
	for (int i = 0; i < taille_; i++) {
		if (pixels_[i]->estMajoriteVert())
			compteur++;

	}
	if (compteur >(taille_ / 2))
		return true;
	else return false;	
}

bool Image::estMajoriteBleu() const
{
	int compteur = 0;
	for (int i = 0; i < taille_; i++) {
		if (pixels_[i]->estMajoriteBleu())
			compteur++;

	}
	if (compteur >(taille_ / 2))
		return true;
	else return false;
}

double Image::obtenirIntensiteMoyenne() const
{
	double intensite =0;
	for (unsigned int i = 0; i < taille_; i++)
		intensite += pixels_[i]->retournerIntensiteMoyenne();
	return ((double)(intensite / taille_));
}

bool Image::operator==(const Image& image) {
    bool retour = true;

    if (image.obtenirNomImage() != nomDuFichier_ ||
        image.obtenirNombrePixelHauteur() != hauteur_ ||
        image.obtenirNombrePixelLargeur() != largeur_) {
        retour = false;
    }
    else {
        for(unsigned int i = 0; i < taille_; i ++) {
            if (image.pixels_[i] != pixels_[i]){
                return false;
            }
        }
    }

    return retour;
}

bool Image::operator==(const string& nom) {
    return(nomDuFichier_ == nom);
}

bool operator==(const string& nom,  Image& image) {
    return image == nom;
}

std::ostream& operator<<(std::ostream& os, const Image& image) {

    os << "Nom de l'image :  " << image.nomDuFichier_ << endl;
    os << "Chemin de l'original : " << image.cheminVersImageOriginale_ << endl;
    os << "Taille de l'image : " << image.taille_ << " pixels"<< endl;
    os << "Resolution en pixels : "  << image.largeur_ << " x " << image.hauteur_ << endl;
    os << "Type de l'image : " << image.obtenirTypeEnString() << endl;
    return os;
}

// Accesseurs
std::string Image::obtenirCheminDuFichier() const {
    return cheminVersImageOriginale_;
}

std::string Image::obtenirNomImage() const {
    return nomDuFichier_;
}

unsigned int Image::obtenirNombrePixelHauteur() const {
    return hauteur_;
}

unsigned int Image::obtenirNombrePixelLargeur() const {
    return largeur_;
}

unsigned int Image::obtenirTaille() const {
    return taille_;
}

string Image::obtenirTypeEnString() const {
    string type_en_string;
    switch(typeImage_) {
        case TypeImage::Couleurs:
            type_en_string = "Couleurs";
            break;
        case TypeImage::Gris:
            type_en_string = "Nuances de Gris";
            break;
        case TypeImage::NB:
            type_en_string = "Noir et Blanc";
            break;
    }
    return type_en_string;
}

// Fonction sauvegarderImage
void Image::sauvegarderImage(const std::string &nomDuFichier) const {
	// Verification avant tentative d'ecriture du fichier sur disque
    if(pixels_ == nullptr) {
        cerr << "Il n'y a aucune donnee a ecrire sur le disque, pixels_ == nullptr" << endl;
        PAUSE;
        exit(1);
    }

    if(pixels_[taille_ - 1] == nullptr) {
        cerr << "Certains pixels ont la valeur nullptr, impossible d'ecrire l'image" << endl;
        PAUSE;
        exit(2);
    }

    // Ouverture d'un stream de sortie
	ofstream bmpOut(nomDuFichier.c_str(), ios::out | ios::binary);
	if (!bmpOut.is_open()) {
		cerr << "Erreur lors de la tentative d'ecriture du fichier." << endl;
		exit(12);
	}

	unchar *rgb = new unchar[taille_ * 3];
	for (unsigned int i = 0; i < taille_; i++) {
        Pixel* p = pixels_[i];
        if(p == nullptr) {
            cerr << "Pixels " << i << " a la valeur nullptr, impossible d'ecrire l'image sur disque" << endl;
            PAUSE;
            exit(2);
        }
		rgb[i * 3] = p->retournerR();
		rgb[i * 3 + 1] = p->retournerG();
		rgb[i * 3 + 2] = p->retournerB();
	}

	unsigned char* output;
	size_t output_size = bitmap_encode_rgb(rgb, largeur_, hauteur_, &output);
	bmpOut.write((char*)output, output_size);
	bmpOut.close();
	delete[] rgb;
	delete[] output;
}

// Fonctions de lecture d'une Image
void Image::lireImage() {
    if(pixels_ != nullptr) {
        unsigned int i;
        for(i = 0; i < taille_; i++) {
            delete pixels_[i];
            pixels_ = nullptr;
        }
        delete[] pixels_;
    }
    // Ouverture du stream entrant
    ifstream bmpIn(cheminVersImageOriginale_.c_str(), ios::in | ios::binary);

    // Si l'ouverture a echouee on quitte la fonction
    if(!bmpIn.is_open()) {
        cerr << "Erreur, le fichier " << cheminVersImageOriginale_ << " n'a pas pu etre ouvert." << endl;
        PAUSE;
        exit(9);
    }

    char info[54];

    bmpIn.read(info, 54);

    int offset = *(int*)&info[10];

    largeur_ = *(unsigned int*)&info[18];
    hauteur_ = *(unsigned int*)&info[22];

    short bytes = *(short*)&info[28];

    if (bytes != 24) {
        cerr << "This bmp is a " << bytes << " and this program only supports 24 bytes bmp files" << endl;
        PAUSE;
        exit(10);
    }

    taille_ = largeur_ * hauteur_;

    bmpIn.seekg(offset);

    pixels_ = new Pixel*[taille_];

    if (typeImage_ == Couleurs) {
        lirePixelsCouleur(bmpIn);
    } else if (typeImage_ == Gris) {
        lirePixelsGris(bmpIn);
    } else {
        lirePixelsBN(bmpIn);
    }
    bmpIn.close();

}

void Image::lirePixelsCouleur(std::ifstream &bmpIn) {
    unsigned int x, y, pos = 0;
    char tmp[3];
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            int indice = (hauteur_ - 1 - y) * largeur_ + x;
            bmpIn.read(tmp, 3);
            // Creation d'un nouveau pixel couleur pour chaque pixel de l'image
            pixels_[indice] = new PixelCouleur((unchar)tmp[2], (unchar)tmp[1], (unchar)tmp[0]);
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }
}

void Image::lirePixelsGris(std::ifstream &bmpIn) {
    unsigned int x, y, pos = 0;
    char tmp[3];
    int indice;
    unsigned int moyenne;
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            indice = (hauteur_ - 1 - y) * largeur_ + x;
            bmpIn.read(tmp, 3);	// Lit le bleu et le positionne a la derniere rangee
            moyenne = (unchar)tmp[0] + (unchar)tmp[1] + (unchar)tmp[2];
            moyenne /= 3;
            // Creation d'un nouveau pixel couleur pour chaque pixel de l'image
            pixels_[indice] = new PixelGris(moyenne);
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }
}

void Image::lirePixelsBN(std::ifstream &bmpIn) {
    unsigned int x, y, pos = 0;
    char tmp[3];
    unsigned int moyenne;
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            int indice = (hauteur_ - 1 - y) * largeur_ + x;
            bmpIn.read(tmp, 3);	// Lit les valeurs bgr
            moyenne = (unchar)tmp[0] + (unchar)tmp[1] + (unchar)tmp[2];
            moyenne /= 3;
            // Creation d'un nouveau pixel couleur pour chaque pixel de l'image
            pixels_[indice] = new PixelBN(moyenne > 127);
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }
}

