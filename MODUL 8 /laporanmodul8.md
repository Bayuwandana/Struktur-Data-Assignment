
# <h1 align="center">Laporan Praktikum Modul 8 Queue - Stack</h1>
<p align="center">Bayu Wandana - 103112430159</p>

## Dasar Teori
Antrean atau Queue merupakan jenis struktur data linear yang mengadopsi mekanisme pelayanan konvensional, layaknya barisan pelanggan di loket pembayaran. Sistem ini beroperasi dengan prinsip FIFO (First In, First Out), yang menjamin bahwa elemen data yang paling awal masuk ke dalam memori akan menjadi yang pertama untuk diakses atau dihapus. Dalam pengembangannya menggunakan bahasa C, tumpukan data ini dapat dikelola menggunakan larik (array) dengan ukuran tetap ataupun struktur linked list yang kapasitasnya dapat menyesuaikan kebutuhan secara dinamis.

A. Konsep Dasar Queue
Fokus utama pada pembahasan ini adalah penerapan Queue melalui linked list, yang modifikasinya relatif lebih efisien dibandingkan manipulasi list standar. Karakteristik utamanya terletak pada keterbatasan titik akses: penambahan data baru (enqueue) secara eksklusif dilakukan pada sisi belakang (Tail), sedangkan pengambilan data (dequeue) hanya diizinkan pada sisi depan (Head). Struktur ini dapat diimplementasikan baik menggunakan Singly Linked List untuk efisiensi memori, maupun Doubly Linked List untuk kemudahan penelusuran dua arah.

1. Enqueue
Enqueue adalah prosedur penyisipan data ke dalam antrean, di mana setiap elemen baru yang masuk akan ditempatkan pada posisi paling akhir, sehingga memperpanjang barisan tumpukan ke arah belakang.

2. Dequeue
Dequeue adalah prosedur ekstraksi atau penghapusan elemen dari antrean, yang dilakukan secara konsisten pada elemen yang berada di posisi terdepan untuk menjaga urutan pemrosesan.

### GUIDED 1
### [Penggunaan Queue] 

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include<string>

using namespace std;

struct Node {
    string nama;
    Node* next;
};

struct queue {
    Node* head;
    Node* tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif

```
### queue.cpp
```C++
#include "queue.h"
using namespace std;

void createQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

```
### main.cpp
```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    createQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
   
   
```
Kode program ini merupakan implementasi Queue menggunakan Linked List dinamis yang mengelola data berdasarkan prinsip FIFO (First In, First Out), di mana setiap penambahan nama baru melalui enQueue akan ditempatkan pada posisi tail (belakang) dan setiap penghapusan melalui deQueue dilakukan pada posisi head (depan) untuk menjamin urutan pelayanan yang adil sesuai urutan kedatangan.


## Guided 2
### [Penggunaan Queue dengan beberapa implementasi] 

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAKSIMAL = 5;

struct queue {
    string nama[MAKSIMAL];
    int head;
    int tail;
};

bool isFull(queue Q);
bool isEmpty(queue Q);
void createQueue(queue &Q); //terbentuk queue dengan head = -1 dan tail = -1
void enQueue(queue &Q, string nama); 
void deQueue(queue &Q);
void viewQueue(queue Q);

#endif

```
### queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void createQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}
 

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }

