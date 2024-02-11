/*
Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // multiset<int> mst;
    // int nums[] = {3, 2, 1, 5, 6, 4};
    // int size = 6;
    // int k = 2;
    // for (int i = 0; i < size; i++)
    // {
    //     mst.insert(nums[i]);
    // }
    // auto it = mst.end();
    // for (int i = 1; i <= k; i++)
    // {
    //     it--;
    // }
    // int elem = *(it);
    // cout << elem;

    priority_queue<int> maxi;
    int nums[] = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int size = 9;
    int k = 4;
    for (auto i : nums)
    {
        maxi.push(i);
    }
    for (int i = 1; i < k; i++)
    {
        maxi.pop();
    }
    int elem = maxi.top();
    cout << elem;
    return 0;
}
