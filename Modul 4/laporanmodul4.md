# <h1 align="center">Laporan Praktikum Modul 4 Singly Linked List(1)</h1>
<p align="center">Bayu Wandana - 103112430159</p>

## Dasar Teori

Berbeda dengan struktur array yang menggunakan blok memori berurutan, Singly Linked List (SLL) mengelola datanya secara dinamis melalui node-node yang terpisah namun saling terhubung. Setiap node membawa beban informasinya sendiri serta sebuah pointer yang berfungsi sebagai jembatan menuju node berikutnya. Sistem ini dimulai dari sebuah titik akses utama yang disebut First, dan berakhir pada penanda NULL.

Fleksibilitas SLL terlihat pada kemudahan operasi seperti CreateList, alokasi/dealokasi memori, hingga penyisipan dan penghapusan data di posisi mana pun tanpa mengganggu struktur keseluruhan secara drastis. Dengan fitur pencarian dan cetak info, SLL menjadi solusi efisien untuk menangani data yang jumlahnya berubah-ubah secara tidak terprediksi, karena tidak terikat pada batasan ukuran statis.

### Guided 

### 1. Linked List 1
#### mainguided1.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
#### listguided1.cpp
```C++
#include "list1.h"
#include <iostream>
using namespace std;


bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void printList(linkedlist List) {
    
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```
#### list1.h
```C++

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; 

typedef struct node *address; 

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ 
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
Ketiga file tersebut membentuk satu kesatuan program untuk mengelola data mahasiswa menggunakan struktur data Singly Linked List. File list1.h berfungsi sebagai kerangka atau kontrak program; di sini didefinisikan struktur node yang menyimpan dataMahasiswa (nama, NIM, umur) dan pointer next, serta mendeklarasikan prototipe fungsi-fungsi dasar seperti alokasi memori dan metode penyisipan node.
Selanjutnya, listguided1.cpp berperan sebagai penyedia logika dari fungsi-fungsi tersebut. File ini mengatur bagaimana memori dipesan lewat fungsi alokasi, bagaimana node baru diletakkan di posisi tertentu melalui insertFirst, insertLast, atau insertAfter, hingga cara menelusuri list untuk menampilkan data ke layar melalui printList.
Sebagai pusat kendali, mainguided1.cpp menjalankan simulasi nyata dengan membuat sebuah list bernama List. Di dalam main, beberapa objek mahasiswa (Dhimas, Arvin, Rizal, Satrio, dan Joshua) dibuat satu per satu menggunakan fungsi alokasi, kemudian dihubungkan secara dinamis ke dalam list. Program ini secara spesifik menguji fleksibilitas SLL dengan menempatkan data di posisi yang berbeda-beda sebelum akhirnya menampilkan hasil akhir urutan mahasiswa tersebut kepada pengguna.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”
```C++
Type infotype : int
Type address : pointer to ElmList
Type ElmList <
    info : infotype
    next : address
>
Type List : < First : address >
procedure CreateList( input/output L : List )
function alokasi( x : infotype ) -> address
procedure dealokasi( input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst( input/output L : List, input P : address )
```
### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”. Kemudian buat program utama didalam file “main.cpp” dengan implementasi sebagai berikut :
```C++
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

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

    printInfo(L);
    
    return 0;
}
```
### KODE PROGRAM
#### main.cpp
```C++
// File: main.cpp

#include "ungu1singlist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = NULL;

    createList(&L);

    P1 = alokasi(2);
    insertFirst(&L, P1);

    P2 = alokasi(0);
    insertFirst(&L, P2);

    P3 = alokasi(8);
    insertFirst(&L, P3);

    P4 = alokasi(12);
    insertFirst(&L, P4);

    P5 = alokasi(9);
    insertFirst(&L, P5);

    printInfo(L);

    // Bagian tambahan untuk membersihkan memori (dealokasi semua elemen)
    address current = L.First;
    address temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        dealokasi(temp);
    }
    L.First = NULL;

    return 0;
}
```
#### list.cpp
```C++
// File: Singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H
```
#### singlylist.h
```C++
// File: Singlylist.h

