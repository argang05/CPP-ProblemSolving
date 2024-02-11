/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the
stock before you buy again).

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/
#include <bits/stdc++.h>
using namespace std;
/* Top Down Approach:
int solve(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp)
{
    // Base Case:
    if (index == prices.size())
    {
        return 0;
    }
    if (limit == 0)
    {
        return 0;
    }
    // If ans of subprob already present then return it:
    if (dp[index][buy][limit] != -1)
    {
        return dp[index][buy][limit];
    }

    // If - else block:
    int profit = 0;
    if (buy)
    {
        int buyStock = -prices[index] + solve(index + 1, 0, prices, limit, dp);
        int skipBuy = 0 + solve(index + 1, 1, prices, limit, dp);
        profit = max(buyStock, skipBuy);
    }
    else
    {
        int sellStock = prices[index] + solve(index + 1, 1, prices, limit - 1, dp);
        int skipSell = 0 + solve(index + 1, 0, prices, limit, dp);
        profit = max(sellStock, skipSell);
    }

    // Store ans of subprob in dp vector:
    return dp[index][buy][limit] = profit;
}
*/

/*Bottom Up Approach
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyStock = -prices[index] + dp[index + 1][0][limit];
                    int skipBuy = 0 + dp[index + 1][1][limit];
                    profit = max(buyStock, skipBuy);
                }
                else
                {
                    int sellStock = prices[index] + dp[index + 1][1][limit - 1];
                    int skipSell = 0 + dp[index + 1][0][limit];
                    profit = max(sellStock, skipSell);
                }
                dp[limit][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}
*/

/*Bottom Up + Space Optimisation Approach:*/
int solveTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int limit = 1; limit <= 2; limit++)
            {
                int profit = 0;
                if (buy)
                {
                    int buyStock = -prices[index] + next[0][limit];
                    int skipBuy = 0 + next[1][limit];
                    profit = max(buyStock, skipBuy);
                }
                else
                {
                    int sellStock = prices[index] + next[1][limit - 1];
                    int skipSell = 0 + next[0][limit];
                    profit = max(sellStock, skipSell);
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][2];
}
int maxProfit(vector<int> &prices)
{
    return solveTab(prices);
}
int main()
{
    vector<int> prc = {7, 6, 4, 3, 1};
    int maxProf = maxProfit(prc);
    cout << maxProf;
}