#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "utils.h"

// Génère un entier aléatoire dans [0, max].
// For random(), RAND_MAX
// Assumes 0 <= max <= RAND_MAX
// Returns in the closed interval [0, max]
long random_at_most(long max) {
unsigned long
// max <= RAND_MAX < ULONG_MAX, so this is okay.
num_bins = (unsigned long) max + 1,
num_rand = (unsigned long) RAND_MAX + 1,
bin_size = num_rand / num_bins,
defect
= num_rand % num_bins;
long x;
do {
x = random();
}
// This is carefully written not to overflow
while (num_rand - defect <= (unsigned long)x);
// Truncated division is intentional
return x/bin_size;
}

// Lit une valeur entière en vérifiant les bornes demandées.
int lireEntier(const std::string& invite, int min, int max) {
    std::string ligne;
    int valeur;
    while (true) {
        std::cout << invite << std::flush;
        if (!std::getline(std::cin, ligne)) {
            std::cin.clear();
            std::cout << "Entrée interrompue, veuillez réessayer.\n";
            continue;
        }
        std::stringstream ss(ligne);
        if (!(ss >> valeur) || !(ss >> std::ws).eof()) {
            std::cout << "Entrée invalide : veuillez saisir un entier.\n";
            continue;
        }
        if (valeur < min || valeur > max) {
            std::cout << "Valeur hors bornes : veuillez saisir un entier entre " << min << " et " << max << ".\n";
            continue;
        }
        return valeur;
    }
}
