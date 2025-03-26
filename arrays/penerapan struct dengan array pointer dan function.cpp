#include <iostream>
using namespace std;

struct Produk {
    string kode, nama;
    float harga;
    int stok;
} daftarProduk[] = {{"P001", "Minyak Goreng", 28000, 50},
                    {"P002", "Gula Pasir", 15000, 30}};

void tampilkan(Produk *p) {
    cout << "Kode: " << p->kode << " | Nama: " << p->nama
         << " | Harga: Rp " << p->harga << " | Stok: " << p->stok << " pcs\n";
}

int main() {
    for (auto &p : daftarProduk) tampilkan(&p);
    return 0;
}


