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
    fin.open("d6p1src.txt");

    string line;
    int pos;
    int i = 0;
    vector<int> times;
    vector<int> distances;
    while (fin>>line)
    {
        if ((i>0) && (i<5))
        {
            ctoi(line, times);
        }
        else if ((i>5) && (i<10))
        {
            ctoi(line, distances);
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
        vector<int> possibleTraveledDistances;
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