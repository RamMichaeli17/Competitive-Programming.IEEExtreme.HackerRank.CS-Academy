#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Xtreme9.0 - Digit Fun!
int main()
{
    //size of the number we are scaning
    int size;
    //the number we are scanning 
    string input;
    cin >> input;
    //main loop
    while (input != "END")
    {
        //size of the string
        size = input.size();
        //A0=1 -> A1=|1|=1 -> A0=A1=1 ----> 1 making 1 the smallest positive i such that Ai = Ai-1.
        if (input == "1")
            cout << 1 << endl;
        //A0={0,2,3,...,9} -> A1=1 -> A0!=A1 -> A2= |A1| = |1| = 1 -> A2=A1=1 ----> making 2 the smallest positive i such that Ai = Ai-1.   
        else if (size == 1)
            cout << 2 << endl;
        //A0={10,11,...,999999999}-> A1={2,3,...,9} -> A0!=A1 -> A2=1 -> A1!=A2 -> A3=|A2|=|1|=1 -> A3=A2=1 ----> making 3 the smallest positive i such that Ai = Ai-1.
        else if (size < 10)
            cout << 3 << endl;
        //A0={1*10^9,...,1*10^1mil-1} -> A1={10,11,...,1mil} -> A0!=A1 -> A2={2,3,...,7} -> A1!=A2 -> A3 = |A2| = 1 -> A2!=A3 -> A4 = |A3| = |1| = 1 ---->  making 4 the smallest positive i such that Ai = Ai-1.
        //because each value of the input is non-negative and no more than a million digits
        //The upper bound of A1 is 1mil and even that will lead us to max 7 in A2 and because of that the last option is 4 and only 4.
        else
            cout << 4 << endl;
        //another loop
        cin >> input;
    }
    return 0;
}
