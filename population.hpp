#ifndef population_HPP
#define  population_HPP

#include <vector>
#include <iostream>
using namespace std;

#include "coord.hpp" 
#include "grille.hpp"
#include "termite.hpp"

class Population
{
private:
    vector<Termite> T;

public:
    Population() { T = vector<Termite>(0);}
    Termite getID (int nbT);

    void ajoutTer(Termite t);
    
    void deplacerAleatoire(Grille& g);

    void deplacerAleatoireBIS(Grille& g, int nbPasse);
    
};


#endif