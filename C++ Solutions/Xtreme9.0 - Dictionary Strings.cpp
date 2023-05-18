#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Xtreme9.0 - Dictionary Strings
int main()
{
    //Some of the test cases are very large, and may require you to speed up input handling in some languages
    //In C++, for example, you can include the following line as 
    //the first line in your main function to speed up the reading from input
    std::ios_base::sync_with_stdio(false);
    //indexes
    int i, j;
    //number of test cases
    int T;
    //represents the number of words in a dictionary
    int D;
    //represents the number of potential dictionary strings to be checked.
    int S;
    cin >> T;
    //a word in the dictionary
    string word;
    //vector to store all the words
    vector<string> words;
    //stores the number of letters from each word 
    int** countArray;
    //the minimum number of characters needed to make the string a Dictionary String
    int missingCounter = 0;
    int flag = 0;
    while (T--)
    {
        //count array that stores the biggest number of each letter from all the words
        int biggestCountArray[26];
        cin >> D >> S;
        countArray = new int* [D];
        for (i = 0; i < D; i++)
        {
            cin >> word;
            countArray[i] = new int[26] { 0 };
            words.push_back(word);
            for (j = 0; j < words[i].size(); j++)
            {
                countArray[i][(words[i][j] - 'a')]++;
            }
        }
        for (i = 0; i < 26; i++)
        {
            biggestCountArray[i] = countArray[0][i];
        }
        for (i = 1; i < D; i++)
        {
            for (j = 0; j < 26; j++)
            {
                if (countArray[i][j] > biggestCountArray[j])
                    biggestCountArray[j] = countArray[i][j];
            }
        }
        while (S--)
        {
            //a copy of the upper array
            int copyBiggestCountArray[26];
            for (i = 0; i < 26; i++)
            {
                copyBiggestCountArray[i] = biggestCountArray[i];
            }
            cin >> word;
            //for evrey letter of the potential dictionary string substract 1 from the copy biggest array
            for (i = 0; i < word.size(); i++)
            {
                copyBiggestCountArray[word[i] - 'a']--;
            }
            //count how many missing letters
            for (i = 0; i < 26; i++)
            {
                if (copyBiggestCountArray[i] > 0)
                {
                    missingCounter += copyBiggestCountArray[i];
                }
            }
            //if there is at least one letter that is missing print No and the number of the letters
            if (missingCounter > 0)
                cout << "No " << missingCounter << endl;
            //if there are no missing letters
            else
            {
                for (i = 0; i < 26; i++)
                {
                    //if there are extra letters
                    if (copyBiggestCountArray[i] < 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    cout << "Yes No" << endl;
                else
                    cout << "Yes Yes" << endl;
            }
            flag = 0;
            missingCounter = 0;
        }
        words.clear();
    }
    return 0;
}