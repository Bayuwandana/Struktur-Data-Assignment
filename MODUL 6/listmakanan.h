#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
#include <string>
using namespace std;

// Struktur data isi makanan
struct makanan {
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;
typedef struct node *address;

// Node Doubly Linked List (punya next dan prev)
struct node {
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist {
    address first;
    address last;
};

// Fungsi Dasar & Manajemen Memori
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

// Fungsi Penambahan Data (Insertion)
void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address nodePrev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

// Fungsi Output
void printList(linkedlist List);

// Fungsi Pembaruan Data (Update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address nodePrev);
void updateBefore(linkedlist List, address nodeNext);

#endif