#ifndef FAKULTAS_H
#define FAKULTAS_H

#include <string>
using namespace std;

// MLL List to List
struct Parent;
struct Child;

typedef Parent* adrParent;
typedef Child* adrChild;

struct Child {
    string namaMatkul;
    adrChild next;
};

struct Parent {
    string namaJurusan;
    adrParent next;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
};

// Inisialisasi
void createList(ListParent &L);

// Operasi Parent
void insertJurusan(ListParent &L, const string &jurusan);
void deleteJurusan(ListParent &L, const string &jurusan);
adrParent findJurusan(ListParent L, const string &jurusan);
void showJurusan(ListParent L);

// Operasi Child
void insertMatkul(ListParent &L, const string &jurusan,
                  const string &matkul);
void deleteMatkul(ListParent &L, const string &jurusan,
                  const string &matkul);
adrChild findMatkul(adrParent P, const string &matkul);
void showMatkul(ListParent L, const string &jurusan);

// Operasi Relasi
bool findRelasi(ListParent L, const string &jurusan,
                const string &matkul);
void showMatkulFromJurusan(ListParent L, const string &jurusan);
void showJurusanFromMatkul(ListParent L, const string &matkul);
void showAllJurusanMatkul(ListParent L);
void showAllMatkulJurusan(ListParent L);
void showAll(ListParent L);

// Perhitungan
int countChildFromParent(ListParent L, const string &jurusan);
int countParentFromChild(ListParent L, const string &matkul);
int countMatkulNoParent(ListParent L);
int countJurusanNoChild(ListParent L);

// Edit Relasi
void editRelasi(ListParent &L,
                const string &oldJurusan,
                const string &oldMatkul,
                const string &newJurusan,
                const string &newMatkul);

#endif
