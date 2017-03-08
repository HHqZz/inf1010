/********************************************
* Titre: Travail pratique #4 - Echiquier.cpp
* Date: 28 Fevrier 2017
*Auteur : Constantin Bouis 1783438, Hammami Ahmed 1796523
	*******************************************/

#include "Echiquier.h"
#include <time.h>

// Implementation du constructeur par defaut d'un echiquier
Echiquier::Echiquier() {}

// Implementation du destructeur d'echiquier
Echiquier::~Echiquier() 
{
	for (unsigned i = 0; i < vecteurPiecesBlanches_.size(); i++)
	{
		delete vecteurPiecesBlanches_[i];
		vecteurPiecesBlanches_[i] = nullptr;
		vecteurPiecesBlanches_.pop_back();
	}
	for (unsigned i = 0; i < vecteurPiecesNoires_.size(); i++)
	{
		delete vecteurPiecesNoires_[i];
		vecteurPiecesNoires_[i] = nullptr;
		vecteurPiecesNoires_.pop_back();
	}
}

//Implementation de la Surcharge operateur << 
std::ostream & operator<<(std::ostream & out, const Echiquier & echiquier)
{
	out << "------------INFORMATION PIECES BLANCHES------------" << endl;		// On affiche selon l'enonce
	out << "Il y a " << echiquier.vecteurPiecesBlanches_.size() << " Pieces blanches" << endl;	// le nombre de piece blanche
	for (int i = 0; i < echiquier.vecteurPiecesBlanches_.size(); i++) 
	{
		out << *echiquier.vecteurPiecesBlanches_[i]; // Pour chaque piece, on affiche sa couleur, son id
	}												// sa position actuelle
	out << endl;
	out << "------------INFORMATION PIECES NOIRES--------------" << endl; // On procede de meme pour les pieces noires
	out << "Il y a " << echiquier.vecteurPiecesNoires_.size() << " Pieces noires" << endl;
	for (int i = 0; i < echiquier.vecteurPiecesNoires_.size(); i++)
	{
		out << *echiquier.vecteurPiecesNoires_[i];
	}
	return out;
}

// Implementation de la methode pour deplacer une piece sur l'echiquier
bool Echiquier::deplacerPiece(const string& id, int toX, int toY)
{
	bool test = true;   
	bool test2 = true;
	int i = -1;
	do
	{
		i++;
		test = vecteurPiecesBlanches_[i]->obtenirId() == id;	// On teste le bonne obtention de l'id de la piece
	} while ( !test && i < vecteurPiecesBlanches_.size() - 1);
	
	int j = -1;
	do
	{
		j++;
		test2 = id == vecteurPiecesNoires_[j]->obtenirId();

	} while (  !test2 && j < vecteurPiecesNoires_.size() - 1);

	if (test)
	{
		if (vecteurPiecesBlanches_[i]->deplacer(toX, toY))
		{
			cout << "Deplacement de la piece reussi " << id << endl;
			return true;
		}
		
	}
	else if (test2)
	{
		if (vecteurPiecesNoires_[j]->deplacer(toX, toY))
		{
			cout << "Deplacement de la piece reussi " << id << endl;
			return true;
		}	
	}
	cout << "Mouvement non valide " << id << endl;
	return false;
}

