﻿#include <cmath>
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


//Xtreme9.0 - Taco Stand
int main()
{
    //how many days Joe will be making tacos.
    int n;
    cin >> n;
    //the number of shells available
    long long s;
    //ingredients[0] is the amount of meat, ingredients[1] is the amount of rice, and ingredients[2] is the amount of beans
    long long ingredients[3];
    while (n--)
    {
        cin >> s >> ingredients[0] >> ingredients[1] >> ingredients[2];
        sort(ingredients, ingredients + 3);
        //ingredients[0] = min(r, m, b), i.e. the smallest quantity of all fillings
        //ingredients[1] = median(r, m, b), i.e. the middle quantity of all fillings
        //ingredients[2] = max(r, m, b), i.e. the largest quantity of all fillings
        //
        //Scenario 1: ingredients[2] > ingredients[0] + ingredients[1]
        //Here the maximum number of filling combinations we can create is generated by using
        //the ingredients[2]-type filling in every taco, with one of the other fillings. So if s is the number of taco
        //shells we have, the number of tacos Joe can make is the min(s, x + y).
        if (ingredients[0] + ingredients[1] < ingredients[2])
            cout << min(s, ingredients[0] + ingredients[1]) << endl;
        else
            cout << min(s, (ingredients[0] + ingredients[1] + ingredients[2]) / 2) << endl;
        //Scenario 2: ingredients[2] <= ingredients[0] + ingredients[1]
        //In scenario 2, we will take an approach that, given sufficient taco shells, will use all but at
        //most one of the fillings. We will start by making tacos with the x-type filling and the z-type
        //filling, reducing z until it becomes equal with y.
        //Then, while there are still two x-type fillings remaining, we will make two tacos - one with
        //x-type and y-type fillings, and one with x-type and z-type fillings. By making pairs of tacos
        //at a time, y stays equal to z.
        //Once we down to less than 2 remaining x-type fillings, we will make tacos using y-type and
        //z-type fillings. Since there are an equal number of both of these, we can use all of the y-
        //type and z-type ingredients.
        //Since we know how to use all (but perhaps one) of the ingredients in this case, we can
        //come up with a simple formula for the number of tacos. Letting s be the number of taco
        //shells we have, the number of tacos Joe can make is the min(s, floor((x + y + z)/2)).
    }
    return 0;
}