/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume
that the majority element always exists in the array.

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums)
{
    // Maintain counter variable and element variable for the max occuring element:
    int n = nums.size();
    int mini = (int)(n / 2) + 1;
    int cnt = 0;
    int el;

    // Using Moore's Voting Algo to find max occuring element:
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            el = nums[i];
        }
        else if (el == nums[i])
        {
            cnt += 1;
        }
        else
        {
            cnt -= 1;
        }
    }

    // Determining that the max occuring element is actually the majority element or not:
    // 1.) Storing count of max occuring element:
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (el == nums[i])
        {
            cnt += 1;
        }
    }
    // 2.) Verifying if its occuring more that n/2 times:
    if (cnt >= mini)
    {
        return el;
    }
}
int main()
{
    vector<int> nms = {2, 2, 1, 1, 1, 2, 2};
    int maj = majorityElement(nms);
    cout << maj;
}