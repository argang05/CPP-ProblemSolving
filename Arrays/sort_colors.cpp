/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so
that objects of the same color are adjacent, with the colors in the order red, white, and
blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue,
respectively.

You must solve this problem without using the library's sort function.
Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
*/
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int size, int s, int e)
{
    int start_elem = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= start_elem)
        {
            cnt++;
        }
    }
    int pivot_index = s + cnt;

    swap(arr[s], arr[pivot_index]);

    int i = s, j = e;
    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] <= arr[pivot_index])
        {
            i++;
        }
        while (arr[j] > arr[pivot_index])
        {
            j--;
        }
        if (i < pivot_index && j > pivot_index)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivot_index;
}

void quickSort(vector<int> &arr, int size, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int p = partition(arr, size, s, e);
    quickSort(arr, size, s, p - 1);
    quickSort(arr, size, p + 1, e);
}
int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    int size = nums.size();
    quickSort(nums, size, 0, size - 1);
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}