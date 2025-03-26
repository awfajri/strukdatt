#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 20;

struct Nilai {
    int absen;
    int tugas;
    int uts;
    int uas;
    float akhir;
    char huruf;
};

struct Mahasiswa {
    string npm;
    string nama;
    Nilai nilai;
};

Mahasiswa dataMahasiswa[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

void hitungNilaiAkhir(Nilai &nilai) {
    nilai.akhir = 0.1 * nilai.absen + 0.2 * nilai.tugas + 0.3 * nilai.uts + 0.4 * nilai.uas;
    if (nilai.akhir > 80) {
        nilai.huruf = 'A';
    } else if (nilai.akhir > 70) {
        nilai.huruf = 'B';
    } else if (nilai.akhir > 60) {
        nilai.huruf = 'C';
    } else {
        nilai.huruf = 'D';
    }
}

void inputDataMahasiswa() {
    if (jumlahMahasiswa >= MAX_MAHASISWA) {
        cout << "Data mahasiswa sudah penuh!" << endl;
        return;
    }

    Mahasiswa mhs;
    cout << "Masukkan NPM: ";
    cin >> mhs.npm;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, mhs.nama);
    cout << "Masukkan Nilai Absen: ";
    cin >> mhs.nilai.absen;
    cout << "Masukkan Nilai Tugas: ";
    cin >> mhs.nilai.tugas;
    cout << "Masukkan Nilai UTS: ";
    cin >> mhs.nilai.uts;
    cout << "Masukkan Nilai UAS: ";
    cin >> mhs.nilai.uas;

    hitungNilaiAkhir(mhs.nilai);
    dataMahasiswa[jumlahMahasiswa++] = mhs;
    cout << "Data mahasiswa berhasil ditambahkan!" << endl;
}

void tampilDataMahasiswa() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa!" << endl;
        return;
    }

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "NPM: " << dataMahasiswa[i].npm << endl;
        cout << "Nama: " << dataMahasiswa[i].nama << endl;
        cout << "Nilai Absen: " << dataMahasiswa[i].nilai.absen << endl;
        cout << "Nilai Tugas: " << dataMahasiswa[i].nilai.tugas << endl;
        cout << "Nilai UTS: " << dataMahasiswa[i].nilai.uts << endl;
        cout << "Nilai UAS: " << dataMahasiswa[i].nilai.uas << endl;
        cout << "Nilai Akhir: " << dataMahasiswa[i].nilai.akhir << endl;
        cout << "Nilai Huruf: " << dataMahasiswa[i].nilai.huruf << endl;
        cout << "-------------------------" << endl;
    }
}

void editDataMahasiswa() {
    string npm;
    cout << "Masukkan NPM mahasiswa yang akan diedit: ";
    cin >> npm;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (dataMahasiswa[i].npm == npm) {
            cout << "Masukkan Nilai Absen baru: ";
            cin >> dataMahasiswa[i].nilai.absen;
            cout << "Masukkan Nilai Tugas baru: ";
            cin >> dataMahasiswa[i].nilai.tugas;
            cout << "Masukkan Nilai UTS baru: ";
            cin >> dataMahasiswa[i].nilai.uts;
            cout << "Masukkan Nilai UAS baru: ";
            cin >> dataMahasiswa[i].nilai.uas;

            hitungNilaiAkhir(dataMahasiswa[i].nilai);
            cout << "Data mahasiswa berhasil diupdate!" << endl;
            return;
        }
    }

    cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan!" << endl;
}

void hapusDataMahasiswa() {
    string npm;
    cout << "Masukkan NPM mahasiswa yang akan dihapus: ";
    cin >> npm;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (dataMahasiswa[i].npm == npm) {
            for (int j = i; j < jumlahMahasiswa - 1; j++) {
                dataMahasiswa[j] = dataMahasiswa[j + 1];
            }
            jumlahMahasiswa--;
            cout << "Data mahasiswa berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Mahasiswa dengan NPM " << npm << " tidak ditemukan!" << endl;
}

int main() {
    int pilihan;
    do {
        cout << "Menu Program:" << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Tampil Data Mahasiswa" << endl;
        cout << "3. Edit Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputDataMahasiswa();
                break;
            case 2:
                tampilDataMahasiswa();
                break;
            case 3:
                editDataMahasiswa();
                break;
            case 4:
                hapusDataMahasiswa();
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
