/*
* Date : 25 février 2019
* Auteur : AbdeB
*/
#include "PlatVege.h"


//TODO
PlatVege::PlatVege(string nom, double prix, double cout,
                   double vitamines, double proteines, double mineraux): Vege(nom, vitamines, proteines, mineraux), Plat(nom ,prix, cout)
{
}
PlatVege::~ PlatVege(){}

Plat* PlatVege::clone()const
{ //TODO
	PlatVege *platVegeClone = new PlatVege(Plat::getNom(), prix_, cout_, vitamines_, proteines_, mineraux_);
	return platVegeClone;
}


void PlatVege::afficherPlat(ostream & os) const
{   
	Plat::afficherPlat(os);
	Vege::afficherVege(os);
}

double PlatVege::calculerApportNutritif() const
{
	return Vege::calculerApportNutritif() * RAPPORT_NUTRITIF;
    //TODO
}
