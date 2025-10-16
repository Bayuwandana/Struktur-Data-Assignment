#include <iostream>
using namespace std;

const int SIZE = 3;

void inputMatriks(int mat[SIZE][SIZE]) {
    cout << "Masukkan elemen matriks 3x3:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Elemen [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
    }
}

void tampilkanMatriks(int mat[SIZE][SIZE]) {
    cout << "Matriks:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void penjumlahan(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
}

void pengurangan(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
}

void perkalian(int A[SIZE][SIZE], int B[SIZE][SIZE], int hasil[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hasil[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int matriksA[SIZE][SIZE], matriksB[SIZE][SIZE], hasil[SIZE][SIZE];
    int pilihan;

    cout << "=== Program Operasi Matriks 3x3 ===\n";
    inputMatriks(matriksA);
    cout << "\nMatriks A:\n";
    tampilkanMatriks(matriksA);

    inputMatriks(matriksB);
    cout << "\nMatriks B:\n";
    tampilkanMatriks(matriksB);

    cout << "\nPilih operasi:\n1. Penjumlahan\n2. Pengurangan\n3. Perkalian\n";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            penjumlahan(matriksA, matriksB, hasil);
            cout << "\nHasil Penjumlahan:\n";
            tampilkanMatriks(hasil);
            break;
        case 2:
            pengurangan(matriksA, matriksB, hasil);
            cout << "\nHasil Pengurangan:\n";
            tampilkanMatriks(hasil);
            break;
        case 3:
            perkalian(matriksA, matriksB, hasil);
            cout << "\nHasil Perkalian:\n";
            tampilkanMatriks(hasil);
            break;
        default:
            cout << "Pilihan tidak valid!\n";
    }

    return 0;
}

