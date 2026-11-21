#include "fakultas.h"
#include <iostream>
using namespace std;

// Inisialisasi List
void createList(ListParent &L) {
    L.first = nullptr;
}

// Mencari Jurusan
adrParent findJurusan(ListParent L, const string &jurusan) {
    adrParent P = L.first;

    while (P != nullptr) {
        if (P->namaJurusan == jurusan) {
            return P;
        }
        P = P->next;
    }

    return nullptr;
}

// Mencari Mata Kuliah pada Jurusan
adrChild findMatkul(adrParent P, const string &matkul) {
    if (P == nullptr) {
        return nullptr;
    }

    adrChild C = P->firstChild;

    while (C != nullptr) {
        if (C->namaMatkul == matkul) {
            return C;
        }
        C = C->next;
    }

    return nullptr;
}

// Menambahkan Jurusan
void insertJurusan(ListParent &L, const string &jurusan) {
    if (jurusan.empty()) {
        cout << "Nama jurusan tidak boleh kosong.\n";
        return;
    }

    if (findJurusan(L, jurusan) != nullptr) {
        cout << "Jurusan sudah terdaftar.\n";
        return;
    }

    adrParent P = new Parent;

    P->namaJurusan = jurusan;
    P->firstChild = nullptr;
    P->next = L.first;

    L.first = P;

    cout << "Jurusan berhasil ditambahkan.\n";
}

// Menambahkan Mata Kuliah ke Jurusan
void insertMatkul(ListParent &L, const string &jurusan,
                  const string &matkul) {
    adrParent P = findJurusan(L, jurusan);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan.\n";
        return;
    }

    if (matkul.empty()) {
        cout << "Nama mata kuliah tidak boleh kosong.\n";
        return;
    }

    if (findMatkul(P, matkul) != nullptr) {
        cout << "Mata kuliah sudah terdaftar pada jurusan ini.\n";
        return;
    }

    adrChild C = new Child;

    C->namaMatkul = matkul;
    C->next = P->firstChild;

    P->firstChild = C;

    cout << "Mata kuliah berhasil ditambahkan ke jurusan "
         << jurusan << ".\n";
}

// Menghapus Mata Kuliah dari Jurusan
void deleteMatkul(ListParent &L, const string &jurusan,
                  const string &matkul) {
    adrParent P = findJurusan(L, jurusan);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan.\n";
        return;
    }

    adrChild C = P->firstChild;
    adrChild prev = nullptr;

    while (C != nullptr && C->namaMatkul != matkul) {
        prev = C;
        C = C->next;
    }

    if (C == nullptr) {
        cout << "Mata kuliah tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr) {
        P->firstChild = C->next;
    } else {
        prev->next = C->next;
    }

    delete C;

    cout << "Mata kuliah berhasil dihapus.\n";
}

// Menghapus Jurusan beserta seluruh Mata Kuliahnya
void deleteJurusan(ListParent &L, const string &jurusan) {
    adrParent P = L.first;
    adrParent prev = nullptr;

    while (P != nullptr && P->namaJurusan != jurusan) {
        prev = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan.\n";
        return;
    }

    // Menghapus seluruh Child milik Parent
    adrChild C = P->firstChild;

    while (C != nullptr) {
        adrChild temp = C;
        C = C->next;
        delete temp;
    }

    // Menghapus Parent dari linked list
    if (prev == nullptr) {
        L.first = P->next;
    } else {
        prev->next = P->next;
    }

    delete P;

    cout << "Jurusan beserta seluruh mata kuliahnya berhasil dihapus.\n";
}

// Mencari Relasi Jurusan dan Mata Kuliah
bool findRelasi(ListParent L, const string &jurusan,
                const string &matkul) {
    adrParent P = findJurusan(L, jurusan);

    return findMatkul(P, matkul) != nullptr;
}

// Menampilkan Semua Jurusan
void showJurusan(ListParent L) {
    if (L.first == nullptr) {
        cout << "Belum ada jurusan yang terdaftar.\n";
        return;
    }

    cout << "\n=== DAFTAR JURUSAN ===\n";

    adrParent P = L.first;

    while (P != nullptr) {
        cout << "- " << P->namaJurusan << endl;
        P = P->next;
    }
}

// Menampilkan Mata Kuliah dari Jurusan
void showMatkul(ListParent L, const string &jurusan) {
    adrParent P = findJurusan(L, jurusan);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan.\n";
        return;
    }

    cout << "\nMata kuliah pada jurusan "
         << P->namaJurusan << ":\n";

    if (P->firstChild == nullptr) {
        cout << "Belum memiliki mata kuliah.\n";
        return;
    }

    adrChild C = P->firstChild;

    while (C != nullptr) {
        cout << "- " << C->namaMatkul << endl;
        C = C->next;
    }
}

// Menampilkan Mata Kuliah dari Jurusan
void showMatkulFromJurusan(ListParent L, const string &jurusan) {
    showMatkul(L, jurusan);
}

