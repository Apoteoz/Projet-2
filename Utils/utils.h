#ifndef UTILS_H
#define UTILS_H

#include <string>

/*
-------------------------------------------------------------------------
FONCTIONS AUXILIAIRES / UTILITAIRE
-------------------------------------------------------------------------
*/

//Retourne une valeur aléatoire comprise dans l'intervalle [0,max]
long random_at_most(long max);

// Lit un entier entre min et max inclus, en vérifiant l'entrée utilisateur.
int lireEntier(const std::string& invite, int min, int max);

#endif // UTILS_H