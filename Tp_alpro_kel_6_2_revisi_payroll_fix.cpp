#include <iostream>
#include <iomanip>	
#include <string>
#include <sstream> 
#include <fstream>
using namespace std;

string formatRupiah(double nominal)
{
    stringstream ss;
    ss << fixed << setprecision(0) << nominal;

    string angka = ss.str();
    string hasil = "";

    int hitung = 0;

    for(int i = angka.length() - 1; i >= 0; i--)
    {
        hasil = angka[i] + hasil;
        hitung++;

        if(hitung == 3 && i != 0)
        {
            hasil = "." + hasil;
            hitung = 0;
        }
    }

    return "Rp " + hasil;
}

class Welcome
{
public:

    void tampilAwal()
    {
        cout << "\n\n";

        cout << "=================================================================================================\n";
        cout << "||                                                                                             ||\n";
        cout << "||                  MARUGAME UDON JAPANESE NOODLES & TEMPURA                                   ||\n";
        cout << "||                                                                                             ||\n";
        cout << "||                           RESTAURANT MANAGEMENT SYSTEM                                      ||\n";
        cout << "||                                                                                             ||\n";
        cout << "=================================================================================================\n\n";

        cout << "                           EMPLOYEE PAYROLL MANAGEMENT SYSTEM\n";
        cout << "                      Human Resource & Restaurant Management\n";
        cout << "                           \"Freshly Made. Every Day.\"\n\n";

        cout << "                                  _.-''''-._\n";
        cout << "                               .-'  .--.    '-.\n";
        cout << "                             .'   .'    '.     '.\n";
        cout << "                            /    /  O  O  \\      \\\n";
        cout << "                           |    |     ^    |      |\n";
        cout << "                           |    |   \\___/   |      |\n";
        cout << "                            \\    \\        /      /\n";
        cout << "                             '.   '.___.'     .'\n";
        cout << "                               '-._______.-'\n";
        cout << "                                  HOT UDON BOWL\n\n";

        cout << "=================================================================================================\n";
        cout << "                                  WELCOME TO THE SYSTEM\n";
        cout << "=================================================================================================\n\n";

        cout << "Restaurant Management System ini dirancang untuk membantu proses\n";
        cout << "pengelolaan operasional restoran, mulai dari data karyawan,\n";
        cout << "absensi, jadwal kerja, bonus, lembur, hingga sistem penggajian\n";
        cout << "karyawan secara efektif dan terintegrasi.\n\n";

        cout << "-------------------------------------------------------------------------------------------------\n";
        cout << "                                   SYSTEM FEATURES\n";
        cout << "-------------------------------------------------------------------------------------------------\n";

        cout << "   [1] Employee Management\n";
        cout << "   [2] Position Management\n";
        cout << "   [3] Work Shift Management\n";
        cout << "   [4] Attendance Management\n";
        cout << "   [5] Overtime & Bonus Management\n";
        cout << "   [6] Payroll Management\n";
        cout << "   [7] Salary Slip\n";
        cout << "   [8] Monthly Payroll Report\n";
        cout << "   [9] Employee Statistics\n\n";
        
        

        cout << "-------------------------------------------------------------------------------------------------\n";

        cout << left;
        cout << setw(20) << "Restaurant"
             << ": Marugame Udon Japanese Noodles & Tempura\n";

        cout << setw(20) << "Version"
             << ": 1.0\n";

        cout << setw(20) << "Developer"
             << ": Hani Julia Santika\n";

        cout << setw(20) << "Programming"
             << ": C++ Object Oriented Programming\n";

        cout << setw(20) << "Project"
             << ": Final Project Simulation\n";

        cout << "-------------------------------------------------------------------------------------------------\n\n";

        cout << "                         Press ENTER to Continue...";
        cin.get();
    }
};

class Login
{
private:

    string username;
    
    string password;

public:

    bool loginAdmin()
    {
        cout<<"\n";
        cout<<"============================================\n";
        cout<<"               LOGIN ADMIN\n";
        cout<<"============================================\n";

        cout<<"Username : ";
        cin>>username;

        cout<<"Password : ";
        cin>>password;

        if(username=="admin" && password=="admin123")
        {
            cout<<"\nLogin Berhasil!\n";
            return true;
        }

        cout<<"\nUsername atau Password Salah!\n";

        return false;
    }

};

//====================================================
// CLASS DASHBOARD
//====================================================
class Dashboard
{
private:
    int pilihan;

public:

    void menuAdmin()
    {
        cout << "\n\n";
        cout << "===============================================================\n";
        cout << "          MARUGAME UDON JAPANESE NOODLES & TEMPURA\n";
        cout << "===============================================================\n";
        cout << "                  DASHBOARD ADMIN\n";
        cout << "===============================================================\n\n";

        cout << "--------------- MASTER DATA -----------------\n";
        cout << "1. Data Karyawan\n";
        cout << "2. Data Jabatan\n";
        cout << "3. Data Shift\n\n";

        cout << "--------------- TRANSAKSI -------------------\n";
        cout << "4. Data Absensi\n";
        cout << "5. Data Lembur\n";
        cout << "6. Data Bonus\n";
        cout << "7. Penggajian\n\n";

        cout << "--------------- LAPORAN ---------------------\n";
        cout << "8. Slip Gaji\n";
        cout << "9. Laporan Gaji\n\n";

        cout << "0. Logout\n";

        cout << "\n===============================================================\n";
        cout << "Pilih Menu : ";
        cin >> pilihan;
    }

    int getPilihan()
    {
        return pilihan;
    }

};

class Employee
{
public:

    struct Karyawan
    {
        string id;
        string nama;
        string jenisKelamin;
        int umur;
        string noHP;
        string alamat;
        string jabatan;
        string shift;
        long long int gajiPokok;
    };

private:

    Karyawan data[100];
    int jumlah;
    int pilihan;

public:
	
	Employee () 
	{
		jumlah = 0;	
		loadData();
	}
	

    string generateID()
    {
        int terbesar = 0;

        for(int i = 0; i < jumlah; i++)
        {
            string angka = data[i].id.substr(3);

            int nomor;
            stringstream ss(angka);
            ss >> nomor;


            if(nomor > terbesar)
                terbesar = nomor;
        }

        terbesar++;

        stringstream ss;

        ss << "EMP";

        if(terbesar < 10)
            ss << "00";
        else if(terbesar < 100)
            ss << "0";

        ss << terbesar;

        return ss.str();
    }

    void menuEmployee()
    {
        cout << "\n";
        cout << "=========================================================\n";
        cout << "                  DATA KARYAWAN\n";
        cout << "=========================================================\n";

        cout << "1. Tambah Data Karyawan\n";
        cout << "2. Lihat Data Karyawan\n";
        cout << "3. Cari Data Karyawan\n";
        cout << "4. Edit Data Karyawan\n";
        cout << "5. Hapus Data Karyawan\n";
        cout << "0. Kembali\n";

        cout << "=========================================================\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
    }

    int getPilihan()
    
    {
        return pilihan;
 	}
 	
 void tambahKaryawan()
{
    int n;

    cout << "\nJumlah data yang ingin ditambahkan : ";
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++)
    {
        cout << "\n==============================\n";
        cout << "Data Karyawan Ke-" << i+1 << endl;
        cout << "==============================\n";

        data[jumlah].id = generateID();

        cout << "ID Karyawan : "
             << data[jumlah].id << endl;

        cout << "Nama : ";
        getline(cin, data[jumlah].nama);

        cout << "Jenis Kelamin : ";
        getline(cin, data[jumlah].jenisKelamin);

        cout << "Umur : ";
        cin >> data[jumlah].umur;
        cin.ignore();

        cout << "No HP : ";
        getline(cin, data[jumlah].noHP);

        cout << "Alamat : ";
        getline(cin, data[jumlah].alamat);

        cout << "Jabatan : ";
        getline(cin, data[jumlah].jabatan);

        cout << "Shift : ";
        getline(cin, data[jumlah].shift);

        cout << "Gaji Pokok : ";
        cin >> data[jumlah].gajiPokok;
        cin.ignore();

        jumlah++;
    }

    simpanData();

    cout << "\nData berhasil ditambahkan.\n";
}
 
