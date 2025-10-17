# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Bayu Wandana - 103112430159</p>

## Dasar Teori
Abstract Data Type (ADT) dapat dipandang sebagai model konseptual formal yang menetapkan suatu tipe data bersama dengan sekelompok operasi esensial (primitif) yang diizinkan untuk diterapkan padanya. Konsep ini berfungsi sebagai spesifikasi atau "cetak biru", yang tidak hanya menguraikan struktur data internal (mirip struct dalam C++), tetapi juga secara eksplisit mendefinisikan seluruh fungsi yang dapat berinteraksi dengan data tersebut. Operasi-operasi primitif ini dikategorikan ke dalam beberapa kelompok, seperti fungsi Konstruktor yang bertanggung jawab menciptakan objek data baru, Selector yang memungkinkan pengambilan atau akses data internal (biasanya menggunakan prefiks seperti Get), dan operasi lainnya untuk validasi data, input/output, hingga perbandingan.

Secara praktis, prinsip ADT diwujudkan melalui modularitas dengan membagi kode menjadi dua berkas utama: berkas header (.h) dan berkas body (.cpp). Berkas header (.h) berfungsi sebagai antarmuka publik atau spesifikasi ADT, menampung deklarasi struktur data (misalnya, struct untuk data mahasiswa) dan semua prototipe fungsi primitif. Sebaliknya, berkas body (.cpp) memuat implementasi detail atau kode program fungsional dari setiap operasi yang telah dideklarasikan dalam header. Program utama (driver) kemudian dapat memanfaatkan ADT ini cukup dengan menyertakan (include) berkas header (.h), sehingga tercapai pemisahan yang ketat antara antarmuka (cara ADT digunakan) dan implementasi (cara ADT bekerja).


### 1. ...

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "Nama   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        getline(cin, mhs[i].nim);
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "Tugas  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=========================================\n";
    cout << "Daftar Nilai Mahasiswa\n";
    cout << "=========================================\n";
    cout << "Nama\t\tNIM\t\tNilai Akhir\n";
    cout << "-----------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << "\t\t"
             << mhs[i].nim << "\t\t"
             << mhs[i].nilaiAkhir << endl;
    }

    cout << "=========================================\n";

    return 0;
}

```
Penjelasan singkat 1
Program C++ ini adalah sistem sederhana untuk mengelola nilai mahasiswa. Pertama, ia menggunakan kerangka data khusus (struct Mahasiswa) untuk menyimpan nama, NIM, nilai UTS, UAS, dan Tugas setiap mahasiswa. Kemudian, program meminta Anda memasukkan jumlah dan detail nilai untuk setiap mahasiswa. Setelah data dimasukkan, ia secara otomatis menghitung Nilai Akhir setiap mahasiswa dengan bobot tertentu. Terakhir, program akan menampilkan daftar rapi berisi Nama, NIM, dan Nilai Akhir dari semua mahasiswa yang telah diproses.

### 2. ...

```h

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(pelajaran pel);

#endif

```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaMapel = namaPel;
    p.kodeMapel = kodePel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}

```

```C++

#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";

    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);

    return 0;
}


```
penjelasan singkat 2
Kode ini mendemonstrasikan praktik pemrograman yang terorganisir, dikenal sebagai Abstract Data Type (ADT), di mana ia memisahkan kode menjadi tiga bagian utama. Bagian pertama (pelajaran.h) adalah spesifikasi yang mendefinisikan struktur data (struct pelajaran) dan fungsi-fungsi yang tersedia. Bagian kedua (implementasi fungsi) berisi detail cara kerja dari fungsi-fungsi tersebut, seperti cara membuat objek pelajaran baru dan cara menampilkannya. Bagian ketiga (fungsi main) adalah program utama yang hanya perlu memanggil fungsi-fungsi yang telah ditentukan di spesifikasi (pelajaran.h) untuk membuat dan menampilkan data mata pelajaran ("Struktur Data" dengan kode "STD"), menunjukkan bahwa kode utama dapat menggunakan tipe data tanpa perlu tahu bagaimana detail di dalamnya bekerja.

### 3. ...

```C++

#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };

    int *ptr1, *ptr2;
    ptr1 = &A[1][1];  
    ptr2 = &B[2][2];  
    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "\nArray B sebelum ditukar:\n";
    tampilArray(B);

    tukarElemen(A, B, 0, 0);

    cout << "\nSetelah menukar elemen A[0][0] dengan B[0][0]:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    tukarPointer(ptr1, ptr2);

    cout << "\nSetelah menukar nilai yang ditunjuk pointer:\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    return 0;
}




```
penjelasan singkat  3
Program C++ ini adalah demonstrasi yang dirancang untuk membandingkan dua cara menukar nilai antar elemen di dua matriks $3 \times 3$ yang berbeda, yaitu Matriks A dan Matriks B. Program memulai dengan fungsi tukarElemen, yang secara langsung menukar nilai elemen pada koordinat yang ditentukan (misalnya $A[0][0]$ dengan $B[0][0]$) melalui pemanggilan fungsi. Setelah itu, program menunjukkan metode yang lebih canggih menggunakan fungsi tukarPointer, di mana ia menukar nilai yang ditunjuk oleh pointer (ptr1 menunjuk $A[1][1]$ dan ptr2 menunjuk $B[2][2]$), membuktikan bahwa manipulasi nilai dalam matriks dapat dilakukan baik secara langsung melalui indeks maupun secara tidak langsung melalui alamat memori (pointer).

##### Output 1
![Screenshot Output 1](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-3/Output-3-1.jpg)

##### Output 2
![Screenshot Output 2](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-3/Output-3-2.jpg)

##### Output 3
![Screenshot Output 3](https://github.com/kyyyyraa/Struktur-Data-Assigment/blob/main/Modul-3/Output-3-3.jpg)


## Kesimpulan
...

## Referensi
[1]
<br>Chaniago, M. B., & Sastradipraja, C. K. (2022). Buku Ajar
Algoritma dan Struktur Data. Kaizen Media Publishing.

<br>
