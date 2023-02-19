#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int tanya1()
{
    int baris;
    cout << "Di baris mana kapal tersebut? : ";
    cin >> baris;
    baris = baris - 1;
    return baris;
}

int tanya2()
{
    int kolom;
    cout << "Di kolom mana kapal tersebut? : ";
    cin >> kolom;
    kolom = kolom - 1;
    return kolom;
}

void jawaban(int lokasi[][4])
{
    for (int w = 0; w < 4; w++)
    {
        for (int v = 0; v < 4; v++)
        {
            cout << lokasi[w][v] << "\t";
        }
        cout << endl
             << endl;
    }
}

void pengarah(int hor, int ver)
{
    COORD coord;
    coord.X = hor;
    coord.Y = ver;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void waktu()
{
    int waktu = 1;
    while (waktu < 35000000)
    {
        waktu++;
    }
}

string opening()
{
    pengarah(5, 0);
    cout << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << endl
         << "\t\t  000000    000300    000000    001000    00        000000          000000    00    oo    00    000000    000000      " << endl
         << "\t\t  00  00    00  00      00        00      00        00              00        00    00    00    00  00    00          " << endl
         << "\t\t  000000    000000      00        00      00        000000          000000    00000000    00    000000    000000      " << endl
         << "\t\t  00  00    00  00      00        00      00        00                  00    00    00    00    00            00      " << endl
         << "\t\t  000000    00  00      00        00      000000    000000          000000    00    00    00    00        000000      ";
    cout << endl
         << endl
         << endl
         << "\t\t                                            0000080000090000000000" << endl
         << "\t\t                                            000                000" << endl
         << "\t\t                                            000    00006000    000" << endl
         << "\t\t                                            000    00000000    000" << endl
         << "\t\t                                            000    00000000    000" << endl
         << "\t\t                                            000    00000000    000" << endl
         << "\t\t                                            000                000" << endl
         << "\t\t                                            0000000000000000000000"
         << endl
         << endl
         << endl;
    string on;
    cout <<"\t\t\t\t\t\t\t\t mulai? (y/n) ";
    cin >> on;
    cout << endl
         << endl
         << endl;
    return on;
}

void peta()
{
    char tanda = 'X';
    int i, x;
    cout << endl
         << endl;
    for (i = 0; i <= 3; i++)
    {
        for (x = 0; x <= 3; x++)
        {
            cout << tanda << "\t";
        }
        cout << endl
             << endl;
    }
}

void rule()
{
    string lanjut;
    cout << "=================================================================================================" << endl
         << endl
         << "\tSELAMAT DATANG DI SIMPLE BATTLESHIPS"
         << endl
         << endl
         << "\tDi game ini, kamu cukup menebak di baris mana dan kolom mana kapal musuh berada.\n\tKamu akan diberikan 3 nyawa.\n\n\tJika kamu berhasil menebak 2 kali berturut - turut, kamu akan mendapatkan bonus 1 nyawa.\n\tJika kamu berhasil menebak 3 kali berturut - turut, kapal musuh akan berkurang 1 kapal."
         << endl
         << endl
         << endl
         << "\tPOSISIMU SAAT INI : KAPTEN"
         << endl
         << endl
         << "\t@Hadid_Ganteng_dev"
         << endl
         << endl;
    cout << "=================================================================================================" << endl
         << "\tKetik huruf apapun untuk melanjutkan  ";
    cin >> lanjut;
    system("cls");
}

int main()
{
    string pilihan/*ke menu*/, pil2/*melanjutkan kesempatan berikutnya*/;
    int o = 0, bonus = 0 /*combo 2x*/, bonus2 = 0 /*variabel combo 3x atau buat ngasih tau lokasi kapal 1 kali*/;
    for (int q = 1; q <= 100; q++)
    {
        pengarah(5, 2);
        cout << "L  O  A  D  I  N  G    " << q << " %";
        waktu();
    }
    system("cls");

    do
    {
        system("cls");
        //opening
        pilihan = opening();
        //jika mulai
        // program randomisasi lokasi kapal
        if (pilihan == "y")
        {
            system("cls");
            rule();
            int acak, acak1, acak2, batas = 0, kesempatan = 3;
            srand(time(0));
            acak = rand() % 2;
            acak1 = rand() % 2;
            acak2 = rand() % 2;
            int kapal[4][4] = {
                {0, acak1, acak, 0},
                {acak, 1, acak2, 1},
                {acak1, 0, acak, 0},
                {0, acak2, 1, acak1}};
            for (int a = 0; a < 4; a++)
            {
                for (int b = 0; b < 4; b++)
                {
                    if (kapal[a][b] == 1)
                        batas++;
                }
            }

            //sistem pendeteksi kapal
            cout << "=================================================================================================" << endl
                 << endl
                 << "Sistem mendeteksi ada " << batas << " kapal musuh. Hanya ada " << kesempatan << " nyawa. Temukan dan hancurkan mereka semua, Kapten!" << endl
                 << endl;
            int kena = 0, jmlh = batas;
            peta();
            cout << endl
                 << "==================================================================================================" << endl;

            //program permainan dimulai
            do
            {
                pengarah(40, 6);
                int horizontal = tanya1();
                pengarah(40, 7);
                int vertikal = tanya2();

                //saat kena sasaran
                if (kapal[horizontal][vertikal] == 1)
                {
                    system("cls");
                    kapal[horizontal][vertikal] = 0;
                    cout << "============================================ STRIKE! ============================================"
                         << endl
                         << endl
                         << "Tepat sasaran. Kini kapal yang tersisa yaitu " << (jmlh -= 1) << " kapal" << endl
                         << endl;
                    int down = 16;
                    bonus++;

                    //buat lokasi kapal yang tertebak
                    int k, l, pen1 = horizontal, pen2 = vertikal;
                    for (k = 0; k <= 3; k++)
                    {
                        for (l = 0; l <= 3; l++)
                        {
                            if (k == pen1 && l == pen2)
                            {
                                cout << "O\t";
                            }
                            else
                            {
                                cout << "X\t";
                            }
                        }
                        cout << endl;
                        cout << endl;
                    }
                    kena++;
                    cout << endl
                         << endl
                         << "Sisa nyawa mu " << kesempatan << endl
                         << endl
                         << "Ketik huruf apapun untuk melanjutkan  "
                         << endl
                         << endl
                         << "==================================================================================================";
                    pengarah(38, down);
                    cin >> pil2;

                    // Sistem Bonus
                    //combo 2x
                    if (bonus == 2)
                    {
                        system("cls");
                        kesempatan++;
                        down += 2;
                        cout << "============================================== BONUS ============================================="
                             << endl
                             << endl
                             << "\tCOMBO 2x! Anda mendapat tambahan 1 nyawa" << endl
                             << endl
                             << "\tNyawamu sekarang: " << kesempatan << endl
                             << endl
                             << endl
                             << "=================================================================================================="
                             << endl
                             << "\tKetik huruf apapun untuk melanjutkan  ";
                        cin >> pil2;
                    }

                    //combo 3x
                    else if (bonus == 3)
                    {
                        system("cls");
                        cout << "============================================== BONUS ============================================="
                             << endl
                             << endl
                             << "COMBO 3x! Bonus 1 tembakan langsung ke lokasi musuh" << endl
                             << endl;
                        jmlh--;

                        //buat petak bonus kapal yang tertebak sistem
                        for (int g = 0; g <= 3; g++)
                        {
                            for (int h = 0; h <= 3; h++)
                            {
                                if (kapal[g][h] == 1)
                                {
                                    bonus2++;
                                    if (bonus2 == 1)
                                    {
                                        cout << "O\t";
                                        kapal[g][h] = 0;
                                    }
                                    else
                                    {
                                        cout << "X\t";
                                    }
                                }
                                else
                                {
                                    cout << "X\t";
                                }
                            }
                            cout << endl;
                            cout << endl;
                        }

                        cout << endl
                             << endl
                             << "Kapal Musuh berkurang, Sisa kapal musuh :  " << jmlh
                             << endl
                             << endl
                             << "=================================================================================================="
                             << endl
                             << "\tKetik huruf apapun untuk melanjutkan  ";
                        cin >> pil2;
                    }
                }

                //saat pemain gagal menebak dengan benar
                else
                {
                    pengarah(0, 15);
                    kesempatan--;
                    if (bonus != 0)
                    {
                        bonus = 0;
                    }

                    cout << endl
                         << "Tembakanmu meleset! Sisa nyawamu adalah " << kesempatan << endl
                         << "Coba tebak lagi. Cemungut ea!" << endl
                         << endl
                         << "Ketik huruf apapun untuk melanjutkan  ";
                    cin >> pil2;
                }
                system("cls");
                if (kesempatan > 0 && kena == batas)
                    break;
                cout << "===================================== Kesempatan Berikutnya =====================================" << endl
                     << endl
                     << "Sisa Kapal =  " << jmlh << "                   Nyawa =  " << kesempatan
                     << endl;
                peta();
                cout << endl
                     << "=================================================================================================" << endl;
            } while (kesempatan > 0 && kena < batas);

            //game over
            if (kesempatan == 0 && kena < batas)
            {
                system("cls");
                cout << "================================================================================================="
                     << endl
                     << endl
                     << "GAME OVER!" << endl
                     << "Kapten BODOH, kamu turun pangkat jadi prajurit biasa!" << endl
                     << endl
                     << endl
                     << "PANGKAT MU SAAT INI : AWAK KAPAL" << endl
                     << endl
                     << endl
                     << "Lokasi musuh yang masih tersembunyi (tanda: angka 1)"
                     << endl
                     << endl;
                //program petak yang belum ditebak
                jawaban(kapal);
                cout << endl
                     << endl
                     << "=================================================================================================" << endl;
            }

            //program win
            else if (kesempatan > 0 && kena == batas)
            {
                system("cls");
                cout << "================================================================================================="
                     << endl
                     << endl
                     << endl
                     << "GOOD JOB Kapten! Negara berhutang budi padamu." << endl
                     << endl
                     << endl
                     << endl
                     << "PANGKAT MU SAAT INI : LAKSAMANA"
                     << endl
                     << endl
                     << "=================================================================================================" << endl;
            }
            //ke tampilan awal utama
            cout << "Ketik y untuk kembali ke menu utama ";
            cin >> pilihan;
        }

        //jika pilihan quit
        else
        {
            system("cls");
            cout << endl
                 << endl
                 << "\t\t\t\t\t\t\t    Apa kamu yakin keluar? (i/t) ";
            cin >> pilihan;
            if (pilihan == "i")
            {
                break;
            }
            else if (pilihan == "t")
            {
                o++;
            }
        }
    } while (pilihan == "y" || pilihan == "t");
}