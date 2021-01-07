#include<iostream>
#include<string.h>
using namespace std;
//Deklarasi variabel yang akan digunakan
string plainteks, cipherteks;
int i, shift;
char var;

void enkripsi()
{
    cipherteks = " "; // inisialisasi cipherteks dengan nilai null string
    cout<<"Masukan pesan : ";
    cin.ignore(); getline (cin, plainteks);

    cout<<"Masukan pergeseran 0-25 : "; cin >> shift;

    for (i=0; i < plainteks.length(); i++)
    {
        var = plainteks[i];
        if (isalpha(var)) // hanya memproses huruf alfabet saja
        {
            var = toupper(var) - 65; // ubah huruf menjadi huruf kapital, selanjutnya rubah ke angka
            var = (var + shift) % 26 + 65; // enkripsi, geser sejauh shift ke kanan
        }
        cipherteks = cipherteks + var; // sambungkan huruf ke cipherteks
    }
    cout << "cipherteks : "<<cipherteks<<endl; // cetak hasil enkripsi (ciphertext)
}

void dekripsi()
{
    plainteks = "";  // inisialisasi plainteks dengan null string
    cout<<"Masukan cipherteks : ";
    cin.ignore(); getline (cin, cipherteks);
    cout<<"Masukan pergeseran 0-25 : "; cin>>shift;

    for (i=0; i<cipherteks.length(); i++)
    {
        var = cipherteks[i];
        if (isalpha(var)) // hanya memproses huruf alfabet saja
        {
            var = toupper(var) - 65; // ubah huruf menjadi huruf kapital, selanjutnya rubah ke angka
            if (var - shift < 0) // kasus pembagian apabila bilangan negatif
                var = 26 + (var - shift);
            else
                var = (var - shift) % 26;
            var = var + 65; // Rubah angka kehuruf
            var = tolower(var); // Merubah plaintext kehuruf kecil
        }
        plainteks = plainteks + var; // sambungkan huruf ke plainteks
    }
    cout<<"plainteks : "<<plainteks<<endl; // cetak hasil deskripsi (plainteks)
}

int main ()
{
    int pilihan; //Deklarasi variabel
    bool ulang = true; //Inisialisasi nilai perulangan dengan true

    while(ulang)
    {
        cout<<"Enkripsi dan Deskripsi Caesar Cipher\nPilih Menu : "<<endl;
        cout<<"1. Enkripsi "<<endl;
        cout<<"2. Dekripsi "<<endl;
        cout<<"0. Exit "<<endl;
        cout<<"Pilihan : ";

        cin>>pilihan;
        switch(pilihan)
        {
            case 1 : enkripsi();break;
            case 2 : dekripsi();break;
            case 0 : ulang = false;break;
        }
    }
}
