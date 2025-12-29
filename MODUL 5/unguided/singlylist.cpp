#include "SinglyList.h"

void createList(List &L) {
    L.first = NULL;
}

Node* alokasi(int x) {
    Node *P = new Node;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasi(Node *P) {
    delete P;
}

void insertFirst(List &L, Node *P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    Node *P = L.first;
    if (P == NULL) {
        cout << "List masih kosong." << endl;
        return;
    }

    cout << "Isi elemen di dalam list: ";
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

Node* findElm(List L, int x) {
    Node *P = L.first;
    while (P != NULL) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int totalInfo(List L) {
    int total = 0;
    Node *P = L.first;

    while (P != NULL) {
        total += P->info;
        P = P->next;
    }

    return total;
}