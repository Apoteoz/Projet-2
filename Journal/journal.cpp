#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "journal.h"

using namespace std;

/// Implémentation 

Evolution* initEvolution(const char* name,const char* nameEvol,Evolution* next)
{
    Evolution* p = new Evolution;
    p->name = name;
    p->nameEvol = nameEvol; 
    p->next = next;
    return p;
}

Historique* initHistorique(Evolution* start)
{
    Historique* l = new Historique;
    l->start = start;
    l->size = 0;
    return l;
}

void addEvolution(Historique* l, Evolution* p)
{
    p->next = l->start;
    l->start = p;
    l->size +=1;
}

void historique(Historique* l)
{
    Evolution* current = new Evolution;
    current = l->start;
    cout << "Nombre d'\u00e9volution : " << l->size << "\n";
    while(current!=nullptr)
    {
        cout << current->name << " a \u00e9volu\u00e9 en " << current->nameEvol << "\n";
        current = current->next;
    }
    delete current;
}

void clearHistorique(Historique* l)
{
    Evolution* current = new Evolution;
    while(l->start!=nullptr)
    {
        current = l->start;
        l->start = l->start->next;
        delete current;
    }
    delete l;
}