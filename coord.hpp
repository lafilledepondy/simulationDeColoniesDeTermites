#ifndef coord_HPP
#define coord_HPP

#include <iostream>
using namespace std;


/**
 *  La taille totale de la grille
*/
const int tailleGrille = 20;
const float densiteBrindille=5;
const int nbTermites=20;


/**
 * Coord représente les coordonnées d'une position dans une grille
*/
class Coord {
    private:
        int p_ligne;
        int p_colonne;
        

    public:

        /**
         * Constructeur de la classe Coord
         * @param lig la ligne de la coordonnée
         * @param col la colonne de la coordonnée
        */
        Coord(int lig, int col);


        /**
         * Accesseur pour la ligne de la coordonnée
         * @return la ligne de la coordonnée
         */
        int getLig() const;


        /**
         * Accesseur pour la colonne de la coordonnée
         * @return la colonne de la coordonnée
         */
        int getCol() const;


        /**
         * Surcharge de l'opérateur d'égalité pour la classe Coord
         * @param other la coordonnée à comparer
         * @return true si les coordonnées sont égales, 
         *         false sinon
         */
        bool operator==(const Coord other) const;


        /**
         * Surcharge de l'opérateur << pour afficher une coordonnée sur un flux de sortie
         * @param out le flux de sortie
         * @param g la coordonnée à afficher
         * @return le flux de sortie
         */
        friend ostream& operator<<(ostream& out, const Coord &crd);

};


/**
 * L'énumération Direction représente les différentes directions possibles dans la grille
 */
enum class Direction {NORD_OUEST, NORD, NORD_EST, 
                      EST, SUD_EST, 
                      SUD, SUD_OUEST, OUEST};


/**
 * Retourne la direction correspondant à un tour à gauche à partir de la direction donnée
 * @param dir la direction actuelle
 * @return la direction après un tour à gauche
 */
Direction aGauche(Direction dir);


/**
 * Retourne la direction correspondant à un tour à droite à partir de la direction donnée
 * @param dir la direction actuelle
 * @return la direction après un tour à droite
 */
Direction aDroite(Direction dir);

 
/**
 * Retourne la coordonnée correspondant à la case devant une coordonnée donnée dans une direction donnée
 * @param coord la coordonnée de départ
 * @param dir la direction à suivre
 * @return la coordonnée de la case suivante
 */
Coord devantCoord(const Coord& coord, Direction dir);


/**
 * Surcharge de l'opérateur << pour afficher une direction sur un flux de sortie
 * @param out le flux de sortie
 * @param dir la direction à afficher
 * @return le flux de sortie
 */
ostream& operator<<(ostream& out, Direction dir);

#endif