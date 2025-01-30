#include <bits/stdc++.h>
using namespace std;
#define MAX 50

int top=0;
int stack[50];
//SATCK[50];
void buatStack();
bool isEmpty();
bool isFull();
void push(int IB);
void pop();
void cetakStack();

void buatStack(){
    stack[0]=0; // pastikan stack[0] = 0 
}

bool isEmpty(){
    if(top==0){
        return(true);
    }
    return(false);
}

bool isFull(){
    if(top==MAX-1){
        return(true);
    }
    return(false);
}

void push(int IB){
    if(isFull()){
        cout<<"/nStack is overflow";
    } else{
        top++; //increment top untuk ke elemen selanjutnya 
        stack[top]=IB; //masukkan IB ke elemen top
        stack[0]=top; //update index 0 
    }
}

void pop(){
    int IP;
    if(isEmpty()){
        cout << "\nStack is underflow";
    } else {
        IP=stack[top]; //menyimpan elemen info hapus
        top--; //decrement top untuk turun ke bawah
        stack[0]=top; //update index 0
        cout << "\nIP= " << IP; //mencetak info yang akan dihapus (opsinal)
        cout << endl;
    }
}

void cetakStack(){
    for(int i=top; i>0; i--){
        cout << stack[i] << endl;
    }
}

int main() {
buatStack();
push(15);
push(21);
push(89);
push(88);
push(90);
cetakStack();
cin.get(); //untuk menunggu inputan user

cout << "\n hasil setelah pop";
pop();
cetakStack();

    return 0;
}