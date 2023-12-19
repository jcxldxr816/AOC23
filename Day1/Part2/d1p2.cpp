#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ifstream fin;
    //fin.open("/Users/james/Desktop/AOC23/Day1/Part1/d1p1src.txt");//using full path so I don't have to copy files for every day
    fin.open("test.txt");
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
        
        for (int i=0; i<=(line.length()-5); i++)
        {
            string sample = line.substr(i, 5);
            if (sample.find("zero"))
            {
                values.push_back(48);
            }
            else if (sample.find("one"))
            {
                values.push_back(49);
            }
            else if (sample.find("two"))
            {
                values.push_back(50);
            }
            else if (sample.find("three"))
            {
                values.push_back(51);
            }
            else if (sample.find("four"))
            {
                values.push_back(52);
            }
            else if (sample.find("five"))
            {
                values.push_back(53);
            }
            else if (sample.find("six"))
            {
                values.push_back(54);
            }
            else if (sample.find("seven"))
            {
                values.push_back(55);
            }
            else if (sample.find("eight"))
            {
                values.push_back(56);
            }
            else if (sample.find("nine"))
            {
                values.push_back(57);
            }
        }
        for (char x : values)
        {
            cout << x << " ";
        }
        const int SIZE = values.size();
        char pair[3] = {values[0], values[SIZE - 1]};
        string n = pair;
        cout << n << endl;
        sum += stoi(n);
    }
    cout << sum;
    fin.close();
    return 0;
}