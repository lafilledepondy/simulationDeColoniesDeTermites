using namespace std;

#include "doctest.h"

#include "termite.hpp"


string Termite::toString() const {
    string afficheT;
    switch (direction) {
        case Direction::SUD: case Direction::NORD:
            afficheT = '|'; 
            break;
        case Direction::EST: case Direction::OUEST:
            afficheT = '_'; 
            break;
        case Direction::NORD_OUEST: case Direction::SUD_EST:
            afficheT = '\\'; 
            break;
        case Direction::NORD_EST: case Direction::SUD_OUEST:
            afficheT = '/'; 
            break;
        default:
            afficheT = ' '; 
            break;
    }
    return afficheT;
}

TEST_CASE("Termite::toString()") {
    SUBCASE("Sud") {
        Termite t(1, 0, 0);
        t.setDir(Direction::SUD);
        CHECK_EQ(t.toString(), "|");
    }

    SUBCASE("Nord") {
        Termite t(2, 0, 0);
        t.setDir(Direction::NORD);
        CHECK_EQ(t.toString(), "|");
    }

    SUBCASE("Est") {
        Termite t(3, 0, 0);
        t.setDir(Direction::EST);
        CHECK_EQ(t.toString(), "_");
    }

    SUBCASE("TOuest") {
        Termite t(4, 0, 0);
        t.setDir(Direction::OUEST);
        CHECK_EQ(t.toString(), "_");
    }

    SUBCASE("Nord-ouest") {
        Termite t(5, 0, 0);
        t.setDir(Direction::NORD_OUEST);
        CHECK_EQ(t.toString(), "\\");
    }

    SUBCASE("Sud-est") {
        Termite t(6, 0, 0);
        t.setDir(Direction::SUD_EST);
        CHECK_EQ(t.toString(), "\\");
    }

    SUBCASE("Nord-est") {
        Termite t(7, 0, 0);
        t.setDir(Direction::NORD_EST);
        CHECK_EQ(t.toString(), "/");
    }

    SUBCASE("Sud-ouest") {
        Termite t(8, 0, 0);
        t.setDir(Direction::SUD_OUEST);
        CHECK_EQ(t.toString(), "/");
    }
}


Direction Termite::directionTermite() const {
    return direction; // static_cast<int>(direction) si c'etait enum
}


Coord Termite::devant() const {
    int dy = 0, dx = 0;
    switch(direction) {
        case Direction::NORD:
            dx = -1;
            break;
        case Direction::SUD:
            dx = 1;
            break;
        case Direction::EST:
            dy = 1;
            break;
        case Direction::OUEST:
            dy = -1;
            break;
        case Direction::NORD_EST:
            dx = -1;
            dy = 1;
            break;
        case Direction::NORD_OUEST:
            dx = -1;
            dy = -1;
            break;
        case Direction::SUD_EST:
            dx = 1;
            dy = 1;
            break;
        case Direction::SUD_OUEST:
            dx = 1;
            dy = -1;            
            break;
    }
    return Coord(X + dx, Y + dy);
}

TEST_CASE("devant()") {
    Termite t(1, 5, 5);
    t.setDir(Direction::NORD);
    CHECK(t.devant() == Coord(4, 5));

    t.setDir(Direction::SUD);
    CHECK(t.devant() == Coord(6, 5));

    t.setDir(Direction::EST);
    CHECK(t.devant() == Coord(5, 6));

    t.setDir(Direction::OUEST);
    CHECK(t.devant() == Coord(5, 4));

    t.setDir(Direction::NORD_EST);
    CHECK(t.devant() == Coord(4, 6));

    t.setDir(Direction::NORD_OUEST);
    CHECK(t.devant() == Coord(4, 4));

    t.setDir(Direction::SUD_EST);
    CHECK(t.devant() == Coord(6, 6));

    t.setDir(Direction::SUD_OUEST);
    CHECK(t.devant() == Coord(6, 4));
}


bool Termite::porteBrindille() const {
    return hasBrindille;
}

