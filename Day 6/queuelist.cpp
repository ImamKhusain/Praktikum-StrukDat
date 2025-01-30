#include <bits/stdc++.h>
using namespace std;

struct node{
    int info;
    node *next;
};

node *depan, *belakang, *NB, *hapus, *bantu;

void buatq();
bool qkosong();
void enqueue(int IB);
void dequeue();
void cetakqueue();

int main(){
    buatq();
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(10);
    cetakqueue();
    dequeue();
    cout << endl;
    cetakqueue();
}

void buatq(){
    depan = NULL;
    belakang = NULL;
}

bool qkosong(){
    if(depan == NULL){
        return(true);
    } else {
        return(false);
    }
}

void enqueue(int IB){
    NB = new node();
    NB->info = IB;
    NB->next = NULL;

    if(qkosong()){
        depan = NB;
        belakang = NB;
    }else{
        belakang->next = NB;
        belakang = NB;
        NB->next = NULL;
    }
}

void dequeue(){
    if(qkosong()){
        cout << "antrian kosong" << endl;
    }else{
        hapus = depan;
        depan = hapus->next;
        free(hapus);
    }
}

void cetakqueue(){
       if(qkosong()){
        cout << "antrian kosong" << endl;
    }else{
        bantu = depan;
        while(bantu != NULL){
            cout << bantu->info << " ";
            bantu = bantu->next;
        }
    }
}