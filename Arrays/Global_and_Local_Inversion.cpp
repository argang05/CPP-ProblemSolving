/*
You are given an integer array nums of length n which represents a permutation of all the
integers in the range [0, n - 1].

The number of global inversions is the number of the different pairs (i, j) where:

0 <= i < j < n
nums[i] > nums[j]
The number of local inversions is the number of indices i where:

0 <= i < n - 1
nums[i] > nums[i + 1]
Return true if the number of global inversions is equal to the number of local inversions.

Example 1:

Input: nums = [1,0,2]
Output: true
Explanation: There is 1 global inversion and 1 local inversion.
Example 2:

Input: nums = [1,2,0]
Output: false
Explanation: There are 2 global inversions and 1 local inversion.
*/
/*
-> We can observe by the question that all local inversions are global inversions but
all global inversions are not local inversion.

->So we have to only find an inversion which is global but not local that means the greater
element must not be present in the next index.
*/
#include <bits/stdc++.h>
using namespace std;
bool isIdealPermutation(vector<int> &nums)
{
    int maxi = -1, n = nums.size();
    if (n == 1)
    {
        return false;
    }
    for (int i = 0; i < n - 2; i++)
    {
        maxi = max(maxi, nums[i]);
        // If inversion is global but not local:
        if (maxi > nums[i + 2])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    vector<int> nms = {1, 2, 0};
    bool isValidPermutation = isIdealPermutation(nms);
    cout << isValidPermutation;
}