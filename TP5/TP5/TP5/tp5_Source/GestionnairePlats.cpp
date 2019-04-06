/********************************************
* Titre: Travail pratique #5 - gestionnairePlats.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#include "GestionnairePlats.h"
#include "LectureFichierEnSections.h"
#include "PlatBio.h"
#include "PlatVege.h"
#include "PlatBioVege.h"
#include <iterator>


void GestionnairePlats::lirePlats(const string& nomFichier, TypeMenu type)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection(entetesDesTypesDeMenu[static_cast<int>(type)]);
	while (!fichier.estFinSection())
		ajouter(lirePlatDe(fichier));
}

pair<string, Plat*> GestionnairePlats::lirePlatDe(LectureFichierEnSections& fichier)
{
	auto lectureLigne = fichier.lecteurDeLigne();
	Plat* plat;
	string nom, typeStr;
	TypePlat type;
	double prix, coutDeRevient;
	lectureLigne >> nom >> typeStr >> prix >> coutDeRevient;
	type = TypePlat(stoi(typeStr));
	double ecotaxe, vitamines, proteines, mineraux;
	switch (type) {
	case TypePlat::Bio:
		lectureLigne >> ecotaxe;
		plat = new PlatBio{ nom, prix, coutDeRevient, ecotaxe };
		break;
	case TypePlat::BioVege:
		lectureLigne >> ecotaxe >> vitamines >> proteines >> mineraux;
		plat = new PlatBioVege(nom, prix, coutDeRevient, ecotaxe, vitamines, proteines, mineraux);
		break;
	case TypePlat::Vege:
		lectureLigne >> vitamines >> proteines >> mineraux;
		plat = new PlatVege(nom, prix, coutDeRevient, vitamines, proteines, mineraux);
		break;
	default:
		plat = new Plat{ nom, prix, coutDeRevient };
	}
	return pair<string, Plat*>(plat->getNom(), plat);
}


GestionnairePlats::GestionnairePlats(const string& nomFichier, TypeMenu type): type_(type) {
	lirePlats(nomFichier, type);
} //TODO


GestionnairePlats::GestionnairePlats(GestionnairePlats* gestionnaire):type_(gestionnaire->getType()) {
	map<string, Plat*>::iterator debut = gestionnaire->getConteneur().begin();
	map<string, Plat*>::iterator fin = gestionnaire->getConteneur().end();
	copy(debut, fin, conteneur_);
} // TODO

GestionnairePlats::~GestionnairePlats() {
	map<string, Plat*>::iterator debut = getConteneur().begin();
	map<string, Plat*>::iterator fin = getConteneur().end();
	conteneur_.erase(debut, fin);
	conteneur_.clear();

} // TODO

TypeMenu GestionnairePlats::getType() const {
	return type_;
} // TODO




Plat* GestionnairePlats::allouerPlat(Plat* plat) {
	return plat->clone();
} // TODO

Plat* GestionnairePlats::trouverPlatMoinsCher() const {
	auto c = getConteneur();
	return (*min_element(c.begin(), c.end(), FoncteurPlatMoinsCher())).second;
}




Plat* GestionnairePlats::trouverPlatPlusCher() const {
	map<string, Plat*>::iterator debut = getConteneur().begin();
	map<string, Plat*>::iterator fin = getConteneur().end();

	
	auto platTrouve = [](pair<string, Plat*> plat1, pair<string, Plat*> plat2) ->bool {
		if (plat1.second->getPrix() < plat2.second->getPrix()) {
			return true;
		}
		else {
			return false;
		}
	};

	return (*max_element(debut, fin, platTrouve)).second;

} 

Plat* GestionnairePlats::trouverPlat(const string& nom) const {
	map<string, Plat*>::iterator debut = getConteneur().begin();
	map<string, Plat*>::iterator fin = getConteneur().end();

	auto platTrouve = [nom](pair<string, Plat*> plat) ->bool {
		if (plat.first == nom) {
			return true;
		}
		else {
			return false;
		}
	};

	return (*find_if(debut, fin, platTrouve)).second;

} // TODO
vector<pair<string, Plat*>> GestionnairePlats::getPlatsEntre(double borneInf, double borneSup) {
	vector<pair<string, Plat*>> vecteurResul;
	map<string, Plat*>::iterator debut = getConteneur().begin();
	map<string, Plat*>::iterator fin = getConteneur().end();

	copy_if(debut, fin, back_inserter(vecteurResul), FoncteurIntervalle(borneInf, borneSup));
	return vecteurResul;
} // TODO

void GestionnairePlats::afficherPlats(ostream& os) {
	map<string, Plat*>::iterator debut = getConteneur().begin();
	map<string, Plat*>::iterator fin = getConteneur().end();
	for (debut; debut != fin; debut++) {
		(*debut).second->afficherPlat(os);
	}
}
