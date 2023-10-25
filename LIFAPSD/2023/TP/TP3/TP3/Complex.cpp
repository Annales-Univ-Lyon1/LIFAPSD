/**
 @author Created by Virgile Broillet P2103804 on 22/08/2023
 @file Complex.cpp
 @brief fichier cpp des complex exercice avec classes
 
 @copyright Copyright © 2023 Virgile Broillet P2103804. All rights reserved for studying or personal use.
 */

#include <iostream>
#include "Complex.h"
#include <fstream>
using namespace std;


float Complex::getIm(){
    return this->im;
}


float Complex::getRe(){
    return this->re;
}


void Complex::setIm(float im){
    this->im = im;
}


void Complex::setRe(float re){
    this->re = re;
}


Complex Complex::multiplie(const Complex &c1){
    Complex result;
    result.re = (c1.re * re) - (c1.im - im);
    result.im = (c1.im * re) + (c1.re - im);
    
    return result;
}

void Complex::afficherComplex()
{
    if (im > 0) {
        cout << re << " + " << im << "i"<<endl;
    }else{
        cout << re << " - " << fabs(im) << "i"<<endl;
    }
}


void Complex::afficherTab(Complex *tab, unsigned int taille){
    for (int i = 0; i < taille; i++) {
        tab[i].afficherComplex();
        cout << tab[i].module() << endl;
        cout << endl;
    }
}


float Complex::module() const{
    return sqrtf((re*re) + (im*im)); // on peut utiliser hypot(re, im) qui fait le job
}


bool Complex::estPlusPetit(const Complex &c2)
{
    return module() < c2.module();
}


void Complex::RemplirTab(Complex *tab, const unsigned int taille){
    for (int index = 0; index < taille; index++) {
        tab[index].setIm(((rand()% (200) / 10.0) - 10.0));
        tab[index].setRe(((rand()% (200) / 10.0) - 10.0));
        tab[index].afficherComplex();
    }
}


void Complex::trierParSelection(Complex *tab, unsigned int taille){
    for (int i = 0; i < taille; i++) {
        //on cherche le min dans tab[1,...,n-1]
        int jmin = i;
        for (int j = i+1; j<taille; j++) {
            if (tab[j].estPlusPetit(tab[jmin])) {
                jmin = j;
            }
            swap(tab[i], tab[jmin]);
        }
    }
}

const Complex Complex::operator * (const Complex &c2){
    Complex res(re, im);
    res.multiplie(c2);
    return res;
}

const bool Complex::operator < (const Complex &c2){
    return module() < c2.module();
}

Complex& Complex::operator=(const Complex &c2){
    re = c2.re;
    im = c2.im;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Complex &c){
    os << c.re;
    if (c.im > 0) {
        os << " + I * "<<c.im;
    }else{
        os << " - I * "<<fabs(c.im);
    }
    return os;
}

std::istream &operator>>(std::istream &is, Complex &c){
    char poubelle;
    is >> c.re;
    is >> c.im;
    is >> poubelle;
    return is;
}

void readTabComplexFromFile(Complex * &tab, unsigned int &n, string filename){
    char poubelle;
    fstream fs;
    fs.open(filename);
    fs >> n; // lecture du nombre de Complexes dans le fichier
    tab = new Complex[n];
    for (int i = 0; i < n; i++) {
        fs >> tab[i] >> poubelle;
    }
    fs.close();
}

double time_us(clock_t ci, clock_t cf){
    return 1e6 * ((double)(cf - ci)/(double)CLOCKS_PER_SEC); // us
}

int main(void) {
    unsigned int n = 1000;
    clock_t ci, cf;
        
    Complex * tab = new Complex[n];
    
    ci = clock();
    for (int i = 0; i < n; i++) {
        tab[i].setIm(((rand()% (200) / 10.0) - 10.0));
        tab[i].setRe(((rand()% (200) / 10.0) - 10.0));
    }

    return 0;
}

