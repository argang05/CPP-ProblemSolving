/*
A permutation of an array of integers is an arrangement of its members into a sequence or
linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3],
[1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].The next permutation of an array of
integers is the next lexicographically greater permutation of its integer. More formally,
if all the permutations of the array are sorted in one container according to their
lexicographical order, then the next permutation of that array is the permutation that
follows it in the sorted container. If such arrangement is not possible, the array must be
rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a
lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.

Example 1:

Input: nums = [1,2,3]
Output: [1,3,2]
Example 2:

Input: nums = [3,2,1]
Output: [1,2,3]
Example 3:

Input: nums = [1,1,5]
Output: [1,5,1]
*/
#include <bits/stdc++.h>
using namespace std;
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int ind = -1; // breakpoint index
    // Find the breakpoint or dip and store the index in 'ind':
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            ind = i;
            break;
        }
    }
    // If breakpoint is not found that means its last possible permutations
    // Hence just reverse it;
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    // If breakpoint is found find the next bigger element than left element of
    // Breakpoint and swap it:
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }
    // Reverse the element after the breakpoint to get the next permutation:
    reverse(nums.begin() + ind + 1, nums.end());
}
int main()
{
    vector<int> nms = {1, 1, 5};
    nextPermutation(nms);
    for (auto i : nms)
    {
        cout << i << " ";
    }
}