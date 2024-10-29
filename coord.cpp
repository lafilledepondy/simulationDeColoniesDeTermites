#include "doctest.h"
#include "coord.hpp"


Coord::Coord(int lig, int col){
    if (lig<0 or lig>= tailleGrille or col<0 or col>=tailleGrille)
        throw out_of_range("Coord::Coord -- Argument must be non-negative and within range");
    this->p_ligne = lig;
    this->p_colonne = col;
}    

TEST_CASE("Q9. Coord") {
  CHECK_THROWS_AS(Coord(-1, 0), out_of_range); // Test with invalid row
  CHECK_THROWS_AS(Coord(0, -1), out_of_range); // Test with invalid column
  CHECK_THROWS_AS(Coord c(0, 20), out_of_range); // Test with a border + value

  CHECK_NOTHROW(Coord c(0, 0)); // Coord dans l'intervalle
  CHECK_NOTHROW(Coord c(19, 19)); // Coord dans l'intervalle
}


int Coord::getLig() const {
    return p_ligne; 
}


int Coord::getCol() const {
    return p_colonne;
}

TEST_CASE("Q10. Getters") {
    Coord c(2, 5);
    CHECK(c.getLig() == 2); 
    CHECK(c.getCol() == 5);
    
    Coord c1(1, 1);
    CHECK(c1.getLig() == 1); 
    CHECK(c1.getCol() == 1);
}


ostream& operator<<(ostream& out, const Coord& crd) {
    out << "(" << crd.getLig() << ", " << crd.getCol() << ")";
    return out;
}
// tests voir le main de projet.cpp

bool Coord::operator==(const Coord other) const {
    return p_colonne==other.p_colonne and p_ligne==other.p_ligne ;
}

TEST_CASE("Q13. Coord::operator==") {
    Coord c(2, 5);
    Coord cbis(2, 5);
    Coord cwrong(1, 6);
    CHECK(c == cbis);
    CHECK_FALSE(cbis == cwrong);
}


ostream& operator<<(ostream& out, Direction dir){
    switch (dir) {
        case Direction::NORD_OUEST: out << "NORD OUEST"; break;
        case Direction::NORD: out << "NORD"; break;
        case Direction::NORD_EST: out << "NORD EST"; break;
        case Direction::EST: out << "EST"; break;
        case Direction::SUD_EST: out << "SUD EST"; break;
        case Direction::SUD: out << "SUD"; break;
        case Direction::SUD_OUEST: out << "SUD OUEST"; break;
        case Direction::OUEST: out << "OUEST"; break;
    default:
        out << "pas une direction"; break;
    }  
    return out;  
}
//test voir le main du fichier projet.cpp

Direction aGauche(Direction dir) {
    Direction g;
    switch (dir) {
        case Direction::NORD_OUEST: g = Direction::OUEST; break;
        case Direction::NORD: g = Direction::NORD_OUEST; break;
        case Direction::NORD_EST: g = Direction::NORD; break;
        case Direction::EST: g = Direction::NORD_EST; break;
        case Direction::SUD_EST: g = Direction::EST; break;
        case Direction::SUD: g = Direction::SUD_EST; break;
        case Direction::SUD_OUEST: g = Direction::SUD; break;
        case Direction::OUEST: g = Direction::SUD_OUEST; break;
    default:
        g = dir; break;
    }
    return g;
}


Direction aDroite(Direction dir) {
    Direction d;
    switch (dir) {
        case Direction::NORD_OUEST: d = Direction::NORD; break;
        case Direction::NORD: d = Direction::NORD_EST; break;
        case Direction::NORD_EST: d = Direction::EST; break;
        case Direction::EST: d = Direction::SUD_EST; break;
        case Direction::SUD_EST: d = Direction::SUD; break;
        case Direction::SUD: d = Direction::SUD_OUEST; break;
        case Direction::SUD_OUEST: d = Direction::OUEST; break;
        case Direction::OUEST: d = Direction::NORD_OUEST; break;
    default:
        d = dir; break;
    }
    return d;
}

