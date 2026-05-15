#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <cstring>
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

//TAMPILAN 
void menuHeader(){
	cout << right;
    cout << "+" << setfill('-') << setw(7) << "+" << setw(36) << "+" << endl;
	cout << "|" << setfill(' ') << setw(25) << "GrocerEase" << setw(18) << "|" << endl;
	cout << "+" << setfill('-') << setw(7) << "+" << setw(36) << "+" << endl;
	cout << setfill(' ');
	cout << "| " << left << setw(4) << " No" << " | " << setw(32) << "        Menu     " << "  |" << endl;
	cout << "+" << setfill('-') << setw(6) << ""<< "+" << setw(35) << "" << "+" << endl;	
	cout << setfill(' ');
	cout << "| " << left << setw(4) << " 1" << " | " << setw(32) << "   Tambah Barang" << "  |" << endl;
	cout << "| " << left << setw(4) << " 2" << " | " << setw(32) << "   Lihat Barang" << "  |" << endl;
	cout << "| " << left << setw(4) << " 3" << " | " << setw(32) << "   Urut Barang" << "  |" << endl;
	cout << "| " << left << setw(4) << " 4" << " | " << setw(32) << "   Cari Barang" << "  |" << endl;
	cout << "| " << left << setw(4) << " 5" << " | " << setw(32) << "   Hapus Barang" << "  |" << endl;
	cout << "| " << left << setw(4) << " 6" << " | " << setw(32) << "   Update Stok Barang" << "  |" << endl;
	cout << "| " << left << setw(4) << " 7" << " | " << setw(32) << "   Keluar" << "  |" << endl;
   cout << "+" << setfill('-') << setw(6) << ""<< "+" << setw(35) << ""<< "+" << endl;	
   cout << setfill(' ');
}
void tampilHeader(){
    cout << "+" << setfill('-') << setw(11) << "-" << "+" << setw(22) << "-" << "+" <<setw(12) << "-" << "+" << setw(17) << "-" << "+" << endl;
    cout << setfill(' ');

     cout << "|"
         << setw(1)  << " " << "ID Barang"    << setw(1) << " " << "|"
         << setw(6)  << " " << "Nama Barang"  <<  setw(5) <<  " "  << "|"
         << setw(4)  << " " << "Stok"         << setw(4) << " " << "|"
         << setw(7)  << " " << "Harga"        << setw(5) << " " << "|"
         << endl;

    cout << "+" << setfill('-') << setw(11) << "-" << "+" << setw(22) << "-" << "+" <<setw(12) << "-" << "+" << setw(17) << "-" << "+" << endl;
    cout << setfill(' ');
}
// Baca data
void bacaData() {
    FILE *data = fopen("swalayan.txt", "r");
    if (data == NULL){
        return;
    }

    while (head != NULL){
        DataBarang* hapus = head;
        head = head->next;
        delete hapus;
    }

    while (!feof(data)) {
        DataBarang* baru = new DataBarang;

        if (fscanf(data, "%d;%[^;];%d;%d\n",
        &baru->data.id_barang,
        baru->data.Nama_barang, &baru->data.stok, &baru->data.harga) != 4) {
            delete baru;
            break;
        }

        baru->next = head;
        head = baru;
    }

    fclose(data);
}

void simpanData(){
    FILE *data = fopen("swalayan.txt", "w");
        if(data == NULL) {
            cout << "Gagal menyimpan file. Coba lagi" << endl;
            return;
                }
    DataBarang* bantu = head;
    while(bantu) {
        fprintf(data, "%d;%s;%d;%d\n",
            bantu-> data.id_barang,
            bantu->data.Nama_barang,
            bantu->data.stok,
            bantu->data.harga
        );
        bantu = bantu->next;
    }
    fclose(data);
    }

