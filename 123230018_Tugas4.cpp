#include <bits/stdc++.h>
using namespace std;

struct Paket {
    string nBarang; // Nama Barang
    string aTujuan; // Alamat Tujuan Pengiriman
    string nResi; // Nomor Resi
    Paket *next;
};

Paket *depan, *belakang, *NB, *hapus, *bantu;

void buatQueue(){
    depan = NULL;
    belakang = NULL;
}

bool queueKosong() {
    return depan == NULL;
}

void enqueue(string nBarang, string aTujuan, string nResi) {
    NB = new Paket();
    NB->nBarang = nBarang;
    NB->aTujuan = aTujuan;
    NB->nResi = nResi;
    NB->next = NULL;

    if(queueKosong()) {
        depan = NB;
        belakang = NB;
    } else {
        belakang->next = NB;
        belakang = NB;
    }
}

void dequeue() {
    if (queueKosong()) {
        cout << "Antrian Kosong, Paket Sudah Dikirim Semua Kawan!!!\n";
    } else {
        hapus = depan;
        cout << "+==============================+\n";
        cout << "|          KIRIM PAKET         |\n";
        cout << "+==============================+\n";
        cout << "|Nama Barang : " << setw(16) << left << hapus->nBarang << "|\n";
        cout << "|No Resi     : " << setw(16) << left << hapus->nResi << "|\n";
        cout << "+==============================+\n";
        cout << "Paket Sedang Dikirimkan ke " << hapus->aTujuan << "\n";

        depan = hapus->next;
        delete hapus;
    }
}

void cetakQueue() {
    if(queueKosong()) {
        cout << "Antrian kosong.\n";
    } else {
        bantu = depan;
        int jumlah = 0;
        cout << "+==============================+\n";
        cout << "|         PAKET MASUK          |\n";
        cout << "+==============================+\n";
        
        while(bantu != NULL) {
            jumlah++;
            cout << "Nama Barang : " << bantu->nBarang << "\n";
            cout << "Tujuan      : " << bantu->aTujuan << "\n";
            cout << "No Resi     : " << bantu->nResi << "\n\n";
            bantu = bantu->next;
        }
        cout << "Jumlah Paket Masuk : " << jumlah << "\n";
    }
}

int main() {
    int pilihan;
    do {
        cout << "+==============================+\n";
        cout << "|          MENU PAKET          |\n";
        cout << "+==============================+\n";
        cout << "|1. Paket Masuk                |\n";
        cout << "|2. Kirim Paket                |\n";
        cout << "|3. Lihat Antrian              |\n";
        cout << "|4. Keluar                     |\n";
        cout << "+==============================+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch(pilihan) {
            case 1: {
                int jumlahPaket;
                cout << "Masukkan jumlah paket yang ingin diinput: ";
                cin >> jumlahPaket;
                cin.ignore();
                
                for(int i = 0; i < jumlahPaket; i++) {
                    string nBarang, aTujuan, nResi;
                    cout << "Nama Barang: ";
                    getline(cin, nBarang);
                    cout << "Alamat Tujuan: ";
                    getline(cin, aTujuan);
                    cout << "Nomor Resi: ";
                    getline(cin, nResi);
                    enqueue(nBarang, aTujuan, nResi);
                    cout << "\n";
                }
                cout << "Paket berhasil ditambahkan ke dalam antrian.\n";
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                cetakQueue();
                break;
            case 4:
                cout << "+=================================================+\n";
                cout << "|Senang sekali Anda mau mencoba program ini!      |\n";
                cout << "|Kami berharap program ini memenuhi harapan Anda, |\n";
                cout << "|dan masukan Anda akan sangat berharga bagi kami. |\n";
                cout << "+=================================================+\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
                break;
        }
    } while(pilihan != 4);
    return 0;
}