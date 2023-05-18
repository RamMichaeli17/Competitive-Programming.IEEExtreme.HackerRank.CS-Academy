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

//Minimum Permutation
int main()
{
    //N integers corresponding to the elements of AA
    int N;
    //M integers corresponding to the elements of SS.
    int M;
    cin >> N >> M;
    int i, j = 0, k = 0;
    //array A of size N+1 , the +1 to prevent the error of leaked memory and 4/8 bytes problem
    int* A = new int[N + 1];
    for (i = 0; i < N; i++)
        cin >> A[i];
    //the last element of the array A equals to the sizes of array A and the size of S plus 1 because: "Each number from 1 to N+M occurs exactly once in either A or S."
    A[i] = N + M + 1;
    //"set" S of size M+1 , the +1 to prevent the error of leaked memory and 4/8 bytes problem 
    int* S = new int[M + 1];
    for (i = 0; i < M; i++)
    {
        cin >> S[i];
    }
    //the last element of the "set" S equals to the sizes of array A and the size of S plus 1 because: "Each number from 1 to N+M occurs exactly once in either A or S."
    S[i] = N + M + 1;
    //sorting the set
    sort(S, S + M);
    //the elements of the lexicographically smallest permutation
    int* per = new int[M + N];
    for (i = 0; i < N + M; i++)
    {
        per[i] = A[j] < S[k] ? A[j++] : S[k++];
        cout << per[i] << " ";
    }
    return 0;
}