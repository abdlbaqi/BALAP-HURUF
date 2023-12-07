#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

char map[20][20];
char player = ' ';  
char player2 = ' ';

int x = 18;
int y = 2;

int x2 = 18;
int y2 = 5;

int finish = 0; 

char walk; // untuk kontrol pemain 1 dan 2

void pilihPlayers() // fungsi pilih player sebelum mulai game 
{
    cout << "Player 1, Pilih satu huruf Jagoanmu: ";
    cin >> player;

    cout << "Player 2, Pilih satu huruf Jagoanmu: ";
    cin >> player2;
}

void buatMap() // fungsi map terminal
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            map[i][j] = ' ';
        }
    }
    map[x][y] = player;    // map player 1
    map[x2][y2] = player2; // map player 2
}

void printMap()    // fungsi untuk memunculkan map
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c", map[i][j]);
        }
        cout << endl;
    }
}

int main() 
{
         pilihPlayers(); // memanggil fungsi pilih players

        do
        {
            system("cls"); //untuk membersihkan layar program

            buatMap(); // memanggil fungsi buat map
            printMap(); // memanggil fungsi printMap
            walk = getch();

            switch (walk) // karena ada 2 player jadi kita pakai switch case
            {
            case 'q': // case pertama jika nilai "walk" adalah karakter ('q') maka kode didalam case akan dijalankan
                if (map[x - 1][y] == ' ') 
                {
                    x--;
                    map[x + 1][y] = ' ';
                    map[x][y] = player;
                }
                break;

            case 'p': // case pertama jika nilai "walk" adalah karakter ('p') maka kode didalam case akan dijalankan
                if (map[x2 - 1][y2] == ' ') 
                {
                    x2--;
                    map[x2 + 1][y2] = ' ';
                    map[x2][y2] = player2;
                }
                break;
            }

            if (x == finish) //kondisi jika player 1 menang duluan
            {
                cout << "Player 1 (" << player << ") menang duluan" << endl;
                break;
            }
            else if (x2 == finish) //kondisi jika player 2 menang duluan
            {
                cout << "Player 2 (" << player2 << ") menang duluan" << endl;
                break;
            }

        } while (true); 

        do
        {
        cout << "Lanjut main? (y/t): ";
        cin >> walk;

       //untuk mengulang game dari awal karna jika tidak ditambahkan maka akan tetap mengulang tapi tidak dari awal
        if (walk == 'y') {
            x = 18;
            y = 2;
            x2 = 18;
            y2 = 5;
        }

    } while (walk == 'y');

    getchar();
}


/*
fuad abdul baqi
puspita sari jannati
shandy raditya dewangga
*/