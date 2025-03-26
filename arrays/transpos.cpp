#include <iostream>
using namespace std;
int main() {
    int A[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    cout << "Matriks Awal:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    int B[3][2]; // Transpos
    // Menghitung transpos
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            B[j][i] = A[i][j];
        }
    }
    // Menampilkan hasil transpos
    cout << "Matriks Transpos:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

