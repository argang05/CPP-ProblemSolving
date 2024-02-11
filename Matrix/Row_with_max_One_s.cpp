/*
Given a boolean 2D array of n x m dimensions, consisting of only 1's and 0's, where each row
is sorted. Find the 0-based index of the first row that has the maximum number of 1's.

Example 1:

Input:
N = 4 , M = 4
Arr[][] = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}}
Output: 2
Explanation: Row 2 contains 4 1's (0-based
indexing).

Example 2:

Input:
N = 2, M = 2
Arr[][] = {{0, 0}, {1, 1}}
Output: 1
Explanation: Row 1 contains 2 1's (0-based
indexing).
*/
#include <bits/stdc++.h>
using namespace std;
int lowerBound(vector<int> &a, int n, int x)
{
    // Function to find first occurence of x:
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] >= x)
        {
            // a[mid] might be the ans:
            ans = mid;
            // Search for smaller index on left:
            high = mid - 1;
        }
        else
        {
            // Search towards right:
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int maxCount = 0; // Variable to store maximum number of 1s row wise.
    int rowIndex = -1;
    // Only perform operations on each row:
    for (int i = 0; i < n; i++)
    {
        // Find index of first occurence of 1:
        int firstOccurenceIndexOf1 = lowerBound(arr[i], m, 1);
        // Count number of 1s using formula:
        int numOf1s = m - firstOccurenceIndexOf1;
        if (numOf1s > maxCount)
        {
            // If number Of 1s is greater then maxCount then update maxCount and rowIndex:
            maxCount = numOf1s;
            rowIndex = i;
        }
    }
    return rowIndex;
}
int main()
{
    vector<vector<int>> a = {{0, 1, 1, 1},
                             {0, 0, 1, 1},
                             {1, 1, 1, 1},
                             {0, 0, 0, 0}};
    int n = 4, m = 4;
    int row = rowWithMax1s(a, n, m);
    cout << row;
}