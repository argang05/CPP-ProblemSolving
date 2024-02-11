/*
Given two arrays a[] and b[] of size n and m respectively. The task is to find the number
of elements in the union between these two arrays.

Union of the two arrays can be defined as the set containing distinct elements from both
the arrays. If there are repetitions, then only one occurrence of element should be printed
in the union.

Note : Elements are not necessarily distinct.

Example 1:

Input:
5 3
1 2 3 4 5
1 2 3
Output:
5
Explanation:
1, 2, 3, 4 and 5 are the
elements which comes in the union set
of both arrays. So count is 5.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {85, 25, 1, 32, 54, 6};
    vector<int> b = {85, 2};
    int m = a.size();
    int n = b.size();
    unordered_set<int> uset;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        uset.insert(a[i++]);
        uset.insert(b[j++]);
    }
    while (i < m)
    {
        uset.insert(a[i++]);
    }
    while (j < n)
    {
        uset.insert(b[j++]);
    }

    int cnt = uset.size();
    cout << cnt;
}