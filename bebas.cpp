#include <iostream>
using namespace std;

// Array untuk menyimpan nama dan harga menu
string namaMenu[14] = {
    "Mie Pedas Nikmat", "Mie Pedas Sedang", "Mie Pedas Dower",
    "Mie Ayam", "Mie Ayam Bakso", "Tidak Pesan Makanan",
    "Es Teh Lemon", "Es Jeruk Peras", "Susu Murni", "Tidak Pesan Minuman",
    "Udang Keju", "Siomay", "Lumpia Gulung", "Tidak Pesan Snack"
};

int hargaMenu[14] = {
    10000, 15000, 20000,
    10000, 25000, 0,
    8000, 7000, 10000, 0,
    15000, 5000, 5000, 0
};

// Array untuk menyimpan pesanan user
int pesananID[100];
int jumlahItem = 0;

void tampilkanMenu(string kategori, int awal, int akhir) {
    cout << "\n===" << kategori << "===\n";
    for (int i = awal; i <= akhir; i++) {
        cout << (i + 1) << ". " << namaMenu[i] << " - Rp" << hargaMenu[i] << endl;
    }
}

void prosesPemesanan(int awalMenu, int akhirMenu) {
    char tambahLagi;
    do {
        int pilihan;
        cout << "Pilih nomor menu: ";
        cin >> pilihan;
        
        if (pilihan >= (awalMenu + 1) && pilihan <= (akhirMenu + 1)) {
            if (pilihan == (akhirMenu + 1)) {
                cout << "Oke, tidak jadi pesan di kategori ini.\n";
                break;
            }
            pesananID[jumlahItem] = pilihan - 1;
            jumlahItem++;
            cout << "Pesanan ditambahkan!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
        
        cout << "Apakah Anda ingin menambah lagi? (y/n): ";
        cin >> tambahLagi;
    } while (tambahLagi == 'y' || tambahLagi == 'Y');
}

int hitungTotal() {
    int total = 0;
    for (int i = 0; i < jumlahItem; i++) {
        total += hargaMenu[pesananID[i]];
    }
    return total;
}

void tampilkanStruk(string nama, string catatan, int nomor_meja, char pilihan) {
    cout << "\n===Struk Pembelian===\n";
    cout << "Nama: " << nama << endl;
    
    if (pilihan == 'd' || pilihan == 'D') {
        cout << "Meja: " << nomor_meja << endl;
    } else {
        cout << "Tipe: Takeaway" << endl;
    }
    
    cout << "\nNama Pesanan | Harga\n";
    cout << "------------------------\n";
    for (int i = 0; i < jumlahItem; i++) {
        cout << namaMenu[pesananID[i]] << " | Rp" << hargaMenu[pesananID[i]] << endl;
    }
    cout << "------------------------\n";
    cout << "Total: Rp" << hitungTotal() << endl;
    
    if (!catatan.empty()) {
        cout << "\nCatatan: " << catatan << endl;
    }
    cout << "===================\n";
}

int main() {
    string nama;
    char pilihan;
    int nomor_meja = 0;
    
    cout << "===Selamat Datang di Warung Yomie===\n";
    cout << "Pesanan atas nama siapa kak?" << endl;
    getline(cin, nama);

    cout << "Makanannya mau Dine in (d) atau Takeaway (t)? (d/t): ";
    cin >> pilihan;
    
    //Cek dulu apakah pilihan valid atau tidak
    if (pilihan != 'd' && pilihan != 'D' && pilihan != 't' && pilihan != 'T') {
        cout << "Maaf, pilihan tidak dikenali. Harap masukkan 'd' atau 't'." << endl;
        return 0;
    }
    
    // Jika user pilih Dine In
    if (pilihan == 'd' || pilihan == 'D') {
        cout << "Silakan pilih nomor meja (1-50): ";
        cin >> nomor_meja;

        if (nomor_meja >= 1 && nomor_meja <= 50) {
            cout << "Baik kak " << nama << ", silakan duduk di meja nomor " << nomor_meja << "." << endl;
        } else {
            cout << "Mohon maaf, nomor meja tersebut tidak tersedia." << endl;
            return 0;
        }
    }
    
    // ===BAGIAN PEMESANAN MENU===
    tampilkanMenu("Mie Pedas 3 Level & Mie Tidak Pedas", 0, 5);
    prosesPemesanan(0, 5);
    
    tampilkanMenu("Minuman", 6, 9);
    prosesPemesanan(6, 9);
    
    tampilkanMenu("Snack", 10, 13);
    prosesPemesanan(10, 13);
    
    // Catatan khusus
    char adaCatatan;
    string catatan = "";
    cout << "\nApakah Anda memerlukan sesuatu? Silakan catat di bawah ini (y/n): ";
    cin >> adaCatatan;
    cin.ignore();
    
    if (adaCatatan == 'y' || adaCatatan == 'Y') {
        cout << "Masukkan catatan: ";
        getline(cin, catatan);
    }
    
    // Tampilkan struk
    tampilkanStruk(nama, catatan, nomor_meja, pilihan);
    
    // Konfirmasi pesanan
    char konfirmasi;
    cout << "\nApakah Anda ingin memesan pesanan ini? (y/n): ";
    cin >> konfirmasi;
    
    if (konfirmasi == 'y' || konfirmasi == 'Y') {
        cout << "\nTerima kasih! Pesanan akan kami proses, mohon ditunggu.\n";
    } else {
        cout << "\nPesanan dibatalkan. Terima kasih sudah berkunjung!\n";
    }
    
}
