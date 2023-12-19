#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("d3p1src.txt");

    //must manually enter rows and columns
    const unsigned short ROWS = 140;
    const unsigned short COLUMNS = 140;
    char schematic[ROWS][COLUMNS];
    //populating 2d array schematic
    string line;
    int i=0;
    while (fin>>line)
    {
        for (int j=0; j<COLUMNS; j++)
        {
            schematic[i][j] = line[j];
        }
        
        i++;
    }

    /* for (int i=0; i<ROWS; i++)//printing og schematic
    {
        for (int j=0; j<COLUMNS; j++)
        {
            cout << schematic[i][j];
        }
        cout << endl;
    }
    cout << endl; */

    int sum=0;

    for (int i=0; i<ROWS; i++)
    {
        for (int j=0; j<COLUMNS; j++)
        {
            if ((schematic[i][j] >= 48) && (schematic[i][j] <= 57))
            {
                //number found
                if (((schematic[i][j+1] >= 48) && (schematic[i][j+1] <= 57)) && ((schematic[i][j+2] >= 48) && (schematic[i][j+2] <= 57)))
                {
                    //next two spaces are also numbers
                    bool valid = false;
                    if ((i==0) && (j==0)) //top left corner
                    {
                        if (
                                                                                                                            (schematic[i][j+3] != '.')
                        || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.') || (schematic[i+1][j+3] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if ((i==0) && (j+2==COLUMNS-1)) //top right corner
                    {
                        if (
                         (schematic[i][j-1] != '.')                                                                                                  
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if ((i==ROWS-1) && (j==0)) //bot left corner
                    {
                        if ((schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.') || (schematic[i-1][j+3] != '.')
                                                                                                                           || (schematic[i][j+3] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if ((i==ROWS-1) && (j+2==COLUMNS-1)) //bot right corner
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.')
                         || (schematic[i][j-1] != '.')                                                                                                  )
                        {
                            valid = true;
                        }
                    }
                    else if (i==0) //top row
                    {
                        if ((schematic[i][j-1] != '.')                                                                                                  || (schematic[i][j+3] != '.')
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.') || (schematic[i+1][j+3] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (i==ROWS-1) //bot row
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.') || (schematic[i-1][j+3] != '.')
                         || (schematic[i][j-1] != '.')                                                                                                  || (schematic[i][j+3] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (j==0) //left side
                    {
                        if ((schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.') || (schematic[i-1][j+3] != '.')
                                                                                                                           || (schematic[i][j+3] != '.')
                         || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.') || (schematic[i+1][j+3] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (j+2==COLUMNS-1) //right side
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.') 
                         || (schematic[i][j-1] != '.')                                                                                                
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else //anywhere else
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.') || (schematic[i-1][j+3] != '.')
                         || (schematic[i][j-1] != '.')                                                                                                  || (schematic[i][j+3] != '.')
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.') || (schematic[i+1][j+3] != '.'))
                        {
                            valid = true;
                        }
                    }

                    if (valid == true)
                    {
                        char temp[] = {schematic[i][j], schematic[i][j+1], schematic[i][j+2]};
                        string triplets = temp;
                        //cout << triplets << endl;
                        int val = stoi(triplets);
                        //cout << val << endl;
                        sum +=val;
                        schematic[i][j] = 'X';
                        schematic[i][j+1] = 'X';
                        schematic[i][j+2] = 'X';
                    }
                }
                if (!((schematic[i][j-1] >= 48) && (schematic[i][j-1] <= 57)) && ((schematic[i][j+1] >= 48) && (schematic[i][j+1] <= 57)) && !((schematic[i][j+2] >= 48) && (schematic[i][j+2] <= 57)))
                {
                    /* schematic[i][j] = 'X';
                    schematic[i][j+1] = 'X'; */
                    bool valid = false;
                    if ((i==0) && (j==0)) //top left corner
                    {
                        if (
                                                                                          (schematic[i][j+2] != '.')
                        || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if ((i==0) && (j+1==COLUMNS-1)) //top right corner
                    {
                        if (
                         (schematic[i][j-1] != '.')                                                                  
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if ((i==ROWS-1) && (j==0)) //bot left corner
                    {
                        if ((schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.')
                                                                                          || (schematic[i][j+2] != '.')
                        )
                        {
                            valid = true;
                        }
                    }
                    else if ((i==ROWS-1) && (j+1==COLUMNS-1)) //bot right corner
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.')
                        || (schematic[i][j-1] != '.')                                                                  
                        )
                        {
                            valid = true;
                        }
                    }
                    else if (i==0) //top row
                    {
                        if ( (schematic[i][j-1] != '.')                                                                  || (schematic[i][j+2] != '.')
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (i==ROWS-1) //bot row
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.')
                        || (schematic[i][j-1] != '.')                                                                  || (schematic[i][j+2] != '.')
                        )
                        {
                            valid = true;
                        }
                    }
                    else if (j==0) //left side
                    {
                        if ((schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.')
                                                                                          || (schematic[i][j+2] != '.')
                        ||  (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (j+1==COLUMNS-1) //right side
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.')
                        || (schematic[i][j-1] != '.')                                                                  
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else //anywhere else
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.') || (schematic[i-1][j+2] != '.')
                        || (schematic[i][j-1] != '.')                                                                  || (schematic[i][j+2] != '.')
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.') || (schematic[i+1][j+2] != '.'))
                        {
                            valid = true;
                        }
                    }

                    if (valid == true)
                    {
                        char temp[] = {schematic[i][j], schematic[i][j+1]};
                        string pair = temp;
                        //cout << pair << endl;
                        int val = stoi(pair);
                        //cout << val << endl;
                        sum +=val;
                        schematic[i][j] = 'X';
                        schematic[i][j+1] = 'X';
                    }
                }
                if (!((schematic[i][j-1] >= 48) && (schematic[i][j-1] <= 57)) && ((schematic[i][j] >= 48) && (schematic[i][j] <= 57)) && !((schematic[i][j+1] >= 48) && (schematic[i][j+1] <= 57)))
                {
                    bool valid = false;
                    if ((i==0) && (j==0)) //top left corner
                    {
                        if (                                   (schematic[i][j+1] != '.')
                         || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if ((i==0) && (j==COLUMNS-1)) //top right corner
                    {
                        if (
                        (schematic[i][j-1] != '.')                                 
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') )
                        {
                            valid = true;
                        }
                    }
                    else if ((i==ROWS-1) && (j==0)) //bot left corner
                    {
                        if ( (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.')
                                                         || (schematic[i][j+1] != '.')
                        )
                        {
                            valid = true;
                        }
                    }
                    else if ((i==ROWS-1) && (j==COLUMNS-1)) //bot right corner
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') 
                        || (schematic[i][j-1] != '.')                                 
                        )
                        {
                            valid = true;
                        }
                    }
                    else if (i==0) //top row
                    {
                        if ((schematic[i][j-1] != '.')                                 || (schematic[i][j+1] != '.')
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (i==ROWS-1) //bot row
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.')
                        || (schematic[i][j-1] != '.')                                 || (schematic[i][j+1] != '.')
                        )
                        {
                            valid = true;
                        }
                    }
                    else if (j==0) //left side
                    {
                        if ( (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.')
                                                         || (schematic[i][j+1] != '.')
                         || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else if (j==COLUMNS-1) //right side
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.')
                        || (schematic[i][j-1] != '.')                                 
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.'))
                        {
                            valid = true;
                        }
                    }
                    else //anywhere else
                    {
                        if ((schematic[i-1][j-1] != '.') || (schematic[i-1][j] != '.') || (schematic[i-1][j+1] != '.')
                        || (schematic[i][j-1] != '.')                                 || (schematic[i][j+1] != '.')
                        || (schematic[i+1][j-1] != '.') || (schematic[i+1][j] != '.') || (schematic[i+1][j+1] != '.'))
                        {
                            valid = true;
                        }
                    }

                    if (valid == true)
                    {
                        int val = schematic[i][j] -48;
                        //cout << val << endl;
                        sum +=val;
                        schematic[i][j] = 'X';
                    }
                }
            }
        }
        
    }

    //printing altered schematic
    for (int i=0; i<ROWS; i++)
    {
        for (int j=0; j<COLUMNS; j++)
        {
            cout << schematic[i][j];
        }
        cout << endl;
    }

    cout << sum;

    fin.close();
    return 0;
}