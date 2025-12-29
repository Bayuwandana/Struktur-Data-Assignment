#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

struct List {
    Node *first;
};

void createList(List &L);
Node* alokasi(int x);
void dealokasi(Node *P);
void insertFirst(List &L, Node *P);
void printInfo(List L);

Node* findElm(List L, int x);
int totalInfo(List L);

#endif
