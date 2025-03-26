#include <iostream>
using namespace std;

// Struct sebagai tipe data global
struct Mahasiswa {
    string nama, npm, alamat;
    float ipk;
};

int main() {
    Mahasiswa mhs;

    cout << "Masukkan NPM: ";
    cin >> mhs.npm;
    cin.ignore(); // Menghindari bug getline setelah cin

    cout << "Masukkan Nama: ";
    getline(cin, mhs.nama); // Bisa menerima spasi

    cout << "Masukkan Alamat: ";
    getline(cin, mhs.alamat); // Bisa menerima spasi

    cout << "Masukkan Nilai IPK: ";
    cin >> mhs.ipk;

    // Output data
    cout << "\nData Mahasiswa:\n";
    cout << "NPM     : " << mhs.npm << endl;
    cout << "Nama    : " << mhs.nama << endl;
    cout << "Alamat  : " << mhs.alamat << endl;
    cout << "IPK     : " << mhs.ipk << endl;

    return 0;
}
