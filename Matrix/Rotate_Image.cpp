/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees
(clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix
directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example 2:

Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/
#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    // Step 1: Transpose The Matrix:
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            // Only traverse the upper triangle above the diagonal:
            // Swap the a[i][j]th  element with a[j][i]th element:

            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Step 2: Reverse each Row of the Transposed Matrix:
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}
int main()
{
    vector<vector<int>> mat = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(mat);
    for (auto i : mat)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
}
