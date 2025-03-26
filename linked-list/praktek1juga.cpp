#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct dataKtp {
    char nama[50];
    char alamat[50];
    char golongandarah[50];
    dataKtp *next, *prev;
};

dataKtp *awal = NULL, *akhir = NULL, *bantu, *baru;

void inputDataDepan() {
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama : ";
    cin >> baru->nama;
    cout << "Alamat : ";
    cin >> baru->alamat;
    cout << "Golongan darah : ";
    cin >> baru->golongandarah;

    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        baru->next = awal;
        awal->prev = baru;
        awal = baru;
    }
    system("cls");
}

void inputDataBelakang() {
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama : ";
    cin >> baru->nama;
    cout << "Alamat : ";
    cin >> baru->alamat;
    cout << "Golongan darah : ";
    cin >> baru->golongandarah;

    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        akhir->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }
    system("cls");
}

void outputData() {
    if (awal == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    bantu = awal;
    while (bantu != NULL) {
        cout << "Nama: " << bantu->nama << endl;
        cout << "Alamat: " << bantu->alamat << endl;
        cout << "Golongan darah: " << bantu->golongandarah << endl;
        cout << "------------------------\n";
        bantu = bantu->next;
    }
}

// Fungsi untuk menghapus data berdasarkan nama
void hapusData() {
    if (awal == NULL) {
        cout << "Data masih kosong, tidak ada yang bisa dihapus.\n";
        return;
    }

    char namaHapus[50];
    cout << "Masukkan nama yang ingin dihapus: ";
    cin >> namaHapus;

    bantu = awal;
    while (bantu != NULL && strcmp(bantu->nama, namaHapus) != 0) {
        bantu = bantu->next;
    }

    if (bantu == NULL) {
        cout << "Data dengan nama " << namaHapus << " tidak ditemukan.\n";
        return;
    }

    // Jika node yang ingin dihapus adalah node pertama
    if (bantu == awal) {
        awal = awal->next;
        if (awal != NULL) awal->prev = NULL;
        else akhir = NULL; // Jika list kosong setelah penghapusan
    }
    // Jika node yang ingin dihapus adalah node terakhir
    else if (bantu == akhir) {
        akhir = akhir->prev;
        if (akhir != NULL) akhir->next = NULL;
        else awal = NULL; // Jika list kosong setelah penghapusan
    }
    // Jika node berada di tengah
    else {
        bantu->prev->next = bantu->next;
        bantu->next->prev = bantu->prev;
    }

    delete bantu; // Hapus node dari memori
    cout << "Data berhasil dihapus.\n";
}

int main() {
    int pilihan;
    do {
        cout << "1. Input Depan\n";
        cout << "2. Input Belakang\n";
        cout << "3. Output\n";
        cout << "4. Hapus Data\n";
        cout << "5. Exit\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                inputDataDepan();
                break;
            case 2:
                inputDataBelakang();
                break;
            case 3:
                outputData();
                break;
            case 4:
                hapusData();
                break;
            case 5:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
