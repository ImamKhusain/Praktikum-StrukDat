#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;

int main(){
 struct data_nilai { 
	char nomhs[10];
    char nama[16];
    string univ;
    string fakultas;
	float nilai;
  };

  struct data_nilai nilaimhs[10];
  int i;

  for (i=1; i<=2; i++){
    cout << "+============================================+\n";
    cout << "|              INPUT DATA MHS                |\n";
    cout << "+============================================+\n";

  cout << "Nama  : "; cin >> nilaimhs[i].nama;
  cout << "Nomhs : "; cin >> nilaimhs[i].nomhs;
  cout << "Nilai : "; cin >> nilaimhs[i].nilai;
  cout << "Univ : "; cin >> nilaimhs[i].univ;
  cout << "Fakultas : "; cin >> nilaimhs[i].fakultas;  
  cout << endl;
  };

  for (i=1; i<=2; i++){
    cout << "+==========================================+\n";
    cout << "|              HASIL OUTPUT                |\n";
    cout << "+==========================================+\n";

  cout << "Nama  : " << nilaimhs[i].nama << '\n';
  cout << "Nomhs : " << nilaimhs[i].nomhs << '\n';
  cout << "Nilai : " << nilaimhs[i].nilai << '\n';
  cout << "Univ : " << nilaimhs[i].univ << '\n';
  cout << "fakultas : " << nilaimhs[i].fakultas << '\n'; 
  cout << endl;
  }

}