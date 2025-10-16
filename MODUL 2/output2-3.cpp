
#include <iostream>
using namespace std;

const int UKURAN = 10;
int arrA[UKURAN] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};

int cariMinimum() {
    int min = arrA[0];
    for (int i = 1; i < UKURAN; i++) {
        if (arrA[i] < min) {
            min = arrA[i];
        }
    }
    return min;
}

int cariMaksimum() {
    int max = arrA[0];
    for (int i = 1; i < UKURAN; i++) {
        if (arrA[i] > max) {
            max = arrA[i];
        }
    }
    return max;
}

void hitungRataRata() {
    float sum = 0;
    for (int i = 0; i < UKURAN; i++) {
        sum += arrA[i];
    }
    float rataRata = sum / UKURAN;
    cout << "Rata-rata: " << rataRata << endl;
}

// Fungsi tampilkan isi array
void tampilkanArray() {
    cout << "Isi array: ";
    for (int i = 0; i < UKURAN; i++) {
        cout << arrA[i] << " ";
    }
    cout << endl;
}

int main() {
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---\n";
        cout << "1. Tampilkan isi array\n";
        cout << "2. Cari nilai maksimum\n";
        cout << "3. Cari nilai minimum\n";
        cout << "4. Hitung nilai rata-rata\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanArray();
                break;
            case 2:
                cout << "Nilai maksimum: " << cariMaksimum() << endl;
                break;
            case 3:
                cout << "Nilai minimum: " << cariMinimum() << endl;
                break;
            case 4:
                hitungRataRata();
                break;
            case 0:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}