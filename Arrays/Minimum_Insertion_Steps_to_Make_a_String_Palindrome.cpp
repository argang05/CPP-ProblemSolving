/*
Given a string s. In one step you can insert any character at any index of the string.

Return the minimum number of steps to make s palindrome.

A Palindrome String is one that reads the same backward as well as forward.

Example 1:

Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.
Example 2:

Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".
Example 3:

Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".
*/
#include <bits/stdc++.h>
using namespace std;
int solveTabLCS(string a, string b)
{
    // Space Optimization approach to obtain Longest Common Subsequence:
    int n = a.length();
    int m = b.length();

    vector<int> curr(m + 1, 0);
    vector<int> next(m + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = max(next[j], curr[j + 1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int minInsertions(string s)
{
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    // The Longest Common Subsequence Of a String and Reverse Of it results in
    // Longest Palindromic Subsequence:
    int longest_Palindromic_Subsequence = solveTabLCS(s, revStr);
    int strLen = s.length();
    // Min Number of insertions Formula:
    int ans = strLen - longest_Palindromic_Subsequence;
    return ans;
}
int main()
{
    string st = "zzazz";
    int minIns = minInsertions(st);
    cout << minIns;
}