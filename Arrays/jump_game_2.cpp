/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned
at nums[0].
Each element nums[i] represents the maximum length of a forward jump from index i. In other
words, if you are at nums[i], you can jump to any nums[i + j] where:
0 <= j <= nums[i] and i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such
that you can reach nums[n - 1].

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from
index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
*/
#include <bits/stdc++.h>
using namespace std;
int jump(vector<int> &nums)
{
    int totalJumps = 0; // stores total number for jumps.
    int n = nums.size();
    int destination = n - 1; // Destination/end index we've to reach
    // To calculate the maximum distance we can travel from i and make the window for options:
    int coverage = 0;
    // The maximum point where we are standing after considering the options in window:
    int lastIndex = 0;

    // Base Case:
    if (n == 1)
    {
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        coverage = max(coverage, i + nums[i]);

        // Make sure that we consider all options:
        if (i == lastIndex)
        {
            lastIndex = coverage;
            totalJumps++;

            // Check whether we've already reached the destination:
            if (coverage >= destination)
            {
                return totalJumps;
            }
        }
    }
    return totalJumps;
}
int main()
{
    vector<int> nms = {2, 3, 0, 1, 4};
    int numJumps = jump(nms);
    cout << numJumps;
}