void lihatKaryawan()
{
    system("cls");

    cout << "\n==============================================================\n";
    cout << "                 DATA SELURUH KARYAWAN\n";
    cout << "==============================================================\n";

    if(jumlah == 0)
    {
        cout << "\nData Karyawan Masih Kosong.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Nama"
         << setw(15) << "Jabatan"
         << setw(10) << "Shift"
         << setw(15) << "Gaji"
         << endl;

    cout << "==============================================================\n";

    for(int i=0;i<jumlah;i++)
    {
        cout << left
             << setw(10) << data[i].id
             << setw(20) << data[i].nama
             << setw(15) << data[i].jabatan
             << setw(10) << data[i].shift
             << setw(15) << data[i].gajiPokok
             << endl;
    }
}

void cariKaryawan()
{
    string cari;

    cout << "\nMasukkan ID Karyawan : ";
    cin.ignore();
    getline(cin,cari);

    bool ketemu = false;

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].id == cari)
        {
            cout << "\n========== DATA DITEMUKAN ==========\n";

            cout << "ID             : " << data[i].id << endl;
            cout << "Nama           : " << data[i].nama << endl;
            cout << "Jenis Kelamin  : " << data[i].jenisKelamin << endl;
            cout << "Umur           : " << data[i].umur << endl;
            cout << "No HP          : " << data[i].noHP << endl;
            cout << "Alamat         : " << data[i].alamat << endl;
            cout << "Jabatan        : " << data[i].jabatan << endl;
            cout << "Shift          : " << data[i].shift << endl;
            cout << "Gaji Pokok     : " << data[i].gajiPokok << endl;

            ketemu = true;
            break;
        }
    }

    if(!ketemu)
        cout << "\nData Tidak Ditemukan.\n";
}

void editKaryawan()
{
    string cari;

    cout << "\nMasukkan ID Karyawan yang akan diedit : ";
    cin.ignore();
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].id == cari)
        {
            cout << "\nData Baru\n";

            cout << "Nama : ";
            getline(cin,data[i].nama);

            cout << "Jenis Kelamin : ";
            getline(cin,data[i].jenisKelamin);

            cout << "Umur : ";
            cin >> data[i].umur;
            cin.ignore();

            cout << "No HP : ";
            getline(cin,data[i].noHP);

            cout << "Alamat : ";
            getline(cin,data[i].alamat);

            cout << "Jabatan : ";
            getline(cin,data[i].jabatan);

            cout << "Shift : ";
            getline(cin,data[i].shift);

            cout << "Gaji Pokok : ";
            cin >> data[i].gajiPokok;
            cin.ignore();
            
            
            simpanData();

            cout << "\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void hapusKaryawan()
{
    string cari;

    cout << "\nMasukkan ID Karyawan yang akan dihapus : ";
    cin.ignore();
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].id == cari)
        {
            for(int j=i;j<jumlah-1;j++)
            {
                data[j]=data[j+1];
            }

            jumlah--;
            
            simpanData();

            cout << "\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void simpanData()
{
    ofstream file("dataKaryawan.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i=0; i<jumlah; i++)
    {
        file
        << data[i].id << "|"
        << data[i].nama << "|"
        << data[i].jenisKelamin << "|"
        << data[i].umur << "|"
        << data[i].noHP << "|"
        << data[i].alamat << "|"
        << data[i].jabatan << "|"
        << data[i].shift << "|"
        << data[i].gajiPokok
        << endl;
    }

    file.close();
}

void loadData()
{
    ifstream file("dataKaryawan.txt");

    if(!file)
        return;

    jumlah = 0;

    while(jumlah < 100 &&
		  getline(file, data[jumlah].id, '|'))
    {
        getline(file, data[jumlah].nama, '|');
        getline(file, data[jumlah].jenisKelamin, '|');

        file >> data[jumlah].umur;
        file.ignore();

        getline(file, data[jumlah].noHP, '|');
        getline(file, data[jumlah].alamat, '|');
        getline(file, data[jumlah].jabatan, '|');
        getline(file, data[jumlah].shift, '|');

       	file >> data[jumlah].gajiPokok;
		file.ignore(1000, '\n');

        jumlah++;
    }

    file.close();
}

Karyawan* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}

};

class Position
{
public:

    struct Jabatan
    {
        string kode;
        string namaJabatan;
        long long int gajiPokok;
        long long int tunjangan;
    };

private:
	Jabatan data[100];
    int jumlah;
    int pilihan;

public:
    Position()
    {
        jumlah = 0;
        loadData();
    }
    
    string generateKodeJabatan()
{
    int terbesar = 0;

    for(int i = 0; i < jumlah; i++)
    {
        if(data[i].kode.length() >= 6)
        {
            string angka = data[i].kode.substr(3);

            int nomor;

            stringstream ss(angka);
            ss >> nomor;

            if(nomor > terbesar)
                terbesar = nomor;
        }
    }

    terbesar++;

    stringstream hasil;

    hasil << "JBT";

    if(terbesar < 10)
        hasil << "00";
    else if(terbesar < 100)
        hasil << "0";

    hasil << terbesar;

    return hasil.str();
}
    
    void menuPosition()
    {
        cout << "\n";
        cout << "=========================================================\n";
        cout << "                  DATA JABATAN\n";
        cout << "=========================================================\n";

        cout << "1. Tambah Data Jabatan\n";
        cout << "2. Lihat Data Jabatan\n";
        cout << "3. Cari Data Jabatan\n";
        cout << "4. Edit Data Jabatan\n";
        cout << "5. Hapus Data Jabatan\n";
        cout << "0. Kembali\n";

        cout << "=========================================================\n";
        cout << "Masukkan Pilihan : ";
        cin >> pilihan;
    }

    int getPilihan()
    {
    	
        return pilihan;
        
    }
    
    void tambahJabatan()
    {
        int n;

        cout << "\nJumlah Jabatan yang ingin ditambahkan : ";
        cin >> n;
        cin.ignore();

        for(int i=0;i<n;i++)
{
    cout << "\n=========================================\n";
    cout << "Data Jabatan Ke-" << i+1 << endl;
    cout << "=========================================\n";

    data[jumlah].kode = generateKodeJabatan();

    cout << "Kode Jabatan : "
         << data[jumlah].kode << endl;

    cout << "Nama Jabatan : ";
    getline(cin,data[jumlah].namaJabatan);

    cout << "Gaji Pokok : ";
    cin >> data[jumlah].gajiPokok;

    cout << "Tunjangan : ";
    cin >> data[jumlah].tunjangan;
    cin.ignore();

    jumlah++;
}

simpanData();

        cout << "\nData Jabatan Berhasil Ditambahkan.\n";
    }
    
    void lihatJabatan()
    {
        if(jumlah==0)
        {
            cout << "\nBelum ada data jabatan.\n";
            return;
        }

        cout << "\n================================================================================\n";
        cout << left
             << setw(15) << "Kode"
             << setw(25) << "Nama Jabatan"
             << setw(20) << "Gaji Pokok"
             << setw(20) << "Tunjangan"
             << endl;

        cout << "================================================================================\n";

        for(int i=0;i<jumlah;i++)
        {
            cout << left
                 << setw(15) << data[i].kode
                 << setw(25) << data[i].namaJabatan
                 << setw(20) << data[i].gajiPokok
                 << setw(20) << data[i].tunjangan
                 << endl;
        }
    }
    
     void cariJabatan()
    {
        string cari;
        bool ketemu=false;

        cin.ignore();

        cout << "\nMasukkan Kode Jabatan : ";
        getline(cin,cari);

        for(int i=0;i<jumlah;i++)
        {
            if(data[i].kode==cari)
            {
                cout << "\nKode Jabatan : " << data[i].kode << endl;
                cout << "Nama Jabatan : " << data[i].namaJabatan << endl;
                cout << "Gaji Pokok   : " << data[i].gajiPokok << endl;
                cout << "Tunjangan    : " << data[i].tunjangan << endl;

                ketemu=true;
                break;
            }
        }

        if(!ketemu)
        {
            cout << "\nData Tidak Ditemukan.\n";
        }
    }
	
	 void editJabatan()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan Kode Jabatan : ";
    getline(cin, cari);

