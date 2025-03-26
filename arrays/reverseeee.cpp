#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &mat) {
    int n = mat.size();

    // Transpose matrix
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Balik setiap baris untuk rotasi 90 derajat searah jarum jam
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}
