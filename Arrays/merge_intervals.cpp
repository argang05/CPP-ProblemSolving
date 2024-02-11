/*
Given an array of intervals where intervals[i] = [starti, endi], merge all
overlapping intervals, and return an array of the non-overlapping intervals that cover all
the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < n; i++)
    {
        // If Non-Overlapping or if ans vector is Empty then push the interval vector element:
        if (ans.empty() || intervals[i][0] > ans.back()[1])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            // If Overlapping then update interval element in ans accordingly:
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}}; //{1, 3}, {2, 6}, {8, 10}, {15, 18} //{1, 4}, {0, 0}
    vector<vector<int>> answer = merge(intervals);
    for (auto i : answer)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << "], ";
    }
    return 0;
}