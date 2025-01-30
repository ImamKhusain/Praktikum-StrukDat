#include <bits/stdc++.h>
using namespace std;
#define MAX 30

struct Buku {
    string namaBuku;
    string penulis;
    Buku* next;
};

Buku* top = NULL;
Buku* newBuku;
Buku* hapus;
Buku* temp;

int countBuku(); 

void buatStack() {
    top = NULL;
}

bool StackKosong() {
    return top == NULL;
}

void pushBuku(string namaBuku, string penulis) {
    newBuku = new Buku();
    newBuku->namaBuku = namaBuku;
    newBuku->penulis = penulis;
    newBuku->next = top; // Menambahkan buku baru di atas stack
    top = newBuku;
    cout << "Buku berhasil ditambahkan.\n";
}

void popBuku(string namaBuku) {
    if (StackKosong()) {
        cout << "Stack Kosong\n";
        return;
    }

    temp = top;
    Buku* prev = NULL; // Untuk menyimpan node sebelumnya
    while (temp != NULL) {
        if (temp->namaBuku == namaBuku) {
            cout << "Ambil Buku:\n";
            cout << "Judul Buku: " << temp->namaBuku << "\n";
            cout << "Penulis: " << temp->penulis << "\n";
            hapus = temp;
            if (prev != NULL) {
                prev->next = temp->next; // Menghubungkan node sebelumnya ke node berikutnya
            } else {
                top = temp->next; // Jika buku yang diambil adalah yang teratas
            }
            delete hapus;
            cout << "[TELAH DIAMBIL]\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Judul buku tidak ditemukan.\n";
}

void popBukuTop() {
    if (StackKosong()) return;

    hapus = top;
    top = top->next; // Menghapus buku teratas
    delete hapus;
}

void daftarBuku() {
    if (StackKosong()) {
        cout << "Stack Kosong\n";
    } else {
        cout << "+=========================+\n";
        cout << "|       Daftar Buku       |\n";
        cout << "+=========================+\n";
        temp = top;
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
        temp = temp->next;
    }
    cout << "Judul buku tidak ditemukan.\n";
}

int countBuku() {
    int count = 0;
    temp = top;
    while (temp != NULL) {
        count++;
        temp = temp->next;
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