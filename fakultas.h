#ifndef FAKULTAS_H
#define FAKULTAS_H

#include <string>
using namespace std;

struct Parent; //Struct jurusan
struct Child; //struct matkul
struct Relasi; //struct relasi jurusan dan matkul

struct Parent {
    string namaJurusan; //isinya adalah nama-nama jurusan
    Parent *next;
};

struct Child {
    string namaMatkul; //isinya adalah nama-nama matkul yang akan di insert di program
    Child *next;
};

struct Relasi { //Terjadi relasi antara jurusan (parent) dan matkul (child)
    Parent *parent; 
    Child *child;
    Relasi *next;
};

struct ListParent { Parent *first; }; //wadah untuk daftar jurusan
struct ListChild  { Child  *first; }; //wadah untuk daftar matkul
struct ListRelasi { Relasi *first; }; //wadah untuk daftar relasi

//list untuk menciptakan jurusan, matkul, relasi
void createList(ListParent &LP, ListChild &LC, ListRelasi &LR); 


void insertJurusan(ListParent &LP, string jurusan); //menambahkan jurusan
void insertMatkul(ListChild &LC, string matkul); //menambahkan jurusan
void insertRelasi(ListRelasi &LR, Parent *P, Child *C); //menghubungkan relasi setelah jurusan dan matkul ditambahkan


void deleteJurusan(ListParent &LP, ListRelasi &LR, string jurusan); //Menghapus jurusan
void deleteMatkul(ListChild &LC, ListRelasi &LR, string matkul); // Menghapus matkul
void deleteRelasi(ListRelasi &LR, string jurusan, string matkul); // Menghapus relasi hubungan jurusan dan matkul


Parent* findJurusan(ListParent LP, string jurusan); //Mencari jurusan
Child* findMatkul(ListChild LC, string matkul); //Mencari matkul
bool findRelasi(ListRelasi LR, string jurusan, string matkul); //Mencari apakah hubungan antara jurusan dan matkul ada atau tidak

// show
void showJurusan(ListParent LP); //Menampilkan jurusan
void showMatkul(ListChild LC); //Menampilkan matkul
void showRelasi(ListRelasi LR); //Menampilkan hubungan jurusan dan matkul
void showMatkulFromJurusan(ListRelasi LR, string jurusan); //Menampilkan matkul dari mengetik jurusan
void showJurusanFromMatkul(ListRelasi LR, string matkul); //Menampilkan jurusan dari mengetik matkul
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
