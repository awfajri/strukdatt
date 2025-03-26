#include <iostream>
using namespace std;

int main (){
    int x[10] = {12,35,20,23,54,49,81,92,119,29};
    int i;
    int min = 1000;
    int maks = -1000;
    for(i=0;i<10; i++){
        if(x[i] > maks)
        {
            maks=x[i];
        }
        if (x[i]< min)
        {
            min = x[i];
        }
    }
    cout <<"nilai maksimum : "<<maks<<endl;
    cout <<"nilai minimum : "<<min<<endl;

    return 0;
}
