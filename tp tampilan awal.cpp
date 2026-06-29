#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

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
private:

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
        double gajiPokok;
    };

    Karyawan data[100];
    int jumlah;
    int pilihan;

public:
	
	Employee () 
	{
		jumlah = 0;	
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

    for(int i = 0; i < n; i++)
    {
        cout << "\n==============================\n";
        cout << "Data Karyawan Ke-" << i+1 << endl;
        cout << "==============================\n";

        cout << "ID Karyawan : ";
        getline(cin, data[jumlah].id);

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

            cout << "\nData Berhasil Dihapus.\n";
            return;
        }
    }

    cout << "\nData Tidak Ditemukan.\n";
}

};

class Position
{
private:

    struct Jabatan
    {
        string kode;
        string namaJabatan;
        double gajiPokok;
        double tunjangan;
    };

    Jabatan data[100];
    int jumlah;
    int pilihan;

public:

    Position()
    {
        jumlah = 0;
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

            cout << "Kode Jabatan : ";
            getline(cin,data[jumlah].kode);

            cout << "Nama Jabatan : ";
            getline(cin,data[jumlah].namaJabatan);

            cout << "Gaji Pokok : ";
            cin >> data[jumlah].gajiPokok;

            cout << "Tunjangan : ";
            cin >> data[jumlah].tunjangan;
            cin.ignore();

            jumlah++;
        }

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
        getline(cin,cari);

        for(int i=0;i<jumlah;i++)
        {
            if(data[i].kode==cari)
            {
                cout << "Nama Jabatan Baru : ";
                getline(cin,data[i].namaJabatan);

                cout << "Gaji Pokok Baru : ";
                cin >> data[i].gajiPokok;

                cout << "Tunjangan Baru : ";
                cin >> data[i].tunjangan;

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

                cout << "\nData Berhasil Dihapus.\n";
                return;
            }
        }

        cout << "\nData Tidak Ditemukan.\n";
    }
};

int main()
{
    Welcome menu;
    Login login;
    Dashboard dashboard;
    Employee employee;
    Position position;

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

            //=================================================
            // DATA KARYAWAN
            //=================================================
            case 1:
            {
                int pilihEmployee;

                do
                {
                    system("cls");

                    employee.menuEmployee();
                    pilihEmployee = employee.getPilihan();

                    switch(pilihEmployee)
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
                        cout << "\nKembali ke Dashboard...\n";
                        break;

                    default:
                        cout << "\nPilihan tidak tersedia!\n";
                    }

                    if(pilihEmployee != 0)
                    {
                        cout << "\n\nTekan ENTER untuk kembali...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilihEmployee != 0);

                break;
            }

            //=================================================
            // DATA JABATAN
            //=================================================
            case 2:
            {
                int pilihPosition;

                do
                {
                    system("cls");

                    position.menuPosition();
                    pilihPosition = position.getPilihan();

                    switch(pilihPosition)
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
                        cout << "\nKembali ke Dashboard...\n";
                        break;

                    default:
                        cout << "\nPilihan tidak tersedia!\n";
                    }

                    if(pilihPosition != 0)
                    {
                        cout << "\n\nTekan ENTER untuk kembali...";
                        cin.ignore();
                        cin.get();
                    }

                }while(pilihPosition != 0);

                break;
            }

            //=================================================
            // MENU YANG BELUM DIBUAT
            //=================================================
            case 3:
                cout << "\nMenu Data Shift masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 4:
                cout << "\nMenu Data Absensi masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 5:
                cout << "\nMenu Data Lembur masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 6:
                cout << "\nMenu Data Bonus masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 7:
                cout << "\nMenu Penggajian masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 8:
                cout << "\nMenu Slip Gaji masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 9:
                cout << "\nMenu Laporan Bulanan masih dalam pengembangan.\n";
                cin.ignore();
                cin.get();
                break;

            case 0:
                cout << "\n==============================================\n";
                cout << " Terima Kasih Telah Menggunakan Sistem\n";
                cout << " Marugame Udon Restaurant Management System\n";
                cout << "==============================================\n";
                break;

            default:
                cout << "\nPilihan tidak tersedia!\n";
                cin.ignore();
                cin.get();
            }

        }while(pilihDashboard != 0);
    }
    else
    {
        cout << "\nLogin gagal!\n";
    }

    return 0;
}
