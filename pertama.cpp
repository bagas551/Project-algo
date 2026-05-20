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
    cout << "Masukkan jumlah data barang : ";
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

    while (!(cin >> tambah->data.id_barang)){
        
        cout << "Input ID harus angka! " << endl;

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Id Barang  : ";
    }
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
	cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
	cout << "|" << setfill(' ')<<  setw(42) << right << "TAMPIL BARANG"<< setw(24) << "|" << endl;
	cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
	cout << setfill(' ');  
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

// Sequential search
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
		system("cls");

        cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
        cout << "|" << setfill(' ')<<  setw(42) << right << "CARI BARANG BERDASARKAN ID"<< setw(24) << "|" << endl;
        cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
        cout << setfill(' ');          
        cout << "Masukkan ID Barang yang mau dicari : ";
        cin >> cari;

        DataBarang* hasil = cariBarang(cari);

        if (hasil != NULL) {
            cout << "\nBarang Berhasil Ditemukan!" << endl;
            tampilHeader();
            cout << "|";
            cout << right << setfill('0') << setw(5) << hasil->data.id_barang
            << left << setfill(' ') << setw(6) << "" << "|" << setw(22) << hasil->data.Nama_barang
            <<"|" << setw(11) << hasil->data.stok
            << " | Rp" << setw(14) << hasil->data.harga << "|" << endl;
            cout << "+" << setfill('-') << setw(11) << "-" << "+" << setw(22) << "-" << "+" <<setw(12) << "-" << "+" << setw(17) << "-" << "+" << endl;
			cout << setfill(' ');
        } else {
            cout << "Maaf barang tidak ditemukan" << endl;
        }
        
        cout << "\n Mau cari barang lain? (y/t): ";
        cin >> id_cari;
    } while (id_cari == 'y' || id_cari == 'Y');  
    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void cariNama() {

    char dicari[100];
    bool ketemu = false;

    if (head == NULL) {
        cout << "Belum ada data barang!\n";
        return;
    }

        cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
        cout << "|" << setfill(' ')<<  setw(42) << right << "CARI BARANG BERDASARKAN NAMA"<< setw(24) << "|" << endl;
        cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
        cout << setfill(' ');          
        cout << "Masukkan nama barang yang mau dicari : ";
        cin.ignore();
    cin.getline(dicari, 100);
 
    DataBarang* bantu = head;
		 cout << "\n";
      tampilHeader();

    while (bantu != NULL) {

        if (strstr(bantu->data.Nama_barang, dicari)) {
			cout << "|" ;
			cout << right << setfill('0') << setw(5) << bantu->data.id_barang 
			<< left << setfill(' ')<< setw(6) << "" << "|"
			<< setw(22) << bantu->data.Nama_barang << "|"
			<< setw(11) << bantu->data.stok << " | Rp" 
			<< setw(14) << bantu->data.harga << "|" << endl;
			
            ketemu = true;
        }

        bantu = bantu->next;
    }

    if (!ketemu) {

        cout << " Barang tidak ditemukan!    \n";
    }

        cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
    cout << "\nTekan enter untuk kembali ke menu utama...";
    cin.get();
}

