/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    int left = 0;              // leftmost pointer
    int right = colCount - 1;  // rightmost pointer
    int top = 0;               // topmost pointer
    int bottom = rowCount - 1; // bottommost pointer
    vector<int> ans;

    // Keep iterating untill there are any row(s) or column(s) left to be traversed:
    while (left <= right && top <= bottom)
    {
        // 1.) Left to right traversal (top constant):
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++; // increment top to avoid duplicacy.

        // 2.) Top to Bottom traversal (right constant):
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]); // Vertical traversal
        }
        right--; // decrement right to avoid duplicacy.

        // 3.) Right to Left traversal (bottom constant):
        if (top <= bottom)
        {
            // If there are any more rows left:
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--; // decrement bottom to avoid duplicacy.
        }

        // 4.) Bottom to Top traversal (left constant):
        if (left <= right)
        {
            // If there is any more columns left:
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]); // Vertical traversal
            }
            left++; // increment left to avoid duplicacy.
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> answ = spiralOrder(mat);
    for (auto i : answ)
    {
        cout << i << " ";
    }
}