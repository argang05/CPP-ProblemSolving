/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> majorityElement(vector<int> &nums)
{
    // Create two counters and element variable for 2 elements
    int cnt1 = 0, cnt2 = 0;
    int el1 = 0, el2 = 0;
    int n = nums.size();
    int mini = (int)(n / 3) + 1;
    vector<int> ans;

    // Traverse the loop and find the two elements that occured max times:
    for (int i = 0; i < n; i++)
    {
        // Using Moore's Voting Algorithm to Determine the two elements:
        if (cnt1 == 0 && el2 != nums[i])
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && el1 != nums[i])
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (el1 == nums[i])
        {
            cnt1++;
        }
        else if (el2 == nums[i])
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // Manually checking if the two max occuring elements are actually the majority elements:
    // 1.) Determine count of element1 and element2:
    cnt1 = 0;
    cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == nums[i])
        {
            cnt1++;
        }
        if (el2 == nums[i])
        {
            cnt2++;
        }
    }

    // 2.) Checking if count of element 1 and 2 is > n/3 if yes then push in ans vector:
    if (cnt1 >= mini && el1 != el2)
    {
        ans.push_back(el1);
    }
    if (cnt2 >= mini)
    {
        ans.push_back(el2);
    }
    return ans;
}
int main()
{
    vector<int> nms = {0, 0, 0};
    vector<int> answ = majorityElement(nms);
    for (auto i : answ)
    {
        cout << i << " ";
    }
}