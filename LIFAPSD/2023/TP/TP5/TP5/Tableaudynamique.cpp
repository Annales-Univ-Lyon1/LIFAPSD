//
		/**
			@author Created by Virgile Broillet P2103804 on 04/09/2023
			@file Tableaudynamique.cpp
			@brief exercice des tableau dynamiques avec .h
		
			@copyright Copyright © 2023 Virgile Broillet P2103804. All rights reserved for studying or personal use.
		*/
		

#include <iostream>
#include "Tableaudynamique.h"
#include "ElementTD.h"

using namespace std;

TableauDynamique::TableauDynamique(){
    capacite = 1;
    taille_utilisee = 0;
    ad = new ElementTD [1];
}

TableauDynamique::~TableauDynamique(){
    if (ad != NULL) {
        delete [] ad;
        ad = NULL;
    }
    capacite = 0;
    taille_utilisee = 0;
}

void TableauDynamique::vider(){
    TableauDynamique::~TableauDynamique();
}

void TableauDynamique::ajouterElement(ElementTD e){
   if (taille_utilisee == capacite){
       capacite = capacite*2;
       ElementTD * temp = ad;
       ad = new ElementTD [capacite];
       
       for (int i = 0; i<taille_utilisee; ++i){
           ad[i] = temp[i];
       }
    }
    ad[taille_utilisee] = e;
    taille_utilisee++;
}

ElementTD TableauDynamique::valeurIemeElement(unsigned int indice) const {
    if (indice >= 0 && indice < taille_utilisee) {
        return ad[indice];
    }else{
        cout << "l'indice est plus petit que 0 ou est supéreieur a la taille du tableau" ;
        return 0;
    }
}

void TableauDynamique::modifierValeurIemeElement(ElementTD e, unsigned int indice){
    if (indice >= 0 && indice < taille_utilisee) {
        ad[indice] = e;
    }else{
        cout << "l'indice est plus petit que 0 ou est supéreieur a la taille du tableau";
    }
}

void TableauDynamique::afficher() const {
    for (int i = 0; i<taille_utilisee; ++i) {
        cout << ad[i] << " ";
    }
}


void TableauDynamique::supprimerElement(unsigned int indice){
    if (indice >= 0 && indice <= taille_utilisee) {
    }
}

int main(int argc, const char * argv[]) {
    TableauDynamique tab;
    tab.taille_utilisee = 2;
    tab.capacite = 3;
    ElementTD a = 3;
    ElementTD b = 3;
    ElementTD c = 3;

    tab.ajouterElement(a);
    tab.ajouterElement(b);
    tab.ajouterElement(c);

    tab.afficher();

    return 0;
}
