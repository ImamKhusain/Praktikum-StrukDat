#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;
int main()
{
    struct kampus{
        string univ, fakultas;
    };
    struct data_nilai{
        char nomhs[10];
        char nama[16];
        float nilai;
        kampus mampus;
 };
 struct data_nilai nilmhs, *ptrnil;
 ptrnil=(data_nilai *) malloc (sizeof(data_nilai));
 ptrnil=&nilmhs;
 strcpy(nilmhs.nomhs,"123090000");
 strcpy(nilmhs.nama,"Sponsbob");
 nilmhs.nilai=95.00;
 nilmhs.mampus.univ = "UPN";
 nilmhs.mampus.fakultas = "FTI";

 cout << "Nama : " << nilmhs.nama << '\n';
 cout << "Nomhs : " << nilmhs.nomhs << '\n';
 cout << "Nilai : " << nilmhs.nilai << '\n';
 cout << "Univ : " << nilmhs.mampus.univ << '\n';
 cout << "Fakultas : " << nilmhs.mampus.fakultas << '\n';
 cout << endl;
}
 //ptrnil->nilai=75;
 //cout << "Nama : " << ptrnil->nam

//int main(){

/*  struct data_nilai { 
	char nomhs[10];
    char nama[16];
	float nilai;
  };

  struct data_nilai nilaimhs[10];
  int i;

  for (i=1; i<=2; i++){
  cout << "Nama  : "; cin >> nilaimhs[i].nama;
  cout << "Nomhs : "; cin >> nilaimhs[i].nomhs;
  cout << "Nilai : "; cin >> nilaimhs[i].nilai;
  cout << endl;
  };

  for (i=1; i<=2; i++){
  cout << "Nama  : " << nilaimhs[i].nama << '\n';
  cout << "Nomhs : " << nilaimhs[i].nomhs << '\n';
  cout << "Nilai : " << nilaimhs[i].nilai << '\n';
  cout << endl;
  }
}*/

