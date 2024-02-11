#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-23, 48, -13, 31, -12, 6, -42, 23, 14, 33, -33, -21, 0, 25, -39, -31, 3};

    // int j = nums.size() - 1;
    // while (i < j)
    // {
    //     if (nums[i] < pivot)
    //     {
    //         i++;
    //     }
    //     else if (nums[j] > pivot)
    //     {
    //         j--;
    //     }
    //     else if (i < j)
    //     {
    //         swap(nums[i++], nums[j--]);
    //     }
    // }
    int i = -1;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] < 0)
        {
            i++;
            swap(nums[i], nums[j]);
        }
    }
    for (auto i : nums)
    {
        cout << i << " ";
    }
}