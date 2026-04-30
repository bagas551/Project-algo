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
void updateStok(){
    int id_baru;
    int stokBaru;
    cout << "Masukkan ID: ";
    cin >> id_baru;

    DataBarang* ada = cariBarang(id_baru);
    if(ada) {
        cout << "Stok baru : ";
        cin >> stokBaru;
        ada->data.stok = stokBaru;
        simpanData();
        cout << "Stok berhasil diupdate" << endl;

    } else {
        cout << "Barang tidak ditemukan" << endl;
    }
        
    }
void simpanData(){
    FILE *file =fopen("swalayan.txt","w");
    if(data == NULL) {
        cout << "Gagal Menyimpan File" << endl;
        return;
    }
    DataBarang* bantu = head;
    while (bantu) {
        fprintf(data, "%d;%s;%d;%d\n",
                bantu-> data.id_barang,
                bantu-> data.Nama_barang,
                bantu->data.harga,
                bantu->data.stok );
            bantu = bantu-> next;
        }
        fclose(data);
}




int main() {
    char pilihan;

    cout << "=== Program Pendataan Swalayan ===" << endl;
    
    do {
        tambahBarang();

        
    }
        cout << "\napakah ingin tambah barang lagi? (y/t) ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');

    cout << "Terima kasih! Program Selesai." << endl;

    return 0;
}

// search (sequential search)

DataBarang* cariBarang(int id){
    DataBarang* bantu = head;

    while (bantu) {
        if(bantu->data.id_barang == id)
        return bantu;

        bantu = bantu->next
    }
    return NULL;
}