TEST_CASE("Termite::porteBrindille") {
    // Cas où le termite porte une brindille
    Termite t1(1, 3, 4);
    t1.setBrindille(true);
    CHECK(t1.porteBrindille());

    // Cas où le termite ne porte pas de brindille
    Termite t2(2, 5, 6);
    t2.setBrindille(false);
    CHECK_FALSE(t2.porteBrindille());
}


void Termite::tourneADroite() {
    switch (direction) {
        case Direction::NORD:
            direction = Direction::NORD_EST;
            break;
        case Direction::SUD:
            direction = Direction::SUD_OUEST;
            break;
        case Direction::EST:
            direction = Direction::SUD_EST;
            break;
        case Direction::OUEST:
            direction = Direction::NORD_OUEST;
            break;
        case Direction::NORD_EST:
            direction = Direction::EST;
            break;
        case Direction::NORD_OUEST:
            direction = Direction::NORD;
            break;
        case Direction::SUD_EST:
            direction = Direction::SUD;
            break;
        case Direction::SUD_OUEST:
            direction = Direction::OUEST;
            break;
    }
}

TEST_CASE("Termite::tourneADroite()") {
    Termite t(1, 5, 5);
    t.setDir(Direction::NORD);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::NORD_EST);

    t.setDir(Direction::NORD_EST);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::EST);

    t.setDir(Direction::EST);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::SUD_EST);

    t.setDir(Direction::SUD_EST);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::SUD);

    t.setDir(Direction::SUD);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::SUD_OUEST);

    t.setDir(Direction::SUD_OUEST);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::OUEST);

    t.setDir(Direction::OUEST);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::NORD_OUEST);

    t.setDir(Direction::NORD_OUEST);
    t.tourneADroite();
    CHECK(t.directionTermite() == Direction::NORD);
}


void Termite::tourneAGauche() {
    switch (direction) {
        case Direction::NORD:
            direction = Direction::NORD_OUEST;
            break;
        case Direction::SUD:
            direction = Direction::SUD_EST;
            break;
        case Direction::EST:
            direction = Direction::NORD_EST;
            break;
        case Direction::OUEST:
            direction = Direction::SUD_OUEST;
            break;
        case Direction::NORD_EST:
            direction = Direction::NORD;
            break;
        case Direction::NORD_OUEST:
            direction = Direction::OUEST;
            break;
        case Direction::SUD_EST:
            direction = Direction::EST;
            break;
        case Direction::SUD_OUEST:
            direction = Direction::SUD;
            break;
    }
}

TEST_CASE("Termite::tourneAGauche()") {
    Termite t(1, 5, 5);
    t.setDir(Direction::NORD);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::NORD_OUEST);

    t.setDir(Direction::NORD_OUEST);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::OUEST);

    t.setDir(Direction::OUEST);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::SUD_OUEST);

    t.setDir(Direction::SUD_OUEST);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::SUD);

    t.setDir(Direction::SUD);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::SUD_EST);

    t.setDir(Direction::SUD_EST);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::EST);

    t.setDir(Direction::EST);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::NORD_EST);

    t.setDir(Direction::NORD_EST);
    t.tourneAGauche();
    CHECK(t.directionTermite() == Direction::NORD);
}


void Termite::tourneAleat() {
    int aleat = rand() % 2;
    switch(aleat) {
        case 0: tourneADroite(); break;
        case 1: tourneAGauche(); break;
        default: break;
    }
    // setDir(Direction(rand() % 9));
}

