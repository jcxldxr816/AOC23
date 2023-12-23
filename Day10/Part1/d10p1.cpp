#include <iostream>
#include <fstream>

using namespace std;

const unsigned short ROWS = 5;

string newGrid[ROWS];
void clearJunk(int row, int column, string map[])
{
    char p = map[row][column]; //p for pipe segment

    if (p == '|')
    {
        if ((map[row+1][column] != ('7' || 'F' || '|')) || (map[row-1][column] != ('J' || 'L' || '|')))
        {
            newGrid[row][column] = '.'; //treat as ground
        }
        else newGrid[row][column] = p; //remain the same
    }
    else if (p == '-')
    {
        if ((map[row][column-1] != ('F' || 'L' || '-')) || (map[row][column+1] != ('J' || '7' || '-')))
        {
            newGrid[row][column] = '.'; //treat as ground
        }
        else newGrid[row][column] = p; //remain the same
    }
    else if (p == 'L')
    {
        if ((map[row][column+1] != ('7' || 'J' || '-')) || (map[row+1][column] != ('F' || '7' || '|')))
        {
            newGrid[row][column] = '.'; //treat as ground
        }
        else newGrid[row][column] = p; //remain the same
    }
    else if (p == 'J')
    {
        if ((map[row][column-1] != ('F' || 'L' || '-')) || (map[row+1][column] != ('F' || '7' || '|')))
        {
            newGrid[row][column] = '.'; //treat as ground
        }
        else newGrid[row][column] = p; //remain the same
    }
    else if (p == '7')
    {
        if ((map[row-1][column] != ('L' || 'J' || '|')) || (map[row][column-1] != ('F' || 'L' || '-')))
        {
            newGrid[row][column] = '.'; //treat as ground
        }
        else newGrid[row][column] = p; //remain the same
    }
    else if (p == 'F')
    {
        if ((map[row-1][column] != ('L' || 'J' || '|')) || (map[row][column+1] != ('J' || '7' || '-')))
        {
            newGrid[row][column] = '.'; //treat as ground
        }
        else newGrid[row][column] = p; //remain the same
    }
    else newGrid[row][column] = p;
}

int main()
{
    ifstream fin;
    fin.open("d10p1src.txt");

    string grid[5]; //enter number of lines
    string line;
    int j=0;
    while (fin>>line)
    {
        grid[j] = line;
        j++;
    }
    const unsigned short COLUMNS = grid[0].length();
    
    int sRow, sCol;
    for (int r = 0; r<ROWS; r++) //for each row of map
    {
        for (int c = 0; c<COLUMNS; c++)
        {
            if (grid[r][c] == 'S')
            {
                sRow = r;
                sCol = c;
            }
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int r = sRow-1; r<sRow+2; r++) //for each row of map
    {
        for (int c = sCol-1; c<sCol+2; c++)
        {
            clearJunk(r,c,grid);
            cout << newGrid[r][c] << " ";
        }
        cout << endl;
    }

    /* for (int r = 0; r<ROWS; r++) //for each row of map
    {
        for (int c = 0; c<COLUMNS; c++)
        {
            cout << newGrid[r][c] << " ";
        }
        cout << endl;
    } */

    fin.close();
    return 0;
}