#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

#endif // SINGLYLIST_H
```
#### Output 1
![Screenshot Output 1](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/b2de01807dab1c8312ce6c5c91f1ab1e44f1f2c9/Modul%204/foto%20hasil/Screenshot%202025-12-29%20170318.png)


Ketiga file ini membentuk satu kesatuan program untuk mengimplementasikan ADT (Abstract Data Type) Singly Linked List yang menyimpan data bertipe integer. File Singlylist.h bertindak sebagai header dan interface, yang mendefinisikan struktur data ElmList sebagai node, address sebagai pointer, dan List sebagai pengelola titik awal (First), serta mendeklarasikan prototipe fungsi-fungsi dasar yang diperlukan. File Singlylist.cpp (yang dalam pesanmu tertulis sebagai list.cpp) berisi implementasi logika dari setiap prosedur, mulai dari pembuatan list kosong, pengalokasian memori dinamis untuk angka-angka baru, hingga mekanisme penyisipan elemen di posisi pertama.
Terakhir, file main.cpp berfungsi sebagai program utama yang menjalankan skenario pengujian. Di dalam file ini, list diinisialisasi dan diisi dengan lima buah nilai (2, 0, 8, 12, 9) menggunakan metode insertFirst. Karena menggunakan metode "sisip di awal", urutan angka yang muncul saat dipanggil oleh prosedur printInfo nantinya akan terbalik dari urutan pemanggilannya. File utama ini juga menunjukkan praktik manajemen memori yang baik dengan melakukan dealokasi pada seluruh node di akhir program untuk mencegah kebocoran memori (memory leak).


### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

#### main.cpp
```C++
// File: unguided1main.cpp

#include "ungu2singlist.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(&L);

    P1 = alokasi(2); insertFirst(&L, P1);
    P2 = alokasi(0); insertFirst(&L, P2);
    P3 = alokasi(8); insertFirst(&L, P3);
    P4 = alokasi(12); insertFirst(&L, P4);
    P5 = alokasi(9); insertFirst(&L, P5);

    cout << "List Awal (untuk verifikasi): ";
    printInfo(L);
    cout << endl << endl;

    address P_del;
    
    deleteFirst(&L, &P_del);
    dealokasi(P_del);
    
    deleteLast(&L, &P_del); 
    dealokasi(P_del);
    
    address Prec = search(L, 12); 

    if (Prec != NULL && Prec->next != NULL && Prec->next->info == 8) {
        deleteAfter(&L, &P_del, Prec);
        dealokasi(P_del);
    }

    printInfo(L);
    cout << endl; 
    
    cout << "Jumlah node : " << nbList(L) << endl; 

    deleteList(&L);
    cout << endl << "- List Berhasil Terhapus -" << endl;

    cout << "Jumlah node : " << nbList(L) << endl; 

    return 0;
}
```
#### list.cpp
```C++
// File: unguided1list.cpp

#include "ungu2singlist.h"
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
    if (P == NULL) return; 

    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
}

address search(List L, infotype X) {
    address P = L.First;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

int nbList(List L) {
    int count = 0;
    address P = L.First;
    while (P != NULL) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteFirst(List *L, address *P) {
    *P = (*L).First;
    if (*P != NULL) {
        (*L).First = (*L).First->next;
        (*P)->next = NULL; 
    }
}

void deleteLast(List *L, address *P) {
    address Last = (*L).First;
    address Prec = NULL;
    
    if (Last != NULL && Last->next == NULL) {
        *P = Last;
        (*L).First = NULL;
        return;
    }

    while (Last != NULL && Last->next != NULL) {
        Prec = Last;
        Last = Last->next;
    }

    if (Last != NULL) {
        *P = Last;
        Prec->next = NULL;
    }
}

void deleteAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        *Pdel = Prec->next;
        Prec->next = (*Pdel)->next;
        (*Pdel)->next = NULL;
    } else {
        *Pdel = NULL;
    }
}

