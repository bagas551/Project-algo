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
        bantu = bantu->next;
    }
    fclose(data);
    }
}

void tambahBarang(){
    int jumlah;
    cout << "Jumlah tambah data barang :";
    cin >> jumlah;
    if (jumlah <= 0) {
        cout << "Data barang harus lebih dari 0" << endl;
        return;
    }

    for(int i =0; i < jumlah; i++){
    DataBarang* tambah = new DataBarang;
    cout << "Data Barang ke-" << i+1;
    cout << "Masukan Id Barang: ";
    cin >> tambah->data.id_barang;

    cout << "Masukkan Nama Barang: ";
    cin.ignore(1000, '\n');
    cin.getline(tambah->data.Nama_barang, 100);

    cout << "Masukkan Harga Barang: ";
    cin >> tambah->data.harga;
    if(tambah->data.harga < 0) {
        cout << "Harga Barang tidak boleh negatif" << endl;
        delete tambah;
        i--;
        continue;
    }

    cout << "Masukkan Stok Barang: ";
    cin >> tambah->data.stok;
    if(tambah->data.stok < 0) {
        cout << "Stok Barang tidak boleh negatif" << endl;
        delete tambah;
        i--;
        continue;;
    }

    tambah->next = head;
    head = tambah;
    }
    simpanData();
    cout << "Data Berhasil Ditambahkan" << endl;
}
void tampilBarang() {
    DataBarang* bantu = head;
    if(!bantu) {
        cout << "Belum ada Barang di Toko Swalayan" << endl;
        return;
    }

    cout << "\n=============================================\n";
    cout << left << setw(10) << "ID_BARANG" 
        << setw(20) << "Nama"
        << setw(10) << "Stok"
        << setw(10) << "Harga" << endl;

    cout << "\n=============================================\n";       
    while(bantu) {
        cout << left << setw(10) << bantu->data.id_barang
             << setw(20) << bantu->data.Nama_barang
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

    if (head == NULL) {
        cout << "Belum ada data barang" << endl;
        return;
    }

    do {
        cout << "\n--- FITUR CARI BARANG ---" << endl;
        cout << "Masukkan ID Barang yang mau dicari: ";
        cin >> cari;

        DataBarang* hasil = cariBarang(cari);

        if (hasil != NULL) {
            cout << " Berhasil ketemu" << endl;
            cout << "=====================================\n";
            cout << left << setw(10) << "ID"
                 << setw(20) << "Nama"
                 << setw(10) << "Stok"
                 << setw(10) << "Harga" << endl;
            cout << "=====================================\n";
               
            cout << setw(10) << hasil->data.id_barang
                 << setw(20) << hasil->data.Nama_barang
                 << setw(10) << hasil->data.stok
                 << setw(10) << hasil->data.harga << endl;
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
    DataBarang* ada = cariBarang(id_baru);
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

void hapusBarang(){
    int id;
    cout <<"Masukkan ID: ";
    cin >> id;

    DataBarang *bantu = head;
    DataBarang *prev = NULL;

    while (bantu && bantu->data.id_barang != id){
        prev = bantu;
        bantu = bantu->next;
    }

    if (!bantu){
        cout << "Data tidak ditemukan!\n";
        return;
    }

    if(!prev) {
        head = bantu->next;
        cout << "Hapus barang paling didepan\n";
    } else {
        prev->next = bantu->next;
        cout << "Hapus barang ditengah";
    } 
    
}

int main() {
    int pilihan;
    do {
        cout << "\n===== TOKO SWALAYAN =====\n";
        cout << "1. Tambah Barang" << endl;
        cout << "2. Lihat Barang" << endl;
        cout << "3. Urut Harga" << endl;
        cout << "4. Cari Barang" << endl;
        cout << "5. Hapus Barang" << endl;
        cout << "6. Update Stok" << endl;
        cout << "Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1: tambahBarang();
            break;
            case 2: tampilBarang();
            break;
            case 3: sortBarang();
            break;
            case 4: cariBarang();
            break;
            case 5: hapusBarang();
            break;
        }
    }
}