#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

void splitString(string source, char delim, string & a, string & b)
{
    string copy = source;
    int pos = source.find(delim);
    a = source.erase(pos);
    b = copy.erase(0, pos+1);
}

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

int main()
{
    int sum = 0;
    
    ifstream fin;
    fin.open("d4p1src.txt");

    string line;
    while (getline(fin, line, '\n'))
    {
        int pos;
        pos = line.find(": ");
        line.erase(0, pos+1);
        //cout << line << endl;

        string winString, cardString;
        splitString(line, '|', winString, cardString);
        //cout << "Winning Numbers: " << winString << " Card Numbers: " << cardString << endl;

        vector<int> winningNums;
        ctoi(winString, winningNums);

        vector<int> cardNums;
        ctoi(cardString, cardNums);

        int points = 0;
        bool havePt = false;
        for (int x : cardNums)
        {
            for (int y : winningNums)
            {
                if ( (x == y) && (havePt == false) )
                {
                    points++;
                    havePt = true;
                    //cout << "MATCH FOUND - - - Winning Number: " << y << " Card Number: " << x  << " " << endl;
                    //cout << "Score: " << points << endl;
                }
                else if ( (x == y) && (havePt == true) )
                {
                    points *= 2;
                    //cout << "MATCH FOUND - - - Winning Number: " << y << " Card Number: " << x << " DOUBLED SCORE" << endl;
                    //cout << "Score: " << points << endl;
                }
            }
        }
        sum += points;
    }
    cout << sum;

    fin.close();
    return 0;
}