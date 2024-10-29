using namespace std;

#include "doctest.h"

#include "population.hpp"

Termite Population::getID (int nbT){
    if (nbT >= 0 and nbT < int(T.size()))
        return T[nbT];
    throw out_of_range("Population::getID -- Cannot get the ID of non-existing termite!!!");
}


void Population::ajoutTer(Termite t){
    T.push_back(t);
}



void Population::deplacerAleatoire(Grille& g) {
    char c;
    bool stop = false;
    while (!stop) {
        // déplacement aléatoire des termites
        for (auto& t : T) {
            Coord c(t.getX(), t.getY());
            if (t.estBordure(g, c)){
                t.changerDirectionBord(t, g);
                if ((g.estVide(t.devant())))
                    t.avanceTermite(g);
            }
            // vérification si la voie est libre avant de déplacer le termite
            else if (t.brindilleEnFace(g)) {
                t.tourneAleat();
            }
            else {
                // déplacement du termite
                t.marcheAleatoire(g);
            }
        }
        // affichage de la grille
        cout << g << endl;
        // demande d'une saisie de caractère pour continuer
        cout << "Appuyez sur Entree pour continuer ou '.' pour arreter." << endl;
        c = getchar();
        if (c == '.') {
            stop = true;
        }
        // nettoyage de la saisie
        while ((c = getchar()) != '\n' && c != EOF) {} // EOF = End of File 
    }
}

            // cout << t.getIdT() << " " << t.getDir() << " " << t.getX() << "  " << t.getY() << endl;  

void Population::deplacerAleatoireBIS(Grille& g, int nbPasse) {
    char c;
    bool stop = false;
    while (!stop) {
        for (int i = 0; i < nbPasse; i++) {
            for (auto& t : T) {
                Coord c(t.getX(), t.getY());
                if (t.estBordure(g, c)) {
                    t.changerDirectionBord(t, g);
                    if (!g.estVide(t.devant())) {
                        t.avanceTermite(g);
                    }
                } else if (t.brindilleEnFace(g)) {
                    t.tourneAleat();
                } else {
                    t.marcheAleatoire(g);
                }
            }
        }
        cout << g << endl;
        cout << "Appuyez sur Entree pour continuer, '.' pour arreter, '*' pour accelerer, '/' pour ralentir." << endl;
        c = getchar();
        if (c == '.') {
            stop = true;
        } else if (c == '*') {
            nbPasse *= 2;
        } else if (c == '/') {
            nbPasse /= 2;
            if (nbPasse < 1) {
                nbPasse = 1;
            }
        }
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
}


