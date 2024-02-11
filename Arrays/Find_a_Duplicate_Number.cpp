/*
Given an array of integers nums containing n + 1 integers where each integer is in the
range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra
space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
*/
#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = 0, fast = 0;
    // Move slow and fast pointers with ith nums value as the next index.
    // And move fast pointer move faster than slow pointer until they meet.
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // If they meet that means there is a cycle (presence of duplicate element).
    // Find the starting point of the cycle.
    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    // Return value of starting point of cycle aka the duplicate element.
    return slow;
}
int main()
{
    vector<int> nms = {3, 1, 3, 4, 2};
    int dup = findDuplicate(nms);
    cout << dup;
}