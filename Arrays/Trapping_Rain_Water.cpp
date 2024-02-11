/*
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array
[0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
*/
#include <bits/stdc++.h>
using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    // Maintain left and right pointers to traverse height of left and right half towers:
    int left = 0, right = n - 1;
    int ans = 0;
    // Maintain leftMax and rightMax for storing max height of left and right half towers:
    int leftMax = 0, rightMax = 0;
    // Terminate traversal when left > right:
    while (left <= right)
    {
        // Perform operation on left half if the height at left is lesser or equal to right.
        // Otherwise perform operations on right
        if (height[left] <= height[right])
        {
            // Update leftMax with max height on left half
            if (height[left] >= leftMax)
            {
                leftMax = height[left];
            }
            else
            {
                // If left pointer height is lesser than leftMax that means their is a gap to store water:
                ans += (leftMax - height[left]);
            }
            left++;
        }
        else
        {
            // Update rightMax with max height on right half
            if (height[right] >= rightMax)
            {
                rightMax = height[right];
            }
            else
            {
                // If left pointer height is lesser than leftMax that means their is a gap to store water:
                ans += (rightMax - height[right]);
            }
            right--;
        }
    }
    return ans;
}
int main()
{
    vector<int> ht = {4, 2, 0, 3, 2, 5};
    int cntRW = trap(ht);
    cout << cntRW;
}