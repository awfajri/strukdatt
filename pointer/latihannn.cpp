#include <iostream>
#include <string>

using namespace std;

void compress(const string& input) {
    int jumlahHuruf[256] = {0};

    for (char c : input) {
        if (c != ' ') {
            jumlahHuruf[c]++;
        }
    }

    cout << "ini hasil kompresi nama kamuu: ";
    for (int i = 0; i < 256; i++) {
        if (jumlahHuruf[i] > 0) {
            cout << (char)i << jumlahHuruf[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Nama kamu siapaa: ";
    getline(cin, input);

    compress(input);

    return 0;
}
