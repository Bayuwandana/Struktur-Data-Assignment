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