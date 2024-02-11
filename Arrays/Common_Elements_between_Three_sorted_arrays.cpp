/*
Given three arrays sorted in increasing order. Find the elements that are common in all
three arrays.
Note: can you take care of the duplicates without using any additional Data Structure?

Example 1:

Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
If there are no such elements return an empty array. In this case the output will be
printed as -1.
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    // code here.
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3)
    {
        // if all elements are equal (if a = b & b = c then a = c):
        if (A[i] == B[j] && B[j] == C[k])
        {
            ans.push_back(A[i]);
            i++;
            j++;
            k++;
        }
        // otherwise if a[i] is smaller than b[j] -> increment i:
        else if (A[i] < B[j])
        {
            i++;
        }
        // otherwise if b[j] is smaller than c[k] -> increment j:
        else if (B[j] < C[k])
        {
            j++;
        }
        // otherwise if c[k] is smaller -> increment k:
        else
        {
            k++;
        }
        // Prevent Addition of Duplicate elements:
        int xx = A[i - 1];
        while (A[i] == xx)
        {
            i++;
        }
        int yy = B[j - 1];
        while (B[j] == yy)
        {
            j++;
        }
        int zz = C[k - 1];
        while (C[k] == zz)
        {
            k++;
        }
    }
    if (ans.size() == 0)
    {
        return {-1};
    }
    return ans;
}
int main()
{
    int a[] = {1, 5, 10, 20, 40, 80};
    int b[] = {6, 7, 20, 80, 100};
    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = 6, n2 = 5, n3 = 8;
    vector<int> answ = commonElements(a, b, c, n1, n2, n3);
    for (auto i : answ)
    {
        cout << i << " ";
    }
}