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
