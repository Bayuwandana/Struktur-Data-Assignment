#include "Doublylist.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nopol, string warna, int thnBuat) {
    address nodeBaru = new node;
    nodeBaru->info.nopol = nopol;
    nodeBaru->info.warna = warna;
    nodeBaru->info.thnBuat = thnBuat;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &P) {
    P->next = Nil;
    P->prev = Nil;
    delete P;
    P = Nil;
}

void printInfo(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address bantu = List.last;
        cout << "DATA LIST 1" << endl;
        cout << endl;
        while (bantu != Nil) {
            cout << "no polisi : " << bantu->info.nopol << endl;
            cout << "warna     : " << bantu->info.warna << endl;
            cout << "tahun     : " << bantu->info.thnBuat << endl;
            bantu = bantu->prev;
        }
    }
}

void insertLast(linkedlist &List, address P) {
    bool duplikat = false;
    address bantu = List.first;
    while (bantu != Nil) {
        if (bantu->info.nopol == P->info.nopol) {
            duplikat = true;
            break;
        }
        bantu = bantu->next;
    }

    cout << "masukkan nomor polisi: " << P->info.nopol << endl;
    cout << "masukkan warna kendaraan: " << P->info.warna << endl;
    cout << "masukkan tahun kendaraan: " << P->info.thnBuat << endl;

    if (duplikat) {
        cout << "nomor polisi sudah terdaftar" << endl;
        cout << endl;
        dealokasi(P);
        return;
    }

    cout << endl;

    if (isEmpty(List)) {
        List.first = P;
        List.last = P;
    } else {
        P->prev = List.last;
        List.last->next = P;
        List.last = P;
    }
}

void findElm(linkedlist List, string nopol){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address P = List.first;
    while(P != Nil){
        if(P->info.nopol == nopol){
            cout << "Masukkan nomor polisi yang dicari : " << P->info.nopol << endl;
            cout << "Nomor Polisi : " << P->info.nopol << endl;
            cout << "Warna        : " << P->info.warna << endl;
            cout << "Tahun        : " << P->info.thnBuat << endl;
            return;
        }
        P = P->next;
    }
}

void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->prev = Nil;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    dealokasi(pDel);
}
