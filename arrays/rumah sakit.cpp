#include <iostream>
using namespace std;

int main() {

//RS ada 2
//Ruang ada 3 jenis : umum, bpjs,vip
//Hari ada 7

    int pasien[2][3][7] = {
        { {10, 12, 8, 9, 11, 7, 6}, {15, 17, 13, 14, 16, 12, 11}, {5, 7, 4, 6, 8, 5, 3} }, // RS 1
        { {9, 11, 10, 8, 7, 6, 5}, {14, 16, 15, 12, 11, 10, 9}, {6, 8, 5, 4, 7, 6, 3} }  // RS 2
    };

    cout << "Jumlah pasien VIP di Rumah Sakit 2 pada hari ke-4: "
         << pasien[0][0][3] << endl;

    return 0;
}


