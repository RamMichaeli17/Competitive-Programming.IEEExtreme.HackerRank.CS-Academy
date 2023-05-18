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

// Done by Ram & Gal
// Bit Soccer

int main()
{
    // The number of player available 
    long long N;
    cin >> N;
    int i;
    // The performance indices of each player
    long long* Players = new long long[N];
    for (i = 0; i < N; i++)
    {
        cin >> Players[i];
    }
    // The number of queries
    int Q;
    cin >> Q;
    // The goal team performance index.
    long long G;
    while (Q--)
    {
        long long current = 0;
        cin >> G;
        for (i = 0; i < N; i++)
        {

            // The OR operator can only increase a number , so if we found out , using the & operator , that
            // There is a bit turned on in the player index BUT is turned off in the goal , we have no way of 
            // Turning that bit off with the OR operator , since , as we said , it can only turn ON bits , but here 
            // We need to turn off... so the number is irrelevant and can not be part of the answer.

            // If there is a match between the player index TURNED-ON bits and the goal TURNED-ON bits
            //  = Player & G = Player
            // Then the player number wont change after using the & operator , indicating that this number (Player)
            // Can possibly be matched (with the OR operator) with another number to get to the goal
            // In other words , if the condition is true , either the Player-number is exactly the goal
            // Or it has some of its bits that are turned-off that needs to be turned-on , something
            // That is possible to achieve with the OR operator

            if ((Players[i] & G) == Players[i])
                // First, current will be initiallized to 0 , and after evrey iteration of the loop ,
                // Add to the current num the 1's from the binary player index that passed the if-condition

                // Because it passed the if-condition , we know the number can only get us closer to the goal
                // And that there is no option to surpass the goal with such number (because of the if-condition)
                // So we either get closer to the goal or land exactly on our goal

                current = current | Players[i];
            // After evrey iteration we will check if the current is eqaul to G and if it does
            // We will break the loop and print YES
            if (current == G)
            {
                cout << "YES" << endl;
                break;
            }
        }
        // If after all the iterations the current won't be equal to the goal
        // Print NO
        if (current != G)
            cout << "NO" << endl;
    }
    return 0;
}