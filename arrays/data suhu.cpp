#include <iostream>
using namespace std;

int main() {
    const int kota = 3, hari = 7, waktu = 3;

    // [Kota][Hari][Waktu] -> Waktu (0 = Pagi, 1 = Siang, 2 = Malam)
    int suhu[kota][hari][waktu] = {
        {{25, 30, 22}, {26, 31, 23}, {27, 32, 24}, {28, 33, 25}, {29, 34, 26}, {30, 35, 27}, {31, 36, 28}},
        {{20, 25, 18}, {21, 26, 19}, {22, 27, 20}, {23, 28, 21}, {24, 29, 22}, {25, 30, 23}, {26, 31, 24}},
        {{15, 20, 12}, {16, 21, 13}, {17, 22, 14}, {18, 23, 15}, {19, 24, 16}, {20, 25, 17}, {21, 26, 18}}
    };

    // Menampilkan suhu kota ke-2 di hari ke-3 pada malam hari
    cout << "Suhu Kota 2 di Hari 3 (Malam): " << suhu[0][1][3] << "°C" << endl;

    return 0;
}

