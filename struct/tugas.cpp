#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string npm;
    struct NilaiMhs {
        float nilaiAbsen;
        float nilaiTugas;
        float nilaiUts;
        float nilaiUas;
        float nilaiAkhir;
        string nilaiHuruf;
    } nilai;
};

const int MAX_MHS = 20;
Mahasiswa daftarMahasiswa[MAX_MHS];
int jumlahMahasiswa = 0;

// Fungsi untuk menghitung nilai akhir
void hitungNilaiAkhir(Mahasiswa &mhs) {
    mhs.nilai.nilaiAkhir = (0.1 * mhs.nilai.nilaiAbsen) + (0.2 * mhs.nilai.nilaiTugas) +
                            (0.3 * mhs.nilai.nilaiUts) + (0.4 * mhs.nilai.nilaiUas);

    if (mhs.nilai.nilaiAkhir > 80)
        mhs.nilai.nilaiHuruf = "A";
    else if (mhs.nilai.nilaiAkhir > 70)
        mhs.nilai.nilaiHuruf = "B";
    else if (mhs.nilai.nilaiAkhir > 60)
        mhs.nilai.nilaiHuruf = "C";
    else
        mhs.nilai.nilaiHuruf = "D";
}

// Fungsi untuk menambahkan mahasiswa
void inputData() {
    if (jumlahMahasiswa >= MAX_MHS) {
        cout << "Data mahasiswa penuh!\n";
        return;
    }

    Mahasiswa mhs;
    cout << "Masukkan Nama: "; cin >> mhs.nama;
    cout << "Masukkan NPM: "; cin >> mhs.npm;
    cout << "Masukkan Nilai Absen: "; cin >> mhs.nilai.nilaiAbsen;
    cout << "Masukkan Nilai Tugas: "; cin >> mhs.nilai.nilaiTugas;
    cout << "Masukkan Nilai UTS: "; cin >> mhs.nilai.nilaiUts;
    cout << "Masukkan Nilai UAS: "; cin >> mhs.nilai.nilaiUas;

    hitungNilaiAkhir(mhs);
    daftarMahasiswa[jumlahMahasiswa++] = mhs;
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilData() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa.\n";
        return;
    }

    cout << endl << "Data Mahasiswa \n";
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "NPM: " << daftarMahasiswa[i].npm
             << " | Nama: " << daftarMahasiswa[i].nama
             << " | Nilai Akhir: " << daftarMahasiswa[i].nilai.nilaiAkhir
             << " | Nilai Huruf: " << daftarMahasiswa[i].nilai.nilaiHuruf << endl;
    }
}

// Fungsi untuk mengedit data mahasiswa berdasarkan NPM
void editData() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa untuk diedit.\n";
        return;
    }

    string npm;
    cout << "Masukkan NPM mahasiswa yang ingin diedit: "; cin >> npm;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].npm == npm) {
            cout << "Masukkan Nilai Absen baru: "; cin >> daftarMahasiswa[i].nilai.nilaiAbsen;
            cout << "Masukkan Nilai Tugas baru: "; cin >> daftarMahasiswa[i].nilai.nilaiTugas;
            cout << "Masukkan Nilai UTS baru: "; cin >> daftarMahasiswa[i].nilai.nilaiUts;
            cout << "Masukkan Nilai UAS baru: "; cin >> daftarMahasiswa[i].nilai.nilaiUas;
            hitungNilaiAkhir(daftarMahasiswa[i]);
            cout << "Data mahasiswa berhasil diperbarui!\n";
            return;
        }
    }
    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan!\n";
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NPM
void hapusData() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa untuk dihapus.\n";
        return;
    }

    string npm;
    cout << "Masukkan NPM mahasiswa yang ingin dihapus: "; cin >> npm;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (daftarMahasiswa[i].npm == npm) {
            for (int j = i; j < jumlahMahasiswa - 1; j++) {
                daftarMahasiswa[j] = daftarMahasiswa[j + 1];
            }
            jumlahMahasiswa--;
            cout << "Data mahasiswa berhasil dihapus!\n";
            return;
        }
    }
    cout << "Mahasiswa dengan NPM tersebut tidak ditemukan!\n";
}

// Fungsi utama untuk menjalankan menu program
int main() {
    int pilihan;
    do {
        cout << endl << "Nama : Auf Fajri Ramadhani" << endl;
        cout << "NPM : 2410631170059" << endl;
        cout << "Menu Program:" << endl;
        cout << "1. Input Data Mahasiswa" << endl;
        cout << "2. Tampil Data Mahasiswa" << endl;
        cout << "3. Edit Data Mahasiswa" << endl;
        cout << "4. Hapus Data Mahasiswa" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: inputData(); break;
            case 2: tampilData(); break;
            case 3: editData(); break;
            case 4: hapusData(); break;
            case 5: cout << "Keluar dari program...\n"; break;
            default: cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
