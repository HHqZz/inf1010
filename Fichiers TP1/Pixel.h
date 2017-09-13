#ifndef PIXEL_H
#define PIXEL_H




class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int getTauxRouge();
	unsigned int getTauxVert();
	unsigned int getTauxBleu();



	void afficherPixel() const;  // Pertinent ?

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif
