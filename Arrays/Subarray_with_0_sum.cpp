/*
Given an array of integers. Find if there is a subarray (of size at-least one) with 0 sum.
You just need to return true/false depending upon whether there is a subarray present with
 0-sum or not. Printing will be taken care by the driver code.

Example 1:

Input:
n = 5
arr = {4,2,-3,1,6}
Output:
Yes
Explanation:
2, -3, 1 is the subarray with sum 0.
Example 2:

Input:
n = 5
arr = {4,2,0,1,6}
Output:
Yes
Explanation:
0 is one of the element in the array so there exist a subarray with sum 0.
*/
#include <bits/stdc++.h>
using namespace std;
bool subArrayExists(int arr[], int n)
{
    // Your code here
    unordered_map<int, int> umap;
    // initializing count of hashmap to 1:
    umap[0] = 1;
    // initializing prefixSum to 0 & count:
    int prefSum = 0;
    for (int i = 0; i < n; i++)
    {
        // Calculate prefixSum:
        prefSum += arr[i];
        // prefSum-0 = prefSum -> Hence If prefSum is present in hashmap then return true:
        if (umap[prefSum])
        {
            return true;
        }
        // Storing prefixSum into hashmap with count:
        umap[prefSum]++;
    }
    return false;
}
int main()
{
    int a[] = {4, 2, -3, 1, 6};
    int n = 5;
    cout << subArrayExists(a, n);
}