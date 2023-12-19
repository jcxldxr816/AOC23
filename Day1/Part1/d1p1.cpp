#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("d1p1src.txt");
    (fin.is_open()) ? cout << "The file has successfully opened." : cout << "The file has failed to open." ;
    cout << endl;
    int sum =0;

    string line;
    while (fin>>line)
    {
        vector<char> values;
        for (int i=0; i<line.length(); i++)
        {
            if (isdigit(line[i]) == true)
            {
                values.push_back(line[i]);
            }
        }
        const int SIZE = values.size();
        char pair[3] = {values[0], values[SIZE - 1]};
        string n = pair;
        sum += stoi(n);
    }
    cout << sum;
    fin.close();
    return 0;
}