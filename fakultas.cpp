
#include "fakultas.h"
#include <iostream>
#include <new>
using namespace std;

// ==============================
// INISIALISASI
// ==============================

void createList(ListParent &L) {
    L.first = nullptr;
}

bool isEmpty(ListParent L) {
    return L.first == nullptr;
}

// ==============================
// OPERASI PARENT
// ==============================

// Insert Jurusan
void insertJurusan(ListParent &L, string jurusan) {
    adrParent P = nullptr;
    findJurusan(L, jurusan, P);

    if (jurusan == "") {
        cout << "Nama jurusan tidak boleh kosong!" << endl;
    } else if (P != nullptr) {
        cout << "Jurusan sudah ada!" << endl;
    } else {
        P = new (nothrow) Parent;

        if (P == nullptr) {
            cout << "Memori tidak mencukupi!" << endl;
        } else {
            P->namaJurusan = jurusan;
            P->next = nullptr;
            P->firstChild = nullptr;

            if (isEmpty(L)) {
                L.first = P;
            } else {
                adrParent Q = L.first;

                while (Q->next != nullptr) {
                    Q = Q->next;
                }

                Q->next = P;
            }

            cout << "Jurusan berhasil ditambahkan!" << endl;
        }
    }
}

// Delete Jurusan
void deleteJurusan(ListParent &L, string jurusan) {
    adrParent P = nullptr;
    findJurusan(L, jurusan, P);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan!" << endl;
    } else {
        if (P == L.first) {
            L.first = P->next;
        } else {
            adrParent Q = L.first;

            while (Q->next != P) {
                Q = Q->next;
            }

            Q->next = P->next;
        }

        // Hapus seluruh Child milik Parent
        adrChild C = P->firstChild;

        while (C != nullptr) {
            adrChild tempChild = C;
            C = C->next;
            delete tempChild;
        }

        adrParent tempParent = P;
        delete tempParent;

        cout << "Jurusan berhasil dihapus!" << endl;
    }
}

// Find Jurusan
void findJurusan(ListParent L, string jurusan, adrParent &P) {
    P = L.first;

    while (P != nullptr && P->namaJurusan != jurusan) {
        P = P->next;
    }
}

// Show Jurusan
void showJurusan(ListParent L) {
    if (isEmpty(L)) {
        cout << "Belum ada data jurusan." << endl;
    } else {
        adrParent P = L.first;
        int i = 1;

        cout << "\n=== DAFTAR JURUSAN ===" << endl;

        while (P != nullptr) {
            cout << i << ". " << P->namaJurusan << endl;
            P = P->next;
            i++;
        }
    }
}

// ==============================
// OPERASI CHILD
// ==============================

// Insert Mata Kuliah
void insertMatkul(ListParent &L, string jurusan, string matkul) {
    adrParent P = nullptr;
    findJurusan(L, jurusan, P);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan!" << endl;
    } else if (matkul == "") {
        cout << "Nama mata kuliah tidak boleh kosong!" << endl;
    } else {
        adrChild C = nullptr;
        findMatkul(P, matkul, C);

        if (C != nullptr) {
            cout << "Mata kuliah sudah terdaftar di jurusan tersebut!" << endl;
        } else {
            C = new (nothrow) Child;

            if (C == nullptr) {
                cout << "Memori tidak mencukupi!" << endl;
            } else {
                C->namaMatkul = matkul;
                C->next = nullptr;

                if (P->firstChild == nullptr) {
                    P->firstChild = C;
                } else {
                    adrChild Q = P->firstChild;

                    while (Q->next != nullptr) {
                        Q = Q->next;
                    }

                    Q->next = C;
                }

                cout << "Mata kuliah berhasil ditambahkan!" << endl;
            }
        }
    }
}

// Delete Mata Kuliah
void deleteMatkul(ListParent &L, string jurusan, string matkul) {
    adrParent P = nullptr;
    findJurusan(L, jurusan, P);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan!" << endl;
    } else {
        adrChild C = nullptr;
        findMatkul(P, matkul, C);

        if (C == nullptr) {
            cout << "Mata kuliah tidak ditemukan!" << endl;
        } else {
            if (C == P->firstChild) {
                P->firstChild = C->next;
            } else {
                adrChild Q = P->firstChild;

                while (Q->next != C) {
                    Q = Q->next;
                }

                Q->next = C->next;
            }

            adrChild tempChild = C;
            delete tempChild;

            cout << "Mata kuliah berhasil dihapus!" << endl;
        }
    }
}

// Find Mata Kuliah
void findMatkul(adrParent P, string matkul, adrChild &C) {
    C = nullptr;

    if (P != nullptr) {
        C = P->firstChild;

        while (C != nullptr && C->namaMatkul != matkul) {
            C = C->next;
        }
    }
}

// Show Mata Kuliah
void showMatkul(ListParent L, string jurusan) {
    adrParent P = nullptr;
    findJurusan(L, jurusan, P);

    if (P == nullptr) {
        cout << "Jurusan tidak ditemukan!" << endl;
    } else if (P->firstChild == nullptr) {
        cout << "Jurusan belum memiliki mata kuliah." << endl;
    } else {
        adrChild C = P->firstChild;

        cout << "\nMata kuliah jurusan " << P->namaJurusan << ":" << endl;

        while (C != nullptr) {
            cout << "- " << C->namaMatkul << endl;
            C = C->next;
        }
    }
}

// ==============================
// OPERASI RELASI
// ==============================

// Find Relasi
bool findRelasi(ListParent L, string jurusan, string matkul) {
    adrParent P = nullptr;
    adrChild C = nullptr;
    bool found = false;

    findJurusan(L, jurusan, P);

    if (P != nullptr) {
        findMatkul(P, matkul, C);

        if (C != nullptr) {
            found = true;
        }
    }

    return found;
}

