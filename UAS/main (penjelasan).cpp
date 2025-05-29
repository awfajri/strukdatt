#include <iostream> // Ini adalah 'kepala' program yang mengizinkan kita untuk melakukan input (misalnya, mengetik sesuatu) dan output (misalnya, menampilkan tulisan di layar).
#include <string>   // Ini 'kepala' program yang memungkinkan kita menggunakan tipe data string, yaitu untuk teks seperti nama tugas atau deadline.
using namespace std; // Ini memberitahu program untuk menggunakan sekumpulan nama standar agar kita tidak perlu mengetik 'std::' setiap kali.

// Struktur untuk menyimpan data tugas
struct Tugas { // 'struct Tugas' itu seperti kita membuat sebuah 'cetakan' atau 'template' untuk data yang berhubungan dengan satu tugas.
    int id;                 // Di dalam 'Tugas', ada 'id' untuk nomor unik tugas, tipenya integer (angka bulat).
    string namaTugas;       // Ada 'namaTugas' untuk menyimpan nama tugas, tipenya string (teks).
    string deadline;        // Ada 'deadline' untuk menyimpan batas waktu tugas, tipenya string (teks).
    Tugas* next;            // 'Tugas* next' ini spesial. Ini adalah 'pointer' yang akan menunjuk ke tugas berikutnya dalam sebuah daftar. Bayangkan ini seperti rantai, di mana setiap mata rantai (Tugas) tahu mata rantai berikutnya. Ini adalah dasar dari Linked List.
};

// Struktur untuk menyimpan data siswa dan status tugas
struct Siswa { // 'struct Siswa' adalah 'cetakan' lain, kali ini untuk data siswa.
    string nama;                          // Menyimpan 'nama' siswa, tipenya string.
    bool statusTugas[100] = {false};      // 'statusTugas' adalah sebuah array (daftar tetap) yang bisa menyimpan 100 status (benar/salah). Awalnya semua diset 'false' (belum dikerjakan). `statusTugas[0]` akan untuk tugas ID 1, `statusTugas[1]` untuk tugas ID 2, dan seterusnya.
};

// Fungsi untuk menambah tugas ke linked list (CREATE)
// 'void tambahTugas' berarti kita membuat sebuah 'perintah' bernama 'tambahTugas' yang tidak mengembalikan nilai apa pun setelah selesai.
// 'Tugas*& head' artinya perintah ini menerima alamat dari pointer 'head' dari daftar tugas kita. 'head' adalah tugas pertama dalam daftar.
// 'int& jumlahTugas' menerima referensi ke variabel yang menyimpan jumlah tugas saat ini, jadi kita bisa mengubahnya di dalam fungsi.
// 'string nama, string deadline' adalah input berupa nama dan deadline tugas baru.
void tambahTugas(Tugas*& head, int& jumlahTugas, string nama, string deadline) {
    Tugas* baru = new Tugas{jumlahTugas + 1, nama, deadline, nullptr}; // Kita membuat 'Tugas' baru di memori. 'jumlahTugas + 1' menjadi ID-nya, 'nama' dan 'deadline' sesuai input, dan 'nullptr' berarti tugas baru ini belum menunjuk ke tugas berikutnya (dia jadi yang terakhir untuk sementara).
    if (!head) { // Jika 'head' itu kosong (artinya belum ada tugas sama sekali)...
        head = baru; // ...maka tugas 'baru' ini menjadi 'head' (tugas pertama).
    } else { // Jika sudah ada tugas...
        Tugas* temp = head; // Kita buat pointer sementara 'temp' yang menunjuk ke 'head'.
        while (temp->next) temp = temp->next; // Kita 'berjalan' di sepanjang daftar tugas ('temp' pindah ke 'next' terus) sampai kita menemukan tugas terakhir (yang 'next'-nya adalah 'nullptr').
        temp->next = baru; // Tugas terakhir tadi sekarang 'next'-nya menunjuk ke tugas 'baru' kita. Jadi, tugas 'baru' ditambahkan di akhir daftar.
    }
    jumlahTugas++; // Jumlah total tugas bertambah satu.
    cout << "Tugas berhasil ditambahkan!\n"; // Tampilkan pesan sukses.
}

