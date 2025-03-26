#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {10, 25, 30},
        {15, 40, 50},
        {5, 60, 20}
    };
    int maxVal = matrix[0][0]; // Inisialisasi dengan elemen pertama

    // Mencari nilai maksimum
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
    }
    cout << "Elemen terbesar dalam matriks adalah: " << maxVal << endl;
    return 0;
}
