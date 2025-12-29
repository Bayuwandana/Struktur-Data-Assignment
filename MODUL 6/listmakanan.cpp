#include "listmakanan.h"

bool isEmpty(linkedlist List) {
    return (List.first == Nil);
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan di awal." << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List)){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan di akhir." << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List)){
        List.first = List.last = nodeBaru;
    } else if (nodePrev != Nil){
        if(nodePrev == List.last){
            insertLast(List, nodeBaru);
        } else {
            nodeBaru->next = nodePrev->next;
            nodeBaru->prev = nodePrev;
            (nodePrev->next)->prev = nodeBaru;
            nodePrev->next = nodeBaru;
            cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah " << nodePrev->isidata.nama << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List)){
        List.first = List.last = nodeBaru;
    } else if (nodeNext != Nil){
        if(nodeNext == List.first){
            insertFirst(List, nodeBaru);
        } else {
            nodeBaru->next = nodeNext;
            nodeBaru->prev = nodeNext->prev;
            (nodeNext->prev)->next = nodeBaru;
            nodeNext->prev = nodeBaru;
            cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum " << nodeNext->isidata.nama << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(!isEmpty(List)){
        cout << "Update data node pertama:" << endl;
        cout << "Nama makanan : "; getline(cin >> ws, List.first->isidata.nama);
        cout << "Jenis makanan: "; getline(cin, List.first->isidata.jenis);
        cout << "Harga        : "; cin >> List.first->isidata.harga;
        cout << "Rating       : "; cin >> List.first->isidata.rating;
        cin.ignore();
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedlist List){
    if(!isEmpty(List)){
        cout << "Update data node terakhir:" << endl;
        cout << "Nama makanan : "; getline(cin >> ws, List.last->isidata.nama);
        cout << "Jenis makanan: "; getline(cin, List.last->isidata.jenis);
        cout << "Harga        : "; cin >> List.last->isidata.harga;
        cout << "Rating       : "; cin >> List.last->isidata.rating;
        cin.ignore();
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(!isEmpty(List) && nodePrev != Nil && nodePrev->next != Nil){
        address nodeBantu = nodePrev->next;
        cout << "Update data setelah node " << nodePrev->isidata.nama << ":" << endl;
        cout << "Nama makanan : "; getline(cin >> ws, nodeBantu->isidata.nama);
        cout << "Jenis makanan: "; getline(cin, nodeBantu->isidata.jenis);
        cout << "Harga        : "; cin >> nodeBantu->isidata.harga;
        cout << "Rating       : "; cin >> nodeBantu->isidata.rating;
        cin.ignore();
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(!isEmpty(List) && nodeNext != Nil && nodeNext->prev != Nil){
        address nodeBantu = nodeNext->prev;
        cout << "Update data sebelum node " << nodeNext->isidata.nama << ":" << endl;
        cout << "Nama makanan : "; getline(cin >> ws, nodeBantu->isidata.nama);
        cout << "Jenis makanan: "; getline(cin, nodeBantu->isidata.jenis);
        cout << "Harga        : "; cin >> nodeBantu->isidata.harga;
        cout << "Rating       : "; cin >> nodeBantu->isidata.rating;
        cin.ignore();
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}