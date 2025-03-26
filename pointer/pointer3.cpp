#include <iostream>
using namespace std;

int main (){
    int x;
    int *px;
    int **ppx;

    x = 170;
    px = &x;
    ppx = &px;
    cout << "nilai x: " << x <<endl;
    cout << "nilai px: " <<*px<<endl;
    cout << "nilai ppx : " <<**ppx<<endl;

    return 0;
}
