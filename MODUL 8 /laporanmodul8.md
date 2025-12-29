
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
### . [Penggunaan Queue] 

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
### . [Penggunaan Queue dengan beberapa implementasi] 

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
//main.cpp
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
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/9748b4e698e991a84b68d66544c725593c5407ce/MODUL%207/hasil%20foto/Screenshot%202025-12-30%20002218.png)

Kode program ini merupakan implementasi struktur data Stack menggunakan Array statis dengan kapasitas maksimal 20 elemen, yang beroperasi berdasarkan prinsip LIFO (Last In First Out) di mana penambahan data melalui fungsi push dan pengambilan data melalui fungsi pop sepenuhnya dikendalikan oleh variabel top sebagai penanda indeks puncak.
Keunikan dari kode ini terletak pada fungsi balikStack, sebuah prosedur yang secara fisik membalikkan urutan elemen di dalam memori array menggunakan teknik two-pointer swapping (menukar elemen indeks awal dengan indeks akhir secara bergantian), sehingga elemen yang sebelumnya berada di dasar tumpukan berpindah menjadi elemen teratas tanpa memerlukan struktur data bantuan lainnya.

### soal 2. 

### stack.h
```C++

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        int val = pop(S);
        push(temp, val);
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

```
### main.cpp
```C++
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    
    printInfo(S);
    return 0;
}

```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/5bf4c91dab2a69bb3bebe8e85bd6259123d1a41d/MODUL%207/hasil%20foto/Screenshot%202025-12-30%20001648.png)

Kode program ini merupakan pengembangan dari implementasi Stack berbasis Array statis sebelumnya, yang kini dilengkapi dengan fitur cerdas pushAscending untuk menjaga agar data di dalam tumpukan selalu terurut dari nilai terkecil di dasar hingga nilai terbesar di puncak.

### soal 3.
### stack.h
```C++

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef int infotype;

const int MAX = 20;

struct Stack{
    int data[MAX];
    int top;

};

void createStack(Stack &S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int X);
void getInputStream(Stack &S);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype X) {
    if(S.top == MAX - 1){
        cout << "Stack Penuh!" << endl;
    } else {
        S.top++;
        S.data[S.top] = X;
    }
}

infotype pop(Stack &S) {
    if(S.top == - 1){
        cout << "Stack kosong!" << endl;
        return -1;
    } else {
        int val = S.data[S.top];
        S.top--;
        return val;
    }
}

void printInfo(Stack S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        cout << "[TOP] " ;
        for(int i = S.top; i >= 0; --i){
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

void balikStack(Stack &S) {
    if(S.top == - 1){
        cout << "Stack Kosong!" << endl;
    } else {
        if (S.top <= 0) return;
    }

    int i = 0;
    int j = S.top;

    while (i < j) {
        int temp = S.data[i];
        S.data[i] = S.data[j];
        S.data[j] = temp;
        i++;
        j--; 
    }
}
void pushAscending(Stack &S, int X) {
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.data[S.top] > X) {
        int val = pop(S);
        push(temp, val);
    }

    push(S, X);

    while (temp.top != -1) {
        push(S, pop(temp));
    }
}

void getInputStream(Stack &S) {
    createStack(S);

    char n;
    while(true){
        n = cin.get();
        if(n == '\n') {
            break;
        }
        if(n >= '0' && n <= '9' ) {
            int val = n - '0';
            push(S, val);
        }
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}

```
### Output soal 3:
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/f66078fc2a30647d5e246c7d0e237b454b0cfd9b/MODUL%207/hasil%20foto/Screenshot%202025-12-30%20003037.png)


Kode ini mengimplementasikan Stack berbasis Array yang mampu membaca input angka secara langsung dari pengguna, menyimpannya dengan aturan LIFO, dan memiliki kemampuan untuk membalikkan urutan data secara fisik di dalam memori array.

### Kesimpulan
Program ini merupakan model Stack yang komprehensif karena tidak hanya menjalankan fungsi standar LIFO (Last In First Out), tetapi juga mengintegrasikan fungsi filtering untuk hanya menerima input bertipe numerik, fungsi sorting otomatis melalui penggunaan tumpukan sementara (temporary stack), dan fungsi reversal fisik menggunakan algoritma two-pointer swapping. Dengan kapasitas statis sebesar 20 elemen, kode ini sangat efektif untuk mendemonstrasikan bagaimana data dapat dimanipulasi di dalam memori array tanpa kehilangan integritas struktur tumpukannya.


## Referensi
[1] GeeksforGeeks - Stack Data Structure: https://www.geeksforgeeks.org/stack-data-structure/

[2]Sorting a Stack using a Temporary Stack: https://www.geeksforgeeks.org/sort-a-stack-using-a-temporary-stack/
