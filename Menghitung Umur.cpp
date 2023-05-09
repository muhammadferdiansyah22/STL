#include <iostream>
#include <ctime>

using namespace std;

class Umur {
    private:
        int tanggalLahir;
        int bulanLahir;
        int tahunLahir;

    public:
        Umur(int tanggal, int bulan, int tahun) {
            tanggalLahir = tanggal;
            bulanLahir = bulan;
            tahunLahir = tahun;
        }

        
        void setTanggalLahir(int tanggal) {
            tanggalLahir = tanggal;
        }

        int getTanggalLahir() {
            return tanggalLahir;
        }

        void setBulanLahir(int bulan) {
            bulanLahir = bulan;
        }

        int getBulanLahir() {
            return bulanLahir;
        }

        void setTahunLahir(int tahun) {
            tahunLahir = tahun;
        }

        int getTahunLahir() {
            return tahunLahir;
        }

        
        void hitungUmur() {
            time_t t = time(NULL);
            tm* timePtr = localtime(&t);
            int hariIni = timePtr->tm_mday ;
            int bulanIni = timePtr->tm_mon + 1;
            int tahunIni = timePtr->tm_year + 1900;

            int tahun = tahunIni - tahunLahir;
            int bulan = bulanIni - bulanLahir;
            int hari = hariIni - tanggalLahir;

            if (bulan < 0) {
                tahun--;
                bulan += 12;
            }

            if (hari < 0) {
                bulan--;
                hari += hitungJumlahHariBulan (bulanIni , tahunIni);
            }

            cout << "Umur Anda adalah " << tahun << " tahun " << bulan << " bulan " << hari << " hari." << endl;
        }

       
        int hitungJumlahHariBulan (int bulan, int tahun) {
            if (bulan == 2) {
                if (tahun % 4 == 0 && (tahun % 100 != 0 || tahun % 400 == 0)) {
                    return 29;
                } else {
                    return 28;
                }
            } else if (bulan == 4 || bulan == 6 || bulan == 9 || bulan == 11) {
                return 30;
            } else {
                return 31;
            }
        }

       
        bool isTahunKabisat(int tahun) {
            if (tahun % 4 == 0 && (tahun % 100 != 0 || tahun % 400 == 0)) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    int tanggal, bulan, tahun;

    cout << "Masukkan tanggal, bulan, dan tahun lahir anda ";
    cin >> tanggal >> bulan >> tahun;

    Umur umur(tanggal, bulan, tahun);
    umur.hitungUmur();

    return 0;
}
