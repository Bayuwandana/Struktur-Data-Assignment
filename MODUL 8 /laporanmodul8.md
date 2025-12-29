
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

### . [stack menggunakan linked list] 

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
//main.cpp
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


## Guided 1

### . [Stack menggunakan fungsi array] 

### stack.h
```C++

#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong

};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif

```
### stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stackTable s) {
    return s.top == -1;
}

bool isFull(stackTable s){
    return s.top == MAX -1;
}

void createStack(stackTable &s) {
    s.top = -1;
}

void push(stackTable &s, int angka){
    if(isFull(s)){
        cout << "Stack Penuh!" << endl;
    } else {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data " << angka << " berhasil ditambahkan kedalam stack!" << endl;
    }
}

void pop(stackTable &s){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
    } else {
        int val = s.data[s.top];
        s.top--;
        cout << "Data " << val << " Berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi){
    if(isEmpty(s)){
        cout << "Stack kosong!" << endl;
        return;
    }
    if(posisi <= 0){
        cout << "Posisi tidak valid!" << endl;
        return;
    }

    //index = top - (posisi -1)
    int idx = s.top - (posisi -1);
    if(idx < 0 || idx > s.top){
        cout << "Posisi " << posisi << " Tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka: ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
    } else {
        for(int i = s.top; i >= 0; --i){
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data){
    if(isEmpty(s)){
        cout << "Stack Kosong!" << endl;
        return;
    }
    cout << "Mencari data" << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for(int i = s.top; i >= 0; --i){
        if(s.data[i] == data){
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if(!found){
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```
### main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    //Posisi dihitung dari TOP(1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

```
Kode program tersebut merupakan implementasi struktur data Stack menggunakan Array statis dengan kapasitas terbatas sebanyak 10 elemen, di mana pengelolaan seluruh datanya dikendalikan oleh variabel top yang berfungsi sebagai penanda indeks posisi elemen paling atas.
Secara operasional, program ini menerapkan prinsip LIFO (Last In First Out) melalui fungsi push yang akan menaikkan nilai top saat data ditambah dan fungsi pop yang akan menurunkan nilai top saat data dihapus, dengan tambahan fitur validasi untuk mendeteksi kondisi Stack Penuh (overflow) maupun Stack Kosong (underflow).
Selain operasi dasar tersebut, kode ini memiliki kecerdasan dalam mengakses data secara spesifik melalui fungsi update dan searchData yang menggunakan perhitungan indeks mundur untuk memproses elemen berdasarkan urutan posisinya dari atas ke bawah.
## Unguided

## Soal 1
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
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

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

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

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
