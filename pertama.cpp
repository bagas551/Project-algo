#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
using namespace std;

struct Barang {
    int id_barang;
    char Nama_barang[100];
    int stok;
    int harga;
};  
struct DataBarang{
    Barang data;
    DataBarang* next;
};

DataBarang* head = NULL;

void simpanData(){
    FILE *data = fopen("swalayan.txt", "w");
    if(data == NULL) {
        if(data == NULL) {
            cout << "Gagal menyimpan file" << endl;
            return;
                }
    DataBarang* bantu = head;
    while(bantu) {
        fprintf(data, "%d;%s;%d;%d\n",
            bantu-> data.id_barang,
            bantu->data.Nama_barang,
            bantu->data.harga,
            bantu->data.stok
        );
    }
    fclose(data);
    }
}

void tambahBarang(){
    DataBarang* tambah = new DataBarang;

    cout << "Masukan Id Barang: ";
    cin >> tambah->data.id_barang;
    cout << "Masukkan Nama Barang: ";
    cin.ignore();
    cin.getline(tambah->data.Nama_barang, 100);
    cout << "Masukkan Harga Barang: ";
    cin >> tambah->data.harga;
    cout << "Masukkan Stok Barang: ";
    cin >> tambah->data.stok;
    tambah->next = head;
    head = tambah;

    simpanData();
    cout << "Data Berhasil Ditambahkan" << endl;
}
void tampilBarang() {
    DataBarang* bantu = head;
    if(!bantu) {
        cout << "Belum ada Barang di Toko Swalayan" << endl;
        return;
    }
    cout << left << setw(10) << "ID_BARANG" 
        << setw(15) << "Nama"
        << setw(15) << "Stok"
        << setw(10) << "Harga" << endl;
        
    while(bantu) {
        cout << setw(10) << bantu->data.id_barang
             << setw(15) << bantu->data.Nama_barang
             << setw(10) << bantu->data.stok
             << setw(10) << bantu->data.harga << endl;
             bantu =  bantu->next;
    }

}

// search (sequential search)

DataBarang* cariBarang(int id){
    DataBarang* bantu = head;

    while (bantu) {
        if(bantu->data.id_barang == id)
        return bantu;

        bantu = bantu->next;
    }
    return NULL;
}
void menuCari() {
    int cari;
    char cari_lagi;

    do {
        cout << "\n--- FITUR CARI BARANG ---" << endl;
        cout << "Masukkan ID Barang yang mau dicari: ";
        cin >> cari;

        DataBarang* hasil = cariBarang(cari);

        if (hasil != NULL) {
            cout << " Berhasil ketemu" << endl;
            cout << " Nama  : " << hasil->data.Nama_barang << endl;
            cout << " Stok  : " << hasil->data.stok << endl;
            cout << " Harga : " << hasil->data.harga << endl;
        } else {
            cout << " Yaahh Barang ini ga ketemu" << endl;
        }
        
        cout << "\n Mau cari barang lain? (y/t)";
        cin >> cari_lagi;
    } while (cari_lagi == 'y' || cari_lagi == 'Y');  
}

void sortBarang(bool asc){
    if (!head){
        cout << "\n Belum ada barang untuk diurutkan" << endl;
        return;
    }

    bool tukar;

    do{
        tukar = false;
        DataBarang* bantu = head;

        while (bantu->next) {

            if ((asc && bantu->data.harga > bantu->next->data.harga) || (!asc && bantu->data.harga < bantu->next->data.harga)) {

                Barang swap = bantu->data;
                bantu->data = bantu->next->data;
                bantu->next->data = swap;

                tukar = true;
            }
            bantu = bantu->next;
        }
    } while (tukar);

    cout << "\n Data berhasil diurutkan";
    if (asc == true) {
        cout << "ASCENDING (Murah ke Mahal)" << endl;
    } else {
        cout << "Urut secara Descending" << endl;
    }
    
}
void updateStok(){
    int id_baru;
    int stok_baru;
    cout << "Masukkan ID: ";
    cin >> id_baru;
    DataBarang* ada = cariBarang(int i);
    if(ada) {
        cout << "Masukkan stok baru: ";
        cin>> stok_baru;
        ada->data.stok = stok_baru;
        simpanData();
    cout << "Stok berhasil diupdate" << endl;

    } else
    cout << "Barang tidak ditemukan" << endl;
}


void menuSort() {
    int pilihanSort;
    cout << "\n === Urut Berdasarkan Harga ===" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "Pilih urutan (1/2): ";
    cin >> pilihanSort;

    if (pilihanSort == 1) {
        sortBarang(true);
        tampilBarang();
    } else if (pilihanSort == 2) {
        sortBarang(false);
        tampilBarang();
    } else {
        cout << "\n Pilihan tidak valid" << endl;
    }
}
