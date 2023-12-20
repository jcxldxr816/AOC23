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

int findScore(string H)
{
    //five of a kind
    if (H[0] == H[1] == H[2] == H[3] == H[4])
    {
        return 1;
    }
    //four of a kind
    if ( (H[1] == H[2] == H[3] == H[4]) || 
         (H[0] == H[2] == H[3] == H[4]) || 
         (H[0] == H[1] == H[3] == H[4]) || 
         (H[0] == H[1] == H[2] == H[4]) || 
         (H[0] == H[1] == H[2] == H[3]) )
    {
        return 2;
    }
    //full house
    if ( ((H[0] == H[1]) && (H[2] == H[3] == H[4])) ||
         ((H[0] == H[2]) && (H[1] == H[3] == H[4])) ||
         ((H[0] == H[3]) && (H[2] == H[1] == H[4])) ||
         ((H[0] == H[4]) && (H[2] == H[3] == H[1])) ||
         
         ((H[1] == H[2]) && (H[0] == H[3] == H[4])) ||
         ((H[1] == H[3]) && (H[0] == H[2] == H[4])) ||
         ((H[1] == H[4]) && (H[0] == H[3] == H[2])) ||
         
         ((H[2] == H[3]) && (H[0] == H[1] == H[4])) ||
         ((H[2] == H[4]) && (H[0] == H[1] == H[3])) ||
         
         ((H[3] == H[4]) && (H[0] == H[1] == H[2])) )
    {
        return 3;
    }
    //three of a kind       DIDNT ADD ALL OF THEM
    if ( (H[0] == H[1] == H[2]) ||
         (H[0] == H[1] == H[3]) ||
         (H[0] == H[1] == H[4]) ||

         (H[0] == H[2] == H[3]) ||
         (H[0] == H[2] == H[4]) ||

         (H[0] == H[3] == H[4]) ||
         //-----------------------
         (H[1] == H[2] == H[3]) ||
         (H[1] == H[2] == H[4]) ||
         
         (H[1] == H[3] == H[4]) ||
         //-----------------------
         (H[2] == H[3] == H[4]) )
    {
        return 4;
    }
    //two pair
    if ( ((H[0] == H[1]) && (H[2] == H[3])) ||
         ((H[0] == H[1]) && (H[2] == H[4])) ||
         ((H[0] == H[1]) && (H[3] == H[4])) ||
         
         ((H[0] == H[2]) && (H[1] == H[3])) ||
         ((H[0] == H[2]) && (H[1] == H[4])) ||
         ((H[0] == H[2]) && (H[3] == H[4])) ||
         
         ((H[0] == H[3]) && (H[1] == H[2])) ||
         ((H[0] == H[3]) && (H[1] == H[4])) ||
         ((H[0] == H[3]) && (H[2] == H[4])) ||
         
         ((H[0] == H[4]) && (H[1] == H[2])) ||
         ((H[0] == H[4]) && (H[1] == H[3])) ||
         ((H[0] == H[4]) && (H[2] == H[3])) ||
         //-----------------------------------
         ((H[1] == H[2]) && (H[3] == H[4])) ||
         
         ((H[1] == H[3]) && (H[2] == H[4])) ||
         
         ((H[1] == H[4]) && (H[2] == H[3])) ||
         //-----------------------------------
         ((H[2] == H[1]) && (H[3] == H[4])) )
    {
        return 5;
    }
    //one pair
    if ( (H[0] == H[1]) ||
         (H[0] == H[2]) ||
         (H[0] == H[3]) ||
         (H[0] == H[4]) ||
         
         (H[1] == H[2]) ||
         (H[1] == H[3]) ||
         (H[1] == H[4]) ||
         
         (H[2] == H[3]) ||
         (H[2] == H[4]) ||
         
         (H[3] == H[4]) )
    {
        return 6;
    }
    //highest card
    int max = 0;
    for (int i=0; i<5; i++)
    {
        int score;
        if (H[i] = 'A')
        {
            score = 14;
        }
        if (H[i] = 'K')
        {
            score = 13;
        }
        if (H[i] = 'Q')
        {
            score = 12;
        }
        if (H[i] = 'J')
        {
            score = 11;
        }
        if (H[i] = 'T')
        {
            score = 10;
        }
        else
        {
            score = H[i] -48;
        }

        if (score > max)
        {
            max = score;
        }
    }
    return 7;
}

int main()
{
    ifstream fin;
    fin.open("d7p1src.txt");

    string line;
    int ct = 0;
    vector<string> hand;
    vector<int> bid;
    while (fin>>line)
    {
        //cout << line << endl;
        ct++;
        if ((ct%2) != 0) //odd
        {
            hand.push_back(line);
        }
        if ((ct%2) == 0) //even
        {
            ctoi(line, bid);
        }
    }

    /* for (string x : hand)
    {
        cout << x << endl;
    }
    for (int x : bid)
    {
        cout << x << endl;
    } */

    for (int i=0; i<hand.size(); i++)//for each pair of data
    {
        string h = hand.at(i);
        int b = bid.at(i);

        
    }

    fin.close();
    return 0;
}