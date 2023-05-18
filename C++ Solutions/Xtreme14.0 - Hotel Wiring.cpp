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
using namespace std;

//Hotel Wiring
int main()
{
    //the number of test cases
    int T;
    cin >> T;
    //M is the number of floors in the hotel, 1≤M≤10^6 , because of that not int but long.
    long M;
    //N is the number of rooms per floor
    long N;
    //K is the exact number of master switches that will be turned off
    long K;

    long* number_of_rooms_that_are_wired_correctly_on_one_floor;
    int i;
    long maximum_number_of_rooms_that_may_receive_power = 0;
    while (T--)
    {
        cin >> M >> N >> K;
        number_of_rooms_that_are_wired_correctly_on_one_floor = new long[M];
        for (i = 0; i < M; i++)
        {
            cin >> number_of_rooms_that_are_wired_correctly_on_one_floor[i];
        }
        sort(number_of_rooms_that_are_wired_correctly_on_one_floor, number_of_rooms_that_are_wired_correctly_on_one_floor + M);
        for (i = 0; i < M; i++)
        {
            if (K > 0)
            {
                maximum_number_of_rooms_that_may_receive_power += N - number_of_rooms_that_are_wired_correctly_on_one_floor[i];
                K--;
            }
            else
                maximum_number_of_rooms_that_may_receive_power += number_of_rooms_that_are_wired_correctly_on_one_floor[i];
        }
        cout << maximum_number_of_rooms_that_may_receive_power << endl;
        maximum_number_of_rooms_that_may_receive_power = 0;
    }
    return 0;
}