```
### main.cpp
```C++
#include "queue.h"
#include "queue.cpp"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    createQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```
Kode program ini merupakan implementasi struktur data Queue (Antrean) berbasis Array statis yang secara komprehensif mendemonstrasikan tiga jenis logika operasional yang berbeda yaitu antrean linear statis dengan posisi kepala tetap, antrean linear dinamis dengan kedua penunjuk bergerak, serta antrean sirkular yang memanfaatkan operator modulus untuk efisiensi ruang memori. Secara teknis, kode yang aktif menjalankan metode antrean linear statis di mana penambahan data melalui enQueue akan menggerakkan penunjuk tail hingga batas maksimal lima elemen, sementara proses deQueue dilakukan dengan cara menghapus data di posisi head lalu secara otomatis menggeser seluruh elemen yang tersisa di belakangnya ke depan agar posisi terdepan selalu berada pada indeks nol. Pendekatan ini memastikan bahwa urutan data tetap terjaga sesuai prinsip FIFO (First In, First Out), meskipun sistem juga telah menyiapkan logika alternatif dalam bentuk komentar untuk mengubah antrean menjadi model dinamis yang hanya menggerakkan indeks atau model sirkular yang memungkinkan tail berputar kembali ke indeks awal jika masih terdapat ruang kosong yang tersedia.
## Unguided

## soal 1. [alternatif 1]
### queue.h
```c++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

```
### queue.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}
 


