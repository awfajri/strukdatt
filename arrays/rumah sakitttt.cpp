#include <iostream>
using namespace std;

int main() {

//RS ada 2
//Ruang ada 3 jenis : umum, bpjs,vip
//Hari ada 7

    int pasien[7][2][3] = {
       {{10,9}, {15,14},{5,6}}
       {{12,11},{17,16},{7,8}}
       {{8,10},{13,15},{4,5}}
       {{9,8},{14,12},{6,4}}
       {{11,7},{16,11},{8,7}}
       {{7,6},{12,10}{5,6}}
       {{6,5}, {11,9},{3,3}}
    };

    cout << "Jumlah pasien VIP di Rumah Sakit 2 pada hari ke-4: "
         << pasien[1][2] << endl;

    return 0;
}


