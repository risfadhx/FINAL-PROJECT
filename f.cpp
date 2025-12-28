#include <iostream>
using namespace std;

int main() {
    string nama;
    char pilihan;
    int nomor_meja;
    
    cout << "===Selamat Datang di Warung Mie Nyemek===\n";
    cout << "Pesanan atas nama siapa kak?" << endl;
    getline(cin, nama);

    cout << "Makanannya mau Dine in (d) atau Takeaway (t)? (d/t): ";
    cin >> pilihan;

    // PENGECEKAN KONDISI

    //jika user pilih Dine In (d atau D)
    if (pilihan == 'd' || pilihan == 'D') {
        cout << "Silakan pilih nomor meja (1-50): ";
        cin >> nomor_meja;

        // Validasi nomor meja 1-50
        if (nomor_meja >= 1 && nomor_meja <= 50) {
            cout << "Baik kak " << nama << ", silakan duduk di meja nomor " << nomor_meja << "." << endl;
        } else {
            cout << "Mohon maaf, nomor meja tersebut tidak tersedia." << endl;
        }
    }
    
    //jika user pilih Takeaway (t atau T)
    else if (pilihan == 't' || pilihan == 'T') {
        cout << "Oke kak " << nama << ", pesanan akan kami bungkus. Mohon tunggu sebentar ya." << endl;
    }
    
    //Jika user salah input (bukan instruksi)
    else {
        cout << "Maaf, pilihan tidak dikenali. Harap masukkan 'd' atau 't'." << endl;
    }

}