/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = [["0"]]
Output: 0
Example 3:

Input: matrix = [["1"]]
Output: 1
*/
#include <bits/stdc++.h>
using namespace std;
#define INT_MIN -1000000;
vector<int> nextSmallerElementIndex(vector<int> &arr, int n)
{
    // Function to Find the next (towards right) smaller element's index for all elements of heights vector:
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
vector<int> prevSmallerElementIndex(vector<int> &arr, int n)
{
    // Function to Find the previous (towards left) smaller element's index for all elements of heights vector:
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // Vector to store all next smaller element indices:
    vector<int> next(n);
    next = nextSmallerElementIndex(heights, n);

    // Vector to store all previous smaller element indices:
    vector<int> prev(n);
    prev = prevSmallerElementIndex(heights, n);

    int area = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        // Width is constant current elements value
        int b = heights[i];

        // If statement to handle edge case where all elements of vector are equal:
        if (next[i] == -1)
        {
            next[i] = n;
        }

        // Length = nextSmallerElement of curr - previousSmallerElement of curr - 1:
        int l = next[i] - prev[i] - 1;

        int newArea = l * b;

        // Maximise the area:
        area = max(area, newArea);
    }
    return area;
}
int maximalRectangle(vector<vector<char>> &matrix)
{
    int maxi = INT_MIN;
    // Histogram vector to store the updated histograms and to calculate area:
    vector<int> histogram(matrix[0].size(), 0);
    for (int i = 0; i < matrix.size(); i++)
    {
        // Creating Histogram vector with breadth of 1s from matrix:
        for (int j = 0; j < histogram.size(); j++)
        {
            if (matrix[i][j] == '1')
            {
                histogram[j]++;
            }
            else
            {
                histogram[j] = 0;
            }
        }

        // Finding the largest rectangular area of the histogram of 1s created:
        int largestRectangularAreaInHistogram = largestRectangleArea(histogram);

        // maximise the result:
        maxi = max(maxi, largestRectangularAreaInHistogram);
    }
    return maxi;
}
int main()
{
    vector<vector<char>> mat = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};
    int maxArea = maximalRectangle(mat);
    cout << maxArea;
}