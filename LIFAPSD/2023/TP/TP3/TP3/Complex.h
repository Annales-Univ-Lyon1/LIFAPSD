/**
 @author Created by Virgile Broillet P2103804 on 22/08/2023
 @file Complex.h
 @brief fichier h des complex exercice
 
 @copyright Copyright © 2023 Virgile Broillet P2103804. All rights reserved for studying or personal use.
 */

#ifndef Complex_h
#define Complex_h


class Complex {
private:
    
    /**
     @brief Immaginary number of the complex
     */
    float im;
    /**
     @brief Real number of the complex
     */
    float re;
    
public:
    
    /**
    @brief get the actual value of the immaginary number of the complex
    @fn getIm()
    @return float
     */
    float getIm();
    
    /**
     @brief get the actual value of the real number of the complex
     @fn getRe()
     @return float
     */
    float getRe();
    
    /**
     @brief set the immaginary value of the complex
     @fn setIm()
     @param[in] im the new value of the immaginary number
     */
    void setIm(float im);
    
    /**
     @brief set the real value of the complex
     @fn setRe()
     @param[in] re the new value of the real number
     */
    void setRe(float re);
    
    /**
     @brief empty constructor of a Complex
     */
    Complex(){this->re = this->im = 0.0f;};
    
    /**
     @brief constructor of a Complex with real and imaginary numbers
     @param[in] re the real value of the new Complex
     @param[in] im the immaginary value of the new Complex
     */
    Complex(float re, float im){this->re = re; this->im=im;};
    
    /**
     @brief constructor of a Complex by copying another complex
     */
    Complex(const Complex &c){this->re = c.re; this->im = c.im;};
    
    /**
     @brief destrcuteur de la classe
     */
    ~Complex(){};
    
    /**
     @brief multiplie a Complex C with another one
     @fn multiple()
     @param[in] C a complex
     @return the result of the multiplication of the thow Complex
     */
    Complex multiplie(const Complex &C);
    
    /**
     @brief Operator \* of the Complex
     @fn operator\*()
     @param[in] c2 the Complex in parameter
     @return the multiplication of the complex times the c2
     */
    const Complex operator * (const Complex &c2);
    
    /**
     @brief Operator= of the Complex is in reference for that a = b = c
     @fn operator=()
     @param[in] c2 the Complex in parameter
     @return the copy of the complex c2
     */
    Complex& operator=(const Complex &c2);
    
    /**
     @brief Operator \< return true if c2 \> global value
     @fn operator\<()
     @param[in] c2 the Complex in parameter
     @return true if c2 > gloal complex
     */
    const bool operator < (const Complex &c2);
    
    /**
     @brief cout operator
     @fn operator<<
     @param os , the outpout
     @param c a complex
     @return the outpout
     */
    friend std::ostream &operator<<(std::ostream &os, const Complex &c);
    
    /**
     @brief cin operator
     @fn operator>>
     @param is , the intpout
     @param c a complex
     @return the input
     */
    friend std::istream &operator>>(std::istream &is, Complex &c);
    
    /**
     @brief read a tab from a filename on computer
     @param n size of the tab (first line of the file)
     @param filename the filename
     @param tab , the tab of n complex
     */
    void readTabComplexFromFile(Complex *tab, unsigned int &n, std::string filename);
    
    /**
     @brief give back the modulo of an complex (sqrt(re^2 + m^2))
     @fn module()
     @return the moduloof the complex passed in parametres
     */
    float module() const;
    
    /**
     @brief say true if the complex 1 in parameters is smaller that the 2nd one, false otherwise
     @fn estPlusPetit()
     @param[in] c2  complex
     @return true if the complex gloab complex  is smaller that the 2nd one, false otherwise
     */
    bool estPlusPetit(const Complex &c2);
    
    /**
     @brief Remplis un tableau de taille donnée de vecteur dont ses valeurs sont comprises entre -10.0 et 10.0 exclus
     @fn RemplirTab()
     @param[in] tab le tableau vide de Complexe
     @param[in] taille la taille du tableau de Complexe
     */
    void RemplirTab(Complex *tab, const int unsigned taille);
    
    /**
     @brief affiche un complex
     @fn afficherComplex()
     */
    void afficherComplex();
    
    /**
     @brief affiche le tabelau de Complexes passer en paramètres
     @fn afficherTab()
     @param[in] tab le tableau de complexe
     @param[in] taille la taille du tableau de Complexe
     */
    void afficherTab(Complex *tab, unsigned int taille);
    
    /**
     @brief tri  pas insertion les élements du plus grand
     @fn trierParSelection()
     @param[in] tab pointeur sur le tableau de nombre Complexes
     @param[in] taille la taille du tableau de nombre Complexes
     */
    void trierParSelection(Complex *tab, unsigned int taille);

};


#endif /* Complex_h */
