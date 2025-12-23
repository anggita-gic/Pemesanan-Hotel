#ifndef FINALSTD_H_INCLUDED
#define FINALSTD_H_INCLUDED
#include <iostream>

using namespace std;

//Struktur untuk Pemesan (Child - Double Linked List)
struct ListHotel;
struct pemesan {
    int id;
    string namaPemesan;
    string nomorKTP;
    string nomorTelepon;
    string email;
    int umur;
    string alamat;
    ListHotel *hotel;
};

typedef pemesan infotypePemesan;
typedef struct elmPemesan *addressPemesan;

//Node untuk Double Linked List (Pemesan)
struct elmPemesan {
    infotypePemesan info;
    addressPemesan next;
    addressPemesan prev;
};

//List untuk Double Linked List (Pemesan)
struct ListPemesan {
    addressPemesan first;
    addressPemesan last;
};

//Struktur untuk Hotel (Parent - Single Linked List)
struct hotel{
    int id;
    string namaHotel;
    string lokasi;
    int jumlahKamar;
    int hargaPerMalam;
    ListPemesan pemesan;
};

typedef hotel infotypeHotel;
typedef struct elmHotel *addressHotel;

//Node untuk Single Linked List (Hotel)
struct elmHotel{
    infotypeHotel info;
    addressHotel next;
    addressHotel prev;
};

//List untuk Single Linked List (Hotel)
struct ListHotel{
    addressHotel first;
    addressHotel last;
};

void menu(ListHotel &LH, ListPemesan &L);

//Fungsi dan prosedur untuk Hotel
void createList_hotel(ListHotel &LH);
addressHotel createElm_hotel(infotypeHotel x);
void insertLast_hotel(ListHotel &LH, addressHotel P);
void showAllHotel_hotel(ListHotel LH);
void showHotelId_hotel(addressHotel P);
addressHotel searchHotel_hotel(ListHotel LH, int id);

//Fungsi dan prosedur untuk Pemesan
void createList_pemesan(ListPemesan &L);
addressPemesan allocate_pemesan(infotypePemesan x);
void printSinglePemesan(addressPemesan pemesan);
void insertLast_pemesan(ListPemesan &L, addressPemesan P);
void deleteFirst_pemesan(ListPemesan &L, addressPemesan &P);
void deleteLast_pemesan(ListPemesan &L, addressPemesan &P);
addressPemesan searchByID_pemesan (ListPemesan L, int pemesanID);
void PrintList_pemesan (ListPemesan L);

//Fungsi dan prosedur untuk relasi
bool isPemesanExistInAllHotel(ListHotel LH, int pemesanID);
void deleteHotelAndPemesan (ListHotel &LH, addressHotel x);
void deletePemesanFromHotel(addressHotel hotel, int hotelID);
int countPemesanbyHotel(addressHotel hotel);
void showSinglePemesanbyHotel (addressHotel hotel, int hotelID);
void showAllHotelAndPemesan (ListHotel LH);

#endif // FINALSTD_H_INCLUDED