    for(int i = 0; i < jumlah; i++)
    {
        if(data[i].kode == cari)
        {
            cout << "\n=====================================\n";
            cout << "      EDIT DATA JABATAN\n";
            cout << "=====================================\n";

            // Hanya ditampilkan, tidak bisa diubah
            cout << "Kode Jabatan : " << data[i].kode << endl;

            cout << "Nama Jabatan Baru : ";
            getline(cin, data[i].namaJabatan);

            cout << "Gaji Pokok Baru : ";
            cin >> data[i].gajiPokok;

            cout << "Tunjangan Baru : ";
            cin >> data[i].tunjangan;
            cin.ignore();

            simpanData();

            cout << "\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}
    
    void hapusJabatan()
    {
        string cari;

        cin.ignore();

        cout << "\nMasukkan Kode Jabatan : ";
        getline(cin,cari);

        for(int i=0;i<jumlah;i++)
        {
            if(data[i].kode==cari)
            {
                for(int j=i;j<jumlah-1;j++)
                {
                    data[j]=data[j+1];
                }

                jumlah--;
                
                simpanData();

                cout << "\nData Berhasil Dihapus.\n";
                return;
            }
        }

        cout << "\nData Tidak Ditemukan.\n";
    }
    
    void simpanData()
{
    ofstream file("dataJabatan.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i=0;i<jumlah;i++)
    {
        file
        << data[i].kode << "|"
        << data[i].namaJabatan << "|"
        << data[i].gajiPokok << "|"
        << data[i].tunjangan
        << endl;
    }

    file.close();
}

	void loadData()
{
    ifstream file("dataJabatan.txt");

    if(!file)
        return;

    jumlah = 0;

    while(jumlah < 100 &&
          getline(file, data[jumlah].kode, '|'))
    {
        getline(file, data[jumlah].namaJabatan, '|');

        file >> data[jumlah].gajiPokok;
        file.ignore();

        file >> data[jumlah].tunjangan;
        file.ignore(1000, '\n');

        jumlah++;
    }

    file.close();
}

    Jabatan* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}
    
};

class Shift
{
private:

    struct DataShift
    {
        string kodeShift;
        string namaShift;
        string jamMasuk;
        string jamPulang;
        double uangMakan;
    };

    DataShift data[100];

    int jumlah;
    int pilihan;

public:

    Shift()
    {
        jumlah = 0;
        loadData();
    }
    
    string generateKodeShift()
{
    int terbesar = 0;

    for(int i = 0; i < jumlah; i++)
    {
        if(data[i].kodeShift.length() >= 6)
        {
            string angka = data[i].kodeShift.substr(3);

            int nomor;
            stringstream ss(angka);
            ss >> nomor;

            if(nomor > terbesar)
                terbesar = nomor;
        }
    }

    terbesar++;

    stringstream hasil;

    hasil << "SFT";

    if(terbesar < 10)
        hasil << "00";
    else if(terbesar < 100)
        hasil << "0";

    hasil << terbesar;

    return hasil.str();
}
    
	void menuShift()
{
    cout << "\n";
    cout << "=========================================================\n";
    cout << "                  DATA SHIFT KERJA\n";
    cout << "=========================================================\n";

    cout << "1. Tambah Data Shift\n";
    cout << "2. Lihat Data Shift\n";
    cout << "3. Cari Data Shift\n";
    cout << "4. Edit Data Shift\n";
    cout << "5. Hapus Data Shift\n";
    cout << "0. Kembali\n";

    cout << "=========================================================\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
}

int getPilihan()
{
    return pilihan;
}

void tambahShift()
{
    int n;

    cout << "\nJumlah Shift yang ingin ditambahkan : ";
    cin >> n;
    cin.ignore();

    for(int i=0;i<n;i++)
    {
        cout << "\n=========================================\n";
        cout << "Data Shift Ke-" << i+1 << endl;
        cout << "=========================================\n";

        data[jumlah].kodeShift = generateKodeShift();

		cout << "Kode Shift : "
     		 << data[jumlah].kodeShift << endl;

        cout << "Nama Shift : ";
        getline(cin,data[jumlah].namaShift);

        cout << "Jam Masuk : ";
        getline(cin,data[jumlah].jamMasuk);

        cout << "Jam Pulang : ";
        getline(cin,data[jumlah].jamPulang);

        cout << "Uang Makan : ";
        cin >> data[jumlah].uangMakan;
        cin.ignore();

        jumlah++;
        
    }
    
    simpanData();

    cout << "\nData Shift Berhasil Ditambahkan.\n";
}

void lihatShift()
{
    if(jumlah==0)
    {
        cout << "\nData Shift Masih Kosong.\n";
        return;
    }

    cout << "\n=====================================================================================================\n";

    cout << left
         << setw(15) << "Kode"
         << setw(20) << "Nama Shift"
         << setw(15) << "Masuk"
         << setw(15) << "Pulang"
         << setw(20) << "Uang Makan"
         << endl;

    cout << "=====================================================================================================\n";

    for(int i=0;i<jumlah;i++)
    {
        cout << left
             << setw(15) << data[i].kodeShift
             << setw(20) << data[i].namaShift
             << setw(15) << data[i].jamMasuk
             << setw(15) << data[i].jamPulang
             << setw(20) << data[i].uangMakan
             << endl;
    }
} 

void cariShift()
{
    string cari;
    bool ketemu=false;

    cin.ignore();

    cout << "\nMasukkan Kode Shift : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].kodeShift==cari)
        {
            cout << "\nKode Shift  : " << data[i].kodeShift << endl;
            cout << "Nama Shift  : " << data[i].namaShift << endl;
            cout << "Jam Masuk   : " << data[i].jamMasuk << endl;
            cout << "Jam Pulang  : " << data[i].jamPulang << endl;
            cout << "Uang Makan  : " << data[i].uangMakan << endl;

            ketemu=true;
            break;
        }
    }

    if(!ketemu)
    {
        cout << "\nData Tidak Ditemukan.\n";
    }
}

void editShift()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan Kode Shift : ";
    getline(cin, cari);

    for(int i = 0; i < jumlah; i++)
    {
        if(data[i].kodeShift == cari)
        {
            cout << "\n=====================================\n";
            cout << "        EDIT DATA SHIFT\n";
            cout << "=====================================\n";

            // Kode hanya ditampilkan, tidak bisa diubah
            cout << "Kode Shift : " << data[i].kodeShift << endl;

            cout << "Nama Shift Baru : ";
            getline(cin, data[i].namaShift);

            cout << "Jam Masuk Baru : ";
            getline(cin, data[i].jamMasuk);

            cout << "Jam Pulang Baru : ";
            getline(cin, data[i].jamPulang);

            cout << "Uang Makan Baru : ";
            cin >> data[i].uangMakan;
            cin.ignore();

            simpanData();

            cout << "\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}
void hapusShift()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan Kode Shift : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].kodeShift==cari)
        {
            for(int j=i;j<jumlah-1;j++)
            {
                data[j]=data[j+1];
            }

            jumlah--;
            
            simpanData();

            cout << "\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
  }
  
  void simpanData()
{
    ofstream file("dataShift.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i = 0; i < jumlah; i++)
    {
        file
        << data[i].kodeShift << "|"
        << data[i].namaShift << "|"
        << data[i].jamMasuk << "|"
        << data[i].jamPulang << "|"
        << data[i].uangMakan
        << endl;
    }

    file.close();
}

	void loadData()
{
    ifstream file("dataShift.txt");

    if(!file)
        return;

    jumlah = 0;

    while(jumlah < 100 &&
          getline(file, data[jumlah].kodeShift, '|'))
    {
        getline(file, data[jumlah].namaShift, '|');
        getline(file, data[jumlah].jamMasuk, '|');
        getline(file, data[jumlah].jamPulang, '|');

        file >> data[jumlah].uangMakan;
        file.ignore(1000, '\n');

        jumlah++;
    }

    file.close();
}
  
  DataShift* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}

};

class Attendance
{
public:

    struct Absensi
    {
        string idKaryawan;
        string nama;
        string tanggal;
        string shift;
        string status;
    };

    Absensi data[500];

