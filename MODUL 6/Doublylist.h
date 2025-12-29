#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
#define Nil NULL

#include<iostream>
using namespace std;

struct kendaraan{
    string nopol;
    string warna; 
    int thnBuat; 
};

typedef kendaraan infotype;

typedef struct node *address;

struct node{
    infotype info;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nopol, string warna, int thnBuat);
void dealokasi(address &P);
void printInfo(linkedlist List);
void insertLast(linkedlist &List, address P);

void findElm(linkedlist List, string nopol);

void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);

#endif
