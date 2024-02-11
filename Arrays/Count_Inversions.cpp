/*
Given an array of integers. Find the Inversion Count in the array.

Inversion Count: For an array, inversion count indicates how far (or close) the array is
from being sorted. If the array is already sorted then the inversion count is 0.
If an array is sorted in the reverse order then the inversion count is the maximum.
Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

Example 1:

Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5
has three inversions (2, 1), (4, 1), (4, 3).
Example 2:

Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already
sorted so there is no inversion count.
Example 3:

Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array
are same, so there is no inversion count.
*/
#include <bits/stdc++.h>
using namespace std;
int merge(long long arr[], int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int cnt = 0;
    int k = 0;
    long long temp[high + 1];
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp[k++] = arr[left++];
        }
        else
        {
            temp[k++] = arr[right++];
            cnt += (mid - left + 1);
        }
    }
    while (left <= mid)
    {
        temp[k++] = arr[left++];
    }
    while (right <= high)
    {
        temp[k++] = arr[right++];
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return cnt;
}
int mergeSort(long long arr[], int low, int high)
{
    int c = 0;
    if (low >= high)
    {
        return c;
    }
    int mid = low + (high - low) / 2;
    c += mergeSort(arr, low, mid);
    c += mergeSort(arr, mid + 1, high);
    c += merge(arr, low, mid, high);
    return c;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    return mergeSort(arr, 0, N - 1);
}
int main()
{
    long long arr[] = {10, 10, 10};
    long long N = 3;
    int ct = inversionCount(arr, N);
    cout << ct;
}