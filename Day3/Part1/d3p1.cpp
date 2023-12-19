#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("d3p1src.txt");

    const unsigned short ROWS = 10;
    unsigned short COLUMNS;
    string line;
    while (fin>>line)
    {
        COLUMNS++;
    }
    cout << COLUMNS << endl;

    char schematic[ROWS][COLUMNS];
    while (fin>>line)
    {
        for (int i=0; i<ROWS; i++)
        {
            for (int j=0; j<COLUMNS; j++)
            {
                schematic[i][j] = line[j];
                cout << schematic[i][j];
            }
            cout << endl;
        }
    }

    fin.close();
    return 0;
}