/********************************************
* Titre: Travail pratique #5 - Foncteur.h
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/

#pragma once

#include <algorithm>
#include "Plat.h"

using namespace std;


class FoncteurPlatMoinsCher
{ // TODO
public:
	FoncteurPlatMoinsCher() {};
	bool operator()(const pair<string, Plat*> plat1, const pair<string, Plat*> plat2) {
		return (plat1.second->getPrix() < plat2.second->getPrix());
	}
};

class FoncteurIntervalle
{
public: 
   // TODO
	FoncteurIntervalle(double min, double max) :borneInf_(min), borneSup_(max) {};
	bool operator()(const pair<string, Plat*> plat) {
		return (borneInf_ < plat.second->getPrix() && plat.second->getPrix() < borneSup_);
	}

private:
	double borneSup_;
	double borneInf_;
};

