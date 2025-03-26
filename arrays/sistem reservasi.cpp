#include <iostream>
using namespace std;

int main() {
    int bioskop[5][6] = {
        {1, 0, 0, 1, 0, 1},
        {0, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1, 0},
        {1, 0, 1, 0, 0, 1}
    };

    cout << "Tampilan Kursi Bioskop (1 = Terisi, 0 = Kosong):\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << bioskop[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

