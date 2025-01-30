#include <iostream>
using namespace std;

struct node{
    int info;
    node* kanan;
    node* kiri;
};

node *awal, *akhir, *bantu, *nb, *hapus, *help;

void buatlist();
bool listkosong();
void sisipnode(int IB);
void hapusnode(int IH);
void cetakdepan();
void cetakbelakang();

int main(){
    system("cls");
    buatlist();
    sisipnode(50); //sisip awal
    sisipnode(10); //sisip depan
    sisipnode(40); //sisip tengah 
    sisipnode(5); //sisip depan
    sisipnode(60); //sisip belakang
    cout << "Cetak Depan\t: ";
    cetakdepan();
    hapusnode(5); //hapus depan
    cout << "\nCetak Depan\t: ";
    cetakdepan();
    hapusnode(40); //hapus tengah
    cout << "\nCetak Belakang\t: ";
    cetakbelakang();
}

void buatlist(){
    awal = NULL;
    akhir = NULL;
}

bool listkosong(){
    if(awal == NULL)
        return(true);
    else
    return(false);
}

void sisipnode(int IB){
    nb = new node();
    nb->info = IB;
    nb->kiri = NULL;
    nb->kanan = NULL;
    //sisip list kosong
    if (listkosong()){
        awal = nb;
        akhir = nb;
    } else if(IB <= awal -> info){//sisipdepan
        nb->kanan = awal;
        awal->kiri = nb;
        awal = nb;
    } else if (IB <= akhir -> info){//sisiptengah
        bantu = awal;
        while(bantu -> kanan != NULL && bantu -> kanan -> info < IB)
            bantu = bantu->kanan;

        help = bantu -> kanan;
        nb->kanan = help;
        help->kiri = nb;
        bantu->kanan = nb;
        nb -> kiri = bantu;
    } else {//sisipbelakang
        bantu = awal;
        while(bantu != akhir && bantu->kanan->info < IB)
            bantu = bantu->kanan;

        bantu->kanan = nb;
        nb->kiri = bantu;
        akhir = nb;
    }
}

void hapusnode(int IH){
    if (listkosong()) {
        cout << "List Kosong" << endl;
    } else if(awal->info == IH){//hapusdepan
        hapus = awal;
        if(awal == akhir)
            buatlist();
            else{
                awal = hapus->kanan;
                awal->kiri = NULL;
                free (hapus);
            }
    } else {
        bantu = awal;
        while(bantu != akhir && bantu->kanan->info != IH)
            bantu = bantu->kanan;

        if(bantu->kanan->info == IH){
            hapus = bantu-> kanan;
            if(hapus == akhir){ //hapusbelakang
                bantu->kanan = NULL;
                akhir = bantu;
                free(bantu);
            } else { //hapustengah
                help = hapus->kanan;
                bantu->kanan = hapus->kanan;
                help->kiri = bantu;
                free(hapus);
            }
        } else {
            cout << "Node " << IH << " Tidak Ada " << endl;
        }
    }
}

void cetakdepan(){
    bantu = awal;
    if(listkosong())
        cout << "List Kosong";
    else {
        while(bantu != NULL){
            cout << bantu->info << " ";
            bantu = bantu->kanan;
        }
    }
}

void cetakbelakang(){
    bantu = akhir;
    if(listkosong())
        cout << "List Kosong";
    else {
        while(bantu != NULL){
            cout << bantu->info << " ";
            bantu = bantu->kiri;
        }
    }
}