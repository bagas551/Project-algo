#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
             << setw(10) << bantu->harga << endl;
             bantu =  bantu->next;
    }

}

// search (sequential search)

Databarang* cariBarang(int id){
    DataBarang* bantu = head;

    while (bantu) {
        if(bantu->data.id_barang == id)
        return bantu;

        bantu = bantu->next
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
