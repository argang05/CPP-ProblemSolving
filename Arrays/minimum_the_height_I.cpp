/*
Given an array arr[] denoting heights of N towers and a positive integer K, you have to
modify the height of each tower either by increasing or decreasing them by K only once.
Find out what could be the possible minimum difference of the height of shortest and
longest towers after you have modified each tower.
Note: Assume that height of the tower can be negative.
A slight modification of the problem can be found here.

Example 1:

Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as
{3, 3, 6, 8}. The difference between
the largest and the smallest is 8-3 = 5.

Example 2:

Input:
K = 3, N = 5
Arr[] = {3, 9, 12, 16, 20}
Output:
11
Explanation:
The array can be modified as
{6, 12, 9, 13, 17}. The difference between
the largest and the smallest is 17-6 = 11.
*/

#include <bits/stdc++.h>
using namespace std;
int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int mini = arr[0];
    int maxi = arr[n - 1];
    int smallest_element = arr[0] + k;
    int largest_element = arr[n - 1] - k;

    for (int i = 1; i < n; i++)
    {
        // Checking every element (until (n-2)th elemnt) by adding k to find best candidate
        // for tallest tower:
        maxi = max(largest_element, arr[i - 1] + k);
        // Checking every element by subtarcting k to find best candidate for shortest tower:
        mini = min(smallest_element, arr[i] - k);
        // Update the minimum difference between tallest and shortest tower:
        ans = min(ans, (maxi - mini));
    }
    return ans;
}
int main()
{
    int arr[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};
    int n = 10;
    int k = 5;
    int minDf = getMinDiff(arr, n, k);
    cout << minDf;
}