#include <iostream>
#include <string>
using namespace std;
// Definisi struct untuk menyimpan data mahasiswa
struct Mahasiswa {
    string nama;
    string npm;
};
int main() {
    // Deklarasi array struct untuk menyimpan 3 mahasiswa
    const int jumlahMahasiswa = 3;
    Mahasiswa daftarMahasiswa[jumlahMahasiswa];

    // Input data mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        getline(cin, daftarMahasiswa[i].nama);
        cout << "NPM: ";
        getline(cin, daftarMahasiswa[i].npm);
        cout << endl;
    }
    // Menampilkan data mahasiswa
    cout << "===== Data Mahasiswa =====" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: " << daftarMahasiswa[i].nama << endl;
        cout << "NPM : " << daftarMahasiswa[i].npm << endl;
        cout << "--------------------------" << endl;
    }
    return 0;
}
