/*
Given an array arr of size N and an element k. The task is to find the count of elements in
the array that appear more than n/k times.

Example 1:

Input:
N = 8
arr = [3,1,2,2,1,2,3,3]
k = 4
Output:
2
Explanation:
In the given array, 3 and 2 are the only elements that appears more than n/k times.
Example 2:

Input:
N = 4
arr = [2,3,3,2]
k = 3
Output:
2
Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.
*/
#include <bits/stdc++.h>
using namespace std;
int countOccurence(int arr[], int n, int k)
{
    // Your code here
    unordered_map<int, int> umap;
    int val = n / k;
    // Storing array element as key and their count as value in unordered map:
    for (int i = 0; i < n; i++)
    {
        umap[arr[i]]++;
    }
    // traversing through map and checking if value of key is > n/k?
    // if yes then increment count by 1:
    int cnt = 0;
    for (auto i : umap)
    {
        if (i.second > val)
        {
            cnt += 1;
        }
    }
    return cnt;
}
int main()
{
    int a[] = {2, 3, 3, 2};
    int n = 4, k = 3;
    int c = countOccurence(a, n, k);
    cout << c;
}