    int jumlah;
    int pilihan;
    
    Employee *employee;

public:

    Attendance(Employee &emp)
    {
    	employee = &emp;
    	
        jumlah = 0;
        loadData();
    }    
    
    void menuAttendance()
{
    cout << "\n";
    cout << "=========================================================\n";
    cout << "                 DATA ABSENSI\n";
    cout << "=========================================================\n";

    cout << "1. Tambah Absensi\n";
    cout << "2. Lihat Absensi\n";
    cout << "3. Cari Absensi\n";
    cout << "4. Edit Absensi\n";
    cout << "5. Hapus Absensi\n";
    cout << "0. Kembali\n";

    cout << "=========================================================\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
}

int getPilihan()
{
    return pilihan;
}

void tambahAbsensi()
{
    string idCari;
    bool ketemu = false;

    Employee::Karyawan *karyawan = employee->getData();

    cout << "\n===============================================\n";
    cout << "           DAFTAR DATA KARYAWAN\n";
    cout << "===============================================\n";

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Nama"
         << setw(15) << "Shift"
         << endl;

    cout << "-----------------------------------------------\n";

    for(int i = 0; i < employee->getJumlah(); i++)
    {
        cout << left
             << setw(10) << karyawan[i].id
             << setw(25) << karyawan[i].nama
             << setw(15) << karyawan[i].shift
             << endl;
    }

    cout << "\nMasukkan ID Karyawan : ";
    cin.ignore();
    getline(cin, idCari);

    for(int i = 0; i < employee->getJumlah(); i++)
    {
        if(karyawan[i].id == idCari)
        {
            ketemu = true;

            data[jumlah].idKaryawan = karyawan[i].id;
            data[jumlah].nama = karyawan[i].nama;
            data[jumlah].shift = karyawan[i].shift;

            break;
        }
    }

    if(!ketemu)
    {
        cout << "\n=======================================\n";
        cout << "ID Karyawan Tidak Ditemukan!\n";
        cout << "=======================================\n";
        return;
    }

    cout << "\n=======================================\n";
    cout << "      DATA KARYAWAN DITEMUKAN\n";
    cout << "=======================================\n";

    cout << "ID Karyawan : "
         << data[jumlah].idKaryawan << endl;

    cout << "Nama        : "
         << data[jumlah].nama << endl;

    cout << "Shift       : "
         << data[jumlah].shift << endl;

    cout << "\nTanggal (dd/mm/yyyy) : ";
    getline(cin, data[jumlah].tanggal);

    cout << "Status (Hadir/Izin/Sakit/Alpha) : ";
    getline(cin, data[jumlah].status);

    jumlah++;

    simpanData();

    cout << "\nData Absensi Berhasil Ditambahkan.\n";
}

void lihatAbsensi()
{
    if(jumlah==0)
    {
        cout<<"\nData Absensi Masih Kosong.\n";
        return;
    }

    cout<<"\n=================================================================================================\n";

    cout<<left
        <<setw(15)<<"ID"
        <<setw(25)<<"Nama"
        <<setw(15)<<"Tanggal"
        <<setw(15)<<"Shift"
        <<setw(15)<<"Status"<<endl;

    cout<<"=================================================================================================\n";

    for(int i=0;i<jumlah;i++)
    {
        cout<<left
            <<setw(15)<<data[i].idKaryawan
            <<setw(25)<<data[i].nama
            <<setw(15)<<data[i].tanggal
            <<setw(15)<<data[i].shift
            <<setw(15)<<data[i].status
            <<endl;
    }
}

void cariAbsensi()
{
    string cari;
    bool ketemu=false;

    cin.ignore();

    cout<<"\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout<<"\nID       : "<<data[i].idKaryawan<<endl;
            cout<<"Nama     : "<<data[i].nama<<endl;
            cout<<"Tanggal  : "<<data[i].tanggal<<endl;
            cout<<"Shift    : "<<data[i].shift<<endl;
            cout<<"Status   : "<<data[i].status<<endl;

            ketemu=true;
            break;
        }
    }

    if(!ketemu)
        cout<<"\nData Tidak Ditemukan.\n";
}

void editAbsensi()
{
    string cari;

    cin.ignore();

    cout<<"\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout<<"Nama Baru : ";
            getline(cin,data[i].nama);

            cout<<"Tanggal Baru : ";
            getline(cin,data[i].tanggal);

            cout<<"Shift Baru : ";
            getline(cin,data[i].shift);

            cout<<"Status Baru : ";
            getline(cin,data[i].status);
            
            simpanData();

            cout<<"\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout<<"\nData Tidak Ditemukan.\n";
}

void hapusAbsensi()
{
    string cari;

    cin.ignore();

    cout<<"\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            for(int j=i;j<jumlah-1;j++)
            {
                data[j]=data[j+1];
            }

            jumlah--;
            
            simpanData();

            cout<<"\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout<<"\nData Tidak Ditemukan.\n";
   }
   
   void simpanData()
{
    ofstream file("dataAbsensi.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i = 0; i < jumlah; i++)
    {
        file
        << data[i].idKaryawan << "|"
        << data[i].nama << "|"
        << data[i].tanggal << "|"
        << data[i].shift << "|"
        << data[i].status
        << endl;
    }

    file.close();
}

void loadData()
{
    ifstream file("dataAbsensi.txt");

    if(!file)
        return;

    jumlah = 0;

    while(getline(file, data[jumlah].idKaryawan, '|'))
    {
        getline(file, data[jumlah].nama, '|');
        getline(file, data[jumlah].tanggal, '|');
        getline(file, data[jumlah].shift, '|');
        getline(file, data[jumlah].status);

        jumlah++;
    }

    file.close();
}	
   
   
   
   Absensi* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}
};

class Overtime
{
public:
    struct Lembur
    {
        string idKaryawan;
        string nama;
        string tanggal;
        int jamLembur;
        long long upahPerJam;
        long long totalLembur;
    };
private:
    Lembur data[100];

    int jumlah;
    int pilihan;
    
    Employee *employee;

public:
    Overtime(Employee &emp)
    {
    	employee = &emp;
    	
        jumlah = 0;
        loadData();
    }
    
