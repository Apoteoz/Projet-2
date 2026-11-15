#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "menu.h"
#include "../Utils/utils.h"

using namespace std;

//Fonctions

// Fait évoluer le Pokémon si les ressources sont suffisantes.
void evolvePokemon(Pokemon* p,Ressource* mesressources,EspecePokemon bestiaire[150],int index,Historique* l){
    p->evol += 1;
    p->nom = bestiaire[index].evolvesTo;
    mesressources->bonbons -= bestiaire[index].nbBonbonsPourEvoluer;
    cout << bestiaire[index].nom << " a évolué en " << bestiaire[index].evolvesTo << " !\n";
    Evolution* m = initEvolution(p->nom,bestiaire[index].evolvesTo);
    addEvolution(l,m);
}

// Augmente le CP du Pokémon en consommant les ressources.
void powerupPokemon(Pokemon* p,Ressource* mesressources,EspecePokemon bestiaire[150]){
    mesressources->poussieres -= 500;
    mesressources->bonbons -= 10;
    p->CP = (int)(p->CP * 1.25);
    cout << p->nom << " a gagné en puissance ! Nouveau CP : " << p->CP << "\n";
}

// Menu de choix entre évolution et power-up.
void powerupEvolveMenu(Pokedex* monpokedex,Ressource* mesressources,EspecePokemon bestiaire[150],Historique* l){
    int answ = lireEntier("\nEntrez le numéro du pokemon à faire évoluer/power-up (1 à " + to_string(monpokedex->current) + ") : ", 1, monpokedex->current);
    maillon* temp = monpokedex->liste;
    for(int i = 1; i < answ; i++)
    {
        temp = temp->suivant;
    }
    int index = getEspeceIndex(bestiaire, temp->p.nom);
    if(index == -1)
    {
        cout << "Erreur : Espèce de Pokémon non trouvée dans le bestiaire.\n";
        menu(monpokedex,mesressources,bestiaire,l);
        return;
    }
    cout << "Que souhaitez-vous faire pour " << temp->p.nom << "?\n";
    cout << "1 - Évolution en " << bestiaire[index].evolvesTo << " (coût : " << bestiaire[index].nbBonbonsPourEvoluer << " bonbons)\n";
    cout << "2 - Power-up (coût : 500 poussières + 10 bonbons )\n";
    int choice = lireEntier("Veuillez entrer un numéro : ", 1, 2);
    switch(choice)
    {
    case 1:
        if(bestiaire[index].nbBonbonsPourEvoluer == 0)
        {
            cout << temp->p.nom << " ne peut pas évoluer davantage !\n";
            menu(monpokedex,mesressources,bestiaire,l);
            break;
        }
        else if(mesressources->bonbons >= bestiaire[index].nbBonbonsPourEvoluer)
        {
            evolvePokemon(&(temp->p), mesressources, bestiaire, index,l);
        }
        else
        {
            cout << "Pas assez de bonbons pour évoluer " << temp->p.nom << " !\n";
        }
        menu(monpokedex,mesressources,bestiaire,l);
        break;
    case 2:
        if(mesressources->poussieres >= 500 && mesressources->bonbons >= 10)
        {
            powerupPokemon(&(temp->p), mesressources, bestiaire);

        }
        else
        {
            cout << "Pas assez de poussières pour power-up " << temp->p.nom << " !\n";
        }
        menu(monpokedex,mesressources,bestiaire,l);
        break;      
    default:
        cout << "Valeur non valide !\n";
        menu(monpokedex,mesressources,bestiaire,l);
        break;
    }
}

// Libère les structures mémoire du jeu.
void quitter(Pokedex* monpokedex,Ressource* mesressources,Historique* l)
{
    if(monpokedex->liste != NULL)
    {
        maillon* temp = monpokedex->liste;
        while(temp != NULL)
        {
            maillon* toFree = temp;
            temp = temp->suivant;
            free(toFree);
        }
    }
    free(monpokedex);
    free(mesressources);
    clearHistorique(l);
}

// Affiche le menu principal et redirige vers les fonctionnalités.
void menu(Pokedex* monpokedex,Ressource* mesressources,EspecePokemon bestiaire[150],Historique* l)
{
    cout << "\n";
    cout << "\033[31m1. Index des pokemons\033[0m\n";
    cout << "\033[32m2. Mon Pokedex\033[0m\n";
    cout << "\033[33m3. Attraper un pokemon\033[0m\n";
    cout << "\033[34m4. Power-up et évolution\033[0m\n";
    cout << "\033[35m5. Combat\033[0m\n";
    cout << "\033[36m6. Historique\033[0m\n";
    cout << "\033[30m7. Quitter\033[0m\n";
    int answ = lireEntier("\033[37mVeuillez entrer un numéro : \033[0m", 1, 7);
    switch(answ)
    {
        case 1:
            cout << "Index des pokemons\n";
            displayBestiaire(bestiaire);
            menu(monpokedex,mesressources,bestiaire,l);
            break;
        case 2:
            cout << "Mon Pokedex\n";
            displayPokedex(monpokedex,mesressources);
            menu(monpokedex,mesressources,bestiaire,l);
            break;
        case 3:                     
            cout << "Attraper un pokemon\n";
            genererPokemon(monpokedex, bestiaire ,mesressources,l);
            break;
        case 4:
            cout << "Power-up et évolution\n";
            displayPokedex(monpokedex,mesressources);
            powerupEvolveMenu(monpokedex,mesressources,bestiaire,l);
            break;
        case 5:
            cout << "Combat\n";
            displayPokedex(monpokedex,mesressources);
            combat(monpokedex,mesressources,bestiaire,l);
            menu(monpokedex,mesressources,bestiaire,l);
            break;
        case 6:
            cout << "Historique\n";
            historique(l);
            menu(monpokedex,mesressources,bestiaire,l);
            break;
        case 7:
            cout << "Quitter\n";
            quitter(monpokedex,mesressources,l);
            exit(0);
            break;
        default:
            cout << "Valeur non valide !\n";
            menu(monpokedex,mesressources,bestiaire,l);
            break;
    }
    cout << "\n";
}