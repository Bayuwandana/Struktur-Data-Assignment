
#include <iostream>
using namespace std;

void swapPointer(int *a, int *b, int *c) {
    int temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void swapReference(int &a, int &b, int &c) {
    int temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    int x = 10, y = 20, z = 30;

    cout << "=== Swap Menggunakan Pointer ===\n";
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    swapPointer(&x, &y, &z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;

    x = 10; y = 20; z = 30;

    cout << "\n=== Swap Menggunakan Reference ===\n";
    cout << "Sebelum: x=" << x << ", y=" << y << ", z=" << z << endl;
    swapReference(x, y, z);
    cout << "Sesudah: x=" << x << ", y=" << y << ", z=" << z << endl;

    return 0;
}
