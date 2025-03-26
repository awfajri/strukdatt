#include <stdio.h>
#include <iostream>
using namespace std;
struct Kursi {
    int nomor;
    bool dipesan;
    Kursi *prev, *next;
    Kursi(int n) : nomor(n), dipesan(false), prev(nullptr), next(nullptr) {}
};
class Bioskop {
private:
    Kursi* head = nullptr;
public:
    void tambahKursi(int n) {
        for (int i = 1; i <= n; i++) {
            Kursi* newKursi = new Kursi(i);
            if (!head) head = newKursi;
            else {
                Kursi* temp = head;
                while (temp->next) temp = temp->next;
                temp->next = newKursi;
                newKursi->prev = temp;
            }
        }
    }
    void aturKursi(int nomor, bool pesan) {
        Kursi* temp = head;
        while (temp) {
            if (temp->nomor == nomor) {
                temp->dipesan = pesan;
                cout << "Kursi " << nomor << (pesan ? " dipesan!\n" : " dibatalkan!\n");
                return;
            }
            temp = temp->next;
        }
        cout << "Kursi tidak ditemukan!\n";
    }
    void tampilkanKursi() {
        for (Kursi* temp = head; temp; temp = temp->next)
            cout << "[Kursi " << temp->nomor << " " << (temp->dipesan ? "X" : "V") << "] ";
        cout << "\n";
    }
};
int main() {
    Bioskop b;
    b.tambahKursi(5);
    b.tampilkanKursi();

    b.aturKursi(2, true);  // Pesan kursi 2
    b.aturKursi(4, true);  // Pesan kursi 4
    b.tampilkanKursi();

    b.aturKursi(2, false); // Batalkan kursi 2
    b.tampilkanKursi();

    return 0;
}
