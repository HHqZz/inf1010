#ifndef BASE_DE_DONNES_GENERIQUE
#define BASE_DE_DONNES_GENERIQUE

#include <list>
#include <algorithm>
#include <iterator>

// Implementer toutes les methodes dans ce fichier

using namespace  std;
template<typename T, typename S> //T = Image, S = GroupeImage
class BaseDeDonnesGenerique
{
public:
	BaseDeDonnesGenerique();
	~BaseDeDonnesGenerique();

	list<T*> obtenirListImages() const;
	list<S*> obtenirListGroupeImages() const;

	void ajouter(T* t);
	void ajouter(S* s);

	bool supprimer(const T* t);
	bool supprimer(const S* s);

	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate);

	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate);

	void vider();

	BaseDeDonnesGenerique& operator+=(T* t) {
		ajouter(t);
		return *this;
	}

	BaseDeDonnesGenerique& operator+=(S* s) {
		ajouter(s);
		return *this;
	}

	BaseDeDonnesGenerique& operator-=(T* t) {
		supprimer(t);
		return *this;
	}

	BaseDeDonnesGenerique& operator-=(S* s) {
		supprimer(s);
		return *this;
	}

protected:
	list<T*> listImage_;
	list<S*> listGroupeImage_;
};



#endif
