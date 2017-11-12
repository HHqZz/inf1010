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
	BaseDeDonnesGenerique() {};
	~BaseDeDonnesGenerique() {};

	list<T*> obtenirListImages() const {
		return listImage_;
	}
	list<S*> obtenirListGroupeImages() const {
		return listGroupeImage_;
	}

	void ajouter(T* t) {
		listImage_.push_back(t);
	}
	void ajouter(S* s) {
		listGroupeImage_.push_back(s);

	}

	bool supprimer(const T* t) {
		auto it = listImage_.begin;
		auto itEnd = listImage_.end;
		erase(*find(it, itEnd, t);
		
	}
	bool supprimer(const S* s) {
		auto it = listGroupeImage_.begin;
		auto itEnd = listGroupeImage_.end;
		erase(*find(it, itEnd, s);
	}

	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate) {
		ListImages_.remove_if(predicate);
	}

	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate) {
		listGroupeImage_.remove_if(predicate);
	}

	void vider() {
		listGroupeImage_.clear();
		listImage_.clear();
	}

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
