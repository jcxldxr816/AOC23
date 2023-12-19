#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void determineValues(int pos, string text, int & val)
{
    if (pos == -1)
    {
        val = 0;
        return;
    }
    
    //checking tens place for digit
    pos -=3;
    if ((text[pos] > 48) && (text[pos] <= 57)) //if there is a digit in tens place
    {
        char temp[] = {text[pos], text[pos+1]};
        string pair = temp;
        val = stoi(pair);
        return;
    }
    else //if there isn't a digit in the tens place
    {
        pos++; //move to ones place
        val = text[pos] -48;
        return;
    };
}

int main() //testing git version hist
{
    ifstream fin;
    fin.open("d2p1src.txt");
    int gameCt =0;
    int sum =0;
    string line;
    while (getline(fin, line))
    {
        bool lessThan = true;
        gameCt++;
        
        cout << "Game #" << gameCt << endl;
        string section;
        int gamePos = line.find(": ");
        line.erase(0, gamePos+1);
        istringstream sin(line);
        //cout << "Line: " << line << endl;

        while (getline(sin, section, ';'))
        {
            cout << endl;
            //cout << "Section: " << section << endl;
            
            int redPos = section.find("red");
            int greenPos = section.find("green");
            int bluePos = section.find("blue");
            int redVal, greenVal, blueVal = 0;

            determineValues(redPos, section, redVal);
            determineValues(greenPos, section, greenVal);
            determineValues(bluePos, section, blueVal);

            //cout << "RGB Values: " << "R: " << redVal << " " << "G: " << greenVal << " " << "B: " << blueVal <<endl;

            if ((redVal > 12) || (greenVal > 13) || (blueVal > 14))
            {
                lessThan = false;
                cout << "game is impossible" << endl;
            }
        }
        if (lessThan == true)
        {
            sum += gameCt;
        }
        cout << endl;
        cout << sum << endl;
    }

    fin.close();
    return 0;
}