   void menuOvertime()
{
    cout << "\n";
    cout << "=========================================================\n";
    cout << "                  DATA LEMBUR\n";
    cout << "=========================================================\n";

    cout << "1. Tambah Data Lembur\n";
    cout << "2. Lihat Data Lembur\n";
    cout << "3. Cari Data Lembur\n";
    cout << "4. Edit Data Lembur\n";
    cout << "5. Hapus Data Lembur\n";
    cout << "6. Hapus Semua Data Lembur\n";
    cout << "0. Kembali\n";

    cout << "=========================================================\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
}

int getPilihan()
{
    return pilihan;
}

void tambahLembur()
{
    string idCari;
    bool ketemu = false;

    Employee::Karyawan *karyawan = employee->getData();

    cout << "\n===============================================\n";
    cout << "           DAFTAR DATA KARYAWAN\n";
    cout << "===============================================\n";

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Nama"
         << endl;

    cout << "-----------------------------------------------\n";

    for(int i = 0; i < employee->getJumlah(); i++)
    {
        cout << left
             << setw(10) << karyawan[i].id
             << setw(25) << karyawan[i].nama
             << endl;
    }

    cout << "\nMasukkan ID Karyawan : ";
    cin.ignore();
    getline(cin, idCari);

    for(int i = 0; i < employee->getJumlah(); i++)
    {
        if(karyawan[i].id == idCari)
        {
            ketemu = true;

            data[jumlah].idKaryawan = karyawan[i].id;
            data[jumlah].nama = karyawan[i].nama;
            
            data[jumlah].upahPerJam = 50000;

            break;
        }
    }

    if(!ketemu)
    {
        cout << "\nID Karyawan Tidak Ditemukan!\n";
        return;
    }

    cout << "\n=====================================\n";
    cout << "DATA KARYAWAN DITEMUKAN\n";
    cout << "=====================================\n";

    cout << "ID Karyawan : " << data[jumlah].idKaryawan << endl;
    cout << "Nama        : " << data[jumlah].nama << endl;

    cout << "Tanggal : ";
    getline(cin, data[jumlah].tanggal);

    cout << "Jumlah Jam Lembur : ";
    cin >> data[jumlah].jamLembur;

    cout << "Upah Per Jam : "
    	 << data[jumlah].upahPerJam << endl;
    
    cin.ignore();

    data[jumlah].totalLembur =
        data[jumlah].jamLembur *
        data[jumlah].upahPerJam;

    jumlah++;

    simpanData();

    cout << "\nData Lembur Berhasil Ditambahkan.\n";
}

void lihatLembur()
{
    if(jumlah==0)
    {
        cout<<"\nData Lembur Masih Kosong.\n";
        return;
    }

    cout<<"\n==============================================================================================================\n";

    cout<<left
        <<setw(12)<<"ID"
        <<setw(20)<<"Nama"
        <<setw(15)<<"Tanggal"
        <<setw(10)<<"Jam"
        <<setw(18)<<"Upah/Jam"
        <<setw(18)<<"Total"
        <<endl;

    cout<<"==============================================================================================================\n";

    for(int i=0;i<jumlah;i++)
    {
        cout<<left
            <<setw(12)<<data[i].idKaryawan
            <<setw(20)<<data[i].nama
            <<setw(15)<<data[i].tanggal
            <<setw(10)<<data[i].jamLembur
            <<setw(18)<<data[i].upahPerJam
            <<setw(18)<<data[i].totalLembur
            <<endl;
    }
}

void cariLembur()
{
    string cari;
    bool ketemu=false;

    cin.ignore();

    cout<<"\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout<<"\nID            : "<<data[i].idKaryawan<<endl;
            cout<<"Nama          : "<<data[i].nama<<endl;
            cout<<"Tanggal       : "<<data[i].tanggal<<endl;
            cout<<"Jam Lembur    : "<<data[i].jamLembur<<endl;
            cout<<"Upah Per Jam  : "<<data[i].upahPerJam<<endl;
            cout<<"Total Lembur  : "<<data[i].totalLembur<<endl;

            ketemu=true;
            return;
        }
    }

    if(!ketemu)
        cout<<"\nData Tidak Ditemukan.\n";
}

void editLembur()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout << "\n=====================================\n";
            cout << "      EDIT DATA LEMBUR\n";
            cout << "=====================================\n";

            cout << "ID Karyawan : " << data[i].idKaryawan << endl;
            cout << "Nama        : " << data[i].nama << endl;

            cout << "Tanggal Baru : ";
            getline(cin,data[i].tanggal);

            cout << "Jam Lembur Baru : ";
            cin >> data[i].jamLembur;

            cout << "Upah Per Jam Baru : ";
            cin >> data[i].upahPerJam;
            cin.ignore();

            data[i].totalLembur =
                data[i].jamLembur *
                data[i].upahPerJam;

            simpanData();

            cout << "\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void hapusLembur()
{
    string cari;

    cin.ignore();

    cout<<"\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            for(int j=i;j<jumlah-1;j++)
            {
                data[j]=data[j+1];
            }

            jumlah--;
            
            simpanData();

            cout<<"\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout<<"\nData Tidak Ditemukan.\n";
}

void hapusSemuaLembur()
{
    char konfirmasi;

    cout << "\nYakin ingin menghapus SEMUA data lembur? (y/n) : ";
    cin >> konfirmasi;

    if(konfirmasi=='y' || konfirmasi=='Y')
    {
        jumlah = 0;

        simpanData();

        cout << "\nSemua Data Lembur Berhasil Dihapus.\n";
    }
    else
    {
        cout << "\nDibatalkan.\n";
    }
}

 void simpanData()
{
    ofstream file("dataLembur.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i = 0; i < jumlah; i++)
    {
        file
        << data[i].idKaryawan << "|"
        << data[i].nama << "|"
        << data[i].tanggal << "|"
        << data[i].jamLembur << "|"
        << data[i].upahPerJam << "|"
        << data[i].totalLembur
        << endl;
    }

    file.close();
}

void loadData()
{
    ifstream file("dataLembur.txt");

    if(!file)
        return;

    jumlah = 0;

    while(getline(file, data[jumlah].idKaryawan, '|'))
    {
        getline(file, data[jumlah].nama, '|');
        getline(file, data[jumlah].tanggal, '|');

        file >> data[jumlah].jamLembur;
        file.ignore();

        file >> data[jumlah].upahPerJam;
        file.ignore();

        file >> data[jumlah].totalLembur;
        file.ignore();

        jumlah++;
    }

    file.close();
}	

Lembur* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}

};

class Bonus
{
public:
    struct DataBonus
    {
        string idKaryawan;
        string nama;
        string tanggal;
        string jenisBonus;
        double nominalBonus;
    };
    
private:
    DataBonus data[100];

    int jumlah;
    int pilihan;
    
    Employee *employee;

public:
    Bonus(Employee &emp)
    {
    	employee = &emp;
    	
        jumlah = 0;
        loadData();
    }
    
    void menuBonus()
{
    cout << "\n";
    cout << "=========================================================\n";
    cout << "                    DATA BONUS\n";
    cout << "=========================================================\n";

    cout << "1. Tambah Data Bonus\n";
    cout << "2. Lihat Data Bonus\n";
    cout << "3. Cari Data Bonus\n";
    cout << "4. Edit Data Bonus\n";
    cout << "5. Hapus Data Bonus\n";
    cout << "0. Kembali\n";

    cout << "=========================================================\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
}

int getPilihan()
{
    return pilihan;
}

void tambahBonus()
{
    string idCari;
    bool ketemu = false;

    Employee::Karyawan *karyawan = employee->getData();

    cout << "\n===============================================\n";
    cout << "           DAFTAR DATA KARYAWAN\n";
    cout << "===============================================\n";

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Nama"
         << endl;

    cout << "-----------------------------------------------\n";

    for(int i = 0; i < employee->getJumlah(); i++)
    {
        cout << left
             << setw(10) << karyawan[i].id
             << setw(25) << karyawan[i].nama
             << endl;
    }

    cout << "\nMasukkan ID Karyawan : ";
    cin.ignore();
    getline(cin, idCari);

    for(int i = 0; i < employee->getJumlah(); i++)
    {
        if(karyawan[i].id == idCari)
        {
            ketemu = true;

            data[jumlah].idKaryawan = karyawan[i].id;
            data[jumlah].nama = karyawan[i].nama;

            break;
        }
    }

    if(!ketemu)
    {
        cout << "\n=======================================\n";
        cout << "ID Karyawan Tidak Ditemukan!\n";
        cout << "=======================================\n";
        return;
    }

    cout << "\n=======================================\n";
    cout << "      DATA KARYAWAN DITEMUKAN\n";
    cout << "=======================================\n";

    cout << "ID Karyawan : " << data[jumlah].idKaryawan << endl;
    cout << "Nama        : " << data[jumlah].nama << endl;

    cout << "Tanggal Bonus : ";
    getline(cin, data[jumlah].tanggal);

    cout << "Jenis Bonus : ";
    getline(cin, data[jumlah].jenisBonus);

    cout << "Nominal Bonus : ";
    cin >> data[jumlah].nominalBonus;
    cin.ignore();

    jumlah++;

    simpanData();

    cout << "\nData Bonus Berhasil Ditambahkan.\n";
}

void lihatBonus()
{
    if(jumlah==0)
    {
        cout << "\nData Bonus Masih Kosong.\n";
        return;
    }

    cout << "\n====================================================================================================\n";

    cout << left
         << setw(12) << "ID"
         << setw(20) << "Nama"
         << setw(15) << "Tanggal"
         << setw(25) << "Jenis Bonus"
         << setw(18) << "Nominal"
         << endl;

    cout << "====================================================================================================\n";

    for(int i=0;i<jumlah;i++)
    {
        cout << left
             << setw(12) << data[i].idKaryawan
             << setw(20) << data[i].nama
             << setw(15) << data[i].tanggal
             << setw(25) << data[i].jenisBonus
             << setw(18) << data[i].nominalBonus
             << endl;
    }
}

void cariBonus()
{
    string cari;
    bool ketemu=false;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout << "\nID            : " << data[i].idKaryawan << endl;
            cout << "Nama          : " << data[i].nama << endl;
            cout << "Tanggal       : " << data[i].tanggal << endl;
            cout << "Jenis Bonus   : " << data[i].jenisBonus << endl;
            cout << "Nominal Bonus : "
                 << data[i].nominalBonus << endl;

            ketemu=true;
            return;
        }
    }

    if(!ketemu)
        cout << "\nData Tidak Ditemukan.\n";
}