void cariStok() {

    if (head == NULL) {

        cout << "\nBelum ada data barang di rak!" << endl;
        cout << "\nTekan enter untuk kembali ke menu utama...";
        cin.ignore();
        cin.get();
        return;
    }

    int cari_stok;

   cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
        cout << "|" << setfill(' ')<<  setw(42) << right << "CARI BARANG BERDASARKAN STOK"<< setw(24) << "|" << endl;
        cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
        cout << setfill(' ');          
        cout << "Masukkan stok barang yang mau dicari : "; 
         cin >> cari_stok;

        cout << endl;

    DataBarang* bantu = head;
    bool ketemu = false;
	
    while (bantu != NULL) {
 
        if (bantu->data.stok == cari_stok) {
		tampilHeader();
            cout << "|";
            cout << right << setfill('0') << setw(5) << bantu->data.id_barang
            << left << setfill(' ') << setw(6) << "" << "|" << setw(22) << bantu->data.Nama_barang
            <<"|" << setw(11) << bantu->data.stok
            << " | Rp" << setw(14) << bantu->data.harga << "|" << endl;
            cout << "+" << setfill('-') << setw(11) << "-" << "+" << setw(22) << "-" << "+" <<setw(12) << "-" << "+" << setw(17) << "-" << "+" << endl;
			cout << setfill(' ');

          

            ketemu = true;
        }

        bantu = bantu->next;
    }

    if (!ketemu) {
        cout << "| Barang dengan stok tersebut tidak ditemukan"
			 << setw(40) << " "
			 << "|" << endl;
    }


    cout << "\nTekan enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

void menuCari() {
    int pilihan;
       cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+" <<endl;
		cout << "|" << setfill(' ') << setw(26) << "             CARI BARANG             " << setw(16) << "     |" << endl;
		cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+"<< endl;
		cout << setfill(' ');
		cout << "|" << setfill(' ') << setw(26) << "  1. Berdasarkan ID Barang          " << setw(16) << "      |" << endl;
		cout << "|" << setfill(' ') << setw(26) << "  2. Berdasarkan Nama Barang         " << setw(16) << "     |" << endl;
		cout << "|" << setfill(' ') << setw(26) << "  3. Berdasarkan Stok Barang         " << setw(16) << "     |" << endl;
		cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+"<< endl;
		cout << setfill(' ');
        cout << "Pilih: ";
        cin >> pilihan;
        switch(pilihan) {
            case 1: cariId();
            break;
            case 2: cariNama();
            break;
            case 3: cariStok();
            break;
            default:
            cout << "Pilihan tidak valid. Coba lagi!" << endl;
        }
}

// Bubble sort
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
        cout << "\nASCENDING (Murah ke Mahal)" << endl;
    } else {
        cout << "\nUrut secara Descending" << endl;
}
}
void updateStok(){
    int id_baru;
    int stok_baru;
    cout << "Masukkan ID Barang: ";
    cin >> id_baru;

    DataBarang* ada = cariBarang(id_baru);
    if(ada) {
        cout << "Masukkan stok baru : ";
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
    cout << "\nTekan enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();

}

void menuSort() {
    int pilihanSort;

    cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+" <<endl;
	cout << "|" << setfill(' ') << setw(26) << "       URUT BERDASARKAN HARGA         " << setw(27) << "    |" << endl;
    cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+" <<endl;
	cout << setfill(' ');
	cout << "|" << left << setfill(' ')<< setw(42) << " 1. Ascending  (Murah ke Mahal)"<< "|" << endl;    
	cout << "|" << left << setfill(' ')<< setw(42) << " 2. Descending  (Mahal ke Murah)"<< "|" << endl;    
    cout << "+" << setfill('-') << setw(7) << "" << setw(35) << "" << "+" <<endl;
    cout << setfill(' ');
    cout << "Pilih urutan (1/2): ";
    cin >> pilihanSort;

    switch (pilihanSort) {

case 1:
    sortBarang(true);
    cout << "\n";
    cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
	cout << "|" << setfill(' ')<<  setw(42) << right << "DATA BARANG ASCENDING"<< setw(24) << "|" << endl;
	cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
	cout << setfill(' ');  
    tampilBarang();
    break;
case 2:
    sortBarang(false);
    cout << "\n";
    cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
	cout << "|" << setfill(' ')<<  setw(42) << right << "DATA BARANG DESCENDING"<< setw(24) << "|" << endl;
	cout << "+" << setfill('-') << setw(65) << "-" << "+" << endl;
	cout << setfill(' ');  

    tampilBarang();
    break;
default:
    cout << "Pilihan tidak valid!" << endl;
}
    }
void hapusBarang(){
   int id_hapus;
   cout << "Masukkan ID yang ingin dihapus : ";
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

    if (bantu == NULL){

    cout << "\nMaaf, data tidak ditemukan. Input ulang! ";

    cout << "\nTekan enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();

    return;
}

    if (prev == NULL){
        head = bantu->next;
        cout << "Barang berhasil dihapus dengan hapus barang di depan\n";
    } else {
        prev->next = bantu->next;

        if (bantu->next == NULL) {
        cout << "Barang berhasil dihapus dengan hapus barang dibelakang\n";
        }else {
        cout << "Barang berhasil dihapus dengan hapus barang di tengah\n";
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
        while (!(cin >> pilihan)){
            cout << "\nInput harus angka!" << endl;

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nPilih Menu: ";
        }
        
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
