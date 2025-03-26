#include <iostream>
using namespace std;
int main() {
    int A[2][2] = {{2, 9}, {5, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2]; // Hasil penjumlahan

    // Menjumlahkan kedua matriks
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    // Menampilkan hasil
    cout << "Hasil Penjumlahan Matriks:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
