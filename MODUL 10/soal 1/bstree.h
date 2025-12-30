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