// Fungsi untuk menampilkan semua tugas (READ)
// 'void tampilkanTugas' adalah perintah untuk menampilkan semua tugas.
// 'Tugas* head' menerima pointer ke tugas pertama. Kita pakai 'Tugas*' (bukan 'Tugas*&') karena kita tidak akan mengubah 'head' aslinya, hanya menggunakannya untuk membaca.
void tampilkanTugas(Tugas* head) {
    cout << "\nDaftar Tugas:\n"; // Tampilkan judul.
    if (!head) { // Jika 'head' kosong...
        cout << "Belum ada tugas.\n"; // ...beritahu pengguna belum ada tugas.
        return; // Keluar dari fungsi ini.
    }
    while (head) { // Selama 'head' masih menunjuk ke sebuah tugas (belum 'nullptr')...
        cout << "ID: " << head->id << " | Nama: " << head->namaTugas << " | Deadline: " << head->deadline << endl; // ...tampilkan detail tugas saat ini (ID, nama, deadline). 'endl' untuk pindah baris.
        head = head->next; // Pindahkan 'head' ke tugas berikutnya dalam daftar.
    }
}

// Fungsi untuk mengupdate tugas (UPDATE)
// 'void updateTugas' adalah perintah untuk mengubah detail tugas yang sudah ada.
// 'Tugas* head' menerima pointer ke tugas pertama.
// 'int idCari' adalah ID tugas yang mau diubah.
void updateTugas(Tugas* head, int idCari) {
    while (head) { // Selama 'head' masih menunjuk ke sebuah tugas...
        if (head->id == idCari) { // ...cek apakah ID tugas saat ini sama dengan 'idCari'.
            cout << "Masukkan nama tugas baru: "; // Jika sama, minta input nama tugas baru.
            getline(cin >> ws, head->namaTugas); // Baca seluruh baris input (termasuk spasi) untuk nama tugas dan simpan. 'ws' untuk mengabaikan spasi sisa dari input sebelumnya.
            cout << "Masukkan deadline baru: "; // Minta input deadline baru.
            getline(cin, head->deadline); // Baca seluruh baris input untuk deadline dan simpan.
            cout << "Tugas berhasil diupdate!\n"; // Tampilkan pesan sukses.
            return; // Keluar dari fungsi karena tugas sudah ketemu dan diupdate.
        }
        head = head->next; // Pindah ke tugas berikutnya.
    }
    cout << "Tugas dengan ID tersebut tidak ditemukan.\n"; // Jika loop selesai dan tugas tidak ketemu, tampilkan pesan ini.
}

// Fungsi untuk menghapus tugas (DELETE)
// 'void hapusTugas' adalah perintah untuk menghapus tugas.
// 'Tugas*& head' menerima alamat dari pointer 'head' karena 'head' bisa saja berubah (jika tugas pertama yang dihapus).
// 'int idCari' adalah ID tugas yang mau dihapus.
// 'int& jumlahTugas' menerima referensi agar jumlah tugas bisa dikurangi.
void hapusTugas(Tugas*& head, int idCari, int& jumlahTugas) {
    if (!head) return; // Jika tidak ada tugas sama sekali, langsung keluar.

    if (head->id == idCari) { // Jika tugas yang mau dihapus adalah tugas pertama ('head')...
        Tugas* hapus = head; // ...simpan alamat 'head' ke pointer 'hapus'.
        head = head->next; // ...jadikan tugas setelahnya sebagai 'head' baru.
        delete hapus; // ...hapus tugas yang tadi disimpan di 'hapus' dari memori.
        jumlahTugas--; // Kurangi jumlah tugas.
        cout << "Tugas berhasil dihapus!\n"; // Tampilkan pesan.
        return; // Keluar.
    }

    Tugas* temp = head; // Buat pointer sementara 'temp' mulai dari 'head'.
    // 'temp->next && temp->next->id != idCari' artinya: selama 'temp' punya tugas berikutnya DAN ID tugas berikutnya itu BUKAN yang kita cari...
    while (temp->next && temp->next->id != idCari) {
        temp = temp->next; // ...pindah 'temp' ke tugas berikutnya. Loop ini berhenti ketika 'temp' adalah tugas SEBELUM tugas yang mau dihapus.
    }

    if (temp->next) { // Jika 'temp->next' ada (artinya tugas yang dicari ketemu dan BUKAN tugas pertama)...
        Tugas* hapus = temp->next; // ...simpan alamat tugas yang mau dihapus (yaitu 'temp->next') ke 'hapus'.
        temp->next = hapus->next; // ...sambungkan 'next' dari 'temp' ke tugas SETELAH 'hapus' (melewati 'hapus').
        delete hapus; // Hapus tugas dari memori.
        jumlahTugas--; // Kurangi jumlah tugas.
        cout << "Tugas berhasil dihapus!\n"; // Tampilkan pesan.
    } else { // Jika 'temp->next' tidak ada setelah loop, berarti tugas tidak ditemukan.
        cout << "Tugas dengan ID tersebut tidak ditemukan.\n";
    }
}

