#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin >> arr[i];
    }
    int previ = 0;
    int prev2i = 0;
    for(int i = 1;i<n;i++)
    {
        int fs = previ + abs(arr[i] - arr[i-1]);
        int ss = INT_MAX;
        if(i > 1)
            ss = prev2i + abs(arr[i-2]-arr[i]);
        int curr = min(fs,ss);    
        prev2i = previ;
        previ = curr;
    }
    cout << previ;
}