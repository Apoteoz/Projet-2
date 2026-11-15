#ifndef POKEDEX_H
#define POKEDEX_H

#include "../Bestiaire/bestiaire.h"
#include "../Utils/utils.h"
#include "../Journal/journal.h"

// Variables globales
extern const char* typesLabel[18];

/*
-------------------------------------------------------------------------
STRUCTURE RELATIVES AU POKEDEX
-------------------------------------------------------------------------
*/

typedef struct Ressource
{
    int poussieres; //Nb de poussières que possède l'utilisateur
    int bonbons;    //Nb de bonbons que possède l'utilisateur
} Ressource;

// Modification apportée : Utilisation de maillons chainés pour le tableau dynamique

typedef struct maillon{
    Pokemon p;
    struct maillon* suivant;
} maillon;

typedef struct Pokedex
{
    maillon* liste;     //Tableau de pokemon
    int current;        //Nb actuel de pokemons dans le pokedex
} Pokedex;

/*
-------------------------------------------------------------------------
FONCTIONS RELATIVES AU POKEDEX
-------------------------------------------------------------------------
*/

//Initialise un pokedex 
Pokedex* initPokedex();

//Initialise mes ressources
Ressource* initRessource();

//Fonction auxiliaire pour insérer un pokemon dans le pokedex de manière triée
void aux_insertPokemon(maillon* prev,maillon* current, Pokemon p);

//Insère un pokemon dans mon pokedex et met à jour les ressources
void insertPokemon(Pokedex* monPokedex,Ressource* mesressources, Pokemon p);

//Affiche le contenu du pokedex
void displayPokedex(Pokedex* pokedex,Ressource* mesressources);

//Affiche le menu principal
extern void menu(Pokedex* monpokedex,Ressource* mesressources,EspecePokemon bestiaire[150],Historique* l);

//Génère un Pokémon sauvage
void genererPokemon(Pokedex* monpokedex, EspecePokemon bestiaire[150],Ressource* mesressources,Historique* l);

//Cherche à l'indice i dans le pokédex
Pokemon displayAt(Pokedex* monpokedex,int i);

#endif // POKEDEX_H