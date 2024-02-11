/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order,
return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).

Example 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Example 2:

Input: matrix = [[-5]], k = 1
Output: -5
*/
#include <bits/stdc++.h>
using namespace std;
int counter(vector<vector<int>> &mat, int mid)
{
    // Function to count number of elements <= mid:
    int rows = mat.size();
    int cols = rows;
    int cnt = 0;

    for (int i = 0; i < rows; i++)
    {
        // Run the j loop in reverse and find the first element 'x' which is <= mid for each row:
        // The count will be no. of all elements on left of 'x' for that row:
        for (int j = cols - 1; j >= 0; j--)
        {
            if (mat[i][j] <= mid)
            {
                cnt += j + 1;
                break;
            }
        }
    }
    return cnt;
}
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int rowCount = matrix.size();
    int colCount = rowCount;

    int low = matrix[0][0];                        // low is the smallest element in matrix initially:
    int high = matrix[rowCount - 1][colCount - 1]; // high is the largest element in matrix initially:

    // Perform Binary Search Until low becomes = high:
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int count = counter(matrix, mid);
        if (count >= k)
        {
            // If the count is greater than or equal to k
            // then update high as mid:
            high = mid;
        }
        else
        {
            // If the count is lesser than k
            // then update low as mid+1:
            low = mid + 1;
        }
    }
    // Return low as it stores the answer after binary search operation:
    return low;
}
int main()
{
    vector<vector<int>> m = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    int kthsmall = kthSmallest(m, k);
    cout << kthsmall;
}