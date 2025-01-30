#include <iostream>
using namespace std;

int main(){
    int a = 5;
    cout << "Alamat A : " << &a << endl;
    cout << "Nilai A : " << a << endl;

    int *b = &a;
    *b = 10;
    cout << "Alamat A : B : " << &a << " : " << b << endl;
    cout << "Nilai A : B " << a << " : " << *b << endl;
}