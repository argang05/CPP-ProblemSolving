#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Approach 1:
    vector<int> nums = {-3, 0, 1, -2};
    int suffix_prod = 1, prefix_prod = 1;
    int maxi = -200000;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        if (prefix_prod == 0)
        {
            prefix_prod = 1;
        }
        if (suffix_prod == 0)
        {
            suffix_prod = 1;
        }
        prefix_prod *= nums[i];
        suffix_prod *= nums[size - i - 1];
        maxi = max(maxi, max(prefix_prod, suffix_prod));
    }
    cout << maxi << endl;

    // Approach 2:
    int ans = nums[0];
    int ma = ans, mi = ans;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            swap(ma, mi);
        }
        ma = max(nums[i], ma * nums[i]);
        mi = min(nums[i], mi * nums[i]);
        ans = max(ma, ans);
    }
    cout << ans;
}