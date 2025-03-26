#include <iostream>
using namespace std;

// Struct sebagai tipe data global
struct Mahasiswa {
    string nama, npm;
    struct alamatMhs{
        string kota, kecamatan;
        int kodePos;
        }alamat;
    float ipk;
};

int main() {
    Mahasiswa mhs[3];

    for(int i = 0; i<3; i++){
        cout << "orang ke-" << i+1 << endl;
        cout << "masukan npm: ";
        cin >> mhs[i].npm;
        cout << "masukan nama: ";
        cin >> mhs[i].nama;
        cout << "masukin nilai ipk: ";
        cin >> mhs[i].ipk;

    }
    cout << endl;
    cout << "output" << endl;
    for (int i = 0; i < 3; i++){
        cout << "orang ke-" << i+1;
        cout << "nama: " <<mhs[i].nama << endl;
        cout << "npm: " <<mhs[i].npm << endl;
        cout << "ipk: " <<mhs[i].ipk << endl;
    }
    return 0;
}
