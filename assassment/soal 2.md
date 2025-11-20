# <h1 align="center">Laporan ASESMEN 1 PRAKTIKUM STRUKTUR DATA </h1>
<p align="center">Bayu Wandana - 103112430159</p>


### 3. ...

```C++
#include <iostream> 
using namespace std; 
 
struct Mahasiswa { 
    string Nama; 
    string NIM; 
    float NilaiTugas; 
    float NilaiUTS; 
    float NilaiUAS; 
}; 
 
const int MAX = 6; 
 
struct StackMahasiswa { 
    Mahasiswa dataMahasiswa[MAX]; 
    int Top; 
}; 
 
bool isEmpty(StackMahasiswa &StackMHS) { 
    return StackMHS.Top == -1; 
} 
 
bool isFull(StackMahasiswa &StackMHS) { 
    return StackMHS.Top == MAX - 1; 
} 
 
void createStack(StackMahasiswa &StackMHS) { 
    StackMHS.Top = -1; 
} 
 
void Push(StackMahasiswa &StackMHS, Mahasiswa dataBaru) { 
    if (isFull(StackMHS)) { 
        cout << "Stack penuh!\n"; 
        return; 
    } 
    StackMHS.Top++; 
    StackMHS.dataMahasiswa[StackMHS.Top] = dataBaru; 
} 
 
void Pop(StackMahasiswa &StackMHS) { 
    if (isEmpty(StackMHS)) { 
        cout << "Stack kosong!\n"; 
        return; 
    } 
    StackMHS.Top--; 
} 
 
void Update(StackMahasiswa &StackMHS, int posisi, Mahasiswa dataBaru) { 
    if (posisi < 1 || posisi > StackMHS.Top + 1) { 
        cout << "Posisi tidak valid!\n"; 
        return; 
    } 
    StackMHS.dataMahasiswa[posisi - 1] = dataBaru; 
} 
 
float hitungNilaiAkhir(Mahasiswa M) { 
    return 0.2 * M.NilaiTugas + 0.4 * M.NilaiUTS + 0.4 * M.NilaiUAS; 
} 
 
void View(StackMahasiswa &StackMHS) { 
    if (isEmpty(StackMHS)) { 
        cout << "Stack kosong!\n"; 
        return; 
    } 
    for (int i = StackMHS.Top; i >= 0; i--) { 
        Mahasiswa &m = StackMHS.dataMahasiswa[i]; 
        cout << "Posisi " << i+1 << ":\n"; 
        cout << "Nama: " << m.Nama << "\n"; 
        cout << "NIM: " << m.NIM << "\n"; 
        cout << "Nilai Tugas: " << m.NilaiTugas << "\n"; 
        cout << "Nilai UTS: " << m.NilaiUTS << "\n"; 
        cout << "Nilai UAS: " << m.NilaiUAS << "\n"; 
        cout << "Nilai Akhir: " << hitungNilaiAkhir(m) << "\n\n"; 
    } 
} 
 
void SearchNilaiAkhir(StackMahasiswa &StackMHS, float Min, float Max) { 
    bool found = false; 
 
    for (int i = 0; i <= StackMHS.Top; i++) { 
        float nilai = hitungNilaiAkhir(StackMHS.dataMahasiswa[i]); 
        if (nilai >= Min && nilai <= Max) { 
            found = true; 
            cout << "Ditemukan pada posisi " << i + 1 << ":\n"; 
            cout << "Nama: " << StackMHS.dataMahasiswa[i].Nama << "\n"; 
            cout << "NIM: " << StackMHS.dataMahasiswa[i].NIM << "\n"; 
            cout << "Nilai Akhir: " << nilai << "\n\n"; 
        } 
    } 
 
    if (!found) { 
        cout << "Tidak ada mahasiswa dengan nilai dalam rentang tersebut.\n"; 
    } 
} 
 
void MaxNilaiAkhir(StackMahasiswa &StackMHS) { 
    if (isEmpty(StackMHS)) { 
        cout << "Stack kosong!\n"; 
        return; 
    } 
 
    int idxMax = 0; 
    float maxNilai = hitungNilaiAkhir(StackMHS.dataMahasiswa[0]); 
 
    for (int i = 1; i <= StackMHS.Top; i++) { 
        float nilai = hitungNilaiAkhir(StackMHS.dataMahasiswa[i]); 
        if (nilai > maxNilai) { 
            maxNilai = nilai; 
            idxMax = i; 
        } 
    } 
 
    cout << "Mahasiswa dengan nilai akhir tertinggi:\n"; 
    cout << "Posisi: " << idxMax + 1 << "\n"; 
    cout << "Nama: " << StackMHS.dataMahasiswa[idxMax].Nama << "\n"; 
    cout << "NIM: " << StackMHS.dataMahasiswa[idxMax].NIM << "\n"; 
    cout << "Nilai Akhir: " << maxNilai << "\n\n"; 
} 
 
int main() { 
 
    StackMahasiswa S; 
    createStack(S); 
 
    Mahasiswa M1 = {"bayu", "11111", 75.7, 82.1, 65.5}; 
    Mahasiswa M2 = {"tedy", "22222", 87.4, 88.9, 81.9}; 
    Mahasiswa M3 = {"zakku", "33333", 92.3, 88.8, 82.4}; 
    Mahasiswa M4 = {"rasya", "44444", 95.5, 85.5, 90.5}; 
    Mahasiswa M5 = {"hamdu", "55555", 77.7, 65.4, 79.9}; 
    Mahasiswa M6 = {"tio", "66666", 99.9, 93.6, 87.3}; 
 
    Push(S, M1); 
    Push(S, M2); 
    Push(S, M3); 
    Push(S, M4); 
    Push(S, M5); 
    Push(S, M6); 
 
    cout << "=== DATA STACK AWAL ===\n"; 
    View(S); 
 
    Pop(S); 
 
    cout << "=== DATA SETELAH POP 1X ===\n"; 
    View(S); 
 
    Mahasiswa Up = {"bayu", "77777", 99.9, 88.8, 77.7}; 
    Update(S, 3, Up); 
 
    cout << "=== DATA SETELAH UPDATE POSISI 3 ===\n"; 
    View(S); 
 
    cout << "=== SEARCH NILAI AKHIR (85.5 - 95.5) ===\n"; 
    SearchNilaiAkhir(S, 85.5, 95.5); 
 
    cout << "=== MAHASISWA NILAI AKHIR TERTINGGI ===\n"; 
    MaxNilaiAkhir(S); 
 
    return 0; 
} 
```
##### Output 3
![Screenshot Output 1](https://github.com/Bayuwandana/Struktur-Data-Assignment/blob/c824c104eb3c2abe22845d04d89061ce998e0523/assassment/soal%201.png)

