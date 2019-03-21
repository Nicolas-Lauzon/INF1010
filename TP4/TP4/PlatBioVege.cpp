/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBioVege.h"



PlatBioVege::PlatBioVege(string nom, double prix, double cout, double ecotaxe, double vitamines, double proteines, double mineraux): Vege(nom, vitamines, proteines, mineraux),	PlatBio(nom,prix,cout, ecotaxe)
{ // TODO
}
PlatBioVege:: ~PlatBioVege(){}

//TODO
void PlatBioVege::afficherPlat(ostream & os) const
{   //TODO
	Plat::afficherPlat(os);
	PlatBio::afficherPlat(os);
	os << "ET ";
	Vege::afficherVege(os);
}

Plat * PlatBioVege::clone() const
{ 
	PlatBioVege *platBioVegeClone = new PlatBioVege(Plat::getNom(), prix_, cout_, ecoTaxe_, vitamines_, proteines_, mineraux_);
	return platBioVegeClone;
}

double PlatBioVege::calculerApportNutritif() const{

   //TODO
	return Vege::calculerApportNutritif() * RAPPORT_NUTRITIF_BIO * AVANTAGE_SANS_PESTICIDE;

}
