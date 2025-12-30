#include <iostream>
#include "multilist.h"
using namespace std;

int main(){
    listinduk L;
    CreateList(L);

    address p1 = alokasi(1);
    address p2 = alokasi(2);
    address p3 = alokasi(3);

    insertFirst(L, p1);
    insertLast(L, p2);
    insertLast(L, p3);

    insertLastAnak(p1->lanak, alokasiAnak(10));
    insertLastAnak(p1->lanak, alokasiAnak(20));
    insertLastAnak(p2->lanak, alokasiAnak(30));
    insertLastAnak(p3->lanak, alokasiAnak(40));
    insertLastAnak(p3->lanak, alokasiAnak(50));

    cout << "=== DATA MULTI LINKED LIST ===" << endl;
    printInfo(L);

    return 0;
}