TEST_CASE("Termite::tourneAleat()") {
    // Test des cas de tourner à droite ou à gauche
    SUBCASE("Direction::Nord") {
        Termite t(1, 5, 5);
        t.setDir(Direction::NORD);
        t.tourneAleat();
        if (t.directionTermite() == Direction::NORD_EST)
            CHECK(t.directionTermite() == Direction::NORD_EST);
        else if(t.directionTermite() == Direction::NORD_OUEST)
            CHECK(t.directionTermite() == Direction::NORD_OUEST);
    }

    SUBCASE("Direction::Nord_est") {
        Termite t(1, 5, 5);
        t.setDir(Direction::NORD_EST);
        t.tourneAleat();
        if (t.directionTermite() == Direction::NORD)
            CHECK(t.directionTermite() == Direction::NORD);
        else if (t.directionTermite() == Direction::EST)
            CHECK(t.directionTermite() == Direction::EST); 
    }

    SUBCASE("Direction::EST") {
        Termite t(1, 5, 5);
        t.setDir(Direction::EST);
        t.tourneAleat();
        if (t.directionTermite() == Direction::NORD_EST)
            CHECK(t.directionTermite() == Direction::NORD_EST);
        else if (t.directionTermite() == Direction::SUD_EST)
            CHECK(t.directionTermite() == Direction::SUD_EST); 
    }

    SUBCASE("Direction::SUD_EST") {
        Termite t(1, 5, 5);
        t.setDir(Direction::SUD_EST);
        t.tourneAleat();
        if (t.directionTermite() == Direction::EST)
            CHECK(t.directionTermite() == Direction::EST);
        else if (t.directionTermite() == Direction::SUD)
            CHECK(t.directionTermite() == Direction::SUD); 
    }

    SUBCASE("Direction::SUD") {
        Termite t(1, 5, 5);
        t.setDir(Direction::SUD);
        t.tourneAleat();
        if (t.directionTermite() == Direction::SUD_EST)
            CHECK(t.directionTermite() == Direction::SUD_EST);
        else if (t.directionTermite() == Direction::SUD_OUEST)
            CHECK(t.directionTermite() == Direction::SUD_OUEST);
    }

    SUBCASE("Direction::SUD_OUEST") {
        Termite t(1, 5, 5);
        t.setDir(Direction::SUD_OUEST);
        t.tourneAleat();
        if (t.directionTermite() == Direction::SUD)
            CHECK(t.directionTermite() == Direction::SUD);
        else if (t.directionTermite() == Direction::NORD)
            CHECK(t.directionTermite() == Direction::NORD);
    }

    SUBCASE("Direction::OUEST") {
        Termite t(1, 5, 5);
        t.setDir(Direction::OUEST);
        t.tourneAleat();
        if (t.directionTermite() == Direction::SUD_OUEST)
            CHECK(t.directionTermite() == Direction::SUD_OUEST);
        else if (t.directionTermite() == Direction::NORD_OUEST)
            CHECK(t.directionTermite() == Direction::NORD_OUEST); 
    }

    SUBCASE("Direction::NORD_OUEST") {
        Termite t(1, 5, 5);
        t.setDir(Direction::NORD_OUEST);
        t.tourneAleat();
        if (t.directionTermite() == Direction::NORD)
            CHECK(t.directionTermite() == Direction::NORD);
        else if (t.directionTermite() == Direction::OUEST)
            CHECK(t.directionTermite() == Direction::OUEST);   
    }
}


bool Termite::laVoieEstLibre(const Grille &g) const {
    Coord c = devant();
    return g.estVide(c);
}

TEST_CASE("laVoieEstLibre()") {
    SUBCASE("laVoieEstLibre() -- return false") {
        Grille g;
        g.poseTermite(Coord(1, 1), 1);
        g.poseBrindille(Coord(2, 1));
        Termite t(1, 2, 1); // termite est maintenant à côté de la brindille
        t.setDir(Direction::NORD);
        CHECK_FALSE(t.laVoieEstLibre(g));
    }

    SUBCASE("laVoieEstLibre() -- return true") {
        Grille g;
        Termite t(1, 2, 1);
        t.setDir(Direction::NORD);
        CHECK(t.laVoieEstLibre(g));
    }

    SUBCASE("laVoieEstLibre() retourne false si la termite est sur un bord de la grille") {
        Grille g;
        Termite t(1, 0, 0);
        t.setDir(Direction::OUEST);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);

        t.setX(tailleGrille-1);
        t.setY(0);
        t.setDir(Direction::SUD_OUEST);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);

        t.setX(tailleGrille-1);
        t.setY(1);
        t.setDir(Direction::SUD);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);

        t.setX(tailleGrille-1);
        t.setY(tailleGrille-1);
        t.setDir(Direction::SUD_EST);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);

        t.setX(1);
        t.setY(tailleGrille-1);
        t.setDir(Direction::EST);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);
    
        
        t.setX(1);
        t.setY(tailleGrille-1);
        t.setDir(Direction::NORD_EST);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);
    
        
        t.setX(0);
        t.setY(10);
        t.setDir(Direction::NORD);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);
    
        
        t.setX(0);
        t.setY(0);
        t.setDir(Direction::NORD_OUEST);
        CHECK_THROWS_AS(t.laVoieEstLibre(g), out_of_range);   
    }

}


