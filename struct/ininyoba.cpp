#include <iostream>
using namespace std;

struct Penduduk {
    string nama, NIK, alamat, pekerjaan;
    int umur;
};

int main() {
    Penduduk pnd[10];
    int maxUmur = 0;
    int indexTertua = 0;


    for (int i = 0; i < 10; i++) {
        cout << "Penduduk ke-" << i + 1 << endl;

        cout << "Masukkan nama penduduk: ";
        cin >> ws;
        getline(cin, pnd[i].nama);

        cout << "Masukkan NIK penduduk: ";
        cin >> pnd[i].NIK;

        cout << "Masukkan umur penduduk: ";
        cin >> pnd[i].umur;

        cout << "Masukkan alamat penduduk: ";
        cin >> ws;
        getline(cin, pnd[i].alamat);

        cout << "Masukkan pekerjaan penduduk: ";
        cin >> ws;
        getline(cin, pnd[i].pekerjaan);


        if (pnd[i].umur > maxUmur) {
            maxUmur = pnd[i].umur;
            indexTertua = i;
        }

        cout << endl;
    }


    cout << "\n Data Penduduk Perumahan Mahkota \n";
    for (int i = 0; i < 10; i++) {
        cout << "\nPenduduk ke-" << i + 1 << endl;
        cout << "Nama      : " << pnd[i].nama << endl;
        cout << "NIK       : " << pnd[i].NIK << endl;
        cout << "Umur      : " << pnd[i].umur << endl;
        cout << "Alamat    : " << pnd[i].alamat << endl;
        cout << "Pekerjaan : " << pnd[i].pekerjaan << endl;
    }


    cout << "\n Penduduk Tertua Perumahan Mahkota \n";
    cout << "Nama      : " << pnd[indexTertua].nama << endl;
    cout << "NIK       : " << pnd[indexTertua].NIK << endl;
    cout << "Umur      : " << pnd[indexTertua].umur << " tahun" << endl;
    cout << "Alamat    : " << pnd[indexTertua].alamat << endl;
    cout << "Pekerjaan : " << pnd[indexTertua].pekerjaan << endl;

    return 0;
}