// Fungsi untuk menandai tugas sudah dikerjakan oleh siswa
// 'void kerjakanTugas' adalah perintah untuk menandai tugas sebagai selesai.
// 'Siswa& siswa' menerima referensi ke objek 'Siswa' agar status tugasnya bisa diubah.
// 'int idTugas' adalah ID tugas yang dikerjakan.
void kerjakanTugas(Siswa& siswa, int idTugas) {
    siswa.statusTugas[idTugas - 1] = true; // Ubah status tugas di array 'statusTugas' milik siswa menjadi 'true' (sudah dikerjakan). Kita pakai 'idTugas - 1' karena array dimulai dari indeks 0 (misal ID tugas 1 ada di `statusTugas[0]`).
}

// Fungsi untuk menampilkan status tugas siswa
// 'void statusTugasSiswa' adalah perintah untuk melihat status semua tugas seorang siswa.
// 'Siswa siswa' menerima salinan objek 'Siswa' (tidak perlu diubah).
// 'Tugas* head' menerima pointer ke awal daftar tugas untuk mendapatkan nama dan deadline.
void statusTugasSiswa(Siswa siswa, Tugas* head) {
    cout << "\nStatus Tugas untuk " << siswa.nama << ":\n"; // Tampilkan nama siswa.
    Tugas* temp = head; // Buat pointer sementara untuk 'berjalan' di daftar tugas.
    while (temp) { // Selama masih ada tugas di daftar...
        cout << temp->namaTugas << " (Deadline: " << temp->deadline << ") : "; // ...tampilkan nama dan deadline tugas.
        if (siswa.statusTugas[temp->id - 1]) // Cek status tugas ini di array 'statusTugas' milik siswa (menggunakan ID tugas sebagai patokan indeks).
            cout << "Sudah dikerjakan\n"; // Jika true, tampilkan "Sudah dikerjakan".
        else
            cout << "Belum dikerjakan\n"; // Jika false, tampilkan "Belum dikerjakan".
        temp = temp->next; // Pindah ke tugas berikutnya.
    }
}

