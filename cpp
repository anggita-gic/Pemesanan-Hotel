#include <iostream>
#include "finalstd.h"

using namespace std;

//SLL
void createList_hotel(ListHotel &LH){
    LH.first = nullptr;
};

addressHotel createElm_hotel(infotypeHotel x){
    addressHotel P = new elmHotel;
    P->info = x;
    createList_pemesan(P->info.pemesan);
    P->next = nullptr;

    return P;
};

void insertLast_hotel(ListHotel &LH, addressHotel P){
    if (LH.first == nullptr){
        LH.first = P;
    } else {
        addressHotel q = LH.first;
        while (q->next != nullptr){
            q = q->next;
        }
        q->next = P;
    }
};

void showAllHotel_hotel(ListHotel LH){
    addressHotel P = LH.first;
    cout << endl;
    cout << "========= D A T A  H O T E L ========"<< endl;
    if (P == nullptr){
        cout << "Maaf data hotel kosong" << endl;
    } else {
        while (P != nullptr){
            cout << "| ID Hotel: " << P->info.id << endl;
            cout << "| Nama Hotel: " << P->info.namaHotel << endl;
            cout << "| Lokasi: " << P->info.lokasi << endl;
            cout << "| Jumlah Kamar: " << P->info.jumlahKamar << endl;
            cout << "| Harga Per Malam: " << P->info.hargaPerMalam << endl;
            cout << "---------------------------------\n";
            cout << endl;
            P = P->next;
        }
         cout << "====================================\n";

    }
};

void showHotelId_hotel(addressHotel P){
    if (P != nullptr){
        cout << "=======================" << endl;
        cout << "|      H O T E L      |" << endl;
        cout << "=======================" << endl;
        cout << "| ID Hotel  : " << P->info.id << endl;
        cout << "| Nama Hotel: " << P->info.namaHotel << endl;
        cout << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }
}

addressHotel searchHotel_hotel(ListHotel LH, int id){
    addressHotel P = LH.first;
    while (P != nullptr){
        if (P->info.id == id){
            return P;
        }
        P = P->next;
    }
    return nullptr;
};

void deleteHotelAndPemesan (ListHotel &LH, addressHotel x){
    if(x->next == nullptr){
        addressHotel prec = LH.first;
        while (prec->next != x){
            prec = prec->next;
        }
        prec->next = nullptr;
    } else if (x == LH.first){
        LH.first = x->next;
        x->next = nullptr;
    } else {
        addressHotel prec = LH.first;
        while (prec->next != x){
            prec = prec->next;
        }
        prec->next = x->next;
        x->next = nullptr;
    }
};

