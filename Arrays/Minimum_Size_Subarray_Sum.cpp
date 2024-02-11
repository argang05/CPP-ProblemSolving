/*
Given an array of positive integers nums and a positive integer target, return the minimal
length of a subarray whose sum is greater than or equal to target. If there is no such
subarray, return 0 instead.

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/
#include <bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();
    // Left and right pointer to form variable sliding window:
    int left = 0, right = 0;
    int sum = 0;
    // var to keep track of shortest subarray with sum >= target:
    int shortest = 1000000;

    // Implementing variable size sliding window algorithm:
    while (right < n)
    {
        // add the current element (from right) to sum:
        sum += nums[right];

        if (sum >= target)
        {
            // if sum >= target then try to compress the window from left
            // and find the min length of window till sum >= target
            // Also decrement the element at left pointer
            while (sum >= target)
            {
                sum -= nums[left];
                left++;
            }
            // Update shortest with minimum length of subarray with sum >= target:
            shortest = min(shortest, (right - left + 2));
        }
        // if sum < target keep incrementing right pointer
        right++;
    }
    // If shortest has the initial INT_MAX value then return 0 otherwise return the updated shortest:
    if (shortest == 1000000)
    {
        shortest = 0;
    }
    return shortest;
}
int main()
{
    vector<int> nms = {1, 1, 1, 1, 1, 1, 1, 1};
    int tar = 11;
    int minLen = minSubArrayLen(tar, nms);
    cout << minLen;
}