// 1. MENU TAMBAH BARANG
void tambahBarang(){
    cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+" <<endl;
	cout << "|" << setfill(' ') << setw(26) << "             TAMBAH BARANG           " << setw(16) << "     |" << endl;
	cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+"<< endl;
	cout << setfill(' ');
    int jumlah;
    cout << "Jumlah tambah data barang : ";
    cin >> jumlah;
    if (jumlah <= 0) {
        cout << "Data barang harus lebih dari 0" << endl;
        cout << "\nTekan enter untuk kembali ke menu...";
        cin.ignore(1000,'\n');
        cin.get();
        return;
    }

    for(int i =0; i < jumlah; i++){
    DataBarang* tambah = new DataBarang;
    
    cout << "\nData Barang ke-" << i+1 << endl;
	cout << endl;
    cout << "Id Barang       : ";
    cin >> tambah->data.id_barang;
    cin.ignore(1000, '\n');

    cout << "Nama Barang     : ";
    cin.getline(tambah->data.Nama_barang, 100);

    cout << "Harga Barang    : ";
    cin >> tambah->data.harga;
    if(tambah->data.harga < 0) {
        cout << "Harga Barang tidak boleh bernilai negatif" << endl;
        delete tambah;
        i--;
        continue;
    }

    cout << "Stok Barang     : ";
    cin >> tambah->data.stok;
    if(tambah->data.stok < 0) {
        cout << "Stok Barang tidak boleh bernilai negatif" << endl;
        delete tambah;
        i--;
        continue;;
    }
    cout << endl;
    tambah->next = head;
    head = tambah;
    }
    simpanData();
    cout << "Data Berhasil Ditambahkan" << endl;
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore(1000,'\n');
    cin.get();
    cout << left;
cout << setfill(' ');
}
void tampilBarang() {
    cout << "+-----------------------------------------------------------------+" << endl;
    cout << "|                         TAMPIL BARANG                           |" << endl;
    cout << "+-----------------------------------------------------------------+" << endl;
    DataBarang* bantu = head;
    if(head == NULL) {
        cout << "Belum ada Barang di Toko" << endl;
        cout << "\nTekan enter untuk kembali ke menu...";
        cin.ignore(1000,'\n');
        cin.get();
        return;
    }
    int jumlah = 0;
    cout << setfill(' ');
    tampilHeader();
   
    cout << setfill(' ');

    while(bantu) {
        cout << "|";
        cout << right << setfill('0') << setw(5) << bantu->data.id_barang << left << setfill(' ') 
        << setw(6) << "" << "|"  << setw(22) << bantu->data.Nama_barang
           << "|"  << setw(10) << bantu->data.stok
             << "  | Rp "  << setw(13) << bantu->data.harga << "|"<< endl;
             jumlah++;
             bantu =  bantu->next;
    }
    cout << "+" << setfill('-') << setw(11) << "-" << "+" << setw(22) << "-" << "+" <<setw(12) << "-" << "+" << setw(17) << "-" << "+" << endl;

    cout << "Jumlah Barang     : " << jumlah << endl;     
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore(1000,'\n');
    cin.get();
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
void cariId() {
    int cari;
    char id_cari;

    if (head == NULL) {
        cout << "Belum ada data barang" << endl;
        cout << "\nTekan enter untuk kembali ke menu...";
        cin.ignore(1000,'\n');
        cin.get();
        return;
    }

    do {
        cout << "\n--- FITUR CARI BARANG ---" << endl;
        cout << "Masukkan ID Barang yang mau dicari: ";
        cin >> cari;

        DataBarang* hasil = cariBarang(cari);

        if (hasil != NULL) {
            cout << " Barang Berhasil Ditemukan!" << endl;
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
        cin >> id_cari;
    } while (id_cari == 'y' || id_cari == 'Y');  
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void cariNama(){
    char dicari[100];
    bool ketemu = false;

    if (head == NULL) {
        cout << "Belum ada data barang\n";
         cout << "\nTekan enter untuk kembali ke menu...";
         cin.ignore();
         cin.get(); 
        return;
    }

    cout << "Masukkan nama yang dicari: ";
    cin.ignore(1000, '\n');
    cin.getline(dicari, 100);
    DataBarang* bantu = head;

    cout << "\nHasil Pencarian: \n";
       menuHeader();

    while (bantu){
        if (strstr(bantu->data.Nama_barang, dicari)) {
            cout << setw(10) << bantu->data.id_barang
                 << setw(20) << bantu->data.Nama_barang
                 << setw(10) << bantu->data.stok
                 << setw(10) << bantu->data.harga << endl;
            ketemu = true;
        }
        bantu = bantu->next;
    }

    if (!ketemu) {
        cout << "Barang tidak ditemukan";
        
    }

    cout << "\nTekan enter untuk kembali ke menu";
    cin.ignore();
    cin.get(); 

}
void cariStok() {

    if (head == NULL) {

        cout << "\nBelum ada data barang di rak!" << endl;
        cout << "\nTekan enter untuk kembali...";
        cin.ignore();
        cin.get();
        return;
    }

    int cari_stok;

    cout << "\n====================================";
    cout << "\n     CARI BERDASARKAN STOK";
    cout << "\n====================================";

    cout << "\nMasukkan jumlah stok : ";
    cin >> cari_stok;

    DataBarang* bantu = head;
    bool ketemu = false;

    cout << "\n";
    cout << "+=======================================================+\n";
    cout << "| ID      | Nama Barang      | Stok    | Harga         |\n";
    cout << "+=======================================================+\n";

    while (bantu != NULL) {

        if (bantu->data.stok == cari_stok) {

            cout << "| "
                 << left << setw(8) << bantu->data.id_barang
                 << "| "
                 << setw(18) << bantu->data.Nama_barang
                 << "| "
                 << setw(8) << bantu->data.stok
                 << "| Rp "
                 << setw(10) << bantu->data.harga
                 << "|\n";

            ketemu = true;
        }

        bantu = bantu->next;
    }

    if (!ketemu) {

        cout << "| Barang dengan stok tersebut tidak ditemukan!          |\n";
    }

    cout << "+=======================================================+\n";

    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void menuCari() {
    int pilihan;
        cout << "\n--- FITUR CARI BARANG ---" << endl;
        cout << "1. Berdasarkan ID Barang" << endl;
        cout << "2. Berdasarkan Nama Barang" << endl;
        cout << "3. Berdasarkan Stok Barang" << endl;
        cout << "Pilih:";
        cin >> pilihan;
        switch(pilihan) {
            case 1: cariId();
            break;
            case 2: cariNama();
            break;
            case 3: cariStok();
            break;
            default:
            cout << "Pilihan tidak valid. Coba lagi" << endl;
        }
}


void sortBarang(bool asc){
   if (head == NULL) {
        cout << "Belum ada data barang" << endl;
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
    cout << "Masukkan ID Barang: ";
    cin >> id_baru;

    DataBarang* ada = cariBarang(id_baru);
    if(ada) {
        cout << "Masukkan stok baru: ";
        cin>> stok_baru;
        
        if(stok_baru < 0) {
            cout << "Stok tidak boleh bernilai negatif" << endl;
            return;
        }

        ada->data.stok = stok_baru;
        simpanData();
    cout << "Stok berhasil diupdate" << endl;
    } else
    cout << "Barang tidak ditemukan" << endl;
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();

}

void menuSort() {
    int pilihanSort;
    cout << "\n === Urut Berdasarkan Harga ===" << endl;
    cout << "1. Ascending" << endl;
    cout << "2. Descending" << endl;
    cout << "Pilih (1/2): ";
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
   int id_hapus;
   cout << "Masukkan ID yang ingin dihapus: ";
   cin >> id_hapus;
   
   if (head == NULL) {
        cout << "Belum ada data barang" << endl;
        return;
    }
    DataBarang *bantu = head;
    DataBarang *prev = NULL;



    while (bantu && bantu->data.id_barang != id_hapus){
        prev = bantu;
        bantu = bantu->next;
    }

    if (!bantu){
        cout << "Data tidak ditemukan!\n";
        return;
    }

    if (prev == NULL){
        head = bantu->next;
        cout << "Hapus barang di depan\n";
    } else {
        prev->next = bantu->next;

        if (bantu->next == NULL) {
        cout << "Hapus barang dibelakang\n";
        }else {
        cout << "Hapus barang di tengah\n";
        }
    }

    delete bantu;
    simpanData();
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

int main() {
    bacaData();

    int pilihan;
    do {
        system("cls");
       menuHeader(); 
        cout << "Pilih Menu: ";
        cin >> pilihan;
		cout << endl;
        
        switch(pilihan) {
            case 1: tambahBarang();
            break;
            case 2: tampilBarang();
            break;
            case 3: menuSort();
            break;
            case 4: menuCari();
            break;
            case 5: hapusBarang();
            break;
            case 6: updateStok();
            break;
        }
    } while (pilihan != 7);
    return 0;
}
