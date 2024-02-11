/*
Given an unsorted array of integers nums, return the length of the longest consecutive
elements sequence.
You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
*/
#include <bits/stdc++.h>
using namespace std;
int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    // if no elements in vector, return 0.
    if (n == 0)
    {
        return 0;
    }
    int longest = 1; // to store length of LCS
    unordered_set<int> uset;
    // Store all vector elements in set:
    for (int i = 0; i < n; i++)
    {
        uset.insert(nums[i]);
    }
    // Traversing through set:
    for (auto it : uset)
    {
        // Check if the current element has not consecutive smaller element
        // i.e its starting point of a consecutive subsequence:
        if (uset.find(it - 1) == uset.end())
        {
            int cnt = 1;
            int x = it;
            // Increment count until there is no larger consecutive element
            while (uset.find(x + 1) != uset.end())
            {
                cnt += 1;
                x += 1;
            }
            // Find LCS:
            longest = max(longest, cnt);
        }
    }
    return longest;
}
int main()
{
    vector<int> nms = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int ln = longestConsecutive(nms);
    cout << ln;
}