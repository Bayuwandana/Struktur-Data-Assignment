# <h1 align="center">Laporan ASESMEN 1 PRAKTIKUM STRUKTUR DATA </h1>
<p align="center">Bayu Wandana - 103112430159</p>


### 1. ...

```C++
#include <iostream>
using namespace std;
struct Barang {
    string nama, sku;
    int jumlah;
    int hargaSatuan;
    int diskonPersen;
};
struct Node {
    Barang data;
    Node *next;
};
struct List {
    Node *first;
};
void createList(List &L) {
    L.first = nullptr;
}
Node* createNode(Barang x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}
void insertLast(List &L, Barang x) {
    Node* newNode = createNode(x);
    if (L.first == nullptr) {
        L.first = newNode;
    } else {
        Node* temp = L.first;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void deleteFirst(List &L) {
    if (L.first != nullptr) {
        Node* temp = L.first;
        L.first = L.first->next;
        delete temp;
    }
}
void printList(List L) {
    Node* temp = L.first;
    while (temp != nullptr) {
        Barang b = temp->data;
        int hargaAkhir = b.hargaSatuan - (b.hargaSatuan * b.diskonPersen / 100);
        cout << "Nama: " << b.nama << ", SKU: " << b.sku << ", Jumlah: " << b.jumlah
             << ", Harga Satuan: " << b.hargaSatuan << ", Diskon: " << b.diskonPersen
             << "%, Harga Akhir: " << hargaAkhir << endl;
        temp = temp->next;
    }
}
void updateAtPosition(List &L, int pos, Barang x) {
    Node* temp = L.first;
    int index = 1;
    while (temp != nullptr && index < pos) {
        temp = temp->next;
        index++;
    }
    if (temp != nullptr) {
        temp->data = x;
    }
}
void searchingHargaAkhir(List L, int min, int max) {
    Node* temp = L.first;
    while (temp != nullptr) {
        Barang b = temp->data;
        int hargaAkhir = b.hargaSatuan - (b.hargaSatuan * b.diskonPersen / 100);
        if (hargaAkhir >= min && hargaAkhir <= max) {
            cout << "Nama: " << b.nama << ", SKU: " << b.sku << ", Harga Akhir: " << hargaAkhir << endl;
        }
        temp = temp->next;
    }
}
void MaxHargaAkhir(List L) {
    Node* temp = L.first;
    Barang* maxBarang = nullptr;
    int maxHargaAkhir = 0;
    while (temp != nullptr) {
        Barang b = temp->data;
        int hargaAkhir = b.hargaSatuan - (b.hargaSatuan * b.diskonPersen / 100);
        if (hargaAkhir > maxHargaAkhir) {
            maxHargaAkhir = hargaAkhir;
            maxBarang = &temp->data;
        }
        temp = temp->next;
    }
    if (maxBarang != nullptr) {
        cout << "Nama: " << maxBarang->nama << ", SKU: " << maxBarang->sku
             << ", Harga Akhir: " << maxHargaAkhir << endl;
    }
}
int main() {
    List L;
    createList(L);
    Barang b1 = {"Pulpen", "SKUA001", 20, 2500, 0};
    Barang b2 = {"Buku", "SKUB002", 15, 5000, 10};
    Barang b3 = {"Penghapus", "SKUC003", 30, 1500, 0};
    insertLast(L, b1);
    insertLast(L, b2);
    insertLast(L, b3);
    cout << "Daftar Barang:" << endl;
    printList(L);
    Barang bUpdate = {"Stabilo", "SKUA010", 40, 9000, 5};
    updateAtPosition(L, 2, bUpdate);
    cout << "\nSetelah Update:" << endl;
    printList(L);
    cout << "\nBarang dengan Harga Akhir antara 2.000 dan 7.000:" << endl;
    searchingHargaAkhir(L, 2000, 7000);
    cout << "\nBarang dengan Harga Akhir Tertinggi:" << endl;
    MaxHargaAkhir(L);
    deleteFirst(L);
    cout << "\nSetelah Menghapus Barang Pertama:" << endl;
    printList(L);
    return 0;
}
```
##### Output 1
![Screenshot Output 1](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/e1317bb72f296a38f1cf225be1452a92bf287a74/MODUL%203/output3-1.png)
