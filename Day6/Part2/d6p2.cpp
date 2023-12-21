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

int main()
{
    ifstream fin;
    fin.open("/Users/james/Desktop/AOC23/Day6/Part1/d6p1src.txt");

    string line;
    int pos;
    unsigned short i = 1;
    bool timeDone = false;
    vector<long> times;
    vector<long> distances;
    while (fin>>line)
    {
        if ((i%2) ==0)
        {
            if (timeDone == false)
            {
                cout << line << endl;
                //ctoi(line, times);
                times.push_back(stol(line));
                timeDone = true;
            }
            else
            {
                cout << line << endl;
                //ctoi(line, distances);
                distances.push_back(stol(line));
            }
        }
        i++;
    }

    /* for (int x : times)
    {
        cout << x << endl;
    }
    cout << endl;
    for (int x : distances)
    {
        cout << x << endl;
    } */

    for (int j=0; j<4; j++)//for each data pair, 1-4
    {
        int t = times.at(j);
        int d = distances.at(j);
        vector<long> possibleTraveledDistances;
        int ct = 0;

        for (int s= 0; s<t; s++)//for each possuble windup duration/speed
        {
            //s represents speed
            int remainingTime = t - s;
            int distTraveled = s * remainingTime;
            possibleTraveledDistances.push_back(distTraveled);
        }

        for (int x : possibleTraveledDistances)
        {
            if (x > d)
            {
                ct++;
            }
        }

        cout << "Total number of ways record can be beaten for pair #" << j+1 << ": " << ct << endl;
    }

    fin.close();
    return 0;
}