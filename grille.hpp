#ifndef grille_HPP
#define grille_HPP

#include <vector>
#include <iostream>
using namespace std;

#include "coord.hpp" 
// #include "termite.hpp"


/**
 * La classe Grille représente la grille de jeu pour la simulation de termites
 */
class  Grille {
    private:

        /**
         * La structure Case représente une case de la grille
         */
        struct Case{
            bool brindille;
            int idTermite;

            /**
             * Constructeur par défaut de la structure Case
             * Initialise la case avec une absence de brindille 
             *                         et de termite
             */
            Case() : brindille(false), idTermite(-1) {}
        };


        /**
         * Le tableau de cases de la grille
         * 
         * Un tableau à 2 dimensions, de taille [tailleGrille][tailleGrille] 
         *         <=> représentant l'ensemble des cases de la grille de jeu
         * Chaque élément du tableau est une structure Case, qui contient des info 
         *         sur la présence d'une brindille 
         *         ou d'une termite sur la case correspondante.
        */
        Case cas[tailleGrille][tailleGrille];

    public:
        /**
         * Vérifie si la case à une coordonnée donnée contient une brindille
         * @param c la coordonnée de la case à vérifier
         * @return true si la case contient rien, 
         *         false sinon
         */
        bool estVide(Coord c) const;


        /**
         * Pose une brindille sur la case à une coordonnée donnée
         * @param c la coordonnée de la case où poser la brindille
         */
        void poseBrindille(Coord c);


        /**
         * Enlève la brindille de la case à une coordonnée donnée
         * @param c la coordonnée de la case où enlever la brindille
         */
        void enleveBrindille(Coord c);


        /**
         * Vérifie si la case à une coordonnée donnée contient une brindille
         * @param c la coordonnée de la case à vérifier
         * @return true si la case contient une brindille, 
         *         false sinon
         */
        bool contientBrindille(Coord c) const;


        /**
         * Pose une termite sur la case à une coordonnée donnée
         * @param c la coordonnée de la case où poser la termite
         * @param idT l'identifiant de la termite à poser
         */
        void poseTermite(Coord c, int idT);


        /**
         * Enlève la termite de la case à une coordonnée donnée
         * @param c la coordonnée de la case où enlever la termite
         */
        void enleveTermite(Coord c);


        /**
         * Récupère l'identifiant de la termite sur la case à une coordonnée donnée
         * @param c la coordonnée de la case à vérifier
         * @return l'identifiant de la termite sur la case, 
         *         ou -1 s'il n'y en a pas
         */
        int numéroTermite(Coord c) const;  


        /**
         * Surcharge de l'opérateur << pour afficher la grille sur un flux de sortie
         * @param out le flux de sortie
         * @param g la grille à afficher
         * @return le flux de sortie
         */
        friend ostream& operator<<(ostream& out, const Grille &g);

        // void affgrille(vector<Termite> t);

};

#endif