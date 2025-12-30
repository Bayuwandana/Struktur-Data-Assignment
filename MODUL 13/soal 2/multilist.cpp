#include "multilist.h"
#include <iostream>
using namespace std;

/* ===== CEK KOSONG ===== */
boolean ListEmpty(listinduk L){
    return (L.first == Nil);
}

boolean ListEmptyAnak(listanak L){
    return (L.first == Nil);
}

/* ===== CREATE ===== */
void CreateList(listinduk &L){
    L.first = Nil;
    L.last = Nil;
}

void CreateListAnak(listanak &L){
    L.first = Nil;
    L.last = Nil;
}

/* ===== ALOKASI ===== */
address alokasi(infotypeinduk x){
    address P = new elemen_list_induk;
    P->info = x;
    CreateListAnak(P->lanak);
    P->next = Nil;
    P->prev = Nil;
    return P;
}

address_anak alokasiAnak(infotypeanak x){
    address_anak P = new elemen_list_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

/* ===== DEALOKASI ===== */
void dealokasi(address P){
    delete P;
}

void dealokasiAnak(address_anak P){
    delete P;
}

/* ===== INSERT INDUK ===== */
void insertFirst(listinduk &L, address P){
    if(ListEmpty(L)){
        L.first = L.last = P;
    }else{
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(listinduk &L, address P){
    if(ListEmpty(L)){
        insertFirst(L,P);
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfter(listinduk &L, address P, address Prec){
    P->next = Prec->next;
    P->prev = Prec;
    if(Prec->next != Nil){
        Prec->next->prev = P;
    }else{
        L.last = P;
    }
    Prec->next = P;
}

/* ===== INSERT ANAK ===== */
void insertLastAnak(listanak &L, address_anak P){
    if(ListEmptyAnak(L)){
        L.first = L.last = P;
    }else{
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

/* ===== DELETE INDUK ===== */
void delFirst(listinduk &L, address &P){
    P = L.first;
    L.first = P->next;
    if(L.first != Nil){
        L.first->prev = Nil;
    }else{
        L.last = Nil;
    }
    P->next = Nil;
}

void delLast(listinduk &L, address &P){
    P = L.last;
    L.last = P->prev;
    if(L.last != Nil){
        L.last->next = Nil;
    }else{
        L.first = Nil;
    }
    P->prev = Nil;
}

/* ===== PRINT ===== */
void printInfo(listinduk L){
    address P = L.first;
    while(P != Nil){
        cout << "Induk : " << P->info << " -> Anak : ";
        address_anak A = P->lanak.first;
        while(A != Nil){
            cout << A->info << " ";
            A = A->next;
        }
        cout << endl;
        P = P->next;
    }
}

