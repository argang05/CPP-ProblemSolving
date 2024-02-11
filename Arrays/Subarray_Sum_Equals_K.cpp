/*
Given an array of integers nums and an integer k, return the total number of subarrays \
whose sum equals to k. A subarray is a contiguous non-empty sequence of elements within an
array.

Example 1:

Input: nums = [1,1,1], k = 2
Output: 2
Example 2:

Input: nums = [1,2,3], k = 3
Output: 2
*/
#include <bits/stdc++.h>
using namespace std;
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> umap;
    // initializing count of hashmap to 1:
    umap[0] = 1;
    // initializing prefixSum to 0 & count:
    int prefSum = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // Calculate prefixSum:
        prefSum += nums[i];
        // Calculate prefSum-k:
        int remove = prefSum - k;
        // Count the number of prefSum-k present using hashmap:
        cnt += umap[remove];
        // Storing prefixSum into hashmap with count:
        umap[prefSum]++;
    }
    return cnt;
}
int main()
{
    vector<int> nms = {1, 1, 1};
    int s = 2;
    int cnt = subarraySum(nms, s);
    cout << cnt;
}