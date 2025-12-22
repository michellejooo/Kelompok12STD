#include <iostream>
#include <string>
#include "fakultas.h"
using namespace std;

int main() {
    ListParent LP;
    ListChild LC;
    ListRelasi LR;
    createList(LP, LC, LR);

    int pil;
    string jur, mat, jur2, mat2;

    while (true) {
        cout << "\nSelamat Datang di List Fakultas Informatika" << endl;
        cout << "1  Insert Jurusan\n";
        cout << "2  Insert Matkul\n";
        cout << "3  Insert Relasi\n";
        cout << "4  Delete Jurusan\n";
        cout << "5  Delete Matkul\n";
        cout << "6  Delete Relasi\n";
        cout << "7  Find Jurusan\n";
        cout << "8  Find Matkul\n";
        cout << "9  Find Relasi\n";
        cout << "10 Show All Jurusan\n";
        cout << "11 Show All Matkul\n";
        cout << "12 Show Matkul dari Jurusan\n";
        cout << "13 Show Jurusan dari Matkul\n";
        cout << "14 Show Semua Relasi Jurusan + Matkul\n";
        cout << "15 Show Semua Relasi Matkul + Jurusan\n";
        cout << "16 Count Matkul dari Jurusan\n";
        cout << "17 Count Jurusan dari Matkul\n";
        cout << "18 Count Matkul tanpa Jurusan\n";
        cout << "19 Count Jurusan tanpa Matkul\n";
        cout << "20 Edit Relasi\n";
        cout << "Pilih angka : ";

        if (!(cin >> pil)) {
             break; // Ini satu-satunya break untuk menghentikan loop while
        }
        cin.ignore(); // Membersihkan sisa 'Enter' agar getline tidak terlewati

        // MENGGANTI SWITCH-CASE DENGAN IF-ELSE IF (TANPA BREAK)
        if (pil == 1) {
            cout << "Nama Jurusan: "; getline(cin, jur);
            insertJurusan(LP, jur);
        }
        else if (pil == 2) {
            cout << "Nama Matkul: "; getline(cin, mat);
            insertMatkul(LC, mat);
        }
        else if (pil == 3) {
            cout << "Jurusan: "; getline(cin, jur);
            cout << "Matkul: "; getline(cin, mat);
            Parent *P = findJurusan(LP, jur);
            Child *C = findMatkul(LC, mat);
            if (!P) cout << "Jurusan tidak ada" << endl;
            else if (!C) cout << "Matkul tidak ada" << endl;
            else insertRelasi(LR, P, C);
        }
        else if (pil == 4) {
            cout << "Nama Jurusan: "; getline(cin, jur);
            deleteJurusan(LP, LR, jur);
        }
        else if (pil == 5) {
            cout << "Nama Matkul: "; getline(cin, mat);
            deleteMatkul(LC, LR, mat);
        }
        else if (pil == 6) {
            cout << "Jurusan: "; getline(cin, jur);
            cout << "Matkul: "; getline(cin, mat);
            deleteRelasi(LR, jur, mat);
        }
        else if (pil == 7) {
            cout << "Nama Jurusan: "; getline(cin, jur);
            if (findJurusan(LP, jur)) cout << "Jurusan ditemukan" << endl;
            else cout << "Jurusan tidak ada" << endl;
        }
        else if (pil == 8) {
            cout << "Nama Matkul: "; getline(cin, mat);
            if (findMatkul(LC, mat)) cout << "Matkul ditemukan" << endl;
            else cout << "Matkul tidak ada" << endl;
        }
        else if (pil == 9) {
            cout << "Jurusan: "; getline(cin, jur);
            cout << "Matkul: "; getline(cin, mat);
            if (findRelasi(LR, jur, mat)) cout << "Ada relasi" << endl;
            else cout << "Tidak ada relasi" << endl;
        }
        else if (pil == 10) {
            showJurusan(LP);
        }
        else if (pil == 11) {
            showMatkul(LC);
        }
       else if (pil == 12) {
    cout << "Jurusan: "; getline(cin, jur);
    showMatkulFromJurusan(LP, LR, jur); // Pastikan LP dimasukkan di sini
}
        else if (pil == 13) {
    cout << "Matkul: "; getline(cin, mat);
    showJurusanFromMatkul(LC, LR, mat); // Tambahkan LC di sini
}
        else if (pil == 14) {
            showAllJurusanMatkul(LR);
        }
        else if (pil == 15) {
            showAllMatkulJurusan(LR);
        }
        else if (pil == 16) {
            cout << "Jurusan: "; getline(cin, jur);
            cout << "Total Matkul di " << jur << ": " << countChildFromParent(LR, jur) << endl;
        }
        else if (pil == 17) {
            cout << "Matkul: "; getline(cin, mat);
            cout << "Total Jurusan ambil " << mat << ": " << countParentFromChild(LR, mat) << endl;
        }
        else if (pil == 18) {
            cout << "Total Matkul tanpa Jurusan terdaftar: " << countMatkulNoParent(LC, LR) << endl;
        }
        else if (pil == 19) {
            cout << "Total Jurusan tanpa Matkul terdaftar: " << countJurusanNoChild(LP, LR) << endl;
        }
        else if (pil == 20) {
            cout << "Jurusan lama: "; getline(cin, jur);
            cout << "Matkul lama: "; getline(cin, mat);
            cout << "Jurusan baru: "; getline(cin, jur2);
            cout << "Matkul baru: "; getline(cin, mat2);
            Parent *P = findJurusan(LP, jur2);
            Child *C = findMatkul(LC, mat2);
            if (!P || !C) cout << "Jurusan/Matkul baru tidak ada" << endl;
            else editRelasi(LR, jur, mat, P, C);
        }
    }

    return 0;
}
