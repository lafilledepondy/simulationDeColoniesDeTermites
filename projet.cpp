#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <random>

#include "coord.hpp"
#include "grille.hpp"
#include "termite.hpp"
#include "population.hpp"

string affGrille(Population p, Grille g) {
    ostringstream flux;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            Coord c(i, j);
            if (g.contientBrindille(c))
                flux << "\033[32;1m" << "*" << "\033[0m";
            else if (g.numéroTermite(c) != -1){
                Termite t = p.getID(g.numéroTermite(c));
                flux << "\033[31;1m" <<  t.toString() << "\033[0m";
            }
            else
                flux << ".";
        }
        flux << endl;
    }
    return flux.str();
}


int main(int argc, const char** argv) {
    doctest::Context context(argc, argv);
    int test_result = context.run();
    context.setAsDefaultForAssertsOutOfTestCases();
    if (context.shouldExit()) return test_result;
    
    
    //cout << "LES TESTS PASSENT ;)" << endl;

    //Coord c(5,5);
    //cout << c << endl;

    //Direction dir = Direction::EST;
    //cout << "main: La direction est : " << aGauche(dir) << endl;
    /*
    Direction dir = Direction::OUEST;
    cout << "Direction initiale : " << dir << endl;
    dir = aDroite(dir);
    cout << "Direction apres une rotation a droite : " << dir << endl;
    dir = aGauche(dir);
    cout << "Direction apres une rotation a gauche : " << dir << endl;
    */

    // Grille g;

    // g.poseTermite(Coord (5,5), 1);

    // g.poseBrindille(Coord (2, 6));
    // g.poseBrindille(Coord (0, 0));
    
    // cout << g << endl;   

    //Termite t(1, Coord (2, 2), 0, false);
    //cout << t.toString() << endl;

    // Termite termite(1, 0, 0); 
    // termite.setDir(Direction::SUD);
    // cout << termite.toString() << endl;

    // Grille g;
    // Coord c1(2, 2);
    // g.poseTermite(c1, 4);
    // Termite t(4, 2, 2);
    // t.setDir(Direction::NORD);
    // t.marcheAleatoire(g);
    // cout << (t.getX()) << " " << (t.getY()) << " " << t.getDir() << endl;

    // cout << "___________" << endl;
    // t.setDir(Direction::NORD_EST);
    // cout << "COORD" << endl;
    // cout << c1 << endl;
    // cout << devantCoord(c1, Direction::NORD) << endl;

    // cout << "TERMITE" << endl;
    // cout << "avant : " << t.getX() << " " << t.getY() << endl;
    // t.marcheAleatoire(g);
    // t.avanceTermite(g);
    //cout << "devant : " << t.devant() << endl;
    // cout << "avanceTermite : " << t.getX() << " " << t.getY() << endl;

    // Grille g;
    // g.poseBrindille(Coord(2,2));

    // Termite t(1, 2, 3);
    // t.setDir(Direction::OUEST);
    // g.poseTermite(Coord(2,3), 1);

    // t.chargeBrindille(t, g);
    // t.dechargeBrindille(g);
    
    // cout << g << endl;   

    // cout << "\033[32;1m" << "Bonjour" << "\033[0m" << endl;

    // Grille g;
    // Termite t(1, 2, 3);
    // t.setDir(Direction::OUEST);
    // g.poseTermite(Coord(2,3), 1);
    // cout << "avant " << t.getDir() << " " << t.getX() << "," << t.getY() << endl; 

    // t.marcheAleatoire(g);
    // cout << "apres " << t.getDir() << " " << t.getX() << "," << t.getY() << endl; 


/////////////////////////////// SUJET - Q3 & 4 ////////////////////////////////////
    // Grille g;
    // // Initialisation du contenu de chaque case de la grille
    // for (int i = 0; i < 20; i++) {
    //     for (int j = 0; j < 20; j++) {
    //         float randVal = rand() % 100; 
    //         if (randVal < densiteBrindille) {
    //             g.poseBrindille(Coord(i, j));

    //         } else {
    //             g.enleveTermite(Coord(i, j));
    //         }
    //     }
    // }

    // // Initialisation des termites
    // for (int i = 0; i < nbTermites; i++) {
    //     int randLig, randCol;
    //     do {
    //         randLig = rand() % 20;
    //         randCol = rand() % 20;
    //     } while (!g.estVide(Coord(randLig, randCol)));
    //     g.poseTermite(Coord(randLig, randCol), i);
    // }

    // cout << g << endl;
//////////////////////////////////////////////////////////////////////


/////////////////////////////// SUJET - Q5 & Q6 ////////////////////////////////////
    Grille g;
    Population p;
    for (int i = 0; i < tailleGrille; i++) {
        for (int j = 0; j < tailleGrille; j++) {
            float randVal = rand() % 150; 
            if (randVal < densiteBrindille) {
                g.poseBrindille(Coord(i, j));

            }
        }
    }


    Termite ter0(0,0,10);
    ter0.setDir(Direction::SUD);
    if (not(g.estVide(Coord(0,10)))) 
        g.enleveBrindille(Coord (0, 10));
    g.poseTermite(Coord(0,10), 0);
    p.ajoutTer(ter0);

    Termite ter1(1, 13, 0);
    if (not(g.estVide(Coord(13, 0)))) 
        g.enleveBrindille(Coord (13, 0));
    ter1.setDir(Direction::NORD);
    g.poseTermite(Coord(13, 0), 1);
    p.ajoutTer(ter1);

    p.deplacerAleatoire(g);

//////////////////////////////////////////////////////////////////////


/////////////////////////////// SUJET - Q7 ////////////////////////////////////
    /* Grille g;
    Population p;
    for (int i = 0; i < tailleGrille; i++) {
        for (int j = 0; j < tailleGrille; j++) {
            float randVal = rand() % 150; 
            if (randVal < densiteBrindille) {
                g.poseBrindille(Coord(i, j));

            }
        }
    }


    Termite ter0(0,0,10);
    ter0.setDir(Direction::SUD);
    if (not(g.estVide(Coord(0,10)))) 
        g.enleveBrindille(Coord (0, 10));
    g.poseTermite(Coord(0,10), 0);
    p.ajoutTer(ter0);

    Termite ter1(1, 13, 0);
    if (not(g.estVide(Coord(13, 0)))) 
        g.enleveBrindille(Coord (13, 0));
    ter1.setDir(Direction::NORD);
    g.poseTermite(Coord(13, 0), 1);
    p.ajoutTer(ter1);

    p.deplacerAleatoireBIS(g, 10); */


    cout << " " << endl;
    return 0;
}

