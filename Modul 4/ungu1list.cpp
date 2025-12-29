#include "ungu1singlist.h"
#include <iostream>

using namespace std;

void createList(List *L) {
    (*L).First = NULL;
}

address alokasi(infotype X) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = X;
        P->next = NULL;
    }
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List *L, address P) {
    if (P != NULL) {
        P->next = (*L).First;
        (*L).First = P;
    }
}

void printInfo(List L) {
    address P = L.First;
    cout << "Isi List: ";
    if (P == NULL) {
        cout << "List Kosong." << endl;
        return;
    }

    while (P != NULL) {
        cout << P->info;
        if (P->next != NULL) {
            cout << " -> ";
        }
        P = P->next;
    }
    cout << endl;
}