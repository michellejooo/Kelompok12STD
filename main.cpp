#include <iostream>
#include <limits>
#include <string>
#include "fakultas.h"

using namespace std;

int main() {
    ListParent L;
    createList(L);

    int pil = 0;
    bool jalan = true;

    string jur, mat, jur2, mat2;

    while (jalan) {
        cout << "\n============================================\n";
        cout << " SISTEM MANAJEMEN JURUSAN DAN MATA KULIAH\n";
        cout << "============================================\n";

        cout << "1.  Tambahkan Jurusan\n";
        cout << "2.  Tambahkan Mata Kuliah ke Jurusan\n";
        cout << "3.  Tambahkan Mata Kuliah ke Jurusan Lain\n";
        cout << "4.  Hapus Jurusan\n";
        cout << "5.  Hapus Mata Kuliah dari Jurusan\n";
        cout << "6.  Hapus Relasi Jurusan dan Mata Kuliah\n";
        cout << "7.  Cari Jurusan\n";
        cout << "8.  Cari Mata Kuliah pada Jurusan\n";
        cout << "9.  Cari Relasi Jurusan dan Mata Kuliah\n";
        cout << "10. Tampilkan Semua Jurusan\n";
        cout << "11. Tampilkan Mata Kuliah dari Jurusan\n";
        cout << "12. Tampilkan Mata Kuliah dari Jurusan Tertentu\n";
        cout << "13. Tampilkan Jurusan yang Memiliki Mata Kuliah\n";
        cout << "14. Tampilkan Semua Relasi Jurusan - Mata Kuliah\n";
        cout << "15. Tampilkan Semua Relasi Mata Kuliah - Jurusan\n";
        cout << "16. Hitung Mata Kuliah dari Jurusan\n";
        cout << "17. Hitung Jurusan yang Memiliki Mata Kuliah\n";
        cout << "18. Hitung Mata Kuliah Tanpa Jurusan\n";
        cout << "19. Hitung Jurusan Tanpa Mata Kuliah\n";
        cout << "20. Edit Relasi Jurusan dan Mata Kuliah\n";
        cout << "0.  Keluar\n";

        cout << "Pilih menu: ";

        if (!(cin >> pil)) {
            cout << "Input harus berupa angka.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // 1. Insert Jurusan
        if (pil == 1) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            insertJurusan(L, jur);
        }

        // 2. Insert Mata Kuliah
        else if (pil == 2) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            insertMatkul(L, jur, mat);
        }

        // 3. Insert Mata Kuliah ke Jurusan Lain
        else if (pil == 3) {
            cout << "Nama jurusan tujuan: ";
            getline(cin, jur);

            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            insertMatkul(L, jur, mat);
        }

        // 4. Delete Jurusan
        else if (pil == 4) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            deleteJurusan(L, jur);
        }

        // 5. Delete Mata Kuliah
        else if (pil == 5) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            deleteMatkul(L, jur, mat);
        }

        // 6. Delete Relasi
        else if (pil == 6) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            deleteMatkul(L, jur, mat);
        }

        // 7. Search Jurusan
        else if (pil == 7) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            if (findJurusan(L, jur) != nullptr) {
                cout << "Jurusan ditemukan.\n";
            } else {
                cout << "Jurusan tidak ditemukan.\n";
            }
        }

        // 8. Search Mata Kuliah
        else if (pil == 8) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            adrParent P = findJurusan(L, jur);

            if (findMatkul(P, mat) != nullptr) {
                cout << "Mata kuliah ditemukan.\n";
            } else {
                cout << "Mata kuliah tidak ditemukan.\n";
            }
        }

        // 9. Search Relasi
        else if (pil == 9) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            if (findRelasi(L, jur, mat)) {
                cout << "Relasi ditemukan.\n";
            } else {
                cout << "Relasi tidak ditemukan.\n";
            }
        }

        // 10. Show Semua Jurusan
        else if (pil == 10) {
            showJurusan(L);
        }

        // 11. Show Mata Kuliah
        else if (pil == 11) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            showMatkul(L, jur);
        }

        // 12. Show Mata Kuliah dari Jurusan Tertentu
        else if (pil == 12) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            showMatkulFromJurusan(L, jur);
        }

        // 13. Show Jurusan dari Mata Kuliah
        else if (pil == 13) {
            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            showJurusanFromMatkul(L, mat);
        }

        // 14. Show Semua Relasi Jurusan - Mata Kuliah
        else if (pil == 14) {
            showAllJurusanMatkul(L);
        }

        // 15. Show Semua Relasi Mata Kuliah - Jurusan
        else if (pil == 15) {
            showAllMatkulJurusan(L);
        }

        // 16. Count Mata Kuliah dari Jurusan
        else if (pil == 16) {
            cout << "Nama jurusan: ";
            getline(cin, jur);

            int total = countChildFromParent(L, jur);

            if (total == -1) {
                cout << "Jurusan tidak ditemukan.\n";
            } else {
                cout << "Jumlah mata kuliah pada "
                     << jur << ": " << total << endl;
            }
        }

        // 17. Count Jurusan yang Memiliki Mata Kuliah
        else if (pil == 17) {
            cout << "Nama mata kuliah: ";
            getline(cin, mat);

            cout << "Jumlah jurusan yang memiliki "
                 << mat << ": "
                 << countParentFromChild(L, mat) << endl;
        }

        // 18. Count Mata Kuliah Tanpa Jurusan
        else if (pil == 18) {
            cout << "Jumlah mata kuliah tanpa jurusan: "
                 << countMatkulNoParent(L) << endl;

            cout << "(Pada model List to List, Child harus "
                 << "berada di bawah Parent.)\n";
        }

        // 19. Count Jurusan Tanpa Mata Kuliah
        else if (pil == 19) {
            cout << "Jumlah jurusan tanpa mata kuliah: "
                 << countJurusanNoChild(L) << endl;
        }

        // 20. Edit Relasi
        else if (pil == 20) {
            cout << "Jurusan lama: ";
            getline(cin, jur);

            cout << "Mata kuliah lama: ";
            getline(cin, mat);

            cout << "Jurusan baru: ";
            getline(cin, jur2);

            cout << "Nama mata kuliah baru: ";
            getline(cin, mat2);

            editRelasi(L, jur, mat, jur2, mat2);
        }

        // Exit
        else if (pil == 0) {
            jalan = false;
        }

        else {
            cout << "Pilihan tidak tersedia.\n";
        }
    }

    cout << "Program selesai.\n";

    return 0;
}
