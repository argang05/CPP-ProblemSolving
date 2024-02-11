/*
Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
Merge them in sorted order without using any extra space. Modify arr1 so that it contains
the first N elements and modify arr2 so that it contains the last M elements.

Example 1:

Input:
n = 4, arr1[] = [1 3 5 7]
m = 5, arr2[] = [0 2 6 8 9]
Output:
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two
non-decreasing arrays, we get,
0 1 2 3 5 6 7 8 9.
Example 2:

Input:
n = 2, arr1[] = [10 12]
m = 3, arr2[] = [5 18 20]
Output:
arr1[] = [5 10]
arr2[] = [12 18 20]
Explanation:
After merging two sorted arrays
we get 5 10 12 18 20.
*/
#include <bits/stdc++.h>
using namespace std;
void swapIfGreater(long long arr1[], long long arr2[], int idx1, int idx2)
{
    if (arr1[idx1] > arr2[idx2])
    {
        swap(arr1[idx1], arr2[idx2]);
    }
}
void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here
    int len = n + m;
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            // left index in arr1 & right index in arr2:
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // left and right both indices in arr2:
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // left and right both indices in arr1:
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }
}
int main()
{
    long long arr1[] = {5, 10};
    long long arr2[] = {12, 18, 20};
    int n = 2;
    int m = 3;
    merge(arr1, arr2, n, m);
    for (int i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i : arr2)
    {
        cout << i << " ";
    }
}