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
bool isEmpty(ListParent L);

// Operasi Parent
void insertJurusan(ListParent &L, string jurusan);
void deleteJurusan(ListParent &L, string jurusan);
void findJurusan(ListParent L, string jurusan, adrParent &P);
void showJurusan(ListParent L);

// Operasi Child
void insertMatkul(ListParent &L, string jurusan, string matkul);
void deleteMatkul(ListParent &L, string jurusan, string matkul);
void findMatkul(adrParent P, string matkul, adrChild &C);
void showMatkul(ListParent L, string jurusan);

// Operasi Relasi
bool findRelasi(ListParent L, string jurusan, string matkul);
void showMatkulFromJurusan(ListParent L, string jurusan);
void showJurusanFromMatkul(ListParent L, string matkul);
void showAllJurusanMatkul(ListParent L);
void showAllMatkulJurusan(ListParent L);
void showAll(ListParent L);

// Perhitungan
int countChildFromParent(ListParent L, string jurusan);
int countParentFromChild(ListParent L, string matkul);
int countMatkulNoParent(ListParent L);
int countJurusanNoChild(ListParent L);

// Edit Relasi
void editRelasi(ListParent &L,
                string oldJurusan,
                string oldMatkul,
                string newJurusan,
                string newMatkul);

#endif
