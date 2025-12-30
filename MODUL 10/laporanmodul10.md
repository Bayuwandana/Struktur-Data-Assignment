
# <h1 align="center">Laporan Praktikum Modul 10 - tree(bagian pertama)</h1>
<p align="center">Bayu Wandana - 103112430159</p>

## Dasar Teori
Konsep Dasar Tree
Setelah sebelumnya kita memahami struktur data linear seperti list, stack, dan queue, kini kita beralih ke struktur data non-linear yang dikenal sebagai Tree (Pohon). Tree dapat didefinisikan sebagai graf tak berarah yang saling terhubung tanpa membentuk sirkuit atau siklus. Struktur ini memiliki tiga ciri utama:
Pohon dianggap kosong jika tidak memiliki elemen sama sekali (empty tree).
Memiliki satu elemen utama di posisi paling atas yang tidak memiliki pendahulu, yang disebut sebagai Akar (Root).
Setiap elemen lainnya (node) hanya diizinkan memiliki tepat satu pendahulu (parent).
Materi Utama: Binary Search Tree (BST)
Pada sesi ini, fokus pembahasan adalah pada fungsi operasional dalam Binary Search Tree (BST), yaitu jenis pohon biner yang datanya tersusun secara sistematis.
1. Penyisipan (Insert)
Proses penambahan data dilakukan dengan membandingkan nilai: jika nilai baru lebih kecil dari node saat ini, data diletakkan pada sub-pohon kiri (Left Subtree), dan jika lebih besar, diletakkan pada sub-pohon kanan (Right Subtree).
2. Pencarian (Search)
Pencarian dilakukan secara rekursif mulai dari root:
Bandingkan nilai target dengan node saat ini.
Jika tidak cocok, arahkan penunjuk (pointer) ke anak kiri jika target lebih kecil, atau ke anak kanan jika target lebih besar.
Proses diulang hingga data ditemukan atau penunjuk mencapai nilai kosong (NULL).
3. Penghapusan (Delete)
Terdapat tiga skenario dalam menghapus node:
Node Daun (Leaf): Langsung dihapus tanpa modifikasi lain.
Node dengan 1 Anak: Posisi node yang dihapus langsung digantikan oleh anaknya.
Node dengan 2 Anak: Posisi node digantikan oleh nilai terbesar dari sub-pohon kiri atau nilai terkecil dari sub-pohon kanan.
4. Elemen Paling Kiri (Most Left)
Merupakan node dengan posisi paling ujung di sisi kiri. Dalam BST, ini merepresentasikan nilai terkecil yang ditemukan dengan menelusuri anak kiri hingga habis.
5. Elemen Paling Kanan (Most Right)
Merupakan node di posisi ujung kanan. Dalam BST, ini merepresentasikan nilai terbesar yang ditemukan dengan menelusuri anak kanan hingga habis.
Metode Penelusuran (Traversal)
Traversal adalah teknik mengunjungi seluruh node dalam pohon dengan urutan tertentu:
Pre-Order: Urutan kunjungannya adalah cetak data node, lalu beralih ke sub-pohon kiri, dan terakhir ke sub-pohon kanan (Root - Left - Right).
In-Order: Urutan kunjungannya adalah mulai dari sub-pohon kiri, cetak data node, baru kemudian ke sub-pohon kanan (Left - Root - Right). Metode ini akan menghasilkan data yang terurut.
Post-Order: Urutan kunjungannya adalah selesaikan sub-pohon kiri, lalu sub-pohon kanan, dan terakhir cetak data node tersebut (Left - Right - Root).

### GUIDED 1
### [Binary Searh Tree] 

