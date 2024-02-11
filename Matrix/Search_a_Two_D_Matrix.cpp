/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/
#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0;          // low index of 2D flattened to 1D version
    int high = n * m - 1; // high index of 2D flattened to 1D version
    // Binary Search Operation:
    while (low <= high)
    {
        // mid index of 2D flattened to 1D version
        int mid = (low + high) / 2;
        // 2D coordinates of mid:
        int rowNum = mid / m;
        int colNum = mid % m;

        if (target == matrix[rowNum][colNum])
        {
            return true;
        }
        else if (target > matrix[rowNum][colNum])
        {
            // make changes to 1D version's mid as 2D coordinates will be calculated above:
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> mat = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int tar = 13;
    if (searchMatrix(mat, tar))
    {
        cout << "Found!";
    }
    else
    {
        cout << "Not Found!";
    }
}