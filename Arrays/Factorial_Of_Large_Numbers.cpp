/*
Given an integer N, find its factorial. return a list of integers denoting the digits that
make up the factorial of N.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> factorial(int N)
{
    vector<int> ans;
    ans.push_back(1); // Bcz min value of N is 1:
    // 1 is already considered, need to operate from 2:
    for (int x = 2; x <= N; x++)
    {
        int carry = 0;
        // traverse through each element of ans vector:
        for (int i = 0; i < ans.size(); i++)
        {
            // Calculate single digit multiplication result:
            int val = ans[i] * x + carry;
            // Store only the digit in units place in ith position ans vector:
            ans[i] = val % 10;
            // Calculate Carry:
            carry = val / 10;
        }
        // If carry is not empty then append its digit:
        while (carry != 0)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }
    // Reverse the vector to obtain correct sequence of digits in factorial:
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int num = 10;
    vector<int> fact = factorial(num);
    for (auto i : fact)
    {
        cout << i << "";
    }
}