# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Bayu Wandana - 103112430159</p>

## Dasar Teori
Kebutuhan perangkat lunak merupakan landasan fundamental dari suatu sistem, yang secara komprehensif mendefinisikan seluruh fungsionalitas, fitur yang diperlukan, dan batasan operasional yang harus dipenuhi oleh perangkat lunak. Kebutuhan ini diklasifikasikan menjadi dua kategori utama. Kategori pertama adalah Kebutuhan Fungsional, yang secara spesifik menjelaskan apa yang harus dilakukan sistem, seperti kemampuan mencetak laporan, memutar konten, atau menghitung metrik tertentu. Kategori kedua adalah Kebutuhan Non-Fungsional (sering disebut kualitas atau batasan), yang berfokus pada bagaimana sistem harus beroperasi atau seberapa baik performanya. Aspek non-fungsional mencakup kecepatan respons (performa), tingkat keamanan, kemudahan penggunaan (usabilitas), dan kepatuhan terhadap batasan teknologi yang berlaku.

Dalam konteks sistem operasi (OS), Proses didefinisikan sebagai program yang sedang dalam tahap eksekusi, menjadikannya unit aktivitas dasar yang dikelola oleh OS. Untuk mengontrol setiap proses, sistem operasi memanfaatkan struktur data krusial yang dikenal sebagai Process Control Block (PCB), yang berfungsi menyimpan semua detail penting mengenai keadaan (state), register, dan informasi kontrol proses tersebut. Sepanjang siklus hidupnya, sebuah proses akan mengalami beberapa keadaan atau state: dimulai dari New (baru dibuat), beralih ke Ready (siap dieksekusi, menunggu CPU), kemudian ke Running (sedang dieksekusi), dapat berpindah ke Blocked (menunggu selesainya operasi I/O atau event), dan diakhiri dengan status Exit (proses telah selesai). Untuk menjamin kemampuan menjalankan banyak tugas secara bersamaan (multitasking), sistem operasi mengandalkan mekanisme penting seperti Context Switching (perpindahan kendali CPU yang cepat antar proses) dan Swapping (pemindahan proses dari memori utama ke disk jika memori penuh).

### 1. ...

```C++
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


```
penjelasan singkat 1
Program C++ ini dirancang untuk melakukan kalkulasi matriks 3x3, mencakup penjumlahan, pengurangan, dan perkalian. Melalui antarmuka input-output yang interaktif, pengguna diminta untuk menginput dua matriks dan memilih jenis operasi. Selanjutnya, program akan memproses perhitungan setiap elemen menggunakan perulangan dan menampilkan matriks hasil secara otomatis.

### 2. ...

```C++

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

```
penjelasan singkat 2
Program C++ ini mengimplementasikan algoritma pergeseran siklis (cyclic shift) untuk tiga variabel sambil secara komparatif mendemonstrasikan dua paradigma passing parameter: pass-by-pointer dan pass-by-reference. Fungsi swapPointer mengeksekusi penukaran nilai dengan memanfaatkan alamat memori dan dereferensi pointer, sebuah pendekatan yang umum dalam bahasa C. Sementara itu, fungsi swapReference menggunakan mekanisme reference C++ untuk memanipulasi variabel asli secara langsung. Kedua implementasi tersebut berhasil mencapai hasil akhir yang sama, yaitu pergeseran nilai variabel.


### 3. ...

```C++

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
```
penjelasan singkat  3
Program C++ ini dirancang sebagai alat bantu berbasis menu untuk melakukan analisis statistik sederhana pada sekumpulan data dari sepuluh angka. Fungsi-fungsi utamanya meliputi kemampuan untuk menampilkan seluruh data, menemukan nilai tertinggi dan terendah, serta menghitung rata-ratanya. Interaksinya dibuat terus-menerus, sehingga pengguna bisa memilih berbagai operasi sampai akhirnya memutuskan untuk keluar dari program.

##### Output 1
![Screenshot Output 1](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-2-1.jpg)

##### Output 2
![Screenshot Output 2](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-2-2.jpg)

##### Output 3
![Screenshot Output 3](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-2/Output-2-3.jpg)


## Kesimpulan
...

## Referensi
[1]
<br>Asyiknya Belajar Struktur Data di Planet C++. (n.d.). (n.p.):
Elex Media Komputindo.

<br>




