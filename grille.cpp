#include "doctest.h"

#include "grille.hpp"


bool Grille::estVide(Coord c) const {
        return ((not cas[c.getLig()][c.getCol()].brindille )&& (cas[c.getLig()][c.getCol()].idTermite == -1));
}

TEST_CASE("estVide(c)") {
    Grille g;
    Coord c1(5,5);
    CHECK(g.estVide(c1));
}


void Grille::poseBrindille(Coord c) {
    if (estVide(c)){
        cas[c.getLig()][c.getCol()].brindille = true;
        return ;
        }
    throw out_of_range("Grille::poseBrindille -- Cannot place brindille on non-empty cell !!!");
}

TEST_CASE("poseBrindille") {
    Grille g;
    Coord c1(5,5);
    g.poseBrindille(c1);
    CHECK_FALSE(g.estVide(c1));
}


bool Grille::contientBrindille(Coord c) const {
    return (cas[c.getLig()][c.getCol()].brindille);
}

TEST_CASE("contientBrindille") {
    Grille g;
    Coord c1(5,5);
    CHECK_FALSE(g.contientBrindille(c1));
    g.poseBrindille(c1);
    CHECK(g.contientBrindille(c1));
}  


void Grille::enleveBrindille(Coord c) {
    if (contientBrindille(c)){
        cas[c.getLig()][c.getCol()].brindille = false;
        return;
    }
    throw out_of_range("Grille::enleveBrindille -- Cannot remove brindille from empty cell !!!");
}

TEST_CASE("enleveBrindille") {
    Grille g;
    Coord c1(5,5);
    g.poseBrindille(c1);
    g.enleveBrindille(c1);
    CHECK(g.estVide(c1));
        
    Coord c2(1,5);
    CHECK_THROWS_AS(g.enleveBrindille(c2), out_of_range);
}


void Grille::poseTermite(Coord c, int idT) {
    if (estVide(c)){
        cas[c.getLig()][c.getCol()].idTermite = idT;
        return;
    }
    throw out_of_range("Grille::poseTermite -- Cannot place termite on non-empty cell !!!");
}

TEST_CASE("poseTermite") {
    Grille g;
    Coord c1(5,5);
    g.poseTermite(c1, 1);
    CHECK(g.numéroTermite(c1) == 1);
}
    

void Grille::enleveTermite(Coord c) {
    if (not(contientBrindille(c))){
        cas[c.getLig()][c.getCol()].idTermite = -1;
        return ;
    }
    throw out_of_range("Grille::enleveTermite -- Cannot remove termite from empty cell !!!");
}


int Grille::numéroTermite(Coord c) const {
    if (not(estVide(c)) and not(contientBrindille(c)))
        return cas[c.getLig()][c.getCol()].idTermite;
    //throw std::out_of_range("Grille::numéroTermite -- Coordonnées invalide pour le termite");
    return -1;
}

TEST_CASE("enleveTermite") {
    Grille g;
    Coord c1(5,5);
    g.poseTermite(c1, 1);
    CHECK(g.numéroTermite(c1) == 1);       
}


TEST_CASE("Vérifications des exceptions"){
    SUBCASE("throw -- poseTermite"){
        Grille g;

        Coord c1(4, 5);
        g.poseTermite(c1, 1);

        CHECK_THROWS_AS(g.poseBrindille(c1), out_of_range);
    }

    SUBCASE("throw -- poseBrindille"){
        Grille g;

        Coord c1(4, 5);
        g.poseBrindille(c1);

        CHECK_THROWS_AS(g.poseTermite(c1, 1), out_of_range);
    }

        SUBCASE("throw -- enleveTermite"){
        Grille g;

        Coord c1(4, 5);
        g.poseBrindille(c1);

        CHECK_THROWS_AS(g.enleveTermite(c1), out_of_range);
    }

    SUBCASE("throw -- enleveBrindille"){
        Grille g;

        Coord c1(4, 5);
        g.poseTermite(c1, 19);

        CHECK_THROWS_AS(g.poseBrindille(c1), out_of_range);
    }
}


// ostream& operator<<(ostream& out, const Grille& g) {
//     for (int i = 0; i < tailleGrille; i++) {
//         for (int j = 0; j < tailleGrille; j++) {
//             Coord c(i, j);
//             if (g.contientBrindille(c))
//                 out << "\033[32;1m" << "B" << "\033[0m";
//             else if (g.numéroTermite(c) != -1)
//                 out << "\033[31;1m" << "T" << "\033[0m" ;
//             else
//                 out << ".";
//         }
//         out << endl;
//     }
//     return out;
// }
