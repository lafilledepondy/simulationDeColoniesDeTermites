
#ifndef termite_HPP
#define termite_HPP

#include <vector>
#include <iostream>
using namespace std;

#include "coord.hpp" 
#include "grille.hpp"


const float probaTourner = 0.1; // 10%
const int dureeSablier = 6;

class Termite {
    private:
        int idTermite;
        int X;
        int Y;
        Direction direction;
        bool hasBrindille;

        int tmpSablier;

        // vector<Termite> T;

    public:
        // Constructeurs
        Termite(int id, int x, int y) : idTermite(id), X(x), Y(y) {tmpSablier = 0;} 
        Termite(){} 

        // set et get pour termite
        int getIdT(){
            return idTermite;
        }

        int getX(){
            return X;
        }

        int getY(){
            return Y;
        }

        Direction getDir(){
            return direction;
        }
        
        void setIdT(int IdT){
            idTermite = IdT;
        }
        
        void setX(int x_pos){
            X = x_pos;
        }

        void setY(int y_pos){
            Y = y_pos;
        }

        void setDir(Direction dir){
            direction = dir;
        }

        void setBrindille(bool brind){
            hasBrindille = brind;
        }

        // Accès
        string toString() const;

        Direction directionTermite() const;

        Coord devant() const;
        
        // Prédicat
        bool porteBrindille() const;

        // Modificateurs
        void tourneADroite();

        void tourneAGauche();

        void tourneAleat();

        bool laVoieEstLibre(const Grille &g) const;

        bool brindilleEnFace(const Grille& g) const;

        int voisinsLibre(const Grille& g) const;

        void avanceTermite(Grille &grille);
        
        void marcheAleatoire(Grille &g);

        void chargeBrindille(Grille& g); 

        void dechargeBrindille(Grille& g);

        void rassemblerBrindille(Grille& g);

        friend ostream& operator<<(ostream& out, const Grille &g);

        bool estBordure(const Grille& g, const Coord& c) const;

        void changerDirectionBord(Termite& t, const Grille& g);
        
};

#endif
