#ifndef MENU_H
#define MENU_H

#include "../Pokedex/pokedex.h"
#include "../Combat/combat.h"
/*
-------------------------------------------------------------------------
STRUCTURES RELATIVES AUX POKEMONS
-------------------------------------------------------------------------
*/ 

// Variables globales
extern const char* typesLabel[18];


/*
-------------------------------------------------------------------------
 FONCTIONS DU MENU
-------------------------------------------------------------------------
*/

// Utilise les bonbons afin de transformer un pokemon dans une version plus évoluée
void evolvePokemon(Pokemon* p,Ressource* mesressources,EspecePokemon bestiaire[150],int index,Historique* l);

//Utilise les ressources afin de faire augmenter les capacités de combat d'un pokemon
void powerupPokemon(Pokemon* p,Ressource* mesressources,EspecePokemon bestiaire[150]);

//Fonctionnalité du menu évolution/power-up
void powerupEvolveMenu(Pokedex* monpokedex,Ressource* mesressources,EspecePokemon bestiaire[150],Historique* l);

//Libère la mémoire allouée au pokedex
void quitter(Pokedex* monpokedex,Ressource* mesressources,Historique* l);

//Affiche le menu principal 
void menu(Pokedex* monpokedex,Ressource* mesressources,EspecePokemon bestiaire[150],Historique* l);

#endif // MENU_H
