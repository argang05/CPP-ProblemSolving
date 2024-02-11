/*
Given a row wise sorted matrix of size R*C where R and C are always odd, find the median of the
matrix.

Example 1:

Input:
R = 3, C = 3
M = [[1, 3, 5],
     [2, 6, 9],
     [3, 6, 9]]
Output: 5
Explanation: Sorting matrix elements gives
us {1,2,3,3,5,6,6,9,9}. Hence, 5 is median.


Example 2:

Input:
R = 3, C = 1
M = [[1], [2], [3]]
Output: 2
Explanation: Sorting matrix elements gives
us {1,2,3}. Hence, 2 is median.
*/
#include <bits/stdc++.h>
using namespace std;
#define INT_MAX 500
#define INT_MIN -500
int upperBound(vector<int> &arr, int x, int n)
{
    // Function to Calculate the very first element > x:
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
        {
            // this maybe the answer;
            ans = mid;
            high = mid - 1; // Search for even smaller towards left index where elem > x
        }
        else
        {
            low = mid + 1; // go towards right
        }
    }
    return ans;
}
int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x)
{
    // Function to Count number of elements greater than the given number x:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += upperBound(mat[i], x, m);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int R, int C)
{
    // code here
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < R; i++)
    {
        // Determine Appropriate value of low (smallest in 0th column)
        // and high (largest value in (C-1)th column)
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][C - 1]);
    }
    int req = (R * C) / 2; // countSmaller value should be greater than req
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, R, C, mid);
        if (smallEqual <= req)
        {
            // if smallEqual is less than equal to req then go search in right half:
            low = mid + 1;
        }
        else
        {
            // if smallEqual is greater tahn req then go search in left half:
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    vector<vector<int>> mt = {{1}, {2}, {3}};
    int n = 3, m = 1;
    int med = median(mt, n, m);
    cout << med;
}