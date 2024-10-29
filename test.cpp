#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"


/*
#include "coord.hpp"
#include "grille.hpp"


TEST_CASE("PARTIE 1: Q7. to 14. du TP mise en place") {
    SUBCASE("Q9. Coord") {
      CHECK_THROWS_AS(Coord(-1, 0), out_of_range); // Test with invalid row
      CHECK_THROWS_AS(Coord(0, -1), out_of_range); // Test with invalid column
      CHECK_THROWS_AS(Coord c(0, 20), out_of_range); // Test with a border value

      CHECK_NOTHROW(Coord c(0, 0)); // Coord dans l'intervalle
      CHECK_NOTHROW(Coord c(19, 19)); // Coord dans l'intervalle
    }

    SUBCASE("Q10. Getters") {
        Coord c(2, 5);
        CHECK(c.getLig() == 2); // c(lig, col) 
        CHECK(c.getCol() == 5);
    }
  
    //SUBCASE("Q11. Opérateur <<") {
      //  Coord c(3, 7);
        //ostringstream out;
        //out << c; 
        //string expected = "(3, 7)";
    }


     SUBCASE("Q13. Opérateur ==") {
        Coord c(2, 5);
        Coord cbis(2, 5);
        Coord cwrong(1, 6);
        CHECK(c == cbis);
        CHECK_FALSE(cbis == cwrong);
    }
}

TEST_CASE("PARTIE 2: Q15. to 21. du TP mise en place") {
    SUBCASE("Q.18 (a) gauche-->droite = pt initiale") {
        Direction dir = Direction::SUD;
        //cout << "Direction initiale : " << dir << endl;
        dir = aGauche(dir);
        //cout << "Direction après une rotation à gauche : " << dir << endl;
        dir = aDroite(dir);
        //cout << "Direction après une rotation à droite : " << dir << endl;
        CHECK(dir == Direction::SUD);
    }

    SUBCASE("Q.18 (b) droite-->gauche = pt initiale") {
        Direction dir = Direction::OUEST;
        //cout << "Direction initiale : " << dir << endl;
        dir = aDroite(dir);
        //cout << "Direction après une rotation à droite : " << dir << endl;
        dir = aGauche(dir);
        //cout << "Direction après une rotation à gauche : " << dir << endl;
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

    SUBCASE("Q20 devantCoord") {
        // Test with valid inputs
        CHECK(devantCoord(Coord(1, 1), Direction::NORD) == Coord(0, 1));
        CHECK(devantCoord(Coord(1, 1), Direction::EST) == Coord(1, 2));
        CHECK(devantCoord(Coord(1, 1), Direction::SUD) == Coord(2, 1));
        CHECK(devantCoord(Coord(1, 1), Direction::OUEST) == Coord(1, 0));

        // Test with invalid inputs
        CHECK_THROWS_AS(devantCoord(Coord(0, 0), Direction::NORD_OUEST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(0, 0), Direction::NORD), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(0, 0), Direction::OUEST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 20), Direction::NORD_EST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(19, 20), Direction::EST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 20), Direction::SUD_EST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 0), Direction::SUD_OUEST), out_of_range);
        CHECK_THROWS_AS(devantCoord(Coord(20, 0), Direction::SUD), out_of_range);
    }

     SUBCASE("Q21 1*devantCoord + 4*aDroite") {
        Coord currentCoord(10, 10);
        Direction currentDir = Direction::NORD;
        currentCoord = devantCoord(currentCoord, currentDir);
        for(int i = 0; i < 4; i++) {
            currentDir = aDroite(currentDir);
        }
        currentCoord = devantCoord(currentCoord, currentDir);
        CHECK(currentCoord == Coord(10, 10));
     }
}


TEST_CASE("PARTIE 3: Q22. to 28. du TP mise en place") {
    
    Grille g;
    
    SUBCASE("estVide(c)") {
        Coord c1(5,5);
        CHECK(g.estVide(c1));
    }
    
   
    SUBCASE("poseBrindille") {
        Coord c1(5,5);
        g.poseBrindille(c1);
        CHECK_FALSE(g.estVide(c1));
    }
    
    SUBCASE("enleveBrindille") {
        Coord c1(5,5);
        g.poseBrindille(c1);
        g.enleveBrindille(c1);
        CHECK(g.estVide(c1));
        
        Coord c2(1,5);
        CHECK_THROWS_AS(g.enleveBrindille(c2), out_of_range);
    }
    
    SUBCASE("contientBrindille") {
        Coord c1(5,5);
        CHECK_FALSE(g.contientBrindille(c1));
        g.poseBrindille(c1);
        CHECK(g.contientBrindille(c1));
    }
    
    SUBCASE("poseTermite") {
        Coord c1(5,5);
        g.poseTermite(c1, 1);
        CHECK(g.numéroTermite(c1) == 1);
    }
    
    SUBCASE("enleveTermite") {
        Coord c1(5,5);
        g.poseTermite(c1, 1);
        g.enleveTermite(c1);
        CHECK(g.numéroTermite(c1) == -1);
        
    }
    
}
*/

