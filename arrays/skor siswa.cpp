#include <iostream>
using namespace std;
int main() {
    const int siswa = 4;
    const int ujian = 3;

    int skor[siswa][ujian] = {
        {85, 90, 78},
        {76, 88, 95},
        {92, 85, 91},
        {89, 77, 82}
    };

    cout << "Skor Ujian & Rata-rata:\n";
    for (int i = 0; i < siswa; i++) {
        int total = 0;
        cout << "Siswa " << i+1 << ": ";
        for (int j = 0; j < ujian; j++) {
            cout << skor[i][j] << " ";
            total += skor[i][j];
        }
        cout << "| Rata-rata: " << total / ujian << endl;
    }
    return 0;
}

