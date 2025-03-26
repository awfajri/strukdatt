#include <iostream>
using namespace std;
struct Lagu {
    string judul;
    Lagu* next;
    Lagu* prev;

    Lagu(string j) : judul(j), next(nullptr), prev(nullptr) {}
};
class Playlist {
private:
    Lagu* head = nullptr;
public:
    // Tambah lagu ke playlist
    void tambahLagu(string judul) {
        Lagu* laguBaru = new Lagu(judul);
        if (!head) {
            head = laguBaru;
            head->next = head;
            head->prev = head;
        } else {
            Lagu* tail = head->prev;
            tail->next = laguBaru;
            laguBaru->prev = tail;
            laguBaru->next = head;
            head->prev = laguBaru;
        }
        cout << "Lagu '" << judul << "' ditambahkan ke playlist.\n";
    }
  // Hapus lagu dari playlist
    void hapusLagu(string judul) {
        if (!head) {
            cout << "Playlist kosong!\n";
            return;
        }

        Lagu* temp = head;
        do {
            if (temp->judul == judul) {
                if (temp->next == temp) { // Hanya satu lagu
                    head = nullptr;
                } else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head) head = temp->next;
                }
                delete temp;
                cout << "Lagu '" << judul << "' dihapus dari playlist.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Lagu '" << judul << "' tidak ditemukan!\n";
    }

    // Putar lagu saat ini
    void putarLagu() {
        if (!head) {
            cout << "Playlist kosong!\n";
            return;
        }
        cout << "Sedang memutar: " << head->judul << "\n";
    }
  // Putar lagu berikutnya
    void laguBerikutnya() {
        if (!head) {
            cout << "Playlist kosong!\n";
            return;
        }
        head = head->next;
        putarLagu();
    }

    // Putar lagu sebelumnya
    void laguSebelumnya() {
        if (!head) {
            cout << "Playlist kosong!\n";
            return;
        }
        head = head->prev;
        putarLagu();
    }

    // Tampilkan semua lagu dalam playlist
    void tampilkanPlaylist() {
        if (!head) {
            cout << "Playlist kosong!\n";
            return;
        }

        Lagu* temp = head;
        cout << "🎶 Playlist Musik 🎶\n";
        do {
            cout << "- " << temp->judul << "\n";
            temp = temp->next;
        } while (temp != head);
    }
};

int main() {
    Playlist playlist;

    playlist.tambahLagu("Lagu A");
    playlist.tambahLagu("Lagu B");
    playlist.tambahLagu("Lagu C");

    playlist.tampilkanPlaylist();

    playlist.putarLagu();
    playlist.laguBerikutnya();
    playlist.laguSebelumnya();

    playlist.hapusLagu("Lagu B");
    playlist.tampilkanPlaylist();

    return 0;
}
