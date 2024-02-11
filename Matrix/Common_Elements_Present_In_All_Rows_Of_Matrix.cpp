/*
Problem statement
You are given a 2-D Matrix 'MAT' having 'N' rows and 'M' columns, respectively. Your task
is to find all elements which are present in each row of the matrix.

Note :
1. The output array can contain the elements in any particular order.

2. Even if a particular element appears more than once in each matrix row, it should still be
present only once in the output array.
For Example :
Consider the matrix MAT [ [ 2, 3, 4, 7 ] , [ 0, 0, 3, 5 ] , [ 1, 3, 8, 9 ] ] having 3 rows and
4 columns respectively.
The output array should be [ 3 ] as 3 is the only element that is present in all three rows.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> findCommonElements(vector<vector<int>> &mat)
{
    // Write your code here
    int n = mat.size();
    int m = mat[0].size();

    // Unordered set to store unique elements in each row:
    unordered_set<int> uset;

    // Unordered map to store count of each unique element in matrix:
    unordered_map<int, int> umap;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Store all elements in set to achieve uniqueness:
            uset.insert(mat[i][j]);
        }

        // Iterate set and store the elements along with its count in map:
        for (auto it : uset)
        {
            umap[it]++;
        }

        // Clear set to store new element in next row to avoid ambiguity:
        uset.clear();
    }

    vector<int> ans;

    // Iterate through map and store the elements (.first value) whose count(.second value)
    // is equal to number of rows:
    for (auto itr : umap)
    {
        if (itr.second == n)
        {
            ans.push_back(itr.first);
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> m = {{2, 3, 4, 7, 5},
                             {0, 0, 3, 5, 7},
                             {1, 3, 8, 9, 7}};
    vector<int> answ = findCommonElements(m);
    for (auto i : answ)
    {
        cout << i << ",";
    }
}