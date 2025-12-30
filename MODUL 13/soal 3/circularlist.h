#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
using namespace std;

/* ===== TYPE ===== */
typedef struct mahasiswa {
    string nama;
    string nim;
    char jenis_kelamin;
    float ipk;
} infotype;

typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

/* ===== FUNCTION & PROCEDURE ===== */
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);

void insertFirst(List &L, address P);
void insertAfter(List &L, address Prec, address P);
void insertLast(List &L, address P);

void deleteFirst(List &L, address &P);
void deleteAfter(List &L, address Prec, address &P);
void deleteLast(List &L, address &P);

address findElm(List L, infotype x);
void printInfo(List L);

/* fungsi tambahan dari soal */
address createData(string nama, string nim, char jenis_kelamin, float ipk);

#endif

