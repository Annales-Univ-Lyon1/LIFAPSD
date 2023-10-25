/**
 @author Created by Virgile Broillet P2103804 on 12/08/2023
 @file main.cpp
 @brief
 
 @copyright Copyright © 2023 Virgile Broillet P2103804. All rights reserved for studying or personal use.
 */

#include <iostream>
using namespace std;

/**
 @brief calcul d'un coefficiant binomial à l'aide du triangle de Pascal
 @fn comb()
 @param[in] n un nombre strictement positif
 @param[in] p un nombre strictement positif
 @return retourne le nombre de combinaisons de p éléments parmis n
 */
 int comb(int n, int p) {
     int tmp1, tmp2;
     cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
     if ((p==0) || (n==p)) 
         return 1;
     tmp1 = comb(n-1, p-1);  /* premier appel récursif*/
     tmp2 = comb(n-1, p);
     return tmp1 + tmp2;
 }

/**
 @brief calcul d'un coefficiant binomial à l'aide du triangle de Pascal
 @fn comb()
 @param[in] n un nombre strictement positif
 @param[in] p un nombre strictement positif
 @param[in] res le resultat du calcul du coefficiant binomial
 */
void comb(int n, int p , int & res){
    int tmp1, tmp2;
    cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
    if ((p==0) || (n==p)){
        res = 1;
    }else{
        comb(n-1, p-1, tmp1);  /* premier appel récursif */
        comb(n-1, p, tmp2);
        res = tmp1 + tmp2;
    }
}

void comb(int n, int p, int * pointeur){
    int * p1 = new int;
    int * p2 = new int;
    cout <<"Calcul du nb de combinaisons de "<<p<<" elts parmi "<<n<<endl;
    if ((p==0) || (n==p)){
        * pointeur = 1;
    }else{
        comb(n-1, p-1, p1);  /* premier appel récursif*/
        comb(n-1, p, p2);
        *pointeur = *p1 + *p2;
        
    }
    delete p1;
    delete p2;
}

/**
 @brief affiche un tableau donnée
 @fn affichetab()
 @param[in] tab le pointeur sur le premier élement du tableau passé en parametre
 @param[in] taille la taille prédéfinie du tableau qui doit etre afficher
 */
void affichetab(const float * tab, unsigned int taille){
    cout << "Taille occupée par le pointeur de monTab dans la fonction : " << sizeof(tab) <<endl;
    /* sa taille est de 8 car on passe en parametre un pointeur sur le tab donc une adresse de 8 octets */
    
    for (unsigned int i = 0; i < taille; i++) {
        cout << "Adresse du des valeurs du tableau " << i  << " " << (long int) &tab[i] << endl;

    }
}

 int main() {
 
     float monTab[] = {3.2, 1.2, 283.3}; // initialise un tableau de 3 éléments uniquement disponible a l'initialisation
     
     cout << "Taille occupée par monTab : " << sizeof(monTab) <<endl;;
     affichetab(monTab, 3);
     
     int c;
     comb(4, 3, &c);
     cout << c << endl;
     
     return 0;
 
 }

