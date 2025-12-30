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