### bst.h
```C++
#ifndef BST_H
#define BST_H
#define Nil NULL

using namespace std;

typedef struct BST *node; 

struct BST {
    int angka;
    node left;
    node right;
};

typedef node BinTree; 

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);

#endif
```
### bst.cpp
```C++
#include "bst.h"
#include <iostream>

using namespace std;

bool isEmpty(BinTree tree) {
    return tree == Nil;
}

void createTree(BinTree &tree) {
    tree = Nil;
}

node alokasi(int angkaInput) {
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus) {
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru) {
    if (tree == Nil) {
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan!" << endl;
    } else if (nodeBaru->angka < tree->angka) {
        insertNode(tree->left, nodeBaru);
    } else if (nodeBaru->angka > tree->angka) {
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari) {
    if (isEmpty(tree)) {
        cout << "Tree kosong!" << endl;
        return;
    }
    node nodeBantu = tree;
    node parent = Nil;
    bool ketemu = false;
    while (nodeBantu != Nil) {
        if (angkaCari < nodeBantu->angka) {
            parent = nodeBantu;
            nodeBantu = nodeBantu->left;
        } else if (angkaCari > nodeBantu->angka) {
            parent = nodeBantu;
            nodeBantu = nodeBantu->right;
        } else {
            ketemu = true;
            break;
        }
    }
    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        cout << "Data ditemukan!" << endl;
        cout << "Parent: " << (parent ? to_string(parent->angka) : "- (Root)") << endl;
        cout << "Child kiri: " << (nodeBantu->left ? to_string(nodeBantu->left->angka) : "-") << endl;
        cout << "Child kanan: " << (nodeBantu->right ? to_string(nodeBantu->right->angka) : "-") << endl;
    }
}

void preOrder(BinTree tree) {
    if (tree != Nil) {
        cout << tree->angka << " - ";
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void inOrder(BinTree tree) {
    if (tree != Nil) {
        inOrder(tree->left);
        cout << tree->angka << " - ";
        inOrder(tree->right);
    }
}

void postOrder(BinTree tree) {
    if (tree != Nil) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->angka << " - ";
    }
}

node mostLeft(BinTree tree) {
    while (tree && tree->left != Nil) tree = tree->left;
    return tree;
}

node mostRight(BinTree tree) {
    while (tree && tree->right != Nil) tree = tree->right;
    return tree;
}

bool deleteNode(BinTree &tree, int angka) {
    if (tree == Nil) return false;
    if (angka < tree->angka) return deleteNode(tree->left, angka);
    if (angka > tree->angka) return deleteNode(tree->right, angka);
    
    node tmp = tree;
    if (tree->left == Nil) {
        tree = tree->right;
        dealokasi(tmp);
    } else if (tree->right == Nil) {
        tree = tree->left;
        dealokasi(tmp);
    } else {
        node successor = mostLeft(tree->right);
        tree->angka = successor->angka;
        return deleteNode(tree->right, successor->angka);
    }
    return true;
}

void deleteTree(BinTree &tree) {
    if (tree != Nil) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree) {
    return (tree == Nil) ? 0 : 1 + size(tree->left) + size(tree->right);
}

int height(BinTree tree) {
    if (tree == Nil) return -1;
    return 1 + max(height(tree->left), height(tree->right));
}
```
### main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    BinTree tree;
    createTree(tree);
    int pilih, angka;

    do {
        cout << "\n========= MENU BST =========" << endl;
        cout << "1. Insert | 2. Delete | 3. Search | 4. PreOrder | 5. InOrder | 6. PostOrder" << endl;
        cout << "7. Size   | 8. Height | 9. MostRight | 10. MostLeft | 11. Clear | 0. Exit" << endl;
        cout << "Pilihan: "; cin >> pilih;

        switch (pilih) {
            case 1: cout << "Angka: "; cin >> angka; insertNode(tree, alokasi(angka)); break;
            case 2: cout << "Hapus: "; cin >> angka; deleteNode(tree, angka); break;
            case 3: cout << "Cari: "; cin >> angka; searchByData(tree, angka); break;
            case 4: preOrder(tree); break;
            case 5: inOrder(tree); break;
            case 6: postOrder(tree); break;
            case 7: cout << "Size: " << size(tree); break;
            case 8: cout << "Height: " << height(tree); break;
            case 9: if(tree) cout << "MostRight: " << mostRight(tree)->angka; break;
            case 10: if(tree) cout << "MostLeft: " << mostLeft(tree)->angka; break;
            case 11: deleteTree(tree); break;
        }
    } while (pilih != 0);
    return 0;
}
   
