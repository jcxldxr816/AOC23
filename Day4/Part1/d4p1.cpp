#include <iostream>
#include <fstream>
#include <vector>

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
    vector<char> cString;
    for (char c : source)
    {
        cString.push_back(c);
    }
    for (int i=0; i<cString.size(); i++)
    {
        //2 digit number " XX"
        if ( (cString.at(i) == ' ') && ((cString.at(i) >48) && (cString.at(i) <=57)) && ((cString.at(i+1) >=48) && (cString.at(i+1) <=57)) )
        {
            char temp[] = {cString.at(i), cString.at(i+1)};
            string pair = temp;
            values.push_back(stoi(pair));
        }
        //1 digit number " X "
        if ((cString.at(i) == ' ') && ((cString.at(i+1) >48) && (cString.at(i+1) <=57)) && (cString.at(i+2) == ' '))
        {
            values.push_back(cString.at(i+1)-48);
        }
    }
}

int main()
{
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
        cout << "Winning Numbers: " << winString << " Card Numbers: " << cardString << endl;

        vector<int> winningNums;
        ctoi(winString, winningNums);

        vector<int> cardNums;
        ctoi(cardString, cardNums);

        for (int x : winningNums)
        {
            cout << "Winning Nums: " << x << endl;
        }
        for (int x : cardNums)
        {
            cout << "Card Nums: " << x << endl;
        }
    }

    fin.close();
    return 0;
}