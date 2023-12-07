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
    do
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
        