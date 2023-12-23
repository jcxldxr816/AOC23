#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void ctoi(string source, vector<int> & values)
{
    stringstream iss;
    iss << source;
    string text;
    while (iss >> text)
    {
        values.push_back(stoi(text));
    }
}

void sequenceGenerator(vector<int> values, vector<int> & sequence)
{
    //sequence.clear();
    for (int i = 0; i<(values.size() -1); i++)
    {
        sequence.push_back(values.at(i+1) - values.at(i));
    }
}

void isZero()
{
    
}

int main()
{
    ifstream fin;
    fin.open("d9p1src.txt");

    const unsigned short lineCt = 3;
    string line;
    vector<int> lines[lineCt];
    int i = 0;
    while (getline(fin, line))
    {
        //cout << line << endl;
        ctoi(line, lines[i]);
        i++;
    }

    /* for (int t = 0; t<lineCt; t++)
    {
        cout << lines[t][0] << " ";
        cout << lines[t][1] << " ";
        cout << lines[t][2] << " ";
        cout << lines[t][3] << " ";
        cout << lines[t][4] << " ";
        cout << lines[t][5] << " ";
        cout << endl;
    } */

    vector<int> changes; //next step will be to push the changes back into the sequence generator for another run, until only zeros
    for (int j = 0; j<lineCt; j++)
    {
        sequenceGenerator(lines[j], changes);

        int zeroCt = 0;
        for (int x : changes)
        {
            if (x==0)
            {
                zeroCt++;
            }
            cout << x << " ";
        }
        cout << endl;
        if (zeroCt == changes.size())
        {
            cout << "All zeroes" << endl;
        }
        else
        {
            zeroCt = 0;
        }
    }

    fin.close();
    return 0;
}