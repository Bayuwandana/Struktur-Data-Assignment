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