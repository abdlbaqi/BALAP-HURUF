#include <stdio.h> // untuk inputan outputan
#include <windows.h>
#include <conio.h>
#include <iostream>

using namespace std; //supaya tidak perlu menambahkan std:: contoh std :: cout menjadi hanya cout

//deklarasi variable & array

char map[20][20]; //array 2dimensi
char player = ' ';  // char player kosong karna kita ingin input dari keyboard
char player2 = ' '; // char player kosong karna kita ingin input dari keyboard

int x = 18; 
int y = 2;

int x2 = 18;
int y2 = 5;

int finish = 0; 
char walk; // untuk kontrol pemain 1 dan 2, stdio.h kepake disini

//fungsi

void pilihPlayers() // fungsi ini untuk meminta inputan huruf untuk memilih jagoan masing2
{
    cout << "Player 1, Pilih satu huruf Jagoanmu: ";
    cin >> player;

    cout << "Player 2, Pilih satu huruf Jagoanmu: ";
      cin >> player2;
}

void buatMap() // array 2d
{
    for (int i = 0; i < 20; i++) //array 2d
    {
        for (int j = 0; j < 20; j++) //array2d
        {
            map[i][j] = ' '; 
        }
    }
    map[x][y] = player;    // map player 1
    map[x2][y2] = player2; // map player 2
}

void printMap()    // fungsi mencetak map ke layar
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            printf("%c", map[i][j]); //print array 2dimensi [20][20]
        }
        cout << endl;
    }
}

//fungsi main

int main() 
{
    
        pilihPlayers();  // memanggil fungsi pilih players
        do
        {
            system("cls");		 //untuk membersihkan layar program (menggunakan windows.h)

            buatMap();	 		// memanggil fungsi buat map
            printMap(); 		// memanggil fungsi printMap
            walk = getch();

            switch (walk) // karena ada 2 player jadi kita pakai switch case
            {
            case 'q': // case pertama jika nilai "walk" adalah karakter ('q') maka kode didalam case akan dijalankan
                if (map[x - 1][y] == ' ') 
                {
                    x--; // 
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
                cout << "Player 1 (" << player << ") menang duluan NT buat player 2" << endl;
                break;
            }
            else if (x2 == finish) //kondisi jika player 2 menang duluan
            {
                cout << "Player 2 (" << player2 << ") menang duluan NT buat player 1" << endl;
                break;
            }

        } while (true); 
        
		do
   		{
        cout << "Lanjut main? (y/t): ";
        cin >> walk;

        } while (walk == 'y');

        
        //untuk mengulang game dari awal karna jika tidak ditambahkan maka akan tetap mengulang tapi tidak dari awal
        if (walk == 'y') {
            x = 18;
            y = 2;
            x2 = 18;
            y2 = 5;
        }
        getchar();
}
