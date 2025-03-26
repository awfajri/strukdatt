#include <iostream>
#include <map>
#include <string>

using namespace std;

void compress(const string& input) {
    map<char, int> freq;

    for (char c : input) {
        if (c != ' ') {
            freq[c]++;
        }
    }

    cout << "hasil kompresi nama kamu: ";
    for (const auto& pair : freq) {
        cout << pair.first << pair.second << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "nama kamu siapaa: ";
    getline(cin, input);

    compress(input);

    return 0;
}