int main() { // 'int main()' adalah fungsi utama, program dimulai dari sini.
    Tugas* daftarTugas = nullptr; // Buat pointer 'daftarTugas' yang akan menjadi 'head' dari linked list tugas kita. Awalnya kosong ('nullptr').
    int jumlahTugas = 0; // Variabel untuk menyimpan berapa banyak tugas yang ada, awalnya 0.
    Siswa siswa[2] = {{"Hafiz"}, {"Indra"}}; // Buat array (daftar tetap) berisi 2 siswa. Siswa pertama namanya "Hafiz", kedua "Indra". Status tugas mereka default-nya 'false' semua.

    int menu; // Variabel untuk menyimpan pilihan menu dari pengguna.
    do { // 'do-while' loop: lakukan blok kode di dalamnya, kemudian cek kondisinya. Akan terus berulang selama kondisi di 'while' (menu != 0) benar.
        cout << "\n===== MENU SISTEM MANAJEMEN TUGAS =====\n"; // Tampilkan pilihan menu.
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Daftar Tugas\n";
        cout << "3. Update Tugas\n";
        cout << "4. Hapus Tugas\n";
        cout << "5. Tandai Tugas Sudah Dikerjakan Siswa\n";
        cout << "6. Tampilkan Status Tugas Siswa\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu; // Baca input angka dari pengguna dan simpan ke 'menu'.

        if (menu == 1) { // Jika pengguna pilih 1...
            string nama, deadline;
            cout << "Masukkan nama tugas: ";
            getline(cin >> ws, nama); // Baca nama tugas. 'cin >> ws' dulu untuk 'membersihkan' sisa input sebelumnya, lalu 'getline' untuk membaca seluruh baris.
            cout << "Masukkan deadline: ";
            getline(cin, deadline); // Baca deadline.
            tambahTugas(daftarTugas, jumlahTugas, nama, deadline); // Panggil fungsi 'tambahTugas'.
        } else if (menu == 2) { // Jika pengguna pilih 2...
            tampilkanTugas(daftarTugas); // Panggil fungsi 'tampilkanTugas'.
        } else if (menu == 3) { // Jika pengguna pilih 3...
            int id;
            cout << "Masukkan ID tugas yang ingin diupdate: ";
            cin >> id; // Baca ID tugas yang mau diupdate.
            updateTugas(daftarTugas, id); // Panggil fungsi 'updateTugas'.
        } else if (menu == 4) { // Jika pengguna pilih 4...
            int id;
            cout << "Masukkan ID tugas yang ingin dihapus: ";
            cin >> id; // Baca ID tugas yang mau dihapus.
            hapusTugas(daftarTugas, id, jumlahTugas); // Panggil fungsi 'hapusTugas'.
        } else if (menu == 5) { // Jika pengguna pilih 5...
            int id, idxSiswa;
            cout << "Pilih siswa:\n";
            for (int i = 0; i < 2; i++) { // Loop untuk menampilkan daftar siswa yang ada (Hafiz dan Indra).
                cout << i + 1 << ". " << siswa[i].nama << endl;
            }
            cout << "Masukkan nomor siswa: ";
            cin >> idxSiswa; // Baca pilihan nomor siswa.
            cout << "Masukkan ID tugas yang sudah dikerjakan: ";
            cin >> id; // Baca ID tugas yang dikerjakan.
            // 'idxSiswa-1' karena array 'siswa' dimulai dari indeks 0, tapi pilihan user dari 1.
            if (idxSiswa > 0 && idxSiswa <= 2) { // Pastikan pilihan siswa valid
                 kerjakanTugas(siswa[idxSiswa - 1], id); // Panggil fungsi 'kerjakanTugas' untuk siswa yang dipilih.
                 cout << "Status tugas " << siswa[idxSiswa - 1].nama << " diperbarui.\n";
            } else {
                 cout << "Nomor siswa tidak valid.\n";
            }
        } else if (menu == 6) { // Jika pengguna pilih 6...
            for (int i = 0; i < 2; i++) { // Loop untuk setiap siswa yang ada...
                statusTugasSiswa(siswa[i], daftarTugas); // ...panggil 'statusTugasSiswa' untuk menampilkan status tugasnya.
            }
        } else if (menu == 0) { // Jika pengguna pilih 0...
            cout << "Keluar dari program.\n"; // Tampilkan pesan keluar.
        } else { // Jika pilihan tidak ada di menu...
            cout << "Menu tidak valid.\n"; // Tampilkan pesan error.
        }
        // Membersihkan buffer input jika terjadi kesalahan input (misalnya memasukkan huruf saat diminta angka)
        if (cin.fail() && menu !=0) {
            cin.clear(); // Menghapus status error pada cin
            cin.ignore(10000, '\n'); // Mengabaikan sisa input di baris saat ini
            cout << "Input tidak valid, silakan coba lagi.\n";
        }
    } while (menu != 0); // Loop akan berhenti jika pengguna memilih menu 0.

    // Sebelum program benar-benar berakhir, kita perlu menghapus semua memori yang dialokasikan untuk 'Tugas' agar tidak ada memory leak.
    Tugas* current = daftarTugas;
    Tugas* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    daftarTugas = nullptr; // Set head ke nullptr setelah semua node dihapus

    return 0; // Akhir dari fungsi 'main', program selesai. Angka 0 menandakan program selesai dengan sukses.
}
