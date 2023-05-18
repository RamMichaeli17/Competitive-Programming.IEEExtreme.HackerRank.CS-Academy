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
using namespace std;

//Dog Walking
int main()
{
    //the number of test cases
    int t;
    cin >> t;
    //the number of dogs
    int N;
    //the number of employees
    int K;
    int i;
    //representing the size of the corresponding dogs
    int* dogSizes;
    //saving the difference between the sizes of each pair of dogs from the smallest to the biggest
    vector<int> dual;
    //the output
    int minimumSum;
    while (t--)
    {
        cin >> N >> K;
        dogSizes = new int[N];
        for (i = 0; i < N; i++)
        {
            cin >> dogSizes[i];
        }
        //Also, since she doesn't want any of the dog walkers to feel left out, 
        //she makes sure each dog walker gets to walk at least one dog
        //because of that, if the number of the dogs equals to the number of the employees
        //than each employee will take one dog and because the range of a group consisting of a single dog is 0
        //the minimum sum will be 0
        if (N == K)
        {
            cout << 0 << endl;
            continue;
        }
        //sorting the dog sizes from small to big
        sort(dogSizes, dogSizes + N);
        //making substracts between each pair of dogs from smallest to biggest
        //after each substract we add the differnce between the bigger one to the smaller one
        //(from left to right)
        for (i = 0; i < N - 1; i++)
        {
            dual.push_back(dogSizes[i + 1] - dogSizes[i]);
        }
        //sorting the differences from small to big
        sort(dual.begin(), dual.end());
        //starting from the worst case (the biggest difference) 
        //taking the biggest dog(the array is sorted) and the smallest one and add the differnce between them
        //to the minimum sum overall
        //for example if we take 1 dog walker, than the minmum sum will be the differnce between
        //the biggest dog to the smallest one
        minimumSum = dogSizes[N - 1] - dogSizes[0];
        //from now on we will decrease the minmum sum by substarcting the biggest diffrences in our vector
        //we already "used" the first and the last dog (i=1 & i<=K-1)
        //for example if we take 2 dog walkers with dog size: 20,30,40,41,50 , than the the optical arrangment
        //will be : {20,30} ,{40,41,50} and the minimum sum will be 10+10=20
        //so we will start from the end , we'll take 50-20=30 and after that we'll decrease the differnce 10
        //only one time because we have only two dog walkers and we have already used one of them
        //in general, we "don't care" about the arrangment of the dogs and the dog walkers, we only care
        //about the overall minimum sum, and because of that we should decrease the the biggest differences
        //according to the number of dog walkers.
        for (i = 1; i <= K - 1; i++)
        {
            minimumSum -= dual[N - 1 - i];
        }
        cout << minimumSum << endl;
        //reseting the vector to the next test case
        dual.clear();
    }
    return 0;
}