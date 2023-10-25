/**
 @author Created by Virgile Broillet P2103804 on 29/08/2023
 @file Vecteur3D.cpp
 @brief fichier cpp des Vecteur3D exercice sans classes
 
 @copyright Copyright © 2023 Virgile Broillet P2103804. All rights reserved for studying or personal use.
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

/**
 @brief structure Vecteur3D
 */
struct Vecteur3D{
    float  x,y,z;
};


/**
 @brief calcul la norme d'un vecteur donné
 @fn Veceteur3DGetNorme()
 @param[in] v le vecteur passé en paramètre
 @return float la norme du vecteur
 */
float Vecteur3DGetNorme(const Vecteur3D &v){
    return sqrtf((v.x * v.x) + (v.y * v.y) + (v.y * v.y));
}

/**
 @brief Normalise un vecteur (fait en sorte que sa norme soit égal à 0)
 @fn Vecteur3DNormaliser()
 @param[in] v le vecteur passé en paramètre
 */
void Vecteur3DNormaliser(Vecteur3D &v){
    float norme;
    norme = Vecteur3DGetNorme(v);
    
    if (norme != 0) {
        v.x /= norme;
        v.y /= norme;
        v.z /= norme;
    }
}

/**
 @brief verifie si le vecteur passé en paramètre est normalisé
 @fn Vecteur3DEstNormalise()
 @param[in] v le vecteur passé en paramètre
 @return bool true si le vecteur est normalisé false sinon
 */
bool Vecteur3DEstNormalise(const Vecteur3D &v){
    return fabsf(Vecteur3DGetNorme(v) - 1) < 1e-6; //remplace le if (un peu long)
}

/**
 @brief additionne deux vecteurs entre eux et retourne la somme de ces deux vecteurs sous forme d'un nouveau vercteur
 @fn Vecteur3DAdd()
 @param[in] v1  le premier vecteur a additioné
 @param[in] v2 le deuxième vecteur a aditioné
 @return Vecteur3D, la somme de v1 et v2
 */
Vecteur3D Vecteur3DAdd(const Vecteur3D &v1, const Vecteur3D &v2){
    Vecteur3D vSomme;
    vSomme.x = v1.x + v2.x;
    vSomme.y = v1.y + v2.y;
    vSomme.z = v1.z + v2.z;
    
    return vSomme;
}

/**
 @brief affiche un vecteur passé en paramètre sous la forme "(x , u ,z)"
 @fn Vecteur3DAfficher()
 */
void Vecteur3DAfficher(const Vecteur3D &v){
    cout<< "(" << v.x << "," << v.y << "," << v.z << ")" <<endl;
}

/**
 @brief Remplis un tableau de taille donnée de vecteur dont ses valeurs sont comprises entre -10.0 et 10.0 exclus
 @fn Vecteur3DRemplirTabVecteur()
 @param[in] tab le tableau vide de Vecteur3D
 @param[in] taille la taille du tableau de Vecteur3D
 */
void Vecteur3DRemplirTabVecteurs(Vecteur3D *tab, const int taille){
    for (int index = 0; index < taille; index++) {
        tab[index].x = ((rand()% (200) / 10.0) - 10.0);
        tab[index].y = ((rand()% (200) / 10.0) - 10.0);
        tab[index].z = ((rand()% (200) / 10.0) - 10.0);
    }
}

/**
 @brief Affiche tous les vecteurs présent dans le tableau de vecteur donnée et dont la taille est donnée en paramètre
 @fn Vecteur3DAfficherTabVecteur()
 @param[in] tab le tableau de Vecteur3D
 @param[in] taille la taille du tableau de Vecteur3D
 */
void Vecteur3DAfficherTabVecteurs(const Vecteur3D *tab, const int taille){
    for (int index = 0; index < taille; index++) {
        cout << "vec" << index+1 << " : "; Vecteur3DAfficher(tab[index]); cout << endl;
    }
}

/**
 @brief Donne l'index dans le tableau du vecteur avec la norme la plus élévée du tableau
 @fn Vecteur3DMaxTabVecteurs()
 @param[in] tab le tableau de Vecteur3D
 @param[in] taille la taille du tableau de Vecteur3D
 @return int l'index du vecteur de plus grande norme du tableau
 */
int Vecteur3DMaxTabVecteurs(const Vecteur3D *tab, const int taille){
    float maxNorme = 0;
    int index = 0;
    for (int i = 0; i < taille; i++) {
        float norme = Vecteur3DGetNorme(tab[i]);
        if (norme > maxNorme) {
            maxNorme = norme;
            index = i+1;
        }
    }
    return index;
}

/**
 @brief concatene les tableau 1 et 2, puis met le resultat dans tab3
 @fn Vecteur3DConcatenationTabVecteurs()
 @param[in] tab1 le tableau de Vecteur3D
 @param[in] tab2 le tableau de Vecteur3D
 @param[in] tab3 le tableau de Vecteur3D
 @param[in] taille1 la taille de tab1
 @param[in] taille2 la taille de tab2
 */
void Vecteur3DConcatenationTabVecteurs(const Vecteur3D *tab1, const Vecteur3D *tab2, Vecteur3D *tab3, int taille1, int taille2){
    
    int i, j = 0;
    for (i = 0; i<taille1; i++) {
        tab3[j] = tab1[i];
        j++;
    }
    for (i = 0; i<taille2; i++) {
        tab3[j] = tab2[i];
        j++;
    }
}

/**
 @brief inverse l'élement n du tableau par l'élément 0 puis continue avec tous les elements du tableau
 @param[in] tab le tableau à inverser
 @param[in] taille la taille du tableau à inverser
 */
void Vecteur3DInverseTabVecteurs(Vecteur3D *tab, int taille){
    int tailleTemp = taille;
    int newtaille;
    Vecteur3D temp;
    if (taille % 2 == 0) {
        newtaille = taille / 2;
    }else{
        newtaille = taille /2 + 0.5;
    }
    for (int i = 0; i < newtaille; i++) {
        tab[tailleTemp] = temp;
        tab[tailleTemp] = tab[i];
        tab[i] = temp;
        tailleTemp--;
    }
}

/**
 @brief fonction principal
 */
int main (void) {
    srand((int)time(NULL));
    Vecteur3D vecteur1 = {0,0,1}; Vecteur3D vecteur2 = {0,0,0};
       cout << "vecteur1 non normalise: ";
       Vecteur3DAfficher(vecteur1);
       cout << endl;
       cout << "vecteur2 non normalise: ";
       Vecteur3DAfficher(vecteur2);
       cout << endl;
    cout << "somme: "; Vecteur3DAfficher(Vecteur3DAdd(vecteur1,vecteur2)); cout << endl;
       Vecteur3DNormaliser(vecteur1);
       Vecteur3DNormaliser(vecteur2);
       cout << "vecteur1 normalise: ";
       Vecteur3DAfficher(vecteur1);
       cout << endl;
       cout << "vecteur2 normalise: ";
       Vecteur3DAfficher(vecteur2);
       cout << endl;
    cout << "somme: ";
    Vecteur3D somme = Vecteur3DAdd(vecteur1,vecteur2); Vecteur3DAfficher(somme);
    if (Vecteur3DEstNormalise(somme)) cout << " est normalise" << endl; else cout << " n'est pas normalise" << endl;
     return 0;
}
