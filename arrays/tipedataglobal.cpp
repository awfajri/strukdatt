#include <iostream>
using namespace std;

// Struct sebagai tipe data global
struct Mahasiswa {
    string nama, npm;
};

struct Siswa {
    string nama;
    int umur;
    float nilai;
};

struct Asdos {
    char nama[25];
    char matkul[15];
};

int main() {
    Asdos asdos1; // Membuat variabel dari struct Asdos

    cout << "Masukkan nama asdos: ";
    cin.getline(asdos1.nama, 25); // Menggunakan getline agar bisa menerima spasi

    cout << "Masukkan mata kuliah asdos: ";
    cin.getline(asdos1.matkul, 15); // Menggunakan getline agar bisa menerima spasi

    cout << "\nNama asdos: " << asdos1.nama << endl;
    cout << "Mata kuliah asdos tersebut adalah: " << asdos1.matkul << endl;

    return 0;
}


