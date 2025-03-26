#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Nama: Auf Fajri Ramadhani" << endl <<"NPM: 2410631170059"<< endl;
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;

    int matrix[10][10];

    // Input elemen matriks
    cout << "Masukkan elemen matriks: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    cout << "Matriks sebelum rotasi:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - 1 - layer;

        for (int i = first; i < last; i++) {
            int offset = i - first;

            // Simpan elemen atas
            int top = matrix[first][i];

            // Geser kiri ke atas
            matrix[first][i] = matrix[last - offset][first];

            // Geser bawah ke kiri
            matrix[last - offset][first] = matrix[last][last - offset];

            // Geser kanan ke bawah
            matrix[last][last - offset] = matrix[i][last];

            // Geser atas ke kanan
            matrix[i][last] = top;
        }
    }


    cout << "Matriks setelah rotasi 90 derajat:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
