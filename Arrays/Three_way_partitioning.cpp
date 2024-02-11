/*
Given an array of size n and a range [a, b]. The task is to partition the array around the
range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the
modified array.

Note: The generated output is 1 if you modify the given array successfully.

Example 1:

Input:
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.


Example 2:

Input:
n = 3
A[] = {1, 4, 3, 6, 2, 1}
[a, b] = [1, 3]
Output: 1
Explanation: One possible arrangement
is: {1, 3, 2, 1, 4, 6}. If you return a valid
arrangement, output will be 1.
*/
#include <bits/stdc++.h>
using namespace std;
void threeWayPartition(vector<int> &array, int a, int b)
{
    // code here
    int n = array.size();
    int curr = 0;    // pointer of current element
    int start = 0;   // pointer to take care of values < a
    int end = n - 1; // pointer to take care of values > b
    // current element pointer goes till end pointer:
    while (curr <= end)
    {
        if (array[curr] < a)
        {
            swap(array[curr], array[start]);
            curr++;
            start++;
        }
        else if (array[curr] >= a && array[curr] <= b)
        {
            curr++;
        }
        else if (array[curr] > b)
        {
            swap(array[curr], array[end]);
            end--;
        }
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 3, 4};
    int a = 1, b = 2;
    threeWayPartition(arr, a, b);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}