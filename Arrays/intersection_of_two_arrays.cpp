/*
Given two integer arrays nums1 and nums2, return an array of their intersection.
Each element in the result must be unique and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums1 = {9, 4, 9, 8, 4};
    vector<int> nums2 = {4, 9, 5};

    // set<int> st1, st2;
    // for (auto i : nums1)
    // {
    //     st1.insert(i);
    // }
    // for (auto i : nums2)
    // {
    //     st2.insert(i);
    // }
    // for (auto i : st1)
    // {
    //     for (auto j : st2)
    //     {
    //         if (j == i)
    //         {
    //             ans.push_back(j);
    //         }
    //     }
    // }
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }
    vector<int> ans;
    unordered_set<int> uset;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    int m = nums1.size(), n = nums2.size();

    while (i < m && j < n)
    {
        if (nums1[i] == nums2[j])
        {
            uset.insert(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    for (auto i : uset)
    {
        ans.push_back(i);
        cout << i << " ";
    }
}