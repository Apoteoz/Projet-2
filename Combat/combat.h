#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include "../Bestiaire/bestiaire.h"
#include "../Pokedex/pokedex.h"
#include "../Journal/journal.h"
using namespace std;


typedef struct CombatEspece{
    const char* nature;
    std::string strongAgainst[5];
    std::string weakAgainst[5];
    struct CombatEspece* next;
} CombatEspece;

typedef struct CombatHash{
    int size;
    CombatEspece table[31]; 
} CombatHash;

// fonction donnant le hash d'un mot
int gethash(CombatHash* htable,const char* str);
// fonction permettant de trouver le pointeur vers un CombatEspece dont la nature vaut key.
CombatEspece* get(CombatHash* hashtable, const char* key);
// fonction permettant de savoir si un CombatEspece pointé par le pointeur c appartient à la table de hachage.
bool contains(CombatHash* hashtable, CombatEspece* c);
// fonction permettant d’insérer un nouvel élément à la table de hachage.
void insert(CombatEspece* c, CombatHash* hashtable);
// fonction auxiliaire de la fonction compare qui retourne true si c1 est plus fort que c2, false sinon
bool isstronger(CombatHash* hashtable,CombatEspece* c1, CombatEspece* c2);
// fonction qui compare les forces de deux CombatEspece et met à jour l'indice de chaque pokemon en fonction de sa force
void compare(EspecePokemon bestiaire[150],CombatHash* hashtable,int indice[2],CombatEspece* c1,CombatEspece* c2);
// fonction qui simule un combat entre deux pokemons en fonction de leur indice de force    
void attaque(Pokemon pok[2],int indice[2]);
// fonction qui initialise la table de hachage des forces de combat
CombatHash* initCombatHash();
// fonction qui simule un combat entre deux pokemons choisis par l'utilisateur
void combat(Pokedex* monpokedex,Ressource* mesressources,EspecePokemon bestiaire[150],Historique* l);

#endif // COMBAT_H