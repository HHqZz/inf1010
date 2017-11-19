//
// Created by Gabriel Bernard on 17-10-06.
//

#include "Pixel.h"

bool Pixel::operator==(const Pixel &p) const {
    return (this->retournerR() == p.retournerR() &&
            this->retournerG() == p.retournerG() &&
            this->retournerB() == p.retournerB());
}

bool Pixel::estMajoriteRouge()const {
	
	if (retournerR() > retournerB() && retournerR() > retournerG())
		return true;
	else
		return false;

}
bool Pixel::estMajoriteBleu()const {

	if (retournerB() > retournerR() && retournerB() > retournerG())
		return true;
	else
		return false;

}
bool Pixel::estMajoriteVert()const {

	if (retournerG() > retournerB() && retournerG() > retournerR())
		return true;
	else
		return false;

}

double Pixel::retournerIntensiteMoyenne() const {
	double intensite = 0;
	return intensite = (retournerB() + retournerG() + retournerR()) / (3*VALEUR_MAX_PIXEL);
}