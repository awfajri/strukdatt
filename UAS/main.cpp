#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan data tugas
struct Tugas {
    int id;
    string namaTugas;
    string deadline;
    Tugas* next;
};

// Struktur untuk menyimpan data siswa dan status tugas
struct Siswa {
    string nama;
    bool statusTugas[100] = {false}; // true = sudah, false = belum
};

// Fungsi untuk menambah tugas ke linked list (CREATE)
void tambahTugas(Tugas*& head, int& jumlahTugas, string nama, string deadline) {
    Tugas* baru = new Tugas{jumlahTugas + 1, nama, deadline, nullptr};
    if (!head) {
        head = baru;
    } else {
        Tugas* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = baru;
    }
    jumlahTugas++;
    cout << "Tugas berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua tugas (READ)
void tampilkanTugas(Tugas* head) {
    cout << "\nDaftar Tugas:\n";
    if (!head) {
        cout << "Belum ada tugas.\n";
        return;
    }
    while (head) {
        cout << "ID: " << head->id << " | Nama: " << head->namaTugas << " | Deadline: " << head->deadline << endl;
        head = head->next;
    }
}

// Fungsi untuk mengupdate tugas (UPDATE)
void updateTugas(Tugas* head, int idCari) {
    while (head) {
        if (head->id == idCari) {
            cout << "Masukkan nama tugas baru: ";
            getline(cin >> ws, head->namaTugas);
            cout << "Masukkan deadline baru: ";
            getline(cin, head->deadline);
            cout << "Tugas berhasil diupdate!\n";
            return;
        }
        head = head->next;
    }
    cout << "Tugas dengan ID tersebut tidak ditemukan.\n";
}

// Fungsi untuk menghapus tugas (DELETE)
void hapusTugas(Tugas*& head, int idCari, int& jumlahTugas) {
    if (!head) return;
    if (head->id == idCari) {
        Tugas* hapus = head;
        head = head->next;
        delete hapus;
        jumlahTugas--;
        cout << "Tugas berhasil dihapus!\n";
        return;
    }
    Tugas* temp = head;
    while (temp->next && temp->next->id != idCari) {
        temp = temp->next;
    }
    if (temp->next) {
        Tugas* hapus = temp->next;
        temp->next = hapus->next;
        delete hapus;
        jumlahTugas--;
        cout << "Tugas berhasil dihapus!\n";
    } else {
        cout << "Tugas dengan ID tersebut tidak ditemukan.\n";
    }
}

// Fungsi untuk menandai tugas sudah dikerjakan oleh siswa
void kerjakanTugas(Siswa& siswa, int idTugas) {
    siswa.statusTugas[idTugas - 1] = true;
}

// Fungsi untuk menampilkan status tugas siswa
void statusTugasSiswa(Siswa siswa, Tugas* head) {
    cout << "\nStatus Tugas untuk " << siswa.nama << ":\n";
    Tugas* temp = head;
    while (temp) {
        cout << temp->namaTugas << " (Deadline: " << temp->deadline << ") : ";
        if (siswa.statusTugas[temp->id - 1])
            cout << "Sudah dikerjakan\n";
        else
            cout << "Belum dikerjakan\n";
        temp = temp->next;
    }
}

int main() {
    Tugas* daftarTugas = nullptr;
    int jumlahTugas = 0;
    Siswa siswa[2] = {{"Hafiz"}, {"Indra"}};

    int menu;
    do {
        cout << "\n===== MENU SISTEM MANAJEMEN TUGAS =====\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Daftar Tugas\n";
        cout << "3. Update Tugas\n";
        cout << "4. Hapus Tugas\n";
        cout << "5. Tandai Tugas Sudah Dikerjakan Siswa\n";
        cout << "6. Tampilkan Status Tugas Siswa\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            string nama, deadline;
            cout << "Masukkan nama tugas: ";
            getline(cin >> ws, nama);
            cout << "Masukkan deadline: ";
            getline(cin, deadline);
            tambahTugas(daftarTugas, jumlahTugas, nama, deadline);
        } else if (menu == 2) {
            tampilkanTugas(daftarTugas);
        } else if (menu == 3) {
            int id;
            cout << "Masukkan ID tugas yang ingin diupdate: ";
            cin >> id;
            updateTugas(daftarTugas, id);
        } else if (menu == 4) {
            int id;
            cout << "Masukkan ID tugas yang ingin dihapus: ";
            cin >> id;
            hapusTugas(daftarTugas, id, jumlahTugas);
        } else if (menu == 5) {
        int id, idxSiswa;
        cout << "Pilih siswa:\n";
        for (int i = 0; i < 2; i++) {
            cout << i+1 << ". " << siswa[i].nama << endl;
        }
        cout << "Masukkan nomor siswa: ";
        cin >> idxSiswa;
        cout << "Masukkan ID tugas yang sudah dikerjakan: ";
        cin >> id;
        kerjakanTugas(siswa[idxSiswa-1], id);
        cout << "Status tugas " << siswa[idxSiswa-1].nama << " diperbarui.\n";
        } else if (menu == 6) {
            for (int i = 0; i < 2; i++) {
                statusTugasSiswa(siswa[i], daftarTugas);
            }
        } else if (menu == 0) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Menu tidak valid.\n";
        }
    } while (menu != 0);

    return 0;
}
