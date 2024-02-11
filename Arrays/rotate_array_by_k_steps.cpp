/*
Given an integer array nums, rotate the array to the right by k steps, where k is
non-negative.

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation:
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/
#include <bits/stdc++.h>
using namespace std;
void reverse(vector<int> &nums, int low, int high)
{
    while (low < high)
    {
        swap(nums[low++], nums[high--]);
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    int sz = nums.size();
    int end_index = sz - 1;
    // Calculate k modulo size to handle test cases where k value is greater than size value:
    k = k % sz;
    // Reverse the first half (from 0 uptill end_index - k):
    reverse(nums, 0, end_index - k);
    // Reverse the second half (from size - k uptill end_index):
    reverse(nums, sz - k, end_index);
    // Reverse the whole resultant vector (from 0 to end_index):
    reverse(nums, 0, end_index);
    for (auto i : nums)
    {
        cout << i << " ";
    }
}