bool Termite::brindilleEnFace(const Grille& g) const {
    Coord c = devant();
    return g.contientBrindille(c);
}

TEST_CASE("brindilleEnFace()") {
    SUBCASE("brindilleEnFace() -- return false") {
        Grille g;
        g.poseTermite(Coord(1, 1), 1);
        g.poseBrindille(Coord(2, 1));
        Termite t(1, 2, 1);
        t.setDir(Direction::SUD);
        CHECK_FALSE(t.brindilleEnFace(g));
    }

    SUBCASE("brindilleEnFace() -- return true") {
        Grille g;
        Termite t(1, 1, 1);
        t.setDir(Direction::NORD);
        CHECK(t.laVoieEstLibre(g));
    }
}


int Termite::voisinsLibre(const Grille& g) const {
    int libre = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue; // ne pas vérifier la case actuelle
            int x = X + dx;
            int y = Y + dy;
            if (x >= 0 && x < tailleGrille && y >= 0 && y < tailleGrille) {
                if (g.estVide(Coord(x, y)))
                    libre++;
            }
        }
    }
    return libre;
}


TEST_CASE("voisinsLibre") {
    Grille g;
    Termite t(1, 5, 5); // termite au centre de la grille
    g.poseBrindille(Coord (4, 5)); // occupé à gauche de la termite
    g.poseBrindille(Coord (5, 4)); // occupé en haut de la termite
    g.poseBrindille(Coord (6, 5)); // occupé à droite de la termite
    g.poseBrindille(Coord (5, 6)); // occupé en bas de la termite
    g.poseBrindille(Coord (4, 4));
    g.poseBrindille(Coord (4, 6));
    g.poseBrindille(Coord (6, 4));
    g.poseBrindille(Coord (6, 6));

    // Test avec une termite entourée d'obstacles
    CHECK(t.voisinsLibre(g) == 0);
        
    // Test avec une termite entourée d'espaces vides
    g.enleveBrindille(Coord (4, 5));
    g.enleveBrindille(Coord (5, 4));
    g.enleveBrindille(Coord (6, 5));
    g.enleveBrindille(Coord (5, 6));
    g.enleveBrindille(Coord (4, 4));
    g.enleveBrindille(Coord (4, 6));
    g.enleveBrindille(Coord (6, 4));
    g.enleveBrindille(Coord (6, 6));
    CHECK(t.voisinsLibre(g) == 8);

    // Test avec une termite au bord de la grille
    Termite t2(2, 0, 0);
    g.poseTermite(Coord (0, 0), 2);
    g.poseBrindille(Coord(1, 0));
    g.poseBrindille(Coord (0, 1));
    CHECK(t2.voisinsLibre(g) == 1);

    // Test avec une grille vide
    Grille g2;
    Termite t3(3, 15, 15);
    CHECK(t3.voisinsLibre(g2) == 8);
}


