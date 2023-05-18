#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

//Xtreme9.0 - Zoom In
int main()
{
    //Use unordered_map when 
    //You need to keep count of some data (Example: strings) and no ordering is required.
    //You need single element access i.e. no traversal.
    unordered_map <char, vector<string>> mainMap;
    //representing how many columns each character will use when printed "zoomed-in".
    int n;
    cin >> n; //
    cin.ignore();
    //representing how many rows each character will use when printed "zoomed-in".
    int m;
    cin >> m;
    cin.ignore();
    //indicates how many characters may need to be translated.
    int k;
    cin >> k;
    cin.ignore();
    //a single character, which has an ASCII value of between 32 and 126, inclusive
    string c;
    //the "zoomed-in" representation of the character on the previous line
    string s;
    int i;
    int j;
    for (i = 0; i < k; i++)
    {
        getline(cin, c);
        for (j = 0; j < m; j++)
        {
            getline(cin, s); // had a problem with scaning a single char
            //insert into the map by charcter and the sutible strings for.
            mainMap[c[0]].push_back(s);
        }
    }
    //indicates how many strings.
    int x;
    cin >> x;
    cin.ignore();
    //each containing a string of up to 2,000 characters, and ending with a new line.
    //The characters in this string will be chosen from the set of k characters previously specified.
    string xS;
    while (x--)
    {
        getline(cin, xS);
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < xS.size(); j++)
            {
                cout << mainMap[xS[j]][i];
            }
            cout << endl;
        }
    }
    return 0;
}