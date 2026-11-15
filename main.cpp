#include <stdio.h>
#include <stdlib.h>
#include "Menu/menu.h"

// Point d'entrée du jeu : initialise les structures puis lance le menu.
int main()
{
    EspecePokemon bestiaire[150];
    initBestiaire(bestiaire);
    trie(bestiaire);
    Ressource* mesressources = initRessource();
    Pokedex* pokedex = initPokedex();
    Historique* l = initHistorique();
    Pokemon a;
    a.nom = "Seadra";
    a.XP = 1;
    a.CP = 4;
    a.evol = 1;
    a.PV = 23;
    Pokemon b;
    b.nom = "Arbok";
    b.XP = 0;
    b.CP = 123;
    b.evol = 2;
    b.PV = 134;
    Pokemon c;
    c.nom = "Zubat";
    c.XP = 40;
    c.CP = 300;
    c.evol = 1;
    c.PV = 223;
    Pokemon d;
    d.nom = "Paras";
    d.XP = 0;
    d.CP = 23;
    d.evol = 1;
    d.PV = 90;
    Pokemon e;
    e.nom = "Arcanine";
    e.XP = 0;
    e.CP = 23;
    e.evol = 2;
    e.PV = 290;
    insertPokemon(pokedex,mesressources,a);
    insertPokemon(pokedex,mesressources,b);
    insertPokemon(pokedex,mesressources,c);
    insertPokemon(pokedex,mesressources,d);
    insertPokemon(pokedex,mesressources,e);

    menu(pokedex,mesressources,bestiaire,l);
}