void Termite::avanceTermite(Grille &g) {    
    Coord positionCourante(X, Y);
    g.enleveTermite(positionCourante);
    Coord positionDevant = devantCoord(positionCourante, direction);
    g.poseTermite(positionDevant, idTermite);
    X = positionDevant.getLig();
    Y = positionDevant.getCol();
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Nord") {
    Grille g;
    g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::NORD);
    t.avanceTermite(g);
    CHECK(t.getX() == 4);
    CHECK(t.getY() == 5);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Sud") {
    Grille g;
    g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::SUD);
    t.avanceTermite(g);
    CHECK(t.getX() == 6);
    CHECK(t.getY() == 5);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Est") {
    Grille g;
    g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::EST);
    t.avanceTermite(g);
    CHECK(t.getX() == 5);
    CHECK(t.getY() == 6);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Ouest") {
    Grille g;
     g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::OUEST);
    t.avanceTermite(g);
    CHECK(t.getX() == 5);
    CHECK(t.getY() == 4);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Nord-Est") {
    Grille g;
     g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::NORD_EST);
    t.avanceTermite(g);
    CHECK(t.getX() == 4);
    CHECK(t.getY() == 6);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Nord-Ouest") {
    Grille g;
     g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::NORD_OUEST);
    t.avanceTermite(g);
    CHECK(t.getX() == 4);
    CHECK(t.getY() == 4);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Sud-Est") {
    Grille g;
     g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::SUD_EST);
    t.avanceTermite(g);
    CHECK(t.getX() == 6);
    CHECK(t.getY() == 6);
}

TEST_CASE("AvanceTermite : Test des déplacements en direction Sud_Ouest") {
    Grille g;
     g.poseTermite(Coord(5, 5),  1);
    Termite t(1, 5, 5);
    t.setDir(Direction::SUD_OUEST);
    t.avanceTermite(g);
    CHECK(t.getX() == 6);
    CHECK(t.getY() == 4);
}


bool Termite::estBordure(const Grille& g, const Coord& c) const {
    int x = c.getLig();
    int y = c.getCol();
    // Vérifier si la coordonnée est sur le bord gauche ou droit
    if (x == 0 || x == tailleGrille - 1) {
        return true;
    }
    // Vérifier si la coordonnée est sur le bord haut ou bas
    if (y == 0 || y == tailleGrille - 1) {
        return true;
    }
    // Si la coordonnée n'est sur aucun des bords, elle n'est pas une bordure
    return false;
}

TEST_CASE("Test de la fonction estBordure") {

    SUBCASE("Coordonnée à l'intérieur de la grille") {
        Grille grille;
        Coord coord(2, 2);
        Termite termite(0, 1, 2);
        REQUIRE_EQ(termite.estBordure(grille, coord), false);
    }
    SUBCASE("Coordonnée sur le bord gauche de la grille") {
        Grille grille;
        Coord coord(0, 3);
        Termite termite(1, 0, 3);
        REQUIRE_EQ(termite.estBordure(grille, coord), true);
    }

    SUBCASE("Coordonnée sur le bord droit de la grille") {
        Grille grille;
        Coord coord(0, 0);
        Termite termite(2, 0, 0);
        REQUIRE_EQ(termite.estBordure(grille, coord), true);
    }

    SUBCASE("Coordonnée sur le bord supérieur de la grille") {
        Grille grille;
        Coord coord(1, 0);
        Termite termite(3, 1, 0);
        REQUIRE_EQ(termite.estBordure(grille, coord), true);
    }

    SUBCASE("Coordonnée sur le bord inférieur de la grille") {
        Grille grille;
        Coord coord(19, 19);
        Termite termite(4, 19, 19);
        REQUIRE_EQ(termite.estBordure(grille, coord), true);
    }
}


