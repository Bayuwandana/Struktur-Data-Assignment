# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (1)</h1>
<p align="center">Bayu Wandana - 103112430159</p>

## Dasar Teori
Materi ini berfungsi sebagai pengantar penggunaan Code::Blocks, sebuah aplikasi gratis yang berfungsi sebagai tempat untuk menulis, mengedit, dan menjalankan program dalam bahasa C++. Anda akan dipandu melalui langkah-langkah praktis, dimulai dari instalasi, cara membuat proyek baru, penulisan kode, hingga menjalankan program tersebut. Bagian ini juga penting untuk belajar mengatasi masalah umum; Anda akan diajari cara menggunakan fitur "Clean project" jika program tidak bisa berjalan, serta bagaimana cara membaca dan memahami pesan kesalahan (error) dari komputer saat ada kesalahan penulisan kode.

Selanjutnya, Anda akan mempelajari konsep dasar dalam pemrograman C++. Materi ini mencakup pemahaman struktur dasar program, pengenalan berbagai jenis data—seperti int untuk bilangan bulat dan float untuk bilangan desimal—dan cara menggunakan variabel untuk menyimpan nilai-nilai tersebut. Selain itu, Anda akan mempelajari operator untuk perhitungan matematika dan logika, serta konsep penting mengenai kontrol alur program, yaitu menggunakan pernyataan kondisional (if-else, switch) agar program dapat membuat keputusan, dan menggunakan perulangan (for, while, do-while) untuk menjalankan perintah yang sama secara berulang kali.

### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nPenjumlahan : " << a + b << endl;
    cout << "Pengurangan : " << a - b << endl;
    cout << "Perkalian   : " << a * b << endl;
    cout << "Pembagian   : " << a / b << endl;

    return 0;
}

```
Penjelasan singkat 1
Program C++ ini berfungsi sebagai kalkulator dasar yang dirancang untuk melakukan empat operasi aritmatika pada dua bilangan yang dimasukkan oleh pengguna. Program akan meminta pengguna memasukkan bilangan pertama dan kedua, yang disimpan sebagai tipe data desimal (float). Setelah menerima input, program akan segera menghitung dan menampilkan hasil dari penjumlahan, pengurangan, perkalian, dan pembagian kedua bilangan tersebut secara berurutan.


### 2. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int angka;

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100 ) {
        cout << "Angka di luar jangkauan" << endl;

        return 0;
    }

    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam",  "tujuh", "delapan", "sembilan"};
    string belasan[] = {"Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas", "Tujuh Belas", "Delapan Belas", "Sembilan Belas"};
    string puluhan[] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

    if (angka == 0) {
        cout << "Nol" << endl;
    } else if (angka == 100) {
        cout << "Seratus" << endl;
    } else if (angka >= 10 && angka < 20) {
        cout << belasan[angka - 10] << endl;
    } else {
        int puluh = angka / 10;
        int satu = angka % 10;

        if (puluh > 0) cout << puluhan[puluh];
        if (puluh > 0 && satu > 0) cout << " ";
        if (satu >  0) cout << satuan[satu];
        cout << endl;
    }
    return 0;
}

```
penjelasan singkat 2
PProgram $\text{C++}$ ini adalah sebuah konverter angka yang menerima masukan angka bulat dari $0$ hingga $100$ dari pengguna, lalu menggunakan larik kamus $\text{string}$ ($\text{satuan, belasan, puluhan}$) serta logika $\text{if-else}$ untuk menerjemahkan dan menampilkan angka tersebut ke dalam bentuk kata-kata Bahasa Indonesia (misalnya, angka $45$ dikonversi menjadi "Empat Puluh Lima").

### 3. ...

```C++

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    cout << "Output:" << endl;

    for (int i = n; i >= 1; i--) {
        for (int s = n; s > i; s--) {
            cout << "  ";
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j;
            if (j < i) cout << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}



```
penjelasan singkat  3
Program $\text{C++}$ ini menerima sebuah angka bulat positif ($n$) dari pengguna, lalu menggunakan perulangan bersarang untuk mencetak sebuah pola visual berbentuk piramida terbalik yang simetris, di mana setiap barisnya dimulai dengan spasi untuk indentasi, diikuti oleh urutan angka dari $n$ menurun hingga $1$, dipisahkan oleh simbol bintang ($\mathbf{*}$), dan diakhiri dengan urutan angka dari $1$ menaik hingga $n$, sebelum pola ditutup dengan sebuah bintang tunggal di puncaknya.
##### Output 1
![Screenshot Output 1](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/main/MODUL%201/output1-1.png)

##### Output 2
![Screenshot Output 2](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/main/MODUL%201/output%201-2.png)

##### Output 3
![Screenshot Output 3](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/main/MODUL%201/output1-3.png)


## Kesimpulan
Ketiga kode C++ yang diberikan menunjukkan aplikasi dasar dari struktur pemrograman. Kode pertama adalah kalkulator yang memproses dua angka desimal untuk menampilkan hasil empat operasi dasar. Kode kedua adalah konverter yang mengubah angka 0 hingga 100 menjadi bentuk terbilang menggunakan array dan logika kondisional. Sementara itu, kode ketiga adalah contoh penggunaan perulangan bersarang untuk menggambar pola piramida terbalik simetris yang tinggi dan bentuknya ditentukan oleh input pengguna.

## Referensi
[1]
<br>Raharjo, B. (2020). Pemrograman C++ Dasar: Konsep dan Implementasi. Penerbit Informatika.

<br>
