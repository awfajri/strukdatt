#include <iostream>
using namespace std;
int main() {
    struct Mahasiswa { string nama, npm; };
// Struct sebagai tipe data lokal

    Mahasiswa m = {"Budi Santoso", "202310001"}; // Inisialisasi struct

    cout << "Nama: " << m.nama << ", NPM: " << m.npm << endl;
// Output
    return 0;
}


