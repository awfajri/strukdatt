#include <iostream>
using namespace std;

main(){
struct mahasiswa
{
    char NPM[13];
    char nama[25];
}mhs;

    cin>>mhs.NPM;
    cin>>mhs.nama;
    cout<<mhs.NPM;
    cout<<mhs.nama<<"\n";

    return 0;
}