void menu(ListHotel &LH, ListPemesan &L){
    int pilihan = 1;
    while (pilihan != 10) {
        cout << " " << endl;
        cout << "===========================================" << endl;
        cout << "|                 M E N U                 |" << endl;
        cout << "===========================================" << endl;
        cout << "|1. Tambah Hotel                          |" << endl;
        cout << "|2. Tampilkan Semua Hotel                 |" << endl;
        cout << "|3. Hapus Hotel beserta Pemesan           |" << endl;
        cout << "|4. Cari Hotel                            |" << endl;
        cout << "|5. Tambah Pemesan pada Hotel             |" << endl;
        cout << "|6. Tampilkan Semua Hotel beserta Pemesan |" << endl;
        cout << "|7. Cari Pemesan pada Hotel               |" << endl;
        cout << "|8. Hapus Pemesan pada Hotel              |" << endl;
        cout << "|9. Hitung Jumlah Pemesan pada Hotel      |" << endl;
        cout << "|10. Keluar                               |" << endl;
        cout << "===========================================" << endl;
        cout << "Pilih Menu [1/2/3/4/5/6/7/8/9/10]; ";
        cin >> pilihan;
        if (pilihan == 1) {
            int i, n;
            infotypeHotel x;
            cout << "====================================\n";
            cout << "|       DATA HOTEL TERSIMPAN       |\n";
            cout << "====================================\n";
            cout << "| ID Hotel         : ";
            cin >> x.id;

            cout << "| Nama Hotel       : ";
            cin >> x.namaHotel;

            cout << "| Lokasi           : ";
            cin >> x.lokasi;

            cout << "| Jumlah Kamar     : ";
            cin >> x.jumlahKamar;

            cout << "| Harga Per Malam  : ";
            cin >> x.hargaPerMalam;
            cout << "====================================\n";

            addressHotel P = createElm_hotel(x);
            insertLast_hotel(LH, P);

            cout << "|    Hotel berhasil ditambahkan!   |\n";
            cout << "====================================\n";

        } else if (pilihan == 2){
            showAllHotel_hotel(LH);
        } else if (pilihan == 3){
            int idHapus;

            cout << "Masukkan ID Hotel yang akan dihapus: ";
            cin >> idHapus;

            addressHotel H = searchHotel_hotel(LH, idHapus);

            if (H != nullptr) {
                deleteHotelAndPemesan(LH, H);
                cout << "Hotel beserta pemesannya berhasil dihapus.\n";
            } else {
                cout << "Hotel dengan ID tersebut tidak ditemukan.\n";
            }
        } else if (pilihan == 4){
            int idCari;
            cout << "Masukkan ID Hotel yang dicari: ";
            cin >> idCari;

            addressHotel H = searchHotel_hotel(LH, idCari);

            if (H != nullptr) {
            cout << "Hotel ditemukan!\n";
            showHotelId_hotel(H);
            } else {
            cout << "Hotel dengan ID tersebut tidak ditemukan.\n";
            }
        } else if (pilihan == 5){
            int idHotel;
            infotypePemesan x;

            cout << "Masukkan ID Hotel tujuan: ";
            cin >> idHotel;

            addressHotel H = searchHotel_hotel(LH, idHotel);
            if (H == nullptr) {
                cout << "Hotel tidak ditemukan.\n\n";
            } else {
                cout << "ID Pemesan    : ";
                cin >> x.id;

                cout << "Nama Pemesan  : ";
                cin >> x.namaPemesan;

                cout << "Nomor KTP     : ";
                cin >> x.nomorKTP;

                cout << "Nomor Telepon : ";
                cin >> x.nomorTelepon;

                cout << "Email         : ";
                cin >> x.email;

                cout << "Umur          : ";
                cin >> x.umur;

                cout << "Alamat        : ";
                cin >> x.alamat;

                addressPemesan P = allocate_pemesan(x);
                insertLast_pemesan(H -> info.pemesan, P);

                cout << "Pemesan berhasil ditambahkan.\n\n";
            }
        } else if (pilihan == 6){
            if (LH.first == nullptr) {
                    cout << "Data hotel masih kosong.\n\n";
            } else {
                addressHotel H = LH.first;
                while (H != nullptr) {
                    cout << "=============================\n";
                    cout << "ID Hotel      : " << H->info.id << endl;
                    cout << "Nama Hotel    : " << H->info.namaHotel << endl;
                    cout << "Lokasi        : " << H->info.lokasi << endl;
                    cout << "Jumlah Kamar  : " << H->info.jumlahKamar << endl;
                    cout << "Harga/Malam   : " << H->info.hargaPerMalam << endl;
                    cout << "--- Daftar Pemesan ---\n";
                    if (H->info.pemesan.first == nullptr) {
                        cout << "Belum ada pemesan.\n";
                    } else {
                        addressPemesan P = H->info.pemesan.first;
                        while (P != nullptr) {
                            cout << "ID Pemesan : " << P->info.id << endl;
                            cout << "Nama       : " << P->info.namaPemesan << endl;
                            cout << "Telepon    : " << P->info.nomorTelepon << endl;
                            cout << "---------------------\n";
                            P = P->next;
                        }
                    }
                    H = H-> next;
                    cout << endl;
                }
            }
        } else if (pilihan == 7){
            int idHotel, idPemesan;
            cout << "Masukkan ID Hotel: ";
            cin >> idHotel;

            addressHotel H = searchHotel_hotel(LH, idHotel);
            if (H == nullptr){
                cout << "Hotel tidak ditemukan. \n\n";
            } else if (H->info.pemesan.first == nullptr){
                cout << "Hotel ini belum memiliki pemesan. \n\n";
            } else {
                cout << "Masukkan ID Pemesan: ";
                cin >> idPemesan;
                addressPemesan P = searchByID_pemesan(H->info.pemesan, idPemesan);

                if (P == nullptr){
                    cout << "Pemesan tidak ditemukan di hotel ini.\n\n";
                } else {
                    cout << "======= DATA PEMESAN =======\n";
                    cout << "ID Pemesan   : " << P->info.id << endl;
                    cout << "Nama         : " << P->info.namaPemesan << endl;
                    cout << "No. KTP      : " << P->info.nomorKTP << endl;
                    cout << "Telepon      : " << P->info.nomorTelepon << endl;
                    cout << "Email        : " << P->info.email << endl;
                    cout << "Umur         : " << P->info.umur << endl;
                    cout << "Alamat       : " << P->info.alamat << endl;
                    cout << "============================\n";
                    cout << endl;
                }
            }
        } else if (pilihan == 8){
            int idHotel, idPemesan;

            cout << "Masukkan ID Hotel    : ";
            cin >> idHotel;

            addressHotel H = searchHotel_hotel(LH, idHotel);

            if (H == nullptr) {
                cout << "Hotel tidak ditemukan.\n\n";
            } else if (H->info.pemesan.first == nullptr) {
                cout << "Hotel ini belum memiliki pemesan.\n\n";
            } else {
                cout << "Masukkan ID Pemesan  : ";
                cin >> idPemesan;

                addressPemesan P = searchByID_pemesan(H->info.pemesan, idPemesan);

                if (P == nullptr) {
                    cout << "Pemesan tidak ditemukan di hotel ini.\n\n";
                } else {
                    if (P == H->info.pemesan.first){
                        deleteFirst_pemesan(H->info.pemesan, P);
                    } else if (P == H->info.pemesan.last){
                        deleteLast_pemesan(H->info.pemesan, P);
                    } else {
                        P->prev->next = P->next;
                        P->next->prev = P->prev;

                        P->prev = nullptr;
                        P->next = H->info.pemesan.first;
                        H->info.pemesan.first->prev = P;
                        H->info.pemesan.first = P;
                        deleteFirst_pemesan(H->info.pemesan, P);
                    }
                    cout << "Pemesan berhasil dihapus." << endl;
                }
            }
        } else if (pilihan == 9){
            int idHotel;
            int count = 0;

            cout << "Masukkan ID Hotel: ";
            cin >> idHotel;
            addressHotel H = searchHotel_hotel(LH, idHotel);

            if (H == nullptr){
                cout << "Hotel tidak ditemukan.\n\n";
            } else {
                addressPemesan P = H->info.pemesan.first;
                while (P != nullptr){
                    count++;
                    P = P->next;
                }
                cout << "Jumlah pemesan pada hotel ini: " << count << endl;
            }
        } else if (pilihan == 10){
            cout << "Terima kasih telah memesan hotel di aplikasi ini! \n";
        }
    }
};

