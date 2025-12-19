#include "fakultas.h"
#include <iostream>
#include <string>
using namespace std;

void createList(ListParent &LP, ListChild &LC, ListRelasi &LR) {
    LP.first = NULL;
    LC.first = NULL;
    LR.first = NULL;
}

void insertJurusan(ListParent &LP, string jurusan) {
    Parent *P = new Parent{jurusan, LP.first};
    LP.first = P;
    cout << "Jurusan '" << jurusan << "' sudah dibuat" << endl;
}

void insertMatkul(ListChild &LC, string matkul) {
    Child *C = new Child{matkul, LC.first};
    LC.first = C;
    cout << "Mata Kuliah '" << matkul << "' sudah dibuat" << endl;
}

Parent* findJurusan(ListParent LP, string jurusan) {
    Parent *P = LP.first;
    while (P) {
        if (P->namaJurusan == jurusan) return P;
        P = P->next;
    }
    return NULL;
}

Child* findMatkul(ListChild LC, string matkul) {
    Child *C = LC.first;
    while (C) {
        if (C->namaMatkul == matkul) return C;
        C = C->next;
    }
    return NULL;
}

void insertRelasi(ListRelasi &LR, Parent *P, Child *C) {
    Relasi *R = new Relasi{P, C, LR.first};
    LR.first = R;
    cout << "Relasi " << P->namaJurusan << " - " << C->namaMatkul << " sudah dibuat" << endl;
}

bool findRelasi(ListRelasi LR, string jurusan, string matkul) {
    Relasi *R = LR.first;
    while (R) {
        if (R->parent->namaJurusan == jurusan &&
            R->child->namaMatkul == matkul)
            return true;
        R = R->next;
    }
    return false;
}

void deleteRelasi(ListRelasi &LR, string jurusan, string matkul) {
    Relasi *R = LR.first, *prev = NULL;
    while (R) {
        if (R->parent->namaJurusan == jurusan &&
            R->child->namaMatkul == matkul) {
            if (prev == NULL) LR.first = R->next;
            else prev->next = R->next;
            delete R;
            cout << "Relasi dihapus" << endl;
            return;
        }
        prev = R;
        R = R->next;
    }
    cout << "Tidak ada relasi antara jurusan dan matkul ini" << endl;
}

void deleteJurusan(ListParent &LP, ListRelasi &LR, string jurusan) {
    Parent *P = LP.first, *prev = NULL;
    while (P) {
        if (P->namaJurusan == jurusan) {
            if (prev == NULL) LP.first = P->next;
            else prev->next = P->next;
            delete P;
            cout << "Jurusan dihapus" << endl;
            return;
        }
        prev = P;
        P = P->next;
    }
    cout << "Jurusan tidak ada" << endl;
}

void deleteMatkul(ListChild &LC, ListRelasi &LR, string matkul) {
    Child *C = LC.first, *prev = NULL;
    while (C) {
        if (C->namaMatkul == matkul) {
            if (prev == NULL) LC.first = C->next;
            else prev->next = C->next;
            delete C;
            cout << "Matkul dihapus" << endl;
            return;
        }
        prev = C;
        C = C->next;
    }
    cout << "Matkul tidak ada" << endl;
}

void showJurusan(ListParent LP) {
    Parent *P = LP.first;
    cout << "--- Daftar Jurusan ---" << endl;
    while (P) {
        cout << P->namaJurusan << endl;
        P = P->next;
    }
    cout << "----------------------" << endl;
}

void showMatkul(ListChild LC) {
    Child *C = LC.first;
    cout << "--- Daftar Mata Kuliah ---" << endl;
    while (C) {
        cout << C->namaMatkul << endl;
        C = C->next;
    }
    cout << "--------------------------" << endl;
}

void showRelasi(ListRelasi LR) {
    Relasi *R = LR.first;
    while (R) {
        cout << R->parent->namaJurusan << " - "
             << R->child->namaMatkul << endl;
        R = R->next;
    }
}

void showMatkulFromJurusan(ListRelasi LR, string jurusan) {
    Relasi *R = LR.first;
    bool ada = false;
    cout << "Mata Kuliah di " << jurusan << ":" << endl;
    while (R) {
        if (R->parent->namaJurusan == jurusan) {
            cout << R->child->namaMatkul << endl;
            ada = true;
        }
        R = R->next;
    }
    if (!ada) cout << "Jurusan ini tidak punya matkul terdaftar" << endl;
}

void showJurusanFromMatkul(ListRelasi LR, string matkul) {
    Relasi *R = LR.first;
    bool ada = false;
    cout << "Jurusan yang mengambil " << matkul << ":" << endl;
    while (R) {
        if (R->child->namaMatkul == matkul) {
            cout << R->parent->namaJurusan << endl;
            ada = true;
        }
        R = R->next;
    }
    if (!ada) cout << "Matkul ini tidak punya jurusan terdaftar" << endl;
}

void showAllJurusanMatkul(ListRelasi LR) {
    cout << "--- Semua Relasi Jurusan - Matkul ---" << endl;
    showRelasi(LR);
    cout << "-------------------------------------" << endl;
}

void showAllMatkulJurusan(ListRelasi LR) {
    showAllJurusanMatkul(LR);
}

int countChildFromParent(ListRelasi LR, string jurusan) {
    int count = 0;
    Relasi *R = LR.first;
    while (R) {
        if (R->parent->namaJurusan == jurusan) count++;
        R = R->next;
    }
    return count;
}

int countParentFromChild(ListRelasi LR, string matkul) {
    int count = 0;
    Relasi *R = LR.first;
    while (R) {
        if (R->child->namaMatkul == matkul) count++;
        R = R->next;
    }
    return count;
}

int countMatkulNoParent(ListChild LC, ListRelasi LR) {
    int count = 0;
    Child *C = LC.first;
    while (C) {
        bool ada = false;
        Relasi *R = LR.first;
        while (R) {
            if (R->child == C) {
                ada = true;
                break;
            }
            R = R->next;
        }
        if (!ada) count++;
        C = C->next;
    }
    return count;
}

int countJurusanNoChild(ListParent LP, ListRelasi LR) {
    int count = 0;
    Parent *P = LP.first;
    while (P) {
        bool ada = false;
        Relasi *R = LR.first;
        while (R) {
            if (R->parent == P) {
                ada = true;
                break;
            }
            R = R->next;
        }
        if (!ada) count++;
        P = P->next;
    }
    return count;
}

void editRelasi(ListRelasi &LR, string oldJurusan, string oldMatkul, Parent *newP, Child *newC) {
    Relasi *R = LR.first;
    while (R) {
        if (R->parent->namaJurusan == oldJurusan &&
            R->child->namaMatkul == oldMatkul) {
            R->parent = newP;
            R->child = newC;
            cout << "Relasi berhasil diedit: "
                 << newP->namaJurusan << " - "
                 << newC->namaMatkul << endl;
            return;
        }
        R = R->next;
    }
    cout << "Relasi tidak ditemukan" << endl;
}
