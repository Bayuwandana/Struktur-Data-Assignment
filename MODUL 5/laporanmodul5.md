# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (2)/h1>
<p align="center">Muhammad Zacky Permana - 103112430159</p>

## Dasar Teori

Singly Linked List (SLL) dalam bahasa C merupakan struktur data dinamis yang menghubungkan elemen-elemen melalui pointer secara satu arah, di mana setiap node menyimpan data dan alamat node berikutnya. Implementasinya sangat bergantung pada manajemen memori manual menggunakan fungsi malloc untuk memesan ruang di memori heap saat pembuatan node, dan fungsi free untuk menghapus node guna mencegah kebocoran memori.
Dalam operasionalnya, SLL dikendalikan oleh sebuah pointer utama bernama Head yang menjadi pintu masuk ke seluruh rangkaian data. Proses penambahan data dapat dilakukan dengan cara memanipulasi alamat pointer, baik di awal, di akhir, maupun di tengah list, tanpa harus menggeser elemen lain seperti pada array. Penelusuran data dilakukan secara sekuensial mulai dari Head dan berakhir ketika pointer menunjukkan nilai NULL, yang menandakan bahwa ujung list telah tercapai.

## Guided 

#### listbuah.h

```C++
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

// deklarasi isi data struct mahasiswa
struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{//ini linked listnya 
    address first;
};

//semua function &prosedur yg akan dipakai 
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodebaru);
void insertAfter(linkedlist &List, address nodebaru, address prev);
void insertLast(linkedlist &List, address nodebaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5(part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5(part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir);

#endif

```
#### listbuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

```
#### main.cpp
```C++

#include "listbuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

   updateFirst(List);
   updateLast(List);
   updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData (List, "Kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "Jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}

```
Ketiga file ini bekerja secara terintegrasi untuk mengelola struktur data linear yang bersifat dinamis. File listbuah.h berfungsi sebagai definisi struktur dan antarmuka (interface); di dalamnya didefinisikan struktur buah sebagai tipe data isi, struktur node sebagai pembungkus data beserta pointernya, serta prototipe fungsi yang mencakup operasi dasar hingga operasi pencarian tingkat lanjut.

Selanjutnya, listbuah.cpp berisi implementasi logika dari seluruh fungsi yang telah dideklarasikan. File ini menangani manajemen memori secara manual melalui alokasi (menggunakan new) dan dealokasi (menggunakan delete). Logika yang diterapkan sangat lengkap, mulai dari penambahan node (di awal, akhir, atau tengah), penghapusan node (termasuk penghapusan seluruh list), hingga pembaruan data (update). Fitur tambahan yang menonjol di sini adalah fungsi searching yang memungkinkan pencarian data berdasarkan nama buah, alamat memori node, hingga pencarian berdasarkan rentang harga tertentu.

Terakhir, file main.cpp berperan sebagai program utama yang mensimulasikan penggunaan nyata dari sistem ini. Di dalamnya, program membuat list kosong, mengalokasikan lima jenis buah (Jeruk, Apel, Pir, Semangka, dan Durian), dan menyusunnya ke dalam list. Program kemudian menguji integritas sistem dengan melakukan serangkaian pembaruan data, pencarian informasi, dan diakhiri dengan prosedur penghapusan node serta pembersihan seluruh memori list.
    
## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”

### singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

struct List {
    Node *first;
};

void createList(List &L);
Node* alokasi(int x);
void dealokasi(Node *P);
void insertFirst(List &L, Node *P);
void printInfo(List L);

Node* findElm(List L, int x);
int totalInfo(List L);

#endif

```
### singlylist.cpp
```C++
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
singlylist.cpp (Logika): Berisi implementasi teknis dari setiap fungsi, seperti pengalokasian memori dinamis untuk node baru dan metode insertFirst yang selalu meletakkan data di posisi paling depan. File ini juga menyediakan fungsi pencarian elemen (findElm) serta fungsi totalInfo yang menelusuri seluruh list untuk menjumlahkan nilai angka yang ada.


#### Output 1
![Screenshot Output 1](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/71bdde810b824f4e9b3bc03caff5475c0d58b153/MODUL%205/hasil%20foto/Screenshot%202025-12-29%20180248.png)


Ketiga file C++ ini bekerja sama untuk mengimplementasikan dan menguji **ADT (Abstract Data Type) Singly Linked List**. File **`unguided1list.h`** berfungsi sebagai *interface*, mendefinisikan struktur data (`List`, `ElmList`, `address`) dan mendeklarasikan *prototype* untuk operasi dasar (seperti `createList`, `alokasi`, `insertFirst`, dan `printInfo`). File **`unguided1list.cpp`** menyediakan **implementasi** konkret dari semua *prototype* yang ada di file header, berisi kode logis untuk manajemen memori dan manipulasi pointer. Terakhir, file **`unguided1main.cpp`** bertindak sebagai **program utama** yang menguji ADT tersebut dengan membuat sebuah *list* kosong, mengalokasikan dan menyisipkan lima elemen data (`2, 0, 8, 12, 9`) secara berurutan menggunakan prosedur `insertFirst`, dan kemudian mencetak isi *list* tersebut ke konsol.



### 2. Hasil ADT Singly Linked list
### Output:
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/71bdde810b824f4e9b3bc03caff5475c0d58b153/MODUL%205/hasil%20foto/Screenshot%202025-12-29%20180248.png)


singlylist.h (Interface): Berfungsi sebagai kerangka program yang mendefinisikan struktur Node (terdiri dari data info dan penunjuk next) serta struktur List untuk menandai kepala rangkaian. Di sini juga dideklarasikan prototipe fungsi untuk operasi dasar hingga fitur perhitungan.


## Kesimpulan
Kesimpulannya, kode ini menunjukkan bahwa kita bisa menambah data kapan saja tanpa batas ukuran, mencari data tertentu, dan menjumlahkan seluruh nilai di dalam list hanya dengan mengikuti rantai pointernya dari depan sampai ke ujung.