void editBonus()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout << "\n=====================================\n";
            cout << "        EDIT DATA BONUS\n";
            cout << "=====================================\n";

            cout << "ID Karyawan : " << data[i].idKaryawan << endl;
            cout << "Nama        : " << data[i].nama << endl;

            cout << "Tanggal Bonus Baru : ";
            getline(cin,data[i].tanggal);

            cout << "Jenis Bonus Baru : ";
            getline(cin,data[i].jenisBonus);

            cout << "Nominal Bonus Baru : ";
            cin >> data[i].nominalBonus;
            cin.ignore();

            simpanData();

            cout << "\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void hapusBonus()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            for(int j=i;j<jumlah-1;j++)
            {
                data[j]=data[j+1];
            }

            jumlah--;
            
            simpanData();

            cout << "\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void simpanData()
{
    ofstream file("dataBonus.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i = 0; i < jumlah; i++)
    {
        file
        << data[i].idKaryawan << "|"
        << data[i].nama << "|"
        << data[i].tanggal << "|"
        << data[i].jenisBonus << "|"
        << data[i].nominalBonus
        << endl;
    }

    file.close();
}

void loadData()
{
    ifstream file("dataBonus.txt");

    if(!file)
        return;

    jumlah = 0;

    while(getline(file, data[jumlah].idKaryawan, '|'))
    {
        getline(file, data[jumlah].nama, '|');
        getline(file, data[jumlah].tanggal, '|');
        getline(file, data[jumlah].jenisBonus, '|');

        file >> data[jumlah].nominalBonus;
        file.ignore();

        jumlah++;
    }

    file.close();
}

DataBonus* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}

};

class Payroll
{
public:

    struct Gaji
    {
        string idKaryawan;
        string nama;
        string jabatan;

        long long int gajiPokok;
        long long int uangLembur;
        long long int bonus;
        long long int potongan;
        long long int totalGaji;
    };

private:

    Gaji data[100];

    int jumlah;
    int pilihan;

    // Relasi ke class lain
    Employee *employee;
    Position *position;
    Shift *shift;
    Attendance *attendance;
    Overtime *overtime;
    Bonus *bonus;

public:

    Payroll(Employee &emp,
            Position &pos,
            Shift &shf,
            Attendance &att,
            Overtime &ovt,
            Bonus &bon)
    {
        employee   = &emp;
        position   = &pos;
        shift      = &shf;
        attendance = &att;
        overtime   = &ovt;
        bonus      = &bon;

        jumlah = 0;

        loadData();
    }
    
    void menuPayroll()
{
    cout << "\n";
    cout << "=========================================================\n";
    cout << "              PENGGAJIAN KARYAWAN\n";
    cout << "=========================================================\n";

    cout << "1. Hitung Gaji\n";
    cout << "2. Lihat Data Gaji\n";
    cout << "3. Cari Data Gaji\n";
    cout << "4. Edit Data Gaji\n";
    cout << "5. Hapus Data Gaji\n";
    cout << "0. Kembali\n";

    cout << "=========================================================\n";
    cout << "Masukkan Pilihan : ";
    cin >> pilihan;
}

int getPilihan()
{
    return pilihan;
}

void hitungGajiOtomatis()
{
    string idCari;

    cin.ignore();

    cout << "\n=============================================\n";
    cout << "          PENGGAJIAN OTOMATIS\n";
    cout << "=============================================\n";

    cout << "Masukkan ID Karyawan : ";
    getline(cin, idCari);

    Employee::Karyawan *karyawan = employee->getData();

    bool ketemu = false;

    //==========================
    // Cari Data Karyawan
    //==========================

    for(int i=0;i<employee->getJumlah();i++)
    {
        if(karyawan[i].id == idCari)
        {
            data[jumlah].idKaryawan = karyawan[i].id;
            data[jumlah].nama = karyawan[i].nama;
            data[jumlah].jabatan = karyawan[i].jabatan;

            ketemu = true;
            break;
        }
    }

    if(!ketemu)
    {
        cout << "\nID Karyawan Tidak Ditemukan.\n";
        return;
    }

    //==========================
    // Ambil Gaji Pokok dari Data Karyawan
    // (pakai gaji pokok yang sudah diisi & disimpan
    //  saat Tambah Data Karyawan, tidak input ulang)
    //==========================

    for(int i=0;i<employee->getJumlah();i++)
    {
        if(karyawan[i].id == idCari)
        {
            data[jumlah].gajiPokok = karyawan[i].gajiPokok;
            break;
        }
    }

    //==========================
    // Hitung Total Bonus
    //==========================

    data[jumlah].bonus = 0;

    Bonus::DataBonus *bon = bonus->getData();

    for(int i=0;i<bonus->getJumlah();i++)
    {
        if(bon[i].idKaryawan == idCari)
        {
            data[jumlah].bonus += bon[i].nominalBonus;
        }
    }

    //==========================
    // Hitung Total Lembur
    //==========================

    data[jumlah].uangLembur = 0;

    Overtime::Lembur *lem = overtime->getData();

    for(int i=0;i<overtime->getJumlah();i++)
    {
        if(lem[i].idKaryawan == idCari)
        {
            data[jumlah].uangLembur += lem[i].totalLembur;
        }
    }

    //==========================
    // Hitung Potongan Absensi
    //==========================

    data[jumlah].potongan = 0;

    Attendance::Absensi *abs = attendance->getData();

    for(int i=0;i<attendance->getJumlah();i++)
    {
        if(abs[i].idKaryawan == idCari)
        {
            if(abs[i].status == "Alpha")
                data[jumlah].potongan += 100000;

            else if(abs[i].status == "Izin")
                data[jumlah].potongan += 25000;
        }
    }

    //==========================
    // Hitung Total Gaji
    //==========================

    data[jumlah].totalGaji =
        data[jumlah].gajiPokok +
        data[jumlah].bonus +
        data[jumlah].uangLembur -
        data[jumlah].potongan;

    //==========================
    // Tampilkan
    //==========================

    cout << "\n=============================================\n";
    cout << "           HASIL PENGGAJIAN\n";
    cout << "=============================================\n";

    cout << "ID Karyawan : " << data[jumlah].idKaryawan << endl;
    cout << "Nama        : " << data[jumlah].nama << endl;
    cout << "Jabatan     : " << data[jumlah].jabatan << endl;

    cout << "---------------------------------------------\n";

    cout << "Gaji Pokok  : " << data[jumlah].gajiPokok << endl;
    cout << "Bonus       : " << data[jumlah].bonus << endl;
    cout << "Lembur      : " << data[jumlah].uangLembur << endl;
    cout << "Potongan    : " << data[jumlah].potongan << endl;

    cout << "---------------------------------------------\n";

    cout << "TOTAL GAJI  : " << data[jumlah].totalGaji << endl;

    cout << "=============================================\n";

    jumlah++;

    simpanData();

    cout << "\nPenggajian Berhasil Diproses.\n";
}
void lihatPayroll()
{
    if(jumlah==0)
    {
        cout << "\nBelum Ada Data Penggajian.\n";
        return;
    }

    cout << "\n=========================================================================================================\n";

    cout << left
         << setw(10) << "ID"
         << setw(20) << "Nama"
         << setw(18) << "Jabatan"
         << setw(18) << "Gaji Bersih"
         << endl;

    cout << "=========================================================================================================\n";

    for(int i=0;i<jumlah;i++)
    {
        cout << left
             << setw(10) << data[i].idKaryawan
             << setw(20) << data[i].nama
             << setw(18) << data[i].jabatan
             << setw(18) << data[i].totalGaji
             << endl;
    }
}

void cariPayroll()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout << "\nID           : " << data[i].idKaryawan << endl;
            cout << "Nama         : " << data[i].nama << endl;
            cout << "Jabatan      : " << data[i].jabatan << endl;
            cout << "Gaji Pokok   : " << data[i].gajiPokok << endl;
            cout << "Lembur       : " << data[i].uangLembur << endl;
            cout << "Bonus        : " << data[i].bonus << endl;
            cout << "Potongan     : " << data[i].potongan << endl;
            cout << "Total Gaji   : " << data[i].totalGaji << endl;

            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void editPayroll()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            cout << "Gaji Pokok Baru : ";
            cin >> data[i].gajiPokok;

