/*
Given an NxN matrix Mat. Sort all elements of the matrix.

Example 1:

Input:
N=4
Mat=[[10,20,30,40],
[15,25,35,45]
[27,29,37,48]
[32,33,39,50]]
Output:
10 15 20 25
27 29 30 32
33 35 37 39
40 45 48 50
Explanation:
Sorting the matrix gives this result.
Example 2:

Input:
N=3
Mat=[[1,5,3],[2,8,7],[4,6,9]]
Output:
1 2 3
4 5 6
7 8 9
Explanation:
Sorting the matrix gives this result.
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    // code here
    vector<int> elems;
    // Store all elements in 1D vector
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            elems.push_back(Mat[i][j]);
        }
    }
    // Sort The 1D vector:
    sort(elems.begin(), elems.end());
    int curr = 0;

    // Store the sorted elements of 1D vector into mat:
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = elems[curr];
            curr++;
        }
    }
    return Mat;
}
int main()
{
    vector<vector<int>> m = {{10, 20, 30, 40},
                             {15, 25, 35, 45},
                             {27, 29, 37, 48},
                             {32, 33, 39, 50}};
    int n = 4;
    vector<vector<int>> ans = sortedMatrix(n, m);
    for (auto i : ans)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << "]" << endl;
    }
}