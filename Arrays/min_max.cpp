/*
Given an array A of size N of integers.
Your task is to find the sum of minimum and maximum element in the array.

Input:
N = 5
A[] = {-2, 1, -4, 5, 3}
Output: 1
Explanation: min = -4, max =  5. Sum = -4 + 5 = 1
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>> pq_min;

    int A[] = {-2, 1, -4, 5, 3};
    for (int i : A)
    {
        pq_max.push(i);
        pq_min.push(i);
    }
    int sum = pq_max.top() + pq_min.top();
    cout << sum;
    return 0;
}
