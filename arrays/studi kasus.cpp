#include <iostream>
using namespace std;

struct Produk {
    string kode, nama;
    float harga;
    int stok;
};

int main() {
    Produk p = {"P001", "Minyak Goreng", 28000, 50};

    cout << "Kode : " << p.kode << "\nNama : " << p.nama
         << "\nHarga: Rp " << p.harga << "\nStok : " << p.stok << " pcs\n";

    return 0;
}

