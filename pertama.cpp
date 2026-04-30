#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct barang {
    int id_barang;
    char Nama_barang[100];
    int stok;
    int harga;
};  
struct DataBarang{
    barang data;
    DataBarang* next;
};
DataBarang* head = NULL;

void tambahBarang(){
    DataBarang* tambah = new DataBarang;

    cout << "Masukan Id Barang: ";
    cin >> tambah->data.id_barang;
    cout << "Masukkan Nama Barang: ";
    cin >> tambah->data.Nama_barang;
    cout << "Masukkan Harga Barang: ";
    cin >> tambah->data.harga;
    cout << "Masukkan Stok Barang: ";
    cin >> tambah->data.stok;
    tambah->next = head;
    head = tambah;

    FILE *data = fopen("swalayan.txt", "a");
    DataBarang* bantu = head;
    while (bantu) {
        fprintf(DataBarang, "%d;%s;%d;%d\n",
                bantu-> data.id_barang,
                bantu-> data.Nama_barang,
                bantu->data.harga,
                bantu->data.stok
            );
            bantu = bantu->next;
        }
        fclose(file);
    
};