```
Program ini merupakan implementasi lengkap dari struktur data Binary Search Tree (BST) yang dirancang secara modular dan interaktif. Inti dari kode ini terletak pada pengaturan data angka di mana setiap elemen baru akan ditempatkan di sisi kiri jika nilainya lebih kecil atau di sisi kanan jika nilainya lebih besar dari induknya, sehingga data tersusun secara hierarkis. Melalui file header dan implementasi yang tersedia, program mampu melakukan manajemen memori secara dinamis mulai dari pembuatan node baru melalui proses alokasi hingga penghapusan seluruh pohon untuk membersihkan memori. Fitur utamanya mencakup fungsi pencarian yang sangat detail karena tidak hanya menemukan angka yang dicari tetapi juga mampu mengidentifikasi hubungan kekerabatan node tersebut seperti induk, saudara kandung, hingga anak-anaknya. Selain itu, program ini menyediakan mekanisme penghapusan node yang cerdas karena dapat menangani tiga kondisi berbeda, termasuk mengganti node yang memiliki dua anak dengan nilai terkecil dari cabang kanan agar struktur pohon tetap valid. Untuk memantau isi pohon, tersedia tiga metode penelusuran yaitu Pre-Order, In-Order, dan Post-Order, serta fungsi tambahan untuk menghitung total elemen, mengukur tinggi level pohon, dan menemukan nilai ekstrem terkecil maupun terbesar. Seluruh logika ini dikendalikan melalui menu interaktif pada fungsi utama yang memungkinkan pengguna untuk terus melakukan operasi pada pohon hingga memilih untuk keluar dari program.
## Unguided

## soal 1. 
### bstree.h
```c++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

// alokasi node
address alokasi(infotype x);

// insert node ke BST
void insertNode(address &root, infotype x);

// mencari node
address findNode(infotype x, address root);

// traversal inorder
void InOrder(address root);

#endif
```
### bstree.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

// fungsi alokasi
address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

// fungsi insert BST
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
    // jika sama → tidak dimasukkan
}

// fungsi cari node
address findNode(infotype x, address root) {
    if (root == Nil || root->info == x)
        return root;
    if (x < root->info)
        return findNode(x, root->left);
    return findNode(x, root->right);
}

// traversal InOrder
void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}


```
### main.cpp
```c++
#include <iostream>
#include "bstree.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;

    address root = Nil;
    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,7);

    InOrder(root);
    return 0;
}
```
### Output soal 1 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/84d2b1bc898bebc8ee9f70e4966110234c946f7c/MODUL%2010/foto%20hasil/Screenshot%202025-12-30%20091404.png)

Kode program ini membangun struktur Binary Search Tree (BST) yang mengorganisir data angka secara hierarkis. Melalui fungsi alokasi, program menyiapkan memori untuk setiap node baru yang terdiri dari data serta penunjuk cabang kiri dan kanan. Proses utama dilakukan oleh fungsi insertNode yang menempatkan angka lebih kecil ke cabang kiri dan angka lebih besar ke cabang kanan secara otomatis, serta mencegah masuknya data duplikat.
Program ini juga menyediakan fitur pencarian melalui findNode dan fitur penampilan data menggunakan metode InOrder. Metode penelusuran InOrder ini sangat penting karena secara sistematis mengunjungi cabang kiri, induk, lalu cabang kanan, yang hasilnya pasti akan menampilkan deretan angka dalam keadaan terurut dari terkecil ke terbesar meskipun data dimasukkan secara acak.

### soal 2.

### bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#define Nil NULL

typedef int infotype;
typedef struct Node* address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Deklarasi fungsi
address alokasi(infotype x);
void insertNode(address &root, infotype x);
void InOrder(address root);

int hitungNode(address root);
int hitungTotal(address root);
int hitungKedalaman(address root, int start);

#endif

