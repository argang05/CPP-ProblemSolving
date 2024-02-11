/*
You are given an integer array nums. You are initially positioned at the array's first
index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
*/

/*
Solution:

--> We will be maintaing a reachable index which will store the max reachability
index by adding nums[i] + i.

--> If our i becomes > reachable index that means we've encontered a 0 max length jump
point and cannot reach the end of array.

--> If not and we succesfully run through all array elements by updating our reachable index,
our reachable index will evaluate to the last index and we can return true.

*/
#include <bits/stdc++.h>
using namespace std;
bool canJump(vector<int> &nums)
{
    int reachableIndex = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > reachableIndex)
        {
            return false;
        }
        reachableIndex = max(reachableIndex, i + nums[i]);
    }
    return true;
}
int main()
{
    vector<int> nms = {3, 2, 1, 0, 4};
    bool ans = canJump(nms);
    cout << ans;
}
