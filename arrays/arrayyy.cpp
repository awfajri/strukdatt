#include <iostream>
using namespace std;

int main() {
    int matrixA[2][2];
    int matrixB[2][2];

    // Input untuk matrixA
    for (int i = 0; i < 2; i++) {  // Perbaikan loop
        for (int j = 0; j < 2; j++) {
            cout << "Masukkan nilai matrix A [" << i << "][" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }
9

    // Menampilkan matrix A
    cout << "Matrix A:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    // Input untuk matrixB
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {  // Perbaikan kondisi loop
            cout << "Masukkan nilai matrix B [" << i << "][" << j << "] : ";
            cin >> matrixB[i][j];  // Memasukkan nilai ke matrixB
        }
    }

    // Menampilkan matrix B
    cout << "Matrix B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    // Penjumlahan dua matriks
    int matrixC[2][2];
    cout << "Hasil penjumlahan Matrix A + B:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrixC[i][j] = matrixA[i][j] + matrixB[i][j];
            cout << matrixC[i][j] << " ";  // Perbaikan kesalahan cout
        }
        cout << endl;
    }

    return 0;
}