void deleteList(List *L) {
    address P;
    while ((*L).First != NULL) {
        deleteFirst(L, &P);
        dealokasi(P);
    }
}
```
#### singlylist.h
```C++
// File: unguided1list.h

#ifndef UNGUIDED1LIST_H
#define UNGUIDED1LIST_H

typedef int infotype;
typedef struct ElmList *address;

typedef struct ElmList {
    infotype info;
    address next;
} ElmList;

typedef struct {
    address First;
} List;

void createList(List *L);
address alokasi(infotype X);
void dealokasi(address P);

void insertFirst(List *L, address P);
void printInfo(List L);

int nbList(List L);
address search(List L, infotype X); 
void deleteFirst(List *L, address *P);
void deleteLast(List *L, address *P);
void deleteAfter(List *L, address *Pdel, address Prec);
void deleteList(List *L);

#endif // UNGUIDED1LIST_H
```

#### Output 2
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/c50c2dc06582f6f0dcb74f03390f51fdaf2a9eea/Modul%204/foto%20hasil/Screenshot%202025-12-29%20172100.png)

Ketiga berkas tersebut merupakan pengembangan lebih lanjut dari ADT Singly Linked List dengan penambahan fitur manipulasi data yang lebih kompleks. Berkas ungu2singlist.h berperan sebagai pustaka (header) yang merinci definisi struktur data dan prototipe fungsi, termasuk operasi penghapusan dan pencarian data. Berkas ungu2list.cpp menyajikan logika operasional yang mendalam, seperti algoritma penelusuran (traversal) untuk menghitung jumlah node (nbList), teknik pointer manipulation untuk menghapus elemen di awal, akhir, maupun posisi spesifik (deleteAfter), serta pembersihan seluruh memori list secara otomatis melalui deleteList.
Sebagai pengujian akhir, berkas ungu2main.cpp mendemonstrasikan siklus hidup linked list secara utuh: dimulai dari pembuatan list, pengisian data (angka 9, 12, 8, 0, 2), hingga proses modifikasi list dengan menghapus node pertama, node terakhir, dan node tertentu yang ditemukan melalui fungsi search. Program utama ini ditutup dengan menampilkan statistik jumlah node dan memastikan integritas memori dengan menghapus seluruh elemen yang tersisa sebelum program berakhir.



## Kesimpulan
Program ini mengimplementasikan struktur data Singly Linked List secara modular, yang terbagi ke dalam tiga komponen utama: definisisi antarmuka (header), implementasi logika, dan pengujian. Struktur ini menggunakan node sebagai unit penyimpanan dinamis yang terdiri dari sebuah nilai data (integer) dan sebuah pointer (next) sebagai penghubung ke elemen berikutnya. Karena alokasi memorinya bersifat dinamis, list ini mampu berkembang atau menyusut tanpa harus menentukan ukuran maksimal di awal.
Pada bagian operasional, sistem ini mencakup manajemen memori yang ketat melalui proses alokasi untuk menciptakan node baru dan dealokasi untuk membebaskan memori. Manipulasi data dilakukan melalui fungsi penyisipan (insert) dan penghapusan (delete) yang mencakup berbagai skenario posisi, yaitu di awal, di akhir, maupun di tengah list (setelah node tertentu). Selain itu, terdapat fungsi pendukung untuk melakukan pencarian data tertentu, penghitungan jumlah total elemen dalam list, serta penelusuran seluruh rangkaian untuk menampilkan informasi ke layar.
Secara keseluruhan, implementasi ini menunjukkan bagaimana pointer digunakan untuk mengelola sekumpulan data secara linear namun fleksibel. Program utama memastikan bahwa setiap elemen yang dibuat selalu dibersihkan kembali melalui prosedur penghapusan menyeluruh, sehingga menjamin efisiensi penggunaan memori dan integritas struktur data selama aplikasi berjalan.