//DLL
void createList_pemesan(ListPemesan &L){
    L.first = nullptr;
    L.last = nullptr;
};

addressPemesan allocate_pemesan(infotypePemesan x){
    addressPemesan P = new elmPemesan;
    if (P != nullptr){
        P->info = x;
        P->next = nullptr;
        P->prev = nullptr;
    }
    return P;
};

void printSinglePemesan(addressPemesan pemesan){
    if (pemesan != nullptr){
        cout << "ID Pemesan       : " << pemesan->info.id << endl;
        cout << "Nama Pemesan     : " << pemesan->info.namaPemesan << endl;
        cout << "No. KTP          : " << pemesan->info.nomorKTP << endl;
        cout << "Nomor Telepon    : " << pemesan->info.nomorTelepon << endl;
        cout << "Email            : " << pemesan->info.email << endl;
        cout << "Umur             : " << pemesan->info.umur << endl;
        cout << "Alamat           : " << pemesan->info.email << endl;
        cout << endl;
    }
};

void insertLast_pemesan(ListPemesan &L, addressPemesan P){
    if (L.first == nullptr){
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
};

void deleteFirst_pemesan(ListPemesan &L, addressPemesan &P){
    if (L.first != nullptr){
        P = L.first;
        if(P->next == nullptr){
            L.first = nullptr;
            L.last = nullptr;
        } else {
            L.first = P->next;
            L.first->prev = nullptr;
        }
        P->next = nullptr;
    }
};

void deleteLast_pemesan(ListPemesan &L, addressPemesan &P){
    if (L.first != nullptr){
        if (L.first->next == nullptr){
            P = L.first;
            L.first = nullptr;
        } else {
            addressPemesan q;
            q = L.first;
            while (q->next->next != nullptr){
                q = q->next;
            }
            P = q->next;
            q->next = nullptr;
        }
    }
};

addressPemesan searchByID_pemesan (ListPemesan L, int pemesanID){
    addressPemesan P = L.first;

    while (P != nullptr){
        if (P->info.id == pemesanID){
            return P;
        }
        P = P->next;
    }
    return nullptr;
};