```
### bstree.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x) {
    address P = new Node;
    if (P != Nil) {
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x) {
    if (root == Nil)
        root = alokasi(x);
    else if (x < root->info)
        insertNode(root->left, x);
    else if (x > root->info)
        insertNode(root->right, x);
}

void InOrder(address root) {
    if (root != Nil) {
        InOrder(root->left);
        cout << root->info << " ";
        InOrder(root->right);
    }
}

int hitungNode(address root) {
    if (root == Nil)
        return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root) {
    if (root == Nil)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == Nil)
        return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

```
### main.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = Nil;

    insertNode(root,1);
    insertNode(root,2);
    insertNode(root,6);
    insertNode(root,4);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,7);

    InOrder(root);
    cout << "\n";

    cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
    cout << "jumlah Node : " << hitungNode(root) << endl;
    cout << "total : " << hitungTotal(root) << endl;

    return 0;
}
```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/5c6cca30ff11387c5f78bcb9456e7108a946e738/MODUL%2010/foto%20hasil/Screenshot%202025-12-30%20093523.png)

Kode program ini membangun struktur Binary Search Tree (BST) yang mengelola data angka secara otomatis. Fungsi insertNode bertugas menyusun angka ke arah kiri (jika lebih kecil) atau ke arah kanan (jika lebih besar), sementara fungsi alokasi menyiapkan memori untuk setiap node tersebut.
Selain menyimpan data, program ini memiliki fungsi analisis otomatis: hitungNode untuk menghitung total elemen, hitungTotal untuk menjumlahkan semua nilai angka, dan hitungKedalaman untuk mengukur tinggi atau level maksimal pohon. Terakhir, fungsi InOrder digunakan untuk menampilkan angka secara terurut dari terkecil ke terbesar.
### soal 3. [alternatif 3]
### bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype X);
void insertNode(address &root, infotype X);
address findNode(infotype X, address &root);
void printInorder(address root);
void preOrder(address root);
void postOrder(address root);

#endif

```
### bstree.cpp
```c++
#include "bstree.h"
#include <iostream>
using namespace std;

address alokasi(infotype X){
    address nodeBaru = new Node;
    nodeBaru->info = X;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void insertNode(address &root, infotype X){
    if(root == Nil){
        root = alokasi(X);
    } else if (X < root->info){
        insertNode(root->left, X);
    } else if (X > root->info){
        insertNode(root->right, X);
    }
}

address findNode(infotype X, address &root){
    if(root == Nil){
        cout << "Tree kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = Nil;
        bool ketemu = false;
        while(nodeBantu != Nil){
            if(X < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if (X > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if (X == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu = true){
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data: " << nodeBantu->info << endl;
        }
    }
    return Nil;
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << " - ";
        printInorder(root->right);
    }
}

void preOrder(address root){
    if(root == Nil){
        return;
    }
    cout << root->info << " - ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(address root){
    if(root == Nil){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->info << " - ";
}

```
### main.cpp
```c++
#include <iostream>
#include "bstree.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 6);
    insertNode(root, 7);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 2);
    insertNode(root, 3);
    insertNode(root, 1);
    
    cout << "Tampilkan preOrder : " ;
    preOrder(root); 
    cout << endl;
    
    cout << "Tampilkan postOrder : "; 
    postOrder(root);
    cout << endl;
    
    return 0;
}

```
### Output soal 3:
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/f40650fc41b6fd33580d772c060b7c2cb8a2b8cf/MODUL%2010/foto%20hasil/Screenshot%202025-12-30%20094310.png)

Kode program ini merupakan implementasi struktur data Binary Search Tree (BST) yang berfungsi untuk mengelola informasi secara hierarkis dan teratur. Alur kerjanya dimulai dengan fungsi alokasi yang memesan ruang memori untuk setiap simpul baru, yang kemudian diposisikan oleh fungsi insertNode ke cabang kiri jika nilainya lebih kecil atau ke cabang kanan jika lebih besar dari induknya. Selain itu, program dilengkapi dengan fungsi findNode yang melakukan pencarian data secara efisien dengan cara menelusuri jalur yang sesuai berdasarkan perbandingan nilai.
Untuk menampilkan isi pohon, program menyediakan tiga metode penelusuran yaitu In-Order untuk mendapatkan urutan angka yang terurut dari terkecil ke terbesar, Pre-Order untuk melihat urutan dari akar ke cabang, dan Post-Order untuk melihat urutan dari cabang terdalam menuju akar. Seluruh logika ini diuji dalam bagian main dengan memasukkan serangkaian angka acak, yang membuktikan bahwa sistem mampu mengorganisir data yang berantakan menjadi struktur yang rapi dan mudah dicari.

### Kesimpulan
Kesimpulan dari seluruh implementasi kode tersebut adalah bahwa Binary Search Tree (BST) merupakan struktur data hierarkis yang sangat efisien untuk mengelola informasi secara otomatis berdasarkan aturan perbandingan nilai. Melalui mekanisme penyisipan yang menempatkan angka lebih kecil di kiri dan angka lebih besar di kanan, program ini mampu mengubah sekumpulan data acak menjadi struktur yang sangat cepat untuk dicari.
Keunggulan utama dari kode ini terletak pada kemampuannya untuk melakukan penelusuran data dalam berbagai urutan, seperti Pre-Order, Post-Order, dan khususnya In-Order yang secara konsisten menghasilkan deretan angka yang terurut secara numerik. Dengan pemisahan kode menjadi modular (header, implementasi, dan main), program menjadi lebih mudah dikelola, dikembangkan, dan digunakan kembali untuk kebutuhan pemrosesan data yang lebih kompleks di masa depan.
