#include <iostream>
#include "SinglyList.h"
using namespace std;

int main() {
    List L;
    createList(L);

    Node *P1, *P2, *P3, *P4, *P5;

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    cout << "Isi list: ";
    printInfo(L);

    Node *found = findElm(L, 8);
    if (found != NULL) {
        cout << "Elemen dengan nilai 8 ditemukan pada alamat: " << found << endl;
    } else {
        cout << "Elemen dengan nilai 8 tidak ditemukan." << endl;
    }

    cout << "Total seluruh nilai info pada list: " << totalInfo(L) << endl;

    return 0;
}