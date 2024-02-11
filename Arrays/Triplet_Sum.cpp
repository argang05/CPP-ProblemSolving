/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    // Sort the vector:
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        // if i is not 0 and a[i] is equal to previous element then 'continue' to avoid duplicacy:
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        // Otherwise initial j & k pointers to start operations:
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            // Calculate triplet sum:
            int sum = nums[i] + nums[j] + nums[k];
            // if sum is -ve -> j++:
            if (sum < 0)
            {
                j++;
            }
            // otherwise if sum is +ve -> k--:
            else if (sum > 0)
            {
                k--;
            }
            // if sum = 0 -> store the triplet and update j & k:
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                // update j and k until both have a new unique element:
                while (j < k && nums[j] == nums[j - 1])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nms = {0, 0, 0};
    vector<vector<int>> answ = threeSum(nms);
    for (auto i : answ)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
}