void Termite::changerDirectionBord(Termite& t, const Grille& g) {
    int x = t.getX(); 
    int y = t.getY();
    int aleat = rand() % 3;
    if (x == 0) {
        if (y == 0) {
            // coin haut-gauche
            switch(aleat) {
                case 0: t.setDir(Direction::EST); break;
                case 1: t.setDir(Direction::SUD_EST); break;
                case 2: t.setDir(Direction::SUD); break;
                default: break;
            }
        } else if (y == tailleGrille-1) {
            // coin bas-gauche
            switch(aleat) {
                case 0: t.setDir(Direction::OUEST); break;
                case 1: t.setDir(Direction::SUD_OUEST); break;
                case 2: t.setDir(Direction::SUD); break;
                default: break;
            }
        } else {
            // bord gauche
            t.setDir(Direction::SUD);
        }
    } else if (x == tailleGrille-1) {
        if (y == 0) {
            // coin haut-droit
            switch(aleat) {
                case 0: t.setDir(Direction::EST); break;
                case 1: t.setDir(Direction::NORD_EST); break;
                case 2: t.setDir(Direction::NORD); break;
                default: break;
            }
        } else if (y == tailleGrille-1) {
            // coin bas-droit
            switch(aleat) {
                case 0: t.setDir(Direction::NORD); break;
                case 1: t.setDir(Direction::NORD_OUEST); break;
                case 2: t.setDir(Direction::OUEST); break;
                default: break;
            }
        } else {
            // bord droit
            t.setDir(Direction::NORD);
        }
    } else if (y == 0) {
        // bord haut
        t.setDir(Direction::EST);
    } else if (y == tailleGrille-1) {
        // bord bas
        t.setDir(Direction::OUEST);
    }
}




// void Termite::marcheAleatoire(Grille &g) {
//     int aleat = rand() % 10;
//     if (laVoieEstLibre(g) and aleat == 0)
//         tourneAleat();
//     else if (laVoieEstLibre(g)) 
//         avanceTermite(g);
//     else 
//         tourneAleat();
// }


void Termite::marcheAleatoire(Grille &g) {
    int aleat = rand() % 10;
    Coord c(X, Y);
    if (estBordure(g, c)) {
        changerDirectionBord(*this, g);
        avanceTermite(g);
    } else if (laVoieEstLibre(g) and aleat == 0) {
        tourneAleat();
    } else if (laVoieEstLibre(g)) {
        avanceTermite(g);
    } else {
        tourneAleat();
    }
}


TEST_CASE("Termite::marcheAleat()") {
    // Test des cas de tourner à droite ou à gauche
    SUBCASE("Direction::Nord") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::NORD);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::NORD_EST) {
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 6);
        } else if(t.directionTermite() == Direction::NORD_OUEST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        } else { 
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 5);
        }
    }

    SUBCASE("Direction::Nord_est") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::NORD_EST);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::NORD) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        } else if(t.directionTermite() == Direction::EST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 6);
        } else if (t.directionTermite() == Direction::NORD_EST){ 
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 6);  
        }
    }

    SUBCASE("Direction::EST") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::EST);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::NORD_EST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        } else if(t.directionTermite() == Direction::SUD_EST) {
            CHECK(t.getX() == 6);
            CHECK(t.getY() == 6);
        } else { 
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 6);  
        }
    }

    SUBCASE("Direction::SUD_EST") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::SUD_EST);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::EST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        } else if (t.directionTermite() == Direction::SUD) {
            CHECK(t.getX() == 3);
            CHECK(t.getY() == 5);
        } else { 
            CHECK(t.getX() == 6);
            CHECK(t.getY() == 6);  
        }
    }

    SUBCASE("Direction::SUD") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::SUD);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::SUD_EST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        } else if(t.directionTermite() == Direction::SUD_OUEST) {
            CHECK(t.getX() == 6);
            CHECK(t.getY() == 4);
        } else { 
            CHECK(t.getX() == 6);
            CHECK(t.getY() == 5);  
        }
    }

    SUBCASE("Direction::SUD_OUEST") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::SUD_OUEST);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::SUD) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        }
        else if(t.directionTermite() == Direction::OUEST) {
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 4);
        } else { 
            CHECK(t.getX() == 6);
            CHECK(t.getY() == 4);  
        }
    }

    SUBCASE("Direction::OUEST") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::OUEST);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::NORD_OUEST) {
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 4);
        } else if(t.directionTermite() == Direction::OUEST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 4);
        } else { 
            CHECK(t.getX() == 6);
            CHECK(t.getY() == 4);  
        } 
    }

    SUBCASE("Direction::NORD_OUEST") {
        Grille g;
        Termite t(1, 5, 5);
        t.setDir(Direction::NORD_OUEST);
        t.marcheAleatoire(g);
        if (t.directionTermite() == Direction::NORD_OUEST) {
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 4);
        } else if(t.directionTermite() == Direction::OUEST) {
            CHECK(t.getX() == 5);
            CHECK(t.getY() == 5);
        } else { 
            CHECK(t.getX() == 4);
            CHECK(t.getY() == 5);  
        }
    }
}


