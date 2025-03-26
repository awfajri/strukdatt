#include <iostream>
using namespace std;

int main (){
    int angka = 120;
    int *ptrAngka = &angka;

    cout << angka <<endl;
    cout << *ptrAngka << endl;
    cout << ptrAngka << endl;
    cout << &angka << endl;

    *ptrAngka = 1500;

    cout <<"---------" << endl;
    cout << angka << endl;
    cout << *ptrAngka << endl;
    cout << ptrAngka << endl;
    cout << &angka << endl;

    return 0;

}
