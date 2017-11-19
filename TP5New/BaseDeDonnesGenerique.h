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
		int tempSize = listImage_.size();

		auto it = listImage_.begin();
		auto itEnd = listImage_.end();
		listImage_.erase(find(it, itEnd, t));

		if (tempSize != listGroupeImage_.size())
			return true;
		else return false;
		
	}

	bool supprimer(const S* s) {
		int tempSize3 = listGroupeImage_.size();

		auto it = listGroupeImage_.begin();
		auto itEnd = listGroupeImage_.end();
		listGroupeImage_.erase(find(it, itEnd, s);

		if (tempSize3 != listGroupeImage_.size()))
			return true;
		else return false;

	}

	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate) {
		int tempSize1 = listImage_.size();

		listImage_.remove_if(predicate);

		if (tempSize1 != listImage_.size())
			return true;
		else return false;
	}
	
	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate) {
		int tempSize2 = listGroupeImage_.size();

		listGroupeImage_.remove_if(predicate);

		if (tempSize2 != listGroupeImage_.size())
			return true;
		else return false;

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