TEST_CASE("Q.18 aGauche et aDroite"){
    SUBCASE("Q.18 (a) gauche-->droite = pt initiale") {
        Direction dir1 = Direction::SUD;
        dir1 = aGauche(dir1);
        dir1 = aDroite(dir1);
        CHECK(dir1 == Direction::SUD);

        Direction dir2 = Direction::NORD;
        dir2 = aGauche(dir2);
        dir2 = aDroite(dir2);
        CHECK(dir2 == Direction::NORD);

        Direction dir3 = Direction::EST;
        dir3 = aGauche(dir3);
        dir3 = aDroite(dir3);
        CHECK(dir3 == Direction::EST);

        Direction dir4 = Direction::NORD_EST;
        dir4 = aGauche(dir4);
        dir4 = aDroite(dir4);
        CHECK(dir4 == Direction::NORD_EST);

        Direction dir5 = Direction::NORD_OUEST;
        dir5 = aGauche(dir5);
        dir5 = aDroite(dir5);
        CHECK(dir5 == Direction::NORD_OUEST);

        Direction dir6 = Direction::OUEST;
        dir6 = aGauche(dir6);
        dir6 = aDroite(dir6);
        CHECK(dir6 == Direction::OUEST);

        Direction dir7 = Direction::SUD_EST;
        dir7 = aGauche(dir7);
        dir7 = aDroite(dir7);
        CHECK(dir7 == Direction::SUD_EST);

        Direction dir8 = Direction::SUD_OUEST;
        dir8 = aGauche(dir8);
        dir8 = aDroite(dir8);
        CHECK(dir8 == Direction::SUD_OUEST);
    }

    SUBCASE("Q.18 (b) droite-->gauche = pt initiale") {
        Direction dir = Direction::OUEST;
        dir = aDroite(dir);
        dir = aGauche(dir);
        CHECK(dir == Direction::OUEST);
    }

    SUBCASE("Q.18 (c) 8*gauche") {
        Direction d = Direction::NORD;
        for (int i = 0; i < 8; i++) {
            d = aGauche(d);
        }
        CHECK(d == Direction::NORD);
    }

    SUBCASE("Q18 (d) 8*droite") {
        Direction d = Direction::EST;
        for (int i = 0; i < 8; i++) {
            d = aDroite(d);
        }
        CHECK(d == Direction::EST);
    }
}

Coord devantCoord(const Coord& coord, Direction dir) {
    int lig = coord.getLig();
    int col = coord.getCol();
    
    switch(dir) {
        case Direction::NORD_OUEST: 
            lig--; col--; break;
        case Direction::NORD:
            lig--; break;
        case Direction::NORD_EST:
            lig--; col++; break;
        case Direction::EST:
            col++; break;
        case Direction::SUD_EST:
            lig++; col++; break;
        case Direction::SUD:
            lig++; break;
        case Direction::SUD_OUEST:
            lig++; col--; break;
        case Direction::OUEST:
            col--; break;
    }
    return Coord(lig, col);
}

TEST_CASE("Q20 devantCoord") {
    SUBCASE("devantCoord with valid inputs"){
        CHECK(devantCoord(Coord(1, 1), Direction::NORD) == Coord(0, 1));
        CHECK(devantCoord(Coord(1, 1), Direction::EST) == Coord(1, 2));
        CHECK(devantCoord(Coord(1, 1), Direction::SUD) == Coord(2, 1));
        CHECK(devantCoord(Coord(1, 1), Direction::OUEST) == Coord(1, 0));
    }

    Coord coord1(2, 2);

    SUBCASE("devantCoord - direction NORD") {
        Coord coord2(1, 2);
        CHECK(devantCoord(coord1, Direction::NORD) == coord2);
    }

    SUBCASE("devantCoord - direction SUD_EST") {
        Coord coord2(3, 3);
        CHECK(devantCoord(coord1, Direction::SUD_EST) == coord2);
    }

    SUBCASE("devantCoord - direction NORD_OUEST") {
    Coord c(4, 4);
    Coord resultatAttendu(3, 3);
    CHECK(devantCoord(c, Direction::NORD_OUEST) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction NORD") {
        Coord c(4, 4);
        Coord resultatAttendu(3, 4);
        CHECK(devantCoord(c, Direction::NORD) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction NORD_EST") {
        Coord c(4, 4);
        Coord resultatAttendu(3, 5);
        CHECK(devantCoord(c, Direction::NORD_EST) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction EST") {
        Coord c(4, 4);
        Coord resultatAttendu(4, 5);
        CHECK(devantCoord(c, Direction::EST) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction SUD_EST") {
        Coord c(4, 4);
        Coord resultatAttendu(5, 5);
        CHECK(devantCoord(c, Direction::SUD_EST) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction SUD") {
        Coord c(4, 4);
        Coord resultatAttendu(5, 4);
        CHECK(devantCoord(c, Direction::SUD) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction SUD_OUEST") {
        Coord c(4, 4);
        Coord resultatAttendu(5, 3);
        CHECK(devantCoord(c, Direction::SUD_OUEST) == resultatAttendu);
    }

    SUBCASE("devantCoord - direction OUEST") {
        Coord c(4, 4);
        Coord resultatAttendu(4, 3);
        CHECK(devantCoord(c, Direction::OUEST) == resultatAttendu);
    }

    SUBCASE("devantCoord with invalid inputs"){
        CHECK_THROWS_AS(devantCoord(Coord(0, 0), Direction::NORD_OUEST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(0, 0), Direction::NORD), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(0, 0), Direction::OUEST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 20), Direction::NORD_EST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(19, 20), Direction::EST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 20), Direction::SUD_EST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 0), Direction::SUD_OUEST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 0), Direction::SUD), out_of_range);
    }
}

TEST_CASE("Q21 1*devantCoord + 4*aDroite") {
    Coord currentCoord(10, 10);
    Direction currentDir = Direction::NORD;
    currentCoord = devantCoord(currentCoord, currentDir);
    for(int i = 0; i < 4; i++) {
        currentDir = aDroite(currentDir);
    }
    currentCoord = devantCoord(currentCoord, currentDir);
    CHECK(currentCoord == Coord(10, 10));
}

