#include <iostream>
using namespace std;

int main() {
    const int fakultas = 3;
    const int prodi = 3;
    const int matkul = 3;
    const int semester = 4;

    double nilai[fakultas][prodi][matkul][semester];

    // Meminta input nilai rata-rata
    cout << "Masukkan nilai rata-rata setiap mata kuliah untuk 4 semester terakhir:\n";
    for (int f = 0; f < fakultas; f++) {
        for (int p = 0; p < prodi; p++) {
            for (int m = 0; m < matkul; m++) {
                for (int s = 0; s < semester; s++) {
                    cout << "Fakultas " << f + 1 << ", Prodi " << p + 1
                         << ", Mata Kuliah " << m + 1 << ", Semester " << s + 1 << ": ";
                    cin >> nilai[f][p][m][s];
                }
            }
        }
    }

    // Menghitung rata-rata nilai tiap fakultas selama 4 semester
    cout << "\nRata-rata nilai tiap fakultas selama 4 semester:\n";
    for (int f = 0; f < fakultas; f++) {
        double total = 0;
        int count = 0;

        for (int p = 0; p < prodi; p++) {
            for (int m = 0; m < matkul; m++) {
                for (int s = 0; s < semester; s++) {
                    total += nilai[f][p][m][s];
                    count++;
                }
            }
        }

        double rataRata = total / count;
        cout << "Fakultas " << f + 1 << ": " << rataRata << endl;
    }

    // Menentukan semester dengan nilai rata-rata tertinggi untuk setiap fakultas
    cout << "\nSemester dengan nilai rata-rata tertinggi untuk setiap fakultas:\n";
    for (int f = 0; f < fakultas; f++) {
        double maxRata = 0;
        int semesterTerbaik = 0;

        for (int s = 0; s < semester; s++) {
            double total = 0;
            int count = 0;

            for (int p = 0; p < prodi; p++) {
                for (int m = 0; m < matkul; m++) {
                    total += nilai[f][p][m][s];
                    count++;
                }
            }

            double rataSmt = total / count;
            if (rataSmt > maxRata) {
                maxRata = rataSmt;
                semesterTerbaik = s;
            }
        }

        cout << "Fakultas " << f + 1 << " memiliki nilai tertinggi di Semester "
             << semesterTerbaik + 1 << " (" << maxRata << ")\n";
    }

    return 0;
}
