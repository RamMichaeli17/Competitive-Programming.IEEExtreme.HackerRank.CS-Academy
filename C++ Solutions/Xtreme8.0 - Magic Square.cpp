#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


//Xtreme8.0 - Magic Square
int main() {
    //First line: N,the size of the square (1 <= N <= 600)
    int N;
    cin >> N;
    //Next N lines: The square, N space separated integers pre line, representing the entries per each row of the square
    int** M = new int* [N + 1];
    //First line: N 
    M[0] = new int[1];
    M[0][0] = N;
    int i, j;
    //vector of the answer
    vector<int> a;
    int sum_of_main_diagonal = 0, sum_of_antidiagonal = 0;
    //to sum the rows of the square
    int sumRows = 0;
    //to sum the cols of the square
    int sumCols = 0;
    //array of sums of the rows with size N 
    int* rows = new int[N];
    //array of sums of the cols with size N 
    int* cols = new int[N];
    //filling the square
    for (i = 1; i < N + 1; i++) {
        M[i] = new int[N];
        for (j = 0; j < N; j++) {
            cin >> M[i][j];
        }
    }
    //calculating the sum of the diagonals
    for (i = 1; i < N + 1; i++)
    {
        //main diagonal - meaning the diagonal that leads from the top-left corner towards bottom-right corner
        sum_of_main_diagonal += M[i][i - 1];
        //antidiagonal - meaning the diagonal that leads from top-right corner towards bottom-left corner
        sum_of_antidiagonal += M[i][N - i];
    }
    //if there is a difference with the sum of the main diagonal so value 0 corresponding to the antidiagonal should be reported.
    if (sum_of_antidiagonal != sum_of_main_diagonal)
        a.push_back(0);
    //Calculating the sums of the rows and adding them to an array
    for (i = 1; i < N + 1; i++)
    {
        sumRows = 0;
        for (j = 0; j < N; j++)
            sumRows += M[i][j];
        rows[i - 1] = sumRows;
    }
    //Calculating the sums of the cols and adding them to an array
    for (i = 0; i < N; i++)
    {
        sumCols = 0;
        for (j = 1; j < N + 1; j++)
            sumCols += M[j][i];
        cols[i] = sumCols;
    }
    //if the lines do not sum up to the sum of the main diagonal , add them to the to suitable array
    for (i = 0; i < N; i++)
    {
        if (sum_of_main_diagonal != rows[i])
            a.push_back(i + 1);
        if (sum_of_main_diagonal != cols[i])
            a.push_back(-i - 1);
    }
    //A sorted (in incremental order ) list of the lines that do not sum up to the sum of the main diagonal.
    sort(a.begin(), a.end());
    //If the Square is magic, the program should output 0 (no answers have been added to the a vector)
    if (a.size() == 0)
        cout << "0" << endl;
    else
        //Next M lines: A sorted (in incremental order ) list of the lines that do not sum up to the
        //sum of the main diagonal. The rows are numbered 1,2,,N; the columns are numbered
        //-1,-2,,-N; and the antidiagonal is numbered zero
    {
        cout << a.size() << endl;
        for (i = 0; i < a.size(); i++)
            cout << a[i] << endl;
    }
    return 0;
}