int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q){
    if(isEmpty(Q)){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i < Q.tail; i++){
            Q.info[i] = Q.info[i+1];
        }
        Q.tail--;
        if(Q.tail < Q.head){ 
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

```
### main.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output soal 1 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/92ac0e320723a17cb6f683f8e3a6bb6a9724af92/MODUL%208%20/foto%20hasil/Screenshot%202025-12-30%20011501.png)

Kode program ini merupakan implementasi struktur data Queue (Antrean) berbasis Array statis yang menggunakan metode pergeseran elemen (shifting) untuk menjaga agar posisi depan antrean selalu tetap, di mana seluruh operasi data diatur oleh indikator head dan tail dengan kapasitas maksimal lima elemen bertipe integer. Program ini bekerja berdasarkan prinsip FIFO (First In, First Out), yang berarti data yang dimasukkan pertama kali melalui fungsi enqueue akan menempati indeks nol dan menggerakkan penunjuk tail ke kanan, sementara proses penghapusan melalui fungsi dequeue akan mengambil data dari posisi head lalu secara otomatis menjalankan perulangan untuk menggeser semua elemen di belakangnya satu langkah ke depan guna mengisi kekosongan posisi.
Strategi ini memastikan bahwa posisi head selalu konsisten pada awal indeks selama antrean tidak kosong, namun memiliki konsekuensi performa berupa kompleksitas waktu linear karena adanya proses pemindahan data setiap kali elemen terdepan dikeluarkan. Ketika semua elemen telah dikeluarkan hingga nilai tail melewati batas bawah head, sistem secara cerdas akan mereset kedua penunjuk kembali ke angka negatif satu sebagai tanda bahwa kondisi antrean telah kembali kosong sepenuhnya.

### soal 2. [alternatif 2]

### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

```
### queue.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

bool isFull(queue Q){
    if(Q.tail == MAX - 1 ){
        return true;
    } else {
        return false;
    }
}


void createQueue(queue &Q){ 
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}


void dequeue(queue &Q){
     if(isEmpty(Q) == true){
         cout << "Queue kosong!" << endl;
     } else {
         Q.head++;
         if(Q.head > Q.tail){
             Q.head = -1;
             Q.tail = -1;
         }
     }
 }

void printInfo(queue Q){
      cout << Q.head << " - " << Q.tail << " | ";
    if(isEmpty(Q) == true){
        cout << "Empty Queue";
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << Q.info[i] << " ";
        }
    }
    cout << endl;
}

```
### main.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/292f8e962e74d3d26a28ba3898dbd1eb976606df/MODUL%208%20/foto%20hasil/Screenshot%202025-12-30%20012500.png)

Kode program ini merupakan implementasi Queue Linear Dinamis berbasis array statis yang mengoperasikan mekanisme antrean dengan menggerakkan kedua penunjuk indeks secara progresif, di mana fungsi enqueue bertugas menambah data dengan menggeser penunjuk tail ke kanan sementara fungsi dequeue menghapus data cukup dengan menggeser penunjuk head maju tanpa perlu memindahkan posisi fisik elemen di dalam memori array. Pendekatan ini secara teknis lebih efisien dalam hal kecepatan eksekusi karena menghindari proses perulangan untuk menggeser data (shifting), namun memiliki karakteristik unik di mana ruang array yang sudah ditinggalkan oleh head akan menjadi area kosong yang tidak dapat diisi kembali hingga seluruh antrean dikosongkan. Untuk mengatasi keterbatasan memori tersebut, program menyertakan logika reset otomatis yang akan mengembalikan posisi head dan tail ke indeks awal jika semua elemen telah dikeluarkan, sehingga integritas prinsip FIFO (First In First Out) tetap terjaga sambil memastikan sistem dapat menerima input baru dari posisi dasar array kembali.

### soal 3. [alternatif 3]
### queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 5;

struct queue {
    int info[MAX];
    int head;
    int tail;
};

void createQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
int enqueue(queue &Q, infotype X); 
void dequeue(queue &Q);
void printInfo(queue Q);

#endif

```
### queue.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q)
{
    if (Q.head == -1 && Q.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(queue Q)
{
    if ((Q.tail + 1) % MAX == Q.head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createQueue(queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
}

int enqueue(queue &Q, infotype X)
{
    if (isFull(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmpty(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail = (Q.tail + 1) % MAX;
        }
        Q.info[Q.tail] = X;
    }
    return 0;
}

void dequeue(queue &Q)
{
    if (isEmpty(Q) == true)
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        if (Q.head == Q.tail)
        {
            Q.head = -1;
            Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % MAX;
        }
    }
}

void printInfo(queue Q)
{
    if (isEmpty(Q) == true)
    {
    cout << Q.head << " - " << Q.tail << " | Empty Queue" << endl;
    return;
    }
    else
    {
        cout << Q.head << " - " << Q.tail << " | ";
        int i = Q.head;
        int count = 1;
        while (true)
        {
            cout << Q.info[i] << " ";

            if (i == Q.tail)
                break;

            cout << " ";
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
}

```
### main.cpp
```c++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World" << endl;
    queue Q;
    createQueue(Q);

    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 2); printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}

```
### Output soal 3:
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/f1e1f8bedb50fa957ac15f21139c6cd93ede5224/MODUL%208%20/foto%20hasil/Screenshot%202025-12-30%20013558.png)

Kode program ini merupakan implementasi struktur data Circular Queue (Antrean Melingkar) berbasis array statis yang secara cerdas memanfaatkan operator modulus untuk memungkinkan penunjuk head dan tail berputar kembali ke indeks awal saat mencapai batas maksimal array. Berbeda dengan antrean linear yang membuang ruang kosong di depan setelah proses penghapusan, mekanisme sirkular ini memastikan efisiensi penggunaan memori karena posisi yang telah ditinggalkan oleh data lama dapat diisi kembali oleh data baru selama antrean belum penuh secara logika. Penentuan kondisi penuh dilakukan dengan memeriksa apakah posisi tail berikutnya akan menabrak head, sementara proses pengosongan data diselesaikan dengan menggeser head secara melingkar atau mengatur ulang kedua penunjuk ke angka negatif satu jika elemen terakhir telah dikeluarkan, sehingga integritas prinsip FIFO tetap terjaga dengan optimalitas ruang yang jauh lebih baik.

### Kesimpulan
Kode ini mengimplementasikan struktur data Circular Queue (Antrean Melingkar) berbasis array statis yang memanfaatkan aritmatika modulus untuk mengoptimalkan penggunaan memori dengan cara memungkinkan penunjuk head dan tail berputar kembali ke indeks awal array.

## Referensi
[1] GeeksforGeeks - Circular Queue Data Structure: https://www.geeksforgeeks.org/introduction-to-circular-queue/

[2] Programiz - Circular Queue Implementation: https://www.programiz.com/dsa/circular-queue

[3] Tutorialspoint - Queue Data Structure: https://www.tutorialspoint.com/data_structures_algorithms/queue_algorithm.htm
 
