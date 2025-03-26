#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

struct dataKtp {
    char nama [50];
    char alamat [50];
    char golongandarah [50];
    dataKtp *next, *prev;
    };

dataKtp *awal = NULL, *akhir = NULL, *bantu , *baru;

void inputDataDepan (){
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama :";
    cin >> baru->nama;
    cout << "alamat :";
    cin >> baru->alamat;
    cout << "Golongan darah :";
    cin >> baru->golongandarah;

    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        baru->next = awal;
        baru->prev = baru;
        awal = baru;
    }
    system ("cls")
}
void inputDataBelakang (){
    baru = new dataKtp;
    baru->next = NULL;
    baru->prev = NULL;
    cout << "Nama :";
    cin >> baru->nama;
    cout << "alamat :";
    cin >> baru->alamat;
    cout << "Golongan darah :";
    cin >> baru->golongandarah;

    if (awal == NULL) {
        awal = akhir = baru;
    } else {
        baru->next = baru;
        baru->prev = akhir;
        akhir = baru;
    }
    system ("cls")
}
void outputData (){
    bantu = awal;
    while (bantu != NULL){
        cout << "nama: " << bantu->nama << endl;
        bantu = bantu->next;
    }
}
int main(){
    int pilihan;
    do {
        cout << "1. Input depan\n";
        cout << "2. Input belakang\n";
        cout << "3. output\n";
        cout << "4. exit\n";
        cout << "pilihan";
        cin >> pilihan;

        switch (pilihan){
            case 1;
            inputDataDepan();
            break;
            case 2;
            inputDataBelakang();
            break;
            case 3;
            if(baru = NULL){
                cout << "data kosong ";
            }else {
                outputData;
            }
            break;
            default;
            cout << "exit";
            break;
        } while (pilihan!=4)
    }
    return 0;
}
