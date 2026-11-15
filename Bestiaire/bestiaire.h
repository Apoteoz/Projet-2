#ifndef BESTIAIRE_H
#define BESTIAIRE_H

// le type enuméré décrivant le type de Pokemon parmi les 18 existants

typedef enum { Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, 
    Fire, Grass, Water, Electric, Psychic, Ice, Dragon, Dark, Fairy } PokemonType;


// Structure représentant un pokémon 

typedef struct Pokemon {
    const char* nom;    
    int XP;             //Niveau d'expérience
    int evol;           //Numéro d'évolution
    int PV;             //Points de vie
    int CP;             //Points de combat
    PokemonType type;   //Espèce de Pokemon
} Pokemon;


//Structure pour les différentes espèces de pokémon

typedef struct EspecePokemon {
    const char* nom;
    PokemonType type;
    int nbBonbonsPourEvoluer;
    const char* evolvesTo;
    bool estEvolue;
} EspecePokemon;


/*
-------------------------------------------------------------------------
FONCTIONS DU BESTIAIRE
-------------------------------------------------------------------------
*/

//Initialise le Bestiaire
void initBestiaire(EspecePokemon bestiaire[]);

//Trie le Bestiaire
void trie(EspecePokemon bestiaire[]);

//Donne l'indice d'une espèce de pokemon à partir de son nom par dichotomie
//Suppose que bestiaire est trié par ordre alphabétique
int getEspeceIndex(EspecePokemon bestiaire[], const char* nom);

//Affiche les caractéristiques d'un Pokémon
void display(const Pokemon p);

//Affiche le Bestiaire
void displayBestiaire(EspecePokemon bestiaire[]);

#endif // BESTIAIRE_H