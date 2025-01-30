//LINKED LIST HEADTAIL
#include <bits/stdc++.h>
using namespace std;

struct Nilai {
    int tugas, kuis, responsi;
    float nMean;  
};

struct Mahasiswa {
    string nim;
    string nama;
    Nilai nilai;
    Mahasiswa* next;
};

Mahasiswa* kepala = NULL;
Mahasiswa* ekor = NULL;

void buatlist() {
    kepala = new Mahasiswa();
    ekor = new Mahasiswa();
    kepala->nim = "HEAD";
    kepala->next = ekor;
    ekor->nim = "TAIL";
    ekor->next = NULL;
}

bool listkosong() {
    return (kepala->next == ekor);
}

float hitungRataRata(Nilai nilai) {
    return (nilai.tugas * 0.25) + (nilai.kuis * 0.35) + (nilai.responsi * 0.40);
}

void tambahMahasiswa(string nim, string nama, float tugas, float kuis, float responsi) {
    Mahasiswa* temp = kepala->next;
    while (temp != ekor) {
        if (temp->nim == nim) {
            cout << "NIM tidak bisa digunakan, sudah ada dalam sistem.\n";
            return;
        }
        temp = temp->next;
    }

    Mahasiswa* mahasiswaBaru = new Mahasiswa();
    mahasiswaBaru->nim = nim;
    mahasiswaBaru->nama = nama;
    mahasiswaBaru->nilai = {tugas, kuis, responsi};
    mahasiswaBaru->nilai.nMean = hitungRataRata(mahasiswaBaru->nilai);  

    if (listkosong()) {
        kepala->next = mahasiswaBaru;
        mahasiswaBaru->next = ekor;
    } else {
        Mahasiswa* bantu = kepala;
        while (bantu->next != ekor && bantu->next->nilai.nMean > mahasiswaBaru->nilai.nMean)  
            bantu = bantu->next;

        mahasiswaBaru->next = bantu->next;
        bantu->next = mahasiswaBaru;
    }
    cout << "Mahasiswa berhasil ditambahkan.\n";
}

void hapusMahasiswa(string nim) {
    if (listkosong()) {
        cout << "List masih kosong!\n";
    } else {
        Mahasiswa* bantu = kepala;
        while (bantu->next != ekor && bantu->next->nim != nim)
            bantu = bantu->next;

        if (bantu->next != ekor) {
            Mahasiswa* hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
            cout << "============================================" <<endl;
            cout << "Data mahasiswa dengan NIM " << nim << " telah dihapus.\n";
        } else {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan!\n";
        }
    }
}

void tampilkanMahasiswa() {
    if (listkosong()) {
        cout << "List masih kosong!\n";
    } else {
        Mahasiswa* temp = kepala->next;
        int peringkat = 1;
        cout << "Peringkat mahasiswa berdasarkan nilai rata-rata:\n";
        while (temp != ekor) {
            cout << peringkat++ << ". NIM: " << temp->nim << ", Nama: " << temp->nama << ", Rata-rata: " << temp->nilai.nMean << endl;  
            temp = temp->next;
            cout << "===============================================================\n";
        }
    }
}

int main() {
    buatlist();
    int pilihan;
    string nim, nama;
    float tugas, kuis, responsi;

    do {
        cout << "+=========================================+\n";
        cout << "|                MENU UTAMA               |\n";
        cout << "+=========================================+\n";
        cout << "| 1. Tambah Data                          |\n";
        cout << "| 2. Hapus Data                           |\n";
        cout << "| 3. Tampilkan Data                       |\n";
        cout << "| 4. Keluar                               |\n";
        cout << "+=========================================+\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan NIM: ";
                cin >> nim;
                cin.ignore();
                cout << "Masukkan Nama: ";
                getline(cin, nama);
                cout << "Masukkan Nilai Tugas: ";
                cin >> tugas;
                cout << "Masukkan Nilai Kuis: ";
                cin >> kuis;
                cout << "Masukkan Nilai Responsi: ";
                cin >> responsi;
                tambahMahasiswa(nim, nama, tugas, kuis, responsi);
                break;

            case 2:
                cout << "Masukkan NIM mahasiswa yang akan dihapus: ";
                cin >> nim;
                hapusMahasiswa(nim);
                break;
            case 3:
                tampilkanMahasiswa();
                break;
            case 4:
                cout << "+---------------------------+\n";
                cout << "| TERIMAKASIH TELAH MENCOBA |\n";
                cout << "|    PROGRAM INI TEMAN:)    |\n";
                cout << "+---------------------------+\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
        cout << endl;
    } while (pilihan != 4);

    return 0;
}
