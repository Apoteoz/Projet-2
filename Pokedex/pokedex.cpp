#include "pokedex.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <string>
#include "../Utils/utils.h"

using namespace std;

// Initialise un nouveau pokédex vide.
Pokedex* initPokedex(){
    Pokedex* monpokedex = (Pokedex*) malloc(sizeof(Pokedex));
    monpokedex->current = 0;
    monpokedex->liste = NULL;
    return monpokedex;
}

// Démarre le stock de ressources du joueur.
Ressource* initRessource(){
    Ressource* res = (Ressource*) malloc(sizeof(Ressource));
    res->poussieres = 10000;
    res->bonbons = 1000;
    return res;
}

// Insère un Pokémon dans la liste triée par ordre alphabétique.
void aux_insertPokemon(maillon* prev,maillon* current, Pokemon p){
    if(current == NULL || strcmp(current->p.nom, p.nom) > 0)
    {
        maillon* nouveau = (maillon*) malloc(sizeof(maillon));
        nouveau->p = p;
        nouveau->suivant = current;
        if(prev != NULL)
        {
            prev->suivant = nouveau;
        }
        return;
    }
    aux_insertPokemon(current, current->suivant, p);
}

Pokemon displayAt(Pokedex* monpokedex,int i){
    int cpt = 0;
    maillon* temp = monpokedex->liste;
    while(cpt<i)
    {
        temp = temp->suivant;
        cpt++;
    }
    cout << "\nTu as choisis : " << temp->p.nom;
    return temp->p;
}

void insertPokemon(Pokedex* monPokedex,Ressource* mesressources, Pokemon p){
    if(monPokedex->liste == NULL || strcmp(monPokedex->liste->p.nom, p.nom) > 0){
        maillon* nouveau = (maillon*) malloc(sizeof(maillon));
        nouveau->p = p;
        nouveau->suivant = monPokedex->liste;
        monPokedex->liste = nouveau;
    }
    else
    {
        aux_insertPokemon(monPokedex->liste, monPokedex->liste->suivant, p);
    }        
    monPokedex->current++;
    mesressources->poussieres += 100;
    mesressources->bonbons += 3;
}

// Affiche les Pokémon capturés ainsi que les ressources disponibles.
void displayPokedex(Pokedex* monpokedex,Ressource* mesressources)
{
    cout << "\nNb de Pokemon capturés : " << monpokedex->current << "\n";
    cout << "Contenu du Pokedex : \n";
    maillon* temp = monpokedex->liste;
    int i = 0;
    while(temp != NULL)
    {   
        cout << "\n  Pokemon " << i+1;
        i++;
        display(temp->p);
        temp = temp->suivant;
    }
    cout << "\n  Ressources \n";
    cout << "Poussierəs : " << mesressources->poussieres << "\n";
    cout << "Bonbons : " << mesressources->bonbons << "\n";
}

// Génère un Pokémon sauvage et propose de le capturer.
void genererPokemon(Pokedex* monpokedex, EspecePokemon bestiaire[150],Ressource* mesressources,Historique* l)
{
    int speciesIndex = random_at_most(149);
    while(bestiaire[speciesIndex].estEvolue)
    {
        speciesIndex = random_at_most(149);
    }
    Pokemon psauvage = { .nom = bestiaire[speciesIndex].nom, .XP = 0, .CP = 200 + (int) random_at_most(800) };
    psauvage.PV = 30 + (int) random_at_most(470);
    cout << "\nOh ! Un pokemon sauvage ";
    display(psauvage);
    cout << "\nTu souhaites : \n";
    cout << "1 - Capturer ce pokemon\n";
    cout << "2 - Essayer d'en capturer un autre\n";
    cout << "3 - Revenir au menu principal\n";
    int answ = lireEntier("Veuillez entrer un numéro : ", 1, 3);
    if(answ == 2)
    {
        genererPokemon(monpokedex, bestiaire,mesressources,l);
        return;
    }
    if(answ == 3)
    {
        menu(monpokedex,mesressources,bestiaire,l);
        return;
    }
    if(answ == 2)
    {
        genererPokemon(monpokedex, bestiaire,mesressources,l);
        return;
    }
    if(answ == 3)
    {
        menu(monpokedex,mesressources,bestiaire,l);
        return;
    }

    int captureChance = random_at_most(100);
    if (captureChance > 60)
    {
        cout << "Félicitation : Pokémon capturé avec succès !\n";
        insertPokemon(monpokedex, mesressources,psauvage);
    }
    else
    {
        cout << "Capture échoué !\n";
    }
    menu(monpokedex,mesressources, bestiaire,l);
}