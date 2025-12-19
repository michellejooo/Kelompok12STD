#ifndef FAKULTAS_H
#define FAKULTAS_H

#include <string>
using namespace std;

struct Parent;
struct Child;
struct Relasi;

struct Parent {
    string namaJurusan;
    Parent *next;
};

struct Child {
    string namaMatkul;
    Child *next;
};

struct Relasi {
    Parent *parent;
    Child *child;
    Relasi *next;
};

struct ListParent { Parent *first; };
struct ListChild  { Child  *first; };
struct ListRelasi { Relasi *first; };

// create
void createList(ListParent &LP, ListChild &LC, ListRelasi &LR);

// insert
void insertJurusan(ListParent &LP, string jurusan);
void insertMatkul(ListChild &LC, string matkul);
void insertRelasi(ListRelasi &LR, Parent *P, Child *C);

// delete
void deleteJurusan(ListParent &LP, ListRelasi &LR, string jurusan);
void deleteMatkul(ListChild &LC, ListRelasi &LR, string matkul);
void deleteRelasi(ListRelasi &LR, string jurusan, string matkul);

// find
Parent* findJurusan(ListParent LP, string jurusan);
Child* findMatkul(ListChild LC, string matkul);
bool findRelasi(ListRelasi LR, string jurusan, string matkul);

// show
void showJurusan(ListParent LP);
void showMatkul(ListChild LC);
void showRelasi(ListRelasi LR);
void showMatkulFromJurusan(ListRelasi LR, string jurusan);
void showJurusanFromMatkul(ListRelasi LR, string matkul);
void showAllJurusanMatkul(ListRelasi LR);
void showAllMatkulJurusan(ListRelasi LR);

// count
int countChildFromParent(ListRelasi LR, string jurusan);
int countParentFromChild(ListRelasi LR, string matkul);
int countMatkulNoParent(ListChild LC, ListRelasi LR);
int countJurusanNoChild(ListParent LP, ListRelasi LR);

// edit
void editRelasi(ListRelasi &LR, string oldJurusan, string oldMatkul, Parent *newP, Child *newC);

#endif
