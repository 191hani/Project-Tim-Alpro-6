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

int main()
{
    Welcome menu;

    menu.tampilAwal();

    return 0;
}
