# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Bayu Wandana 103112430159</p>

## Dasar Teori
Graph adalah kumpulan titik (node) dan garis (edge) yang saling terhubung. Bayangkan kostan dan kampus sebagai titiknya, sementara rute jalan yang menghubungkan keduanya adalah garis penghubungnya.

### A. Materi Modul 14
Pada sesi ini, fokus utama adalah mengimplementasikan fungsi menggunakan algoritma penelusuran graph.

### 1. Breadth First Search (BFS)
BFS adalah teknik pencarian yang bergerak melebar. Algoritma ini memprioritaskan kunjungan ke semua tetangga terdekat di satu level sebelum pindah ke level yang lebih dalam. Cara Kerjanya: Dimulai dari titik awal (level 0), lalu menyisir semua titik di level 1 dari kiri ke kanan, dilanjutkan ke level berikutnya secara berurutan.

### 2. Depth First Search (DFS)
DFS adalah teknik pencarian yang bergerak mendalam. Algoritma ini akan menelusuri satu jalur hingga titik paling ujung sebelum balik lagi (backtracking) untuk mencoba jalur lainnya. Cara Kerjanya: Dimulai dari titik awal, kemudian masuk ke cabang terdalam secara berulang (rekursif) hingga tidak ada jalur lagi.


## Guided 

### . [Graph dengan beberapa fungsi] 

### graph.h
```C++

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;      //menyimpan data node (misal: char/int)
    int visited;        //Penanda untuk traversal (0/1) (penanda apakah node sudah dikunjungi)
    adrEdge firstEdge; //Pointer ke edge pertama yang terhubung
    adrNode Next;     //Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;  //Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;  //Pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph {
    adrNode First;  //Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);  //prosedur untuk mengeset fitur dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data);  //alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);  //alokasi Edge baru

void InsertNode(Graph &G, infoGraph data);  //menambahkan node ke dalam graph
adrNode FindNode(Graph G, infoGraph data);  //function untuk mencari alamat node berdasarkan nilai info yang diberikan
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); //prosedur untuk menghubungkan dua node (membuat edge dari info1 ke info2)
void DisconnectNode(adrNode node1, adrNode node2);  //prosedur untuk memutuskan hubungan dua node (menghapus edge dari node1 ke node2)
void DeleteNode(Graph &G, infoGraph X);  //prosedur untuk menghapus node X beserta semua Edge yang terhubung

void PrintInfoGraph(Graph G);  //Menampilkan isi graph(Adjency list)
void ResetVisited(Graph &G);  //Reset status visited sebelum traversal
void PrintBFS(Graph G, infoGraph StartInfo);  //traversal Breadth Search / BFS (Menggunakan queue untuk menelusuri node berdasarkan tingkat)
void PrintDFS(Graph G, infoGraph StartInfo);  //traversal Depth First Search / DFS (menggunakan stack untuk menelusuri node secara mendalam)

#endif

```
### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}


```
main.cpp
```C++
#include "graph.h"
#include "graph.cpp"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    
    //hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E') == NULL) {
        cout << "node E berhasil dihapus" << endl;
    } else {
        cout << "Node E tidak berhasil dihapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');  //BFS
    PrintDFS(G, 'A');  //DFS

    return 0;
}

```
Kode ini membangun sebuah sistem jaringan menggunakan metode Adjacency List yang terdiri dari dua komponen utama, yaitu Node (simpul) dan Edge (sisi). Node merepresentasikan objek atau data utama, sedangkan Edge berfungsi sebagai jembatan penghubung yang menyimpan alamat node tujuan, sehingga memungkinkan satu simpul terhubung ke banyak simpul lainnya secara dinamis.

## Unguided

## soal 1. 

### graph.h
```C++

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);

#endif

```
### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}


```
### main.cpp
```c++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;   
}

```
### Output soal 1 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/e2c8fab4639aa5f93e3e703528bbfac0997689be/MODUL%2014/hasil%20foto/Screenshot%202025-12-30%20211158.png)

Proses dimulai dengan fungsi InsertNode yang mengalokasikan memori untuk simpul baru dan menyambungkannya ke daftar utama menggunakan prinsip insert last. Setiap simpul memiliki penunjuk firstEdge yang awalnya bernilai kosong, siap untuk mencatat koneksi ke simpul lainnya melalui struktur ElmEdge.


### soal 2.  Buatlah prosedur untuk menampilkanhasil penelusuran DFS. Prosedur PrintDFS (Graph G, adrNode N);
### graph.h
```C++

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);
void PrintDFS(graph &G, adrNode N);

#endif

```
### graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {

        // Buat edge dari N1 -> N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        // Buat edge dari N2 -> N1 (undirected)
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