            cout << "Lembur Baru : ";
            cin >> data[i].uangLembur;

            cout << "Bonus Baru : ";
            cin >> data[i].bonus;

            cout << "Potongan Baru : ";
            cin >> data[i].potongan;
            cin.ignore();

            data[i].totalGaji =
                data[i].gajiPokok +
                data[i].uangLembur +
                data[i].bonus -
                data[i].potongan;
                
            simpanData();    

            cout << "\nData Berhasil Diubah.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void hapusPayroll()
{
    string cari;

    cin.ignore();

    cout << "\nMasukkan ID Karyawan : ";
    getline(cin,cari);

    for(int i=0;i<jumlah;i++)
    {
        if(data[i].idKaryawan==cari)
        {
            for(int j=i;j<jumlah-1;j++)
            {
                data[j]=data[j+1];
            }

            jumlah--;
            
            simpanData();

            cout << "\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

void simpanData()
{
    ofstream file("dataPayroll.txt");

    if(!file)
    {
        cout << "File tidak dapat dibuat!\n";
        return;
    }

    for(int i=0; i<jumlah; i++)
    {
        file
        << data[i].idKaryawan << "|"
        << data[i].nama << "|"
        << data[i].jabatan << "|"
        << data[i].gajiPokok << "|"
        << data[i].uangLembur << "|"
        << data[i].bonus << "|"
        << data[i].potongan << "|"
        << data[i].totalGaji
        << endl;
    }

    file.close();
}

void loadData()
{
    ifstream file("dataPayroll.txt");

    if(!file)
        return;

    jumlah = 0;

    while(getline(file, data[jumlah].idKaryawan, '|'))
    {
        getline(file, data[jumlah].nama, '|');
        getline(file, data[jumlah].jabatan, '|');

        file >> data[jumlah].gajiPokok;
        file.ignore();

        file >> data[jumlah].uangLembur;
        file.ignore();

        file >> data[jumlah].bonus;
        file.ignore();

        file >> data[jumlah].potongan;
        file.ignore();

        file >> data[jumlah].totalGaji;
        file.ignore();

        jumlah++;
    }

    file.close();
}

Gaji* getData()
{
    return data;
}

int getJumlah()
{
    return jumlah;
}

};

class SlipGaji
{
private:

    Payroll *payroll;

public:

    SlipGaji(Payroll *p)
    {
        payroll = p;
    }

    void cetakSlip()
    {
        string id;
        bool ketemu = false;

        cout << "\n=============================================\n";
        cout << "              CETAK SLIP GAJI\n";
        cout << "=============================================\n";

        cout << "Masukkan ID Karyawan : ";
        cin >> id;

        Payroll::Gaji *data = payroll->getData();
        int jumlah = payroll->getJumlah();

        for(int i=0;i<jumlah;i++)
        {
            if(data[i].idKaryawan == id)
            {
                cout << "\n=============================================\n";
                cout << "           SLIP GAJI KARYAWAN\n";
                cout << "=============================================\n";

                cout << "ID          : " << data[i].idKaryawan << endl;
                cout << "Nama        : " << data[i].nama << endl;
                cout << "Jabatan     : " << data[i].jabatan << endl;
                cout << "Gaji Pokok  : Rp " << fixed << setprecision(0) << data[i].gajiPokok << endl;
                cout << "Bonus       : Rp " << data[i].bonus << endl;
                cout << "Lembur      : Rp " << data[i].uangLembur << endl;
                cout << "Potongan    : Rp " << data[i].potongan << endl;

                cout << "---------------------------------------------\n";

                cout << "TOTAL GAJI  : Rp " << data[i].totalGaji << endl;

                cout << "=============================================\n";

                ketemu = true;
                break;
            }
        }

        if(!ketemu)
        {
            cout << "\nData Tidak Ditemukan.\n";
        }
    }
};
    
    
class LaporanGaji
{
private:
    Payroll *payroll;

public:

    LaporanGaji(Payroll *p)
    {
        payroll = p;
    }

    void tampilLaporan()
    {
        Payroll::Gaji *data = payroll->getData();
        int jumlah = payroll->getJumlah();

        if(jumlah == 0)
        {
            cout << "\nBelum Ada Data Penggajian.\n";
            return;
        }

        double total = 0;
        double tertinggi = data[0].totalGaji;
        double terendah = data[0].totalGaji;

        cout << "\n===============================================================\n";
        cout << "                  LAPORAN GAJI KARYAWAN\n";
        cout << "===============================================================\n";

        cout << left
             << setw(10) << "ID"
             << setw(20) << "Nama"
             << setw(20) << "Jabatan"
             << setw(15) << "Total Gaji"
             << endl;

        cout << "===============================================================\n";

        for(int i=0;i<jumlah;i++)
        {
            cout << left
                 << setw(10) << data[i].idKaryawan
                 << setw(20) << data[i].nama
                 << setw(20) << data[i].jabatan
                 << setw(15) << fixed << setprecision(0)
                 << data[i].totalGaji
                 << endl;

            total += data[i].totalGaji;

            if(data[i].totalGaji > tertinggi)
                tertinggi = data[i].totalGaji;

            if(data[i].totalGaji < terendah)
                terendah = data[i].totalGaji;
        }

        cout << "\nJumlah Karyawan : " << jumlah << endl;
        cout << "Total Gaji      : Rp " << total << endl;
        cout << "Rata-rata Gaji  : Rp " << total/jumlah << endl;
        cout << "Gaji Tertinggi  : Rp " << tertinggi << endl;
        cout << "Gaji Terendah   : Rp " << terendah << endl;
    }
    
};

class Statistik
{
private:
    Employee *employee;
    Position *position;
    Shift *shift;
    Attendance *attendance;
    Overtime *overtime;
    Bonus *bonus;
    Payroll *payroll;

public:

    Statistik(Employee &emp,
              Position &pos,
              Shift &shf,
              Attendance &att,
              Overtime &ovt,
              Bonus &bon,
              Payroll &pay)
    {
        employee = &emp;
        position = &pos;
        shift = &shf;
        attendance = &att;
        overtime = &ovt;
        bonus = &bon;
        payroll = &pay;
    }

    void tampilStatistik()
{
    system("cls");

    Employee::Karyawan *karyawan = employee->getData();
    Payroll::Gaji *gaji = payroll->getData();

    int manager = 0;
    int supervisor = 0;
    int crew = 0;

    int pagi = 0;
    int siang = 0;
    int malam = 0;

    double totalPengeluaran = 0;

    double gajiTertinggi = 0;
    double gajiTerendah = 999999999;

    string namaTertinggi = "-";
    string namaTerendah = "-";

    //=========================
    // Data Karyawan
    //=========================

    for(int i=0;i<employee->getJumlah();i++)
    {
        if(karyawan[i].jabatan=="Manager")
            manager++;

        else if(karyawan[i].jabatan=="Supervisor")
            supervisor++;

        else
            crew++;

        if(karyawan[i].shift=="Pagi")
            pagi++;

        else if(karyawan[i].shift=="Siang")
            siang++;

        else if(karyawan[i].shift=="Malam")
            malam++;
    }

    //=========================
    // Data Payroll
    //=========================

    for(int i=0;i<payroll->getJumlah();i++)
    {
        totalPengeluaran += gaji[i].totalGaji;

        if(gaji[i].totalGaji > gajiTertinggi)
        {
            gajiTertinggi = gaji[i].totalGaji;
            namaTertinggi = gaji[i].nama;
        }

        if(gaji[i].totalGaji < gajiTerendah)
        {
            gajiTerendah = gaji[i].totalGaji;
            namaTerendah = gaji[i].nama;
        }
    }

    double rata = 0;

    if(payroll->getJumlah()!=0)
        rata = totalPengeluaran/payroll->getJumlah();

    cout<<"\n";
    cout<<"==============================================\n";
    cout<<"            STATISTIK RESTORAN\n";
    cout<<"==============================================\n\n";

    cout<<left<<setw(28)<<"Jumlah Karyawan"<<": "<<employee->getJumlah()<<" Orang\n";
    cout<<left<<setw(28)<<"Jumlah Manager"<<": "<<manager<<" Orang\n";
    cout<<left<<setw(28)<<"Jumlah Supervisor"<<": "<<supervisor<<" Orang\n";
    cout<<left<<setw(28)<<"Jumlah Crew"<<": "<<crew<<" Orang\n\n";

    cout<<left<<setw(28)<<"Shift Pagi"<<": "<<pagi<<" Orang\n";
    cout<<left<<setw(28)<<"Shift Siang"<<": "<<siang<<" Orang\n";
    cout<<left<<setw(28)<<"Shift Malam"<<": "<<malam<<" Orang\n\n";

    cout<<left<<setw(28)<<"Total Pengeluaran Gaji"<<": "<<formatRupiah(totalPengeluaran)<<endl;

    cout<<left<<setw(28)<<"Rata-rata Gaji"<<": "<<formatRupiah(rata)<<endl;

    cout<<"\n";
    cout<<"Karyawan Gaji Tertinggi\n";
    cout<<"Nama : "<<namaTertinggi<<endl;
    cout<<formatRupiah(gajiTertinggi)<<endl;

    cout<<"\n";
    cout<<"Karyawan Gaji Terendah\n";
    cout<<"Nama : "<<namaTerendah<<endl;
    cout<<formatRupiah(gajiTerendah)<<endl;

    cout<<"==============================================\n";
}
    
};



int main()
{
    Welcome menu;
    Login login;
    Dashboard dashboard;

    Employee employee;
    Position position;
    Shift shift;
    
    Attendance attendance(employee);
    Overtime overtime(employee);
    Bonus bonus(employee);

    // Payroll sekarang menerima semua class
    Payroll payroll(employee, position, shift, 
	attendance, overtime, bonus);
    
    SlipGaji slip(&payroll);
    
    LaporanGaji laporan(&payroll);
    
    Statistik statistik(employee,
                    position,
                    shift,
                    attendance,
                    overtime,
                    bonus,
                    payroll);
    
   

    menu.tampilAwal();

    if(login.loginAdmin())
    {
        int pilihDashboard;

        do
        {
            system("cls");

            dashboard.menuAdmin();
            pilihDashboard = dashboard.getPilihan();

            switch(pilihDashboard)
            {

            //====================================================
            // DATA KARYAWAN
            //====================================================
            case 1:
            {
                int pilih;

                do
                {
                    system("cls");

                    employee.menuEmployee();
                    pilih = employee.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        employee.tambahKaryawan();
                        break;

                    case 2:
                        employee.lihatKaryawan();
                        break;

                    case 3:
                        employee.cariKaryawan();
                        break;

                    case 4:
                        employee.editKaryawan();
                        break;

                    case 5:
                        employee.hapusKaryawan();
                        break;

                    case 0:
                        break;

                    default:
                        cout<<"\nPilihan Tidak Tersedia!\n";
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // DATA JABATAN
            //====================================================
            case 2:
            {
                int pilih;

                do
                {
                    system("cls");

                    position.menuPosition();
                    pilih = position.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        position.tambahJabatan();
                        break;

                    case 2:
                        position.lihatJabatan();
                        break;

                    case 3:
                        position.cariJabatan();
                        break;

                    case 4:
                        position.editJabatan();
                        break;

                    case 5:
                        position.hapusJabatan();
                        break;

                    case 0:
                        break;

                    default:
                        cout<<"\nPilihan Tidak Tersedia!\n";
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // DATA SHIFT
            //====================================================
            case 3:
            {
                int pilih;

                do
                {
                    system("cls");

                    shift.menuShift();
                    pilih = shift.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        shift.tambahShift();
                        break;

                    case 2:
                        shift.lihatShift();
                        break;

                    case 3:
                        shift.cariShift();
                        break;

                    case 4:
                        shift.editShift();
                        break;

                    case 5:
                        shift.hapusShift();
                        break;

                    case 0:
                        break;

                    default:
                        cout<<"\nPilihan Tidak Tersedia!\n";
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // DATA ABSENSI
            //====================================================
            case 4:
            {
                int pilih;

                do
                {
                    system("cls");

                    attendance.menuAttendance();
                    pilih = attendance.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        attendance.tambahAbsensi();
                        break;

                    case 2:
                        attendance.lihatAbsensi();
                        break;

                    case 3:
                        attendance.cariAbsensi();
                        break;

                    case 4:
                        attendance.editAbsensi();
                        break;

                    case 5:
                        attendance.hapusAbsensi();
                        break;

                    case 0:
                        break;

                    default:
                        cout<<"\nPilihan Tidak Tersedia!\n";
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // DATA LEMBUR
            //====================================================
            case 5:
            {
                int pilih;

                do
                {
                    system("cls");

                    overtime.menuOvertime();
                    pilih = overtime.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        overtime.tambahLembur();
                        break;

                    case 2:
                        overtime.lihatLembur();
                        break;

                    case 3:
                        overtime.cariLembur();
                        break;

                    case 4:
                        overtime.editLembur();
                        break;

                    case 5:
                        overtime.hapusLembur();
                        break;

                    case 6:
                        overtime.hapusSemuaLembur();
                        break;

                    case 0:
                        break;

                    default:
                        cout<<"\nPilihan Tidak Tersedia!\n";
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // DATA BONUS
            //====================================================
            case 6:
            {
                int pilih;

                do
                {
                    system("cls");

                    bonus.menuBonus();
                    pilih = bonus.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        bonus.tambahBonus();
                        break;

                    case 2:
                        bonus.lihatBonus();
                        break;

                    case 3:
                        bonus.cariBonus();
                        break;

                    case 4:
                        bonus.editBonus();
                        break;

                    case 5:
                        bonus.hapusBonus();
                        break;

                    case 0:
                        break;
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // PAYROLL
            //====================================================
            case 7:
            {
                int pilih;

                do
                {
                    system("cls");

                    payroll.menuPayroll();
                    pilih = payroll.getPilihan();

                    switch(pilih)
                    {
                    case 1:
                        payroll.hitungGajiOtomatis();
                        break;

                    case 2:
                        payroll.lihatPayroll();
                        break;

                    case 3:
                        payroll.cariPayroll();
                        break;

                    case 4:
                        payroll.editPayroll();
                        break;

                    case 5:
                        payroll.hapusPayroll();
                        break;

                    case 0:
                        break;
                    }

                    if(pilih!=0)
                    {
                        cout<<"\nTekan ENTER...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilih!=0);

                break;
            }

            //====================================================
            // SLIP GAJI
            //====================================================
            case 8:
            {
            	
                system("cls");


    			slip.cetakSlip();

    			cout << "\nTekan ENTER...";
    			cin.ignore();
    			cin.get();
    			break;
    			
    		}

            //====================================================
            // LAPORAN
            //====================================================
            case 9:
            {	
                
    			laporan.tampilLaporan();

    			cout << "\nTekan ENTER...";
    			cin.ignore();
    			cin.get();
    			break;
    		}
    		//====================================================
            // STATISTIK
            //====================================================	
            case 10:
            {	
            	
           		system("cls");

 		    	statistik.tampilStatistik();

    			cout << "\nTekan ENTER...";
    			cin.ignore();
    			cin.get();
    			break;	
        	}

            case 0:
            	
            	
                cout<<"\n=============================================\n";
                cout<<" Terima Kasih Telah Menggunakan Sistem\n";
                cout<<" Marugame Udon Japanese Noodles & Tempura\n";
                cout<<"=============================================\n";
                break;

            default:
            	
            	
            	
                cout<<"\nPilihan Tidak Tersedia!\n";
                cin.ignore();
                cin.get();
            }

        }while(pilihDashboard!=0);
    }
    else
    {
        cout<<"\nLogin Gagal!\n";
    }

    return 0;
    
}
