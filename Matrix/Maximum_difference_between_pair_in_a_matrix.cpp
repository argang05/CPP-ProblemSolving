/*
Given an N x N matrix, mat[N][N] of integers. The task is to find the maximum value
of mat(c, d) mat(a, b) over all choices of indexes such that both c > a and d > b.

Example 1:

Input:
mat[N][N] = {{ 1, 2, -1, -4, -20 },
             { -8, -3, 4, 2, 1 },
             { 3, 8, 6, 1, 3 },
             { -4, -1, 1, 7, -6 },
             { 0, -4, 10, -5, 1 }};
Output: 18
Explanation: The maximum value is 18 as mat[4][2]
- mat[1][0] = 18 has maximum difference.
*/
#include <bits/stdc++.h>
using namespace std;
int findMaxValue(vector<vector<int>> &mat, int n)
{
    // Write your code here

    vector<vector<int>> compute(n, vector<int>(n, 0)); // PreComputeMatrix

    // Computing & Storing Values into PreComputeMatrix:
    compute[n - 1][n - 1] = mat[n - 1][n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        // Computing & Storing right and bottom max elements in PreComputeMatrix
        compute[n - 1][i] = max(compute[n - 1][i + 1], mat[n - 1][i]);
        compute[i][n - 1] = max(compute[i + 1][n - 1], mat[i][n - 1]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            // Storing max of Right_Maximum , Bottom_Maximum (from PreComputeMatrix)
            // and Current element (from Input matrix):
            int maxOfRightAndBottomMax = max(compute[i + 1][j], compute[i][j + 1]);
            compute[i][j] = max(maxOfRightAndBottomMax, mat[i][j]);
        }
    }

    int ans = INT_MIN;
    // Finding the maximum difference:
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            // Current element of Input matrix:
            int currElem = mat[i][j];

            // Corresponding nearest diagonal element of PreComputeMatrix:
            int diagonalElem = compute[i + 1][j + 1];

            // Calculating difference between diagonal and current element:
            int diff = diagonalElem - currElem;

            // Maximise the Difference:
            ans = max(ans, diff);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mt = {{1, 2, -1, -4, -20},
                              {-8, -3, 4, 2, 1},
                              {3, 8, 6, 1, 3},
                              {-4, -1, 1, 7, -6},
                              {0, -4, 10, -5, 1}};
    int n = 5;
    int maxVal = findMaxValue(mt, n);
    cout << maxVal;
}