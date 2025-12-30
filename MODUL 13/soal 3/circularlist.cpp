#include "circularlist.h"

/* ===== CREATE LIST ===== */
void createList(List &L) {
    L.First = NULL;
}

/* ===== ALOKASI ===== */
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    return P;
}

/* ===== DEALOKASI ===== */
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

/* ===== INSERT FIRST ===== */
void insertFirst(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        P->next = P;
    } else {
        address Q = L.First;
        while (Q->next != L.First) {
            Q = Q->next;
        }
        P->next = L.First;
        Q->next = P;
        L.First = P;
    }
}

/* ===== INSERT AFTER ===== */
void insertAfter(List &L, address Prec, address P) {
    P->next = Prec->next;
    Prec->next = P;
}

/* ===== INSERT LAST ===== */
void insertLast(List &L, address P) {
    if (L.First == NULL) {
        insertFirst(L, P);
    } else {
        address Q = L.First;
        while (Q->next != L.First) {
            Q = Q->next;
        }
        Q->next = P;
        P->next = L.First;
    }
}

/* ===== DELETE FIRST ===== */
void deleteFirst(List &L, address &P) {
    if (L.First != NULL) {
        address Q = L.First;
        if (Q->next == Q) {
            P = Q;
            L.First = NULL;
        } else {
            while (Q->next != L.First) {
                Q = Q->next;
            }
            P = L.First;
            L.First = P->next;
            Q->next = L.First;
        }
        P->next = NULL;
    }
}

/* ===== DELETE AFTER ===== */
void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}

/* ===== DELETE LAST ===== */
void deleteLast(List &L, address &P) {
    if (L.First != NULL) {
        address Q = L.First;
        address Prec = NULL;
        while (Q->next != L.First) {
            Prec = Q;
            Q = Q->next;
        }
        P = Q;
        Prec->next = L.First;
        P->next = NULL;
    }
}

/* ===== FIND ELEMENT (berdasarkan NIM) ===== */
address findElm(List L, infotype x) {
    address P = L.First;
    if (P != NULL) {
        do {
            if (P->info.nim == x.nim) {
                return P;
            }
            P = P->next;
        } while (P != L.First);
    }
    return NULL;
}

/* ===== PRINT INFO ===== */
void printInfo(List L) {
    address P = L.First;
    if (P != NULL) {
        do {
            cout << "Nama : " << P->info.nama << endl;
            cout << "NIM  : " << P->info.nim << endl;
            cout << "L/P  : " << P->info.jenis_kelamin << endl;
            cout << "IPK  : " << P->info.ipk << endl;
            cout << endl;
            P = P->next;
        } while (P != L.First);
    }
}

/* ===== CREATE DATA ===== */
address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    return alokasi(x);
}

