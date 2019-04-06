/********************************************
* Titre: Travail pratique #5 - gestionnaireTables.cpp
* Date: 21 mars 2019
* Auteur: Moussa Traor� & Ryan Hardie & Wassim Khene
*******************************************/


#include "GestionnaireTables.h"
#include "LectureFichierEnSections.h"
#include <iterator>

void GestionnaireTables::lireTables(const string& nomFichier)
{
	LectureFichierEnSections fichier{ nomFichier };
	fichier.allerASection("-TABLES");
	while (!fichier.estFinSection()) {
		int id, nbPlaces;
		fichier >> id >> nbPlaces;
		ajouter(new Table(id, nbPlaces));
	}
}

Table* GestionnaireTables::getTable(int id) const {
	set<Table*>::iterator debut = getConteneur().begin();
	set<Table*>::iterator fin = getConteneur().end();


	auto idTrouve = [id](Table* table) -> bool {
		if (table->getId() == id) {
			return true;
		}
		else {
			return false;
		}
	};


	return (*find_if(debut, fin, idTrouve));



} // TODO
Table* GestionnaireTables::getMeilleureTable(int tailleGroupe) const {
	set<Table*>::iterator debut = getConteneur().begin();
	set<Table*>::iterator fin = getConteneur().end();

	auto tableTrouve = [tailleGroupe](Table* table) -> bool {
		if (!table->estOccupee() && table->getId() != ID_TABLE_LIVRAISON) {
			if (table->getNbPlaces() >= tailleGroupe) {
				return true;
			}
		}
		else {
			return false;
		}
	};
	return (*min_element(debut, fin, tableTrouve));


}// TODO



void GestionnaireTables::afficherTables(ostream& os) const {
	set<Table*>::iterator debut = getConteneur().begin();
	set<Table*>::iterator fin = getConteneur().end();
	
	
	
	copy(debut, fin, ostream_iterator<Table*>(cout, "/n"));



} // TODO