// Menampilkan Jurusan yang Memiliki Mata Kuliah
void showJurusanFromMatkul(ListParent L, const string &matkul) {
    if (L.first == nullptr) {
        cout << "Belum ada data jurusan.\n";
        return;
    }

    bool found = false;

    cout << "\nJurusan yang memiliki mata kuliah "
         << matkul << ":\n";

    adrParent P = L.first;

    while (P != nullptr) {
        if (findMatkul(P, matkul) != nullptr) {
            cout << "- " << P->namaJurusan << endl;
            found = true;
        }

        P = P->next;
    }

    if (!found) {
        cout << "Mata kuliah belum terdaftar pada jurusan mana pun.\n";
    }
}

// Menampilkan Semua Jurusan dan Mata Kuliah
void showAllJurusanMatkul(ListParent L) {
    showAll(L);
}

// Menampilkan Semua Mata Kuliah beserta Jurusannya
void showAllMatkulJurusan(ListParent L) {
    if (L.first == nullptr) {
        cout << "Belum ada data jurusan.\n";
        return;
    }

    cout << "\n=== SEMUA MATA KULIAH DAN JURUSANNYA ===\n";

    adrParent P = L.first;
    bool any = false;

    while (P != nullptr) {
        adrChild C = P->firstChild;

        while (C != nullptr) {
            cout << C->namaMatkul << " - "
                 << P->namaJurusan << endl;

            any = true;
            C = C->next;
        }

        P = P->next;
    }

    if (!any) {
        cout << "Belum ada mata kuliah yang terdaftar.\n";
    }
}

// Menampilkan Seluruh Data (Parent dan Child)
void showAll(ListParent L) {
    if (L.first == nullptr) {
        cout << "Belum ada data jurusan.\n";
        return;
    }

    cout << "\n=== SELURUH DATA JURUSAN DAN MATA KULIAH ===\n";

    adrParent P = L.first;

    while (P != nullptr) {
        cout << "\nJurusan: " << P->namaJurusan << endl;

        if (P->firstChild == nullptr) {
            cout << "  Belum memiliki mata kuliah.\n";
        } else {
            adrChild C = P->firstChild;

            while (C != nullptr) {
                cout << "  - " << C->namaMatkul << endl;
                C = C->next;
            }
        }

        P = P->next;
    }
}

// Menghitung Mata Kuliah pada Suatu Jurusan
int countChildFromParent(ListParent L, const string &jurusan) {
    adrParent P = findJurusan(L, jurusan);

    if (P == nullptr) {
        return -1;
    }

    int count = 0;
    adrChild C = P->firstChild;

    while (C != nullptr) {
        count++;
        C = C->next;
    }

    return count;
}

// Menghitung Jumlah Jurusan yang Memiliki Mata Kuliah
int countParentFromChild(ListParent L, const string &matkul) {
    int count = 0;
    adrParent P = L.first;

    while (P != nullptr) {
        if (findMatkul(P, matkul) != nullptr) {
            count++;
        }

        P = P->next;
    }

    return count;
}

// Menghitung Mata Kuliah Tanpa Jurusan
int countMatkulNoParent(ListParent L) {
    // Dalam model List to List, Child harus dimiliki Parent.
    // Jadi tidak ada Child yang berdiri sendiri.
    (void)L;
    return 0;
}

// Menghitung Jurusan Tanpa Mata Kuliah
int countJurusanNoChild(ListParent L) {
    int count = 0;
    adrParent P = L.first;

    while (P != nullptr) {
        if (P->firstChild == nullptr) {
            count++;
        }

        P = P->next;
    }

    return count;
}

// Mengubah Relasi Jurusan dan Mata Kuliah
void editRelasi(ListParent &L,
                const string &oldJurusan,
                const string &oldMatkul,
                const string &newJurusan,
                const string &newMatkul) {

    adrParent oldP = findJurusan(L, oldJurusan);
    adrParent newP = findJurusan(L, newJurusan);

    if (oldP == nullptr) {
        cout << "Jurusan lama tidak ditemukan.\n";
        return;
    }

    if (newP == nullptr) {
        cout << "Jurusan baru tidak ditemukan.\n";
        return;
    }

    if (findMatkul(oldP, oldMatkul) == nullptr) {
        cout << "Mata kuliah lama tidak ditemukan pada jurusan lama.\n";
        return;
    }

    if (newMatkul.empty()) {
        cout << "Nama mata kuliah baru tidak boleh kosong.\n";
        return;
    }

    if (oldP == newP && oldMatkul == newMatkul) {
        cout << "Data relasi tidak mengalami perubahan.\n";
        return;
    }

    if (findMatkul(newP, newMatkul) != nullptr) {
        cout << "Mata kuliah baru sudah terdaftar pada jurusan tujuan.\n";
        return;
    }

    // Menghapus Child lama dari Parent asal
    adrChild C = oldP->firstChild;
    adrChild prev = nullptr;

    while (C != nullptr && C->namaMatkul != oldMatkul) {
        prev = C;
        C = C->next;
    }

    if (prev == nullptr) {
        oldP->firstChild = C->next;
    } else {
        prev->next = C->next;
    }

    delete C;

    // Menambahkan Child baru ke Parent tujuan
    adrChild newC = new Child;

    newC->namaMatkul = newMatkul;
    newC->next = newP->firstChild;

    newP->firstChild = newC;

    cout << "Data mata kuliah berhasil diperbarui.\n";
}
