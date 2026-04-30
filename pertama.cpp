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

    FILE *data = fopen("swalayan.txt", "a");
    if (data == NULL) {
        cout << "Gagal membuka file " << endl;
        return;
    }
    DataBarang* bantu = head;
    while (bantu) {
        fprintf(data, "%d;%s;%d;%d\n",
                tambah-> data.id_barang,
                tambah-> data.Nama_barang,
                tambah->data.harga,
                tambah->data.stok );
            
    
        }
        fclose(data);
    cout << "Data Berhasil Ditambahkan" << endl;
}

int main() {
    char pilihan;

    cout << "=== Program Pendataan Swalayan ===" << endl;
    
    do {
        tambahBarang();

<<<<<<< HEAD
        
    }
=======
        cout << "\napakah ingin tambah barang lagi? (y/t) ";
        cin >> pilihan;
    } while (pilihan ++ 'y' || pilihan == 'Y');

    cout << "Terima kasih! Program Selesai." << endl;

    return 0;
>>>>>>> 88fa767fa1927c524a2b26669b13f31335f66531
}