// Menampilkan Mata Kuliah dari Jurusan
void showMatkulFromJurusan(ListParent L, string jurusan) {
    showMatkul(L, jurusan);
}

// Menampilkan Jurusan dari Mata Kuliah
void showJurusanFromMatkul(ListParent L, string matkul) {
    if (isEmpty(L)) {
        cout << "Belum ada data jurusan." << endl;
    } else {
        adrParent P = L.first;
        bool found = false;

        cout << "\nJurusan yang memiliki mata kuliah "
             << matkul << ":" << endl;

        while (P != nullptr) {
            adrChild C = nullptr;
            findMatkul(P, matkul, C);

            if (C != nullptr) {
                cout << "- " << P->namaJurusan << endl;
                found = true;
            }

            P = P->next;
        }

        if (found == false) {
            cout << "Mata kuliah tidak ditemukan." << endl;
        }
    }
}

// Menampilkan seluruh Jurusan beserta Mata Kuliah
void showAllJurusanMatkul(ListParent L) {
    showAll(L);
}

// Menampilkan seluruh Mata Kuliah beserta Jurusan
void showAllMatkulJurusan(ListParent L) {
    if (isEmpty(L)) {
        cout << "Belum ada data jurusan." << endl;
    } else {
        adrParent P = L.first;

        cout << "\n=== SELURUH MATA KULIAH DAN JURUSAN ===" << endl;

        while (P != nullptr) {
            adrChild C = P->firstChild;

            while (C != nullptr) {
                cout << C->namaMatkul
                     << " - " << P->namaJurusan << endl;

                C = C->next;
            }

            P = P->next;
        }
    }
}

// Print All
void showAll(ListParent L) {
    if (isEmpty(L)) {
        cout << "Data jurusan masih kosong." << endl;
    } else {
        adrParent P = L.first;
        int i = 1;

        cout << "\n=== DATA SELURUH JURUSAN DAN MATA KULIAH ===" << endl;

        while (P != nullptr) {
            cout << "\n" << i << ". Jurusan: "
                 << P->namaJurusan << endl;

            if (P->firstChild == nullptr) {
                cout << "   Belum memiliki mata kuliah." << endl;
            } else {
                adrChild C = P->firstChild;

                while (C != nullptr) {
                    cout << "   - " << C->namaMatkul << endl;
                    C = C->next;
                }
            }

            P = P->next;
            i++;
        }
    }
}

// ==============================
// PERHITUNGAN
// ==============================

// Menghitung jumlah Child dari Parent
int countChildFromParent(ListParent L, string jurusan) {
    int total = 0;
    adrParent P = nullptr;

    findJurusan(L, jurusan, P);

    if (P != nullptr) {
        adrChild C = P->firstChild;

        while (C != nullptr) {
            total++;
            C = C->next;
        }
    }

    return total;
}

// Menghitung jumlah Parent yang memiliki Child tertentu
int countParentFromChild(ListParent L, string matkul) {
    int total = 0;
    adrParent P = L.first;

    while (P != nullptr) {
        adrChild C = nullptr;
        findMatkul(P, matkul, C);

        if (C != nullptr) {
            total++;
        }

        P = P->next;
    }

    return total;
}

// Menghitung Mata Kuliah tanpa Parent
int countMatkulNoParent(ListParent L) {
    // Dalam struktur List to List,
    // Child selalu berada di dalam Parent.
    // Jadi tidak ada Child tanpa Parent.
    return 0;
}

// Menghitung Jurusan tanpa Child
int countJurusanNoChild(ListParent L) {
    int total = 0;
    adrParent P = L.first;

    while (P != nullptr) {
        if (P->firstChild == nullptr) {
            total++;
        }

        P = P->next;
    }

    return total;
}

// ==============================
// EDIT RELASI
// ==============================

void editRelasi(ListParent &L,
                string oldJurusan,
                string oldMatkul,
                string newJurusan,
                string newMatkul) {

    adrParent POld = nullptr;
    adrParent PNew = nullptr;
    adrChild C = nullptr;
    adrChild CNew = nullptr;

    findJurusan(L, oldJurusan, POld);
    findJurusan(L, newJurusan, PNew);

    if (POld == nullptr) {
        cout << "Jurusan asal tidak ditemukan!" << endl;
    } else if (PNew == nullptr) {
        cout << "Jurusan tujuan tidak ditemukan!" << endl;
    } else {
        findMatkul(POld, oldMatkul, C);

        if (C == nullptr) {
            cout << "Mata kuliah asal tidak ditemukan!" << endl;
        } else {
            findMatkul(PNew, newMatkul, CNew);

            if (CNew != nullptr) {
                cout << "Mata kuliah sudah ada di jurusan tujuan!" << endl;
            } else {
                // Lepaskan Child dari Parent lama
                if (C == POld->firstChild) {
                    POld->firstChild = C->next;
                } else {
                    adrChild Q = POld->firstChild;

                    while (Q->next != C) {
                        Q = Q->next;
                    }

                    Q->next = C->next;
                }

                // Ubah nama mata kuliah
                C->namaMatkul = newMatkul;
                C->next = nullptr;

                // Masukkan Child ke Parent baru
                if (PNew->firstChild == nullptr) {
                    PNew->firstChild = C;
                } else {
                    adrChild Q = PNew->firstChild;

                    while (Q->next != nullptr) {
                        Q = Q->next;
                    }

                    Q->next = C;
                }

                cout << "Relasi berhasil diedit!" << endl;
            }
        }
    }
}