void Termite::chargeBrindille(Grille& g) {
    Coord c = devant();
    g.enleveBrindille(c);
    hasBrindille = true;
    tmpSablier = dureeSablier;
}

TEST_CASE("Test de la méthode chargeBrindille") {
    Grille g;
    // On place une brindille sur la case (2,2) et une termite sur la case (2,3)
    g.poseBrindille(Coord(2,2));
    Termite t(1, 2, 3);
    t.setDir(Direction::OUEST);
    g.poseTermite(Coord(2,3), 1);

    // On vérifie que la termite ne porte pas de brindille
    CHECK_FALSE(t.porteBrindille());

    // On appelle la méthode chargeBrindille
    t.chargeBrindille(g);

    // On vérifie que la termite porte maintenant une brindille
    CHECK(t.porteBrindille());

     // On vérifie que la brindille a bien été enlevée de la grille
    CHECK_FALSE(g.contientBrindille(Coord(2,2)));
}


void Termite::dechargeBrindille(Grille& g) {
    Coord positionDevant = devant();
    g.poseBrindille(positionDevant);
    hasBrindille = false;
}

TEST_CASE("Test de la méthode dechargeBrindille") {
    SUBCASE("charge et decharge sur le meme case") {
        Grille g;
        // On place une brindille sur la case (2,2) et une termite sur la case (2,3)
        g.poseBrindille(Coord(2,2));
        Termite t(1, 2, 3);
        t.setDir(Direction::OUEST);
        g.poseTermite(Coord(2,3), 1);
        t.chargeBrindille(g);
        t.dechargeBrindille(g);
        CHECK(g.contientBrindille(Coord(2,2)));
    }
    SUBCASE("charge et decharge sur le meme case") {
        Grille g;
        g.poseBrindille(Coord(2,2));
        Termite t(1, 2, 3);
        t.setDir(Direction::OUEST);
        g.poseTermite(Coord(2,3), 1);
        t.chargeBrindille(g);
        t.avanceTermite(g);
        t.dechargeBrindille(g);
        CHECK(g.contientBrindille(Coord(2,1)));
    }
}



ostream& operator<<(ostream& out, const Grille& g) {
    for (int i = 0; i < tailleGrille; i++) {
        for (int j = 0; j < tailleGrille; j++) {
            Coord c(i, j);
            if (g.contientBrindille(c))
                out << "\033[32;1m" << "*" << "\033[0m";
            else if (g.numéroTermite(c) != -1){
                Termite t(i, c.getLig(), c.getCol());
                // t.setDir();
                out << "\033[31;1m" <<  t.toString() << "\033[0m";
            }
            else
                out << ".";
        }
        out << endl;
    }
    return out;
}


void Termite::rassemblerBrindille(Grille& g){
    if (tmpSablier > 0) { 
        tmpSablier--;
        marcheAleatoire(g);
    }
    else if (not(hasBrindille) and brindilleEnFace(g)){
        chargeBrindille(g);
        marcheAleatoire(g);
    }
    else {
        if (hasBrindille and laVoieEstLibre(g)) {
            dechargeBrindille(g);
            marcheAleatoire(g);
        }
        else {
            marcheAleatoire(g);
        }
    }
}




// Termite Termite::getID (int nbT){
//     if (nbT >= 0 and nbT < T.size())
//         return T[nbT];
// }
//  // throw

// void Termite::ajoutTer(Termite t){
//     T.push_back(t);
// }