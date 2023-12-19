#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream fin;
    fin.open("d2p1src.txt");
    int gameCt =0;
    int sum =0;
    string line;
    while (getline(fin, line))
    {
        gameCt++;
        cout << "Game #" << gameCt << endl;
        bool lessThan = true;
        string section;
        int gamePos = line.find(": ");
        line.erase(0, gamePos+1);
        istringstream sin(line);
        //cout << "Line: " << line << endl;

        while (getline(sin, section, ';'))
        {
            //cout << "Section: " << section << endl;
            
            int redPos = section.find("red") -3;
            int greenPos = section.find("green") -3;
            int bluePos = section.find("blue") -3;
            int redVal, greenVal, blueVal = 0;

            if ((section[redPos] > 48) && (section[redPos] <=57))
            {
                redVal = 0;
                char red[] = {section[redPos], section[redPos+1]};
                string r = red;
                redVal = stoi(r);

                cout << "DOUBLE DIGIT" << endl;
            }
            else 
            {
                redVal = 0;
                redPos++;
                if (section[redPos] != 0)
                {
                    redVal = section[redPos] -48;
                }
            }

            if ((section[greenPos] > 48) && (section[greenPos] <=57))
            {
                greenVal = 0;
                char green[2] = {section[greenPos], section[greenPos+1]};
                cout << green << endl;
                string g = green;
                cout << g << endl;
                greenVal = stoi(g);

                cout << "DOUBLE DIGIT" << endl;
            }
            else 
            {
                greenVal = 0;
                greenPos++;
                if (section[greenPos] != 0)
                {
                    greenVal = section[greenPos] -48;
                }
            }

            if ((section[bluePos] > 48) && (section[bluePos] <=57))
            {
                blueVal = 0;
                char blue[] = {section[bluePos], section[bluePos+1]};

                string b = blue;

                blueVal = stoi(b);
                
                cout << "DOUBLE DIGIT" << endl;
            }
            else 
            {
                blueVal = 0;
                bluePos++;
                if (section[bluePos] != 0)
                {
                    blueVal = section[bluePos] -48;
                }
            }
            cout << "RGB Values: " << redVal << " " << greenVal << " " << blueVal <<endl;
            
        }
        cout << endl;
    }

    fin.close();
    return 0;
}