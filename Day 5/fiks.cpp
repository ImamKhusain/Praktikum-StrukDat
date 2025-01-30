#include <bits/stdc++.h>
using namespace std;
#define MAX 30

struct Buku {
    string namaBuku;
    string penulis;
    Buku* next;
    Buku* prev;
};

Buku* top = NULL;
Buku* bottom = NULL;
Buku* newBuku;
Buku* hapus;
Buku* temp;

int countBuku(); 

void buatStack() {
    top = NULL;
    bottom = NULL;
}

bool StackKosong() {
    return top == NULL;
}

void pushBuku(string namaBuku, string penulis) {
    newBuku = new Buku();
    newBuku->namaBuku = namaBuku;
    newBuku->penulis = penulis;
    newBuku->next = NULL;
    newBuku->prev = NULL;

    if (StackKosong()) {
        top = newBuku;
        bottom = newBuku;
    } else {
        top->next = newBuku;
        newBuku->prev = top;
        top = newBuku;
    }
    cout << "Buku berhasil ditambahkan.\n";
}

void popBuku(string namaBuku) {
    if (StackKosong()) {
        cout << "Stack Kosong\n";
        return;
    }
    
    temp = top;
    while (temp != NULL) {
        if (temp->namaBuku == namaBuku) {
            cout << "Ambil Buku:\n";
            cout << "Judul Buku: " << temp->namaBuku << "\n";
            cout << "Penulis: " << temp->penulis << "\n";
            hapus = temp;
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                top = temp->next; // Jika buku yang diambil adalah yang teratas
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            } else {
                bottom = temp->prev; // Jika buku yang diambil adalah yang terbawah
            }
            delete hapus;
            cout << "[TELAH DIAMBIL]\n";
            return;
        }
        temp = temp->prev;
    }
    cout << "Judul buku tidak ditemukan.\n";
}

void popBukuTop() {
    if (StackKosong()) return;
    
    hapus = top;
    if (top->prev != NULL) {
        top = top->prev;
        top->next = NULL;
    } else {
        top = NULL;
        bottom = NULL;
    }
    delete hapus;
}

void daftarBuku() {
    if (StackKosong()) {
        cout << "Stack Kosong\n";
    } else {
        cout << "+=========================+\n";
        cout << "|       Daftar Buku       |\n";
        cout << "+=========================+\n";
        temp = bottom;
        while (temp != NULL) {
            cout << "[" << temp->namaBuku << ", " << temp->penulis << "]\n";
            temp = temp->next;
        }
        cout << "Jumlah Buku: " << countBuku() << "\n";
    }
}

void hapusStack() {
    while (!StackKosong()) {
        popBukuTop(); // Menghapus dari atas hingga stack kosong
    }
    cout << "[SEMUA BUKU TELAH DIHAPUS]\n";
}

void editBuku(string bukuLama) {
    temp = top;
    while (temp != NULL) {
        if (temp->namaBuku == bukuLama) {
            cout << "Edit Data Buku:\n";
            cout << "Judul Buku Lama: " << temp->namaBuku << "\n";
            cout << "Penulis Lama: " << temp->penulis << "\n";
            cout << "Judul Buku Baru: ";
            getline(cin, temp->namaBuku);
            cout << "Penulis Baru: ";
            getline(cin, temp->penulis);
            cout << "[DATA BUKU DIPERBARUI]\n";
            return;
        }
        temp = temp->prev;
    }
    cout << "Judul buku tidak ditemukan.\n";
}

int countBuku() {
    int count = 0;
    temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->prev;
    }
    return count;
}

int main() {
    int choice;
    string namaBuku, penulis;

    do {
        cout << "+=========================+\n";
        cout << "|       DAFTAR MENU       |\n";
        cout << "+=========================+\n";
        cout << "|1. Taruh Buku            |\n";
        cout << "|2. Ambil Buku            |\n";
        cout << "|3. Daftar Buku           |\n";
        cout << "|4. Buang Semua Buku      |\n";
        cout << "|5. Edit Data Buku        |\n";
        cout << "|6. Keluar                |\n";
        cout << "+=========================+\n";
        cout << "Pilih Menu: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                int jumlah;
                cout << "Jumlah Buku yang akan dimasukkan: ";
                cin >> jumlah;
                cin.ignore();

                if (countBuku() + jumlah > MAX) { 
                    cout << "Error: Jumlah buku yang dimasukkan akan melebihi batas maksimal (" << MAX << ").\n";
                    break;
                }
                for (int i = 0; i < jumlah; i++) {
                    cout << "Judul Buku: ";
                    getline(cin, namaBuku);
                    cout << "Penulis: ";
                    getline(cin, penulis);
                    pushBuku(namaBuku, penulis);
                }
                break;
            }
            case 2: {
                cout << "Masukkan Judul Buku yang ingin diambil: ";
                getline(cin, namaBuku);
                popBuku(namaBuku);
                break;
            }
            case 3:
                daftarBuku();
                break;
            case 4:
                hapusStack();
                break;
            case 5: {
                cout << "Masukkan Judul Buku yang ingin diedit: ";
                getline(cin, namaBuku);
                editBuku(namaBuku);
                break;
            }
            case 6:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 6);
    return 0;
}
