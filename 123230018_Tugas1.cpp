#include <iostream>
#include <string>

using namespace std;

struct Pegawai {
    string nPegawai;
    int gaji;
    Pegawai* next;
};

Pegawai* buatNode(string nPegawai, int gaji) {
    Pegawai* newNode = new Pegawai;
    newNode->nPegawai = nPegawai;
    newNode->gaji = gaji;
    newNode->next = NULL;
    return newNode;
}

void sisipDepan(Pegawai*& head, string nPegawai, int gaji) {
    Pegawai* newNode = buatNode(nPegawai, gaji);
    newNode->next = head;
    head = newNode;
}

void sisipTengah(Pegawai*& head, string nPegawai, int gaji) {
    if (head == NULL) {
        sisipDepan(head, nPegawai, gaji);
        return;
    }

    cout << "Masukkan nama pegawai sebagai acuan: ";
    cin.ignore();
    string acuan;
    getline(cin, acuan);

    Pegawai* temp = head;
    while (temp != NULL) {
        if (temp->nPegawai == acuan) {
            Pegawai* newNode = buatNode(nPegawai, gaji);
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }

    cout << "Nama acuan tidak ditemukan!" << endl;
}

void sisipBelakang(Pegawai*& head, string nPegawai, int gaji) {
    Pegawai* newNode = buatNode(nPegawai, gaji);
    if (head == NULL) {
        head = newNode;
    } else {
        Pegawai* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void hapusData(Pegawai*& head, string nPegawai) {
    if (head == NULL) {
        cout << "Data kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    Pegawai* temp = head;
    Pegawai* prev = NULL;
    bool found = false;

    while (temp != NULL) {
        if (temp->nPegawai == nPegawai) {
            found = true;
            if (temp == head) {
                head = head->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    if (found) {
        cout << "+=================================+" << endl;
        cout << "|           DATA TERBARU          |" << endl;
        cout << "+=================================+" << endl;
        if (head == nullptr) {
            cout << "Tidak ada data pegawai." << endl;
        } else {
            Pegawai* temp = head;
            while (temp != NULL) {
                cout << "Nama Pegawai : " << temp->nPegawai << endl;
                cout << "Gaji Pegawai : Rp. " << temp->gaji << endl;
                cout << "---------------------------------" << endl;
                temp = temp->next;
            }
        }
        cout << "Nama pegawai berhasil dihapus." << endl;
    } else {
        cout << "Nama tidak ditemukan." << endl;
    }
}

void tampilkanData(Pegawai* head) {
    if (head == NULL) {
        cout << "Tidak ada data pegawai." << endl;
        return;
    }
    cout << "+=================================+" << endl;
    cout << "|           DATA PEGAWAI          |" << endl;
    cout << "+=================================+" << endl;
    Pegawai* temp = head;
    while (temp != NULL) {
        cout << "Nama Pegawai : " << temp->nPegawai << endl;
        cout << "Gaji Pegawai : Rp. " << temp->gaji << endl;
        cout << "---------------------------------" << endl;
        temp = temp->next;
    }
}

int main() {
    Pegawai* head = NULL;
    char back;

    do {
        cout << "+==============================+" << endl;        
        cout << "|          MENU UTAMA          |" << endl;
        cout << "+==============================+" << endl; 
        cout << "|1. TAMBAH DATA                |" << endl;
        cout << "|2. HAPUS DATA                 |" << endl;
        cout << "|3. TAMPILKAN DATA             |" << endl;
        cout << "|4. EXIT                       |" << endl;
        cout << "+==============================+" << endl; 
        cout << "Masukkan pilihan anda (1-4): ";
        int pilihan;
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "Masukkan nama pegawai: ";
                cin.ignore(); 
                string nama;
                getline(cin, nama);

                cout << "Masukkan gaji pegawai: Rp. ";
                int gaji;
                cin >> gaji;

                cout << "+==============================+" << endl;                
                cout << "|          TAMBAH DATA         |" << endl;
                cout << "+==============================+" << endl; 
                cout << "|1. SISIP DEPAN                |" << endl;
                cout << "|2. SISIP TENGAH               |" << endl;
                cout << "|3. SISIP BELAKANG             |" << endl;
                cout << "+==============================+" << endl; 
                cout << "Masukkan pilihan anda (1-3): ";
                int sisipPilihan;
                cin >> sisipPilihan;

                switch (sisipPilihan) {
                    case 1:
                        sisipDepan(head, nama, gaji);
                        break;
                    case 2:
                        sisipTengah(head, nama, gaji);
                        break;
                    case 3:
                        sisipBelakang(head, nama, gaji);
                        break;
                    default:
                        cout << "Pilihan sisip tidak valid." << endl;
                }
                break;
            }
            case 2: {
                cout << "Masukkan nama pegawai yang akan dihapus: ";
                cin.ignore();
                string nama;
                getline(cin, nama);
                hapusData(head, nama);
                break;
            }
            case 3:
                tampilkanData(head);
                break;
            case 4:
                cout << "+=================================================+\n";
                cout << "|Senang sekali Anda mau mencoba program ini!      |\n";
                cout << "|Kami berharap program ini memenuhi harapan Anda, |\n";
                cout << "|dan masukan Anda akan sangat berharga bagi kami. |\n";
                cout << "+=================================================+\n";
                return 0;
            default:
                cout << "Pilihan tidak valid." << endl;
        }

        cout << "Kembali ke menu ? (y/n) : ";
        cin >> back;
        cout << endl;

    } while (back == 'y' || back == 'Y');

    return 0;
}
