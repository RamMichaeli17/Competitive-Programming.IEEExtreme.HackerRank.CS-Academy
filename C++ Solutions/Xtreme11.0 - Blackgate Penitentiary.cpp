#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
    //the number of crew members that were arrested
    int n;
    cin >> n;
    int i;
    //the name of the crew member
    string s;
    // the height of the crew member
    int h;
    //firstly, insert the element to a regular map (key,value).. ordered by strings
    map <string, int> M;
    ////secondly, a new map with the option to insert multiplie same values with height ordered from low to high 
    multimap<int, string> MM;
    //iterator to run on the map
    multimap<int, string>::iterator it;
    int firstIndex = 1;
    int secondIndex = 1;
    for (i = 0; i < n; i++)
    {
        cin >> s >> h;
        M[s] = h;
    }
    for (auto& it : M) {
        MM.insert({ it.second, it.first });
    }
    //run the entire map
    for (it = MM.begin(); it != MM.end(); it++)
    {
        //check if the heights are same
        while (it->first == (++it)->first)
        {
            secondIndex++;
            cout << (--it)->second << " ";
            ++it;
        }
        --it;
        cout << it->second << " " << firstIndex << " " << secondIndex << endl;
        secondIndex++;
        firstIndex = secondIndex;

    }
    return 0;
}