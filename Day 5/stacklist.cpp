#include <bits/stdc++.h>
using namespace std;

struct node {
    int info;
    node *next;
    node *prev;
};

node *top, *bottom, *NB, *hapus, *bantu;

void buatstack();
bool stackkosong();
void push(int IB);
void pop();
void cetakstack();
int hitungstack();  // Perbaikan nama fungsi

int main() {
    system("cls");
    buatstack();
    // push(50);
    // push(20);
    // push(30);
    // push(10);
    // push(40);
    // push(60);

    cout << "Stack awal : " << endl;
    cetakstack();
    cout << "Jumlah elemen dalam stack: " << hitungstack() << endl;  // Menampilkan jumlah

    pop();
    cout << "Setelah Pop : " << endl;
    cetakstack();
    cout << "Jumlah elemen dalam stack: " << hitungstack() << endl;  // Menampilkan jumlah lagi
}

void buatstack() {
    top = NULL;
    bottom = NULL;
}

int hitungstack() {
    if (stackkosong()) {
        return 0;
    } else {
        int jumlah = 0;
        bantu = top;
        while (bantu != NULL) {
            bantu = bantu->prev;
            jumlah++;
        }
        return jumlah;
    }
}

bool stackkosong() {
    return top == NULL;
}

void push(int IB) {
    NB = new node();
    NB->info = IB;
    NB->next = NULL;
    NB->prev = NULL;

    if (stackkosong()) {
        top = NB;
        bottom = NB;
    } else {
        top->next = NB;
        NB->prev = top;
        top = NB;
    }
}

void pop() {
    if (stackkosong()) {
        cout << "Stack Kosong" << endl;
    } else {
        hapus = top;
        top = top->prev;
        if (top != NULL) {
            top->next = NULL;
        } else {
            bottom = NULL;  // Jika stack menjadi kosong
        }
        delete hapus;
    }
}

void cetakstack() {
    bantu = top;
    while (bantu != NULL) {
        cout << bantu->info << endl;
        bantu = bantu->prev;
    }
}