#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
    string label;
    string left;
    string right;
};

int main()
{
    ifstream fin;
    fin.open("d8p1src.txt");

    string instructions;
    fin >> instructions;
    //cout << instructions;

    string line;
    const unsigned short nodeCt = 770;

    Node nodes[nodeCt];

    //populating each node's 3 variables
    int x = 0;
    int z = 0;
    while (fin>>line)
    {
        if (x==0)
        {
            nodes[z].label = line;
            x++;
        }
        else if (x==1)
        {
            x++;
        }
        else if (x==2)
        {
            line.erase(4, 1);
            line.erase(0, 1);

            nodes[z].left = line;
            x++;
        }
        else if (x==3)
        {
            line.erase(3, 1);

            nodes[z].right = line;
            x = 0;
            //cout << "Label: " << nodes[z].label << " Left: " << nodes[z].left << " Right: " << nodes[z].right << endl;
            z++;
        }
    }

    //cout << "searchval: AAA" << endl;
    string searchVal = "AAA";
    int instructIndex = 0;
    int stepCt = 0;
    bool zFound = false;
    while (zFound == false)
    {
        for (int i=0; i<nodeCt; i++)
        {
            if (searchVal == nodes[i].label)
            {
                //cout << "Found: " << nodes[i].label << endl;
                //cout << "Left Option: " << nodes[i].left << " Right Option: " << nodes[i].right << endl;
                if (instructions[instructIndex] == 'L')
                {
                    searchVal = nodes[i].left;
                }
                else if (instructions[instructIndex] == 'R')
                {
                    searchVal = nodes[i].right;
                }
                else
                {
                    instructIndex = 0;
                    continue;
                }
                instructIndex++;
                if (nodes[i].label == "ZZZ")
                {
                    cout << stepCt;
                    zFound = true;
                    return 0;
                }
                stepCt++;
            }
        }
    }
    
    fin.close();
    return 0;
}