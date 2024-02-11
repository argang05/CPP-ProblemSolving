/*
Given an array arr of n positive integers and a number k. One can apply a swap operation on the
array any number of times, i.e choose any two index i and j (i < j) and swap arr[i] , arr[j] .
Find the minimum number of swaps required to bring all the numbers less than or equal to k
together, i.e. make them a contiguous subarray.

Example 1:

Input :
arr[ ] = {2, 1, 5, 6, 3}
K = 3
Output :
1
Explanation:
To bring elements 2, 1, 3 together,
swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be-
arr[] = {2, 1, 3, 6, 5}

Example 2:

Input :
arr[ ] = {2, 7, 9, 5, 8, 7, 4}
K = 6
Output :
2
Explanation:
To bring elements 2, 5, 4 together,
swap index 0 with 2 (0-based indexing)
and index 4 with 6 (0-based indexing)
such that final array will be-
arr[] = {9, 7, 2, 5, 4, 7, 8}
*/
#include <bits/stdc++.h>
using namespace std;
int minSwap(int arr[], int n, int k)
{
    // variable to calculate no. of elements <= k for window size:
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            cnt += 1;
        }
    }

    // variable to store no. of elements in a window which are <= k:
    int currentWindow = 0;

    // Calculating for the first window:
    for (int i = 0; i < cnt; i++)
    {
        if (arr[i] <= k)
        {
            currentWindow += 1;
        }
    }
    // variable to store min no. of swaps required:
    int ans = cnt - currentWindow;

    // Sliding the window to find best subarray option and min no. of swaps required:
    for (int i = cnt; i < n; i++)
    {
        // if new element in window is <= k then increment currWindow:
        if (arr[i] <= k)
        {
            currentWindow += 1;
        }
        // if discarded element from window is <= k then decrement currWindow:
        if (arr[i - cnt] <= k)
        {
            currentWindow -= 1;
        }
        // Minimise the answer:
        ans = min(ans, (cnt - currentWindow));
    }
    return ans;
}
int main()
{
    int a[] = {2, 7, 9, 5, 8, 7, 4};
    int n = 7, k = 6;
    int minSp = minSwap(a, n, k);
    cout << minSp;
}