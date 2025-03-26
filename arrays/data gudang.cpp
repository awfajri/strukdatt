#include <iostream>
using namespace std;

int main() {
    string gudang[2] = {"Gudang 1", "Gudang 2"};
    string produk[3] = {"Laptop", "Mouse", "Keyboard"};
    string cabang[4] = {"Toko A", "Toko B", "Toko C", "Toko D"};


    int stok[2][3][4] = {
        {{10, 5, 8, 12}, {20, 18, 25, 22}, {15, 10, 12, 17}}, // Gudang 1
        {{8, 12, 9, 14}, {18, 22, 20, 19}, {12, 8, 11, 16}}  // Gudang 2
    };

    cout << "Stok Produk di Gudang 1 untuk Laptop di Toko C: " << stok[1][2][3] << " unit" << endl;
    return 0;
}


