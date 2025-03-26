#include <iostream>
using namespace std;

int main() {
int x[5];
int *px;
px = x; // px =&x[0]

for (int i = 0; i < 5; i++) {
    cout<<"Masukkan Nilai "<<i+1<< " : ";
    cin >> x[i];
}
cout<<endl;
for (int i=0;i<5;i++) {
    cout<<"Nilai X["<<i<<"] : "<<*px<<endl;
    cout<<"Alamat X["<<i<<"] : "<<px<<endl;
}


}
