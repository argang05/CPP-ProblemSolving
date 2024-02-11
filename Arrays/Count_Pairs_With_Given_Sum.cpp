/*
Given an array of N integers, and an integer K, find the number of pairs of elements in
the array whose sum is equal to K.

Example 1:

Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation:
arr[0] + arr[1] = 1 + 5 = 6
and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:

Input:
N = 4, K = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation:
Each 1 will produce sum 2 with any 1.
*/
#include <bits/stdc++.h>
using namespace std;
int getPairsCount(int arr[], int n, int k)
{
    // code here
    unordered_map<int, int> umap;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // Calculate the diffrence (b = sum - a):
        int val = k - arr[i];
        // Find 'b' in map if found update count with frequency of b:
        if (umap[val])
        {
            cnt += umap[val];
        }
        // insert element into map/ update its count:
        umap[arr[i]]++;
    }
    return cnt;
}
int main()
{
    int arr[] = {1, 1, 1, 1};
    int N = 4;
    int K = 2;
    int cnt = getPairsCount(arr, N, K);
    cout << cnt;
}