void PrintDFS(graph &G, adrNode N){
    if (N == NULL) return;
    stack<adrNode> Stak;
    Stak.push(N);
    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

```
### main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== Hasil Traversal DFS ===" << endl;
    PrintDFS(G, A);
    cout << endl;
}

```
### Output soal 2 :
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/e2c8fab4639aa5f93e3e703528bbfac0997689be/MODUL%2014/hasil%20foto/Screenshot%202025-12-30%20211450.png)

Secara teknis, kode ini menggunakan struktur Adjacency List yang terdiri dari dua lapisan linked list. Lapisan pertama adalah rangkaian simpul utama (ElmNode) yang menyimpan data, dan lapisan kedua adalah daftar sisi (ElmEdge) yang menempel pada setiap simpul sebagai representasi tetangga yang terhubung secara langsung.

### soal 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS. Prosedur PrintBFS (Graph G, adrNode N);

### graph.h
```C++

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct graph {
    adrNode first;
};

void CreateGraph(graph &G);
void InsertNode(graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(graph &G);
void PrintDFS(graph &G, adrNode N);
void PrintBFS(graph &G, adrNode N);

#endif

```
graph.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void CreateGraph(graph &G){
    G.first = NULL;
}

void InsertNode(graph &G, infoGraph X){
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = X;
    nodeBaru->visited = 0;
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;

    if(G.first == NULL) {
        G.first = nodeBaru;
    } else {
        adrNode nodeBantu = G.first;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    if (N1 != NULL && N2 != NULL) {

        // Buat edge dari N1 -> N2
        adrEdge E1 = new ElmEdge;
        E1->Node = N2;
        E1->Next = N1->firstEdge;
        N1->firstEdge = E1;

        // Buat edge dari N2 -> N1 (undirected)
        adrEdge E2 = new ElmEdge;
        E2->Node = N1;
        E2->Next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}

void PrintInfoGraph(graph &G) {
    adrNode nodeBantu = G.first;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " ";
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

void PrintDFS(graph &G, adrNode N){
    adrNode temp = G.first;
    while (temp != NULL) {
        temp->visited = 0;
        temp = temp->Next;
    }
    if (N == NULL) return;
    stack<adrNode> Stak;
    Stak.push(N);
    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}

void PrintBFS(graph &G, adrNode N){
    adrNode temp = G.first;
    while (temp != NULL) {
        temp->visited = 0;
        temp = temp->Next;
    }
    if (N == NULL ){
        return;
    }
    queue<adrNode> Qyu;
    Qyu.push(N);
    N->visited = 1;
    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

```
### main.cpp
```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main(){
    graph G;
    CreateGraph(G);

    InsertNode(G, 'A'); adrNode A = G.first;
    InsertNode(G, 'B'); adrNode B = A->Next;
    InsertNode(G, 'C'); adrNode C = B->Next;
    InsertNode(G, 'D'); adrNode D = C->Next;
    InsertNode(G, 'E'); adrNode E = D->Next;
    InsertNode(G, 'F'); adrNode F = E->Next;
    InsertNode(G, 'G'); adrNode Gn = F->Next;
    InsertNode(G, 'H'); adrNode H = Gn->Next;
    
    //hubungkan antar node
    ConnectNode(A, B);
    ConnectNode(A, C);
    ConnectNode(B, D);
    ConnectNode(B, E);
    ConnectNode(C, F);
    ConnectNode(C, Gn);
    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gn, H);

    cout << "=== LIST GRAPH ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

     cout << "=== Hasil Traversal DFS ===" << endl;
    PrintDFS(G, A);
    cout << endl;

    cout << "=== Hasil Traversal BFS ===" << endl;
    PrintBFS(G, A);
    cout << endl;

}

```
### Output soal 3:
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/e2c8fab4639aa5f93e3e703528bbfac0997689be/MODUL%2014/hasil%20foto/Screenshot%202025-12-30%20211643.png)

Kode ini mengimplementasikan struktur Graph menggunakan metode Adjacency List, di mana setiap simpul (Node) memiliki daftar sisi (Edge) yang menyimpan referensi ke simpul-simpul tetangganya, menciptakan struktur data dinamis yang sangat efisien dalam penggunaan memori untuk graf yang memiliki banyak simpul namun koneksi terbatas.

### Kesimpulan
Implementasi struktur data Graph dengan metode Adjacency List ini menunjukkan efisiensi dalam mengelola hubungan antar-simpul (node) yang dinamis melalui penggunaan memori yang hanya dialokasikan saat terjadi koneksi (edge). Penggunaan dua algoritma penelusuran memberikan fleksibilitas analisis yang berbeda: BFS (Breadth First Search) yang memanfaatkan Queue sangat efektif untuk memetakan hubungan berdasarkan level atau jarak terdekat, sementara DFS (Depth First Search) yang memanfaatkan Stack lebih optimal untuk eksplorasi jalur terdalam hingga ke ujung cabang. Mekanisme penandaan visited pada setiap node menjadi kunci utama dalam menjaga integritas traversal guna menghindari perulangan tak terbatas (infinite loop) dalam jaringan yang memiliki siklus.
