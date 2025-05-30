#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,pre=1,pre2=0;
    cin >> n;
    for(int i = 2;i<=n;i++)
    {
        int curr = pre + pre2;
        pre2 = pre;
        pre = curr;
    }
    cout << pre;
}