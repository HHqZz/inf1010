
#include"Pixel.h"
#include"Const.h"


Pixel::Pixel()
{
  tauxVert_=0;
  tauxRouge_=0;
  tauxBleu_=0;
}

Pixel::Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu)
{
  tauxRouge_=tauxRouge ;
  tauxVert_=tauxVert ;
  tauxBleu_=tauxBleu ;
}

unsigned int Pixel::getTauxRouge()
{
  return tauxRouge_;
}


unsigned int Pixel::getTauxVert()
{
  return tauxVert_;
}


unsigned int Pixel::getTauxBleu()
{
  return tauxBleu_;
}

void Pixel::modifierTeinteRouge( int incrementRouge)
{
  tauxRouge_ += incrementRouge ;

  if (tauxRouge_> MAX_CONCENTRATION_COULEUR)
  {
    tauxRouge_=MAX_CONCENTRATION_COULEUR;
  }
  if (tauxRouge_<MIN_CONCENTRATION_COULEUR)
  {
    tauxRouge_=MIN_CONCENTRATION_COULEUR;
  }
}



void Pixel::modifierTeinteVert( int incrementVert)
{
  tauxVert_ += incrementVert ;

  if (tauxVert_> MAX_CONCENTRATION_COULEUR)
  {
    tauxVert_=MAX_CONCENTRATION_COULEUR;
  }
  if (tauxVert_<MIN_CONCENTRATION_COULEUR)
  {
    tauxVert_=MIN_CONCENTRATION_COULEUR;
  }
}



void Pixel::modifierTeinteBleu(int incrementBleu)
{
  tauxBleu_ += incrementBleu ;

  if (tauxBleu_> MAX_CONCENTRATION_COULEUR)
  {
    tauxBleu_=MAX_CONCENTRATION_COULEUR;
  }
  if (tauxBleu_<MIN_CONCENTRATION_COULEUR)
  {
    tauxBleu_=MIN_CONCENTRATION_COULEUR;
  }
}
