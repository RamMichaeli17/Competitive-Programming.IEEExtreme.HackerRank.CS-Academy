#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <map>
#include <list>
#include <limits.h>
#include <queue>
#include <sstream>
using namespace std;


//Xtreme9.0 - Shortening in the Real World

//Encode this unsigned integer using Base62 encoding. In this encoding, you convert the integer to a base 62 number,
//where the digits 0-9 represent values 0-9, lowercase letters a-z represent values 10-35, and capital letters A-Z represent values 36-61

/* a function to convert a decimal number to a base62 number , taken from github, simple function:
https://gist.github.com/heminy/1b189bf0db872639041f9bc0f31d012e - the first function
*/

//used for the base62 convertor
const string CODES = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string toBase62(long long value) {
    string str;

    do {
        str.insert(0, string(1, CODES[value % 62]));
        value /= 62;
    } while (value > 0);

    return str;
}

int main()
{
    //the base URL of your company
    string baseUrl;
    cin >> baseUrl;
    //used in the while loop to copy the baseUrl
    string newBaseUrl;
    //the number of URLs you will need to encode
    int n;
    cin >> n;
    //target URL to encode
    string targetUrl;
    //used in the while loop to copy the baseUrl
    string temp;
    //index
    int j;
    //represent the result after the XOR operataion
    int num;
    // the last 8 bytes of the number converted to an unsigned integer
    long long x;
    //used in the while loop 
    string stemp;

    while (n--)
    {
        // stringstream type to save the hex numbers
        stringstream ss;
        //copy to baseUrl
        newBaseUrl = baseUrl;
        // get from the user the targetUrl
        cin >> targetUrl;
        // if the target is bigger than the base
        if (newBaseUrl.size() < targetUrl.size())
        {
            //resize could be done, same methood
            temp = targetUrl;
            //If the base URL of your company is shorter than the target URL, you would repeat the base URL as many times as needed to make the lengths equal
            for (j = 0; j < targetUrl.size(); j++)
            {
                temp[j] = newBaseUrl[(j % baseUrl.size())];
            }
        }
        else
            //If the target URL is shorter than the base URL of your company, you would truncate the base URL so that the lengths are equal
        {
            temp = newBaseUrl;
            temp.resize(targetUrl.size());
        }
        //Now we apply the exclusive - or cipher, repeating the bytes in the base URL so that the two strings are the same length 
        for (j = temp.size() - 8; j < temp.size(); j++)
        {
            //xor operation between to ASCII chars
            num = temp[j] ^ targetUrl[j];
            //convert to hex num
            ss << hex << num;
            //if the num has only 1 figure add 0 before
            if (ss.str().size() == 1)
                stemp.append("0");
            //add this num to the string
            stemp.append(ss.str());
            //reset the stringstream to the next operation
            ss.str("");
        }
        //take the last 8 bytes from temp, and convert this to the corresponding unsigned integer
        ss << hex << stemp;
        ss >> x;
        //take the baseUrl and add to it '/' and the base62 form of the unsinged integer
        newBaseUrl.append('/' + toBase62(x));
        cout << newBaseUrl << endl;
        //reset the stringstream
        ss.str("");
        //reset the string stemp
        stemp.clear();
    }
    return 0;
}