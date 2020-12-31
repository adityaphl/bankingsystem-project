#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#define MAX 100

using namespace std;
int x = 6, indt, pil;

struct data
{
    string username[100]    = {"rdtyphlv",   "rlvldomlna",     "frdishndra",      "arfhdtyhlh",    "andkbrmdhan",   "atthribrhm"};
    string nama[100]        = {"Rio Aditya", "Rivaldo Maulana", "Fredi Suhendra", "Arif Hidayat", "Andika Ramadhan", "Atthur Ibrahim"};
    string identity[100]    = {"314131", "314311", "323132", "123212", "133212", "132334" };
    float tabungan[100]     = {70000, 80000, 50000, 90000, 85000, 90000};
} member;

struct antrian
{
    int data[MAX];
    int awal, akhir;
} antri;

void first()
{
    antri.awal = -1;
    antri.akhir = -1;
}

bool isfull()
{
    if (antri.akhir == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isempty()
{
    if (antri.akhir == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int a = 1;
int tambah()
{
    return a++;
}

void tampilkanantrian()
{
    if (!isempty())
    {
        cout << "STATUS SAAT INI : " << endl
             << endl;
        for (int ant = antri.awal; ant < antri.akhir; ant++)
        {
            cout << antri.data[ant] << " | ";
        }
        cout << endl;
    }
    else
    {
        a = 1;
        cout << "STATUS SAAT INI : " << endl
             << endl;
        cout << "UNTUK SAAT INI TIDAK ADA ANTRIAN" << endl;
    }
    cout << endl;
}

void ambilantrian()
{
    int nomer;
    float total;
    if (!isfull())
    {
        cout << endl;
        cout << "Nomer Antrian Telah Diambil, Mohon Menunggu Nomer Antrian Anda di Panggil" << endl
             << endl;
        antri.data[antri.akhir] = tambah();
        total = total + antri.data[antri.akhir];
        antri.akhir++;
        system("pause");
    }
    else
    {
        cout << "Antrian penuh" << endl
             << endl;
    }
}

void format()
{
    antri.awal = -1;
    antri.akhir = -1;
    a = 1;
    cout << "Antrian Berhasil Dikosongkan..." << endl
         << endl;
}

void panggilantrian()
{
    if (!isempty())
    {
        cout << endl;
        cout << "Silakan Nomer Antrian Ke - " << antri.data[antri.awal] << " Untuk Menuju Ke Teller/CS" << endl;
        for (int i = antri.awal; i < antri.akhir; i++)
        {
            antri.data[i] = antri.data[i + 1];
        }
        antri.akhir--;
        cout << endl;
        system("pause");
    }
    else
    {
        cout << endl;
        cout << "Untuk Saat Ini Tidak Ada Antrian" << endl
             << endl;
        system("pause");
    }
}


void header()
{
    system("color 6");
    system("cls");
    cout << "========================================================\n";
    cout << "                   SELAMAT DATANG !!!\n";
    cout << "                 BANK BERKAH BAROKAH \n";
    cout << endl;
    cout << "            Sistem Perbankan Version 3.0   " << endl;
    cout << "========================================================\n";
    cout << endl;
    cout << "[1] No.Antrian" << endl;
    cout << "[2] List Member Bank" << endl;
    cout << "[3] Input Data Member Baru" << endl;
    cout << "[4] Edit Data Member" << endl;
    cout << "[5] Hapus Data Member" << endl;
    cout << "[6] Menabung" << endl;
    cout << "[7] Penarikan" << endl;
    cout << "[8] Pencarian Data" << endl;
    cout << "[9] About Us" << endl;
    cout << "[10] Keluar" << endl;
    cout << endl;
}

int main()
{
home:
    header();
    cout << "INPUT PILIHAN =>> ";
    cin >> pil;
    if (pil == 1)
    {
    ant:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                          Antrian                                     |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Ambil Dan Panggil Antrian" << endl;
        cout << "[1] Ambilkan Antrian" << endl;
        cout << "[2] Panggil Antrian" << endl;
        cout << "[3] Kosongkan Antrian" << endl;
        cout << "[4] Kembali Ke Menu" << endl;
        cout << endl;
        tampilkanantrian();
        int antr;
        cout << "Masukan Pilihan Anda [1/2/3/4] > ";
        cin >> antr;
        if (antr == 1)
        {
            ambilantrian();
            goto ant;
        }
        else if (antr == 2)
        {
            panggilantrian();
            goto ant;
        }
        else if (antr == 3)
        {
            format();
            goto ant;
        }
        else if (antr == 4)
        {
            goto home;
        }
        else
        {
            cout << "Inputan Anda Salah ,INputkan Pilihan [1 / 2 / 3]" << endl;
            system("pause");
            goto ant;
        }
    }
    else if (pil == 2)
    {
    sor: //label
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      List Member Bank                                |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUSERNAME\tNAMA MEMBER\t\t\tNo.Identitas\t\tSaldo" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "."
                 << "\t" << member.username[i] << "\t" << member.nama[i] << "\t\t\t" << member.identity[i] << "\t\t\tRp. " << member.tabungan[i] << endl;
        }
        cout << endl;
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Lakukan Per-Sortingan " << endl;
        cout << "[1] Mode Ascending (A to Z)" << endl;
        cout << "[2] Mode Discending (Z to A)" << endl;
        cout << "[3] Kembali Ke Menu" << endl;
        cout << endl;
        int sort;
        cout << "Masukan Pilihan Anda [1/2/3] > ";
        cin >> sort;
        if (sort == 1)
        {

            string copynama[100], copyusername[100], copyidentity[100], tempnama, tempusername, tempidentity;
            float copytabungan[100], temptabungan;
            int f, g, u, r;
            int h = x;
            for (f = 0; f < x; f++)
            {
                copynama[f] = member.nama[f];
                copyusername[f] = member.username[f];
                copyidentity[f] = member.identity[f];
                copytabungan[f] = member.tabungan[f];
            } //mengcopy array utama ke array khusus sorting
            for (g = 0; g < h; g++)
            {
                u = g;
                for (r = g + 1; r < h; r++)
                {
                    if (copynama[r] < copynama[u])
                    {
                        u = r;
                    }
                }
                tempnama = copynama[g];
                copynama[g] = copynama[u];
                copynama[u] = tempnama;

                tempusername = copyusername[g];
                copyusername[g] = copyusername[u];
                copyusername[u] = tempusername;

                tempidentity = copyidentity[g];
                copyidentity[g] = copyidentity[u];
                copyidentity[u] = tempidentity;

                temptabungan = copytabungan[g];
                copytabungan[g] = copytabungan[u];
                copytabungan[u] = temptabungan;
            }
            cout << endl;
            cout << "|======================================================================================|\n";
            cout << "|                           Data Terurut Dengan Mode Ascending (A-Z)                   |\n";
            cout << "|======================================================================================|\n";
            cout << endl;
            cout << "NO.\tUSERNAME\tNAMA MEMBER\t\t\tNo.Identitas\t\tSaldo" << endl;
            for (int ur = 0; ur < x; ur++)
            {
                cout << ur + 1 << "."
                     << "\t" << copyusername[ur] << "\t" << copynama[ur] << "\t\t\t" << copyidentity[ur] << "\t\t\tRp. " << copytabungan[ur] << endl;
            }
            cout << endl;
            cout << "|======================================================================================|\n";
            system("pause");
            goto sor;
        }
        else if (sort == 2)
        {
            //deklarasi tampungan array untuk sorting, mengapa ada array lagi? agar array utama tidak berubah.
            string copynama[100], copyusername[100], copyidentity[100], tempnama, tempusername, tempidentity;
            float copytabungan[100], temptabungan;
            int f, g, u, r;
            int h = x;
            for (f = 0; f < x; f++)
            {
                copynama[f] = member.nama[f];
                copyusername[f] = member.username[f];
                copyidentity[f] = member.identity[f];
                copytabungan[f] = member.tabungan[f];
            } //mengcopy array utama ke array khusus sorting
            for (g = 0; g < h; g++)
            {
                u = g;
                for (r = g + 1; r < h; r++)
                {
                    if (copynama[r] > copynama[u])
                    {
                        u = r;
                    }
                }
                tempnama = copynama[g];
                copynama[g] = copynama[u];
                copynama[u] = tempnama;

                tempusername = copyusername[g];
                copyusername[g] = copyusername[u];
                copyusername[u] = tempusername;

                tempidentity = copyidentity[g];
                copyidentity[g] = copyidentity[u];
                copyidentity[u] = tempidentity;

                temptabungan = copytabungan[g];
                copytabungan[g] = copytabungan[u];
                copytabungan[u] = temptabungan;
            } //Lopping Untuk Sorting Data.
            cout << endl;
            cout << "|======================================================================================|\n";
            cout << "|                           Data Terurut Dengan Mode Descending (Z-A)                   |\n";
            cout << "|======================================================================================|\n";
            cout << endl;
            cout << "NO.\tUSERNAME\tNAMA MEMBER\t\t\tNo.Identitas\t\tSaldo" << endl;
            for (int ur = 0; ur < x; ur++)
            {
                cout << ur + 1 << "."
                     << "\t" << copyusername[ur] << "\t" << copynama[ur] << "\t\t\t" << copyidentity[ur] << "\t\t\tRp. " << copytabungan[ur] << endl;
            } //Menampilkan Data yang sudah Ter Sort
            cout << endl;
            cout << "|======================================================================================|\n";
            system("pause");
            goto sor;
        }
        else if (sort == 3)
        {
            goto home;
        }
        else
        {
            cout << "Inputan Anda Salah ,INputkan Pilihan [1 / 2 / 3]" << endl;
            system("pause");
            goto sor;
        }
        system("pause");
        goto home;
    }
    else if (pil == 3)
    {
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      Menu Tambah Member                              |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Berapa Jumlah Data yang akan Anda Inputkan > ";
        cin >> indt;
        //B= 4;
        int b = x;

        //++//INCREMENT
        //--//DECR
        for (x; x < indt + b; x++)
        {
            cout << "Masukan Data Member ke - " << x + 1 << endl;
            cout << "InpUt Nama Lengkap : ";
            cin.ignore();
            getline(cin, member.nama[x]);
            cout << "No. Identitas      : ";
            cin >> member.identity[x];
            cout << "Tabungan Awal      : Rp. ";
            cin >> member.tabungan[x];
            cout << "Buat Username      : ";
            cin >> member.username[x];
            cout << endl;
        }

        x = (x + indt) - indt;

        cout << "Data Berhasil Di INputkan !!!" << endl;
        cout << endl;
        system("pause");
        goto home;
    }
    else if (pil == 4)
    {
    mbalik:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                   Menu Edit Data Member                              |\n";
        cout << "|======================================================================================|\n";
        cout << "NO.\tUsername" << endl;
        int i;
        bool edit = false;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string nm;
        cout << "Untuk Edit Data Input Username Member = ";
        cin >> nm;
        for (i = 0; i < x; i++)
        {
            if (nm == member.username[i])
            {
                edit = true;
                cout << "Halo !!!, " << member.username[i];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : Rp. " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                char pila;
            ehe:
                cout << "Apakah Anda Yakin Ingin Mengubah Data Tersebut ? (Y/N) =>> ";
                cin >> pila;
                if (pila == 'y' || pila == 'Y')
                {
                    cout << "Ubah Data member " << member.username[i] << endl;
                    cout << "Ubah Nama          : ";
                    cin.ignore();
                    getline(cin, member.nama[i]);
                    cout << "Ubah no Identitas  : ";
                    cin >> member.identity[i];
                    cout << "Ubah Username      : ";
                    cin >> member.username[i];
                    cout << endl;
                    cout << "DATA BERHASIL DIUBAH !!!" << endl;
                    system("pause");
                    goto home;
                }
                else if (pila == 'n' || pila == 'N')
                {
                    system("pause");
                    goto home;
                }
                else
                {
                    cout << "Inputan Yang anda Masukan Salah !!!, Inputkan (Y/N)" << endl
                         << endl;
                    system("pause");
                    goto ehe;
                }
            }
        }
        if (edit == false)
        {
            cout << "Username Yang Anda Masukkan Tidak Ada!!!" << endl;
            system("pause");
            goto mbalik;
        }
    }
    else if (pil == 5)
    {
    busak:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                  Menu Hapus Data Member                              |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUsername" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string busak;

        cout << "Untuk Hapus Data Input Username Member = ";
        cin >> busak;
        bool delstatus = false;

        for (int j = 0; j < x; j++)
        {
            if (busak == member.username[j])
            {
                cout << "Halo !!!, " << member.username[j];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[j] << endl;
                cout << "Nama Member    : " << member.nama[j] << endl;
                cout << "Saldo Tabungan : Rp. " << member.tabungan[j] << endl;
                cout << "No. Identitas  : " << member.identity[j] << endl;
                cout << endl;
                char hps;
                cout << "Apakah Anda Yakin Ingin Mengahupus Data Tersebut ? (y/n) > ";
                cin >> hps;
                if (hps == 'y' || hps == 'Y')
                {
                    for (int k = j ; k < x; k++)
                    {
                        member.username[k]  = member.username[k + 1] ;
                        member.nama[k]      = member.nama[k + 1] ;
                        member.identity[k]  = member.identity[k + 1] ;
                        member.tabungan[k]  = member.tabungan[k + 1] ;
                    }

                    x -= 1;
                    delstatus = true;
                    cout << "Data Berhasil Dihapus !!!" << endl;
                    cout << endl;
                    break;
                }
                else if (hps == 'n' || hps == 'N')
                {
                    system("pause");
                    goto home;
                }
                else
                {
                    cout << "Inputan Salah,Inputkan (y/n)" << endl;
                    system("pause");
                    goto home;
                }
            }
        }
        if (delstatus == false)
        {
            cout << "Username " << busak << " Tidak Ditemukan !!!" << endl;
            system("pause");
            goto busak;
        }
        system("pause");
        goto home;
    }
    else if (pil == 6)
    {
    tabg:
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      Menu Menabung                                   |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUsername" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string tab;
        cout << "Untuk Menabung ,Silakan Input Username Member = ";
        cin >> tab;
        bool tabung = false;
        for (i = 0; i < x; i++)
        {
            if (tab == member.username[i])
            {
                cout << "Halo !!!, " << member.username[i];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                float baru;
                cout << "Masukan Jumlah Uang Yang akan Ditabung = Rp. ";
                cin >> baru;
                member.tabungan[i] = baru + member.tabungan[i];
                tabung = true;
                cout << endl;
                cout << "Berhasil Menambahkan Saldo Ke Akun Anda !!! " << endl;
                //revisi
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                system("pause");
                goto home;
            }
        }
        if (tabung == false)
        {
            cout << "Username " << tab << "Tidak Ditemukan !!!" << endl;
            system("pause");
            goto tabg;
        }
    }
    else if (pil == 7)
    {
    bali:
        system("cls");
        string ambil;
        float buang;
        cout << "|======================================================================================|\n";
        cout << "|                                  Menu Penarikan Uang                                 |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUsername" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        string tarik;
        cout << "Untuk Melakukan Penarikan Uang  ,Silakan Input Username Member = ";
        cin >> tarik;
        bool take = false;
        for (i = 0; i < x; i++)
        {
            if (tarik == member.username[i])
            {
                take = true;
                cout << "Halo !!!, " << member.username[i];
                cout << endl;
                cout << "Informasi Data Anda Saat Ini" << endl;
                cout << "Username       : " << member.username[i] << endl;
                cout << "Nama Member    : " << member.nama[i] << endl;
                cout << "Saldo Tabungan : Rp. " << member.tabungan[i] << endl;
                cout << "No. Identitas  : " << member.identity[i] << endl;
                cout << endl;
                float baru;
                cout << "Masukan Jumlah Uang yang akan diambil = Rp. ";
                cin >> baru;
                if (baru >= member.tabungan[i])
                {
                    cout << "Maaf, Saldo Anda Tidak Mencukupi Untuk Melakukan Penarikan !!!" << endl;
                    system("pause");
                    goto bali;
                }
                else if (baru < member.tabungan[i])
                {
                    member.tabungan[i] = member.tabungan[i] - baru;
                    cout << endl;
                    cout << "Berhasil Melakukan Penarikan Uang !!! " << endl;
                    cout << endl;
                    cout << "Informasi Data Anda Saat Ini" << endl;
                    cout << "Username       : " << member.username[i] << endl;
                    cout << "Nama Member    : " << member.nama[i] << endl;
                    cout << "Saldo Tabungan : Rp. " << member.tabungan[i] << endl;
                    cout << "No. Identitas  : " << member.identity[i] << endl;
                    cout << endl;
                print:
                    char ps;
                    cout << "Apakah Anda Akan Print Struck ? (y/n) > ";
                    cin >> ps;
                    if (ps == 'y' || ps == 'Y')
                    {

                        time_t now = time(0);
                        char *dt = ctime(&now);

                        ofstream struk;
                        struk.open("struk.txt");
                        struk << "==================================================\n";
                        struk << "\t\tBANK BERKAH BAROKAH\n";
                        struk << "\tWaktu Penarikan : " << dt;
                        struk << "==================================================\n";
                        struk << endl;
                        struk << "Nama Member           : " << member.nama[i] << "\n";
                        struk << "Jumlah Uang Diambil   : Rp. " << baru << "\n";
                        struk << "Sisa Saldo Tabungan   : Rp. " << member.tabungan[i] << "\n";
                        struk << endl;
                        struk << "=================================================\n";
                        struk << "\tTERIMAKASIH TELAH MELAKUKAN TRANSAKSI\n";
                        struk.close();
                        system("notepad.exe struk.txt");
                        system("pause");
                        goto home;
                    }
                    else if (ps == 'n' || ps == 'N')
                    {
                        system("pause");
                        goto home;
                    }
                    else
                    {
                        cout << "Inputan Salah,Inputkan (y/n)" << endl;
                        system("pause");
                        goto print;
                    }
                }
            }
        }
        if (take == false)
        {
            cout << "Username " << tarik << " Tidak Ditemukan !!!" << endl;
            system("pause");
            goto bali;
        }
    }
    else if (pil == 8)
    {
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      Menu Pencarian Data                             |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "NO.\tUSERNAME" << endl;
        int i;
        for (i = 0; i < x; i++)
        {
            cout << i + 1 << "\t" << member.username[i] << endl;
        }
        cout << endl;
        cout << "|======================================================================================|\n";
        string cari;
        cout << endl;
        bool golek = false;
        cout << "Inputkan Username Data yang Akan Anda Cari > ";
        cin >> cari;
        int q;
        for (q = 0; q < x; q++)
        {
            if (cari == member.username[q])
            {

                cout << "Username " << member.username[q] << " Ditemukan !!!" << endl;
                cout << endl;
            ifdta:
                char pl;
                cout << "Tampilkan Informasi Lengkap Data ? (y/n) => ";
                cin >> pl;
                if (pl == 'y' || pl == 'Y')
                {
                    cout << endl;
                    cout << "Informasi Data Anda Saat Ini" << endl;
                    cout << "Username       : " << member.username[q] << endl;
                    cout << "Nama Member    : " << member.nama[q] << endl;
                    cout << "Saldo Tabungan : " << member.tabungan[q] << endl;
                    cout << "No. Identitas  : " << member.identity[q] << endl;
                    cout << endl;
                    system("pause");
                    goto home;
                }
                else if (pl == 'n' || pl == 'N')
                {
                    system("pause");
                    goto home;
                }
                else
                {
                    cout << "Inputan Anda Salah !!!, Inputkan (y/n)" << endl;
                    system("pause");
                    goto ifdta;
                }
                golek = true;
            }
        }
        if (golek == false)
        {
            cout << "Username " << cari << " Tidak Ditemukan !!!" << endl;
            system("pause");
            goto home;
        }
    }
    else if (pil == 9)
    {
        system("cls");
        cout << "|======================================================================================|\n";
        cout << "|                                      About Us                                        |\n";
        cout << "|======================================================================================|\n";
        cout << endl;
        cout << "Sistem Ini Dibuat Oleh : " << endl;
        cout << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "|              NAMA                    |    NIM     |" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "| 1. Rio Aditya P		                | 19.11.26** |" << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << endl;
        cout << "|======================================================================================|\n";
        system("pause");
        goto home;
    }
    else if (pil == 10)
    {
        system("cls");
        cout << endl;
        cout << "#########################" << endl;
        cout << "|T|e|r|i|m|a| |K|a|s|i|h|" << endl;
        cout << "#########################" << endl;
        cout << endl;
        system("pause");
        return 0;
    }
    else
    {
        cout << "Inputan Salah !!!,SIlakan Masukan Pilihan yang Benar [ 1 / 2 / 3 / 4 / 5 / 6 / 7 / 8 / 9]" << endl;
        system("pause");
        goto home;
    }
}
