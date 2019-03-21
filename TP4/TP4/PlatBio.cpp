/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatBio.h"

PlatBio::PlatBio(string nom, double prix, double cout, double ecotaxe): Plat(nom, prix, cout), ecoTaxe_(ecotaxe)
{
}


PlatBio::~ PlatBio(){}

double PlatBio::getEcoTaxe() const
{
	return ecoTaxe_;
}

void PlatBio::setEcoTaxe(double ecoTaxe)
{
	ecoTaxe_ = ecoTaxe;
}

//TODO
Plat * PlatBio:: clone () const
{
	PlatBio *platbio = new PlatBio(nom_, prix_, cout_, ecoTaxe_);
	return platbio;
}
double PlatBio::getPrixDeRevient()
{ 
	return getPrix() + getEcoTaxe();
}

void PlatBio::afficherPlat(ostream& os) const
{
    //TODO
	Plat::afficherPlat(os);
	os << "Plat Bio    comprend une taxe ecologique de :" << getEcoTaxe() << endl;
}