// Implementation de la surcharge de l'operateur +=
Echiquier& Echiquier::operator+=(Piece* piece)
{
	int i = 0;
	int j = 0;
	bool test = true;
	bool test1 = true;
	while (i < vecteurPiecesBlanches_.size() && test)
	{
		if (piece->obtenirId() == vecteurPiecesBlanches_[i]->obtenirId())
			test = false;
		i++;
	}
	while (j < vecteurPiecesNoires_.size() && test1)
	{
		if (piece->obtenirId() == vecteurPiecesNoires_[j]->obtenirId())
			test1 = false;
		j++;
	}
		
		if ((test && test1) || (vecteurPiecesBlanches_.size() == 0 && vecteurPiecesNoires_.size() == 0))
		{
			if (piece->obtenirCouleur() == "blanc" && piece->obtenirType() == "class Pion")
				vecteurPiecesBlanches_.push_back(new Pion(piece->obtenirId(),piece->obtenirCouleur(),piece->obtenirPositionX(),piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "blanc" && piece->obtenirType() == "class Tour")
				vecteurPiecesBlanches_.push_back(new Tour(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "blanc" && piece->obtenirType() == "class Fou")
				vecteurPiecesBlanches_.push_back(new Fou(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "blanc" && piece->obtenirType() == "class Reine")
				vecteurPiecesBlanches_.push_back(new Reine(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "blanc" && piece->obtenirType() == "class Roi")
				vecteurPiecesBlanches_.push_back(new Roi(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "noir" && piece->obtenirType() == "class Pion")
				vecteurPiecesNoires_.push_back(new Pion(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "noir" && piece->obtenirType() == "class Tour")
				vecteurPiecesNoires_.push_back(new Tour(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "noir" && piece->obtenirType() == "class Fou")
				vecteurPiecesNoires_.push_back(new Fou(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "noir" && piece->obtenirType() == "class Reine")
				vecteurPiecesNoires_.push_back(new Reine(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));
			if (piece->obtenirCouleur() == "noir" && piece->obtenirType() == "class Roi")
				vecteurPiecesNoires_.push_back(new Roi(piece->obtenirId(), piece->obtenirCouleur(), piece->obtenirPositionX(), piece->obtenirPositionY()));

		}
		else
		{
			cout << "ajout impossible, l id est deja existant !!" << endl;
		}
		return *this;
}

// Implementation de la surcharge de l'operateur -=
Echiquier& Echiquier::operator-=(const string& id)
{
	int i = 0;
	int j = 0;
	bool test = true;
	bool test1 = true;
	while (i < vecteurPiecesBlanches_.size() && test)
	{
		if (id == vecteurPiecesBlanches_[i]->obtenirId())
		{
			test = false;
			for (unsigned int k = i; k < vecteurPiecesBlanches_.size() - 1; k++)
				vecteurPiecesBlanches_[k] = vecteurPiecesBlanches_[k + 1];
			vecteurPiecesBlanches_.pop_back();
		}
		i++;
	}
	while (j < vecteurPiecesNoires_.size() && test1)
	{
		if (id == vecteurPiecesNoires_[j]->obtenirId())
		{
			test1 = false;
			for (unsigned int k = i; k < vecteurPiecesNoires_.size() - 1; k++)
				vecteurPiecesNoires_[k] = vecteurPiecesNoires_[k + 1];
			vecteurPiecesNoires_.pop_back();
		}
		j++;
	}
	if (test && test1)
	{
		cout << "suppression impossible, l id n est pas existant !!" << endl;
	}
	return *this;
}

// Implementation de la methode pour promouvoir une piece
bool Echiquier::promouvoir(const string& id)
{
	srand(time(NULL));
	bool test = true;
	bool test2 = true;
	int i = -1;
	do
	{
		i++;
		test = vecteurPiecesBlanches_[i]->obtenirId() == id;
	} while (!test && i < vecteurPiecesBlanches_.size() - 1);

	int j = -1;
	do
	{
		j++;
		test2 = id == vecteurPiecesNoires_[j]->obtenirId();

	} while (!test2 && j < vecteurPiecesNoires_.size() - 1);

	if (test || test2)
	{
		string ch;
		if(test)
			ch = vecteurPiecesBlanches_[i]->obtenirType();
		else 
			ch = vecteurPiecesNoires_[j]->obtenirType();
		if (ch == "class Pion")
		{
			unsigned k = rand() % 3;
			switch (k)
			{
			case 0:
				if (test)
				{
					vecteurPiecesBlanches_[i] = new Reine(vecteurPiecesBlanches_[i]->obtenirId(), vecteurPiecesBlanches_[i]->obtenirCouleur(), vecteurPiecesBlanches_[i]->obtenirPositionX(), vecteurPiecesBlanches_[i]->obtenirPositionY());
					
				}
				else
					vecteurPiecesNoires_[j] = new Reine(vecteurPiecesNoires_[j]->obtenirId(), vecteurPiecesNoires_[j]->obtenirCouleur(), vecteurPiecesNoires_[j]->obtenirPositionX(), vecteurPiecesNoires_[j]->obtenirPositionY());
				break;
			case 1: 
				if (test)
					vecteurPiecesBlanches_[i] = new Tour(vecteurPiecesBlanches_[i]->obtenirId(), vecteurPiecesBlanches_[i]->obtenirCouleur(), vecteurPiecesBlanches_[i]->obtenirPositionX(), vecteurPiecesBlanches_[i]->obtenirPositionY());
				else
					vecteurPiecesNoires_[j] = new Tour(vecteurPiecesNoires_[j]->obtenirId(), vecteurPiecesNoires_[j]->obtenirCouleur(), vecteurPiecesNoires_[j]->obtenirPositionX(), vecteurPiecesNoires_[j]->obtenirPositionY());
				break;
			case 2: 
				if (test)
					vecteurPiecesBlanches_[i] = new Fou(vecteurPiecesBlanches_[i]->obtenirId(), vecteurPiecesBlanches_[i]->obtenirCouleur(), vecteurPiecesBlanches_[i]->obtenirPositionX(), vecteurPiecesBlanches_[i]->obtenirPositionY());
				else
					vecteurPiecesNoires_[j] = new Fou(vecteurPiecesNoires_[j]->obtenirId(), vecteurPiecesNoires_[j]->obtenirCouleur(), vecteurPiecesNoires_[j]->obtenirPositionX(), vecteurPiecesNoires_[j]->obtenirPositionY());
				break;
			}
			cout << "Promotion reussie" << endl;
			cout << vecteurPiecesBlanches_[i]->obtenirType() << endl;
	
			return true;
		}
	}
	else
	{
		cout << "Promotion impossible" << endl;
		return false;
	}
    return false;
}

