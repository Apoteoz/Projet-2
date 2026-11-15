#ifndef JOURNAL_H
#define JOURNAL_H

typedef struct Evolution{
  const char*  name;
  const char* nameEvol;
  struct Evolution* next;
} Evolution;

typedef struct Historique{
    Evolution* start;
    int size;
} Historique;

// Initialise un maillon
Evolution* initEvolution(const char* name,const char* nameEvol,Evolution* next=nullptr);
// Initialise l'historique
Historique* initHistorique(Evolution* start=nullptr);
// Ajouter une évolution à la tête de la liste chaînée
void addEvolution(Historique* l,Evolution* p);
//Affiche l'historique
void historique(Historique* l);
// Désallocation mémoire
void clearHistorique(Historique* l);

#endif // JOURNAL_H
